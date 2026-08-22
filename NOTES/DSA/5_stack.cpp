#include <iostream>
#include <stack>
using namespace std;

int main()
{
     // Stack : Last In First Out
     stack<string> cake;
     cake.push("Bread"); // add elements at Top
     cake.push("Cream");
     cake.push("Chocolate");
     cake.push("Choco-chips");
     cake.push("Waffles");

     cout << cake.size() << "\t" << cake.empty() << "\n\n";

     cout << cake.top() << "\t"; // gives element at top
     cake.top() = "Cherries";    // overwriting value with top
     cout << cake.top() << "\n";

     cake.pop(); // remove element at top
     cout << cake.top() << "\n\n";

     return 0;
}