#include <iostream>
using namespace std;

// Array Implementation - Fixed Size
class Queue
{
    int size;
    int *arr;
    int frnt;
    int back;

public:
    Queue(int s)
    {
        size = s;
        arr = new int[size];
        frnt = back = -1;
    }

    bool full()
    {
        return back == size - 1;
    }

    bool empty()
    {
        return frnt == -1 || frnt > back;
    }

    void enqueue(int val)
    {
        if (full())
        {
            cout << "Queue is Full!\n";
            return;
        }

        if (frnt == -1)
        {
            frnt = back = 0;
            arr[back] = val;
            return;
        }

        back++;
        arr[back] = val;
    }

    int dequeue()
    {
        if (empty())
        {
            cout << "Queue is Empty!\n";
            return -1;
        }

        int val = arr[frnt];
        arr[frnt] = -1;
        frnt++;

        return val;
    }

    int front()
    {
        if (empty())
        {
            return -1;
        }

        return arr[frnt];
    }
};

// Linked List Implementation - No Fixed Size
class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        val = val;
        next = nullptr;
    }
};
class Queue
{
    Node *frnt;
    Node *back;

public:
    Queue()
    {
        frnt = back = nullptr;
    }

    bool empty()
    {
        return frnt == nullptr;
    }

    void enqueue(int val)
    {
        Node *newNode = new Node(val);

        if (empty())
        {
            frnt = back = newNode;
            return;
        }

        back->next = newNode;
        back = newNode;
    }

    int dequeue()
    {
        if (empty())
        {
            return -1;
        }

        Node *temp = frnt;
        int val = temp->val;
        frnt = frnt->next;

        if (frnt == nullptr)
        {
            back = nullptr;
        }

        delete temp;

        return val;
    }

    int front()
    {
        if (empty())
        {
            return -1;
        }

        return frnt->val;
    }
};

int main()
{
    Queue q(3);
    cout << "Empty: " << q.empty() << endl;
    cout << "Full: " << q.full() << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front: " << q.front() << endl;
    cout << "Full: " << q.full() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Front: " << q.front() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Empty: " << q.empty() << endl;

    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front: " << q.front() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Front: " << q.front() << endl;

    return 0;
}