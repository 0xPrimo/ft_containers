#ifndef _SET_ITERATOR_
# define _SET_ITERATOR_

#include "../utils/iterator_traits.hpp"

# define RED 0
# define BLACK 1
template< class T>
struct Node_set
{
    typedef T   value_type;

    T       value;
    int     color;
    Node_set*   parent;
    Node_set*   left;
    Node_set*   right;

    Node_set(): color(RED), left(0), right(0), parent(0) {}

};
namespace ft
{
    template <class value>
    class set_iterator
    {
        public:
            typedef typename ft::iterator_traits<value>::value_type                  value_type;
            typedef typename ft::iterator_traits<value>::difference_type             difference_type;
            typedef typename ft::iterator_traits<value>::pointer                     pointer;
            typedef typename ft::iterator_traits<value>::reference                   reference;
            typedef std::bidirectional_iterator_tag                                  iterator_category;
        
        private:
            typedef Node_set<value_type>                                                 Node;

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
            set_iterator(): node(NULL), NIL(NULL), Max(NULL)
            {
            }

            set_iterator(Node* node, Node* NIL, Node *Max): node(node), NIL(NIL), Max(Max)
            {
            }
            
            template<class U>
            set_iterator(const set_iterator<U>& other): node(other.base()), NIL(other.Nil()), Max(other.max())
            {
            }

            set_iterator& operator=(const set_iterator& other)
            {
                this->node = other.base();
                this->NIL = other.Nil();
                this->Max = other.max();
                return (*this);
            }
            
            

            set_iterator& operator++()
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

            set_iterator operator++(int)
            {
                set_iterator tmp(*this);
                this->operator++();
                return (tmp);
            }

            set_iterator& operator--()
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

            set_iterator operator--(int)
            {
                set_iterator tmp(*this);
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
    bool operator==(const ft::set_iterator<it1> &iter1, const ft::set_iterator<it2> &iter2)
    {
        if (iter1.base() == iter2.base())
            return (true);
        return (false);
    }

    template <class it1, class it2>
    bool operator!=(const ft::set_iterator<it1> &iter1, const ft::set_iterator<it2> &iter2)
    {
        if (iter1.base() != iter2.base())
            return (true);
        return (false);
    }
}
#endif