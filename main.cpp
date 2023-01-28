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


#define A_SIZE 64
#define B_SIZE 32

// {
//     charvector v;

//     v.assign(0, 'c');

//     CHECK_AND_PRINT_ALL(v);

//     v.assign(64, 'A');

//     CHECK_AND_PRINT_ALL(v);

//     v.assign(32, '5');

//     CHECK_AND_PRINT_ALL(v);

//     v.assign(49, '8');

//     CHECK_AND_PRINT_ALL(v);

//     v.assign(77, '2');

//     CHECK_AND_PRINT_ALL(v);
// }

int main()  
{

    {
        
        int a[] = {10, 20, 30, 40, 50};


        std::vector<int> v;
        int c = 20;
        v.assign(a, &c);
    }
}