#include <bits/stdc++.h>
using namespace std;

// https://www.hackerrank.com/challenges/rectangle-area/problem?isFullScreen=true

class Rectangle
{
public:
  int width;
  int height;

  void read_input()
  {
    cin >> width >> height;
  }

  void display()
  {
    cout << width << " " << height << endl;
  }
};

class RectangleArea : public Rectangle
{
public:
  void display()
  {
    cout << width * height;
  }
};

int main()
{
  RectangleArea rect;
  rect.read_input();
  rect.Rectangle::display();
  rect.display();
  return 0;
}
