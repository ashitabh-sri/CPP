#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

int main()
{
     // Map : stores unique Key/Value pairs
     unordered_map<int, string> suspect0 = {{101, "Unknown"}, {213, "Ashitabh Srivastava"}, {804, "Pranaw Prakash"}, {102, "Deceased"}}; // TC = O(1)
     for (auto sus : suspect0)
     {
          cout << "Suspect " << sus.first // access key
               << ": " << sus.second      // access value
               << '\n';
     }
     cout << '\n';

     // map: data type of key = int, double, pair<int, int>
     // unordered_map - int, double, string

     map<int, string> suspect = {{101, "Unknown"}, {213, "Ashitabh Srivastava"}, {804, "Pranaw Prakash"}, {102, "Deceased"}}; // Sorted in Ascending order as per key by default
     cout << "Suspect 213: " << suspect[101] << '\n';      // accessing value - by key
     cout << "Sespect 084: " << suspect.at(102) << "\n\n"; // safer access for out of bounds

     suspect[410] = "Anshuman Srivastava"; // add element by key
     suspect.insert({811, "Harsh Gupta"}); // add element as unit

     suspect.erase(101); // remove element by key
     suspect.erase(102);
     for (auto sus : suspect)
     {
          cout << "Suspect " << sus.first << ": " << sus.second << '\n';
     }
     cout << '\n';

     cout << suspect.size() << '\t';
     suspect.clear();
     cout << suspect.empty() << '\n';
     cout << suspect.count(103) << "\n\n"; // check existence of value by key

     map<int, string, greater<int>> suspect1 = {{101, "Unknown"}, {213, "Ashitabh Srivastava"}, {103, "Nobody"}}; // to sort in Descending order as per key
     for (auto sus : suspect1)
     {
          cout << "Suspect " << sus.first << ": " << sus.second << '\n';
     }
     cout << '\n';

     auto it = suspect1.find(103);
     for(auto i = it; i != suspect1.end(); i++){
          cout << (*i).first << '\n';
     }
     cout << '\n';

     // Multi-map - can store duplicate key values
     multimap<int, int, greater<int>> score = {{4, 1}, {3, 2}, {3, 3}, {5, 4}};
     for (auto &it : score)
     {
          cout << it.first << " " << it.second;
     }
     cout << "\n\n";

     return 0;
}