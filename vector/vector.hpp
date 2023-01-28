#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <cstring>
# include "vector_iterator.hpp"
# include "vector_reverse_iterator.hpp"
# include "../utils/enable_if.hpp"
# include "../utils/is_integral.hpp"
# include "../utils/lexicographical_compare.hpp"

namespace ft {

template < class T, class Allocator = std::allocator<T> >

class vector
{
    public:

        ////////////////////////////////////////////////////////////////////
        //                         Member types                           //
        ////////////////////////////////////////////////////////////////////

        typedef     typename Allocator::value_type              value_type;
        typedef     Allocator                                   allocator_type;
        typedef     typename Allocator::size_type               size_type;
        typedef     typename Allocator::difference_type         difference_type;
        typedef     typename Allocator::reference               reference;
        typedef     typename Allocator::const_reference         const_reference;
        typedef     typename Allocator::pointer                 pointer;
        typedef     typename Allocator::const_pointer           const_pointer;


        typedef     ft::Iterator<pointer>                       iterator;
        typedef     ft::Iterator<const_pointer>                 const_iterator;
        typedef     ft::reverse_iterator<iterator>              reverse_iterator;
        typedef     ft::reverse_iterator<const_iterator>        const_reverse_iterator;
    private:
        void destroy(pointer ptr, size_type size)
        {
            for(size_type i = 0; i < size; i++)
                m_Allocator.destroy(ptr + i);
        }

        void construct(pointer ptr, size_type size, value_type value)
        {
            for(size_type i = 0; i < size; i++)
                m_Allocator.construct(ptr + i, value);
        }

        template <class it>
        difference_type m_Distance(it first, it last)
        {
            difference_type i = 0;

            for(; first != last; first++)
                i++;
            return i;
        }


    public:
        ////////////////////////////////////////////////////////////////////
        //                        Member functions                        //
        ////////////////////////////////////////////////////////////////////
        /* Default constructor */
        vector(const allocator_type& alloc = allocator_type()):     m_Size(0),
                                                                    m_Capacity(0),
                                                                    m_Data(nullptr),
                                                                    m_Allocator(alloc)
        {
        }

        /* Size constructor */
        vector(size_type n, const value_type &val = value_type()):  m_Size(n),
                                                                    m_Capacity(n)
        {
            m_Data = m_Allocator.allocate(m_Size);

            for(size_type i = 0 ; i < n; i++)
                m_Allocator.construct(m_Data + i, val);
        }

        /* Iterator constructor */
        template <class InputIterator>
        vector (InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
            typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0): 
            m_Size(0),
            m_Capacity(0),
            m_Data(NULL),
            m_Allocator(alloc)
        {

            size_type distance = &*last - &*first;
            size_type i = 0;

            reserve(distance);

            while (first != last)
            {
                m_Allocator.construct(m_Data + i, *first);
                first++;
                i++;
            }
            m_Size = distance;
        }

        /* Copy Constructor */
        vector(const vector &other):    m_Size(other.m_Size),
                                        m_Capacity(other.m_Capacity),
                                        m_Allocator(other.m_Allocator)
        {
            m_Data = m_Allocator.allocate(other.m_Capacity);
            for(size_type i = 0; i < other.m_Size; i++)
                m_Allocator.construct(m_Data + i, other.m_Data[i]);
        }

        /* Destructor */
        ~vector()
        {
            for(size_type i = 0; i < m_Size; i++)
                m_Allocator.destroy(m_Data + i);
            if (m_Capacity)
                m_Allocator.deallocate(m_Data, m_Capacity);
        }

        /* Assigns values to the container */
        vector& operator=(const vector &other)
        {
            clear();
            if (other.m_Size > this->m_Capacity)
                reserve(other.m_Size);
            for(size_type i = 0; i < other.m_Size; i++)
                m_Allocator.construct(m_Data + i, other.m_Data[i]);
            m_Size = other.m_Size;
            return (*this);
        }

        /* Assigns values to the container */
        void    assign(size_type count, const T& value)
        {
            if (count > m_Allocator.max_size())
                throw std::length_error("vector");


            destroy(m_Data, m_Size);
            if (count > m_Capacity)
            {
                if (m_Capacity)
                    m_Allocator.deallocate(m_Data, m_Capacity);
                m_Data = m_Allocator.allocate(count);
                m_Capacity = count;
            }
            construct(m_Data, count, value);
            m_Size = count;
        }

        template< class InputIt >
        void assign( InputIt first, InputIt last,
                typename ft::enable_if<!is_integral<InputIt>::value, InputIt>::type* = 0)
        {
            InputIt _first(first), _last(last);
            size_type size = m_Distance(_first, _last);

            clear();
            if (size > m_Capacity)
                reserve(size);
            for(size_type i = 0; first != last; first++)
            {
                m_Allocator.construct(m_Data + i, *first);
                i++;
            }
            m_Size = size;
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
                throw std::out_of_range("vector");
            return (*(m_Data + pos));
        }

        const_reference at(size_type pos) const
        {
            if (pos >= m_Size)
                throw std::out_of_range("vector");
            return (*(m_Data + pos));
        }
    
        reference operator[](size_type pos)
        {
            if (pos >= m_Size)
                throw std::out_of_range("vector");
            return (*(m_Data + pos));
        }

        const_reference operator[](size_type pos) const
        {
            if (pos >= m_Size)
                throw std::out_of_range("vector");
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
            return (*(m_Data + (m_Size - 1)));
        }

        reference back() const
        {
            return (*(m_Data + (m_Size - 1)));
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

        const_iterator begin() const
        {
            return (const_iterator(m_Data));
        }

        /* Return iterator pointing to the last elemnt */
        iterator end()
        {
            return (iterator(m_Data + m_Size));
        }

        const_iterator end() const
        {
            return (const_iterator(m_Data + m_Size));
        }
        
        /* Reverse iterator */
        reverse_iterator rbegin()
        {
            return(reverse_iterator(iterator(m_Data + m_Size)));
        }

        const_reverse_iterator rbegin() const
        {
            return (const_reverse_iterator(iterator(m_Data + m_Size)));
        }

        reverse_iterator rend()
        {
            return (reverse_iterator(iterator(m_Data)));
        }

        const_reverse_iterator rend() const
        {
            return (const_reverse_iterator(iterator(m_Data)));
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
            if (new_cap > m_Allocator.max_size())
                throw std::length_error("vector");
            if (new_cap > m_Capacity)
            {
                pointer ptr = m_Data;
                m_Data = m_Allocator.allocate(new_cap);
                for(size_type i = 0; i < m_Size && m_Capacity; i++)
                    m_Allocator.construct(m_Data + i, ptr[i]);
                for(size_type i = 0; i < m_Size && m_Capacity; i++)
                    m_Allocator.destroy(ptr + i);
                if (m_Capacity)
                    m_Allocator.deallocate(ptr, m_Capacity);
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
        /* destroy all the elements of the container */
        void clear()
        {
            destroy(m_Data, m_Size);
            m_Size = 0;
        }

        /* insert */
        iterator insert(const_iterator pos, const T& value)
        {
            size_type empty_size = capacity() - size();
            size_type index = &(*pos) - m_Data;

            /* check if there is empty place */
            if (empty_size == 0)
            {
                size_type new_cap = (m_Capacity * 2 > 0) ? m_Capacity * 2 : 1;
                reserve(new_cap);
            }
            
            m_Size++;
            // shift the array by 1
            for(size_type i = m_Size; i > index; i--)
            {
                m_Allocator.construct(m_Data + i, m_Data[i - 1]);
                m_Allocator.destroy(m_Data + i - 1);
            }
            m_Allocator.construct(m_Data + index, value);
            return (iterator(m_Data + index));
        }

        iterator insert(const_iterator pos, size_type count, const T& value)
        {
            size_type empty_size = capacity() - size();
            size_type index = &(*pos) - m_Data;

            /* check if there is empty place */
            if (empty_size == 0)
                reserve(m_Size + count);

            m_Size += count;
            // shift the array by the count
            for(size_type i = m_Size; i > index; i--)
            {
                m_Allocator.construct(m_Data + i, m_Data[i - count]);
                m_Allocator.destroy(m_Data + i - count);
            }
            for(size_type i = index; i < index + count; i++)
                m_Allocator.construct(m_Data + i, value);
            return (iterator(m_Data + index));
        }

        template< class InputIt>
        iterator insert(const_iterator pos, InputIt first, InputIt last)
        {
        
            size_type empty_size = capacity() - size();
            size_type index = &(*pos) - m_Data;
            size_type count = last - first;

            /* check if there is empty place */
            if (empty_size == 0)
                reserve(m_Capacity * 2);

            m_Size += count;
            
            // shift the array by the count
            for(size_type i = m_Size; i > index; i--)
            {
                m_Allocator.construct(m_Data + i, m_Data[i - count]);
                m_Allocator.destroy(m_Data + i - count);
            }
            for(size_type i = index; first != last; first++)
            {
                m_Allocator.construct(m_Data + i, *first);
                i++;
            }
            return (iterator(m_Data + index));

        
        }
        /* push back */
        void push_back(const T& value)
        {
            if (!m_Size)
                reserve(1);
            if (m_Size == m_Capacity)
                reserve(m_Capacity * 2);
            m_Allocator.construct(m_Data + m_Size, value);
            m_Size++;
        }
    
        /* resize */
        void resize(size_type count, T value = T())
        {
            if (count < m_Size)
            {
                for(size_type i = count; i < m_Size; i++)
                    m_Allocator.destroy(m_Data + i);
                m_Size = count;
            }
            else
            {
                if (count > m_Capacity)
                    reserve(m_Capacity * 2);
                
                for(size_type i = m_Size; i < (m_Size + count - m_Size); i++)
                    m_Allocator.construct(m_Data + i, value);
                m_Size = count;
            }
        }

        /* pop back */
        void pop_back()
        {
            m_Allocator.destroy(m_Data + m_Size);
            m_Size--;
        }

        /* erase */
        iterator erase(iterator pos)
        {
            size_type index = &*pos - m_Data;

            m_Allocator.destroy(m_Data + index);
            for(size_type i = index; i < m_Size; i++)
            {
                m_Allocator.construct(m_Data + i, m_Data[i + 1]);
                m_Allocator.destroy(m_Data + i + 1);
            }
            m_Size--;
            return (iterator(m_Data + index));
        }

        iterator erase(iterator first, iterator last)
        {
            size_type   start_index = &*first - m_Data;
            size_type   end_index = &*last - m_Data;
    
            for(; first != last; first++)
                m_Allocator.destroy(&*first);
            for(size_type i = start_index; i != m_Size; i++)
            {
                m_Allocator.construct(m_Data + i, m_Data[end_index + i]);
                m_Allocator.destroy(m_Data + end_index + i);
            }
            m_Size -= (end_index - start_index) + 1;
            return (iterator(m_Data + index));
        }

    private:
        size_type   m_Size;
        size_type   m_Capacity;
        pointer     m_Data;
        Allocator   m_Allocator;
};

        ////////////////////////////////////////////////////////////////////
        //                        Non-member functions                    //
        ////////////////////////////////////////////////////////////////////

    template <class T, class allocator>
    bool    operator==(const vector<T, allocator> &vec1, const vector<T, allocator> &vec2)
    {
        if (vec1.size() != vec2.size())
            return (false);
        for(size_t i = 0; i < vec1.size(); i++)
            if (vec1[i] != vec2[i])
                return (false);
        return (true);
    }

    template <class T, class allocator>
    bool    operator!=(const vector<T, allocator> &vec1, const vector<T, allocator> &vec2)
    {
        return (!operator==(vec1, vec2));
    }

    template <class T, class allocator>
    bool    operator<(const vector<T, allocator> &vec1, const vector<T, allocator> &vec2)
    {
        return (ft::lexicographical_compare(vec1.begin(), vec1.end(), vec2.begin(), vec2.end()));
    }

    template <class T, class allocator>
    bool    operator>(vector<T, allocator> vec1, vector<T, allocator> vec2)
    {
            return (!(vec1 < vec2));
    }

    template <class T, class allocator>
    bool    operator<=(vector<T, allocator> vec1, vector<T, allocator> vec2)
    {
        if (vec1 < vec2 || vec1 == vec2)
            return (true)
        return (false);
    }

    template <class T, class allocator>
    bool    operator<(vector<T, allocator> vec1, vector<T, allocator> vec2)
    {
        if (vec1.size() != vec2.size())
            return (false);
        for(size_t i = 0; i < vec1.size(); i++)
            if (vec1[i] >= vec2[i])
                return (false);
        return (true);
    }
}
#endif