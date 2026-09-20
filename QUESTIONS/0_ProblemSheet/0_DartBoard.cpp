#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Set a (+ve) Max point for Dart Board: ";
    cin >> n;

    if(n == 1){
        cout << 1 << '\n';
        return 0;
    }

    int size = 2*n - 1;
    for(int i=0; i < size; i++){
        for(int j=0; j < size; j++){
            int k = min({i, j, (size-1)-i, (size-1)-j});
            cout << n-k << " ";
        }
        cout << '\n';
    }

    return 0;
}