#ifndef _PAIR_
# define _PAIR_

template<class T1, class T2>
struct pair
{
    public:
        typedef     T1      first_type;
        typedef     T2      second_type;

    public:
        first_type  first;
        second_type second;
    
    pair()
    {

    }

    pair &operator(const pair &other)
    {

    }

};
#endif