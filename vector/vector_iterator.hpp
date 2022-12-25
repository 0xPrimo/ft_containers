#ifndef _VECTOR_ITERATOR_
# define _VECTOR_ITERATOR_

template <class Vector>

class VectorIterator
{
    public:
        typedef typename Vector::value_type     value_type;
        typedef typename Vector::pointer        pointer;
        typedef typename Vector::reference      reference;

    public:
        VectorIterator(pointer *ptr): m_ptr(ptr){}
        
        VectorIterator& operator++(int)
        {
            m_ptr++;
            return(*this);
        }

        VectorIterator operator++()
        {
            VectorIterator tmp = *this;
            m_ptr++;
            return (tmp);
        }       
        
        
        VectorIterator& operator--(int)
        {
            m_ptr--;
            return (*this);
        }

        VectorIterator operator--()
        {
            VectorIterator tmp = *this;
            m_ptr--;
            return (tmp);
        }

        pointer operator->()
        {
            return (m_ptr);
        }

        reference operator*()
        {
            return (*m_ptr);
        }

        reference operator[](int index)
        {
            if (index < 0){
                // throw exception
            }
            return (*(m_ptr + index));
        }



    private:
        pointer     m_ptr;

};

#endif