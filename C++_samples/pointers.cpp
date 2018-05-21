#include <iostream>
#include <assert.h>
#include <vector>
#include <functional>
#include <memory>

class pointers {
        public :
                pointers(std::unique_ptr<int> p1) : ptr1(std::move(p1)) {
                        std::cout << "Pointers: Constructor called" << std::endl;
                }

                std::function<int ()> get_function() {
                        return std::bind(&pointers::get_value, this);
                }

                int get_value() {
			std::cout << "Pointers: Constructor called : " << *ptr1 << std::endl;
                        return *ptr1;
                }

        private:
                std::unique_ptr<int> ptr1;
};

int main() {
        std::unique_ptr<int> p1(new int(40));

        std::unique_ptr<pointers> a(new pointers(std::move(p1)));

        std::function<int ()> func = a->get_function();

        assert(func() == 40);

}
