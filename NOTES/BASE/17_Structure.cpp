#include <iostream>
#include <string>
using namespace std;

struct S // group different data types
{
    int nums2;    // Both members
    string words; // have different memory space
};

struct Rich
{
    string name;
    int age;
    string networth;
};

struct Num
{
private:
    int p, q;

public:               // default
    Num(int a, int b) // Constructor
    {
        p = a;
        q = b;
    }

    void printsum() // Member Function
    {
        cout << p << "+" << q << " = " << p + q << "\n\n";
    }

    ~Num() // Destructor
    {
        cout << "\nDestroyed Num vars using Destructor!\n";
    }
};

struct Outer
{
    struct Inner // Nested Structure
    {
        int i1, i2;
    } in;
    int o1, o2;
};

struct Spointer
{
    int i3;
    void print()
    {
        cout << i3 << "\n\n";
    }
};

struct node // Self-Referential Structure
{
    int data;
    struct node *prev;
    struct node *next;
};

union U // group different data types
{
    int i;  // Both members
    char c; // share same memory space
};

int main()
{

    S myStruct = {7, "Scorch"}; // Structure variable
    cout << myStruct.nums2 << "\t" << myStruct.words << "\n\n";

    Rich rich1 = {"Anshuman Srivastava", 22, "$11.2 Million"};
    Rich rich2 = {"Ashitabh Srivastava", 25, "$11.1 Million"};
    cout << "The Year 2030 :\n"
         << rich1.name << "\t" << rich1.age << "\t" << rich1.networth << endl
         << rich2.name << "\t" << rich2.age << "\t" << rich2.networth << "\n\n";

    rich1.age = 32; // modifying member values
    rich2.age = 35;
    rich1.networth = "$51.2 Million";
    rich2.networth = "$51.1 Million";
    cout << "The Year 2040: \n"
         << rich1.name << "\t" << rich1.age << "\t" << rich1.networth << endl
         << rich2.name << "\t" << rich2.age << "\t" << rich2.networth << "\n\n";

    Num n1(5, 2);
    n1.printsum();

    cout << sizeof(S) << "\t" << sizeof(Rich) << "\n\n";

    Outer obj = {{0, 1}, 6, 7};
    cout << "Inner: " << obj.in.i1 << " " << obj.in.i2 << endl
         << "Outer: " << obj.o1 << " " << obj.o2 << "\n\n";

    Spointer obj1 = {21};
    Spointer *sptr = &obj1; // Structure Pointer

    sptr->print(); // accessing the structure pointer

    node box1;
    box1.data = 10;
    box1.prev = NULL;
    box1.next = NULL;

    node box2;
    box2.data = 20;
    box2.prev = NULL;
    box2.next = NULL;

    node box3;
    box3.data = 30;
    box3.prev = NULL;
    box3.next = NULL;

    box1.next = &box2; // Forward Linking
    box2.next = &box3;

    box2.prev = &box1; // Backward Linking
    box3.prev = &box2;

    cout << box1.data << " " << box1.next->data << " " << box1.next->next->data << endl;
    cout << box2.data << " " << box2.next->data << " " << box2.prev->data << endl;

    U myUnion; // Union variable
    myUnion.i = 21;
    myUnion.c = 'A';

    cout << "myUnion.i: " << myUnion.i << endl
         << "myUnion.c: " << myUnion.c << "\n\n";

    return 0;
}