#include <iostream>
#include "BoundaryTest.h" //边界条件测试
#include "UnitTest.h" //单元测试
#include "Fraction.h"

using namespace std;

int main()
{
    /*边界条件测试*/
    BoundaryTest();

    /*单元测试*/

    //去掉以下注释可运行单元测试
    //单元测试可能需要较长时间，请耐心等待
    /*TestCon();
    TestAdd();
    TestSub();
    TestMul();
    TestDiv();
    TestPow();*/

    /*用法示例*/

    //构造函数和赋值
    Fraction f1(1, 2); //1/2
    Fraction f2(-6, 8); //-6/8
    Fraction f3(5); //5/1
    Fraction f4(-6); //-6/1
    Fraction f5(BigInt(1), BigInt(2));
    Fraction f6(BigInt(-6), BigInt(8));
    Fraction f7("2/3");
    Fraction f8("-3/-5");
    Fraction f9 = Fraction(1, 2);
    Fraction f10 = Fraction(3);
    Fraction f11 = Fraction(BigInt(2), BigInt(3));
    Fraction f12 = Fraction("1/100");
    cout << f1 << endl;
    cout << f2 << endl;
    cout << f3 << endl;
    cout << f4 << endl;
    cout << f5 << endl;
    cout << f6 << endl;
    cout << f7 << endl;
    cout << f8 << endl;
    cout << f9 << endl;
    cout << f10 << endl;
    cout << f11 << endl;
    cout << f12 << endl;

    //运算符重载
    cout << Fraction(1, 2) + Fraction(1, 3) << endl; //1/2 + 1/3 = 5/6
    cout << Fraction(1, 2) - Fraction(1, 3) << endl; //1/2 - 1/3 = 1/6
    cout << Fraction(1, 2) * Fraction(1, 3) << endl; //1/2 * 1/3 = 1/6
    cout << Fraction(1, 2) / Fraction(1, 3) << endl; //1/2 / 1/3 = 3/2
    cout << (Fraction(3, 5) ^ BigInt(100)) << endl;  //(3/5)^100
    cout << (Fraction(1, 2) += Fraction(1, 3)) << endl;
    cout << (Fraction(1, 2) -= Fraction(1, 3)) << endl;
    cout << (Fraction(1, 2) *= Fraction(1, 3)) << endl;
    cout << (Fraction(1, 2) /= Fraction(1, 3)) << endl;
    cout << (Fraction(3, 5) ^= BigInt(100)) << endl;

    /*应用示例*/

    //求1+1/2+1/3+...+1/500
    Fraction res(0);
    for (int i = 1; i <= 500; ++i)
    {
        res += Fraction(1, i);
    }
    cout << res << endl;

    //求(1/2)*(2/3)*(3/4)*...*(100/101)
    res = Fraction(1);
    for (int i = 1; i <= 100; ++i)
    {
        res *= Fraction(i, i + 1);
    }
    cout << res << endl;

    return 0;
}
