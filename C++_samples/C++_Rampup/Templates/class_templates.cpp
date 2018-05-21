#include <iostream>

using namespace std;

template <class T>
class mypair {
	T a, b;

	public:
		mypair (T first, T second) {
			a = first; 
			b = second;
			cout << "A : " << a << " B : " << b << endl;
		}

	T getmax ();
};

template <class T>
T mypair<T>::getmax () {
	T retval;
	retval = a > b ? a : b;
	return retval;
}

int main () {
	mypair <int> myobject (100, 75);
	cout << "Max int is : " << myobject.getmax() << endl;
	
	mypair <float> myobject1 (10.03, 10.02);
	cout << "Max float is : " << myobject1.getmax() << endl;

	return 0;
}
