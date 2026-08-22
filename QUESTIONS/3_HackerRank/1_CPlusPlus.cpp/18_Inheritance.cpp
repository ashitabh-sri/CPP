#include <bits/stdc++.h>
using namespace std;

// https://www.hackerrank.com/challenges/inheritance-introduction/problem?isFullScreen=true

class Triangle
{
public:
    void tri()
    {
        cout << "I am a triangle";
    }
};

class Isosceles : public Triangle
{
public:
    void iso()
    {
        cout << "I am an isosceles triangle\n"
             << "In an isosceles triangle two sides are equal\n";
    }
};

int main()
{
    Isosceles isotri;
    isotri.iso();
    isotri.tri();
    return 0;
}