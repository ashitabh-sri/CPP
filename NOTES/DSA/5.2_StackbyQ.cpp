#include <iostream>
#include <queue>
using namespace std;

/*
    Stack using 1 Queue

    Stack -> LIFO
    Queue -> FIFO

    q -> stores all elements

    PUSH:
        1. Push the new element into the queue.
        2. Move all previous elements from front to back.

        This makes the newly inserted element come
        to the front.

    POP:
        Simply remove q.front().

    TOP:
        Simply return q.front().

    EMPTY:
        Check whether q is empty.

    Complexity:
        push()  -> O(n)
        pop()   -> O(1)
        top()   -> O(1)
        empty() -> O(1)
        Space   -> O(n)

    Why push() is O(n)?
        After every push, we move all previous elements
        to the back of the queue.
*/

class MyStack
{
    queue<int> q;

public:
    // Push element into stack
    void push(int x)
    {
        q.push(x);

        // Move all previous elements behind x
        int n = q.size();

        for (int i = 0; i < n - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    // Remove and return top element
    int pop()
    {
        if (q.empty())
            return -1;

        int x = q.front();
        q.pop();

        return x;
    }

    // Return top element
    int top()
    {
        if (q.empty())
            return -1;

        return q.front();
    }

    // Check if stack is empty
    bool empty()
    {
        return q.empty();
    }
};

int main()
{
    MyStack st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    cout << "Top: " << st.top() << endl;

    cout << "Pop: " << st.pop() << endl;
    cout << "Pop: " << st.pop() << endl;

    st.push(50);

    cout << "Top: " << st.top() << endl;

    cout << "Pop: " << st.pop() << endl;
    cout << "Pop: " << st.pop() << endl;
    cout << "Pop: " << st.pop() << endl;

    cout << "Stack empty: " << boolalpha << st.empty() << endl;

    return 0;
}