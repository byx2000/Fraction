#include "Fraction.h"

#include <cassert>

Fraction::Fraction()
{
    a = BigInt(1);
    b = BigInt(1);
    sign = 1;
}

Fraction::Fraction(long long a, long long b)
{
    assign(BigInt(a), BigInt(b));
}

Fraction::Fraction(const string &a, const string &b)
{
    assign(BigInt(a), BigInt(b));
}

Fraction::Fraction(const BigInt &a, const BigInt &b)
{
    assign(a, b);
}

Fraction::Fraction(long long i)
{
    assign(BigInt(i), BigInt(1));
}

Fraction::Fraction(const string &s)
{
    //解析"a/b"格式的字符串
    unsigned index = s.find('/');
    if (index == string::npos)
    {
        assign(BigInt(s), BigInt(1));
    }
    else
    {
        string s1(s.begin(), s.begin() + index);
        string s2(s.begin() + index + 1, s.end());

        assign(BigInt(s1), BigInt(s2));
    }
}

Fraction::Fraction(const BigInt &num)
{
    assign(num, BigInt(1));
}

void Fraction::assign(const BigInt &a, const BigInt &b)
{
    assert(b != BigInt(0));

    this->a = a.bigAbs();
    this->b = b.bigAbs();

    if ((a.getSign() == b.getSign()) || a == BigInt(0))
    {
        sign = 1;
    }
    else
    {
        sign = -1;
    }

    reduce();
}

string Fraction::toString() const
{
    if (a == BigInt(0))
    {
        return "0";
    }
    else if (b == BigInt(1))
    {
        return (sign == 1) ? a.toString() : ("-" + a.toString());
    }
    else
    {
        string s = "";
        if (sign == -1)
        {
            s += "-";
        }
        s += a.toString();
        s += '/';
        s += b.toString();
        return s;
    }
}

int Fraction::getSign() const
{
    return sign;
}

void Fraction::reduce()
{
    BigInt fac = Gcd(a, b);
    a /= fac;
    b /= fac;
}

bool Fraction::operator==(const Fraction &f) const
{
    if (a == BigInt(0) && f.a == BigInt(0))
    {
        return true;
    }
    return (sign == f.sign) && (a == f.a) && (b == f.b);
}

bool Fraction::operator!=(const Fraction &f) const
{
    return !((*this) == f);
}

bool Fraction::operator<(const Fraction &f) const
{
    if (sign != f.sign)
    {
        return sign == -1;
    }
    else
    {
        if (a * f.b < b * f.a)
        {
            return (sign == 1) ? true : false;
        }
        else if (a * f.b > b * f.a)
        {
            return (sign == 1) ? false : true;
        }
        else
        {
            return false;
        }
    }
}

bool Fraction::operator>(const Fraction &f) const
{
    if (sign != f.sign)
    {
        return sign == 1;
    }
    else
    {
        if (a * f.b < b * f.a)
        {
            return (sign == 1) ? false : true;
        }
        else if (a * f.b > b * f.a)
        {
            return (sign == 1) ? true : false;
        }
        else
        {
            return false;
        }
    }
}

Fraction Fraction::operator+(const Fraction &f) const
{
    Fraction res;
    if (sign == f.sign)
    {
        res.assign(a * f.b + b * f.a, b * f.b);
        res.sign = sign;
    }
    else
    {
        BigInt delta = a * f.b - b * f.a;
        res.assign(delta, b * f.b);
        if (delta > BigInt(0))
        {
            res.sign = sign;
        }
        else if (delta < BigInt(0))
        {
            res.sign = f.sign;
        }
        else
        {
            res.sign = 1;
        }
    }

    return res;
}

Fraction Fraction::operator+=(const Fraction &f)
{
    return (*this) = (*this) + f;
}

Fraction Fraction::operator-(const Fraction &f) const
{
    Fraction t = f;
    t.sign = -t.sign;
    return (*this) + t;
}

Fraction Fraction::operator-=(const Fraction &f)
{
    return (*this) = (*this) - f;
}

Fraction Fraction::operator*(const Fraction &f) const
{
    Fraction res;
    res.assign(a * f.a, b * f.b);

    if (sign == f.sign)
    {
        res.sign = 1;
    }
    else
    {
        res.sign = -1;
    }
    return res;
}

Fraction Fraction::operator*=(const Fraction &f)
{
    return (*this) = (*this) * f;
}

Fraction Fraction::operator/(const Fraction &f) const
{
    assert(f.a != BigInt(0));

    Fraction res;
    res.assign(a * f.b, b * f.a);
    if (sign == f.sign)
    {
        res.sign = 1;
    }
    else
    {
        res.sign = -1;
    }
    return res;
}

Fraction Fraction::operator/=(const Fraction &f)
{
    return (*this) = (*this) / f;
}

Fraction Fraction::operator^(const BigInt &num) const
{
    assert(num >= BigInt(0));

    Fraction res(a ^ num, b ^ num);
    if (num.getDigit(0) % 2 == 0)
    {
        res.sign = 1;
    }
    else
    {
        res.sign = sign;
    }
    return res;
}

Fraction Fraction::operator^=(const BigInt &num)
{
    return (*this) = (*this) ^ num;
}

ostream& operator<<(ostream &out, const Fraction &f)
{
	out << f.toString();
	return out;
}
