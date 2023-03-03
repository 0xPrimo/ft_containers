#ifndef _MAP_ITERATOR_
# define _MAP_ITERATOR_

#include "../utils/iterator_traits.hpp"

# define RED 0
# define BLACK 1
template< class T>
struct Node_map
{
    typedef T   value_type;

    T       value;
    int     color;
    Node_map*   parent;
    Node_map*   left;
    Node_map*   right;

    Node_map(): color(RED), left(0), right(0), parent(0) {}

};
namespace ft
{
    template <class value>
    class map_iterator
    {
        public:
            typedef typename ft::iterator_traits<value>::value_type                  value_type;
            typedef typename ft::iterator_traits<value>::difference_type             difference_type;
            typedef typename ft::iterator_traits<value>::pointer                     pointer;
            typedef typename ft::iterator_traits<value>::reference                   reference;
            typedef std::bidirectional_iterator_tag                                  iterator_category;
            typedef Node_map<value_type>                                                 Node;

        private:
            Node *get_max(Node *node)
            {
                if (!node || node == NIL)
                    return (NULL);
                while (node->right != NIL)
                    node = node->right;
                return (node);
            }

        public:
            map_iterator(): node(NULL), NIL(NULL), Max(NULL)
            {
            }

            map_iterator(Node* node, Node* NIL, Node *Max): node(node), NIL(NIL), Max(Max)
            {
            }
            
            template<class U>
            map_iterator(const map_iterator<U>& other): node(other.base()), NIL(other.Nil()), Max(other.max())
            {
            }

            map_iterator& operator=(const map_iterator& other)
            {
                this->node = other.base();
                this->NIL = other.Nil();
                this->Max = other.max();
                return (*this);
            }
            
            

            map_iterator& operator++()
            {
                if (node->right != NIL)
                {
                    node = node->right;
                    while (node->left != NIL)
                        node = node->left;
                }
                else
                {
                    Node *parent = node->parent;
                    while (parent != NIL && node == parent->right)
                    {
                        node = parent;
                        parent = parent->parent;
                    }
                    node = parent;
                }
                return (*this);
            }

            map_iterator operator++(int)
            {
                map_iterator tmp(*this);
                this->operator++();
                return (tmp);
            }

            map_iterator& operator--()
            {
                if (node == NIL)
                    node = Max;
                else if (node->left != NIL)
                {
                    node = node->left;
                    while (node->right != NIL)
                        node = node->right;
                }
                else
                {
                    Node *parent = node->parent;
                    while (parent != NIL && node == parent->left)
                    {
                        node = parent;
                        parent = parent->parent;
                    }
                    node = parent;
                }
                return (*this);
            }

            map_iterator operator--(int)
            {
                map_iterator tmp(*this);
                this->operator--();
                return (tmp);
            }
            reference operator*() const
            {
                return (node->value);
            }

            pointer operator->() const
            {
                return (&node->value);
            }

            Node* base() const
            {
                return (node);
            }
            Node* Nil() const
            {
                return (NIL);
            }

            Node* max() const
            {
                return (Max);
            }
        private:
            Node*   node;
            Node*   NIL;
            Node*   Max;
    };

    template <class it1, class it2>
    bool operator==(const ft::map_iterator<it1> &iter1, const ft::map_iterator<it2> &iter2)
    {
        if (iter1.base() == iter2.base())
            return (true);
        return (false);
    }

    template <class it1, class it2>
    bool operator!=(const ft::map_iterator<it1> &iter1, const ft::map_iterator<it2> &iter2)
    {
        if (iter1.base() != iter2.base())
            return (true);
        return (false);
    }
}
#endif