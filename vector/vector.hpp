#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include "vector_iterator.hpp"
# include "vector_reverse_iterator.hpp"

namespace ft {

template <
            class T,
            class Allocator = std::allocator<T>
>

class vector
{
    
    public:

        ////////////////////////////////////////////////////////////////////
        //                         Member types                           //
        ////////////////////////////////////////////////////////////////////

        typedef     Allocator                                   allocator_type;
        typedef     typename Allocator::value_type              value_type;
        typedef     typename Allocator::pointer                 pointer;
        typedef     typename Allocator::const_pointer           const_pointer;
        typedef     typename Allocator::reference               reference;
        typedef     typename Allocator::const_reference         const_reference;
        typedef     typename Allocator::size_type               size_type;
        typedef     typename Allocator::difference_type         difference_type;


        typedef     ft::Iterator<T*>                            iterator;
        typedef     ft::Iterator<const T*>                      const_iterator;
        typedef     ft::reverse_iterator<T*>                    reverse_iterator;
        typedef     ft::reverse_iterator<const T*>              const_reverse_iterator;

        ////////////////////////////////////////////////////////////////////
        //                        Member functions                        //
        ////////////////////////////////////////////////////////////////////
        /* Default constructor */
        vector(const allocator_type& alloc = allocator_type()):     m_Size(0),
                                                                    m_Capacity(0),
                                                                    m_Data(nullptr)
        {

        }

        /* Size constructor */
        vector(size_type n, const value_type &val = value_type()):  m_Size(n),
                                                                    m_Capacity(n)
        {
            m_Data = m_Allocator.allocate(m_Size);

            for(int i = 0 ; i < n; i++)
                m_Allocator.construct(m_Data + i, val);
        }

        /* Iterator constructor */
        // template <class InputIterator>
        // vector (InputIterator first, InputIterator last)
        // {
        //     while (first != last)
        //     {
        //         // push back elements
        //     }
        // } 

        /* Copy Constructor */
        vector(const vector &other):    m_Size(other.m_Size),
                                        m_Capacity(other.m_Capacity),
                                        m_Allocator(other.allocator)
        {
            m_Data = m_Allocator.allocate(other.m_Size);

            for(int i = 0; i < other.m_Size; i++)
                m_Allocator.construct(m_Data + i, other.m_Data[i]);
        }

        /* Destructor */
        ~vector()
        {

        }

        /* Assigns values to the container */
        vector& operator=(const vector &other)
        {
            this->m_Ptr = other.Ptr;
        }

        /* Assigns values to the container */
        void    assign(size_type count, const T& value)
        {
            if (count > m_Capacity)
                reserve(count);
            m_Size = count;
            for(int i = 0; i < count; i++)
                m_Data[i] = value;
        }


        /* Returns the allocator associated with the container */
        allocator_type get_allocator() const
        {
            return (m_Allocator);
        }

        ////////////////////////////////////////////////////////////////////
        //                          Element access                        //
        ////////////////////////////////////////////////////////////////////
        /* Access specified element */
        reference at(size_type pos)
        {
            if (pos >= m_Size)
                std::out_of_range("vector");
            return (*(m_Data + pos));
        }

        const_reference at(size_type pos) const
        {
            if (pos >= m_Size)
                std::out_of_range("vector");
            return (*(m_Data + pos));
        }

        reference operator[](size_type pos)
        {
            if (pos >= m_Size)
                std::out_of_range("vector");
            return (*(m_Data + pos));
        }

        const_reference operator[](size_type pos) const
        {
            if (pos >= m_Size)
                std::out_of_range("vector");
            return (*(m_Data + pos));
        }

        /* Access the first element */
        reference front()
        {
            return (*m_Data);
        }

        const_reference front() const
        {
            return (*m_Data);
        }

        /* Access the last element */
        reference back()
        {
            return (*(m_Data + m_Size));
        }

        reference back() const
        {
            return (*(m_Data + m_Size));
        }
        
        pointer data()
        {
            return (m_Data);
        }

        const_pointer data() const
        {
            return (m_Data);
        }
        ////////////////////////////////////////////////////////////////////
        //                            Iterators                           //
        ////////////////////////////////////////////////////////////////////

        /* Return iterator pointing to the first element */
        iterator begin()
        {
            return (iterator(m_Data));
        }

        /* Return iterator pointing to the last elemnt */
        iterator end()
        {
            return (iterator(m_Data + m_Size));
        }

        ////////////////////////////////////////////////////////////////////
        //                            Capacity                            //
        ////////////////////////////////////////////////////////////////////
        /* Checks whether the container is empty */
        bool empty() const
        {
            if (m_Size == 0)
                return (true);
            else
                return (false);
        }
        /* Returns the number of elements */
        size_type size() const
        {
            return (m_Size);
        }

        /* Returns the maximum possible number of elements */
        size_type max_size() const
        {
            return (m_Allocator.max_size());
        }

        /* Increase the capacity of the container */
        void reserve(size_type new_cap)
        {
            std::cout << "somthing " << m_Size << std::endl;
            if (new_cap > m_Allocator.max_size())
                throw std::length_error("vector");
            if (new_cap > m_Capacity)
            {
                pointer ptr = m_Data;
                m_Data = m_Allocator.allocate(new_cap);
                for(int i = 0; i < m_Size; i++)
                    m_Allocator.construct(m_Data + i, ptr[i]);
                for(int i = 0; i < m_Size; i++)
                    m_Allocator.destroy(ptr + i);
                m_Allocator.deallocate(ptr, m_Size);
                m_Capacity = new_cap;
            }
        }

        /* The capacity of the currently allocated storage */
        size_type capacity() const
        {
            return (m_Capacity);
        }

        ////////////////////////////////////////////////////////////////////
        //                            Modifiers                           //
        ////////////////////////////////////////////////////////////////////
        /**/

        ////////////////////////////////////////////////////////////////////
        //                        Non-member functions                    //
        ////////////////////////////////////////////////////////////////////
        /**/


    private:
        size_type   m_Size;
        size_type   m_Capacity;
        pointer     m_Data;
        Allocator   m_Allocator;
};

}
#endif