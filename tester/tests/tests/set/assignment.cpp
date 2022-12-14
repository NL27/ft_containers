#include "set_prelude.hpp"

void set_test_assignment()
{
    SETUP_ARRAYS();

    {
        intset m1;
        intset m2;

        m1 = m2;

        PRINT_ALL(m1);

        m2 = intset(int_arr, int_arr + int_size);

        PRINT_ALL(m2);

        m1 = m2;

        PRINT_ALL(m1);

        m1 = intset(int_arr, int_arr + 10);

        PRINT_ALL(m1);

        m2 = m1;

        PRINT_ALL(m2);
    }

    {
        strset m1;
        strset m2;

        m1 = m2;

        PRINT_ALL(m1);

        m2 = strset(str_arr, str_arr + str_size);

        PRINT_ALL(m2);

        m1 = m2;

        PRINT_ALL(m1);

        m1 = strset(str_arr, str_arr + 10);

        PRINT_ALL(m1);

        m2 = m1;

        PRINT_ALL(m2);
    }
}

MAIN(set_test_assignment)
