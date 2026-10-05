#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> v)
{
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    // Lambda Expression : unnamed function written directly when needed
    auto hello = []() // auto variable = [capture](parameters)
    {
        cout << "Hello Universe!\n";
    };
    hello();

    auto res = [](int x) -> int // with parameters, can leave writing return type
    {
        return x + x;
    };
    cout << res(5) << "\n\n";

    vector<int> v1, v2;

    auto byRef = [&](int m) { // Capture all required External variables by Reference
        v1.push_back(m);
        v2.push_back(m);
    };

    auto byVal = [=](int m) mutable { // Capture all.. by Value, mutable - to modify captured variable, as taken constant
        v1.push_back(m);
        v2.push_back(m);
    };

    auto mixed = [&v1, v2](int m) mutable { // Capture v1 by Reference, v2 by Value
        v1.push_back(m);
        v2.push_back(m);
    };

    byRef(20);
    byVal(2347);
    mixed(10);

    print(v1);
    print(v2);

    vector<int> arr = {5, 2, 8, 1};
    sort(arr.begin(), arr.end(), [](int a, int b) { // lambda acts as comparator for sort
        return a > b; // If True => put a before b, sorts in descending order
    });

    vector<pair<int,int>> v = {
        {1, 5},
        {2, 3},
        {4, 1}
    };
    sort(v.begin(), v.end(), [](pair<int,int> a, pair<int,int> b) {
        return a.second < b.second; // a's second is smaller than b's second -> True -> put pair a before before pair b
    });

    return 0;
}