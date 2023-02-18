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

    
        void printBT(const std::string& prefix, const node* node, bool isLeft)
        {
            if( node != nullptr )
            {
                std::cout << prefix;

                std::cout << (isLeft ? "├──" : "└──" );

                // print the value of the node
                std::cout << (node->color ? RESET: REED) << *node->value << RESET << (node->side ? " Right" : " Left") << std::endl;
                
                
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
    private:
        void rightRotation(node *Node)
        {
            node *tmp = Node->left;

            // Inherite the Node
            Node->left = tmp->right;
            if (tmp->right != NULL)
                tmp->right->parent = Node; // Inherite the Node
            tmp->parent = Node->parent;
            if (Node->parent == NULL)
                root = tmp;
            else if (Node == Node->parent->right) // the Node at the right side
                Node->parent->right = tmp;
            else // the Node at the left side
                Node->parent->left = tmp;
            tmp->right = Node;
            Node->parent = tmp;
        }

        void leftRotation(node *Node)
        {
            node *tmp = Node->right;

            Node->right = tmp->left;
            if (tmp->left != NULL)
                tmp->left->parent = Node;
            tmp->parent = Node->parent;
            if (Node->parent == NULL)
                root = tmp;
            else if (Node == Node->parent->left)
                Node->parent->left = tmp;
            else
                Node->parent->right = tmp;
            tmp->left = Node;
            Node->parent = tmp;
        }

        void BalanceTreeInsert(node *curr)
        {
            while (curr != root && curr->parent->color == RED)
            {
                node *GrandNode = curr->parent->parent;
                if (GrandNode->right == curr->parent) // we are at the right side of the tree
                {
                    if (GrandNode->left->color == RED) // Swap colors
                    {
                        GrandNode->right->color = BLACK;
                        GrandNode->left->color = BLACK;
                        GrandNode->color = RED;

                        curr = GrandNode; // balance the grand node
                    }
                    else // do a left rotation
                    {
                        if (curr == curr->parent->left)
                        {
                            curr = curr->parent;
                            rightRotation(curr);
                        }
                        curr->parent->color = BLACK;
                        GrandNode->color = RED;
                        leftRotation(GrandNode);
                    }
                }
                else // we are at the left side of the tree
                {
                    if (GrandNode->right->color == RED) // Swap colors
                    {
                        GrandNode->left->color = BLACK;
                        GrandNode->right->color = BLACK;
                        GrandNode->color = RED;

                        curr = GrandNode; // balance the grand node
                    }
                    else // do a right rotation
                    {
                        if (curr == curr->parent->right)
                        {
                            curr = curr->parent;
                            leftRotation(curr);
                        }
                        curr->parent->color = BLACK;
                        GrandNode->color = RED;
                        rightRotation(GrandNode);
                    }
                }
                
            }
            root->color = BLACK;
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
                    BalanceTreeInsert(parent->left);
                }
                else
                {
                    parent->right = newNode(value, parent, RIGHT);
                    BalanceTreeInsert(parent->right);
                }
            }
            size++;
            /* balance the tree */

        }

};

#endif