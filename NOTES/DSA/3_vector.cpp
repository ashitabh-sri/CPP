#include <iostream>
#include <array>
#include <vector>
using namespace std;

int main()
{
     // Array : container for same type of data
     array<int, 5> A = {5, 1, 7, 8, 2};

     cout << A[2] << " ";                          // access elements by Index
     cout << A.at(4) << '\n';                      // safer access for out of Bounds
     cout << A.empty() << '\n';                    // True if array has No elements
     cout << A.front() << " " << A.back() << '\n'; // gives First & Last element

     // Vector : variable sized arrays
     vector<string> foods = {"Oats", "Eggs", "Lassi", "Chicken", "Milk"};
     for (string food : foods) // for-each loop
          cout << food << "\t";

     cout << '\n'
          << foods[1] << "\t" << foods[3] << "\n\n"; // access elements by Index
     cout << foods.at(2) << '\n';                    // safer access for out of Bounds

     foods.at(2) = "Paneer"; // overwriting values
     cout << foods.at(2) << "\n\n";

     cout << foods.front() << "\t" << foods.back() << "\n\n"; // gives First & Last element

     foods.push_back("Peanuts"); // add element at end
     foods.push_back("Banana");
     for (string food : foods)
          cout << food << "\t";
     cout << '\n';

     foods.pop_back(); // removes element at end
     for (string food : foods)
     {
          cout << food << "\t";
     }
     cout << "\n\n";

     vector<int> nums(4, 0);
     cout << nums.capacity() << "\t" // max elements can be stored
          << nums.size() << "\t"     // no. of elements present
          << nums.empty() << '\n';   // True if has No elements

     nums.clear(); // removes all elements
     cout << nums.capacity() << "\t" << nums.size() << "\n\n";

     // vector<int>::iterator it = foods.begin();
     auto it = foods.begin(); // Iterator to first element
     cout << *it << "\t";     // dereferencing iterator for value
     it = foods.begin() + 1;  // to second element
     cout << *it << "\t";
     it = foods.end() - 1; // to last element
     cout << *it << "\n\n";
     for (it = foods.begin(); it != foods.end(); it++)
     {
          if (*it == "Chicken")
          {
               foods.erase(it); // removes the element
               break;
          }
     }

     for (it = foods.begin(); it != foods.end(); it++) // for-loop using iterator
     {
          cout << *it << "\t";
     }
     cout << "\n\n";

     vector<string> shapes = {"Triangle", "Square", "Pentagon", "Hexagon", "Circle"};
     for (auto it1 = shapes.rbegin(); it1 != shapes.rend(); it1++) // reverse iterator for-loop
     {
          cout << *it1 << "\t";
     }
     cout << "\n\n";

     return 0;
}