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
};