#include <iostream>
#include <thread>
#include <vector>

#include "worker_thread.h"

// Constructor
worker_thread::worker_thread (vector<uint64_t> *th, int x, int id) {
	Data = th;
	start_value = x;
	thread_id = id;
}

// Destructor
worker_thread::~worker_thread () {
	if(glb_thread.joinable()) {
		terminate ();
	}
}

// Callback function
void worker_thread::staticCallbackFunction(void *p, vector<uint64_t> *th, int svalue, int id, void *thp) {
	((worker_thread *)p) -> verify(th, svalue, id, (worker_thread *) thp);
}

// Registring callback function
void worker_thread::registerCallback(CallbackFunctionPtr cb, void *p) {
	m_cb = cb;
  	m_p = p;
}

// Write data into Data Region using thread
void worker_thread::add_data () {
	int data_value = start_value;
	int th_id = thread_id;

	for (int x = 0; x < DATA_REGION_SIZE; x++) {	
		Data->push_back(data_value);
		cout << "Thread ID : " << thread_id << " Data write : " << data_value << endl;
		data_value++;
	}
	m_cb(m_p, Data, start_value, th_id, this);
}

// Verfy Data in Data Region using Callback Function
void worker_thread::verify (vector<uint64_t> *lData, int s_value, int id, worker_thread *thp) {
	int data_value = s_value;
	int success = 0, failure = 0;
	int th_id = id;

	for (int x = 0; x < lData->size(); x++) {
		if (lData->at(x) == data_value) 
			success++;
		else
			failure++;

		data_value++;
	}

	thp->set_success(success);
	thp->set_failed(failure);
	thp->set_thread_id(id);
}

// Creating thread and get ID for each thread
void worker_thread::create_thread() {
	glb_thread = thread(&worker_thread :: add_data, this);
	
	glb_thread.detach();
}

// Get success count
int worker_thread::get_success () {
	return success_count;
}

// Get failed count
int worker_thread::get_failed () {
	return failure_count;
}

// Set success count
void worker_thread::set_success (int success) {
	success_count = success;
}

// Set failed count
void worker_thread::set_failed (int failure) {
	failure_count = failure;
}

// Get Thread_id
int worker_thread::get_thread_id () {
	return thread_id;
}

void worker_thread::set_thread_id (int id) {
	thread_id = id;
}
