class kStacks
{
    int N; // Size of array
    int K; // Number of stacks

    int *arr;  // Stores actual values
    int *top;  // top indices of each stack
    int *next; // Initially points free space, then previous element

    int freeid; // free space's index

public:
    kStacks(int n, int k) // // TC = O(N + K)
    {
        // initialize data structures for k stacks
        N = n;
        K = k;

        arr = new int[N];
        top = new int[K];
        next = new int[N];

        for (int i = 0; i < K; i++)
        {
            top[i] = -1;
        }

        for (int i = 0; i < N; i++)
        {
            next[i] = i + 1;
        }
        next[N - 1] = -1;

        freeid = 0;
    }

    void push(int x, int i) // TC = O(1)
    {
        // push element x into stack i
        if (freeid == -1)
        {
            return; // Stack Overflow (no space left to push)
        }

        int id = freeid; // index of free space

        arr[id] = x; // initialized the value

        freeid = next[id]; // update freeid

        next[id] = top[i]; // update next from free space to previous element

        top[i] = id; // update the new top of stack i
    }

    int pop(int i) // TC = O(1)
    {
        // pop element from stack i
        if (top[i] == -1)
        {
            return -1; // Stack Underflow (no element to pop in stack i)
        }

        int id = top[i]; // get the top element index

        top[i] = next[id]; // update top element id to previous one using next

        next[id] = freeid; // update next back to pointing next free space

        freeid = id; // update freeid to current free space

        return arr[id]; // return the popped element
    }
};

// SC = O(N = K)

// https://www.geeksforgeeks.org/problems/implement-k-stacks-in-an-array/1