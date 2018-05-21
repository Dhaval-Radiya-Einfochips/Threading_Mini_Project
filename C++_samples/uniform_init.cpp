#include <iostream>
#include <assert.h>

class uniform_init {
	public :
		uniform_init(int val) {
			value = val;
		}
		int get_value() {
			std::cout << "Get Value Called : " << value << std::endl;
			return value;
		}
	private :
		int value;

};

int main() {
	uniform_init obj{5};
	assert(obj.get_value() == 5);

	return 0;
}

