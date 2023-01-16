#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <memory>

#include "vector/vector.hpp"

int main()
{
    ft::vector<int> vec;

    char arr[] = {47, 34, 58, 97, 67, 85};

    vec.insert(vec.begin() + 7, arr, arr + 6);
    std::cout << "cap, " << vec.capacity() << std::endl;
    std::cout << "size, " << vec.size() << std::endl;
    for(ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        std::cout << *it << std::endl;
    }
}