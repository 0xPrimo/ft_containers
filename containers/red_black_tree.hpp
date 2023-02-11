#ifndef _RBTREE_
# define _RBTREE_
# include <memory>
# include "../utils/pair.hpp"

#define RED 0
#define BLACK 1

template <class T, class alloc>
class node
{
    private:
        alloc m_Allocator;
    public:
        node(const T &value, node *parent, bool color = RED): left(NULL),
                                                            right(NULL),
                                                            parent(parent),
                                                            color(color)
        {
            data = m_Allocator.allocate(1);
            m_Allocator.construct(data, value);
        }
        ~node()
        {
            m_Allocator.destroy(data);
            m_Allocator.deallocate(data, 1);
        }
    public:
        node*   left, right, parent;
        T*      data;
        bool    color;

};

template <class T, class Key, class alloc = std::allocator<T>,
    class Compare = std::less<Key> >
class rbtree
{
private:
    typedef     node<T, alloc>  node;

private:
    node    *root;
    size_t  size;    
};

#endif