#include <queue>
class MedianFinder
{
public:
    priority_queue<int> lef;                            // max heap
    priority_queue<int, vector<int>, greater<int>> rig; // min heap

    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (lef.empty() || num <= lef.top())
        {
            lef.push(num);
        }
        else
        {
            rig.push(num);
        }

        // balancing both sides
        if (lef.size() > rig.size() + 1)
        { // lef can atmost 1 more than rig
            rig.push(lef.top());
            lef.pop();
        }
        else if (lef.size() < rig.size())
        {
            lef.push(rig.top());
            rig.pop();
        }
    }

    double findMedian()
    {
        if (lef.size() == rig.size())
        { // even sized list
            return (lef.top() + rig.top()) / 2.0;
        }

        return lef.top(); // odd sized list
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

// Two Heaps
// TC = O(logn), O(1)
// SC = O(n)