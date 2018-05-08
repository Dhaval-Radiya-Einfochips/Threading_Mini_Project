#include <iostream>
#include <thread>
#include <vector>

using namespace std;

// Maximum Data Region size
#define DATA_REGION_SIZE 115

// Declare callback function using function pointer
typedef void(*CallbackFunctionPtr)(void *, vector<uint64_t> *th, int value, void *thp);

class worker_thread {
	public: 
		// Constructor
		worker_thread (vector<uint64_t> *th, int x) {
			Data = th;
			start_value = x;
		}

		// Destructor
		~worker_thread () {
		}

		// Static Callback function
		static void staticCallbackFunction(void *p, vector<uint64_t> *th, int svalue, void *thp) {
			((worker_thread *)p) -> verify(th, svalue, (worker_thread *) thp);
		}

		// Registring callback function
		void registerCallback(CallbackFunctionPtr cb, void *p) {
			m_cb = cb;
        		m_p = p;
		}

		// Write data into Data Region using thread
		void add_data () {
			int data_value = start_value;

			for (int x = 0; x < DATA_REGION_SIZE; x++) {	
				Data->push_back(data_value);
				cout << "Thread ID : " << thread_id << " Data write : " << data_value << endl;
				data_value++;
			}
			m_cb(m_p, Data, start_value, this);
		}

		// Verfy Data in Data Region using Callback Function
		void verify (vector<uint64_t> *lData, int s_value, worker_thread *thp) {
			int data_value = s_value;
			int success = 0, failure = 0;

			for (int x = 0; x < lData->size(); x++) {
				if (lData->at(x) == data_value) 
					success++;
				else
					failure++;
				
				data_value++;
			}

			thp->set_success(success);
			thp->set_failed(failure);
		}

		// Creating thread and get ID for each thread
		void create_thread() {
			thread worker_th(&worker_thread :: add_data, this);
			
			thread_id = std::this_thread::get_id();
			
			worker_th.detach();
		}

		// Get success count
		int get_success () {
			return success_count;
		}

		// Get failed count
		int get_failed () {
			return failure_count;
		}

		// Set success count
		void set_success (int success) {
			success_count = success;
		}

		// Set failed count
		void set_failed (int failure) {
			failure_count = failure;
		}
		
		// Local pointer for data region access
		vector<uint64_t> *Data;
		
		int start_value = 0, success_count = 0, failure_count = 0;

		CallbackFunctionPtr m_cb;
		void *m_p;

		std::thread::id thread_id;
};
