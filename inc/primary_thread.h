#include <iostream>
#include <thread>
#include <vector>

#include "worker_thread.h"
#include "UnitTest++/UnitTest++.h"

using namespace std;

class primary_thread {
	public: 
		// Constructor
		primary_thread ();

		// Destructor
		~primary_thread ();

		// Init Resources for primary thread
		void init_resource();

	private:

		// Data Region pointers
		vector<uint64_t> *Data_region_1;
		vector<uint64_t> *Data_region_2;
		vector<uint64_t> *Data_region_3;
		vector<uint64_t> *Data_region_4;
};
