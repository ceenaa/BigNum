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
    friend BigNum operator+(int n, BigNum a) { BigNum b(n); return (b+a);}
    friend BigNum operator-(int n, BigNum a) { BigNum b(n); return (b-a);}
    friend BigNum operator*(int n, BigNum a) { BigNum b(n); return (b*a);}
    friend BigNum operator/(int n, BigNum a) { BigNum b(n); return (b/a);}
    friend BigNum operator%(int n, BigNum a) { BigNum b(n); return (b%a);}
    friend bool operator<(int n, BigNum a) { BigNum b(n); return (b<a);}
    friend bool operator>(int n, BigNum a) { BigNum b(n); return (b>a);}
    friend bool operator<=(int n, BigNum a) { BigNum b(n); return (b<=a);}
    friend bool operator>=(int n, BigNum a) { BigNum b(n); return (b>=a);}
    friend bool operator==(int n, BigNum a) { BigNum b(n); return (b==a);}
    friend int operator+=(int, BigNum) { throw std::invalid_argument("cannot convert BigNum to int");}
    friend int operator-=(int, BigNum) { throw std::invalid_argument("cannot convert BigNum to int");}
    friend int operator*=(int, BigNum) { throw std::invalid_argument("cannot convert BigNum to int");}
    friend int operator/=(int, BigNum) { throw std::invalid_argument("cannot convert BigNum to int");}
    friend BigNum operator+(long n, BigNum a) { BigNum b(n); return (b+a);}
    friend BigNum operator-(long n, BigNum a) { BigNum b(n); return (b-a);}
    friend BigNum operator*(long n, BigNum a) { BigNum b(n); return (b*a);}
    friend BigNum operator/(long n, BigNum a) { BigNum b(n); return (b/a);}
    friend BigNum operator%(long n, BigNum a) { BigNum b(n); return (b%a);}
    friend bool operator<(long n, BigNum a) { BigNum b(n); return (b<a);}
    friend bool operator>(long n, BigNum a) { BigNum b(n); return (b>a);}
    friend bool operator<=(long n, BigNum a) { BigNum b(n); return (b<=a);}
    friend bool operator>=(long n, BigNum a) { BigNum b(n); return (b>=a);}
    friend bool operator==(long n, BigNum a) { BigNum b(n); return (b==a);}
    friend long operator+=(long, BigNum) { throw std::invalid_argument("cannot convert BigNum to long");}
    friend long operator-=(long, BigNum) { throw std::invalid_argument("cannot convert BigNum to long");}
    friend long operator*=(long, BigNum) { throw std::invalid_argument("cannot convert BigNum to long");}
    friend long operator/=(long, BigNum) { throw std::invalid_argument("cannot convert BigNum to long");}

public:
    explicit BigNum(std::string = "0");
    BigNum(int);
    BigNum(long);
    ~BigNum();
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
    
    unsigned int operator[](size_t);

    bool operator<(BigNum);
    bool operator>(BigNum);
    bool operator==(BigNum);
    bool operator!=(BigNum);
    bool operator>=(BigNum);
    bool operator<=(BigNum);

    void printDelimiter() const;

    operator std::string() const;

private:
    std::string number;
    char sign;
};

#endif