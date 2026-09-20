#include <iostream>
#include <string>
#include <limits>
#include <iomanip> // set_, manipulators...
using namespace std;

int main()
{
     // Output
     cout << "This is Ashitabh Srivastava!";                                   // << : Insertion operator to show data on console
     cout << " Learning C++ language.." << endl;                               // end of line
     cout << "Another\tEscape sequence, \\Back Slash, \"Double Quotes\" \n\n"; // \n - newline character, \t = tab character

     // Input
     cout << "\tPrinting from User Input :-\n";
     double v;
     cout << "Type any Number: ";
     cin >> v; // user input
     cout << "Entered Number: " << v << "\n\n";

     long b;
     char c;
     double e;
     cout << "Type any Number, Character & Decimal: ";

     scanf("%ld %c %lf", &b, &c, &e);     // large no. of Inputs
     printf("%ld\n%c\n%lf\n\n", b, c, e); // large no. of Outputs

     // Output stream Modifiers
     cout << setw(10) << 2342 << endl;                    // width for next output
     cout << setprecision(4) << 3.14159 << endl;          // 4 significant digits
     cout << fixed << setprecision(4) << 3.14159 << endl; // 4 digits after decimal
     cout << showpoint << 42.0 << endl;                   // always show the decimal point (even for whole numbers)
     cout << scientific << 3.14159 << "\n\n";             // exponential form of 10^_

     // Boolean Manipulators
     bool answer = true;
     cout << boolalpha << "Is C++ fun: " << answer << endl;      // true/false
     cout << noboolalpha << "Rank of C++: " << answer << "\n\n"; // 1/0

     // Alignment & Sign Manipulators
     int num = 77;
     cout << "Left Aligned: " << left << setw(10) << num << endl;
     cout << "Right Aligned: " << right << setw(10) << num << endl;
     cout << "Show +ve sign: " << showpos << num << endl;
     cout << "No +ve sign: " << noshowpos << num << "\n\n";

     // Base Manipulators
     cout << "Hexadecimal: " << hex << num << endl;
     cout << "Decimal: " << dec << num << endl;
     cout << "Octal: " << oct << num << endl;

     // Input stream Modifiers
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
     int a;
     a = cin.get(); // can take newline, tab and space as input
     cout << "Value provided by User: " << a << "\n\n";

     cin.ignore(numeric_limits<streamsize>::max(), '\n');
     string fullName;
     cout << "Type your Full Name: ";
     getline(cin, fullName); // take whole line as input, only newline as terminator
     cout << "Your name is: " << fullName << "\n\n";

     char x, y;
     cout << "Type a character: ";
     cin >> ws >> x; // ignore leading whitespace, default
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
     cout << "Type another character: ";
     cin >> noskipws >> y; // don't skip whitespace
     cout << "x: " << x << ", y: " << y << "\n\n";

     // Error Handling
     int n1;
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
     cout << "Enter any Number (except Zero): ";
     cin >> n1;
     if (n1 == 0)
     {
          cerr << "Error!! Are You even Listening??" << "\n\n"; // immediate display of error
          return 1;                                             // exit the program with error code 1
     }
     else
     {
          cout << "You entered: " << n1 << "\n\n";
     }

     return 0;
}