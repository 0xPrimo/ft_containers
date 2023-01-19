#ifndef _EQUAL_
# define _EQUAL_


//  Returns true if the range [first1, last1) is equal to the range [first2, first2 + (last1 - first1)), and false otherwise.

template< class InputIt1, class InputIt2 >
bool equal( InputIt1 first1, InputIt1 last1,
            InputIt2 first2 )
{
    while (first1 != last1)
    {
        if (*first1 != *first2)
            return (false);
        first1++;
        first2++;
    }
    return (true);
}

//  Returns true if the range [first1, last1) is equal to the range [first2, last2), and false otherwise.

template< class InputIt1, class InputIt2,
          class BinaryPredicate >
bool equal( InputIt1 first1, InputIt1 last1,
            InputIt2 first2, BinaryPredicate p )
{
    while (first1 != last1)
    {
        if (!p(*first1, *first2))
            return (false);
        first1++;
        first2++;
    }
    return (true);
}
#endif