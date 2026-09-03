class MyCircularQueue
{
    int size;
    int *arr;
    int frnt;
    int rear;

public:
    MyCircularQueue(int k) // O(1), O(k)
    {
        size = k;
        arr = new int[size];
        frnt = rear = -1;
    }

    bool enQueue(int value) // O(1)
    {
        if (frnt == -1) // first element to add
        {
            frnt = rear = 0;
            arr[rear] = value;
            return true;
        }

        if (isFull())
        {
            return false;
        }

        rear++;
        if (rear == size)
        {
            rear = 0;
        }

        arr[rear] = value;

        return true;
    }

    bool deQueue() // O(1)
    {
        if (isEmpty())
        {
            return false;
        }

        arr[frnt] = -1;

        if (frnt == rear) // last element to remove
        {
            frnt = rear = -1;
            return true;
        }

        frnt++;
        if (frnt == size)
        {
            frnt = 0;
        }

        return true;
    }

    int Front() // O(1)
    {
        if (isEmpty())
        {
            return -1;
        }

        return arr[frnt];
    }

    int Rear() // O(1)
    {
        if (isEmpty())
        {
            return -1;
        }

        return arr[rear];
    }

    bool isEmpty() // O(1)
    {
        return frnt == -1;
    }

    bool isFull() // O(1)
    {
        return frnt == (rear + 1) % size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

// TC = O(1)
// SC = O(k)