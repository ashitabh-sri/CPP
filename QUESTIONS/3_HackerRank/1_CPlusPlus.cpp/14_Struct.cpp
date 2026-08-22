#include <bits/stdc++.h>
using namespace std;

// https://www.hackerrank.com/challenges/c-tutorial-struct/problem?isFullScreen=true

struct Student
{
    int age;
    string fname;
    string lname;
    int stnd;

    Student(int a, string f, string l, int s)
    {
        age = a;
        fname = f;
        lname = l;
        stnd = s;
    }

    void display()
    {
        cout << age << " " << fname << " " << lname << " " << stnd;
    }
};

int main()
{
    int a, s;
    string f, l;
    cin >> a >> f >> l >> s;

    Student john(a, f, l, s);
    john.display();
    return 0;
}
