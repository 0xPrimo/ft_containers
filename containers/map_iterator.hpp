#ifndef _MAP_ITERATOR_
# define _MAP_ITERATOR_

#include "vector_iterator_traits.hpp"
#include "map.hpp"

template <class T>
class map_iterator
{
    public:
        typedef typename ft::iterator_traits<T>::value_type                  value_type;
        typedef typename ft::iterator_traits<T>::difference_type             difference_type;
        typedef typename ft::iterator_traits<T>::pointer                     pointer;
        typedef typename ft::iterator_traits<T>::reference                   reference;
        typedef typename ft::iterator_traits<T>::iterator_category           iterator_category;
    

    public:
        map_iterator(): node(NULL)
        {

        }

        map_iterator(Node* node): node(node)
        {

        }
        map_iterator(const map_iterator& other): node(other.base())
        {

        }

        map_iterator& operator=(const map_iterator& other)
        {
            this->node = other.base();
            return (*this);
        }

        map_iterator& operator++()
        {

        }

        Node* base()
        {
            return (node);
        }

    private:
        Node*   node;
};
#endif