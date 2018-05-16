#include <iostream>
#include <functional>
#include <assert.h>

using namespace std;
using namespace std::placeholders;

class placeholder1 {
	public :
		placeholder1(int value) : m_value(value) {}

		int default_mul(int i) {
			return i*5;
		}

		int get_value() {
			return 1;
		}

		int get_double_value(const placeholder1 & p1) {
			return p1.m_value + m_value;
  		}

	private :
		int m_value;
};

int default_sum(int i) {
	return i+5;
}

int get_value() {
  	return 5;
}

int main () {

	std::function<int (int)> a = std::bind(default_sum, _1);
	std::function<int ()> b = std::bind(get_value);

	assert((a(10) + b()) == 20);
	std::cout << "Actual func value get : " << a(10) + b() << endl;

	placeholder1 p1(2);

	std::function<int (int)> c = std::bind(&placeholder1::default_mul, p1, _1);
	std::function<int ()> d = std::bind(&placeholder1::get_value, p1);

	assert((c(1) + d()) == 6);
	std::cout << "Actual Class func value get : " << c(1) + d() << endl;

	placeholder1 p2(3);
	std::function<int (int)> e = std::bind(&placeholder1::default_mul, p1, _1);
	std::function<int ()> f = std::bind(&placeholder1::get_double_value, std::ref(p1), std::cref(p2));

	assert((e(1) + f()) == 10);
	std::cout << "Actual Class func value double get : " << e(1) + f() << endl;
}
