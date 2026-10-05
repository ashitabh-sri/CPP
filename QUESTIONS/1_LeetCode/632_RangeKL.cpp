class Solution
{
    struct Node
    {
        int val;
        int row;
        int col;

        Node(int v, int r, int c)
        {
            val = v;
            row = r;
            col = c;
        }
    };
    struct Compare
    {
        bool operator()(Node &a, Node &b)
        {                         // define compare for min heap
            return a.val > b.val; // Smaller Value => Priority
        }
    };

public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        int n = nums.size();
        priority_queue<Node, vector<Node>, Compare> mnh; // min heap
        int mx = INT_MIN;                                // current max range
        int beg, end;                                    // final ranges

        for (int i = 0; i < n; i++)
        {                                     // from every list..
            mnh.push(Node(nums[i][0], i, 0)); // ..push first element
            mx = max(mx, nums[i][0]);
        }
        beg = mnh.top().val;
        end = mx;

        while (true)
        {
            Node tem = mnh.top(); // minimum number
            mnh.pop();
            int mn = tem.val;  // current minimum range
            int row = tem.row; // min num's row
            int col = tem.col; // column

            if (mx - mn < end - beg)
            { // update the final range
                beg = mn;
                end = mx;
            }

            if (col + 1 == nums[row].size())
            {
                break;
            }

            mnh.push(Node(nums[row][col + 1], row, col + 1)); // add next element from row

            mx = max(mx, nums[row][col + 1]); // update current max range
        }

        return {beg, end};
    }
};

// Min Heap
// TC = O(N*logk), N = total no. of elements in all k lists
// SC = O(k)