#include <iostream>
#include <unordered_set>
#include <set>
using namespace std;

int main()
{
    // Set : Only stores unique vales
    unordered_set uset = {"Beta", "Alpha", "Gamma", "Epsilon", "Delta"}; // TC = O(1)
    for (string str : uset)
    {
        cout << str << "\t";
    }
    cout << "\n\n";

    set<string> mySet = {"Beta", "Alpha", "Delta", "Gamma", "Epsilon"}; // Sorted in Ascending order ny default
    for (string str : mySet)                                            // sorted alphabetically
    {
        cout << str << "\t";
    }
    cout << "\n\n";

    set<int> mySet2 = {1, 5, 4, 2, 3};
    for (int i : mySet2) // sorted numerically
    {
        cout << i << "\t";
    }
    cout << "\n\n";

    set<int, greater<int>> mySet3 = {1, 5, 4, 2, 3}; // to Sort in Descending order
    for (int i : mySet3)
    {
        cout << i << "\t";
    }
    cout << "\n\n";

    set<string> mySet4 = {"Assassin Creed", " Batman's Night", "C", "Detroit", "Detroit", "Elden Ring"}; // ignores Duplicate values
    for (string str : mySet4)
    {
        cout << str << "\t";
    }
    cout << "\n\n";

    set<double> mySet5 = {1, 3.14, 9.8, 1.38};
    mySet5.insert(6.63); // add element
    mySet5.insert(9.1);
    auto result = mySet5.insert(10); // insert() => pair<iterator, bool>
    // result.first : iterator pointing to 10
    // result.second : true or false - true if value was inserted i.e. value wasn't present
    mySet5.erase(1); // remove element by vale
    auto it = mySet5.begin();
    it++;
    mySet5.erase(it); // remove element by iterator
    for (double d : mySet5)
    {
        cout << d << "\t";
    }
    cout << "\n";

    cout << mySet5.count(9.8) << '\n'; // True if element is present
    auto it1 = mySet5.find(9.8);       // if found returns an Iterator
    if (it1 != mySet5.end())
        mySet5.erase(it1);

    cout << mySet5.size() << "\t";
    mySet5.clear();
    cout << mySet5.empty() << "\n\n";

    set<int, greater<int>> B;
    B.insert(23);
    B.insert(34);
    B.insert(64);
    B.insert(12);
    auto it = B.begin();
    advance(it, 2); // moves the pointer forward

    cout << *it << " ";

    // Multi-set : can store duplicate values
    multiset<int> ms = {3, 1, 2, 3};
    ms.insert(2);
    cout << ms.count(3) << '\n';
    ms.erase(ms.find(2));
    for (int x : ms)
        cout << x << ' ';

    return 0;
}