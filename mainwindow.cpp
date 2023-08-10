#include "mainwindow.h"
#include "ui_mainwindow.h"

/**************************************************************************
 * CONSTRUCTOR
 *************************************************************************/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setFixedSize(575, 620);
    ui->setupUi(this);

    srand(time(NULL));

    countOpenParen  = 0;
    countCloseParen = 0;
    memoryReg       = 0;
    isDegree        = false;
}

/**************************************************************************
 * DESTRUCTOR
 *************************************************************************/
MainWindow::~MainWindow()
{
    delete ui;
}

/**************************************************************************
 *                              FILE
 * ------------------------------------------------------------------------
 *                      on_actionHelp_triggered
 *                      on_actionGood_Bye_triggered
 *************************************************************************/
/**************************************************************************
 * on_actionHelp_triggered
 *************************************************************************/
void MainWindow::on_actionHelp_triggered()
{
    HelpDialog *theHelp = new HelpDialog();

    theHelp->show();
}

/**************************************************************************
 * on_actionGood_Bye_triggered
 *************************************************************************/
void MainWindow::on_actionGood_Bye_triggered()
{
    QApplication::quit();
}

/**************************************************************************
 *                              SECOND BTN
 * ------------------------------------------------------------------------
 *                          page1()
 *                          page2()
 *                          on_secondBtn_clicked()
 *************************************************************************/

/**************************************************************************
 * page1()
 *************************************************************************/
void MainWindow::page1()
{
    if(currentIndex < ui->changeStackWidget->count())
        ui->changeStackWidget->setCurrentIndex(0); // page1
}

/**************************************************************************
 * page2()
 *************************************************************************/
void MainWindow::page2()
{
    if(currentIndex < ui->changeStackWidget->count())
        ui->changeStackWidget->setCurrentIndex(1); // for page2
}

/**************************************************************************
 * on_secondBtn_clicked
 *************************************************************************/
void MainWindow::on_secondBtn_clicked()
{
    currentIndex = ui->changeStackWidget->currentIndex();
    if(currentIndex == 0)
        page2();
    else if(currentIndex == 1)
        page1();
}

/**************************************************************************
 *                          VALIDATORS
 * ------------------------------------------------------------------------
 *                          Reset
 *                          Error
 *                          CheckIfNum
 *                          CheckIfMathOp
 *                          ValidToAddNum
 *************************************************************************/
/**************************************************************************
 * Reset
 *************************************************************************/
void MainWindow::Reset() {
    isDegree        = false;
    countOpenParen  = 0;
    countCloseParen = 0;
    eqnDisplay.clear();
    ui->screenLbl->setText("");
    ui->postFixLbl->setText("");
    ui->ansLbl->setText("");
}

/**************************************************************************
 * Error
 *************************************************************************/
void MainWindow::Error() {
    Reset();
    ui->screenLbl->setText("ERROR");
}

/**************************************************************************
 * CheckIfNum
 *************************************************************************/
bool MainWindow::CheckIfNum(QChar ch) const {
    if(ch == '0' || ch == '1' || ch == '2' ||
       ch == '3' || ch == '4' || ch == '5' ||
       ch == '6' || ch == '7' || ch == '8' || ch == '9')
        return true;
    return false;
}

/**************************************************************************
 * CheckIfMathOp
 *************************************************************************/
bool MainWindow::CheckIfMathOp(QChar ch) const {
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
        return true;
    return false;
}

/**************************************************************************
 * ValidToAddNum
 *************************************************************************/
bool MainWindow::ValidToAddNum(QChar ch) const {
    if(ch != MathSymbols::MATH_SYMBOL_PI && ch != ')')
        return true;
    return false;
}

/**************************************************************************
 *                          NUMBERS & Decimal Point
 * ------------------------------------------------------------------------
 *                          on_zeroBtn_clicked
 *                          on_oneBtn_clicked
 *                          on_twoBtn_clicked
 *                          on_threeBtn_clicked
 *                          on_fourBtn_clicked
 *                          on_fiveBtn_clicked
 *                          on_sixBtn_clicked
 *                          on_sevenBtn_clicked
 *                          on_eightBtn_clicked
 *                          on_nineBtn_clicked
 *                          on_decPointBtn_clicked
 *************************************************************************/

/**************************************************************************
 * on_zeroBtn_clicked
 *************************************************************************/
void MainWindow::on_zeroBtn_clicked()
{
    if(ValidToAddNum(eqnDisplay.length()-1)) {
        eqnDisplay.append("0");
    }
    ui->screenLbl->setText(eqnDisplay);
}

/**************************************************************************
 * on_oneBtn_clicked
 *************************************************************************/
void MainWindow::on_oneBtn_clicked()
{
    if(ValidToAddNum(eqnDisplay.length()-1)) {
        eqnDisplay.append("1");
    }
    ui->screenLbl->setText(eqnDisplay);
}

/**************************************************************************
 * on_twoBtn_clicked
 *************************************************************************/
void MainWindow::on_twoBtn_clicked()
{
    if(ValidToAddNum(eqnDisplay.length()-1)) {
        eqnDisplay.append("2");
    }
    ui->screenLbl->setText(eqnDisplay);
}

/**************************************************************************
 * on_threeBtn_clicked
 *************************************************************************/
void MainWindow::on_threeBtn_clicked()
{
    if(ValidToAddNum(eqnDisplay.length()-1)) {
        eqnDisplay.append("3");
    }
    ui->screenLbl->setText(eqnDisplay);
}

/**************************************************************************
 * on_fourBtn_clicked
 *************************************************************************/
void MainWindow::on_fourBtn_clicked()
{
    if(ValidToAddNum(eqnDisplay.length()-1)) {
        eqnDisplay.append("4");
    }
    ui->screenLbl->setText(eqnDisplay);
}

/**************************************************************************
 * on_fiveBtn_clicked
 *************************************************************************/
void MainWindow::on_fiveBtn_clicked()
{
    if(ValidToAddNum(eqnDisplay.length()-1)) {
        eqnDisplay.append("5");
    }
    ui->screenLbl->setText(eqnDisplay);
}

/**************************************************************************
 * on_sixBtn_clicked
 *************************************************************************/
void MainWindow::on_sixBtn_clicked()
{
    if(ValidToAddNum(eqnDisplay.length()-1)) {
       eqnDisplay.append("6");
    }
    ui->screenLbl->setText(eqnDisplay);
}

/**************************************************************************
 * on_sevenBtn_clicked
 *************************************************************************/
void MainWindow::on_sevenBtn_clicked()
{
   if(ValidToAddNum(eqnDisplay.length()-1)) {
       eqnDisplay.append("7");
   }
    ui->screenLbl->setText(eqnDisplay);
}

/**************************************************************************
 * on_eightBtn_clicked
 *************************************************************************/
void MainWindow::on_eightBtn_clicked()
{
    if(ValidToAddNum(eqnDisplay.length()-1)) {
        eqnDisplay.append("8");
    }
    ui->screenLbl->setText(eqnDisplay);
}

/**************************************************************************
 * on_nineBtn_clicked
 *************************************************************************/
void MainWindow::on_nineBtn_clicked()
{
    if(ValidToAddNum(eqnDisplay.length()-1)) {
        eqnDisplay.append("9");
    }
    ui->screenLbl->setText(eqnDisplay);
}

/**************************************************************************
 * on_decPointBtn_clicked
 *************************************************************************/
void MainWindow::on_decPointBtn_clicked()
{
    if(ValidToAddNum(eqnDisplay.length()-1)) {
        eqnDisplay.append(".");
    }
    ui->screenLbl->setText(eqnDisplay);
}

/**************************************************************************
 *                      Parantheses
 * ------------------------------------------------------------------------
 *                  on_openParenthesisBtn_clicked
 *                  on_closeParenthesisBtn_clicked
 *************************************************************************/

/**************************************************************************
 * on_openParenthesisBtn_clicked
 *************************************************************************/
void MainWindow::on_openParenthesisBtn_clicked()
{
    bool valid = false;

    if(eqnDisplay.isEmpty())
        valid = true;
    else if(CheckIfMathOp(eqnDisplay.at(eqnDisplay.length()-1)) ||
            eqnDisplay.endsWith("(") || eqnDisplay.endsWith("^"))
        valid = true;

    if(valid) {
        countOpenParen++;
        eqnDisplay.append("(");
        ui->screenLbl->setText(eqnDisplay);
    }
}

/**************************************************************************
 * on_closeParenthesisBtn_clicked
 *************************************************************************/
void MainWindow::on_closeParenthesisBtn_clicked()
{
    if(!CheckIfMathOp(eqnDisplay.at(eqnDisplay.length()-1)) &&
        countOpenParen > countCloseParen && !eqnDisplay.endsWith("(")) {
        eqnDisplay.append(")");
        countCloseParen++;
        ui->screenLbl->setText(eqnDisplay);
    }
}

/**************************************************************************
 *                          Binary Operators (excluding ^)
 * ------------------------------------------------------------------------
 *                          on_addBtn_clicked
 *                          on_subtractBtn_clicked
 *                          on_multiplyBtn_clicked
 *                          on_divideBtn_clicked
 *                          on_moduloBtn_clicked
 *************************************************************************/

/**************************************************************************
 * on_addBtn_clicked
 *************************************************************************/
void MainWindow::on_addBtn_clicked()
{
    if(!eqnDisplay.endsWith("(") && !eqnDisplay.endsWith("^")
       && !eqnDisplay.isNull()) {
        if(CheckIfMathOp(eqnDisplay.at(eqnDisplay.length()-1))) {
            eqnDisplay = eqnDisplay.left(eqnDisplay.length()-1);
        }
        eqnDisplay.append("+");
        ui->screenLbl->setText(eqnDisplay);
    }
}

/**************************************************************************
 * on_subtractBtn_clicked
 *************************************************************************/
void MainWindow::on_subtractBtn_clicked()
{
    if(!eqnDisplay.endsWith("(") && !eqnDisplay.endsWith("^")
       && !eqnDisplay.isNull()) {
        if(CheckIfMathOp(eqnDisplay.at(eqnDisplay.length()-1))
           || eqnDisplay.endsWith("(")) {
            eqnDisplay = eqnDisplay.left(eqnDisplay.length()-1);
        }
        eqnDisplay.append("-");
        ui->screenLbl->setText(eqnDisplay);
    }
}

/**************************************************************************
 * on_multiplyBtn_clicked
 *************************************************************************/
void MainWindow::on_multiplyBtn_clicked()
{
    if(!eqnDisplay.endsWith("(") && !eqnDisplay.endsWith("^")
       && !eqnDisplay.isNull()) {
        if(CheckIfMathOp(eqnDisplay.at(eqnDisplay.length()-1))
           || eqnDisplay.endsWith("(")) {
            eqnDisplay = eqnDisplay.left(eqnDisplay.length()-1);
        }
        eqnDisplay.append("*");
        ui->screenLbl->setText(eqnDisplay);
    }
}

/**************************************************************************
 * on_divideBtn_clicked
 *************************************************************************/
void MainWindow::on_divideBtn_clicked()
{
    if(!eqnDisplay.endsWith("(") && !eqnDisplay.endsWith("^")
       && !eqnDisplay.isNull()) {
        if(CheckIfMathOp(eqnDisplay.at(eqnDisplay.length()-1)) ||
           eqnDisplay.endsWith("(")) {
            eqnDisplay = eqnDisplay.left(eqnDisplay.length()-1);
        }
        eqnDisplay.append("/");
        ui->screenLbl->setText(eqnDisplay);
    }
}

/**************************************************************************
 * on_moduloBtn_clicked
 *************************************************************************/
void MainWindow::on_moduloBtn_clicked()
{
    if(!eqnDisplay.endsWith("(") && !eqnDisplay.endsWith("^")
       && !eqnDisplay.isNull()) {
        if(CheckIfMathOp(eqnDisplay.at(eqnDisplay.length()-1)) ||
           eqnDisplay.endsWith("(")) {
            eqnDisplay = eqnDisplay.left(eqnDisplay.length()-1);
        }
        eqnDisplay.append("%");
        ui->screenLbl->setText(eqnDisplay);
    }
}

/**************************************************************************
 *              Binary Operators (for all ^ - including roots)
 * ------------------------------------------------------------------------
 *                          on_tenPowerBtn_clicked
 *                          on_xSquaredBtn_clicked
 *                          on_xCubedBtn_clicked
 *                          on_ytoXPowerBtn_clicked
 *                          on_sqrtXBtn_clicked
 *                          on_cubeRootXBtn_clicked
 *                          on_xRootYBtn_clicked
 *                          on_ePowerBtn_clicked
 *                          on_timesToThePowerBtn_clicked
 *************************************************************************/

/**************************************************************************
 * on_tenPowerBtn_clicked
 *************************************************************************/
void MainWindow::on_tenPowerBtn_clicked()
{
    if(!eqnDisplay.isEmpty()) {
        if(!eqnDisplay.endsWith(MathSymbols::MATH_SYMBOL_PI) &&
           !CheckIfNum(eqnDisplay.at(eqnDisplay.length()-1))) {
            eqnDisplay.append("10^");
            ui->screenLbl->setText(eqnDisplay);
        }
    }
}

/**************************************************************************
 * on_xSquaredBtn_clicked
 *************************************************************************/
void MainWindow::on_xSquaredBtn_clicked()
{
    if(!eqnDisplay.isEmpty()) {
        if(CheckIfNum(eqnDisplay.at(eqnDisplay.length()-1)) ||
           eqnDisplay.endsWith(")")) {
            eqnDisplay.append("^2");
            ui->screenLbl->setText(eqnDisplay);
        }
    }
}

/**************************************************************************
 * on_xCubedBtn_clicked
 *************************************************************************/
void MainWindow::on_xCubedBtn_clicked()
{
    if(!eqnDisplay.isEmpty()) {
        if(CheckIfNum(eqnDisplay.at(eqnDisplay.length()-1)) ||
           eqnDisplay.endsWith(")")) {
            eqnDisplay.append("^3");
            ui->screenLbl->setText(eqnDisplay);
        }
    }
}

/**************************************************************************
 * on_ytoXPowerBtn_clicked
 *************************************************************************/
void MainWindow::on_ytoXPowerBtn_clicked()
{
    if(!eqnDisplay.isEmpty()) {
        if(CheckIfNum(eqnDisplay.at(eqnDisplay.length()-1)) ||
           eqnDisplay.endsWith(")")) {
            eqnDisplay.append("^");
            ui->screenLbl->setText(eqnDisplay);
        }
    }
}

/**************************************************************************
 * on_sqrtXBtn_clicked
 *************************************************************************/
void MainWindow::on_sqrtXBtn_clicked()
{
    bool valid = false;

    if(eqnDisplay.isEmpty())
        valid = true;
    else if(CheckIfMathOp(eqnDisplay.at(eqnDisplay.length()-1)))
        valid = true;

    if(valid) {
        eqnDisplay.append("sqrt(");
        countOpenParen++;
        ui->screenLbl->setText(eqnDisplay);
    }
}

/**************************************************************************
 * on_cubeRootXBtn_clicked
 *************************************************************************/
void MainWindow::on_cubeRootXBtn_clicked()
{
    bool valid = false;

    if(eqnDisplay.isEmpty())
        valid = true;
    else if(CheckIfMathOp(eqnDisplay.at(eqnDisplay.length()-1)))
        valid = true;

    if(valid) {
        eqnDisplay.append("cuberoot(");
        countOpenParen++;
        ui->screenLbl->setText(eqnDisplay);
    }
}

/**************************************************************************
 * on_xRootYBtn_clicked
 *************************************************************************/
void MainWindow::on_xRootYBtn_clicked()
{
    bool valid = false;

    if(eqnDisplay.isEmpty())
        valid = false;
    else if(CheckIfNum(eqnDisplay.at(eqnDisplay.length()-1)))
        valid = true;

    if(valid) {
        eqnDisplay.append("root(");
        countOpenParen++;
        ui->screenLbl->setText(eqnDisplay);
    }
}

/**************************************************************************
 * on_ePowerBtn_clicked
 *************************************************************************/
void MainWindow::on_ePowerBtn_clicked()
{
    if(!eqnDisplay.isEmpty()) {
        if(!eqnDisplay.endsWith(MathSymbols::MATH_SYMBOL_PI) &&
           !CheckIfNum(eqnDisplay.at(eqnDisplay.length()-1))) {

            eqnDisplay.append("e^");
        }
    }
    else {
        eqnDisplay.append("e^");
    }

    ui->screenLbl->setText(eqnDisplay);
}

/**************************************************************************
 * on_timesToThePowerBtn_clicked
 *************************************************************************/
void MainWindow::on_timesToThePowerBtn_clicked()
{
    if(!eqnDisplay.isEmpty()) {
        if(CheckIfNum(eqnDisplay.at(eqnDisplay.length()-1)) ||
           eqnDisplay.endsWith(")")) {

            eqnDisplay.append("*10^");
            countOpenParen++;
            ui->screenLbl->setText(eqnDisplay);
        }
    }
}

/**************************************************************************
 *                      Constant Symbols
 * ------------------------------------------------------------------------
 *                          on_piBtn_clicked
 *************************************************************************/

/**************************************************************************
 * on_piBtn_clicked
 *************************************************************************/
void MainWindow::on_piBtn_clicked()
{
    if(eqnDisplay.isEmpty()) {
        eqnDisplay.append(MathSymbols::MATH_SYMBOL_PI);
    }
    else if((CheckIfMathOp(eqnDisplay.at(eqnDisplay.length()-1)) ||
             eqnDisplay.endsWith("("))) {
        eqnDisplay.append(MathSymbols::MATH_SYMBOL_PI);
    }
    ui->screenLbl->setText(eqnDisplay);
}

/**************************************************************************
 *                      Fraction Math
 * ------------------------------------------------------------------------
 *                          on_fractionBtn_clicked
 *************************************************************************/

/**************************************************************************
 * on_fractionBtn_clicked
 *************************************************************************/
void MainWindow::on_fractionBtn_clicked()
{
    if(eqnDisplay.isEmpty()) {
        eqnDisplay.append("1/");
    }
    else if(!eqnDisplay.endsWith(MathSymbols::MATH_SYMBOL_PI) &&
       !CheckIfNum(eqnDisplay.at(eqnDisplay.length()-1))) {
        eqnDisplay.append("1/");
    }
    ui->screenLbl->setText(eqnDisplay);
}

/**************************************************************************
 *                      Unary Operator (not trig)
 * ------------------------------------------------------------------------
 *                          on_negPosBtn_clicked
 *                          on_logBtn_clicked
 *                          on_lnBtn_clicked
 *************************************************************************/

/**************************************************************************
 * on_negPosBtn_clicked
 *************************************************************************/
void MainWindow::on_negPosBtn_clicked()
{
    if(eqnDisplay.isEmpty()) {
        eqnDisplay.append("-");
    }
    else if(eqnDisplay.length() == 1 && eqnDisplay.at(0) == '-') {
        if(eqnDisplay.endsWith("-"))
            eqnDisplay.replace(0, 1, "");
        else
            eqnDisplay.replace(0, 1, "-");
    }
    else if(CheckIfMathOp(eqnDisplay.at(eqnDisplay.length()-1))) {
        eqnDisplay.append("-");
    }
    else if(eqnDisplay.endsWith("(")) {
        eqnDisplay.append("-");
    }
    else {
        QString mathNum;
        int index   = eqnDisplay.length() - 1;
        bool getNum = true;

        while(getNum) {
            if(index < 0) {
                getNum = false;
            }
            else if(!CheckIfMathOp(eqnDisplay.at(index)) && eqnDisplay.at(index) != '(') {
                mathNum.push_front(eqnDisplay.endsWith(index));
                index--;
            }
            else {
                getNum = false;
            }
        }

        if((index - 1) >= 0) {
            if(CheckIfMathOp(eqnDisplay.at(index - 1))) {
                if(eqnDisplay.at(index) == '-') {
                    eqnDisplay.remove(index, 1);
                }
                else {
                    eqnDisplay.insert((index), "-");
                }
            }
            else {
                eqnDisplay.insert((index + 1), "-");
            }
        }
        else {
            eqnDisplay.insert((index + 1), "-");
        }
    }
    ui->screenLbl->setText(eqnDisplay);
}

/**************************************************************************
 * on_logBtn_clicked
 *************************************************************************/
void MainWindow::on_logBtn_clicked()
{
    bool valid = false;

    if(eqnDisplay.isEmpty())
        valid = true;
    else if(CheckIfMathOp(eqnDisplay.at(eqnDisplay.length()-1)))
        valid = true;

    if(valid) {
        eqnDisplay.append("log(");
        countOpenParen++;
        ui->screenLbl->setText(eqnDisplay);
    }
}

/**************************************************************************
 * on_lnBtn_clicked
 *************************************************************************/
void MainWindow::on_lnBtn_clicked()
{
    bool valid = false;

    if(eqnDisplay.isEmpty())
        valid = true;
    else if(CheckIfMathOp(eqnDisplay.at(eqnDisplay.length()-1)))
        valid = true;

    if(valid) {
        eqnDisplay.append("ln(");
        countOpenParen++;
        ui->screenLbl->setText(eqnDisplay);
    }
}

/**************************************************************************
 *                      Unary Operator (trig)
 * ------------------------------------------------------------------------
 *                          on_sinBtn_clicked
 *                          on_cosBtn_clicked
 *                          on_tanBtn_clicked
 *                          on_sinhBtn_clicked
 *                          on_coshBtn_clicked
 *                          on_tanhBtn_clicked
 *                          on_invSinBtn_clicked
 *                          on_invCosBtn_clicked
 *                          on_invTanBtn_clicked
 *                          on_invSinhBtn_clicked
 *                          on_invCoshBtn_clicked
 *                          on_invTanhBtn_clicked
 *************************************************************************/

/**************************************************************************
 * on_sinBtn_clicked
 *************************************************************************/
void MainWindow::on_sinBtn_clicked()
{
    bool valid = false;

    if(eqnDisplay.isEmpty())
        valid = true;
    else if(CheckIfMathOp(eqnDisplay.at(eqnDisplay.length()-1)))
        valid = true;

    if(valid) {
        eqnDisplay.append("sin(");
        countOpenParen++;
        ui->screenLbl->setText(eqnDisplay);
    }
}

/**************************************************************************
 * on_cosBtn_clicked
 *************************************************************************/
void MainWindow::on_cosBtn_clicked()
{
    bool valid = false;

    if(eqnDisplay.isEmpty())
        valid = true;
    else if(CheckIfMathOp(eqnDisplay.at(eqnDisplay.length()-1)))
        valid = true;

    if(valid) {
        eqnDisplay.append("cos(");
        countOpenParen++;
        ui->screenLbl->setText(eqnDisplay);
    }
}

/**************************************************************************
 * on_tanBtn_clicked
 *************************************************************************/
void MainWindow::on_tanBtn_clicked()
{
    bool valid = false;

    if(eqnDisplay.isEmpty())
        valid = true;
    else if(CheckIfMathOp(eqnDisplay.at(eqnDisplay.length()-1)))
        valid = true;

    if(valid) {
        eqnDisplay.append("tan(");
        countOpenParen++;
        ui->screenLbl->setText(eqnDisplay);
    }
}

/**************************************************************************
 * on_sinhBtn_clicked
 *************************************************************************/
void MainWindow::on_sinhBtn_clicked()
{
    bool valid = false;

    if(eqnDisplay.isEmpty())
        valid = true;
    else if(CheckIfMathOp(eqnDisplay.at(eqnDisplay.length()-1)))
        valid = true;

    if(valid) {
        eqnDisplay.append("sinh(");
        countOpenParen++;
        ui->screenLbl->setText(eqnDisplay);
    }
}

/**************************************************************************
 * on_coshBtn_clicked
 *************************************************************************/
void MainWindow::on_coshBtn_clicked()
{
    bool valid = false;

    if(eqnDisplay.isEmpty())
        valid = true;
    else if(CheckIfMathOp(eqnDisplay.at(eqnDisplay.length()-1)))
        valid = true;

    if(valid) {
        eqnDisplay.append("cosh(");
        countOpenParen++;
        ui->screenLbl->setText(eqnDisplay);
    }
}

/**************************************************************************
 * on_tanhBtn_clicked
 *************************************************************************/
void MainWindow::on_tanhBtn_clicked()
{
    bool valid = false;

    if(eqnDisplay.isEmpty())
        valid = true;
    else if(CheckIfMathOp(eqnDisplay.at(eqnDisplay.length()-1)))
        valid = true;

    if(valid) {
        eqnDisplay.append("tanh(");
        countOpenParen++;
        ui->screenLbl->setText(eqnDisplay);
    }
}

/**************************************************************************
 * on_invSinBtn_clicked
 *************************************************************************/
void MainWindow::on_invSinBtn_clicked()
{
    bool valid = false;

    if(eqnDisplay.isEmpty())
        valid = true;
    else if(CheckIfMathOp(eqnDisplay.at(eqnDisplay.length()-1)))
        valid = true;

    if(valid) {
        eqnDisplay.append("invSin(");
        countOpenParen++;
        ui->screenLbl->setText(eqnDisplay);
    }
}

/**************************************************************************
 * on_invCosBtn_clicked
 *************************************************************************/
void MainWindow::on_invCosBtn_clicked()
{
    bool valid = false;

    if(eqnDisplay.isEmpty())
        valid = true;
    else if(CheckIfMathOp(eqnDisplay.at(eqnDisplay.length()-1)))
        valid = true;

    if(valid) {
        eqnDisplay.append("invCos(");
        countOpenParen++;
        ui->screenLbl->setText(eqnDisplay);
    }
}

/**************************************************************************
 * on_invTanBtn_clicked
 *************************************************************************/
void MainWindow::on_invTanBtn_clicked()
{
    bool valid = false;

    if(eqnDisplay.isEmpty())
        valid = true;
    else if(CheckIfMathOp(eqnDisplay.at(eqnDisplay.length()-1)))
        valid = true;

    if(valid) {
        eqnDisplay.append("invTan(");
        countOpenParen++;
        ui->screenLbl->setText(eqnDisplay);
    }
}

/**************************************************************************
 * on_invSinhBtn_clicked
 *************************************************************************/
void MainWindow::on_invSinhBtn_clicked()
{
    bool valid = false;

    if(eqnDisplay.isEmpty())
        valid = true;
    else if(CheckIfMathOp(eqnDisplay.at(eqnDisplay.length()-1)))
        valid = true;

    if(valid) {
        eqnDisplay.append("invSinh(");
        countOpenParen++;
        ui->screenLbl->setText(eqnDisplay);
    }
}

/**************************************************************************
 * on_invCoshBtn_clicked
 *************************************************************************/
void MainWindow::on_invCoshBtn_clicked()
{
    bool valid = false;

    if(eqnDisplay.isEmpty())
        valid = true;
    else if(CheckIfMathOp(eqnDisplay.at(eqnDisplay.length()-1)))
        valid = true;

    if(valid) {
        eqnDisplay.append("invCosh(");
        countOpenParen++;
        ui->screenLbl->setText(eqnDisplay);
    }
}

/**************************************************************************
 * on_invTanhBtn_clicked
 *************************************************************************/
void MainWindow::on_invTanhBtn_clicked()
{
    bool valid = false;

    if(eqnDisplay.isEmpty())
        valid = true;
    else if(CheckIfMathOp(eqnDisplay.at(eqnDisplay.length()-1)))
        valid = true;

    if(valid) {
        eqnDisplay.append("invTanh(");
        countOpenParen++;
        ui->screenLbl->setText(eqnDisplay);
    }
}

/**************************************************************************
 *                      Clear/Reset Btns
 * ------------------------------------------------------------------------
 *                          on_clearBtn_clicked
 *                          on_cBtn_clicked
 *                          on_mcBtn_clicked
 *                          on_mrBtn_clicked
 *                          on_mPlusBtn_clicked
 *                          on_mMinusBtn_clicked
 *************************************************************************/
/**************************************************************************
 * on_clearBtn_clicked
 *************************************************************************/
void MainWindow::on_clearBtn_clicked()
{
    countOpenParen  = 0;
    countCloseParen = 0;
    memoryReg       = 0;

    eqnDisplay.clear();
    ui->screenLbl->setText("0");
    ui->ansLbl->setText("");
    ui->postFixLbl->setText("");
}

/**************************************************************************
 * on_cBtn_clicked
 *************************************************************************/
void MainWindow::on_cBtn_clicked()
{
    if(!eqnDisplay.isEmpty()) {
        int i = eqnDisplay.length()-1;

        while((i >= 0) && CheckIfMathOp(eqnDisplay.at(i))) {
            eqnDisplay.remove(i, 1);
            i--;
        }

        while((i >= 0) && !CheckIfMathOp(eqnDisplay.at(i))) {
            eqnDisplay.remove(i, 1);
            i--;
        }
    }
    ui->screenLbl->setText(eqnDisplay);
}

/**************************************************************************
 * on_mcBtn_clicked
 *************************************************************************/
void MainWindow::on_mcBtn_clicked()
{
    memoryReg = 0;
    Reset();
}

/**************************************************************************
 * on_mrBtn_clicked
 *************************************************************************/
void MainWindow::on_mrBtn_clicked()
{
    ui->ansLbl->setText(QString::number(memoryReg));
}

/**************************************************************************
 * on_mPlusBtn_clicked
 *************************************************************************/
void MainWindow::on_mPlusBtn_clicked()
{
    memoryReg += theAns.toFloat();
    Reset();
}

/**************************************************************************
 * on_mMinusBtn_clicked
 *************************************************************************/
void MainWindow::on_mMinusBtn_clicked()
{
    memoryReg -= theAns.toFloat();
    Reset();
}

/**************************************************************************
 *                      Other Typical Calculator Btns
 * ------------------------------------------------------------------------
 *                          on_equalBtn_clicked
 *                          on_randBtn_clicked
 *                          on_degreeBtn_clicked
 *                          on_factorialBtn_clicked
 *************************************************************************/

/**************************************************************************
 * on_equalBtn_clicked
 *************************************************************************/
void MainWindow::on_equalBtn_clicked()
{
    if(countCloseParen == countOpenParen) {
        InfixToPostfix postfix;
        QString postfixEqn = postfix.GetInfixToPostfix(eqnDisplay);
        theAns     = postfix.GetCalculatedPostfix(postfixEqn, isDegree);

        ui->ansLbl->setText(theAns);
        ui->postFixLbl->setText(postfixEqn);
        ui->screenLbl->setText(eqnDisplay);
    }
}

/**************************************************************************
 * on_randBtn_clicked
 *************************************************************************/
void MainWindow::on_randBtn_clicked()
{
    bool valid = false;

    if(eqnDisplay.isEmpty())
        valid = true;
    else if(CheckIfMathOp(eqnDisplay.at(eqnDisplay.length()-1)))
        valid = true;

    if(valid) {
        int randNum = rand() % 100;
        eqnDisplay.append(QString::number(randNum));
        ui->screenLbl->setText(eqnDisplay);
    }
}

/**************************************************************************
 * on_degreeBtn_clicked
 *************************************************************************/
void MainWindow::on_degreeBtn_clicked()
{
    if(isDegree == true) {
        isDegree = false;
        ui->radDegreeLbl->setText("Radian");
    }
    else {
        isDegree = true;
        ui->radDegreeLbl->setText("Degree");
    }
}

/**************************************************************************
 * on_factorialBtn_clicked
 *************************************************************************/
void MainWindow::on_factorialBtn_clicked()
{
    if(!eqnDisplay.isEmpty()) {
        if(CheckIfNum(eqnDisplay.at(eqnDisplay.length() - 1)))
            eqnDisplay.append("!");
            ui->screenLbl->setText(eqnDisplay);
    }
}
