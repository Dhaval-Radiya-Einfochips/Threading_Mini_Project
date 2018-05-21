#include <iostream>

using namespace std;

template <class T, class F>
F GetMax (T a, F b) {
	return ((a > b) ? a : b);
}

template <class T>
T GetMax (T a, T b) {
	return ((a > b) ? a : b);
}

int main () {
	int i = 5, j = 6.5, max_int;

	long l = 10.9, m = 5, max_long;
	
	float a = 10, b = 2, max_float;

	int o = 9; float p = 10.50;

	//max_int = GetMax<int>(i,j);
	max_int = GetMax(i,j);
	cout << "Maximux int is : " << max_int << endl;

	//max_long = GetMax<long>(l,m);
	max_long = GetMax(l,m);
	cout << "Maximum long is : " << max_long << endl;

	//max_float = GetMax<float>(a,b);
	max_float = GetMax(a,b);
	cout << "Maximum float is : " << max_float << endl;
	
	cout << "Maximum int-float is : " << GetMax<int, float>(o,p) << endl;
	
	cout << "Maximum int-float is : " << GetMax(o,p) << endl;

	return 0;
}
