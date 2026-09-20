#include <bits/stdc++.h>
using namespace std;

int main() {

    // Character Hashing (as per ASCII values)
    string S;
    cin >> S;

    //precompute:
    int hash[256] = {0};
    for (int i = 0; i < S.size(); i++) {
        hash[S[i]]++;
    }

    int q;
    cin >> q;
    while (q--) {
        char c;
        cin >> c;
        
        // fetch:
        cout << hash[c] << endl;
    }

    // Number Hashing (using array)
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // precompute:
    int hash[13] = {0};
    for (int i = 0; i < n; i++) {
        hash[A[i]] += 1; // making Hash Table of frequency
    }

    int q;
    cin >> q;
    while (q--) {
        int num;
        cin >> num;
        
        // fetch:
        cout << hash[num] << endl;
    }

    // Hashing using unordered map
    // TC = O(N)
    // SC = O(N)
    int n;
    cin >> n;
    vector<int> B(n);
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    //precompute:
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[B[i]]++;
    }

    int q;
    cin >> q;
    while (q--) {
        int num;
        cin >> num;
        // fetch:
        cout << mp[num] << endl;
    }

    return 0;
}