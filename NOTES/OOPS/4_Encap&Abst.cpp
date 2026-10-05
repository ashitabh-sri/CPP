#include <bits/stdc++.h>
using namespace std;

// Encapsulation - grouping relevant data together
class Employee // Fully Encapsulated class - all data members are private
{
private:
    string nam;
    int age;
    float pkg;
public:
    Employee(string n, int a, float p) : nam(n), age(a), pkg(p) {}

    void show(){
        cout << nam << ": Age = " << age << " | Package = " << pkg << "!\n\n";
    }
};

// Abstraction - hide implementation details
class Car
{
private:
    int dis = 40, pet = 10;
    int mil = dis / pet;

public:
    void mileage()
    {
        cout << "The Mileage of car is: " << mil << " kmpl!" << endl;
    }
};

int main()
{
    Employee ashi("Ashitabh Srivastava", 21, 20.5);
    ashi.show();

    Car bugatti;
    bugatti.mileage();

    cout << "\n\n\tTHE END OF C++ !";

    return 0;
}