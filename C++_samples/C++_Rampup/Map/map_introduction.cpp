#include <iostream>
#include <map>
#include <string>
#include <iterator>

using namespace std;

std::map<std::string, int>::iterator serachByValue(std::map<std::string, int> & mapOfWords, int val)
{
    // Iterate through all elements in std::map and search for the passed element
    std::map<std::string, int>::iterator it = mapOfWords.begin();
    while(it != mapOfWords.end())
    {
        if(it->second == val)
	        return it;
        it++;
    }
	return it;
}
 
int main()
{
    std::map<std::string, int> mapOfWords;
    
    mapOfWords.insert(std::make_pair("earth", 1));
    
    mapOfWords.insert(std::make_pair("moon", 1));
    
    mapOfWords["sun"] = 1;
    
    // Will replace the value of already added key i.e. earth
    mapOfWords["earth"] = 4;
    
    // Iterate through all elements in std::map
    std::map<std::string, int>::iterator it = mapOfWords.begin();
    
    while(it != mapOfWords.end())
    {
        std::cout<< it->first << " :: " << it->second << std::endl;
        it++;
    }
    
    // Check if insertion is successful or not
    //if(mapOfWords.insert(std::make_pair("earth", 1)).second == false)
    if(mapOfWords.insert(std::make_pair("EI", 1)).second == false)
    {
        std::cout<<"Element with key 'earth' not inserted because already existed"<<std::endl;
    }

    // Searching element in std::map by key.
    if(mapOfWords.find("sun") != mapOfWords.end())
        std::cout<<"word 'sun' found"<<std::endl;

    if(mapOfWords.find("mars") == mapOfWords.end())
        std::cout<<"word 'mars' not found"<<std::endl;

    it = serachByValue(mapOfWords, 2);
    if((it != mapOfWords.end())) {
        std::cout<< "Search key is : " << it->first << " :: " << it->second<<std::endl;
	mapOfWords.erase(it);
    } 

    //pOfWords.erase(it);

    std::map<std::string, int>::iterator it1 = mapOfWords.begin();

    while(it1 != mapOfWords.end())
    {
        std::cout<< it1->first << " :: " << it1->second << std::endl;
        it1++;
    }

    return 0;
}
