#ifndef _RBTREE_
# define _RBTREE_
# include <memory>
# include <string>
# include <iostream>
// # include "../utils/pair.hpp"

# define RED 0
# define BLACK 1
# define LEFT 0
# define RIGHT 1


/* Colors */
#define RESET "\033[m"
#define REED   "\033[0;31m"


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
template< class T, class comp = std::less<T> , class alloc = std::allocator<T> >
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
        node *newNode(value_type const &value, node *parent, int side)
        {
            node *newnode = new node;
            
            newnode->value = allocator.allocate(1);
            allocator.construct(newnode->value, value);
            newnode->side = side;
            newnode->color = RED;
            newnode->parent = parent;
            newnode->left = NULL;
            newnode->right = NULL;
            return (newnode);
        }
    private:
        void BalanceTreeInsert(node *curr)
        {

        }
    
        void printBT(const std::string& prefix, const node* node, bool isLeft)
        {
            if( node != nullptr )
            {
                std::cout << prefix;

                std::cout << (isLeft ? "├──" : "└──" );

                // print the value of the node
                std::cout << (node->color ? RESET: REED) << *node->value << RESET << std::endl;
                
                
                // enter the next tree level - left and right branch
                printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
                printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
            }
        }

        void printBT(const node* node)
        {
            printBT("", node, false);
        }

    public:
        void print()
        {
            printBT(root);
        }


    public:
        RedBlackTree(): root(NULL), size(0)
        {

        }
        void insert( value_type const &value)
        {
            if (!root && !size++)
                root = newNode(value, NULL, BLACK);
            else
            {
                node *tmp = root;
                node *parent = NULL;
                while (tmp != NULL)
                {
                    parent = tmp;
                    if (value < *(tmp->value))
                        tmp = tmp->left;
                    else if (*(tmp->value) < value)
                        tmp = tmp->right;
                }

                if (value < *parent->value)
                {   
                    parent->left = newNode(value, parent, LEFT);
                    // BalanceTreeInsert(parent->left);
                }
                else
                {
                    parent->right = newNode(value, parent, RIGHT);
                    // BalanceTreeInsert(parent->right);
                }
            }
            size++;
            /* balance the tree */

            
        }

};

#endif