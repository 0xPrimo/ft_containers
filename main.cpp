#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <memory>

#include "vector/vector.hpp"

int main()
{
    ft::vector<int> vec(10, 2);

    vec.resize(5, 554);
    vec.resize(10, 911);

    for(ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        std::cout << *it << std::endl;
    }
}