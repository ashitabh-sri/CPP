#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Selection Sort - Unstable
void SelSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int mni = i; // current index

        for (int j = i + 1; j < n; j++) // compare with right elements
        {
            if (arr[mni] > arr[j])
            {
                mni = j; // // find smallest element's index
            }
        }

        swap(arr[i], arr[mni]); // swap with current index
    }

    cout << "\nSelection Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
// TC = O(n^2)
// SC = O(1)

// Bubble Sort - Stable
void BubSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) // n times
    {
        bool swapped = false;

        for (int j = 0; j < (n - 1) - i; j++)
        {
            if (arr[j] > arr[j + 1]) // if larger on left
            {
                swap(arr[j], arr[j + 1]); // shifts larger on right
                swapped = true;
            }
        }

        if (!swapped) // No swaps => Array is Sorted
        {
            break;
        }
    }

    cout << "\nBubble Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
// TC = O(n^2), O(n) for already Sorted
// SC = O(1)

// Insertion Sort - Stable
void InsSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int pos = i;
        int cur = arr[i]; // store current value
        int j = i - 1;    // index for left side

        while (j >= 0 && cur < arr[j]) // current element is smaller than left
        {
            arr[j + 1] = arr[j]; // keep shifting elements to right
            pos = j;             // store correct index
            j--;
        }

        arr[pos] = cur; // insert value at correct position
    }

    cout << "\nInsertion Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
// TC = O(n^2), O(n) for already Sorted
// SC = O(1)

void print(vector<int> &arr)
{
    for (int a : arr)
    {
        cout << a << " ";
    }
}

// Counting Sort - Stable
void countSort(vector<int> &arr)
{
    if (arr.empty())
    {
        return;
    }

    int n = arr.size();

    // Find maximum value
    int maxv = arr[0];
    for (int i = 1; i < n; i++)
    {
        maxv = max(maxv, arr[i]);
    }

    // Count array
    vector<int> count(maxv + 1, 0);

    for (int x : arr)
    {
        count[x]++;
    }

    // Prefix sum -> positions
    for (int i = 1; i <= maxv; i++)
    {
        count[i] += count[i - 1];
    }

    // Output array
    vector<int> output(n);

    // Traverse from right to left to maintain stability
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy back
    arr = output;
}
// TC = O(n + k)
// SC = O(n + k)

// Radix Sort - Stable
void countSort(vector<int> &arr, int exp)
{
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    // Count occurrences of each digit
    for (int i = 0; i < n; i++)
    {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // Prefix sum -> positions
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // Build output from right to left -> stable
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;

        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy back
    arr = output;
}
void radixSort(vector<int> &arr)
{
    if (arr.empty())
    {
        return;
    }

    // Find maximum value
    int maxv = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        maxv = max(maxv, arr[i]);
    }

    // Sort by each digit
    for (int exp = 1; maxv / exp > 0; exp *= 10)
    {
        countSort(arr, exp);
    }
}
// TC = O(d(n + k))
// SC = O(n + k)

// Qucik Sort - Unstable, Suitable for Arrays (random access of elements)
int part(vector<int> &arr, int s, int e)
{
    int piv = arr[s]; // letting pivot element
    int cnt = 0;      // counter to smaller elements than pivot

    for (int i = s; i < e; i++)
    {
        if (arr[i] <= piv)
        {
            cnt++;
        }
    }

    int pivid = s + cnt;
    swap(arr[s], arr[pivid]); // putting pivot to right index
    int i = s, j = e;

    while (i < pivid && j > pivid)
    {
        while (arr[i] < piv) // skipping the
        {
            i++;
        }
        while (arr[j] > piv) // right order elements
        {
            j--;
        }

        if (arr[i] > piv && arr[j] < piv)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivid;
}
void quicksort(vector<int> &arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int piv = part(arr, s, e);  // pivot index
    quicksort(arr, s, piv - 1); // left side
    quicksort(arr, piv + 1, e); // right side
}
// TC = O(n^2), Avg/Best : O(nlogn)
// SC = O(n), Avg : O(logn)

// Merge Sort - Stable, Suitable for Linked List (retains the order)
void merge(vector<int> &arr, int beg, int end)
{
    int mid = (beg + end) / 2;
    int n1 = mid - beg + 1; // left's size
    int n2 = end - mid;     // right's size
    int left[n1], right[n2];
    int k = beg;

    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[k++];
    }

    k = mid + 1;

    for (int i = 0; i < n2; i++)
    {
        right[i] = arr[k++];
    }

    int i = 0, j = 0;
    k = beg;

    while (i < n1 && j < n2) // sort and insert
    {
        if (left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }

    while (i < n1) // add any leftovers
    {
        arr[k++] = left[i++];
    }
    while (j < n2) // in any
    {
        arr[k++] = right[j++];
    }
}
void mergesort(vector<int> &arr, int beg, int end)
{
    if (beg >= end) // single element is sorted
        return;

    int mid = (beg + end) / 2;
    mergesort(arr, beg, mid);     // left part division
    mergesort(arr, mid + 1, end); // right part division
    merge(arr, beg, end);         // merge to finish
}
// TC = O(nlogn)
// SC = O(n)

// Heap Sort - In the File : 12_Heaps.cpp

// Bucket Sort - Stable (if sorting inside each bucket is stable)
// Best suited for uniformly distributed values in a known range
void bucketSort(vector<float> &arr)
{
    if (arr.empty())
    {
        return;
    }

    int n = arr.size();

    // Create n empty buckets
    // Bucket index represents the range in which the element falls
    vector<vector<float>> bucket(n);

    // Distribute elements into appropriate buckets
    for (float x : arr)
    {
        int index = x * n;
        bucket[index].push_back(x);
    }

    // Sort each individual bucket
    for (int i = 0; i < n; i++)
    {
        sort(bucket[i].begin(), bucket[i].end());
    }

    // Combine all buckets back into the original array
    int index = 0;

    for (int i = 0; i < n; i++)
    {
        for (float x : bucket[i])
        {
            arr[index++] = x;
        }
    }
}
// TC = O(n^2), avg O(n + k)
// SC = O(n + k)

int main()
{
    int arr[26] = {5, 7, 2, 7, 7, 2, 2, 7, 8, 9, 2, 0, 4, 7, 2, 2, 1, 7, 8, 6, 5, 3, 3, 1, 2, 2};
    SelSort(arr, 26);

    arr = {5, 7, 2, 7, 7, 2, 2, 7, 8, 9, 2, 0, 4, 7, 2, 2, 1, 7, 8, 6, 5, 3, 3, 1, 2, 2};
    BubSort(arr, 26);

    arr = {5, 7, 2, 7, 7, 2, 2, 7, 8, 9, 2, 0, 4, 7, 2, 2, 1, 7, 8, 6, 5, 3, 3, 1, 2, 2};
    InsSort(arr, 26);

    vector<int> arr1 = {52, 25, 23, 523, 356, 253, 7347, 246, 745, 2, 52, 253};
    radixsort(arr1);
    cout << "\n\nRadix Sorted: ";
    print(arr1);

    vector<int> arr2 = {52, 25, 23, 523, 356, 253, 7347, 246, 745, 2, 52, 253};
    countsort(arr2);
    cout << "\nCount Sorted: ";
    print(arr2);

    vector<int> arr3 = {52, 25, 23, 523, 356, 253, 7347, 246, 745, 2, 52, 253};
    quicksort(arr3, 0, 11);
    cout << "\nQuick Sorted: ";
    print(arr3);

    vector<int> arr4 = {52, 25, 23, 523, 356, 253, 7347, 246, 745, 2, 52, 253};
    mergesort(arr4, 0, 11);
    cout << "\nMerge Sorted: ";
    print(arr4);

    vector<float> arr5 = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
    bucketSort(arr5);
    cout << "\nBucket Sorted: ";
    for (float x : arr5)
    {
        cout << x << " ";
    }

    return 0;
}