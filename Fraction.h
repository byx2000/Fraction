#pragma once

#include "BigInt.h"

class Fraction
{
public:
    /*构造函数*/
	Fraction();
	Fraction(long long a, long long b);
	Fraction(const string &a, const string &b);
	Fraction(const BigInt &a, const BigInt &b);
	explicit Fraction(long long i);
	explicit Fraction(const string &s);
	explicit Fraction(const BigInt &num);

	void assign(const BigInt &a, const BigInt &b);

	//转换为字符串
	string toString() const;

	int getSign() const;

	/*运算符重载*/
	bool operator==(const Fraction &f) const;
	bool operator!=(const Fraction &f) const;
	bool operator<(const Fraction &f) const;
	bool operator>(const Fraction &f) const;
	Fraction operator+(const Fraction &f) const;
	Fraction operator+=(const Fraction &f);
	Fraction operator-(const Fraction &f) const;
	Fraction operator-=(const Fraction &f);
	Fraction operator*(const Fraction &f) const;
	Fraction operator*=(const Fraction &f);
	Fraction operator/(const Fraction &f) const;
	Fraction operator/=(const Fraction &f);
	Fraction operator^(const BigInt &num) const;
	Fraction operator^=(const BigInt &num);

private:
	int sign;
	BigInt a;
	BigInt b; //a/b

    //约分
	void reduce();
};

/*重载<<运算符*/
ostream& operator<<(ostream &out, const Fraction &f);
