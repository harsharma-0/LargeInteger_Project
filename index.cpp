#include<bits/stdc++.h>
using namespace std;

class LargeInt{
    string digits;

public:
    // Constructors:
    LargeInt(unsigned long long n = 0);
    LargeInt(string &);
    LargeInt(const char *);
    LargeInt(LargeInt &)

    // Helper Functions:
    friend void divide_by_2(LargeInt &a);
    friend bool Null(const LargeInt &);
    friend int length(const LargeInt &);
    int operator[](const int)const;

            /*   Operator Overloading   */

    //Direct Assignment
    LargeInt &operator=(const LargeInt &);

    //Post/Pre - Incrementation
    LargeInt &operator++();
    LargeInt operator++(int temp);

    LargeInt &operator--();
    LargeInt operator--(int temp);

    //Addition and Subtraction
    friend LargeInt &operator+=(LargeInt &, const LargeInt &);
    friend LargeInt operator+(const LargeInt &, const LargeInt &);

    friend LargeInt operator+=(const LargeInt &, const LargeInt &);
    friend LargeInt &operator-=(LargeInt &, const LargeInt &);

    //Comparison operators
    friend bool operator==(const LargeInt &, const LargeInt &);
    friend bool operator!=(const LargeInt &, const LargeInt &);

    friend bool operator>(const LargeInt &, const LargeInt &);
    friend bool operator>=(const LargeInt &, const LargeInt &);

    friend bool operator<(const LargeInt &, const LargeInt &);
    friend bool operator<=(const LargeInt &, const LargeInt &);

    //Multiplication and Division
    friend LargeInt &operator*=(LargeInt &, const LargeInt &);
    friend LargeInt operator*(const LargeInt &, const LargeInt &);

    friend LargeInt &operator/=(LargeInt &, const LargeInt &);
    friend LargeInt operator/(const LargeInt &, const LargeInt &);

    //Modulo
    friend LargeInt operator%(const LargeInt &, const LargeInt &);
    friend LargeInt &operator%=(LargeInt &, const LargeInt &);

    //Power Function
    friend LargeInt operator^(const LargeInt &, const LargeInt &);
    friend LargeInt &operator^=(LargeInt &, const LargeInt &); 

    //Square Root Function
    friend LargeInt sqrt(LargeInt &a);

    //Read and Write
    friend ostream &operator<<(ostream &,const LargeInt &);
    friend istream &operator>>(istream &, LargeInt &);

    //Others
    friend LargeInt NthCatalan(int n);
    friend LargeInt NthFibonacci(int n);
    friend LargeInt Factorial(int n);
};