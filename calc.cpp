#include "calc.h"

Calc::Calc()
{

}

/**************************************************************************
 *                          Validate
 * ------------------------------------------------------------------------
 *                          IntOutOfBounds
 *                          FloatOutOfBounds
 *************************************************************************/

/**************************************************************************
 * IntOutOfBounds
 *************************************************************************/
bool Calc::IntOutOfBounds(int aNum) const {
    if(aNum <= INT_MIN && aNum >= INT_MAX)
        return true;
    return false;
}

/**************************************************************************
 * FloatOutOfBounds
 *************************************************************************/
bool Calc::FloatOutOfBounds(float aNum) const {
    if(aNum <= FLT_MIN && aNum >= FLT_MAX)
        return true;
    return false;
}

/**************************************************************************
 *                          Calculate
 * ------------------------------------------------------------------------
 *                          CalculateUnary
 *                          CalculateBinary
 *************************************************************************/

/**************************************************************************
 * CalculateUnary
 *************************************************************************/
QString Calc::CalculateUnary(int theOp, QString num1, bool isDeg) {
    QString total = "";

    if(PICalculate(num1))
        num1 = QString::number(M_PI);

    if(ECaclulate(num1))
        num1 = QString::number(M_E);

    switch(theOp) {
    case NEGATE   : total = Negate(num1);
                    break;
    case LN       : total = NaturalLog(num1);
                    break;
    case LOG      : total = Log(num1);
                    break;
    case SIN      : total = Sin(num1, isDeg);
                    break;
    case COS      : total = Cos(num1, isDeg);
                    break;
    case TAN      : total = Tan(num1, isDeg);
                    break;
    case INVSIN   : total = InvSin(num1, isDeg);
                    break;
    case INVCOS   : total = InvCos(num1, isDeg);
                    break;
    case INVTAN   : total = InvTan(num1, isDeg);
                    break;
    case SINH     : total = Sinh(num1, isDeg);
                    break;
    case COSH     : total = Cosh(num1, isDeg);
                    break;
    case TANH     : total = Tanh(num1, isDeg);
                    break;
    case INVSINH  : total = InvSinh(num1, isDeg);
                    break;
    case INVCOSH  : total = InvCosh(num1, isDeg);
                    break;
    case INVTANH  : total = InvTanh(num1, isDeg);
                    break;
    case FACTORIAL: total = Factorial(num1);
                    break;
    case SQRT     : total = SquareRoot(num1);
                    break;
    case CUBERT   : total = CubeRoot(num1);
                    break;
    default: total = "ERROR";
        break;
    }
    return total;
}

/**************************************************************************
 * CalculateBinary
 *************************************************************************/
QString Calc::CalculateBinary(int theOp, QString num1, QString num2) {
    QString total = "";

    if(PICalculate(num1))
        num1 = QString::number(M_PI);

    if(PICalculate(num2))
        num2 = QString::number(M_PI);

    if(ECaclulate(num1))
        num1 = QString::number(M_E);

    if(ECaclulate(num2))
        num2 = QString::number(M_E);

    switch(theOp) {
        case POWER    : total = Power(num1, num2);
                        break;
        case MULTIPLY : total = Multiply(num1, num2);
                        break;
        case DIVIDE   : total = Divide(num1, num2);
                        break;
        case MODULO   : total = Modulo(num1, num2);
                        break;
        case ADD      : total = Add(num1, num2);
                        break;
        case SUBTRACT : total = Subtract(num1, num2);
                        break;
        default       : total = "ERROR";
                        break;
    }

   return total;
}

/**************************************************************************
 *                          Calculate Constants
 * ------------------------------------------------------------------------
 *                          PICalculate
 *                          ECaclulate
 *                          RadToDeg
 *************************************************************************/
/**************************************************************************
 * PICalculate
 *************************************************************************/
bool Calc::PICalculate(QString ch) const {
    if(ch == MathSymbols::MATH_SYMBOL_PI)
        return true;
    return false;
}

/**************************************************************************
 * ECaclulate
 *************************************************************************/
bool Calc::ECaclulate(QString ch) const {
    if(ch == "e")
        return true;
    return false;
}

/**************************************************************************
 * RadToDeg
 *************************************************************************/
QString Calc::RadToDeg(QString theNum) {
    return QString::number(theNum.toFloat() * (M_PI / 180));
}

/**************************************************************************
 *                  Calculate Binary Operators
 * ------------------------------------------------------------------------
 *                          Power
 *                          Multiply
 *                          Divide
 *                          Modulo
 *                          Add
 *                          Subtract
 *************************************************************************/

/**************************************************************************
 * Power
 *************************************************************************/
QString Calc::Power(QString num1, QString num2) {
    bool ok1;
    bool ok2;
    bool invalidPow = false;
    float thePow;

    num1.toFloat(&ok1);
    num2.toFloat(&ok2);

    if(ok1 && ok2) {
        thePow = pow(num1.toFloat(), num2.toFloat());
        invalidPow = FloatOutOfBounds(thePow);
    }

    if(!invalidPow && ok1 && ok2)
        return QString::number(thePow);
    else
        return "ERROR";
}

/**************************************************************************
 * Multiply
 *************************************************************************/
QString Calc::Multiply(QString num1, QString num2) {
    bool ok1;
    bool ok2;
    bool invalidMul = false;
    float  mul;

    num1.toFloat(&ok1);
    num2.toFloat(&ok2);

    if(ok1 && ok2) {
        mul = num1.toFloat() * num2.toFloat();
        invalidMul = FloatOutOfBounds(mul);
    }

    if(!invalidMul && ok1 && ok2) {
        return QString::number(mul);
    }
    else
        return "ERROR";
}

/**************************************************************************
 * Divide
 *************************************************************************/
QString Calc::Divide(QString num1, QString num2) {
    bool ok1;
    bool ok2;
    bool invalidDiv = false;
    float div;

    num1.toFloat(&ok1);
    num2.toFloat(&ok2);

    if(ok1 && ok2 && num2.toFloat() != 0) {
        div = num1.toFloat() / num2.toFloat();
        invalidDiv = FloatOutOfBounds(div);
    }

    if(!invalidDiv && ok1 && ok2 && num2.toFloat() != 0)
        return QString::number(div);
    else
        return "ERROR";

}

/**************************************************************************
 * Modulo
 *************************************************************************/
QString Calc::Modulo(QString num1, QString num2) {
    bool ok1;
    bool ok2;
    bool invalidMod = false;
    float theMod;

    if(!num1.contains(".") && !num2.contains(".")) {
        num1.toInt(&ok1);
        num2.toInt(&ok2);

        if(ok1 && ok2) {
            theMod = num1.toInt() % num2.toInt();
            invalidMod = IntOutOfBounds(theMod);
        }

        if(!invalidMod && ok1 && ok2)
            return QString::number(theMod);
        else return "ERROR";
    }
    else {
        return "ERROR";
    }

}

/**************************************************************************
 * Add
 *************************************************************************/
QString Calc::Add(QString num1, QString num2) {
    bool ok1;
    bool ok2;
    bool invalidAdd = false;
    float added;

    num1.toFloat(&ok1);
    num2.toFloat(&ok2);

    if(ok1 && ok2) {
        added = num1.toFloat() + num2.toFloat();
        invalidAdd = FloatOutOfBounds(added);
    }

    if(!invalidAdd && ok1 && ok2)
        return QString::number(added);
    else
        return "ERROR";
}

/**************************************************************************
 * Subtract
 *************************************************************************/
QString Calc::Subtract(QString num1, QString num2) {
    bool ok1;
    bool ok2;
    bool invalidSub = false;
    float sub;

    num1.toFloat(&ok1);
    num2.toFloat(&ok2);

    if(ok1 && ok2) {
        sub = num1.toFloat() - num2.toFloat();
        invalidSub = FloatOutOfBounds(sub);
    }

    if(!invalidSub && ok1 && ok2)
        return QString::number(sub);
    else
        return "ERROR";
}

/**************************************************************************
 *                  Calculate Unary Operators
 * ------------------------------------------------------------------------
 *                          Negate
 *                          Log
 *                          NaturalLog
 *                          Sin
 *                          Cos
 *                          Tan
 *                          InvSin
 *                          InvCos
 *                          InvTan
 *                          Sinh
 *                          Cosh
 *                          Tanh
 *                          InvSinh
 *                          InvCosh
 *                          InvTanh
 *                          Factorial
 *                          SquareRoot
 *                          CubeRoot
 *                          XRootY
 *************************************************************************/

/**************************************************************************
 * Negate
 *************************************************************************/
QString Calc::Negate(QString num) {
    float negatedNum;
    bool  ok;
    bool  invalidNegate;

    num.toFloat(&ok);
    negatedNum    = num.toFloat() * - 1;
    invalidNegate = FloatOutOfBounds(negatedNum);

    if(!invalidNegate && ok)
        return QString::number(negatedNum);
    else
        return "ERROR";
}

/**************************************************************************
 * Log
 *************************************************************************/
QString Calc::Log(QString num) {
    float logNum;
    bool  ok;
    bool  invalidLog;

    num.toFloat(&ok);
    logNum     = log10(num.toFloat());
    invalidLog = FloatOutOfBounds(logNum);

    if(!invalidLog && ok)
        return QString::number(logNum);
    else
        return "ERROR";
}

/**************************************************************************
 * NaturalLog
 *************************************************************************/
QString Calc::NaturalLog(QString num) {
    float lnNum;
    bool  ok;
    bool  invalidLn;

    num.toFloat(&ok);
    lnNum     = log(num.toFloat());
    invalidLn = FloatOutOfBounds(lnNum);

    if(!invalidLn && ok)
        return QString::number(lnNum);
    else
        return "ERROR";
}

/**************************************************************************
 * Sin
 *************************************************************************/
QString Calc::Sin(QString num, bool isDeg) {
    float sinNum;
    bool  ok;
    bool  invalidSin;

    if(isDeg)
        num = RadToDeg(num);

    num.toFloat(&ok);
    sinNum     = sin(num.toFloat());
    invalidSin = FloatOutOfBounds(sinNum);

    if(!invalidSin && ok)
        return QString::number(sinNum);
    else
        return "ERROR";
}

/**************************************************************************
 * Cos
 *************************************************************************/
QString Calc::Cos(QString num, bool isDeg) {
    float cosNum;
    bool  ok;
    bool  invalidCos;

    if(isDeg)
        num = RadToDeg(num);

    num.toFloat(&ok);
    cosNum     = cos(num.toFloat());
    invalidCos = FloatOutOfBounds(cosNum);

    if(!invalidCos && ok)
        return QString::number(cosNum);
    else
        return "ERROR";
}

/**************************************************************************
 * Tan
 *************************************************************************/
QString Calc::Tan(QString num, bool isDeg) {
    float tanNum;
    bool  ok;
    bool  invalidTan;

    if(isDeg)
        num = RadToDeg(num);

    num.toFloat(&ok);
    tanNum     = tan(num.toFloat());
    invalidTan = FloatOutOfBounds(tanNum);

    if(!invalidTan && ok)
        return QString::number(tanNum);
    else
        return "ERROR";
}

/**************************************************************************
 * InvSin
 *************************************************************************/
QString Calc::InvSin(QString num, bool isDeg) {
    float invSinNum;
    bool  ok;
    bool  invalid;

    if(isDeg)
        num = RadToDeg(num);

    num.toFloat(&ok);
    invSinNum = asin(num.toFloat());
    invalid   = FloatOutOfBounds(invSinNum);

    if(!invalid && ok)
        return QString::number(invSinNum);
    else
        return "ERROR";
}

/**************************************************************************
 * InvCos
 *************************************************************************/
QString Calc::InvCos(QString num, bool isDeg) {
    float invCosNum;
    bool  ok;
    bool  invalid;

    if(isDeg)
        num = RadToDeg(num);

    num.toFloat(&ok);
    invCosNum = acos(num.toFloat());
    invalid   = FloatOutOfBounds(invCosNum);

    if(!invalid && ok)
        return QString::number(invCosNum);
    else
        return "ERROR";
}

/**************************************************************************
 * InvTan
 *************************************************************************/
QString Calc::InvTan(QString num, bool isDeg) {
    float invTanNum;
    bool  ok;
    bool  invalid;

    if(isDeg)
        num = RadToDeg(num);

    num.toFloat(&ok);
    invTanNum = atan(num.toFloat());
    invalid   = FloatOutOfBounds(invTanNum);

    if(!invalid && ok)
        return QString::number(invTanNum);
    else
        return "ERROR";
}

/**************************************************************************
 * Sinh
 *************************************************************************/
QString Calc::Sinh(QString num, bool isDeg) {
    float sinhNum;
    bool  ok;
    bool  invalid;

    if(isDeg)
        num = RadToDeg(num);

    num.toFloat(&ok);
    sinhNum = sinh(num.toFloat());
    invalid = FloatOutOfBounds(sinhNum);

    if(!invalid && ok)
        return QString::number(sinhNum);
    else
        return "ERROR";
}

/**************************************************************************
 * Cosh
 *************************************************************************/
QString Calc::Cosh(QString num, bool isDeg) {
    float coshNum;
    bool  ok;
    bool  invalid;

    if(isDeg)
        num = RadToDeg(num);

    num.toFloat(&ok);
    coshNum = cosh(num.toFloat());
    invalid = FloatOutOfBounds(coshNum);

    if(!invalid && ok)
        return QString::number(coshNum);
    else
        return "ERROR";
}

/**************************************************************************
 * Tanh
 *************************************************************************/
QString Calc::Tanh(QString num, bool isDeg) {
    float tanhNum;
    bool  ok;
    bool  invalid;

    if(isDeg)
        num = RadToDeg(num);

    num.toFloat(&ok);
    tanhNum = tanh(num.toFloat());
    invalid = FloatOutOfBounds(tanhNum);

    if(!invalid && ok)
        return QString::number(tanhNum);
    else
        return "ERROR";
}

/**************************************************************************
 * InvSinh
 *************************************************************************/
QString Calc::InvSinh(QString num, bool isDeg) {
    float invSinh;
    bool  ok;
    bool  invalid;

    if(isDeg)
        num = RadToDeg(num);

    num.toFloat(&ok);
    invSinh = asinh(num.toFloat());
    invalid = FloatOutOfBounds(invSinh);

    if(!invalid && ok)
        return QString::number(invSinh);
    else
        return "ERROR";
}

/**************************************************************************
 * InvCosh
 *************************************************************************/
QString Calc::InvCosh(QString num, bool isDeg) {
    float invCosh;
    bool  ok;
    bool  invalid;

    if(isDeg)
        num = RadToDeg(num);

    num.toFloat(&ok);
    invCosh = acosh(num.toFloat());
    invalid = FloatOutOfBounds(invCosh);

    if(!invalid && ok)
        return QString::number(invCosh);
    else
        return "ERROR";
}

/**************************************************************************
 * InvTanh
 *************************************************************************/
QString Calc::InvTanh(QString num, bool isDeg) {
    float invtanh;
    bool  ok;
    bool  invalid;

    if(isDeg)
        num = RadToDeg(num);

    num.toFloat(&ok);
    invtanh = atanh(num.toFloat());
    invalid = FloatOutOfBounds(invtanh);

    if(!invalid && ok)
        return QString::number(invtanh);
    else
        return "ERROR";
}

/**************************************************************************
 * Factorial
 *************************************************************************/
QString Calc::Factorial(QString num) {
    if(num.contains(".")) {
        return "ERROR";
    }
    else {
        bool ok;
        bool invalid = false;
        int  factTotal;

        num.toInt(&ok, 10);
        factTotal = 1;

        for(int i = num.toInt(); i > 0; --i) {
            factTotal *= i;
        }
        invalid = IntOutOfBounds(factTotal);

        if(!invalid && ok)
            return QString::number(factTotal);
        else
            return "ERROR";
    }
}

/**************************************************************************
 * SquareRoot
 *************************************************************************/
QString Calc::SquareRoot(QString num) {
    bool ok;
    float sqrtNum;
    bool invalid;

    sqrtNum = sqrt(num.toFloat(&ok));
    invalid = FloatOutOfBounds(sqrtNum);

    if(!invalid && ok)
        return QString::number(sqrtNum);
    else
        return "ERROR";
}

/**************************************************************************
 * CubeRoot
 *************************************************************************/
QString Calc::CubeRoot(QString num) {
    bool ok;
    float cbrtNum;
    bool invalid;

    cbrtNum = cbrt(num.toFloat(&ok));
    invalid = FloatOutOfBounds(cbrtNum);

    if(!invalid && ok)
        return QString::number(cbrtNum);
    else
        return "ERROR";
}
