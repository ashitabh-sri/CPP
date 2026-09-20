class minHeap
{
private:
    // Initialize your data members
    int Hsize;
    int arr[1000000];

public:
    minHeap()
    {
        Hsize = 0;
    }

    void push(int x)
    {
        // Insert x into the heap
        int idx = Hsize;
        arr[idx] = x;
        Hsize++;

        while (idx > 0)
        {
            int par = (idx - 1) / 2; // Parent index, Heap Property
            if (arr[idx] < arr[par])
            {
                swap(arr[idx], arr[par]);
                idx = par;
            }
            else
            {
                return;
            }
        }
    }

    void pop()
    {
        // Remove the top (minimum) element
        Hsize--;
        arr[0] = arr[Hsize];

        int i = 0;
        while (2 * i + 1 < Hsize)
        {
            // 0-based index
            int lefC = 2 * i + 1; // Left Child index, Heap Property
            int rigC = 2 * i + 2; // Right Child index, Heap property
            int j = i;

            if (arr[i] > arr[lefC])
            {
                j = lefC;
            }
            if (rigC < Hsize && arr[j] > arr[rigC])
            {
                j = rigC;
            }
            if (j == i)
            {
                return;
            }
            swap(arr[i], arr[j]);
            i = j;
        }
    }

    int peek()
    {
        // Return the top element or -1 if empty
        if (Hsize == 0)
        {
            return -1;
        }

        return arr[0];
    }

    int size()
    {
        // Return the number of elements in the heap
        return Hsize;
    }
};

// Min Heap, Parent is Smaller
// TC = O(logn)
// SC = O(n)

// https://www.geeksforgeeks.org/problems/min-heap-implementation/1