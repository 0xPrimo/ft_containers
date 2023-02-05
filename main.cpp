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
    {
        
        int a[64];
        for(int i = 0; i < 64; i++)
            a[i] = i;



        ft::vector<int> v(a, a + 64);
        
        // v.resize(14, "hello mate");
        
        // ft::vector<int>::reverse_iterator it = v.rend() - 1;
        ft::vector<int>::reverse_iterator it2 = v.rbegin();
        // ft::vector<std::string>::const_reverse_iterator cit = v.rbegin();
        // ft::vector<std::string>::const_reverse_iterator cit2 = v.rbegin();


        std::cout << it2[2] << std::endl;
        // std::cout << *it << std::endl;
        // if (v.rbegin() == cit)
        //     std::cout << "true" << std::endl;
    }
}