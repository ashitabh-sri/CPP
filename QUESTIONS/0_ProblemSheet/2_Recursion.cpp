#include <bits/stdc++.h>
using namespace std;

// Reverse Array
// Time Complexity : O(n)
// Space Complexty : O(1)
class Solution{
    public:
        void revarr(vector<int>& arr){
            int s = 0, e = arr.size() - 1;

            while(s < e){
                swap(arr[s], arr[e]);
                s++;
                e--;
            }
        }
};

// Check for Palindrome String
// Time Complexity: O(n)
// Space Complexity: O(n)
bool palindrome(int i, string& s) {
    if (i >= (int)s.length() / 2) return true; // Base Condition: If i exceeds half of the string, all the elements have been compared

    if (s[i] != s[s.length() - i - 1]) return false; // If characters are not equal: it's not a palindrome

    else return palindrome(i + 1, s); // If both characters are the same
}

// Fibonacci Series
// TC = O(2^n)
// SC = O(n)
int Fibo(int n){
    if(n <= 1) return n;

    int lst = Fibo(n-1), slst = Fibo(n-2); // Two Function calls for each

    return lst + slst;
}

int main(){

    // reverse array
    int n = 0;
    cout << "Enter the Size of Array: ";
    cin >> n;

    vector<int> A(n);
    cout << "Enter the Elements: ";
    for(int i=0; i<n; i++) cin >> A[i];

    cout << "Your given Array: ";
    for(int i : A) cout << i << " ";

    Solution sol;
    sol.revarr(A);
    cout << "\nReversed Array: ";
    for(int i : A) cout << i << " ";

    // check for palindrome string
    string S;
    cout << "Enter a String to check for Palindrome: ";
    cin >> S;

    bool chk = palindrome(0, S);
    if(chk) cout << "String is Palindrome";
    else cout << "String is not Palindrome";

    // fibonacci series
    int n;
    cout << "Enter the term for Fibonacci Series: ";
    cin >> n;

    cout << Fibo(n) << '\n';

    return 0;
}