#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <memory>
#include <type_traits>
#include "vector/vector.hpp"

int main()
{
    int arr[] = {10, 20, 30};
    ft::vector<int> vec(arr, arr + 1);
}