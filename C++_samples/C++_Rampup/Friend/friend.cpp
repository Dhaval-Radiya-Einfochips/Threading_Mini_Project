// friend functions
#include <iostream>
using namespace std;

class Rectangle {
    int width, height;
  
  public:
    Rectangle() {
    }
    
    Rectangle (int x, int y) : width(x), height(y) {
	cout << "X = "<< x << endl;
	cout << "Y = "<< y << endl;
	cout << "width = "<< width << endl;
	cout << "height = "<< height << endl;
    }
    
    int area() {
	return width * height;
    }
    
    friend Rectangle duplicate (const Rectangle&);
};

Rectangle duplicate (const Rectangle& param)
{
  Rectangle res;
  res.width = param.width*2;
  res.height = param.height*2;

  cout << "res.width = " << res.width << endl;
  cout << "res.height = " << res.height << endl;
  return res;
}

int main () {
  Rectangle foo;
  Rectangle bar (2,3);
  foo = duplicate (bar);
  cout << foo.area() << '\n';
  return 0;
}
