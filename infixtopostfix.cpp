#include "infixtopostfix.h"

/**************************************************************************
 * InfixToPostfix
 *************************************************************************/
InfixToPostfix::InfixToPostfix()
{
    infixStr   = "";
    postfixStr = "";
}

/**************************************************************************
 *                          INFIX TO POSTFIX
 * ------------------------------------------------------------------------
 *                      GetInfixToPostfix
 *                      GetCalculatedPostfix
 *************************************************************************/

/**************************************************************************
 * GetInfixToPostfix
 *************************************************************************/
QString InfixToPostfix::GetInfixToPostfix(const QString str) {
    infixStr = str;
    infixStr = ChangeUnarySymbols(infixStr);
    return ConvertInfixToPostfix(infixStr);
}

/**************************************************************************
 * GetCalculatedPostfix
 *************************************************************************/
QString InfixToPostfix::GetCalculatedPostfix(const QString exp,
                                             const bool isDeg) {
    postfixStr = exp;
    return EvaluatePostFix(postfixStr, isDeg);
}

/**************************************************************************
 * ChangeUnarySymbols
 *************************************************************************/
QString InfixToPostfix::ChangeUnarySymbols(QString str) {
    str = str.replace("ln", "l");
    str = str.replace("log", "L");

    str = str.replace("invSinh", "H");
    str = str.replace("invCosh", "J");
    str = str.replace("invTanh", "K");

    str = str.replace("invSin", "S");
    str = str.replace("invCos", "C");
    str = str.replace("invTan", "T");

    str = str.replace("sinh", "h");
    str = str.replace("cosh", "j");
    str = str.replace("tanh", "k");

    str = str.replace("sin", "s");
    str = str.replace("cos", "c");
    str = str.replace("tan", "t");

    while(str.contains("sqrt")) {
        str = ReplaceSqrt(str);
    }

    while(str.contains("cuberoot")) {
        str = ReplaceCubeRoot(str);
    }

    while(str.contains("root")) {
        str = ReplaceXRootY(str);
    }

    str = str.replace("^-", "^~");
    str = str.replace("*-", "*~");
    str = str.replace("/-", "/~");
    str = str.replace("+-", "+~");
    str = str.replace("--", "-~");
    str = str.replace("(-", "(~");

    if(str.startsWith("-")) {
        str = str.replace(0, 1, "~");
    }

    infixStr = str;

    return infixStr;
}

/**************************************************************************
 * ReplaceSqrt
 *************************************************************************/
QString InfixToPostfix::ReplaceSqrt(const QString theStr) {
    QString str         = theStr;
    int     index       = str.indexOf("sqrt(");
    int     countOpen   = 0;
    int     countClose  = 0;

    if(index != -1) {
        QString replace;
        bool run = true;

        str.remove(index, 4);
        int i = index;
        while(i < str.length() && run) {
            if(str.at(i) == '(') {
                countOpen++;
            }
            else if(str.at(i) == ')') {
                countClose++;
            }

            if(countOpen != countClose) {
                replace.append(str.at(i));
            }
            else {
                run = false;
            }
            i++;
        }
        str.insert(i, "@");
    }
    return str;
}

/**************************************************************************
 * ReplaceCubeRoot
 *************************************************************************/
QString InfixToPostfix::ReplaceCubeRoot(const QString theStr) {
    QString str         = theStr;
    int     index       = str.indexOf("cuberoot(");
    int     countOpen   = 0;
    int     countClose  = 0;

    if(index != -1) {
        QString replace;
        bool run = true;

        str.remove(index, 8);
        int i = index;
        while(i < str.length() && run) {
            if(str.at(i) == '(') {
                countOpen++;
            }
            else if(str.at(i) == ')') {
                countClose++;
            }

            if(countOpen != countClose) {
                replace.append(str.at(i));
            }
            else {
                run = false;
            }
            i++;
        }
        str.insert(i, "#");
    }
    return str;
}

/**************************************************************************
 * ReplaceXRootY
 *************************************************************************/
QString InfixToPostfix::ReplaceXRootY(const QString theStr) {
    QString str         = theStr;
    int     index       = str.indexOf("root(");
    QString theNum      = "";
    int     countOpen   = 0;
    int     countClose  = 0;
    bool run;
        int count = 0;

    if(index != -1) {
        int ind = index - 1;
        QChar ch;
        run = true;
        while(run) {
            if(ind >= 0) {
                ch = str.at(ind);
                if(ch == '0' || ch == '1' || ch == '2' ||
                   ch == '3' || ch == '4' || ch == '5' ||
                   ch == '6' || ch == '7' || ch == '8' || ch == '9' || ch == '.'){
                    theNum.push_front(ch);
                    count++;
                    ind--;
                }
                else if(ch == '-') {
                    if(ind > 0) {
                        QChar temp = str.at(ind - 1);
                        if(temp == '*' || temp == '/' || temp == '-' ||
                           temp == '+' || temp == '%') {
                            theNum.push_front(temp);
                            count++;
                            run = false;
                        }
                    }
                    else {
                        theNum.push_front(ch);
                        count++;
                        run = false;
                    }
                }
                else
                    run = false;
            }
            else
                run = false;
        }
    }

    if(index != -1) {
        QString replace;
        run = true;

        str.remove(index, 4);
        int i = index;
        while(i < str.length() && run) {
            if(str.at(i) == '(') {
                countOpen++;
            }
            else if(str.at(i) == ')') {
                countClose++;
            }

            if(countOpen != countClose) {
                replace.append(str.at(i));
            }
            else {
                run = false;
            }
            i++;
        }
        str.insert(i, "^(1/" + theNum + ")");
        str.remove(index - count, count);
    }
    return str;
}

/**************************************************************************
 * InfixToPostfix
 * ------------------------------------------------------------------------
 * Used to calculate math problem!
 *************************************************************************/
QString InfixToPostfix::ConvertInfixToPostfix(QString eqnSolve) {
    QStack<QChar> theOpStack;
    QString postfix = "";
    QStack<QString> out;

    infixStr = eqnSolve;

    for(int i = 0; i < eqnSolve.length(); i++)
    {
        if(IsOperand(eqnSolve.at(i))) {
            QString str = eqnSolve.at(i);
            while((i + 1) < eqnSolve.length() )
                if(IsOperand(eqnSolve.at(i+1))) {
                    str += eqnSolve.at(i+1);
                    i++;
                }
                else
                    break;
            out.push(str);
        }
        else if(IsBinaryOperator(eqnSolve.at(i)))
        {
            while(!theOpStack.empty() && !IsOpeningParen(theOpStack.top()) &&
                  HasHigherPrecedence(theOpStack.top(), eqnSolve.at(i)))
            {
                out.push(theOpStack.top());
                theOpStack.pop();
            }
            theOpStack.push(eqnSolve.at(i));
        }
        else if(IsUnaryOperator(eqnSolve.at(i)))
        {
            theOpStack.push(eqnSolve.at(i));
        }
        else if(IsOpeningParen(eqnSolve.at(i))) {
            theOpStack.push(eqnSolve.at(i));
        }
        else if(eqnSolve.at(i) == ')') {
            while(!theOpStack.empty() && !IsOpeningParen(theOpStack.top())) {
                out.push(theOpStack.top());
                theOpStack.pop();
            }
            theOpStack.pop();
        }
    } // End for

    while(!theOpStack.empty()) {
        out.push(theOpStack.top());
        theOpStack.pop();
    }

    for(int k =0 ; k < out.length() ; k++) {
        postfix = postfix + out[k] + " ";
    }

    postfixStr = postfix;

    return postfixStr;
}

/**************************************************************************
 * IsBinaryOperator
 *************************************************************************/
bool InfixToPostfix::IsBinaryOperator(QChar oper) {
    for(int i = 0; i < MathOp::BINARY_AR_SIZE; i++) {
        if(MathOp::BinaryOpArr[i] == oper)
            return true;
    }
    return false;
}

/**************************************************************************
 * IsUnaryOperator
 *************************************************************************/
bool InfixToPostfix::IsUnaryOperator(QChar oper) {
    for(int i = 0; i < MathOp::UNARY_AR_SIZE; i++) {
        if(MathOp::UnaryOpArr[i] == oper)
            return true;
    }
    return false;
}

/**************************************************************************
 * IsOpeningParen
 *************************************************************************/
bool InfixToPostfix::IsOpeningParen(QChar ch) {
    if(ch == '(')
        return true;
    return false;
}

/**************************************************************************
 * IsOperand
 *************************************************************************/
bool InfixToPostfix::IsOperand(QChar ch) {
    if(ch.isDigit() || ch == '.' || ch == MathSymbols::MATH_SYMBOL_PI
            || ch == 'e')
        return true;
    return false;
}

/**************************************************************************
 * HasHigherPrecedence
 *************************************************************************/
bool InfixToPostfix::HasHigherPrecedence(const QChar topOfStackOper,
                                         const QChar eqnDisplayOper) {
    int precTopOfStack     = GetPrecedence(topOfStackOper);
    int preceqnDisplayOper = GetPrecedence(eqnDisplayOper);

    if(precTopOfStack <= preceqnDisplayOper)
        return true;
    return false;
}

/**************************************************************************
 * GetPrecedence
 *************************************************************************/
int InfixToPostfix::GetPrecedence(const QChar oper) {
    int prec;
    if(oper == '^')
        prec = MathPrec::POWER_PREC;
    else if(oper == '*')
        prec = MathPrec::MULT_PREC;
    else if(oper == '/')
        prec = MathPrec::DIV_PREC;
    else if(oper == '%')
        prec = MathPrec::MOD_PREC;
    else if(oper == '+')
        prec = MathPrec::ADD_PREC;
    else if(oper == '-')
        prec = MathPrec::SUB_PREC;
    else
        prec = MathPrec::PAREN_PREC;
    return prec;
}

/**************************************************************************
 * EvaluatePostFix
 *************************************************************************/
QString InfixToPostfix::EvaluatePostFix(QString exp, bool isDeg) {
    QStack<QString> theStack;
    QString         res;
    QString         op1;
    QString         op2;
    QString         unOp;
    QString         num;
    Calc            theCalc;
    int             index;

    for(int i = 0; i < exp.length(); i++) {
        num = "";
        if(IsOperand(exp.at(i))) {
            num = num.append(exp.at(i));
            while((i + 1) < exp.length()) {
                if(IsOperand(exp.at(i+1))) {
                    num = num.append(exp.at(i+1));
                    i++;
                }
                else
                    break;
            }
            theStack.push(num);
        }
        else if(IsUnaryOperator(exp.at(i))) {
            index = FindUnaryOpIndex(exp.at(i));
            unOp  = theStack.pop();
            res   = theCalc.CalculateUnary(index, unOp, isDeg);
            theStack.push(res);
        }
        else if(IsBinaryOperator(exp.at(i)))
        {
            op2   = theStack.pop();
            op1   = theStack.pop();
            index = FindBinaryOpIndex(exp.at(i));
            res   = theCalc.CalculateBinary(index, op1, op2);
            theStack.push(res);
        }
    }
    return res;
}

/**************************************************************************
 * FindUnaryOpIndex
 *************************************************************************/
int InfixToPostfix::FindUnaryOpIndex(QChar theOp) {
    int index;

    for(index = 0; index < MathOp::UNARY_AR_SIZE; index++) {
        if(MathOp::UnaryOpArr[index] == theOp)
            return index;
    }
    return -1;
}

/**************************************************************************
 * FindBinaryOpIndex
 *************************************************************************/
int InfixToPostfix::FindBinaryOpIndex(QChar theOp) {
    int     index;

    for(index = 0; index < MathOp::BINARY_AR_SIZE; index++) {
        if(MathOp::BinaryOpArr[index] == theOp)
            return index;
    }
    return -1;
}
