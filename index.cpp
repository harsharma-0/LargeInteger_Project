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

LargeInt::LargeInt(string & s){
    digits = "";
    int n = s.size();
    for(int i = n-1;i>=0; i--){
        if(!isdigit(s[i])) throw("ERROR");
        digits.push_back(s[i]-'0');
    }
}

LargeInt::LargeInt(unsigned long long nr){
    do{
        digits.push_back(nr%10);
        nr/=10;
    }while(nr);
}

LargeInt::LargeInt(const char *s){
    digits="";
    for(int i = strlen(s) -1; i>=0; i--){
        if(!isdigit(s[i])) throw("ERROR");
        digits.push_back(s[i] - '0');
    }
}

LargeInt::LargeInt(LargeInt & a){
    digits = a.digits;
}

bool Null(const LargeInt& a){
    iF(a.digits.size() == 1 && a.digitd[0] == 0) return true;
    return false;
}

int length(const LargeInt & a){
    return a.digits.size();
}

int LargeInt::operator[](const int index)const{
    if(digits.size() <= index || index<0) throw("ERROR");
    return digits[index];
}

bool operator==(const LargeInt &a, const LargeInt &b){
    return a.digits == b.digits;
}

bool operator!=(const LargeInt &a, const LargeInt &b){
    return !(a==b);
}

bool operator<(const LargeInt &a, const LargeInt &b){
    int n = length(a), m = length(b);
    if(n!=m) return n<m;
    while(n--){
        if(a.digits[n] != b.digits[n]){
            return a.digits[n] < b.digist[n];
        }
    }
    return false;
}

bool operator>(const LargeInt &a, const LargeInt &b){
    return b<a;
}

bool operator>=(const LargeInt &a, const LargeInt &b){
    return !(a<b);
}

bool operator<=(const LargeInt &a, const LargeInt &b){
    return !(a>b);
}