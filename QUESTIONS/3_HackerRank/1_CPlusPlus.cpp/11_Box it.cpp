#include <bits/stdc++.h>
using namespace std;

// https://www.hackerrank.com/challenges/box-it/problem?isFullScreen=true

class Box
{
private:
    int l;
    int b;
    int h;

public:
    Box()
    {
        l = b = h = 0;
    }

    Box(int x, int y, int z)
    {
        l = x;
        b = y;
        h = z;
    }

    Box(const Box &other)
    { // Copy Constructor
        l = other.l;
        b = other.b;
        h = other.h;
    }

    int getLength()
    {
        return l;
    }

    int getBreadth()
    {
        return b;
    }

    int getHeight()
    {
        return h;
    }

    long long CalculateVolume()
    {
        long vol = static_cast<long long>(l * b * h);
        return vol;
    }

    bool operator<(const Box &other) const
    { // Overload the < operator
        // Compare this box with another box
        if (l < other.l)
            return true;
        else if (l == other.l && b < other.b)
            return true;
        else if (l == other.l && b == other.b && h < other.h)
            return true;
        else
            return false;
    }

    friend ostream &operator<<(ostream &out, const Box &B)
    { // Friend function to overload <<
        out << B.l << " " << B.b << " " << B.h;
        return out;
    }
};

int main()
{
    Box b1;          // Default box: 0 0 0
    Box b2(2, 3, 4); // Box with dimensions 2 3 4
    Box b3(b2);      // Copy of b2

    cout << b2.getLength() << " " << b2.getBreadth() << " " << b2.getHeight() << endl; // 2 3 4
    cout << b2.CalculateVolume() << endl;                                              // 24

    if (b1 < b2)
        cout << "b1 is smaller" << endl;

    cout << b2 << endl; // prints: 2 3 4

    return 0;
}

// Incomplete Explanation of Question..Direct Solution below
// #include<bits/stdc++.h>

// using namespace std;
// class Box {
// private:
//     int length, breadth, height;

// public:
//     // Constructors
//     Box() : length(0), breadth(0), height(0) {}
//     Box(int l, int b, int h) : length(l), breadth(b), height(h) {}
//     Box(const Box& box) : length(box.length), breadth(box.breadth), height(box.height) {}

//     // Getter functions
//     int getLength() { return length; }
//     int getBreadth() { return breadth; }
//     int getHeight() { return height; }

//     // Calculate volume
//     long long CalculateVolume() { return static_cast<long long>(length) * breadth * height; }

//     // Operator overloading <
//     bool operator<(const Box& b) {
//         if (length < b.length)
//             return true;
//         else if (length == b.length && breadth < b.breadth)
//             return true;
//         else if (length == b.length && breadth == b.breadth && height < b.height)
//             return true;
//         else
//             return false;
//     }

//     // Operator overloading <<
//     friend ostream& operator<<(ostream& out, const Box& B) {
//         out << B.length << " " << B.breadth << " " << B.height;
//         return out;
//     }
// };

// void check2()
// {
// 	int n;
// 	cin>>n;
// 	Box temp;
// 	for(int i=0;i<n;i++)
// 	{
// 		int type;
// 		cin>>type;
// 		if(type ==1)
// 		{
// 			cout<<temp<<endl;
// 		}
// 		if(type == 2)
// 		{
// 			int l,b,h;
// 			cin>>l>>b>>h;
// 			Box NewBox(l,b,h);
// 			temp=NewBox;
// 			cout<<temp<<endl;
// 		}
// 		if(type==3)
// 		{
// 			int l,b,h;
// 			cin>>l>>b>>h;
// 			Box NewBox(l,b,h);
// 			if(NewBox<temp)
// 			{
// 				cout<<"Lesser\n";
// 			}
// 			else
// 			{
// 				cout<<"Greater\n";
// 			}
// 		}
// 		if(type==4)
// 		{
// 			cout<<temp.CalculateVolume()<<endl;
// 		}
// 		if(type==5)
// 		{
// 			Box NewBox(temp);
// 			cout<<NewBox<<endl;
// 		}

// 	}
// }

// int main()
// {
// 	check2();
// }