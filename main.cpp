#include <map>
#include <iostream>
#include <iterator>
#include <string>

int main()
{
    int arr[] = {9, 123 , 1, 4534, 66, 4, 0, 34, 948, 234, 987, 829, 950};
    std::map<int, int> map;

    for(int i = 0; i < 13; i++)
    {
        map.insert(std::pair<int, int>(i, arr[i]));
    }
    std::map<int, int>::iterator it = map.begin();
    for(; it != map.end(); it++)
        std::cout << it->second << std::endl;

    return (0);
}