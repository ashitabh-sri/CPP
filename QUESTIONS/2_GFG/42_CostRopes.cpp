// https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

class Solution
{
public:
    int minCost(vector<int> &arr)
    {
        // code here
        priority_queue<long long, vector<long long>, greater<long long>> mnh;
        for (int a : arr)
        {
            mnh.push(a);
        }

        long long cost = 0;
        while (mnh.size() > 1)
        {
            long long a = mnh.top();
            mnh.pop();

            long long b = mnh.top();
            mnh.pop();

            long long sum = a + b;

            cost += sum;
            mnh.push(sum);
        }

        return cost;
    }
};

// Min Heap
// TC = O(nlogn)
// SC = O(n)