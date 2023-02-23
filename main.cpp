#include "containers/map.hpp"
#include "fancy_tree/src/fancy_tree.hpp"
int main()
{
    int arr[] = {9, 123 , 1, 4534, 66, 4, 0, 34, 948, 234, 987, 829, 950};
    ft::map<int> map;

    fancy_tree<int> tree;

    for(int i = 0; i < 10; i++)
        map.insert(arr[i]);
    // map.print();
    
    map.erase(arr[0]);
    // std::cout << *map.root->value << std::endl;
    map.erase(arr[4]); 
    map.erase(arr[8]); 
    map.erase(arr[2]); 
    map.erase(arr[9]); 
    map.erase(arr[3]); 
    tree.print_tree(map.root, V_VIEW);
    // map.print();
    // map.print();
    return (0);
}