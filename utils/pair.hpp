#ifndef _PAIR_
# define _PAIR_
namespace ft
{
    template<class T1, class T2>
    class pair
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

        pair(const first_type t1, const second_type t2): first(t1), second(t2)
        {

        }

        template <class U, class V>
        pair(const pair<U,V> &other): first(other.first), second(other.second)
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
    bool operator==(const pair<T1, T2> &p1, const pair<T1, T2> &p2)
    {
        if (p1.first == p2.first && p1.second == p2.second)
            return (true);
        return (false);
    }

    template <class T1, class T2>
    bool operator!=(const pair<T1, T2> &p1, const pair<T1, T2> &p2)
    {
        return (!operator==(p1, p2));
    }

    template <class T1, class T2>
    bool operator<(const pair<T1, T2> &p1, const pair<T1, T2> &p2)
    {
        if (p1.first < p2.first && p1.second < p2.second)
            return (true);
        return (false);
    }

    template <class T1, class T2>
    bool operator<=(const pair<T1, T2> &p1, const pair<T1, T2> &p2)
    {
        return (!(p2 < p1));
    }

    template <class T1, class T2>
    bool operator>(const pair<T1, T2> &p1, const pair<T1, T2> &p2)
    {
        return (p2 < p1);
    }

    template <class T1, class T2>
    bool operator>=(const pair<T1, T2> &p1, const pair<T1, T2> &p2)
    {
        return (!(p2 > p1));
    }

    template <class T1, class T2>
    ft::pair<T1, T2> make_pair(T1 a, T2 b)
    {
        return (ft::pair<T1, T2>(a, b));
    }
}
#endif