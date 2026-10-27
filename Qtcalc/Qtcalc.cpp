#include "stdafx.h"
#include "Qtcalc.h"
#include <QPushButton>

/*图形化计算器 v2.0

 * 作者：Paris Zhang
 * 日期：2024-06-15
 * 说明：这是一个基于 Qt 的简单计算器实现，支持基本的加减乘除运算。
 * 更新日志：
    * 0.1：支持整数加减乘除运算，界面包含数字按钮、运算符按钮、清除按钮和确认按钮，仅能显示当前数字与结果
	* 1.0：新增计算过程显示功能，可显示当前及前一项输入的操作数和运算符。
    * 2.0：增加了除法结果小数显示，而非仅显示整数部分。修复了除法运算中除数为零的错误处理。
 */

/**
 * @brief Qtcalc 构造函数
 *
 * 初始化计算器状态，并为界面上的数字按钮与操作按钮绑定对应槽函数。
 * 默认状态为：
 * - currentInput = "0"
 * - storedValue = ""
 * - pendingOperator = ""
 * - waitingForOperand = false
 *
 * 构造完成后立即刷新显示内容。
 */
Qtcalc::Qtcalc(QWidget* parent)
    : QWidget(parent),
    currentInput("0"),
    storedValue(""),
    pendingOperator(""),
    waitingForOperand(false)
{
    ui.setupUi(this);

    // 绑定数字键
    connect(ui.btn0, &QPushButton::clicked, this, &Qtcalc::Btn0Clicked);
    connect(ui.btn1, &QPushButton::clicked, this, &Qtcalc::Btn1Clicked);
    connect(ui.btn2, &QPushButton::clicked, this, &Qtcalc::Btn2Clicked);
    connect(ui.btn3, &QPushButton::clicked, this, &Qtcalc::Btn3Clicked);
    connect(ui.btn4, &QPushButton::clicked, this, &Qtcalc::Btn4Clicked);
    connect(ui.btn5, &QPushButton::clicked, this, &Qtcalc::Btn5Clicked);
    connect(ui.btn6, &QPushButton::clicked, this, &Qtcalc::Btn6Clicked);
    connect(ui.btn7, &QPushButton::clicked, this, &Qtcalc::Btn7Clicked);
    connect(ui.btn8, &QPushButton::clicked, this, &Qtcalc::Btn8Clicked);
    connect(ui.btn9, &QPushButton::clicked, this, &Qtcalc::Btn9Clicked);

    // 绑定运算符键
    connect(ui.btnp, &QPushButton::clicked, this, &Qtcalc::BtnPlusClicked);
    connect(ui.btns, &QPushButton::clicked, this, &Qtcalc::BtnMinusClicked);
    connect(ui.btnm, &QPushButton::clicked, this, &Qtcalc::BtnMultiplyClicked);
    connect(ui.btnd, &QPushButton::clicked, this, &Qtcalc::BtnDivideClicked);

    // 绑定清除和确认键
    connect(ui.btnc, &QPushButton::clicked, this, &Qtcalc::BtnClearClicked);
    connect(ui.btne, &QPushButton::clicked, this, &Qtcalc::BtnEnterClicked);
}

/**
 * @brief 更新显示区内容
 *
 * 将 currentInput 的当前值同步到界面上的 result 文本框中。
 * 每次数值变更、运算处理或状态重置后都应调用此函数。
 */
void Qtcalc::updateDisplay(QString opu)
{
    if(opu == "")
        ui.result->setPlainText(currentInput);
    if (opu == "+" || opu == "-" || opu == "*" || opu == "/") {
        if (currentInput == "0") {
            ui.result->setPlainText(storedValue + " " + opu);
        }
        else {
            ui.result->setPlainText(storedValue + " " + opu + " " + currentInput);
        }
    }
}

/**
 * @brief 重置计算器状态
 *
 * 清空已存储的值、待执行运算符，以及等待新操作数状态。
 * 作用等同于“C”键，恢复到最初状态。
 */
void Qtcalc::resetCalculator()
{
    op = "";
    currentInput = "0";
    storedValue = "";
    pendingOperator = "";
    waitingForOperand = false;
    updateDisplay(op);
}

/**
 * @brief 将数字追加到当前输入中
 *
 * 处理数字按键输入逻辑：
 * 1. 若当前显示为 "Error"，则新输入会覆盖错误状态；
 * 2. 若处于等待新操作数状态，则从新开始输入；
 * 3. 若当前为 "0"，则防止出现多个前导 0；
 * 4. 否则将数字追加到现有字符串中。
 *
 * @param digit 输入的单个数字字符串（如 "3"）
 */
void Qtcalc::appendDigit(const QString& digit)
{
    // 若当前处于错误状态，输入新数字后立即覆盖错误并恢复正常
    if (currentInput == "Error")
    {
        currentInput = digit;
        waitingForOperand = false;
        updateDisplay(op);
        return;
    }

    // 若上一步骤已输入运算符，表示等待第一个操作数或新操作数输入
    if (waitingForOperand)
    {
        currentInput = digit;
        waitingForOperand = false;
    }
    else
    {
        // 避免输入 "00" 这种重复的前导 0
        if (currentInput == "0" && digit == "0")
        {
            // 保持为 0
        }
		if (currentInput == "0" && digit != "0")
		{
			currentInput = digit;
		}
        else
        {
            currentInput += digit;
        }
    }

    updateDisplay(op);
}

/**
 * @brief 应用运算符
 *
 * 当用户按下 +、-、*、/ 时，调用此函数。
 * 逻辑：
 * - 若已有旧运算符和存储值，则先执行前一个运算；
 * - 将当前输入保存到 storedValue 中；
 * - 设置 pendingOperator 为当前运算符；
 * - 将 waitingForOperand 置为 true，表示等待下一次输入作为右操作数。
 *
 * @param op 当前按下的运算符，例如 "+"、"-"、"*"、"/"
 */
void Qtcalc::applyOperator(const QString& opa)
{
    // 错误状态下，不允许继续运算
    if (currentInput == "Error: Invalid input" || currentInput == "Error: Division by zero")
    {
        return;
    }

    // 如果已经存在上一条未完成的运算，则先进行计算
    if (!storedValue.isEmpty() && !pendingOperator.isEmpty())
    {
        performCalculation(); 
    }

    storedValue = currentInput;
	currentInput = "0";
    pendingOperator = opa;
	op = opa;
    waitingForOperand = true;
    updateDisplay(op);
}

/**
 * @brief 执行当前待处理的运算
 *
 * 本函数从 storedValue 和 currentInput 中读取左右操作数，
 * 根据 pendingOperator 执行加减乘除运算。
 * 如果存在非法转换或除数为 0，则将 currentInput 置为 "Error"。
 *
 * 运算后：
 * - 将结果写回 currentInput
 * - 更新 storedValue
 * - 清空 pendingOperator
 * - 标记等待新操作数
 */
void Qtcalc::performCalculation()
{
    if (storedValue.isEmpty() || pendingOperator.isEmpty())
    {
        return;
    }

    bool ok1 = false;
    bool ok2 = false;

    // 支持小数：尝试转换为 double
    double left = storedValue.toDouble(&ok1);
    double right = currentInput.toDouble(&ok2);

    if (!ok1 || !ok2)
    {
        currentInput = "Error: Invalid input";
        updateDisplay(op);
        return;
    }

    double result = 0.0;

    if (pendingOperator == "+")
    {
        result = left + right;
    }
    else if (pendingOperator == "-")
    {
        result = left - right;
    }
    else if (pendingOperator == "*")
    {
        result = left * right;
    }
    else if (pendingOperator == "/")
    {
        if (right == 0.0)
        {
            currentInput = "Error: Division by zero";
            updateDisplay(op);
            return;
        }
        result = left / right;
    }

    // 显示小数结果，去除多余的0
    currentInput = QString::number(result, 'g', 15);
    storedValue = currentInput;
    pendingOperator = "";
    op = "";
    waitingForOperand = true;
    updateDisplay(op);
}

/**
 * @brief 数字 0 按钮点击槽函数
 */
void Qtcalc::Btn0Clicked()
{
    appendDigit("0");
}

/**
 * @brief 数字 1 按钮点击槽函数
 */
void Qtcalc::Btn1Clicked()
{
    appendDigit("1");
}

/**
 * @brief 数字 2 按钮点击槽函数
 */
void Qtcalc::Btn2Clicked()
{
    appendDigit("2");
}

/**
 * @brief 数字 3 按钮点击槽函数
 */
void Qtcalc::Btn3Clicked()
{
    appendDigit("3");
}

/**
 * @brief 数字 4 按钮点击槽函数
 */
void Qtcalc::Btn4Clicked()
{
    appendDigit("4");
}

/**
 * @brief 数字 5 按钮点击槽函数
 */
void Qtcalc::Btn5Clicked()
{
    appendDigit("5");
}

/**
 * @brief 数字 6 按钮点击槽函数
 */
void Qtcalc::Btn6Clicked()
{
    appendDigit("6");
}

/**
 * @brief 数字 7 按钮点击槽函数
 */
void Qtcalc::Btn7Clicked()
{
    appendDigit("7");
}

/**
 * @brief 数字 8 按钮点击槽函数
 */
void Qtcalc::Btn8Clicked()
{
    appendDigit("8");
}

/**
 * @brief 数字 9 按钮点击槽函数
 */
void Qtcalc::Btn9Clicked()
{
    appendDigit("9");
}

/**
 * @brief 加号按钮点击槽函数
 */
void Qtcalc::BtnPlusClicked()
{
    applyOperator("+");
}

/**
 * @brief 减号按钮点击槽函数
 */
void Qtcalc::BtnMinusClicked()
{
    applyOperator("-");
}

/**
 * @brief 乘号按钮点击槽函数
 */
void Qtcalc::BtnMultiplyClicked()
{
    applyOperator("*");
}

/**
 * @brief 除号按钮点击槽函数
 */
void Qtcalc::BtnDivideClicked()
{
    applyOperator("/");
}

/**
 * @brief 清除按钮点击槽函数
 *
 * 调用 resetCalculator() 以恢复默认状态。
 */
void Qtcalc::BtnClearClicked()
{
    resetCalculator();
}

/**
 * @brief 确认/等于按钮点击槽函数
 *
 * 若当前状态不是错误，并且存在待执行运算，则执行一次计算。
 * 计算完成后仍将 waitingForOperand 置为 true，以便继续后续计算。
 */
void Qtcalc::BtnEnterClicked()
{
    if (currentInput == "Error: Invalid input" || currentInput == "Error: Division by zero")
    {
        return;
    }

    if (!storedValue.isEmpty() && !pendingOperator.isEmpty())
    {
        performCalculation();
    }

    waitingForOperand = true;
    updateDisplay(op);
}

/**
 * @brief 析构函数
 *
 * 目前没有额外的资源释放需求，保持为空实现。
 */
Qtcalc::~Qtcalc()
{
}