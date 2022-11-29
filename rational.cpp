#include "rational.h"

unsigned gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);
    if ((a == 0) || (b == 0))
    {
        return(a + b);
    }
    else
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
        gcd(a, b);
    }
}

Rational::Rational(int numerator, int denominator) // на совести пользователя введение ненулевого значения знаменателя
{
    int nod = gcd(numerator, denominator);

    if (denominator < 0)
    {
        this->denominator_ = -denominator / nod;
        this->numerator_ = -numerator / nod;
    }
    else
    {
        this->numerator_ = numerator / nod;
        this->denominator_ = denominator / nod;
    }
}

int Rational::get_num() const
{
    return numerator_;
}

int Rational::get_den() const
{
    return denominator_;
}

void Rational::add(Rational rational)
{
    int d = this->denominator_ * rational.denominator_;
    int n = this->numerator_ * rational.denominator_ + rational.numerator_ * this->denominator_;
    int nod = gcd(d, n);
    this->denominator_ = d / nod;
    this->numerator_ = n / nod;
}

void Rational::sub(Rational rational)
{
    int d = this->denominator_ * rational.denominator_;
    int n = this->numerator_ * rational.denominator_ - rational.numerator_ * this->denominator_;
    int nod = gcd(d, n);
    this->denominator_ = d / nod;
    this->numerator_ = n / nod;
}

void Rational::mul(Rational rational)
{
    int d = this->denominator_ * rational.denominator_;
    int n = this->numerator_ * rational.numerator_;
    int nod = gcd(d, n);
    this->denominator_ = d / nod;
    this->numerator_ = n / nod;
}

void Rational::div(Rational rational)
{
    int d = this->denominator_ * rational.numerator_;
    int n = this->numerator_ * rational.denominator_;
    int nod = gcd(d, n);
    this->denominator_ = d / nod;
    this->numerator_ = n / nod;
}

void Rational::neg()
{
    this->numerator_ = -this->numerator_;
}

void Rational::inv() {}

double Rational::to_double() const
{
    return numerator_ / (double)denominator_;;
}

Rational& Rational::operator+=(Rational rational)
{
    this->add(rational);
    return *this;
}

Rational& Rational::operator-=(Rational rational)
{
    this->sub(rational);
    return *this;
}

Rational& Rational::operator*=(Rational rational)
{
    this->mul(rational);
    return *this;
}

Rational& Rational::operator/=(Rational rational)
{
    this->div(rational);
    return *this;
}

Rational Rational::operator-() const
{
    return Rational(-this->numerator_, this->denominator_);
}

Rational Rational::operator+() const
{
    return Rational(this->numerator_, this->denominator_);
}

Rational operator+(Rational lhs, Rational rhs)
{
    return lhs += rhs;
}

Rational operator-(Rational lhs, Rational rhs)
{
    return lhs -= rhs;
}

Rational operator*(Rational lhs, Rational rhs)
{
    return lhs *= rhs;
}

Rational operator/(Rational lhs, Rational rhs)
{
    return lhs /= rhs;
}

bool operator==(Rational lhs, Rational rhs)
{
    lhs -= rhs;
    if (lhs.get_num() == 0)
        return true;
    else
        return false;
}

bool operator<(Rational lhs, Rational rhs)
{
    lhs -= rhs;
    if (lhs.get_num()*lhs.get_den() < 0)
        return true;
    else
        return false;
}

bool operator>(Rational lhs, Rational rhs)
{
    return (rhs < lhs);
}

bool operator!=(Rational lhs, Rational rhs)
{
    return !(lhs == rhs);
}

bool operator<=(Rational lhs, Rational rhs)
{
    return !(rhs < lhs);
}

bool operator>=(Rational lhs, Rational rhs)
{
    return !(lhs < rhs);
}
