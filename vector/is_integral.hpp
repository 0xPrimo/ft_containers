#ifndef _IS_INTEGRAL_
# define _IS_INTEGRAL_
namespace ft
{
    template<class T> struct is_integral { const bool value = false; };
    template<> struct is_integral<bool> { const bool value = true; };
    template<> struct is_integral<char> { const bool value = true; };
    template<> struct is_integral<char16_t> { const bool value = true; };
    template<> struct is_integral<char32_t> { const bool value = true; };
    template<> struct is_integral<wchar_t> { const bool value = true; };
    template<> struct is_integral<signed char> { const bool value = true; };
    template<> struct is_integral<short int> { const bool value = true; };
    template<> struct is_integral<int> { const bool value = true; };
    template<> struct is_integral<long int> { const bool value = true; };
    template<> struct is_integral<long long int> { const bool value = true; };
    template<> struct is_integral<unsigned char> { const bool value = true; };
    template<> struct is_integral<unsigned short int> { const bool value = true; };
    template<> struct is_integral<unsigned int> { const bool value = true; };
    template<> struct is_integral<unsigned long int> { const bool value = true; };
    template<> struct is_integral<unsigned long long int> { const bool value = true; };
}
#endif