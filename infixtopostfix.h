#ifndef INFIXTOPOSTFIX_H
#define INFIXTOPOSTFIX_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calc.h"

namespace MathPrec {
    const int PAREN_PREC = 1;
    const int POWER_PREC = 2;
    const int MULT_PREC  = 3;
    const int DIV_PREC   = 3;
    const int MOD_PREC   = 3;
    const int ADD_PREC   = 4;
    const int SUB_PREC   = 4;
}

namespace MathOp {
    const int   BINARY_AR_SIZE = 6;
    const int   UNARY_AR_SIZE  = 18;
    const QChar BinaryOpArr[]  = {'^', '*', '/', '%', '+', '-'};
    const QChar UnaryOpArr[]   = {'~', 'l', 'L', 's', 'c', 't', 'S', 'C',
                                  'T', 'h', 'j', 'k', 'H', 'J', 'K', '!',
                                  '@', '#'};
}

class InfixToPostfix
{
public:
    InfixToPostfix();

    QString GetInfixToPostfix(const QString str);
    QString GetCalculatedPostfix(const QString exp, const bool isDeg);

private slots:
    QString ConvertInfixToPostfix(QString eqnSolve);
    QString ChangeUnarySymbols(QString str);
    QString ReplaceSqrt(const QString theStr);
    QString ReplaceCubeRoot(const QString theStr);
    QString ReplaceXRootY(const QString theStr);

    bool IsBinaryOperator(QChar oper);
    bool IsUnaryOperator(QChar oper);
    bool IsOperand(QChar ch);
    bool IsOpeningParen(QChar ch);
    int  GetPrecedence(const QChar oper);
    bool HasHigherPrecedence(const QChar topOfStackOper, const QChar eqnOper);

    QString EvaluatePostFix(QString exp, bool isDeg);
    int FindBinaryOpIndex(QChar theOp);
    int FindUnaryOpIndex(QChar theOp);

private:
    QString infixStr;
    QString postfixStr;
};

#endif // INFIXTOPOSTFIX_H
