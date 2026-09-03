#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int main()
{
    // Queue : First In First Out
    queue<char> line;
    line.push('Z');
    line.push('A'); // add element at back
    line.push('B');
    line.push('C');
    line.push('W');
    cout << line.size() << "\t" << line.empty() << "\n";
    cout << line.front() << "\t" << line.back() << "\n";
    line.front() = 'Y';
    line.back() = 'D';
    cout << line.front() << "\t" << line.back() << "\n\n";
    line.pop(); // remove element at front
    cout << line.front() << "\n\n";

    // Double-Ended Queue : Insertion & Deletion from both sides
    deque<char> line = {'P', 'Q', 'W', 'S', 'T'};
    for (char a : line)
    {
        cout << a << "\t";
    }
    cout << "\n\n";
    cout << line[1] << "\t" << line.at(3) << "\n";
    cout << line.front() << "\t" << line.back() << "\n";
    line.at(2) = 'R';
    cout << line.at(2) << "\n";
    cout << line.size() << "\t";
    cout << line.empty() << "\n\n";
    line.push_back('Y');  // add element at back
    line.push_front('O'); // add element at front
    cout << line.front() << "\t" << line.back() << "\n\n";
    line.pop_back();  // remove element at back
    line.pop_front(); // remove element at front
    cout << line.front() << "\t" << line.back() << "\n\n";
    line.erase(line.begin(), line.begin() + 1); // inclusive, exclusive
    for (char a : line)
    {
        cout << a << "\t";
    }
    cout << "\n\n";

    // Priority Queue : Orders in certain way
    priority_queue<int> maxh; // Max Heap
    maxh.push(1);
    maxh.push(2);
    maxh.push(5);
    maxh.push(4);
    int n = maxh.size(); // gives no. of elements
    for (int i = 0; i < n; i++)
    {
        cout << maxh.top() << "\t"; // gives top element = largest element
        maxh.pop();                 // removes element
    }
    cout << "\n\n";

    priority_queue<int, vector<int>, greater<int>> minh; // Min Heap
    minh.push(1);
    minh.push(2);
    minh.push(5);
    minh.push(4);
    int n1 = minh.size();
    for (int i = 0; i < n1; i++)
    {
        cout << minh.top() << "\t"; // gives top element = smallest element
        minh.pop();
    }
    cout << "\n\n";
    cout << minh.empty(); // gives 1 = if the heap is empty

    return 0;
}