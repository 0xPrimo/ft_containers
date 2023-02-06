#ifndef _STACK_
# define _STACK_

#include "vector.hpp"

namespace ft {

template < class T, class Container = ft::vector<T> >
class stack
{
        public:;
            typedef                     Container                           container_type;
            typedef     typename        Container::value_type               value_type;
            typedef     typename        Container::size_type                size_type;
            typedef     typename        Container::reference                reference;
            typedef     typename        Container::const_reference          const_reference;

        protected:
            Container c;
        
        public:
            stack()
            {

            }

            stack(const Container &cont): c(cont)
            {
            }

            stack(const stack &other): c(other.c)
            {
            }

            stack &operator=(const stack &other)
            {
                if (*this != other)
                    c = other.c;
                return (*this);
            }

            ~stack()
            {
            }
        
            reference top()
            {
                return (c.back());
            }

            bool empty()
            {
                return (c.empty());
            }

            size_type size()
            {
                return (c.size());
            }

            void pop()
            {
                c.pop_back();
            }

            void push(const value_type &value)
            {
                c.push_back(value);
            }

            friend bool operator==(const stack &s1, const stack &s2)
            {
                return (s1.c == s2.c);
            }

            friend bool    operator!=(const stack &s1, const stack &s2)
            {
                return (s1.c != s2.c);
            }

            friend bool    operator<(const stack &s1, const stack &s2)
            {
                return (s1.c < s2.c);
            }

            friend bool    operator>(const stack &s1, const stack &s2)
            {
                return (s1.c > s2.c);
            }

            friend bool    operator<=(const stack &s1, const stack &s2)
            {
                return (s1.c <= s2.c);
            }

            friend bool    operator>=(const stack &s1, const stack &s2)
            {
                return (s1.c >= s2.c);
            }
};

}


#endif