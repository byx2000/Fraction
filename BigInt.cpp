#include <iostream>
#include <algorithm>
#include <cmath>
#include <cassert>

#include "BigInt.h"

BigInt::BigInt()
{
    sign = 1;
    d.push_back(0);
}

BigInt::BigInt(long long i)
{
    assign(i);
}

BigInt::BigInt(const string &s)
{
    assign(s);
}

void BigInt::assign(long long i)
{
    d.clear();
    sign = (i >= 0) ? 1 : -1;
    i = abs(i);

    while (i)
    {
        d.push_back(i % 10);
        i /= 10;
    }

    if (d.size() == 0)
    {
        d.push_back(0);
    }
}

void BigInt::assign(const string &s)
{
    d.clear();
    int start = 0;
    if (s[0] == '-')
    {
        sign = -1;
        start = 1;
    }
    else
    {
        sign = 1;
        start = 0;
    }

    for (int i = s.size() - 1; i >= start; --i)
    {
        d.push_back(s[i] - '0');
    }
}

int BigInt::getSign() const
{
    return sign;
}

vector<char> BigInt::getDigits() const
{
    return d;
}

int BigInt::getDigit(int i) const
{
    return (int)d[i];
}

string BigInt::toString() const
{
    string res;

    if (sign == -1)
    {
        res.push_back('-');
    }

    for (int i = d.size() - 1; i >= 0; --i)
    {
        res.push_back(d[i] + '0');
    }
    return res;
}

//ȥ��ǰ�õ�0
void BigInt::reduceZero()
{
    for (int i = d.size() - 1; i >= 0; --i)
    {
        if (d[i] == 0)
        {
            d.erase(d.begin() + i);
        }
        else
        {
            break;
        }
    }

    if (d.size() == 0)
    {
        d.push_back(0);
    }
}

//����ֵ
BigInt BigInt::bigAbs() const
{
    BigInt res = (*this);
    res.sign = 1;
    return res;
}

bool BigInt::operator<(const BigInt &num) const
{
    if (sign == 1 && num.sign == -1)
    {
        return false;
    }
    else if (sign == -1 && num.sign == 1)
    {
        return true;
    }

    if (d.size() < num.d.size())
    {
        return (sign == 1) ? true : false;
    }
    else if (d.size() > num.d.size())
    {
        return (sign == 1) ? false : true;
    }

    for (int i = d.size() - 1; i >= 0; --i)
    {
        if (d[i] < num.d[i])
        {
            return (sign == 1) ? true : false;
        }
        else if (d[i] > num.d[i])
        {
            return (sign == 1) ? false : true;
        }
    }

    return false;
}

bool BigInt::operator>(const BigInt &num) const
{
    if (sign == 1 && num.sign == -1)
    {
        return true;
    }
    else if (sign == -1 && num.sign == 1)
    {
        return false;
    }

    if (d.size() < num.d.size())
    {
        return (sign == 1) ? false : true;
    }
    else if (d.size() > num.d.size())
    {
        return (sign == 1) ? true : false;
    }

    for (int i = d.size() - 1; i >= 0; --i)
    {
        if (d[i] < num.d[i])
        {
            return (sign == 1) ? false : true;
        }
        else if (d[i] > num.d[i])
        {
            return (sign == 1) ? true : false;
        }
    }

    return false;
}

bool BigInt::operator==(const BigInt &num) const
{
    if (sign != num.sign)
    {
        return false;
    }

    if (d.size() != num.d.size())
    {
        return false;
    }

    for (size_t i = 0; i < d.size(); ++i)
    {
        if (d[i] != num.d[i])
        {
            return false;
        }
    }

    return true;
}

bool BigInt::operator!=(const BigInt &num) const
{
    return !((*this) == num);
}

bool BigInt::operator>=(const BigInt &num) const
{
    return (*this) > num || (*this) == num;
}

bool BigInt::operator<=(const BigInt &num) const
{
    return (*this) < num || (*this) == num;
}

BigInt BigInt::operator<<(int n) const
{
    BigInt t = *this;
    if (t == BigInt(0))
    {
        return t;
    }

    for (int i = 0; i < n; ++i)
    {
        t.d.insert(t.d.begin(), 0);
    }

    return t;
}

BigInt BigInt::operator<<=(int n)
{
    return (*this) = (*this) << n;
}

BigInt BigInt::operator+(const BigInt &num) const
{
    BigInt res;

    if (sign == num.sign)
    {
        res = uAdd(*this, num);
        res.sign = sign;
    }
    else
    {
        BigInt t1 = bigAbs();
        BigInt t2 = num.bigAbs();
        if (t1 > t2)
        {
            res = uSub(t1, t2);
            res.sign = sign;
        }
        else if (t1 < t2)
        {
            res = uSub(t2, t1);
            res.sign = num.sign;
        }
        else
        {
            res = BigInt(0);
        }
    }

    return res;
}

BigInt BigInt::operator-(const BigInt &num) const
{
    BigInt t = num;
    t.sign = -t.sign;
    return (*this) + t;
}

BigInt BigInt::operator+=(const BigInt &num)
{
    return (*this) = (*this) + num;
}

BigInt BigInt::operator-=(const BigInt &num)
{
    return (*this) = (*this) - num;
}

BigInt BigInt::operator*(const BigInt &num) const
{
    BigInt res(0);

    if ((*this) == BigInt(0) || num == BigInt(0))
    {
        res = BigInt(0);
    }

    if (*this < num)
    {
        for (size_t i = 0; i < d.size(); ++i)
        {
            res += (dMul(num, d[i]) << i);
        }
    }
    else
    {
        for (size_t i = 0; i < num.d.size(); ++i)
        {
            res += (dMul(*this, num.d[i]) << i);
        }
    }

    if (sign == num.sign)
    {
        res.sign = 1;
    }
    else if (res != BigInt(0))
    {
        res.sign = -1;
    }

    return res;
}

BigInt BigInt::operator*=(const BigInt &num)
{
    return (*this) = (*this) * num;
}

BigInt BigInt::operator/(const BigInt &num) const
{
    BigInt remain;
    BigInt res = tryDivision(bigAbs(), num.bigAbs(), remain);
    if (res != BigInt(0))
    {
        res.sign = (sign == num.sign) ? 1 : -1;
    }
    return res;
}

BigInt BigInt::operator/=(const BigInt &num)
{
    return (*this) = (*this) / num;
}

BigInt BigInt::operator%(const BigInt &num) const
{
    BigInt remain;
    tryDivision(bigAbs(), num.bigAbs(), remain);
    return remain;
}

BigInt BigInt::operator%=(const BigInt &num)
{
    return (*this) = (*this) % num;
}

BigInt BigInt::operator^(const BigInt &num) const
{
    BigInt res = power(bigAbs(), num);
    if (num.d[0] % 2 == 0)
    {
        res.sign = 1;
    }
    else
    {
        res.sign = sign;
    }
    return res;
}

BigInt BigInt::operator^=(const BigInt &num)
{
    return (*this) = (*this) ^ num;
}

//�޷��żӷ�
BigInt BigInt::uAdd(const BigInt &num1, const BigInt &num2)
{
    BigInt res;
    res.d.clear();
    int carry = 0;
    int len = max(num1.d.size(), num2.d.size());
    for (int i = 0; i < len; ++i)
    {
        int r = 0;

        if ((size_t)i >= num1.d.size())
        {
            r += 0;
        }
        else
        {
            r += num1.d[i];
        }

        if ((size_t)i >= num2.d.size())
        {
            r += 0;
        }
        else
        {
            r += num2.d[i];
        }

        r += carry;
        res.d.push_back(r % 10);
        carry = r / 10;
    }

    if (carry != 0)
    {
        res.d.push_back(1);
    }

    return res;
}

//�޷��ż���
BigInt BigInt::uSub(const BigInt &num1, const BigInt &num2)
{
    BigInt res;
    res.d.clear();
    int carry = 0;

    for (size_t i = 0; i < num1.d.size(); ++i)
    {
        int r = num1.d[i];
        if (i >= num2.d.size())
        {
            r -= 0;
        }
        else
        {
            r -= num2.d[i];
        }

        r += carry;
        if (r < 0)
        {
            carry = -1;
            res.d.push_back(10 + r);
        }
        else
        {
            carry = 0;
            res.d.push_back(r);
        }
    }

    res.reduceZero();

    return res;
}

//�޷��Ÿ�λ�˷�
BigInt BigInt::dMul(const BigInt &num, int dight)
{
    BigInt res;
    res.d.clear();

    int carry = 0;
    for (size_t i = 0; i < num.d.size(); ++i)
    {
        int r = num.d[i] * dight + carry;
        res.d.push_back(r % 10);
        carry = r / 10;
    }

    if (carry != 0)
    {
        res.d.push_back(carry);
    }

    res.reduceZero();

    return res;
}

BigInt BigInt::tryDivision(const BigInt &dividend, const BigInt &divisor, BigInt &remain)
{
    assert(divisor != BigInt(0));

    BigInt res(0);
    BigInt a = dividend, b = divisor;
    int n2 = b.d[b.d.size() - 1];
    while (a >= b)
    {
        int n1 = a.d[a.d.size() - 1];
        int off = a.d.size() - b.d.size();
        if (n1 > n2)
        {
            int k = n1 / n2;
            BigInt t = b << off;
            int i;
            for (i = k; i >= 1; --i)
            {
                if (t * BigInt(i) <= a)
                {
                    break;
                }
            }
            res += (BigInt(i) << off);
            a = a - (b << off) * BigInt(i);
        }
        else
        {
            if (off >= 2)
            {
                int k = (10 * n1 + a.d[a.d.size() - 2]) / n2;
                BigInt t = b << (off - 1);
                int i;
                for (i = k; i >= 1; --i)
                {
                    if (t * BigInt(i) <= a)
                    {
                        break;
                    }
                }
                res += (BigInt(i) << (off - 1));
                a = a - (b << (off - 1)) * BigInt(i);
            }
            else
            {
                res += (BigInt(1) << (off - 1));
                a = a - (b << (off - 1));
            }
        }
    }
    remain = a;
    return res;
}

BigInt BigInt::power(const BigInt &a, const BigInt &b)
{
    assert(b >= BigInt(0));

    if (b == BigInt(0))
    {
        return BigInt(1);
    }
    else if (b == BigInt(1))
    {
        return a;
    }
    else
    {
        if (b.d[0] % 2 == 0)
        {
            return power(a, b / BigInt(2)) * power(a, b / BigInt(2));
        }
        else
        {
            return a * power(a, (b - BigInt(1)) / BigInt(2)) * power(a, (b - BigInt(1)) / BigInt(2));
        }
    }
}

ostream& operator<<(ostream& out, const BigInt &num)
{
    out << num.toString();
	return out;
}

BigInt Max(const BigInt &a, const BigInt &b)
{
    return (a > b) ? a : b;
}

BigInt Min(const BigInt &a, const BigInt &b)
{
    return (a < b) ? a : b;
}

BigInt Gcd(const BigInt &a, const BigInt &b)
{
    assert(a >= BigInt(0) && b >= BigInt(0));

	BigInt ta = a, tb = b, t;
	while (tb != BigInt(0))
	{
		t = ta;
		ta = tb;
		tb = t % tb;
	}
	return ta;
}

BigInt Lcm(const BigInt &a, const BigInt &b)
{
    assert(a > BigInt(0) && b > BigInt(0));

	if (a < b)
	{
		return a / Gcd(a, b) * b;
	}
	else
	{
		return b / Gcd(a, b) * a;
	}
}
