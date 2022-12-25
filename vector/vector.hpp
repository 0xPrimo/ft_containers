#ifndef _VECTOR_
# define _VECTOR_

# include <memory>
# include "vector_iterator.hpp"

template <
    typename T,
    typename Allocator = std::allocator<T>
> class vector
{
    
    public:
        typedef     typename Allocator::value_type          value_type;
        typedef     typename Allocator::pointer             pointer;
        typedef     typename Allocator::const_pointer       const_pointer;
        typedef     typename Allocator::reference           reference;
        typedef     typename Allocator::const_reference     const_reference;
        typedef     typename Allocator::size_type           size_type;
        typedef     typename Allocator::difference_type     difference_type;

        typedef     typename VectorIterator<T>              Iterator;

        vector(): _size(0), m_Data(NULL) {}

        vector(size_type n, const value_type &val = value_type()): _size(n) {
            m_Data = allocator.allocate(_size);
            
            for(int i = 0 ; i < _size; i++)
                allocator.construct(m_Data + i, val);
        }

        vector(const vector &x): _size(x._size), allocator(x.allocator) {
            m_Data = allocator.allocate(x._size);

            for(int i = 0; i < x._size; i++)
                allocator.construct(m_Data + i, x.m_Data[i]);

        }

        Iterator& begin()
        {
            return (Iterator(m_Data));
        }

        Iterator& end()
        {
            return (Iterator(m_Data + m_Size));
        }


    private:
        size_type   m_Size;
        pointer     m_Data;
        Allocator   m_Allocator;
};

#endif