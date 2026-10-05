#include <bits/stdc++.h>
using namespace std;

// Class
class Employee
{
private: // defualt - can't access outside class
    int income;

public:
    void setIncome(int i) // Setter
    {
        income = i;
    }

    int getIncome() // Getter
    {
        return income;
    }
};

class car
{
public: // can access anywhere
    string name;

    void specs(int tspeed) // Method - inside class
    {
        cout << "The car of " << name << " company has a Top speed of " << tspeed << " km/h.\n";
    }

    void wmodel(string model);
};
void car::wmodel(string model) // Method - outside class
{
    cout << "The Best car model of this company is " << model << "!\n\n";
}

class Box
{
public:
    int length;
    int breadth;

    Box(){cout << "Constructor called!"} // Default Constructor

    Box(int l, int b) : length(l), breadth(b) // Parameterized Constructor - initialize values
    {
    }

    Box(Box &other) // Custom Copy Constructor - Deep Copy (Actual Copy)
    {
        length = other.length;
        breadth = other.breadth;
    }

    void pdim()
    {
        cout << "Length = " << length << " Breadth = " << breadth << "\n";
    }
};

class Game
{
    string name;
    int year;
    string company;

public:
    static int usedtime; // Static variable
    static void getut()
    {
        cout << usedtime << '\n\n';
        ;
    }

    Game(string x, int y, string z) // Constructor with other codes
    {
        name = x;
        year = y;
        company = z;
        cout << name << " was released by " << company << " (" << year << ").";
    }

    ~Game() // Destructor - for Static allocation
    {
        cout << "Destructor called and ended!\n\n";
    }
};

int Game::usedtime = 10; // don't need an object to use

int main()
{
    // Object
    Employee p1;
    p1.setIncome(85000);
    Employee p2;
    p2.setIncome(80000);
    cout << "The salary of Pranaw Prakash: " << p1.getIncome() << endl
         << "The salary of Harsh Gupta: " << p2.getIncome() << "\n\n";

    // Static
    car motor1;
    motor1.name = "Koenigsegg"; // initialize class variables
    motor1.specs(330);
    motor1.wmodel("Koenigsegg Jesko Absolut");
    // Dynamic
    car *motor2 = new car;
    (*motor2).name = "BMW";
    (*motor2).specs(250);
    motor2->wmodel("BMW M5 Competition");
    delete motor2; // manual destructor

    Box b0;
    Box b1(10, 20);
    b1.pdim();
    // Box b2(b1); // Default Copy constructor - Shallow Copy (By Memory Address)
    // b2.pdim();
    // b1.breadth = 25;
    // b1.pdim();
    // b2.pdim();
    Box b2(b1);
    b2.pdim();
    b1.breadth = 25; // changing value of orignal object
    b1.pdim();
    b2.pdim();
    b1 = b2; // Copy Assigment Operator on Objects (of Same Class)
    b1.pdim();
    b2.pdim();

    Game fun1("IGI", 2000, "InnerLoop Studios");
    Game fun2("COD", 2003, "Acitvision");
    Game fun3("GTA SA", 2004, "Rockstar Games");
    Game fun4("AC", 2007, "Ubisoft Montreal");
    cout << Game::usedtime << '\n'; // access directly from class
    Game::getut();

    return 0;
}