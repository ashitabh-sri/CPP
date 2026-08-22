#include <bits/stdc++.h>
using namespace std;

// https://www.hackerrank.com/challenges/c-tutorial-stringstream/problem?isFullScreen=true

vector<int> parselnts(string line)
{
    stringstream ss1(line);
    string temp;
    int n = 0;
    while (getline(ss1, temp, ','))
    { // reads the stringstream ss1, stores in temp, until next comma
        n++;
    }
    stringstream ss(line);
    vector<int> vecss;
    for (int p = 1; p <= n; p++)
    {
        int a;
        char ch;

        ss >> a >> ch;

        vecss.push_back(a);
    }

    return vecss;
}

int main()
{
    string line;
    getline(cin, line);

    vector<int> vecss = parselnts(line);
    for (int q : vecss)
    {
        cout << q << endl;
    }
    return 0;
}
