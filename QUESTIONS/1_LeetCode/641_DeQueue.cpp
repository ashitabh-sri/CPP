class MyCircularDeque
{
private:
    vector<int> deq;
    int frnt, rear;
    int siz, cap;

public:
    MyCircularDeque(int k)
    {
        cap = k;
        deq.resize(k);
        frnt = rear = 0;
        siz = 0;
    }

    bool insertFront(int value)
    {
        if (isFull())
        {
            return false;
        }

        frnt = (frnt - 1 + cap) % cap; // to handle -ve index and make it circular
        deq[frnt] = value;
        siz++;

        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
        {
            return false;
        }

        deq[rear] = value;
        rear = (rear + 1) % cap; // to make it circular
        siz++;

        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
        {
            return false;
        }

        frnt = (frnt + 1) % cap;
        siz--;

        return true;
    }

    bool deleteLast()
    {
        if (isEmpty())
        {
            return false;
        }

        rear = (rear - 1 + cap) % cap;
        siz--;

        return true;
    }

    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }

        return deq[frnt];
    }

    int getRear()
    {
        if (isEmpty())
        {
            return -1;
        }

        return deq[(rear - 1 + cap) % cap];
    }

    bool isEmpty()
    {
        return siz == 0;
    }

    bool isFull()
    {
        return siz == cap;
    }
};

// TC = O(1)
// SC = O(k)