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
    int *arr = (int *)malloc(sizeof(int) * 3);

    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    std::vector<int> vec(20, 20);
    std::vector<int> vec2(10, 10);

    vec.push_back(10);

    std::cout << "--------------------------------" << std::endl;
    std::cout << "vec2 cap: " << vec2.capacity() << std::endl;
    std::cout << "vec2 size: " << vec2.size() << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "vec cap: " << vec.capacity() << std::endl;
    std::cout << "vec size: " << vec.size() << std::endl;
    std::cout << "--------------------------------" << std::endl;


    vec2 = vec;
    
    std::cout << "------------after--------------" << std::endl;
    std::cout << "vec2 cap: " << vec2.capacity() << std::endl;
    std::cout << "vec2 size: " << vec2.size() << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "vec cap: " << vec.capacity() << std::endl;
    std::cout << "vec size: " << vec.size() << std::endl;
    std::cout << "--------------------------------" << std::endl;

    std::vector<int>::iterator it = vec2.begin();

    try
    {
        for(int i = 0; it != vec2.end(); it++)
            std::cout << *it << std::endl;
    }
    catch(std::exception &ex)
    {
        std::cout << ex.what() << std::endl;
    }
}