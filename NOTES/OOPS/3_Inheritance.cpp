#include <bits/stdc++.h>
using namespace std;

class Vehicle // Base / Super / Parent class
{
public: // can be Inherited
	Vehicle()
	{
		cout << "This is a Vehicle!" << endl;
	}

private: // can't be Inherited
	int qwe = 12;

protected: // only derived classes can access
	string name;
};
// Single Inheritance
// 1st Child class
class car : public Vehicle // Derived / Sub / Child class
{
public:
	car()
	{
		name = "BMW";
		cout << "This is a " << name << " car!" << "\n\n";
	}
};
// Hierarchical Inheritance
// 2nd Child class
class bike : public Vehicle // public Mode of Inheritance - data members remain same
{
public:
	bike()
	{
		name = "Kawasaki";
		cout << "This is a " << name << " bike!" << "\n\n";
	}
};

class Parent1
{
public:
	string name1;
	Parent1(string s1) : name1(s1) {}
	string role1 = "Husband!";

protected:
	void status1()
	{
		cout << name1 << " is now the " << role1 << endl;
	}
};
class Parent2
{
public:
	string name2;
	Parent2(string s2) : name2(s2) {}
	string role2 = "Wife!";

protected:
	void status2()
	{
		cout << name2 << " is now the " << role2 << endl;
	}
};
// Multiple Inheritance
// derived child class from 2 Parent classes
class child : protected Parent1, protected Parent2 // protected Mode of Inheritance - data members become protected
{
public:
	string name3;
	child(string s3, string s1, string s2) : Parent1(s1), Parent2(s2)
	{
		name3 = s3;
	}
	string role3 = "Daughter!";

	void usestatus1()
	{
		status1();
		status2();
		cout << '\n';
	}
	void status3()
	{
		cout << name3 << " is now the " << role3 << endl;
	}
	void newstatus1()
	{
		role1 = "Father!";
		role2 = "Mother!";
		usestatus1();
	}
};
// Multi-level Inheritance
// derived from the Child class itself
class grandchild : private child // private Mode of Inheritance - data members become private
{
public:
	string name4;
	grandchild(string s4, string s3, string s1, string s2) : child(s3, s1, s2)
	{
		name4 = s4;
	}
	string role4 = "Grand Son!";

	void usestatus2()
	{
		status3();
		status1();
		status2();
		cout << '\n';
	}
	void status4()
	{
		cout << name4 << " is now the " << role4 << endl;
	}
	void newstatus2()
	{
		role1 = "Grandpa!";
		role2 = "Grandma!";
		role3 = "Mother!";
		usestatus2();
	}
};

// Hybrid Inheritance - Combination of types of Inheritance

// Ambiguity in Inheritance
class A
{
public:
	void fun() // same name..
	{
		cout << "I am made of A!\n\n";
	}
};

class B
{
public:
	void fun() // ..confuses the compiler..
	{
		cout << "I am made of B!\n\n";
	}
};

class C : public A, public B // ..if inherited together!
{
public:
};

int main()
{
	car bmw;

	bike kws;

	child p1("Lisa", "Ash", "Marry");
	p1.usestatus1();
	p1.status3();
	p1.newstatus1();

	grandchild p2("Jake", "Lisa", "Ash", "Marry");
	p2.status4();
	p2.newstatus2();

	C obj;
	// Ambigious
	// obj1.fun();
	// Using Scope Resolution operator
	obj.A::fun();
	obj.B::fun();

	return 0;
}