#include <iostream>
#include <vector>

using namespace std;

class Stooge {
	public:
    		virtual void slap_stick() = 0;
};

class Larry: public Stooge {
	public:
    		void slap_stick() {
        		cout << "Larry: poke eyes\n";
    		}
};
class Moe: public Stooge {
	public:
    		void slap_stick() {
        		cout << "Moe: slap head\n";
    		}
};
class Curly: public Stooge {
	public:
    		void slap_stick() {
        		cout << "Curly: suffer abuse\n";
    		}
};
class JP: public Stooge {
	public:
                void slap_stick() {
                        cout << "JP: Bhow bhow\n";
                }
};

int main()
{
	vector<Stooge*> roles;
  	int choice;

  	while (true) {
    		cout << "Larry(1) Moe(2) Curly(3) JP(4) Go(0): ";
    		cin >> choice;
    
		if (choice == 0) {
			cout << "Choice is : 0, so break !!\n";
      			break;
		} else if (choice == 1) {
			cout << "Choice is : 1, Created Larry !!\n";
      			roles.push_back(new Larry);
		} else if (choice == 2) {
			cout << "Choice is : 2, Created Moe !!\n";
      			roles.push_back(new Moe);
		} else if (choice == 3) {
			cout << "Choice is : 3, Created Curly !!\n";
      			roles.push_back(new Curly);
		} else {
			cout << "Choice is : 4, Created JP !!\n";
			roles.push_back(new JP);
		}
  	}
  
	cout << "Size of Role Vector is : " << roles.size() << endl;

	for (int i = 0; i < roles.size(); i++)
    		roles[i]->slap_stick();
  
	for (int i = 0; i < roles.size(); i++)
    		delete roles[i];
}
