#include <iostream>
#include <iterator>
#include <vector>
#include <list>
// #include "vector/vector_iterator_traits.hpp"
// #include "vector/vector_iterator.hpp"
#include "vector/vector.hpp"

int main()
{
    ft::vector<int> vec(10, 5);

    ft::vector<int>::iterator it = vec.begin();

    for(int i;i < 10; i++)
        std::cout << it.operator[](i) << std::endl;
}