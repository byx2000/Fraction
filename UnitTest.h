#include <iostream>
#include <fstream>
#include "Fraction.h"

using namespace std;

//µ•‘™≤‚ ‘

//ππ‘Ï∫Ø ˝≤‚ ‘
void TestCon()
{
	ifstream fin("cof.txt");
	string s1, s2, s3;
	cout << "Begin con test..." << endl;
	int cnt = 1;
	while (fin >> s1 >> s2 >> s3)
	{
		Fraction a(s1);
		Fraction b(s2, s3);
		if (a != b)
		{
			cout << "Con test failed!" << endl;
			cout << cnt << endl;
			fin.close();
			return;
		}
		cnt++;
	}

	cout << "Con test succeeded!" << endl;

	fin.close();
}

//º”∑®≤‚ ‘
void TestAdd()
{
	ifstream fin("add.txt");
	string s1, s2, s3, s4, s5, s6;
	cout << "Begin add test..." << endl;
	while (fin >> s1 >> s2 >> s3 >> s4 >> s5 >> s6)
	{
		Fraction res = Fraction(s1, s2) + Fraction(s3, s4);
		string cmp = s5;
		if (BigInt(1) != BigInt(s6))
		{
			cmp += "/";
			cmp += s6;
		}
		if (res.toString() != cmp)
		{
			cout << "Add test failed!" << endl;
			cout << s1 << " " << s2 << " " << s3 << " " << s4 << " " << s5 << " " << s6 << " " << endl;
			cout << res.toString() << endl;
			fin.close();
			return;
		}
	}

	cout << "Add test succeeded!" << endl;

	fin.close();
}

//ºı∑®≤‚ ‘
void TestSub()
{
	ifstream fin("sub.txt");
	string s1, s2, s3, s4, s5, s6;
	cout << "Begin sub test..." << endl;
	while (fin >> s1 >> s2 >> s3 >> s4 >> s5 >> s6)
	{
		Fraction res = Fraction(s1, s2) - Fraction(s3, s4);
		string cmp = s5;
		if (BigInt(1) != BigInt(s6))
		{
			cmp += "/";
			cmp += s6;
		}
		if (res.toString() != cmp)
		{
			cout << "Sub test failed!" << endl;
			cout << s1 << " " << s2 << " " << s3 << " " << s4 << " " << s5 << " " << s6 << " " << endl;
			cout << res.toString() << endl;
			fin.close();
			return;
		}
	}

	cout << "Sub test succeeded!" << endl;

	fin.close();
}

//≥À∑®≤‚ ‘
void TestMul()
{
	ifstream fin("mul.txt");
	string s1, s2, s3, s4, s5, s6;
	cout << "Begin mul test..." << endl;
	while (fin >> s1 >> s2 >> s3 >> s4 >> s5 >> s6)
	{
		Fraction res = Fraction(s1, s2) * Fraction(s3, s4);
		string cmp = s5;
		if (BigInt(1) != BigInt(s6))
		{
			cmp += "/";
			cmp += s6;
		}
		if (res.toString() != cmp)
		{
			cout << "Mul test failed!" << endl;
			cout << s1 << " " << s2 << " " << s3 << " " << s4 << " " << s5 << " " << s6 << " " << endl;
			cout << res.toString() << endl;
			fin.close();
			return;
		}
	}

	cout << "Mul test succeeded!" << endl;

	fin.close();
}

//≥˝∑®≤‚ ‘
void TestDiv()
{
	ifstream fin("div.txt");
	string s1, s2, s3, s4, s5, s6;
	cout << "Begin div test..." << endl;
	while (fin >> s1 >> s2 >> s3 >> s4 >> s5 >> s6)
	{
		Fraction res = Fraction(s1, s2) / Fraction(s3, s4);
		string cmp = s5;
		if (BigInt(1) != BigInt(s6))
		{
			cmp += "/";
			cmp += s6;
		}
		if (res.toString() != cmp)
		{
			cout << "Div test failed!" << endl;
			cout << s1 << " " << s2 << " " << s3 << " " << s4 << " " << s5 << " " << s6 << " " << endl;
			cout << res.toString() << endl;
			fin.close();
			return;
		}
	}

	cout << "Div test succeeded!" << endl;

	fin.close();
}

//«Û√›≤‚ ‘
void TestPow()
{
	ifstream fin("pow.txt");
	string s1, s2, s3, s4, s5;
	cout << "Begin pow test..." << endl;
	while (fin >> s1 >> s2 >> s3 >> s4 >> s5)
	{
		Fraction res = Fraction(s1, s2) ^ BigInt(s3);
		string cmp = s4;
		if (BigInt(1) != BigInt(s5))
		{
			cmp += "/";
			cmp += s5;
		}
		if (res.toString() != cmp)
		{
			cout << "Pow test failed!" << endl;
			cout << s1 << " " << s2 << " " << s3 << " " << s4 << " " << s5 << " " << endl;
			cout << res.toString() << endl;
			fin.close();
			return;
		}
	}

	cout << "Pow test succeeded!" << endl;

	fin.close();
}
