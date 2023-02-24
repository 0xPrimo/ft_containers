#ifndef _MAP_
# define _MAP_
# include <memory>
# include <string>
# include <iostream>

# include "../utils/pair.hpp"

# define RED 0
# define BLACK 1



/* Colors */
#define RESET "\033[m"
#define REED   "\033[0;31m"


template< class T>
struct Node
{
    typedef T   value_type;

    T       value;
    int     color;
    Node*   parent;
    Node*   left;
    Node*   right;

    Node(): color(RED), left(0), right(0), parent(0) {}
    // Node(const Node &other): value(other.value), color(other.color), left(other.left), right(other.right), parent(other.parent) {}

};
namespace ft
{
/* ref: https://github.dev/m3zh/ft_containers/tree/master/src */
template< class T, class Key, class compare = std::less<Key> , class alloc = std::allocator<ft::pair<const Key, T> > >
class map
{
    public:
        typedef Key                                             key_type;
        typedef T                                               mapped_type;
        typedef ft::pair<const Key, T>		                    value_type;
        typedef std::size_t                                     size_type;
        typedef std::ptrdiff_t                                  difference_type;
        typedef compare                                         Key_compare;
        typedef alloc                                           allocator_type;
        typedef typename allocator_type::reference              reference;
        typedef typename allocator_type::const_reference        const_reference;
        typedef typename allocator_type::pointer                pointer;
        typedef typename allocator_type::const_pointer          const_pointer;
        typedef Node<value_type>                                node;
        typedef typename alloc::template rebind<node>::other    node_allocator;

        node*                   root;
    private:
        node*                   NIL;
        size_type               size;
        allocator_type          allocator;
        node_allocator          nodeAlloc;
        Key_compare             key_compare;
    
    private:
        node *newNode(value_type const &value, node *parent)
        {
            node *newnode = nodeAlloc.allocate(1);
            
            allocator.construct(&newnode->value, value);
            newnode->color = RED;
            newnode->parent = parent;
            newnode->left = NIL;
            newnode->right = NIL;
            return (newnode);
        }

        node *newNIL()
        {
            node *newnode = nodeAlloc.allocate(1);

            newnode->color = BLACK;
            newnode->parent = NULL;
            newnode->left = NULL;
            newnode->right = NULL;
            return (newnode);      
        }

        void rightRotation(node *Node)
        {
            node *tmp = Node->left;

            // Inherite the Node
            Node->left = tmp->right;
            if (tmp->right != NIL)
                tmp->right->parent = Node; // Inherite the Node
            tmp->parent = Node->parent;
            if (Node->parent == NIL)
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
            if (tmp->left != NIL)
                tmp->left->parent = Node;
            tmp->parent = Node->parent;
            if (Node->parent == NIL)
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

        void BalanceTreeErase(node *Node)
        {
            while(Node != root && Node->color == BLACK)
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

        void rbTransplant(node *a, node *b)
        {
            if (a->parent == NIL)
                root = b;
            else if (a == a->parent->left)
                a->parent->left = b;
            else
                a->parent->right = b;
            b->parent = a->parent;
        }

        node *get_min(node *node)
        {
            while (node->left != NIL)
                node = node->left;
            return (node);
        }


        node *get_node(value_type &value)
        {
            node *tmp = root;
            while (tmp != NULL)
            {
                if (key_compare(value.first, tmp->value.first))
                    tmp = tmp->left;
                else if (!key_compare(value.first, tmp->value.first))
                    tmp = tmp->right;
                else
                    return (tmp);
            }
            return (0);
        }

    public:
        map(const compare &com,
            const allocator_type &alloc = allocator_type()): root(NULL), size(0), NIL(newNIL()),
                                                             allocator(alloc), key_compare(com)
        {
        }
        
        template<class InputIt>
        map( InputIt first, InputIt last,
            const compare &comp = compare(),
            const allocator_type &alloc = allocator_type())
        {
            
        }
        void insert( const value_type &value)
        {
            if (!root && !size++)
            {
                root = newNode(value, NIL);
                root->color = BLACK;
            }
            else
            {
                node *tmp = root;
                node *parent = NULL;
                while (tmp != NIL)
                {
                    parent = tmp;
                    if (key_compare(value.first, tmp->value.first))
                        tmp = tmp->left;
                    else if (key_compare(tmp->value.first, value.first))
                        tmp = tmp->right;
                }
                if (key_compare(value.first, parent->value.first))
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

        void erase(value_type &value)
        {
            erase(get_node(value));
        }

        void erase(node *Node)
        {
            node*   FixUp;
            int     color;

            color = Node->color;
            if (Node->left == NIL)
            {
                FixUp = Node->right;
                rbTransplant(Node, Node->right);
            }
            else if (Node->right == NIL)
            {
                FixUp = Node->left;
                rbTransplant(Node, Node->left);
            }
            else
            {
                node *suc = get_min(Node->right);
                color = suc->color;
                FixUp = suc->right;
                if (suc->parent == Node)
                    suc->right->parent = suc;
                else
                {
                    rbTransplant(suc, suc->right);
                    suc->right = Node->right;
                    suc->right->parent = suc;
                }
                rbTransplant(Node, suc);
                suc->left = Node->left;
                suc->left->parent = suc;
                suc->color = Node->color;
            }
            
            if (color == BLACK)
                BalanceTreeErase(FixUp);
            size--;
        }

};
}

#endif