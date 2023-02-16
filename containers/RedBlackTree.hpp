#ifndef _RBTREE_
# define _RBTREE_
# include <memory>
# include "../utils/pair.hpp"

# define RED 0
# define BLACK 1
# define LEFT 0
# define RIGHT 1

template< class T>
struct Node
{
    T       *value;
    int     color;
    int     side;
    Node*   parent;
    Node*   left;
    Node*   right;

    Node(): value(0), color(RED), left(0), right(0), parent(0) {}

};

/* ref: https://github.dev/m3zh/ft_containers/tree/master/src */
template<class T, class comp = std::less< T >, class alloc = std::allocator<T>>
class RedBlackTree
{
    public:
        typedef T												            value_type;
        typedef alloc   										            allocator_type;                // container allocator
        typedef comp                                                        value_compare;                     
        typedef typename allocator_type::pointer				            pointer;
        typedef typename allocator_type::const_pointer			            const_pointer;
        typedef typename allocator_type::reference				            reference;
        typedef typename allocator_type::const_reference		            const_reference;
        typedef std::size_t										            size_type;
        typedef Node<T>                                                     node;
    private:
        node*           root;
        size_type       size;
        allocator_type  allocator;
    
    private:
        node *newNode(value_type const &value, node *parent, int color)
        {
            node *newnode = allocator.allocate(1);

            allocator.construct(&(newnode->value), value);
            newnode->color = color;
            newnode->parent = parent;
            newnode->left = NULL;
            newnode->right = NULL;
        }

    public:
        RedBlackTree(): root(0), size(0) {}

        void insert( value_type const &value)
        {
            if (!root && size++)
                root = newNode(value, NULL, BLACK);
            else
            {
                node *tmp = root;
                node *parent = NULL;
                while (tmp != NULL)
                {
                    parent = tmp;
                    if (comp(value, tmp->value))
                        tmp = tmp->left;
                    else if (comp(tmp->value, value))
                        tmp = tmp->right;
                }
                tmp = newNode(value, parent, RED);
                if (comp(value, parent->value))
                    parent->left = tmp;
                else
                    parent->right = tmp;
            }
        }

};

#endif