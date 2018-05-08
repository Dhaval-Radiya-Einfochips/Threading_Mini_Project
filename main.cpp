#include <iostream>
#include <thread>
#include <vector>
#include <signal.h>

#include "worker_thread.h"
#include "UnitTest++/UnitTest++.h"

using namespace std;

bool exitInterrupt = false;

void sigHandler(int)
{
    exitInterrupt = true;
}

// UnitTest++ Test Cases
TEST(Sanity) {
	vector<uint64_t> *Data_region_1 = new vector<uint64_t>;
	vector<uint64_t> *Data_region_2 = new vector<uint64_t>;
	vector<uint64_t> *Data_region_3 = new vector<uint64_t>;
	vector<uint64_t> *Data_region_4 = new vector<uint64_t>;

	worker_thread Test1(Data_region_1, 100);
	worker_thread Test2(Data_region_2, 300);
	worker_thread Test3(Data_region_3, 400);
	worker_thread Test4(Data_region_4, 500);
	
	Test1.registerCallback(worker_thread::staticCallbackFunction, &Test2);
	Test2.registerCallback(worker_thread::staticCallbackFunction, &Test3);
	Test3.registerCallback(worker_thread::staticCallbackFunction, &Test4);
	Test4.registerCallback(worker_thread::staticCallbackFunction, &Test1);

	Test1.create_thread();
	Test2.create_thread();
	Test3.create_thread();
	Test4.create_thread();

	this_thread::sleep_for(chrono::seconds(1));

	CHECK_EQUAL(115, Test1.get_success());
	CHECK_EQUAL(0, Test1.get_failed());

	CHECK_EQUAL(115, Test2.get_success());
	CHECK_EQUAL(0, Test2.get_failed());

	CHECK_EQUAL(115, Test3.get_success());
	CHECK_EQUAL(0, Test3.get_failed());

	CHECK_EQUAL(115, Test4.get_success());
	CHECK_EQUAL(0, Test4.get_failed());
}

int main() {

	// Created Data Regions
	vector<uint64_t> *Data_region_1 = new vector<uint64_t>;
	vector<uint64_t> *Data_region_2 = new vector<uint64_t>;
	vector<uint64_t> *Data_region_3 = new vector<uint64_t>;
	vector<uint64_t> *Data_region_4 = new vector<uint64_t>;

	// Create objects for Worker thread with Data region pointers and Start value
	worker_thread w1(Data_region_1, 100);
	worker_thread w2(Data_region_2, 300);
	worker_thread w3(Data_region_3, 400);
	worker_thread w4(Data_region_4, 500);

	// Register Callback for Each worker thread using Function pointer
	w1.registerCallback(worker_thread::staticCallbackFunction, &w2);
	w2.registerCallback(worker_thread::staticCallbackFunction, &w3);
	w3.registerCallback(worker_thread::staticCallbackFunction, &w4);
	w4.registerCallback(worker_thread::staticCallbackFunction, &w1);

	// Creating threads and write data
	w1.create_thread();
	w2.create_thread();
	w3.create_thread();
	w4.create_thread();

	// Signal Handlers for abort/terminate/stop the application
    	signal(SIGTSTP,sigHandler);
    	signal(SIGABRT,sigHandler);
    	signal(SIGTERM,sigHandler);
    	signal(SIGINT, sigHandler);
    
	while (1) {
        	if(true == exitInterrupt) {
            		break;
        	}
	}

	// Shows the Success/Failure count for each worker thread
	cout << "W1 Thread ID : " << w1.thread_id << " Success : " << w1.get_success() << " Failed : " << w1.get_failed() << endl;
	cout << "W2 Thread ID : " << w2.thread_id << " Success : " << w2.get_success() << " Failed : " << w2.get_failed() << endl;
	cout << "W3 Thread ID : " << w3.thread_id << " Success : " << w3.get_success() << " Failed : " << w3.get_failed() << endl;
	cout << "W4 Thread ID : " << w4.thread_id << " Success : " << w4.get_success() << " Failed : " << w4.get_failed() << endl;

	// Free the Data region pointers
	delete Data_region_1;
	delete Data_region_2;
	delete Data_region_3;
	delete Data_region_4;
	
	// Run test cases
	return UnitTest::RunAllTests();
}
