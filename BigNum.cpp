#include "BigNum.h"

using namespace std;

void reverseString(string &m)
{
    string t = "";
    for(int i = m.length()-1 ; i >= 0; i--)
        t += m[i];
    m = t;
}

void removeZero(string &m)
{
    if(m.size() == 1  && m[0] == '0')
        return;
    if(m[0] != '0')
        return;
    while(m.size() > 1 && m[0] == '0')
        m = m.substr(1,  m.length() - 1);
}

BigNum::BigNum(const char* n)
{
    setSign('+');
    setNumber(n);
}

BigNum::BigNum(long long i)
{
    string t = to_string(i);
    setNumber(t);
}

void BigNum::setNumber(string n)
{
    number = "";
    if(n[0] != '-' && n[0] != '+')
    {
        number += n[0];
        setSign('+');
    }
    else
        setSign(n[0]);
    for(unsigned int i = 1; i < n.length(); i++)
        number += n[i];
}
string BigNum::getNumber() const
{
    return number;
}

void BigNum::setSign(char a)
{
    sign = a;
}
char BigNum::getSign() const
{
    return sign;
}

void BigNum::printDelimiter() const
{
    string t = "";
    int j = 0;
    for(int i = this->number.length()-1; i >= 0; i--, j++)
    {
        if(j % 3 == 0 && j)
            t += ',';
        t += this->number[i];
    }
    reverseString(t);
    cout << this->getSign() << t << endl;
}

void BigNum::operator=(const char* a)
{
    setNumber(a);
}

ostream& operator<<(ostream &output, BigNum n)
{
    if(n.getSign() == '+')
        output << n.getNumber();
    else
        output << n.getSign() << n.getNumber();
    return output;
}
istream& operator>>(istream &input, BigNum &n)
{
    string t;
    input >> t;
    n.setNumber(t);
    return input;
}

BigNum BigNum::operator+(BigNum n)
{
    if(getSign() == '+' && n.getSign() == '-')
    {
        n.setSign('+');
        return ( (*this) - n );
    }
    if(getSign() == '-' && n.getSign() == '+')
    {
        BigNum temp = *this;
        temp.setSign('+');
        temp = n - temp;
        return temp;
    }
    if(getSign() == '-' && n.getSign() == '-')
    {
        BigNum temp = *this;
        temp.setSign('+');
        n.setSign('+');
        temp = n + temp;
        temp.setSign('-');
        return temp;
    }
    string a = getNumber(), b = n.getNumber();
    if(b.length() > a.length())
        swap(a, b);
    int n1 = a.length()-1, n2 = b.length()-1;
    int carry = 0;
    reverseString(a);
    reverseString(b);
    string res = "";
    for(int i = 0; i <= n2; i++)
    {
        int sum = ( (a[i]-'0') + (b[i] - '0') + carry);
        res += sum % 10 + '0';
        carry = sum/10;
    }
    for(int i = n2+1; i <= n1; i++)
    {
        int sum = (a[i]-'0') + carry;
        res += sum%10 + '0';
        carry = sum/10;
    }
    if(carry)
        res += (carry + '0');
    reverseString(res);
    n.setNumber(res);
    return n;
}
BigNum BigNum::operator-(BigNum n)
{
    if(getSign() == '+' && n.getSign() == '-')
    {
        n.setSign('+');
        return ((*this) + n);
    }
    if(getSign() == '-' && n.getSign() == '+')
    {
        BigNum temp = *this;
        temp.setSign('+');
        temp = temp + n;
        temp.setSign('-');
        return temp;
    }
    if(getSign() == '-' && n.getSign() == '-')
    {
        n.setSign('+');
        return (n+*this);
    }
    string a = getNumber(), b = n.getNumber();
    int n1 = a.length(), n2 = b.length();
    if(*this < n)
    {
        swap(a, b);
        swap(n1, n2);
    }
    string res = "";
    reverseString(a);
    reverseString(b);
    int carry = 0;
    for(int i = 0; i < n2; i++)
    {
        int sub = ((a[i] - '0') - (b[i] - '0') - carry );
        if(sub < 0)
        {
            sub += 10;
            carry = 1;
        }
        else
            carry = 0;
        if(n2 == n1 && i == n2-1 && sub == 0)
            break;
        res += (sub + '0');
    }
    for(int i = n2; i < n1; i++)
    {
        int sub = ((a[i] - '0') - carry);
        if(sub < 0)
        {
            sub += 10;
            carry = 1;
        }
        else
            carry = 0;
        if(i == n1-1 && sub == 0)
            break;
        res += (sub + '0');
    }
    if(*this < n)
        res += '-';
    if(res == "")
        res += "0";
    reverseString(res);
    removeZero(res);
    n.setNumber(res);
    return n;
}
BigNum BigNum::operator*(BigNum n)
{
    string a = this->getNumber(), b = n.getNumber();
    if(*this > n)
        swap(a, b);
    reverseString(a);
    reverseString(b);
    string t = "";
    BigNum res("0"), temp;
    int carry = 0;
    for(int i = 0; a[i]; i++)
    {
        t = "";
        carry = 0;
        for(unsigned int j = 0; b[j]; j++)
        {
            if(j == b.length() - 1)
            {
                string holder = to_string(( (b[j]-'0') * (a[i] - '0') ) + carry);
                reverseString(holder);
                t += holder;
            }
            else
                t += ( ((b[j]-'0') * (a[i] - '0')) % 10 ) + carry + '0';
            carry = ( (b[j]-'0') * (a[i] - '0') ) / 10;
        }
        reverseString(t);
        for(int z = 0; z < i; z++)
            t += "0";
        temp.setNumber(t);
        res = res + temp;
    }
    if( (this->getSign() == '-' && n.getSign() == '+') || (this->getSign() == '+' && n.getSign() == '-') )
        res.setSign('-');
    removeZero(res.number);
    return res;
}
BigNum BigNum::operator/(BigNum n)
{
    BigNum res("0"), temp, remain;
    string sA = getNumber(), sB = n.getNumber();
    if(n.number == "0")
        throw invalid_argument("Invalid entry for \"/\" operator.");
    int nA = sA.size(), nB = sB.size(), lastIndex;
    {
        BigNum holderA(*this), holderB(n);
        holderA.setSign('+');
        holderB.setSign('+');
        if(holderA < holderB)
            return res;
    }
    if( (this->sign == '-' && n.sign == '+' ) || (this->sign == '+' && n.sign == '-' ))
        res.setSign('-');
    if(sA == sB)
    {
        res.number = "1";
        return res;
    }
    n.setSign('+');
    temp.number = sA.substr(0, nB);
    lastIndex = nB-1;
    if(temp < n)
    {
        temp.number = sA.substr(0, nB+1);
        lastIndex = nB;
    }
    int i;
    res.number = "";
    while(lastIndex < nA)
    {
        for (i = 1; i <= 9; i++)
        {
            if( (n*i) <= temp && ( n*(i+1) ) > temp)
            {
                res.number += ('0' + i);
                break;
            }
        }
        remain = temp - (n * i);
        lastIndex++;
        if(lastIndex == nA)
                break;
        remain.number += sA[lastIndex];
        removeZero(remain.number);
        if(remain.number == "0")
            res.number += '0';
        while(remain < n && lastIndex + 1 < nA )
        {
            lastIndex++;
            remain.number += sA[lastIndex];
            removeZero(remain.number);
            res.number += '0';
        }
        temp = remain;
    }
    return res;
}
BigNum BigNum::operator%(BigNum n)
{
    BigNum holder(*this), remain("0");
    holder.setSign('+');
    n.setSign('+');
    if(holder < n)
    {
        holder.setSign(this->getSign());
        return holder;
    }
    if(holder == n)
        return remain;
    remain = holder - (n * (holder / n));
    if(this->sign == '-')
        remain.setSign('-');
    return remain;
}
BigNum BigNum::operator+=(BigNum n)
{
    *this = (*this + n);
    return *this;
}
BigNum BigNum::operator-=(BigNum n)
{
    *this = (*this - n);
    return *this;
}
BigNum BigNum::operator*=(BigNum n)
{
    *this = (*this * n);
    return *this;
}
BigNum BigNum::operator/=(BigNum n)
{
    *this = *this / n;
    return *this;
}
unsigned int BigNum::operator[](size_t i)
{
    if(i >= this->number.length())
        throw out_of_range("Index out of range !");
    return (this->number[i] - '0');
}

bool BigNum::operator<(BigNum n)
{
    string a = this->getNumber(), b = n.getNumber();
    int na = a.size(), nb = b.size();

    if(*this == n)
        return false;

    if(this->getSign() == '-' && n.getSign() == '+')
        return true;
    else if(this->getSign() == '+' && n.getSign() == '-')
        return false;
    else if(this->getSign() == '-' && n.getSign() == '-')
    {
        if(nb < na)
            return true;
        else if(nb > na)
            return false;
        for(int i = 0; i < na; i++)
        {
            if(a[i] < b[i])
                return true;
            else if(a[i] > b[i])
                return false;
        }
    }
    if(na < nb)
        return true;
    else if(na > nb)
        return false;
    for(int i = 0; i < na; i++)
    {
        if(a[i] < b[i])
            return true;
        else if(a[i] > b[i])
            return false;
    }
    return false;
}
bool BigNum::operator>(BigNum n)
{
    return (n < *this);
}
bool BigNum::operator==(BigNum n)
{
    string a = this->getNumber(), b = n.getNumber();
    char ca = this->getSign() , cb = n.getSign();
    if(a == b && ca == cb)
        return true;
    return  false;
}
bool BigNum::operator!=(BigNum n)
{
    return !(*this == n);
}
bool BigNum::operator<=(BigNum n)
{
    if( (*this < n) || (*this == n))
        return true;
    return false;
}
bool BigNum::operator>=(BigNum n)
{
    if( (*this > n) || (*this == n))
        return true;
    return false;
}
