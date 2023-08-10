#ifndef CALC_H
#define CALC_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <math.h>
#include <cmath>
#include <QStack>
#include <limits>
#include <float.h>

enum OpUnaryPrec {
    NEGATE,
    LN,
    LOG,
    SIN,
    COS,
    TAN,
    INVSIN,
    INVCOS,
    INVTAN,
    SINH,
    COSH,
    TANH,
    INVSINH,
    INVCOSH,
    INVTANH,
    FACTORIAL,
    SQRT,
    CUBERT
};

enum OpBinaryPrec {
    POWER,
    MULTIPLY,
    DIVIDE,
    MODULO,
    ADD,
    SUBTRACT
};

class Calc
{
public:
    Calc();
    QString CalculateBinary(int theOp, QString num1, QString num2);
    QString CalculateUnary(int theOp, QString num1, bool isDeg);

private slots:
    bool IntOutOfBounds(int theNum) const;
    bool FloatOutOfBounds(float aNum) const;

    bool PICalculate(QString ch) const;
    bool ECaclulate(QString ch) const;
    QString RadToDeg(QString theNum);

    QString Modulo(QString num1, QString num2);
    QString Power(QString num1, QString num2);
    QString Add(QString num1, QString num2);
    QString Subtract(QString num1, QString num2);
    QString Multiply(QString num1, QString num2);
    QString Divide(QString num1, QString num2);

    QString Negate(QString num);
    QString Log(QString num);
    QString NaturalLog(QString num);
    QString Sin(QString num, bool isDeg);
    QString Cos(QString num, bool isDeg);
    QString Tan(QString num, bool isDeg);
    QString InvSin(QString num, bool isDeg);
    QString InvCos(QString num, bool isDeg);
    QString InvTan(QString num, bool isDeg);
    QString Sinh(QString num, bool isDeg);
    QString Cosh(QString num, bool isDeg);
    QString Tanh(QString num, bool isDeg);
    QString InvSinh(QString num, bool isDeg);
    QString InvCosh(QString num, bool isDeg);
    QString InvTanh(QString num, bool isDeg);
    QString Factorial(QString num);
    QString SquareRoot(QString num);
    QString CubeRoot(QString num);
};

#endif // CALC_H
