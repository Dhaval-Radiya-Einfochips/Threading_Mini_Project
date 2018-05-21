#include <iostream>

using namespace std;

class Foo {
	public:
    		Foo () : _x( 3 ) {}
    
		void func () {
        		// a very silly, but illustrative way of printing out the value of _x
        		[this] () { cout << _x << endl; } ();
    		}

	private:
        	int _x;
};

int main()
{
    Foo f;
    f.func();

    auto lambda = []() { cout << "Code within a lambda expression" << endl; };
    lambda();

    std::cout << [](int a, int b){ return a*b; }(4, 5) << std::endl;

    auto i = [](int a, int b){ return a*b; }(4, 5);
    std::cout << "I : " << i << std::endl;

    std::cout << [](int n){return n+n;} (5) << std::endl;;
}
