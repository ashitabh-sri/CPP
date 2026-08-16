#include <bits/stdc++.h> // contains almost all header files
//#include <algorithm>
using namespace std;

int main()
{
    int a = 10, b = 23;
    cout << a << " " << b << '\n';
    swap(a, b); // swap the values of two variables
    cout << a << " " << b << "\n\n";

    string S = "!avatsavirS hbatihsA si sihT";
    cout << S << '\n';
    reverse(S.begin(), S.end()); // reverse the desired range
    cout << S << "\n\n";

    vector<int> vec = {1, 2, 3, 4, 5};
    for(int v : vec){
        cout << v << " ";
    }
    cout << '\n';
    rotate(vec.begin(), vec.begin()+2, vec.end()); // rotates the elements in Clockwise manner
    for(int v : vec){
        cout << v << " ";
    }
    cout << "\n\n";

    // Search & Sort
    vector<int> nums = {2, 1, 3, 5, 4, 10, 9, 7, 8, 6};
    auto it = find(nums.begin(), nums.end(), 10); // linear search (generally), TC = O(n)
    if (it != nums.end())
    {
        cout << *it;
    }
    else
    {
        cout << "Given element Not Found!";
    }
    cout << "\n\n";

    sort(nums.begin(), nums.end()); // Sort in ascending order
    for (int i : nums)
    {
        cout << i << "\t";
    }
    cout << '\n';

    cout << binary_search(nums.begin(), nums.end(), 8) << '\n'; // binary search, TC = O(logn)

    sort(nums.rbegin(), nums.rend()); // Sort in descencding order
    for (int i : nums)
    {
        cout << i << "\t";
    }
    cout << "\n\n";

    vector<string> cntry = {"Start", "India", "Switzerland", "New York", "New Zealand", "Dubai", "End"};
    sort(cntry.begin() + 1, cntry.end() - 1); // Sorting - Starts from India, Ends at Dubai
    for (string i : cntry)
    {
        cout << i << "\t";
    }
    cout << "\n\n";

    // Upper & Lower Bound, Min, Max
    vector<int> nums1 = {3, 6, 9, 3, 7, 3, 9, 1};
    sort(nums1.begin(), nums1.end()); // bounds works only in sorted d.s.
    auto it1 = upper_bound(nums1.begin(), nums1.end(), 6); // finds the 1st value greater than given value
    if (it1 != nums1.end())
    {
        cout << *it1;
    }
    else
    {
        cout << "Upper Bound Not Found!";
    }
    cout << '\t';

    it1 = lower_bound(nums1.begin(), nums1.end(), 6); // finds the 1st value smaller than given value
    if (it1 != nums1.end())
    {
        cout << *it1;
    }
    else
    {
        cout << "Lower Bound Not Found!";
    }
    cout << "\n\n";

    vector<double> deci = {2.42, 5.23, -34.34, -2.33, 4.23};
    auto it2 = min_element(deci.begin(), deci.end()); // gives the minimum value
    cout << *it2 << "\t";
    auto it3 = max_element(deci.begin(), deci.end()); // gives the maximum value
    cout << *it3 << "\n\n";

    // Using Lambda Function
    vector<int> v = {5, 1, 8, 3, 9, 2};
    auto it4 = find_if(v.begin(), v.end(), [](const int &a) { // to find first element that is divisible by 3
        return a % 3 == 0;
    });
    if (it4 != v.end()){
        cout << *it4 << "\n\n";
    }
    else{
        cout << "No such element" << "\n\n";
    }

    return 0;
}