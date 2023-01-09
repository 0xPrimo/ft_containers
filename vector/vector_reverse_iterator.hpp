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
            
            reverse_iterator()
            {

                std::cout << "true" << std::endl;
            }

            reverse_iterator(int i)
            {

                std::cout << "true ii" << std::endl;
            }
            
            
            reverse_iterator(iterator_type &itr)
            {
            }

            // reverse_iterator(reverse_iterator &ritr)
            // {
            //     m_Iterator.base() = ritr.base();
            // }

            // iterator_type base() const
            // {
            //     return (m_Iterator);
            // }


            // reference operator*() const
            // {
            //     return (*m_Iterator);
            // }

            // // pointer opeartor->() const
            // // {
            // //     return (m_Iteartor->);
            // // }

            // reference operator[](difference_type n) const
            // {
            //     return (m_Iterator[n]);
            // }

            // reverse_iterator& operator++()
            // {
            //     m_Iterator--;
            //     return (*this);
            // }

            // reverse_iterator operator++(int)
            // {
            //     reverse_iterator tmp(m_Iterator);
            //     m_Iterator--;
            //     return (tmp);
            // }

            // reverse_iterator& operator--()
            // {
            //     m_Iterator++;
            //     return (*this);
            // }

            // reverse_iterator operator--(int)
            // {
            //     reverse_iterator tmp(m_Iterator);
            //     m_Iterator++;
            //     return (tmp);
            // }

            // reverse_iterator operator+(difference_type n) const
            // {
            //     return (reverse_iterator(m_Iterator + n));
            // }

            // reverse_iterator operator-(difference_type n) const
            // {
            //     return (reverse_iterator(m_Iterator - n));
            // }

            // reverse_iterator& operator+=(difference_type n)
            // {
            //     m_Iterator += n;
            //     return (*this);
            // }

            // reverse_iterator& operator-=(difference_type n)
            // {
            //     m_Iterator -= n;
            //     return (*this);
            // }

            // template<class Iterator1, class Iterator2>
            // friend bool operator==( ft::reverse_iterator<Iterator1> &lhs,
            //                  ft::reverse_iterator<Iterator2> &rhs)
            // {
            //     return (lhs.base() == rhs.base());
            // }

            // template<class Iterator1, class Iterator2>
            // friend bool operator!=( ft::reverse_iterator<Iterator1> &lhs,
            //                  ft::reverse_iterator<Iterator2> &rhs)
            // {
            //     return (lhs.base() != rhs.base());
            // }

            // template<class Iterator1, class Iterator2>
            // friend bool operator!=( ft::reverse_iterator<Iterator1> &lhs,
            //                  ft::reverse_iterator<Iterator2> &rhs)
            // {
            //     return (lhs.base() > rhs.base());
            // }

            // template<class Iterator1, class Iterator2>
            // friend bool operator!=( ft::reverse_iterator<Iterator1> &lhs,
            //                  ft::reverse_iterator<Iterator2> &rhs)
            // {
            //     return (lhs.base() >= rhs.base());
            // }

            // template<class Iterator1, class Iterator2>
            // friend bool operator!=( ft::reverse_iterator<Iterator1> &lhs,
            //                  ft::reverse_iterator<Iterator2> &rhs)
            // {
            //     return (lhs.base() < rhs.base());
            // }

            // template<class Iterator1, class Iterator2>
            // friend bool operator!=( ft::reverse_iterator<Iterator1> &lhs,
            //                  ft::reverse_iterator<Iterator2> &rhs)
            // {
            //     return (lhs.base() <= rhs.base());
            // }
        private:
            iterator_type m_Iterator;

    };
}
#endif