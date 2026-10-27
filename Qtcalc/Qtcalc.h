#pragma once

#include <QtWidgets/QWidget>
#include "ui_Qtcalc.h"

/**
 * @class Qtcalc
 * @brief 一个简单的 Qt 计算器界面类。
 *
 * 该类继承自 QWidget，封装了按钮和显示区域的逻辑，
 * 通过按钮槽函数实现数字输入、运算符处理、清空和计算结果展示。
 *
 * 核心成员说明：
 * - currentInput: 当前显示在屏幕上的值；
 * - storedValue: 上一次保存的操作数；
 * - pendingOperator: 当前等待执行的运算符；
 * - waitingForOperand: 是否正在等待下一次输入操作数。
 */
class Qtcalc : public QWidget
{
    Q_OBJECT

public:
    Qtcalc(QWidget* parent = nullptr);
    ~Qtcalc();

private slots:
    // 数字键
    void Btn0Clicked();
    void Btn1Clicked();
    void Btn2Clicked();
    void Btn3Clicked();
    void Btn4Clicked();
    void Btn5Clicked();
    void Btn6Clicked();
    void Btn7Clicked();
    void Btn8Clicked();
    void Btn9Clicked();

    // 运算符键
    void BtnPlusClicked();
    void BtnMinusClicked();
    void BtnMultiplyClicked();
    void BtnDivideClicked();

    // 功能键
    void BtnClearClicked();
    void BtnEnterClicked();

private:
    // Qt 自动生成的 UI 对象
    Ui::QtcalcClass ui;

    // 计算器内部状态
    QString currentInput;     // 当前显示值
    QString storedValue;      // 暂存的前一个操作数
    QString pendingOperator;  // 等待执行的运算符
    bool waitingForOperand;    // 是否等待新操作数输入
    QString op; //此处为类成员变量op
    // 私有辅助函数
    void appendDigit(const QString& digit); // 追加数字
    //已加入参数op
	void updateDisplay(const QString opu);   // 刷新显示区，此处opu仅在该函数中生效
    void applyOperator(const QString& opa); // 应用运算符，此处opa仅在该函数中生效
    void performCalculation();             // 执行计算
    void resetCalculator();                // 重置计算器状态
};