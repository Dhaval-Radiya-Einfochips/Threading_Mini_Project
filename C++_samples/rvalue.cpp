#include <iostream>
#include <memory>

class shared {
	public :
		shared () : share_count(count++) {
			std::cout << "Shared :: Default Constructor : " << share_count << std::endl;
		}

		shared (const shared & obj) : share_count(count++) {
			std::cout << "Shared :: Copy Constructor : " << obj.share_count << " to " << share_count << std::endl;
		}

		shared (shared && obj) : share_count(count++) {
			std::cout << "Shared :: Move Constructor : "  << obj.share_count << " to " << share_count << std::endl;
		}

		~shared () {
			std::cout << "~Shared :: Destructor : " << share_count << std::endl;
		}

		shared & operator=(const shared & obj) {
			std::cout << "Shared :: Copy Assignment : " << obj.share_count << " to " << share_count << std::endl;
		}

		shared & operator=(shared && obj) {
			std::cout << "Shared :: Move Assignment : " << obj.share_count << " to " << share_count << std::endl;
		}

	private :
		static int count;
		int share_count;
};

int shared::count = 0;

int main() {
	{
		shared a0{};
	}
	{
		shared a1{};
		shared a2 = a1;

		std::unique_ptr<shared> a3(new shared());

		shared a4(std::move(*(a3.get())));

		a3.reset();
		
		a4 = a1;

		a2 = std::move(a4);
	}		
}
