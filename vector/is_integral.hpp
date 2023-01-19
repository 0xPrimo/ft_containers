#ifndef _IS_INTEGRAL_
# define _IS_INTEGRAL_
namespace ft
{
    template<class T>
    struct is_integral { const bool value = false; };
    template<bool>
    struct is_integral { const bool value = true; };
    template<char>
    struct is_integral { const bool value = true; };
    template<char16_t>
    struct is_integral { const bool value = true; };
    template<char32_t>
    struct is_integral { const bool value = true; };
    template<wchar_t>
    struct is_integral { const bool value = true; };
    template<signed char>
    struct is_integral { const bool value = true; };
    template<short int>
    struct is_integral { const bool value = true; };
    template<int>
    struct is_integral { const bool value = true; };
    template<long int>
    struct is_integral { const bool value = true; };
    template<long long int>
    struct is_integral { const bool value = true; };
    template<unsigned char>
    struct is_integral { const bool value = true; };
    template<unsigned short int>
    struct is_integral { const bool value = true; };
    template<unsigned int>
    struct is_integral { const bool value = true; };
    template<unsigned long int>
    struct is_integral { const bool value = true; };
    template<unsigned long long int>
    struct is_integral { const bool value = true; };
}
#endif