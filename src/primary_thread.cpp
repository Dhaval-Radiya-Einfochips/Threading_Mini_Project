#include "primary_thread.h"
#include <signal.h>

bool exitInterrupt = false;

void sigHandler(int)
{
    exitInterrupt = true;
}

primary_thread::primary_thread () {
	thread primary_th(&primary_thread::init_resource, this);

	primary_th.join();
}

primary_thread::~primary_thread () {
	// Free the Data region pointers
	delete Data_region_1;
	delete Data_region_2;
	delete Data_region_3;
	delete Data_region_4;
}

void primary_thread::init_resource () {

	// Created Data Regions
	Data_region_1 = new vector<uint64_t>;
	Data_region_2 = new vector<uint64_t>;
	Data_region_3 = new vector<uint64_t>;
	Data_region_4 = new vector<uint64_t>;

	// Create objects for Worker thread with Data region pointers and Start value
	worker_thread w1(Data_region_1, 100, 10);
	worker_thread w2(Data_region_2, 300, 20);
	worker_thread w3(Data_region_3, 400, 30);
	worker_thread w4(Data_region_4, 500, 40);

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
	cout << "W1 Thread ID : " << w1.get_thread_id() << " Success : " << w1.get_success() << " Failed : " << w1.get_failed() << endl;
	cout << "W2 Thread ID : " << w2.get_thread_id() << " Success : " << w2.get_success() << " Failed : " << w2.get_failed() << endl;
	cout << "W3 Thread ID : " << w3.get_thread_id() << " Success : " << w3.get_success() << " Failed : " << w3.get_failed() << endl;
    	cout << "W4 Thread ID : " << w4.get_thread_id() << " Success : " << w4.get_success() << " Failed : " << w4.get_failed() << endl;
}

TEST(Sanity) {
        vector<uint64_t> *Data_region_1 = new vector<uint64_t>;
        vector<uint64_t> *Data_region_2 = new vector<uint64_t>;
        vector<uint64_t> *Data_region_3 = new vector<uint64_t>;
        vector<uint64_t> *Data_region_4 = new vector<uint64_t>;

        // Create objects for Worker thread with Data region pointers and Start value
        worker_thread w1(Data_region_1, 100, 10);
	worker_thread w2(Data_region_2, 300, 20);
        worker_thread w3(Data_region_3, 400, 30);
        worker_thread w4(Data_region_4, 500, 40);

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

        this_thread::sleep_for(chrono::seconds(1));

        CHECK_EQUAL(115, w1.get_success());
        CHECK_EQUAL(0, w1.get_failed());

        CHECK_EQUAL(115, w2.get_success());
        CHECK_EQUAL(0, w2.get_failed());

        CHECK_EQUAL(115, w3.get_success());
	CHECK_EQUAL(0, w3.get_failed());

        CHECK_EQUAL(115, w4.get_success());
        CHECK_EQUAL(0, w4.get_failed());

	delete Data_region_1;
        delete Data_region_2;
        delete Data_region_3;
        delete Data_region_4;
}
