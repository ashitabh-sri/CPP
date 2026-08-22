#include <bits/stdc++.h>
using namespace std;

// https://www.hackerrank.com/challenges/classes-objects/problem?isFullScreen=true

class Student
{
public:
    vector<int> score;

    void input(int x)
    {
        score.push_back(x);
    }

    int calculateTotalScore()
    {
        int sum = 0;
        for (int i : score)
        {
            sum += i;
        }
        return sum;
    }
};

int main()
{
    int n;
    cin >> n;

    Student kris;
    for (int i = 1; i <= 5; i++)
    {
        int a;
        cin >> a;
        kris.input(a);
    }
    int kscore = kris.calculateTotalScore();

    int count = 0;
    for (int k = 1; k <= n - 1; k++)
    {
        Student other;
        for (int i = 1; i <= 5; i++)
        {
            int a;
            cin >> a;
            other.input(a);
        }
        int oscore = other.calculateTotalScore();
        if (kscore < oscore)
            count++;
    }

    cout << count;

    return 0;
}