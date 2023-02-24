#include "containers/map.hpp"
#include "utils/pair.hpp"
// #include "p_tree/src/fancy_tree.hpp"
#include "containers/map_iterator.hpp"
#include <map>
#include <utility>
#include <string>


int main()
{
    ft::map<std::string, int> db;
    std::string str1 = "empty", str2 = "full", str3 = "yello", str4 = "mello";
    int num1 = 1, num2 = 2, num3 = 3, num4 = 4;

    ft::pair<const int, std::string> p1(1, "hello");
    ft::pair<const int, std::string> p2(2, "hello");
    ft::pair<const int, std::string> p3(3, "hello");
    ft::pair<const int, std::string> p4(4, "hello");

    // ft::pair<const int, std::string> p(1, "empty");
    db.insert(p1);
    db.insert(p2);
    db.insert(p3);
    db.insert(p4);

    ft::map<std::string, int>::iterator it = db.begin();
    it++;
    
    // db.insert(std::make_pair(num2, str2));
    // db.insert(std::make_pair(num3, str3));
    // db.insert(std::make_pair(num4, str4));
    
    // std::cout << (--db.begin())->first << std::endl;
    // map_iterator<int *> it;

    return (0);
}