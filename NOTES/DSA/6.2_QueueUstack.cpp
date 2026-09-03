#include <iostream>
#include <stack>
using namespace std;

/*
    Queue using 2 Stacks

    Queue  -> FIFO
    Stack  -> LIFO

    s1 -> incoming elements
    s2 -> outgoing elements

    PUSH:
        Simply push into s1.

    POP / FRONT:
        If s2 is empty:
            Transfer all elements from s1 -> s2.

        This reverses the order, so the oldest element
        comes to the top of s2.

    Example:
        enqueue: 1 2 3
        s1:
        3
        2
        1

        Transfer to s2:
        s2:
        1 <- top
        2
        3

        Now 1 is the front of the queue.

    Complexity:
        push()       -> O(1)
        pop()        -> O(1) amortized
        front()      -> O(1) amortized
        empty()      -> O(1)
        Space        -> O(n)

    Why pop/front is O(1) amortized?
        Each element is transferred from s1 to s2
        at most once.
*/

class MyQueue
{
    stack<int> s1, s2;

public:
    // Push element into queue
    void push(int x)
    {
        s1.push(x);
    }

    // Remove and return front element
    int pop()
    {

        // Transfer only when s2 is empty
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int x = s2.top();
        s2.pop();

        return x;
    }

    // Return front element
    int front()
    {

        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    // Check if queue is empty
    bool empty()
    {
        return s1.empty() && s2.empty();
    }
};

int main()
{

    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout << "Front: " << q.front() << endl;

    cout << "Pop: " << q.pop() << endl;
    cout << "Pop: " << q.pop() << endl;

    q.push(50);

    cout << "Front: " << q.front() << endl;

    cout << "Pop: " << q.pop() << endl;
    cout << "Pop: " << q.pop() << endl;
    cout << "Pop: " << q.pop() << endl;

    cout << "Queue empty: " << boolalpha << q.empty() << endl;

    return 0;
}