#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <memory>

#include "vector/vector.hpp"

int main()
{
    int a = 10;

    ft::vector<int> vec(10, 2);

    // ft::vector<int>::reverse_iterator it = vec.rbegin();
    vec.rbegin();

    // std::cout << *it << std::endl;
    
}