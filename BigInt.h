#pragma once

#include <vector>
#include <string>

using namespace std;

class BigInt
{
public:
    /*构造函数*/
	BigInt();
	explicit BigInt(long long i);
	explicit BigInt(const string &s);

	void assign(long long i);
	void assign(const string &s);

	int getSign() const;
	vector<char> getDigits() const;
	int getDigit(int i) const;

	//转换成字符串
    string toString() const;

	//绝对值
	BigInt bigAbs() const;

	/*运算符重载*/
	bool operator<(const BigInt &num) const;
	bool operator>(const BigInt &num) const;
	bool operator==(const BigInt &num) const;
	bool operator!=(const BigInt &num) const;
	bool operator>=(const BigInt &num) const;
	bool operator<=(const BigInt &num) const;
	BigInt operator<<(int n) const;
	BigInt operator<<=(int n);
    BigInt operator+(const BigInt &num) const;
    BigInt operator-(const BigInt &num) const;
	BigInt operator+=(const BigInt &num);
	BigInt operator-=(const BigInt &num);
	BigInt operator*(const BigInt &num) const;
	BigInt operator*=(const BigInt &num);
	BigInt operator/(const BigInt &num) const;
    BigInt operator/=(const BigInt &num);
    BigInt operator%(const BigInt &num) const;
    BigInt operator%=(const BigInt &num);
    BigInt operator^(const BigInt &num) const;
    BigInt operator^=(const BigInt &num);

private:
	int sign;
	vector<char> d;

	/*内部函数*/
    //去除前置的0
	void reduceZero();
	//无符号加法
	static BigInt uAdd(const BigInt &num1, const BigInt &num2);
	//无符号减法
	static BigInt uSub(const BigInt &num1, const BigInt &num2);
	//无符号个位乘法
	static BigInt dMul(const BigInt &num, int dight);
	//无符号试商
	static BigInt tryDivision(const BigInt &dividend, const BigInt &divisor, BigInt &remain);
	//无符号求幂
	static BigInt power(const BigInt &a, const BigInt &b);
};

//重载<<运算符
ostream& operator<<(ostream& out, const BigInt &num);

//最大值
BigInt Max(const BigInt &a, const BigInt &b);
//最小值
BigInt Min(const BigInt &a, const BigInt &b);

//最大公因数
BigInt Gcd(const BigInt &a, const BigInt &b);
//最小公倍数
BigInt Lcm(const BigInt &a, const BigInt &b);
