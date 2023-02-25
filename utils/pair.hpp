#ifndef _PAIR_
# define _PAIR_
namespace ft
{
    template<class T1, class T2>
    struct pair
    {
        public:
            typedef     T1      first_type;
            typedef     T2      second_type;

        public:
            first_type  first;
            second_type second;

        pair(): first(), second()
        {

        }

        pair(first_type t1, second_type t2): first(t1), second(t2)
        {

        }

        pair(const pair &other): first(other.first), second(other.second)
        {

        }

        pair &operator=(const pair &other)
        {
            first = other.first;
            second = other.second;
            return (*this);
        }
    };

    template <class T1, class T2>
    ft::pair<T1, T2> make_pair(T1 a, T2 b)
    {
        return (ft::pair<T1, T2>(a, b));
    }
}
#endif