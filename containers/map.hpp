#ifndef _MAP_
# define _MAP_
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
    Node*   parent;
    Node*   left;
    Node*   right;

    Node(): value(0), color(RED), left(0), right(0), parent(0) {}

};
namespace ft
{
/* ref: https://github.dev/m3zh/ft_containers/tree/master/src */
template< class T, class comp = std::less<T> , class alloc = std::allocator<T> >
class map
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
        node *newNode(value_type const &value, node *parent)
        {
            node *newnode = new node;
            
            newnode->value = allocator.allocate(1);
            allocator.construct(newnode->value, value);
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
            while (curr && curr != root && curr->parent->color == RED)
            {
                node *GrandNode = curr->parent->parent;
                if (GrandNode->right == curr->parent) // we are at the right side of the tree
                {
                    if (GrandNode->left && GrandNode->left->color == RED) // Swap colors
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
                    if (GrandNode->right && GrandNode->right->color == RED) // Swap colors
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

        void changeColor(node *Node)
        {
            Node->color = Node->color == RED ? BLACK : RED;
        }

        void BalanceTreeErase(node *Node)
        {
            while(Node != root && Node->color != BLACK)
            {
                if (Node == Node->parent->left)
                {
                    node *sib = Node->parent->right;
                    if (sib->color == RED)
                    {
                        sib->color = BLACK;
                        Node->parent->color = RED;
                        leftRotation(Node->parent);
                        sib = Node->parent->right;
                    }
                    if (sib->left->color == BLACK && sib->right->color == BLACK)
                    {
                        sib->color = RED;
                        Node = Node->parent;
                    }
                    else
                    {
                        if (sib->right->color == BLACK)
                        {
                            sib->left->color = BLACK;
                            sib->color = RED;
                            rightRotation(sib);
                            sib = Node->parent->right;
                        }
                        sib->color = Node->parent->color;
                        Node->parent->color = BLACK;
                        sib->right->color = BLACK;
                        leftRotation(Node->parent);
                        Node = root;
                    }
                }
                else
                {
                    node *sib = Node->parent->left;
                    if (sib->color == RED)
                    {
                        sib->color = BLACK;
                        Node->parent->color = RED;
                        rightRotation(Node->parent);
                        sib = Node->parent->left;
                    }
                    if (sib->left->color == BLACK && sib->right->color == BLACK)
                    {
                        sib->color = RED;
                        Node = Node->parent;
                    }
                    else
                    {
                        if (sib->left->color == BLACK)
                        {
                            sib->right->color = BLACK;
                            sib->color = RED;
                            leftRotation(sib);
                            sib = Node->parent->left;
                        }
                        sib->color = Node->parent->color;
                        Node->parent->color = BLACK;
                        sib->left->color = BLACK;
                        rightRotation(Node->parent);
                        Node = root;
                    }                    
                }
            }
            Node->color = BLACK;
        }

    public:
        map(): root(NULL), size(0)
        {
        }
        
        void insert( value_type const &value)
        {
            if (!root && !size++)
            {
                root = newNode(value, NULL);
                root->color = BLACK;
            }
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
                    parent->left = newNode(value, parent);
                    if (parent->color == RED)
                        BalanceTreeInsert(parent->left);
                }
                else
                {
                    parent->right = newNode(value, parent);
                    if (parent->color == RED)
                        BalanceTreeInsert(parent->right);
                }
            }
            size++;
            /* balance the tree */

        }

        void rbTransplant(node *a, node *b)
        {
            if (a->parent == NULL)
                root = b;
            else if (a == a->parent->left)
                a->parent->left = b;
            else
                a->parent->right = b;
            if (b)
                b->parent = a->parent;
        }

        node *get_min(node *node)
        {
            while (node->left != NULL)
                node = node->left;
            return (node);
        }


        node *get_node(value_type &value)
        {
            node *tmp = root;
            while (tmp != NULL)
            {
                if (value < *(tmp->value))
                    tmp = tmp->left;
                else if (value > *(tmp->value))
                    tmp = tmp->right;
                else
                    return (tmp);
            }
            return (0);
        }

        void erase(value_type &value)
        {
            erase(get_node(value));
        }

        void erase(node *Node)
        {
            node    *tmp = Node;
            node    *to_balance;
            int     color = Node->color;

            if (Node->left == NULL)
            {
                to_balance = Node->right;
                rbTransplant(Node, Node->right);
            }
            else if (Node->right == NULL)
            {
                to_balance = Node->left;
                rbTransplant(Node, Node->left);
            }
            else
            {
                tmp = get_min(Node->right);
                color = tmp->color;
                to_balance = tmp->right;
                if (to_balance && tmp->parent == Node)
                    to_balance->parent = tmp;
                else
                {
                    rbTransplant(tmp, tmp->right);
                    tmp->right = Node->right;
                    if (tmp->right)
                        tmp->right->parent = tmp;
                }

                rbTransplant(Node, tmp);
                tmp->left = Node->left;
                tmp->left->parent = tmp;
                tmp->color = Node->color;
            }

        }

};
}

#endif