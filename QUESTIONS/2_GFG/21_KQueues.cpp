class kQueues
{
    int n;
    int k;

    int *arr;  // for storing elements of queues
    int *frnt; // front element of queue i
    int *rear; // rear element of queue i
    int *next; // next free index OR next rear

    int frei;

public:
    kQueues(int n, int k)
    {
        // Initialize your data members
        this->n = n;
        this->k = k;

        arr = new int[n];

        frnt = new int[k];
        for (int i = 0; i < k; i++)
        {
            frnt[i] = -1;
        }

        rear = new int[k];
        for (int i = 0; i < k; i++)
        {
            rear[i] = -1;
        }

        next = new int[n];
        for (int i = 0; i < n - 1; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;

        frei = 0;
    }

    void enqueue(int x, int i)
    {
        // enqueue element x into queue i
        if (frei == -1) // overflow
        {
            return;
        }

        int idx = frei; // current free index in array

        frei = next[idx]; // update using next

        if (frnt[i] == -1) // if queue i is empty()
        {
            frnt[i] = rear[i] = idx; // update front & rear of queue i
            next[idx] = -1;          // as free index is stored in frei & now it points to next rear (doesn't exist yet)
        }
        else
        {
            next[rear[i]] = idx; // connect previous rear with new rear
            rear[i] = idx;       // update new rear
            next[idx] = -1;      // next rear doesn't exist yet
        }

        arr[idx] = x; // push given value
    }

    int dequeue(int i)
    {
        // dequeue element from queue i
        if (frnt[i] == -1) // underflow
        {
            return -1;
        }

        int idx = frnt[i]; // get index of front of queue i

        int x = arr[idx]; // stores front value of queue i

        frnt[i] = next[idx]; // update front to next element

        if (frnt[i] == -1)
        {
            rear[i] = -1; // if nothing left of queue i
        }

        next[idx] = frei; // update next to free index

        frei = idx; // update with current inedex

        return x; // returns popped value
    }

    bool isEmpty(int i)
    {
        // check if queue i is empty
        return frnt[i] == -1;
    }

    bool isFull()
    {
        // check if array is full
        return frei == -1;
    }
};

// TC = O(1)
// SC = O(n + k)

// https://www.geeksforgeeks.org/problems/implement-k-queues-in-a-single-array/1