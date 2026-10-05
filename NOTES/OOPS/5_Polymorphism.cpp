#include <bits/stdc++.h>
using namespace std;

// Static Polymorphism (Compile-time)
class Function
{
public:
    void sum(int a, int b)
    {
        cout << "Integer Sum: " << a + b << endl;
    }
    void sum(double a, double b) // Method Overloading
    {
        cout << "Float Sum: " << a + b << "\n\n";
    }
};
class Complex
{
public:
    int real, img;
    Complex(int r, int i)
    {
        real = r;
        img = i;
    }

    // Operator Overloading
    Complex operator+(const Complex &num)
    {
        return Complex(real + num.real, img + num.img);
    }

    void operator-(Complex &num1)
    {
        cout << "Subtraction of two Complex Nums: " << real - num1.real << " + i" << img - num1.img << "\n\n";
    }

    // Operators can't be overloaded - ::, .*, ., ?:
};

// Dynamic Polymorphism (Run-time)
class Animal
{
public:
    virtual void sound() // function to be redefined in derived class
    {
        cout << "Animal Sound!\n";
    }
    virtual ~Animal() {}
};

class Dog : public Animal // usess on Inheritance
{
public:
    void sound() override // Method Overriding
    {
        cout << "woof woof!\n";
    }
};

class Cat : public Animal
{
public:
    void sound() override
    {
        cout << "meow meow!\n";
    }
};

class Lion : public Animal
{
public:
    void sound() override
    {
        cout << "rooaaaarrr!\n\n";
    }
};

int main()
{
    Function obj;
    obj.sum(4, 6);
    obj.sum(42.65, 45.21);

    Complex c1(12, 5);
    Complex c2(7, 2);
    Complex c3 = c1 + c2;   
    cout << "Sum of Two Complex Nums: " << c3.real << " + i" << c3.img << "\n\n";
    c1 - c2;

    Animal myanimal;
    Dog gshepherd;
    Cat beluga;
    Lion sherkhan;
    myanimal.sound();
    gshepherd.sound();
    beluga.sound();
    sherkhan.sound();

    // Typecasting
    Animal *animalPtr = new Dog();                // Base class pointer to derived class
    Dog *dogPtr = dynamic_cast<Dog *>(animalPtr); // Downcasting - Base class pointer to Derived class pointer
    if (dogPtr)                                   // check typecasting
    {
        dogPtr->sound();
    }
    else
    {
        cout << "Failed to cast to Dog." << endl;
    }
    Cat *catPtr = dynamic_cast<Cat *>(animalPtr); // 
    if (catPtr)
    {
        catPtr->sound();
    }
    else
    {
        cout << "Failed to cast to Cat." << endl;
    }
    delete animalPtr;

    return 0;
}