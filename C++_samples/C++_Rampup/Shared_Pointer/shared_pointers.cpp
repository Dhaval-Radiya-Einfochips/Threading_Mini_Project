#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;
 
struct Base {
	Base() { 
		std::cout <<"Base Constructor :: Base()\n";
	}
    	
	~Base() { 
		std::cout <<"Base Distructor :: ~Base()\n";
	}
};
 
struct Derived: public Base {
    	Derived() { 
		std::cout <<"Derived Constructor :: Derived()\n"; 
	}
    
	~Derived() { 
		std::cout <<"Derived Distructor:: ~Derived()\n";
	}
};
 
void thr(std::shared_ptr<Base> p) {
	std::this_thread::sleep_for(std::chrono::seconds(1));
    
	std::shared_ptr<Base> lp = p; // thread-safe, even though the shared use_count is incremented
    	{
        	static std::mutex io_mutex;
        	std::lock_guard<std::mutex> lk(io_mutex);
        	std::cout << "local pointer in a thread:\n" << "lp.get() = " << lp.get() << ", lp.use_count() = " << lp.use_count() << '\n';
    	}
}
 
int main() {
	std::shared_ptr<Base> p = std::make_shared<Derived>();
 
    	std::cout <<"Created a shared Derived (as a pointer to Base)\n" << "p.get() = " << p.get() <<", p.use_count() = " << p.use_count() << '\n';
    
	std::thread t1(thr, p), t2(thr, p), t3(thr, p);
    
	p.reset(); // release ownership from main
    
	std::cout <<"Shared ownership between 3 threads and released\n" << "ownership from main:\n" << "p.get() = " << p.get() << ", p.use_count() = " << p.use_count() << '\n';

	t1.join(); t2.join(); t3.join();

	std::cout <<"All threads completed, the last one deleted Derived\n";
}
