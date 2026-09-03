#include <iostream>
using namespace std;

// Array Implementation - Fixed Size
class Stack
{
public:
    // Properties
    int size;
    int top;
    int *arr;

    // Initialization
    Stack(int s)
    {
        size = s;
        top = -1;
        arr = new int[size];
    }

    // Behaviour
    void push(int val)
    {
        if (top + 1 == size)
        {
            cout << "Stack Overflow!\n";
            return;
        }

        top++;
        arr[top] = val;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow!\n";
            return;
        }

        top--;
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is Empty! Error Code: ";
            return -1;
        }

        return arr[top];
    }

    bool empty()
    {
        return top == -1;
    }

    ~Stack()
    {
        delete[] arr;
    }
};

// Linked List Implementation - No Fixed Size
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};
class Stack1
{
public:
    Node *top;

    Stack1()
    {
        top = nullptr;
    }

    void push(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (top == nullptr)
        {
            cout << "Stack Underflow!\n";
            return;
        }

        Node *temp = top;
        top = top->next;
        delete temp;
    }

    int peek()
    {
        if (top == nullptr)
        {
            cout << "Stack is Empty! Error Code: ";
            return -1;
        }

        return top->data;
    }

    bool empty()
    {
        return top == nullptr;
    }
};

int main()
{
    Stack st(5);
    st.pop();
    cout << st.empty() << '\n'
         << st.peek() << '\n';
    st.push(0);
    st.push(5);
    st.push(10);
    st.push(15);
    st.push(20);
    st.push(25); // will cause Stack overflow
    st.pop();
    cout << st.empty() << '\n'
         << st.peek() << "\n\n";

    Stack1 st1;
    st1.pop();
    cout << st1.empty() << '\n'
         << st1.peek() << '\n';
    st1.push(0);
    st1.push(5);
    st1.push(10);
    st1.push(15);
    st1.push(20);
    st1.push(25); // won't be any overflow
    st1.pop();
    cout << st1.empty() << '\n'
         << st1.peek() << "\n\n";

    return 0;
}