#include<iostream>
#include<memory>

using namespace std;
 
class auto1 { 
	public:
    		void show() { 
			cout << "Auto1 class show() called" << endl;
		}
};
 
int main() {
	cout << "=================Auto pointer=================" << endl;
    	
	auto_ptr <auto1> p1(new auto1);
    
	p1 -> show();
 
    	cout << p1.get() << endl;
 
    	auto_ptr <auto1> p2(p1);
	
    	p2 -> show();
 
    	cout << p1.get() << endl;
 
    	cout << p2.get() << endl;

	cout << "=================Unique pointer=================" << endl;

	unique_ptr<auto1> ptr1 (new auto1);

	ptr1 -> show();

	cout << ptr1.get() << endl;

	unique_ptr<auto1> ptr2 = move(ptr1);

	ptr2 -> show();

	cout << ptr1.get() << endl;

	cout << ptr2.get() << endl;

	cout << "=================Unique pointer : P3 =================" << endl;

	unique_ptr<auto1> p3 = move(ptr2);
    
	p3->show();
    
	cout << ptr1.get() << endl;
    
	cout << ptr2.get() << endl;
    
	cout << p3.get() << endl;

	cout << "=================Shared pointer=================" << endl;

	shared_ptr<auto1> shared1 (new auto1);

	cout << "Shared pointer 1 address : " << shared1.get() << endl;
    
	cout << "Shared pointer 1 show : " ;
	shared1->show();
    
	shared_ptr<auto1> shared2 (shared1);

	cout << "Shared pointer 2 show : ";
	shared2->show();

	cout << "Shared pointer 1 address : " << shared1.get() << endl;
    
	cout << "Shared pointer 2 address : " << shared2.get() << endl; 
 
	// Returns the number of shared_ptr objects referring to the same managed object.
    
	cout << "Shared pointer 1 use count : " << shared1.use_count() << endl;
    	
	cout << "Shared pointer 2 use_count : " << shared2.use_count() << endl;
 
    	shared1.reset();
    
	cout << "Shared pointer 1 address after reset : " << shared1.get() << endl;
    
	cout << "Shared pointer 1 use count after reset : " << shared1.use_count() << endl;
    
	cout << "Shared pointer 2 address : " << shared2.get() << endl;
	
	cout << "Shared pointer 1 use count : " << shared2.use_count() << endl;
 
    	return 0;
}
