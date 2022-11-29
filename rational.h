#include<math.h>

struct Rational
{
    Rational(int numerator = 0, int denominator = 1); // на совести пользователя введение ненулевого значения знаменателя

    void add(Rational rational);
    void sub(Rational rational);
    void mul(Rational rational);
    void div(Rational rational);

    void neg();
    void inv();
    double to_double() const;

    Rational& operator+=(Rational rational);
    Rational& operator-=(Rational rational);
    Rational& operator*=(Rational rational);
    Rational& operator/=(Rational rational);

    Rational operator-() const;
    Rational operator+() const;

    int get_num() const;
    int get_den() const;

private:
    int numerator_;
    int denominator_;
};

Rational operator+(Rational lhs, Rational rhs);
Rational operator-(Rational lhs, Rational rhs);
Rational operator*(Rational lhs, Rational rhs);
Rational operator/(Rational lhs, Rational rhs);

bool operator==(Rational lhs, Rational rhs);
bool operator!=(Rational lhs, Rational rhs);
bool operator<=(Rational lhs, Rational rhs);
bool operator>=(Rational lhs, Rational rhs);
bool operator<(Rational lhs, Rational rhs);
bool operator>(Rational lhs, Rational rhs);