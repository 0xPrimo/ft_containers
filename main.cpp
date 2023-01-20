#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <memory>
#include <type_traits>
#include "vector/vector.hpp"
#include <algorithm>
#include <string>
    
    
int main()  
{

    std::vector<int> vec;

    for(int i = 0; i < 10; i++)
        vec.push_back(i);

    std::vector<int>::iterator it = vec.begin();

    try
    {
        vec.at(100);
    }
    catch(std::exception &ex)
    {
        std::cout << ex.what() << std::endl;
    }
}