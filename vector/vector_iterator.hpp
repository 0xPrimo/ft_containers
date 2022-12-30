#ifndef _VECTOR_ITERATOR_
# define _VECTOR_ITERATOR_

# include "vector.hpp"
# include "vector_iterator_traits.hpp"
template <class T>

class VectorIterator
{
    public:
        typedef ft::iterator_traits<T>::value_type          value_type;
        typedef ft::iterator_traits<T>::pointer             pointer;
        typedef ft::iterator_traits<T>::reference           reference;
        typedef const ft::iterator_traits<T>::reference     const_reference;

        typedef T                   value_type;
        typedef T*                  pointer;
        typedef T&                  reference;
        typedef T const&            const_reference;

    public:
        VectorIterator(): m_Ptr(NULL) {};
        VectorIterator(pointer ptr): m_Ptr(ptr){}
        
        VectorIterator& operator=(const VectorIterator& other)
        {
            other.m_Ptr = m_Ptr;
            return (*this);
        }

        VectorIterator& operator++(int)
        {
            m_Ptr++;
            return(*this);
        }

        VectorIterator operator++()
        {
            VectorIterator tmp = *this;
            m_Ptr++;
            return (tmp);
        }       
        
        
        VectorIterator& operator--(int)
        {
            m_Ptr--;
            return (*this);
        }

        VectorIterator operator--()
        {
            VectorIterator tmp = *this;
            m_Ptr--;
            return (tmp);
        }

        pointer operator->()
        {
            return (m_Ptr);
        }

        reference operator*()
        {
            return (*m_Ptr);
        }

        reference operator[](int index)
        {
            if (index < 0){
                // throw exception
            }
            return (*(m_Ptr + index));
        }

        bool operator!=(const VectorIterator& other)
        {
            if (other.m_Ptr != m_Ptr)
                return (true);
            return (false);
        }

        bool operator==(const VectorIterator& other)
        {
            if (other.m_Ptr == m_Ptr)
                return (true);
            return (false);
        }
        
        bool operator>(const VectorIterator& other)
        {
            if (other.m_Ptr > m_Ptr)
                return (true);
            return (false);
        }

        bool operator>=(const VectorIterator& other)
        {
            if (other.m_Ptr >= m_Ptr)
                return (true);
            return (false);
        }

        bool operator<(const VectorIterator& other)
        {
            if (other.m_Ptr < m_Ptr)
                return (true);
            return (false);
        }

        bool operator<=(const VectorIterator& other)
        {
            if (other.m_Ptr <= m_Ptr)
                return (true);
            return (false);
        }

    private:
        pointer     m_Ptr;

};

#endif