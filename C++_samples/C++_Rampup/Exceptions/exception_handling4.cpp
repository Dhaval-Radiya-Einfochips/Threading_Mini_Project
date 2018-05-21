#include <iostream>
using namespace std;
 
int main()
{
    try  {
       throw 5;
    }
    catch (int x)  {
        cout << "Caught Exceptions : " << x << endl;
    }
    catch (...)  {
        cout << "Default Exception\n";
    }
    return 0;
}
