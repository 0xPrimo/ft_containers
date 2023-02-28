#ifndef __REVERSE_ITERATOR__
# define __REVERSE_ITERATOR__

# include "vector_iterator_traits.hpp"

namespace ft
{
    template <class iter>
    
    class reverse_iterator
    {
        public:

            typedef          iter                                                   iterator_type;
            typedef typename ft::iterator_traits<iter>::value_type                  value_type;
            typedef typename ft::iterator_traits<iter>::difference_type             difference_type;
            typedef typename ft::iterator_traits<iter>::pointer                     pointer;
            typedef typename ft::iterator_traits<iter>::reference                   reference;
            typedef typename ft::iterator_traits<iter>::iterator_category           iterator_category;

        public:
            
            reverse_iterator(): m_Iterator()
            {
            }

            reverse_iterator(iterator_type it) : m_Iterator(it)
            {

            }

            reverse_iterator(const reverse_iterator &ritr): m_Iterator(ritr.base())
            {

            }

            template <class U>
            reverse_iterator(const reverse_iterator<U> &ritr): m_Iterator(ritr.base())
            {
            }

            iterator_type base() const
            {
                return (m_Iterator);
            }

            reference operator*() const
            {
                iterator_type tmp(m_Iterator);
                
                return (*(--tmp));
            }

            pointer operator->() const
            {
                iterator_type tmp(m_Iterator);

                return (&(*--tmp));
            }

            reference operator[](difference_type n) const
            {
                return (*(m_Iterator - n - 1));
            }

            reverse_iterator& operator++()
            {
                m_Iterator--;
                return (*this);
            }

            reverse_iterator operator++(int)
            {
                reverse_iterator tmp(m_Iterator);
                m_Iterator--;
                return (tmp);
            }

            reverse_iterator& operator--()
            {
                m_Iterator++;
                return (*this);
            }

            reverse_iterator operator--(int)
            {
                reverse_iterator tmp(m_Iterator);
                m_Iterator++;
                return (tmp);
            }

            reverse_iterator operator+(difference_type n) const
            {
                return (reverse_iterator(m_Iterator - n));
            }

            reverse_iterator operator-(difference_type n) const
            {
                return (reverse_iterator(m_Iterator + n));
            }
        
            template <class it>
            difference_type operator-(const reverse_iterator<it> &rit) const
            {
                return (rit.m_Iterator - this->m_Iterator);
            }

            reverse_iterator& operator+=(difference_type n)
            {
                m_Iterator -= n;
                return (*this);
            }

            reverse_iterator& operator-=(difference_type n)
            {
                m_Iterator += n;
                return (*this);
            }

        private:
            iter m_Iterator;

    };

    template <class it>
    reverse_iterator<it> operator+( int n,
                                    const reverse_iterator<it> &rit )
    {
        return (rit + n);
    }

    template <class it>
    reverse_iterator<it> operator-( int n,
                                    const reverse_iterator<it> &rit )
    {
        return (rit - n);
    }

    template<class it1, class it2>
    bool operator==(const ft::reverse_iterator<it1> &lhs,
                     const ft::reverse_iterator<it2> &rhs)
    {
        return (lhs.base() == rhs.base());
    }
    
    template<class it1, class it2>
    bool operator!=(const ft::reverse_iterator<it1> &lhs,
                     const ft::reverse_iterator<it2> &rhs)
    {
        return (lhs.base() != rhs.base());
    }
    
    template<class it1, class it2>
    bool operator>(const ft::reverse_iterator<it1> &lhs,
                     const ft::reverse_iterator<it2> &rhs)
    {
        return (lhs.base() < rhs.base());
    }
    
    template<class it1, class it2>
    bool operator>=(const ft::reverse_iterator<it1> &lhs,
                     const ft::reverse_iterator<it2> &rhs)
    {
        return (lhs.base() <= rhs.base());
    }
    
    template<class it1, class it2>
    bool operator<(const ft::reverse_iterator<it1> &lhs,
                     const ft::reverse_iterator<it2> &rhs)
    {
        return (lhs.base() > rhs.base());
    }

    template<class it1, class it2>
    bool operator<=(const ft::reverse_iterator<it1> &lhs,
                     const ft::reverse_iterator<it2> &rhs)
    {
        return (lhs.base() >= rhs.base());
    }
}
#endif