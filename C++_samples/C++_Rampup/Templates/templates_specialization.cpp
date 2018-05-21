#include <iostream>

using namespace std;

// class template:
template <class T>
class mycontainer {
	T element;

	public:
		mycontainer (T arg) {
			element = arg;
			cout << "Element is : " << element << endl;
		}
		
		T increase () {
			return ++element;
		}
};

// class template specialization:
template <>
class mycontainer <char> {
	char element;
	public:
		mycontainer (char arg) {
			element = arg;
			cout << "Element is : " << element << endl;
		}
	
		char uppercase () {
			if ((element >= 'a') && (element <= 'z')) {
      				element += 'A' - 'a';
			}
      			return element;
    		}
};

int main () {
	mycontainer<int> myint (5);

	cout << "Integer Increase : " << myint.increase() << endl;
	
	mycontainer<char> mychar ('d');
	
	cout << "Character Increase : " << mychar.uppercase() << endl;

	return 0;
}
