#include <bits/stdc++.h>
using namespace std;

int main(){
    int n1, n2;
    cout << "Enter Two numbers: ";
    cin >> n1 >> n2;

    int ans = min(n1, n2);
    while(ans > 1){
        if(n1%ans == 0 && n2%ans == 0) break;
        ans--;
    }

    cout << "GCD = " << ans << "\n\n";

    // Divisors
    int n;
    cout << "Enter a Number: ";
    cin >> n;

    vector<int> A;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            A.push_back(i);
    }

    for (int a : A)
        cout << a << " ";

    // Check Prime no.
    int n;
    cout << "Enter number to check Prime: ";
    cin >> n;

    if (n <= 1)
    {
        cout << "False";
        return 0;
    }

    bool chk = true;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            chk = false;
            break;
        }
    }

    cout << boolalpha << chk;

    return 0;
}