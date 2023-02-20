#include "containers/map.hpp"

int main()
{
    int arr[] = {9, 123 , 1, 4534, 66, 4, 0, 34, 948, 234, 987, 829, 950};
    ft::map<int> map;

    for(int i = 0; i < 10; i++)
        map.insert(arr[i]);
    
    map.erase(arr[0]);
    map.erase(arr[1]);
    map.print();
    return (0);
}