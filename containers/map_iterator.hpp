#ifndef _MAP_ITERATOR_
# define _MAP_ITERATOR_

#include "vector_iterator_traits.hpp"

# define RED 0
# define BLACK 1
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
    template <class value>
    class map_iterator
    {
        public:
            typedef typename ft::iterator_traits<value>::value_type                  value_type;
            typedef typename ft::iterator_traits<value>::difference_type             difference_type;
            typedef typename ft::iterator_traits<value>::pointer                     pointer;
            typedef typename ft::iterator_traits<value>::reference                   reference;
            typedef typename ft::iterator_traits<value>::iterator_category           iterator_category;
            typedef Node<value_type>                                                 Node;



        public:
            map_iterator(): node(NULL), NIL(NULL)
            {

            }

            map_iterator(Node* node, Node* NIL): node(node), NIL(NIL)
            {

            }
            map_iterator(const map_iterator& other): node(other.base()), NIL(other.Nil())
            {

            }

            map_iterator& operator=(const map_iterator& other)
            {
                this->node = other.base();
                this->NIL = other.Nil();
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
                    while (parent != NIL && node == node->right)
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
                if (node->NIL != NIL)
                {
                    node = node->left;
                    while (node->right != NIL)
                        node = node->right;
                }
                else
                {
                    Node *parent = node->parent;
                    while (parent != NIL && node == node->left)
                    {
                        node = parent;
                        parent = parent->parent;
                    }
                    node = parent;
                }
                return (*this);
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

        private:
            Node*   node;
            Node*   NIL;
    };

    // template <class it>
    // Iterator<it> operator-(int n, const Iterator<it> &other)
    // {
    //     Iterator<it> tmp(other);

    //     tmp -= n;

    //     return (tmp);
    // }

    // template <class it>
    // Iterator<it> operator+(int n, const Iterator<it> &other)
    // {
    //     Iterator<it> tmp(other);

    //     tmp += n;

    //     return (tmp);
    // }

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

    // template <class it1, class it2>
    // bool operator<(const ft::Iterator<it1> &iter1, const ft::Iterator<it2> &iter2)
    // {
    //     if (iter1.base() < iter2.base())
    //         return (true);
    //     return (false);
    // }

    // template <class it1, class it2>
    // bool operator<=(const ft::Iterator<it1> &iter1, const ft::Iterator<it2> &iter2)
    // {
    //     if (iter1.base() <= iter2.base())
    //         return (true);
    //     return (false);
    // }

    // template <class it1, class it2>
    // bool operator>(const ft::Iterator<it1> &iter1, const ft::Iterator<it2> &iter2)
    // {
    //     if (iter1.base() > iter2.base())
    //         return (true);
    //     return (false);
    // }

    // template <class it1, class it2>
    // bool operator>=(const ft::Iterator<it1> &iter1, const ft::Iterator<it2> &iter2)
    // {
    //     if (iter1.base() >= iter2.base())
    //         return (true);
    //     return (false);
    // }

}
#endif