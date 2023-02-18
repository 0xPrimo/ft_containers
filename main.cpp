#include "containers/RedBlackTree.hpp"

int main()
{
    RedBlackTree<int> tree;
    int arr[] = {9, 123 , 1, 4534, 66, 4, 0};

    tree.insert(9);
    tree.insert(15);
    // for(int i = 0; i < 7; i++)
    //     tree.insert(arr[i]);
    tree.print();
    return (0);
}