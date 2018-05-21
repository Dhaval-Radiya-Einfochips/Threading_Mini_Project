#include <iostream>
#include <vector>

using namespace std;

int main () {

    size_t size = 1;
    int sarray[size];
    int *darray = new int[size];
    
    for(int i=0; i<size; ++i) {
        sarray[i] = i;
	cout << "Sarray = " << sarray[i] << endl;

        darray[i] = i;
	cout << "Darray = " << darray[i] << endl;
    }
    // don't forget to delete darray when you're done
    delete [] darray;

    std::vector<int> array(size);

    for(int i=0; i<size; ++i){
	array[i] = i;
	cout << "Vector Array = " << array[i] << endl;
    }

    std::vector<char> Carray;
    Carray.reserve(4);   

    char d = 0;

    while(d != 'x') {
  	cin >> d;
  	Carray.push_back(d);
    }

    for(int i=0; i<Carray.capacity(); ++i) {
	cout << "Darray = " << Carray[i] << endl;
    }

    cout<< "Darray Capacity = " << Carray.capacity() << endl;

    std::vector<int> rray;

    try {
    	rray.at(1000) = 0;
    }
   
    catch(std::out_of_range o) {
    	std::cout<<o.what()<<std::endl;
    }

    return 0;
}
