#include <bits/stdc++.h>
using namespace std;

class LargeInt
{
    string digits;

public:
    // Constructors:
    LargeInt(unsigned long long n = 0);
    LargeInt(string &);
    LargeInt(const char *);
    LargeInt(LargeInt &);

    // Helper Functions:
    friend void divide_by_2(LargeInt &a);
    friend bool Null(const LargeInt &);
    friend int length(const LargeInt &);
    int operator[](const int) const;

    /*   Operator Overloading   */

    // Direct Assignment
    LargeInt &operator=(const LargeInt &);

    // Post - Incrementation
    LargeInt &operator++();
    LargeInt operator++(int temp);

    // Pre - Incrementation
    LargeInt &operator--();
    LargeInt operator--(int temp);

    // Addition and Subtraction
    friend LargeInt &operator+=(LargeInt &, const LargeInt &);
    friend LargeInt operator+(const LargeInt &, const LargeInt &);

    friend LargeInt operator+=(const LargeInt &, const LargeInt &);
    friend LargeInt &operator-=(LargeInt &, const LargeInt &);

    // Comparison operators
    friend bool operator==(const LargeInt &, const LargeInt &);
    friend bool operator!=(const LargeInt &, const LargeInt &);

    friend bool operator>(const LargeInt &, const LargeInt &);
    friend bool operator>=(const LargeInt &, const LargeInt &);

    friend bool operator<(const LargeInt &, const LargeInt &);
    friend bool operator<=(const LargeInt &, const LargeInt &);

    // Multiplication and Division
    friend LargeInt &operator*=(LargeInt &, const LargeInt &);
    friend LargeInt operator*(const LargeInt &, const LargeInt &);

    friend LargeInt &operator/=(LargeInt &, const LargeInt &);
    friend LargeInt operator/(const LargeInt &, const LargeInt &);

    // Modulo
    friend LargeInt operator%(const LargeInt &, const LargeInt &);
    friend LargeInt &operator%=(LargeInt &, const LargeInt &);

    // Power Function
    friend LargeInt operator^(const LargeInt &, const LargeInt &);
    friend LargeInt &operator^=(LargeInt &, const LargeInt &);

    // Square Root Function
    friend LargeInt sqrt(LargeInt &a);

    // Read and Write
    friend ostream &operator<<(ostream &, const LargeInt &);
    friend istream &operator>>(istream &, LargeInt &);

    // Others
    friend LargeInt NthCatalan(int n);
    friend LargeInt NthFibonacci(int n);
    friend LargeInt Factorial(int n);
};

LargeInt::LargeInt(string &s)
{
    digits = "";
    int n = s.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (!isdigit(s[i]))
            throw("ERROR");
        digits.push_back(s[i] - '0');
    }
}

LargeInt::LargeInt(unsigned long long nr)
{
    do
    {
        digits.push_back(nr % 10);
        nr /= 10;
    } while (nr);
}

LargeInt::LargeInt(const char *s)
{
    digits = "";
    for (int i = strlen(s) - 1; i >= 0; i--)
    {
        if (!isdigit(s[i]))
            throw("ERROR");
        digits.push_back(s[i] - '0');
    }
}

LargeInt::LargeInt(LargeInt &a)
{
    digits = a.digits;
}

bool Null(const LargeInt &a)
{
    if(a.digits.size() == 1 && a.digits[0] == 0) return true;
    return false;
}

int length(const LargeInt &a)
{
    return a.digits.size();
}

// Subscript Operator: This operator allows you to access a specific digit in the BigInt object by its index.

int LargeInt::operator[](const int index) const /*Const qualifier*/
{
    if (digits.size() <= index || index < 0)
        throw("ERROR");
    return digits[index];
}

bool operator==(const LargeInt &a, const LargeInt &b)
{
    return a.digits == b.digits;
}

bool operator!=(const LargeInt &a, const LargeInt &b)
{
    return !(a == b);
}

bool operator<(const LargeInt &a, const LargeInt &b)
{
    int n = length(a), m = length(b);
    if (n != m)
        return n < m;
    while (n--)
    {
        if (a.digits[n] != b.digits[n])
        {
            return a.digits[n] < b.digits[n];
        }
    }
    return false;
}

bool operator>(const LargeInt &a, const LargeInt &b)
{
    return b < a;
}

bool operator>=(const LargeInt &a, const LargeInt &b)
{
    return !(a < b);
}

bool operator<=(const LargeInt &a, const LargeInt &b)
{
    return !(a > b);
}

LargeInt &LargeInt::operator=(const LargeInt &a)
{
    digits = a.digits;
    return *this;
}

LargeInt &LargeInt::operator++()
{
    int i, n = digits.size();
    for (i = 0; i < n && digits[i] == 9; i++)
    {
        digits[i] = 0;
    }
    if (i == n)
        digits.push_back(1);
    else
        digits[i]++;
    return *this;
}

LargeInt LargeInt::operator++(int temp)
{
    LargeInt aux;
    aux = *this;
    ++(*this);
    return aux;
}

LargeInt &LargeInt::operator--()
{
    int n = digits.size();
    if (digits[0] == 0 && digits.size() == 1)
    {
        throw("UNDERFLOW");
    }
    int i;
    for (i = 0; digits[i] == 0 && i < n; i++)
    {
        digits[i] = 9;
    }
    digits[i]--;
    if (n > 1 && digits[n - 1] == 0)
    {
        digits.pop_back();
    }
    return *this;
}

LargeInt LargeInt::operator--(int temp)
{
    LargeInt aux;
    aux = *this;
    --(*this);
    return aux;
}

LargeInt &operator+=(LargeInt &a, const LargeInt &b)
{
    int t = 0, s, i;
    int n = length(a), m = length(b);
    if (m > n)
    {
        a.digits.append(m - n, 0);
    }
    n = length(a);
    for (i = 0; i < n; i++)
    {
        if (i < m)
        {
            s = (a.digits[i] + b.digits[i]) + t;
        }
        else
        {
            s = a.digits[i] + t;
        }
        t = s / 10;
        a.digits[i] = s % 10;
    }
    if (t)
    {
        a.digits.push_back(t);
    }
    return a;
}

LargeInt operator+(const LargeInt &a, LargeInt &b)
{
    LargeInt temp;
    temp = a;
    temp += b;
    return temp;
}

LargeInt &operator-=(LargeInt &a, const LargeInt &b){
    if(a < b){
        throw("UNDERFLOW");
    }
    int n = length(a), m = length(b);
    int i, t = 0, s;
    for(i = 0; i< n;i++){
        if(i<m){
            s = a.digits[i] - b.digits[i] + t;
        }else{
            s = a.digits[i] + t;
        }
        if(s < 0){
            s += 10;
            t = -1;
        }else{
            t = 0;
            a.digits[i] = s;
        }
    }
    while(n > 1 && a.digits[n-1] == 0){
        a.digits.pop_back();
        n--;
    }
    return a;
}

LargeInt operator-(const LargeInt &a, LargeInt &b){
    LargeInt temp;
    temp = a;
    temp -= b;
    return temp;
}