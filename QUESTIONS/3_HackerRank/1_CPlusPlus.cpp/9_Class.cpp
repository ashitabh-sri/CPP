#include <bits/stdc++.h>
using namespace std;

// https://www.hackerrank.com/challenges/c-tutorial-class/problem?isFullScreen=true

class student
{
public:
    int age;
    string fname;
    string lname;
    int std;

    student(int w, string x, string y, int z)
    {
        age = w;
        fname = x;
        lname = y;
        std = z;
    }

    void id()
    {
        cout << age << endl
             << lname << ", " << fname << endl
             << std << "\n\n";
        cout << age << "," << fname << "," << lname << "," << std;
    }
};

int main()
{
    int a;
    string fn;
    string ln;
    int s;
    cin >> a >> fn >> ln >> s;

    student robo(a, fn, ln, s);
    robo.id();

    return 0;
}