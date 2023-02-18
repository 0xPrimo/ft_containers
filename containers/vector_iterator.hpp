#ifndef _VECTOR_ITERATOR_
# define _VECTOR_ITERATOR_

# include "vector_iterator_traits.hpp"
namespace ft
{
    template <class T>
    class Iterator
    {
        public:

            typedef typename ft::iterator_traits<T>::value_type                  value_type;
            typedef typename ft::iterator_traits<T>::difference_type             difference_type;
            typedef typename ft::iterator_traits<T>::pointer                     pointer;
            typedef typename ft::iterator_traits<T>::reference                   reference;
            typedef typename ft::iterator_traits<T>::iterator_category           iterator_category;

        public:
            
            Iterator(pointer Ptr = nullptr)
            {
                m_Ptr = Ptr;
            }

            template <class type>
            Iterator(const Iterator<type> &other): m_Ptr(other.base()) {}

            T base() const
            {
                return (m_Ptr);
            }

            Iterator& operator=(const Iterator& other)
            {
                m_Ptr = other.base();
                return (*this);
            }

            Iterator& operator++()
            {
                m_Ptr++;
                return(*this);
            }

            Iterator operator++(int)
            {
                Iterator tmp = *this;
                m_Ptr++;
                return (tmp);
            }

            Iterator& operator--()
            {
                m_Ptr--;
                return (*this);
            }

            Iterator operator--(int)
            {
                Iterator tmp = *this;
                m_Ptr--;
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
                return (*(m_Ptr + index));
            }

            Iterator operator+(difference_type n) const
            {
                return (Iterator(m_Ptr + n));
            }

            Iterator operator-(difference_type n) const
            {
                return (Iterator(m_Ptr - n));
            }

            difference_type operator-(const Iterator &other) const
            {
                return (this->m_Ptr - other.m_Ptr);
            }

            Iterator &operator+=(difference_type n)
            {
                this->m_Ptr += n;              
                return (*this);
            }

            Iterator &operator-=(difference_type n)
            {
                this->m_Ptr -= n;
                return (*this);
            }

        private:
            pointer     m_Ptr;

    };

    template <class it>
    Iterator<it> operator-(int n, const Iterator<it> &other)
    {
        Iterator<it> tmp(other);

        tmp -= n;

        return (tmp);
    }

    template <class it>
    Iterator<it> operator+(int n, const Iterator<it> &other)
    {
        Iterator<it> tmp(other);

        tmp += n;

        return (tmp);
    }

    template <class it1, class it2>
    bool operator==(const ft::Iterator<it1> &iter1, const ft::Iterator<it2> &iter2)
    {
        if (iter1.base() == iter2.base())
            return (true);
        return (false);
    }

    template <class it1, class it2>
    bool operator!=(const ft::Iterator<it1> &iter1, const ft::Iterator<it2> &iter2)
    {
        if (iter1.base() != iter2.base())
            return (true);
        return (false);
    }

    template <class it1, class it2>
    bool operator<(const ft::Iterator<it1> &iter1, const ft::Iterator<it2> &iter2)
    {
        if (iter1.base() < iter2.base())
            return (true);
        return (false);
    }

    template <class it1, class it2>
    bool operator<=(const ft::Iterator<it1> &iter1, const ft::Iterator<it2> &iter2)
    {
        if (iter1.base() <= iter2.base())
            return (true);
        return (false);
    }

    template <class it1, class it2>
    bool operator>(const ft::Iterator<it1> &iter1, const ft::Iterator<it2> &iter2)
    {
        if (iter1.base() > iter2.base())
            return (true);
        return (false);
    }

    template <class it1, class it2>
    bool operator>=(const ft::Iterator<it1> &iter1, const ft::Iterator<it2> &iter2)
    {
        if (iter1.base() >= iter2.base())
            return (true);
        return (false);
    }

}
#endif