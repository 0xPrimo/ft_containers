#include <memory>
#include <iterator>
#include <iostream>
#include "vector.hpp"

int main()
{
    ft::vector<int> b(10, 20);

    for(ft::vector<int>::iterator it = b.begin(); it != b.end(); it++){
        std::cout << (*it) << std::endl;
    }
}