#include "containers/map.hpp"

int main()
{
    map<int> tree;
    int arr[] = {9, 123 , 1, 4534, 66, 4, 0, 34, 948, 234, 987, 829, 950};


    for(int i = 0; i < 13; i++)
        tree.insert(arr[i]);
    tree.print();
    return (0);
}