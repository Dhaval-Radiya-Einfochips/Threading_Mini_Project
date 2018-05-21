#include <iostream>

using namespace std;

template <class T, int N>
class mysequence {
	T memblock [N];

	public:
		void setmember (int x, T value);
    		T getmember (int x);
};

template <class T, int N>
void mysequence<T, N>::setmember (int x, T value) {
	memblock[x] = value;
}

template <class T, int N>
T mysequence<T, N>::getmember (int x) {
	return memblock[x];
}

int main () {
	mysequence <int, 5> myints;
	
	mysequence <double, 5> myfloats;
	
	mysequence <char, 2> mystrings;

	myints.setmember (0,10);

	myfloats.setmember (3,3.416);
	
	mystrings.setmember (2,'D');

	cout << "Get Integer number : " << myints.getmember(0) << endl;

	cout << "Get Float number : " << myfloats.getmember(3) << endl;
	
	cout << "Get Strings : " << mystrings.getmember(2) << endl;

	return 0;
}
