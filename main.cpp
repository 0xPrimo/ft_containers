#include "rb.hpp"

int main()
{
    rb tree;
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    for(int i = 0; i < 10; i++)
        tree.insert(arr[i]);
    
    return (0);
}