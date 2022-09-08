#ifndef BigNum_H
#define BigNum_H

#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

class BigNum
{
    friend std::ostream& operator<<(std::ostream&, BigNum);
    friend std::istream& operator>>(std::istream&, BigNum&);

    friend BigNum operator+(long long n, BigNum a) { BigNum b(n); return (b+a);}
    friend BigNum operator-(long long n, BigNum a) { BigNum b(n); return (b-a);}
    friend BigNum operator*(long long n, BigNum a) { BigNum b(n); return (b*a);}
    friend BigNum operator/(long long n, BigNum a) { BigNum b(n); return (b/a);}
    friend BigNum operator%(long long n, BigNum a) { BigNum b(n); return (b%a);}
    friend bool operator<(long long n, BigNum a) { BigNum b(n); return (b<a);}
    friend bool operator>(long long n, BigNum a) { BigNum b(n); return (b>a);}
    friend bool operator<=(long long n, BigNum a) { BigNum b(n); return (b<=a);}
    friend bool operator>=(long long n, BigNum a) { BigNum b(n); return (b>=a);}
    friend bool operator==(long long n, BigNum a) { BigNum b(n); return (b==a);}
    friend bool operator!=(long long n, BigNum a) { return !(n==a);}
    friend long operator+=(long long, BigNum) { throw std::invalid_argument("Conversion error");}
    friend long operator-=(long long, BigNum) { throw std::invalid_argument("Conversion error");}
    friend long operator*=(long long, BigNum) { throw std::invalid_argument("Conversion error");}
    friend long operator/=(long long, BigNum) { throw std::invalid_argument("Conversion error");}

public:
    BigNum(const char* = "0");
    BigNum(long long);

    void setNumber(std::string);
    std::string getNumber() const;
    void setSign(char);
    char getSign() const;

    BigNum operator+(BigNum);
    BigNum operator+=(BigNum);

    BigNum operator-(BigNum);
    BigNum operator-=(BigNum);
    BigNum operator*(BigNum);
    BigNum operator*=(BigNum);
    BigNum operator/(BigNum);
    BigNum operator/=(BigNum);
    BigNum operator%(BigNum);

    void operator=(const char*);

    unsigned int operator[](size_t);

    bool operator<(BigNum);
    bool operator>(BigNum);
    bool operator==(BigNum);
    bool operator!=(BigNum);
    bool operator>=(BigNum);
    bool operator<=(BigNum);

    void printDelimiter() const;

private:
    std::string number;
    char sign;
};

#endif
