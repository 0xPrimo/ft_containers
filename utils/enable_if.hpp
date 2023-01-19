#ifndef _ENABLE_IF_
# define _ENABLE_IF_
namespace ft
{
    template <bool B, class T = void>
    struct enable_if
    {
    };

    template <class T>
    struct enable_if<true, T>
    {
        typedef T type;
    };
}

#endif