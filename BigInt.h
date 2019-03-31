#pragma once

#include <vector>
#include <string>

using namespace std;

class BigInt
{
public:
    /*���캯��*/
	BigInt();
	explicit BigInt(long long i);
	explicit BigInt(const string &s);

	void assign(long long i);
	void assign(const string &s);

	int getSign() const;
	vector<char> getDigits() const;
	int getDigit(int i) const;

	//ת�����ַ���
    string toString() const;

	//����ֵ
	BigInt bigAbs() const;

	/*���������*/
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

	/*�ڲ�����*/
    //ȥ��ǰ�õ�0
	void reduceZero();
	//�޷��żӷ�
	static BigInt uAdd(const BigInt &num1, const BigInt &num2);
	//�޷��ż���
	static BigInt uSub(const BigInt &num1, const BigInt &num2);
	//�޷��Ÿ�λ�˷�
	static BigInt dMul(const BigInt &num, int dight);
	//�޷�������
	static BigInt tryDivision(const BigInt &dividend, const BigInt &divisor, BigInt &remain);
	//�޷�������
	static BigInt power(const BigInt &a, const BigInt &b);
};

//����<<�����
ostream& operator<<(ostream& out, const BigInt &num);

//���ֵ
BigInt Max(const BigInt &a, const BigInt &b);
//��Сֵ
BigInt Min(const BigInt &a, const BigInt &b);

//�������
BigInt Gcd(const BigInt &a, const BigInt &b);
//��С������
BigInt Lcm(const BigInt &a, const BigInt &b);
