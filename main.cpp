#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <memory>

// #include "vector/vector.hpp"

int main()
{
    std::vector<int> vec(10, 20);

    std::vector<int>::iterator itr = vec.begin();
    // vec.insert(itr, 100);
    // itr = vec.begin() + 1;
    // vec.insert(itr, 100);
    // itr = vec.end();
    // vec.insert(itr, 100);

    std::vector<int>::iterator it = vec.begin();

    for(;it != vec.end(); it++){
        std::cout << *it << std::endl;
    }
    std::cout << "Capacity: " << vec.capacity() << std::endl;
}