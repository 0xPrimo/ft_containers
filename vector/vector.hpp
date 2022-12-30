#ifndef _VECTOR_
# define _VECTOR_

# include <memory>
# include "vector_iterator.hpp"
namespace ft {

template <
    typename T,
    typename Allocator = std::allocator<T>
> class vector
{
    
    public:

        ////////////////////////////////////////////////////////////////////
        //                         Member types                           //
        ////////////////////////////////////////////////////////////////////

        typedef     Allocator                               allocator_type;
        typedef     typename Allocator::value_type          value_type;
        typedef     typename Allocator::pointer             pointer;
        typedef     typename Allocator::const_pointer       const_pointer;
        typedef     typename Allocator::reference           reference;
        typedef     typename Allocator::const_reference     const_reference;
        typedef     typename Allocator::size_type           size_type;
        typedef     typename Allocator::difference_type     difference_type;

        /// Iterators
        typedef     VectorIterator<value_type>              iterator;
        typedef     const VectorIterator<value_type>        const_iterator;

        ////////////////////////////////////////////////////////////////////
        //                         Constructors                           //
        ////////////////////////////////////////////////////////////////////
        vector(const allocator_type& alloc = allocator_type()): m_ReservedBlocks(0), m_Size(0), m_Data(NULL) {}

        vector(size_type n, const value_type &val = value_type()): m_ReservedBlocks(n), m_Size(n)
        {
            m_Data = m_Allocator.allocate(m_Size);
            
            for(int i = 0 ; i < m_Size; i++)
                m_Allocator.construct(m_Data + i, val);
        }

        // template <class InputIterator>
        // vecotr (InputIterator first, InputIterator last)
        // {
        //     while (first != last)
        //     {
        //         // push back elements
        //     }
        // }

        vector(const vector &other): m_ReservedBlocks(other.m_Size), m_Size(other.m_Size), m_Allocator(other.allocator)
        {
            m_Data = m_Allocator.allocate(other.m_Size);

            for(int i = 0; i < other.m_Size; i++)
                m_Allocator.construct(m_Data + i, other.m_Data[i]);
        }

        ////////////////////////////////////////////////////////////////////
        //                          Destructors                           //
        ////////////////////////////////////////////////////////////////////


        ////////////////////////////////////////////////////////////////////
        //                        Iterators Methods                       //
        ////////////////////////////////////////////////////////////////////
        iterator begin()
        {
            return (iterator(m_Data));
        }

        iterator end()
        {
            return (iterator(m_Data + m_Size));
        }

        ////////////////////////////////////////////////////////////////////
        //                          Vector Methods                        //
        ////////////////////////////////////////////////////////////////////

        void    push_back(const_reference other)
        {
            pointer ptr;

            
            ptr = m_Allocator.allocate(m_Size + 20);
        }

    private:
        size_type   m_ReservedBlocks;
        size_type   m_Size;
        pointer     m_Data;
        Allocator   m_Allocator;
};

}
#endif