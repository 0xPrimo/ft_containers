#ifndef _VECTOR_ITERATOR_
# define _VECTOR_ITERATOR_

# include "vector.hpp"
# include "vector_iterator_traits.hpp"
namespace ft
{
    template <
                class Category,
                class T,
                class Distance = std::ptrdiff_t,
                class Pointer = T*,
                class Reference = T&            
    > class Iterator
    {
        public:

            typedef T           value_type;
            typedef Distance    difference_type;
            typedef Pointer     pointer;
            typedef Reference   reference;
            typedef Category    category_type;

        public:
            
            Iterator(pointer Ptr)
            {
                m_Ptr = Ptr;
            }

            Iterator& operator=(const Iterator& other)
            {
                other.m_Ptr = m_Ptr;
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
            
            
            Iterator& operator--(int)
            {
                m_Ptr--;
                return (*this);
            }

            Iterator operator--()
            {
                Iterator tmp = *this;
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
                // if (index < 0){
                //     // throw exception
                // }
                return (*(m_Ptr + index));
            }

            bool operator!=(const Iterator& other)
            {
                if (other.m_Ptr != m_Ptr)
                    return (true);
                return (false);
            }

            bool operator==(const Iterator& other)
            {
                if (other.m_Ptr == m_Ptr)
                    return (true);
                return (false);
            }
            
            bool operator>(const Iterator& other)
            {
                if (other.m_Ptr > m_Ptr)
                    return (true);
                return (false);
            }

            bool operator>=(const Iterator& other)
            {
                if (other.m_Ptr >= m_Ptr)
                    return (true);
                return (false);
            }

            bool operator<(const Iterator& other)
            {
                if (other.m_Ptr < m_Ptr)
                    return (true);
                return (false);
            }

            bool operator<=(const Iterator& other)
            {
                if (other.m_Ptr <= m_Ptr)
                    return (true);
                return (false);
            }

        private:
            pointer     m_Ptr;

    };
}
#endif