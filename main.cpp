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
        // v.insert(v.end(), 10, 64);
        
        v.insert(v.begin(), 5, -1);

    }
}