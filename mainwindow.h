#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "helpdialog.h"
#include "infixtopostfix.h"
#include <QMainWindow>
#include <QDebug>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

namespace Ui {
    class MainWindow;
}

namespace MathSymbols {
    const QChar MATH_SYMBOL_PI      = (0x03C0);
    const QChar MATH_SYMBOL_POS_NEG = (0x00B1);
    const QChar MATH_SYMBOL_SQRT    = (0x221A);
    const QChar MATH_SYMBOL_CUBERT  = (0x221B);
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    /**********************************************************************
     *                  SECOND BTN Functionality
     *********************************************************************/
    void page1();
    void page2();
    void on_secondBtn_clicked();

    /**********************************************************************
     *                          VALIDATORS
     *********************************************************************/
    void Reset();
    void Error();
    bool CheckIfNum(QChar ch) const;
    bool CheckIfMathOp(QChar ch) const;
    bool ValidToAddNum(QChar ch) const;

    /**********************************************************************
     *                  NUMBERS & Decimal Point
     *********************************************************************/
    void on_zeroBtn_clicked();
    void on_oneBtn_clicked();
    void on_twoBtn_clicked();
    void on_threeBtn_clicked();
    void on_fourBtn_clicked();
    void on_sixBtn_clicked();
    void on_fiveBtn_clicked();
    void on_sevenBtn_clicked();
    void on_eightBtn_clicked();
    void on_nineBtn_clicked();
    void on_decPointBtn_clicked();

    /**********************************************************************
     *                      Parantheses
     *********************************************************************/
    void on_openParenthesisBtn_clicked();
    void on_closeParenthesisBtn_clicked();

    /**********************************************************************
     *                  Binary Operators (excluding ^)
     *********************************************************************/
    void on_addBtn_clicked();
    void on_subtractBtn_clicked();
    void on_multiplyBtn_clicked();
    void on_divideBtn_clicked();
    void on_moduloBtn_clicked();

    /**********************************************************************
     *          Binary Operators (for all ^ - including roots)
     *********************************************************************/
    void on_tenPowerBtn_clicked();
    void on_xSquaredBtn_clicked();
    void on_xCubedBtn_clicked();
    void on_ytoXPowerBtn_clicked();
    void on_sqrtXBtn_clicked();
    void on_cubeRootXBtn_clicked();
    void on_xRootYBtn_clicked();
    void on_ePowerBtn_clicked();
    void on_timesToThePowerBtn_clicked();

    /**********************************************************************
     *                      Constant Symbols
     **********************************************************************/
    void on_piBtn_clicked();

    /**********************************************************************
     *                      Fraction Math
     *********************************************************************/
    void on_fractionBtn_clicked();

    /**********************************************************************
     *                  Unary Operator (not trig)
     *********************************************************************/
    void on_negPosBtn_clicked();
    void on_logBtn_clicked();
    void on_lnBtn_clicked();

    /**********************************************************************
     *                      Unary Operator (trig)
     *********************************************************************/
    void on_sinBtn_clicked();
    void on_cosBtn_clicked();
    void on_tanBtn_clicked();
    void on_sinhBtn_clicked();
    void on_coshBtn_clicked();
    void on_tanhBtn_clicked();
    void on_invSinBtn_clicked();
    void on_invCosBtn_clicked();
    void on_invTanBtn_clicked();
    void on_invSinhBtn_clicked();
    void on_invCoshBtn_clicked();
    void on_invTanhBtn_clicked();

    /**********************************************************************
     *                      Clear/Reset Btns
     *********************************************************************/
    void on_clearBtn_clicked();
    void on_cBtn_clicked();
    void on_mcBtn_clicked();
    void on_mrBtn_clicked();
    void on_mPlusBtn_clicked();
    void on_mMinusBtn_clicked();

    /**********************************************************************
     *              Other Typical Calculator Btns
     *********************************************************************/
    void on_equalBtn_clicked();
    void on_randBtn_clicked();
    void on_degreeBtn_clicked();
    void on_factorialBtn_clicked();

    void on_actionHelp_triggered();

    void on_actionGood_Bye_triggered();

private:
    Ui::MainWindow *ui;                 // Ui main frame
    int             currentIndex;       // Stack Widget Pages Index
    QString         eqnDisplay;         // Equation Display for user infix
    int             countOpenParen;     // Count Open Paren
    int             countCloseParen;    // Count Close Paren
    int             memoryReg;          // Memory Register
    QString         theAns;             // The Final Calculated Answer
    bool            isDegree;            // Degrees or radians
};

#endif // MAINWINDOW_H
