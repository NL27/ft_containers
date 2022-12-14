#include "stack_prelude.hpp"

#define CHECK_TYPEDEF(type)                                                                        \
    {                                                                                              \
        NAMESPACE::stack<int>::type a = NAMESPACE::stack<int>::type();                             \
        (void)a;                                                                                   \
    }

void stack_check_typedefs()
{
    CHECK_TYPEDEF(container_type);
    CHECK_TYPEDEF(value_type);
    CHECK_TYPEDEF(size_type);

    {
        ft::stack<int>::value_type a = 10;
        ft::stack<int>::reference b = a;
        ft::stack<int>::const_reference c = a;
        (void)a;
        (void)b;
        (void)c;
    }
}

MAIN(stack_check_typedefs)
