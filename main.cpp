#include <iostream>
#include "BigNum.h"

using namespace std;

int main()
{
    BigNum t1, t2;
    t1 = "10000000000000000000";
    t2 = "-23";
    cout << "t1 + t2: " << t1 + t2 << endl;
    cout << "t1 - t2: " << t1 - t2 << endl;
    cout << "t1 * t2: " << t1 * t2 << endl;
    cout << "t1 / t2: " << t1 / t2 << endl;
    cout << "t1 % t2: " << t1 % t2 << endl;
    cout << "---------------------------------------------" << endl;
    BigNum a("1232654896145145621450543654598456925"), b("215489450265945641025641200");
    cout << "a + b : " << (a+b) << endl;
    cout << "a - b : " << (a-b) << endl;
    cout << "b - a : " << (b-a) << endl;
    cout << "a / b : " << (a/b) << endl;
    cout << "b / a : " << (b/a) << endl;
    cout << "a * b : " << (a*b) << endl;
    cout << "a < b : " << (a>b) << endl;
    cout << "a <= b : " << (a<=b) << endl;
    cout << "a > b : " << (a>b) << endl;
    cout << "a >= b : " << (a>=b) << endl;
    cout << "----------------------------------------------------" << endl;
    BigNum c("549216984515484166974120001"), d("-4001302840013028");
    cout << "c + d : " << (c+d) << endl;
    cout << "c - d : " << (c-d) << endl;
    cout << "d - c : " << (d-c) << endl;
    cout << "c / d : " << (c/d) << endl;
    cout << "d / c : " << (d/c) << endl;
    cout << "c * d : " << (c*d) << endl;
    cout << "c % d : " << (c%d) << endl;
    cout << "d < c : " << (d<c) << endl;
    cout << "d > c : " << (d>c) << endl;
    cout << "d <= c : " << (d<=c) << endl;
    cout << "d >= c : " << (d>=c) << endl;
    cout << "d == c : " << (d==c) << endl;
    cout << "d != c : " << (d!=c) << endl;
    cout << "----------------------------------------------------" << endl;
    int n = 111;
    cout << "c + n : " << (c+n) << endl;
    cout << "c - n : " << (c-n) << endl;
    cout << "n - c : " << (n-c) << endl;
    cout << "n / c : " << (n/c) << endl;
    cout << "c / n : " << (c/n) << endl;
    cout << "c * n : " << (c*n) << endl;
    cout << "c % n : " << (c%n) << endl;
    cout << "n < c : " << (n<c) << endl;
    cout << "n > c : " << (n>c) << endl;
    cout << "n <= c : " << (n<=c) << endl;
    cout << "n >= c : " << (n>=c) << endl;
    cout << "n == c : " << (n==c) << endl;
    cout << "n != c : " << (n!=c) << endl;
    cout << "----------------------------------------------------" << endl;
    long m = 344451164;
    cout << "a + m : " << (a+m) << endl;
    cout << "a - m : " << (a-m) << endl;
    cout << "m - a : " << (m-a) << endl;
    cout << "a / m : " << (a/m) << endl;
    cout << "m / a : " << (m/a) << endl;
    cout << "a * m : " << (a*m) << endl;
    cout << "a < m : " << (a>m) << endl;
    cout << "a <= m : " << (a<=m) << endl;
    cout << "a > m : " << (a>m) << endl;
    cout << "a >= m : " << (a>=m) << endl;
    cout << "a == m : " << (a==m) << endl;
    cout << "a != m : " << (a!=m) << endl;
    cout << "----------------------------------------------------" << endl;
    cin >> a >> d;
    a.printDelimiter();
    d.printDelimiter();
    cout << "a : " << a << endl;
    cout << "d : " << d << endl;
    cout << "b[5] : " << b[10] << endl;
    cout << "c[0] : " << c[0] << endl;
    cout << "----------------------------------------------------" << endl;

	return 0;
}
