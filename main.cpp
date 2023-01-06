#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <memory>

#include "vector/vector.hpp"

int main()
{
    int a = 10;
    ft::vector<char> vec(10, 'b');



    vec.assign(200, 'a');
    for(ft::vector<char>::iterator it = vec.begin(); it != vec.end(); it++){
        std::cout << *it << std::endl;
    }
    std::cout << vec.capacity() << std::endl;
}