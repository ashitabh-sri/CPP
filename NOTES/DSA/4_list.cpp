#include <iostream>
#include <list>
using namespace std;

int main()
{
    // List : implementation of Doubly linked list
    list<int> todo = {20, 3, 4, 5, 6, 7, 8, 90};
    for (int i : todo)
    {
        cout << i << "\t";
    }
    cout << "\n\n";

    // Same functions as previos DS
    cout << todo.front() << "\t" << todo.back() << '\n';
    todo.front() = 2; // overwriting values with front
    todo.back() = 9; // or back
    cout << todo.front() << "\t" << todo.back() << "\n";
    cout << todo.size() << "\t" << todo.empty() << "\n\n";

    todo.push_front(1); // add element at front
    todo.push_front(0);
    todo.push_back(10); // add element at end
    todo.push_back(11);
    todo.pop_front(); // remove element at front : 0
    todo.pop_back();  // remove element at end : 11
    for (int i : todo)
    {
        cout << i << "\t";
    }
    cout << "\n\n";

    list<int> L(6, 89);
    for(int i : L){
        cout << i << "\t";
    }
    cout << "\n\n";

    return 0;
}