#include <iostream>
using namespace std;

/*
Heap = Complete Binary Tree (Every level is completely filled (except possibly the last level), and last level is filled from Left to Right)
Max Heap = Root is Maximum, Children are smaller
Min Heap = Root is Minimum, Children are greater
*/

// Max Heap - Implementation using Array
class heap
{
public:
    int arr[1000];
    int size;

    heap()
    {
        size = 0; // size and last index
    }

    void Ins(int val) // TC = O(logn)
    {
        int idx = size; // last index
        size++;         // update size
        arr[idx] = val; // assign val

        while (idx > 0)
        {
            int par = (idx - 1) / 2; // Parent index, Heap property

            if (arr[par] < arr[idx])
            {
                swap(arr[par], arr[idx]); // fix position of assigned value
                idx = par;
            }
            else
            {
                return;
            }
        }
    }

    void Del() // TC = O(logn)
    {
        if (size == 0) // nothing to delete
        {
            return;
        }

        int i = 0; // root index
        arr[i] = arr[size - 1];
        size--; // update size

        while (2 * i < size) // if child exists to check with
        {
            int lefC = 2 * i + 1; // Left Child index, Heap property
            int rigC = 2 * i + 2; // Right Child index, Heap property
            int j = i;

            if (arr[i] < arr[lefC])
            {
                j = lefC;
            }
            if (rigC < size && arr[j] < arr[rigC])
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

    void Show() // TC = O(n)
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << '\n';
    }
};

// Heapify Algorithm
void heapify(int arr[], int n, int i)
{
    int mxi = i;
    int lefC = 2 * i + 1;
    int rigC = 2 * i + 2;

    if (lefC < n && arr[mxi] < arr[lefC])
    {
        mxi = lefC;
    }
    if (rigC < n && arr[mxi] < arr[rigC])
    {
        mxi = rigC;
    }

    if (mxi != i)
    {
        swap(arr[i], arr[mxi]);
        heapify(arr, n, mxi);
    }
}
// TC = O(logn)
// SC = O(logn)

// Heap Sort
void HeapSort(int arr[], int n)
{
    // Build Max Heap, O(n)
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // Move maximum to end + heapify, O(logn)
    int size = n;

    while (size > 1)
    {
        swap(arr[0], arr[size - 1]);
        size--;

        heapify(arr, size, 0);
    }
}
// TC = O(nlogn)
// SC = O(logn)

// Min Heap - 39th GFG Question

// STL Implementation in File : 6_queue.cpp

int main()
{
    heap h;
    h.Ins(50);
    h.Ins(55);
    h.Ins(53);
    h.Ins(52);
    h.Ins(54);
    h.Show();

    h.Del();
    h.Show();

    int arr[6] = {64, 54, 53, 55, 52, 50};
    int n = 6;
    HeapSort(arr, n);
    cout << "Printing array: \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << '\n';

    return 0;
}