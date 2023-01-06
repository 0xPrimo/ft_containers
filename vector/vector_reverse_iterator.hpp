#ifndef __REVERSE_ITERATOR__
# define __REVERSE_ITERATOR__

# include "vector_iterator_traits.hpp"
namespace ft
{
    template <class T> class reverse_iterator
    {
        public:

            typedef typename ft::iterator_traits<T>::value_type                  value_type;
            typedef typename ft::iterator_traits<T>::difference_type             difference_type;
            typedef typename ft::iterator_traits<T>::pointer                     pointer;
            typedef typename ft::iterator_traits<T>::reference                   reference;
            typedef typename ft::iterator_traits<T>::iterator_category           iterator_category;

        public:
            
            reverse_iterator(pointer Ptr = nullptr)
            {
                m_Ptr = Ptr;
            }

            template <class type>
            reverse_iterator(const reverse_iterator<type> &other): m_Ptr(other.base()) {}

            T base() const
            {
                return (m_Ptr);
            }

            reverse_iterator& operator=(const reverse_iterator& other)
            {
                m_Ptr = other.base();
                return (*this);
            }

            reverse_iterator& operator++()
            {
                m_Ptr--;
                return(*this);
            }

            reverse_iterator operator++(int)
            {
                reverse_iterator tmp = *this;
                m_Ptr--;
                return (tmp);
            }

            reverse_iterator operator--(int)
            {
                m_Ptr++;
                return (*this);
            }

            reverse_iterator& operator--()
            {
                reverse_iterator tmp = *this;
                m_Ptr++;
                return (tmp);
            }

            pointer operator->() const
            {
                return (m_Ptr);
            }

            reference operator*() const
            {
                return (*m_Ptr);
            }

            reference operator[](int index) const
            {
                // if (index < 0){
                //     // throw exception
                // }
                return (*(m_Ptr + index));
            }

            template <class cmp_type>
            bool operator!=(const reverse_iterator<cmp_type>& other) const
            {
                if (other.base() != m_Ptr)
                    return (true);
                return (false);
            }

            template <class cmp_type>
            bool operator==(const reverse_iterator<cmp_type>& other) const
            {
                if (other.base() == m_Ptr)
                    return (true);
                return (false);
            }

            template <class cmp_type>            
            bool operator>(const reverse_iterator<cmp_type>& other) const
            {
                if (other.base() > m_Ptr)
                    return (true);
                return (false);
            }

            template <class cmp_type>
            bool operator>=(const reverse_iterator<cmp_type>& other) const
            {
                if (other.base() >= m_Ptr)
                    return (true);
                return (false);
            }

            template <class cmp_type>
            bool operator<(const reverse_iterator<cmp_type>& other) const
            {
                if (other.base() < m_Ptr)
                    return (true);
                return (false);
            }

            template <class cmp_type>
            bool operator<=(const reverse_iterator<cmp_type>& other) const
            {
                if (other.base() <= m_Ptr)
                    return (true);
                return (false);
            }

            reverse_iterator operator+(difference_type n) const
            {
                return (reverse_iterator(m_Ptr + n));
            }

            reverse_iterator operator-(difference_type n) const
            {
                return (reverse_iterator(m_Ptr - n));
            }

            reverse_iterator operator+=(difference_type n) const
            {
                return (reverse_iterator(m_Ptr + n));
            }

            reverse_iterator operator-=(difference_type n) const
            {
                return (reverse_iterator(m_Ptr - n));
            }

        private:
            pointer     m_Ptr;

    };
}
#endif