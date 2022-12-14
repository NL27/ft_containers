#include "set_prelude.hpp"

void set_test_ctor_copy()
{
    SETUP_ARRAYS();

    {
        intset m1(int_arr, int_arr + int_size);

        PRINT_ALL(m1);

        intset m2(m1);

        PRINT_ALL(m2);
    }

    {
        strset m1(str_arr, str_arr + str_size);

        PRINT_ALL(m1);

        strset m2(m1);

        PRINT_ALL(m2);
    }
}

MAIN(set_test_ctor_copy)
