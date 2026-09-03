class Solution
{
public:
    int startStation(vector<int> &gas, vector<int> &cost)
    {
        //  code here
        int n = gas.size();
        int beg = 0;
        int bal = 0;
        int les = 0;

        for (int i = 0; i < n; i++)
        {
            bal += gas[i] - cost[i];
            if (bal < 0)
            {
                beg = i + 1;
                les += bal;
                bal = 0;
            }
        }

        if (bal + les >= 0)
        {
            return beg;
        }
        else
        {
            return -1;
        }
    }
};

// TC = O(n)
// SC = O(1)

// https://www.geeksforgeeks.org/problems/circular-tour-1587115620/1