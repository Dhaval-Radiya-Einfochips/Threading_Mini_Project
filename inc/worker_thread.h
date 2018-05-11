#include <iostream>
#include <thread>
#include <vector>

using namespace std;

// Maximum Data Region size
#define DATA_REGION_SIZE 115

// Declare callback function using function pointer
typedef void(*CallbackFunctionPtr)(void *, vector<uint64_t> *th, int value, int id, void *thp);

class worker_thread {
	public: 
		// Constructor
		worker_thread (vector<uint64_t> *th, int x, int id);

		// Destructor
		~worker_thread ();

		// Registring callback function
		void registerCallback(CallbackFunctionPtr cb, void *p);

		// Write data into Data Region using thread
		void add_data ();

		// Verfy Data in Data Region using Callback Function
		void verify (vector<uint64_t> *lData, int s_value, int id, worker_thread *thp);

		// Creating thread 
		void create_thread();

		// Get success count
		int get_success ();

		// Get failed count
		int get_failed ();
		
		// Get Thread ID
		int get_thread_id ();

		// Set success count
		void set_success (int success);

		// Set failed count
		void set_failed (int failure);

		// Set Thread ID
		void set_thread_id (int id);

		// Static Callback function
		static void staticCallbackFunction(void *p, vector<uint64_t> *th, int svalue, int id, void *thp);
	
	private:		
		// Local pointer for data region access
		vector<uint64_t> *Data;
		
		int thread_id;
		int start_value = 0, success_count = 0, failure_count = 0;

		CallbackFunctionPtr m_cb;
		void *m_p;
		thread glb_thread;
};
