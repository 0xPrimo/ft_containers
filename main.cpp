#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <memory>

#include "vector/vector.hpp"

int main()
{
    std::vector<int> vec;

    vec.insert(vec.begin(), 911);
    vec.insert(vec.begin() + 10, 911);
    std::vector<int>::iterator it = vec.begin();
    for(; it != vec.end(); it++)
        std::cout << *it << std::endl;
    std::cout << vec.size() << ", " << vec.capacity() << std::endl;
}