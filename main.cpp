#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <memory>
#include <type_traits>
#include "vector/vector.hpp"
#include <algorithm>
#include <string>
#include <memory>
    
int main()  
{
    std::allocator<int> alloc;


    int *ptr = alloc.allocate(20);
    ptr = alloc.allocate(20);
    alloc.deallocate(ptr, 20);
}