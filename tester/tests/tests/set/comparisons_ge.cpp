#include "set_prelude.hpp"

void set_test_comparisons_ge()
{
    SETUP_ARRAYS();

    {
        intset m;
        intset n;

        if (m > n) {
            PRINT_MSG("Greater");
        }
    }

    {
        intset m(int_arr, int_arr + 1);
        intset n;

        if (m > n) {
            PRINT_MSG("Greater.");
        }
    }

    {
        intset m(int_arr, int_arr + 1);
        intset n;

        if (n > m) {
            PRINT_MSG("Greater..");
        }
    }

    {
        intset m(int_arr, int_arr + 1);
        intset n(int_arr, int_arr + 1);

        if (n > m) {
            PRINT_MSG("Greater...");
        }
    }

    {
        intset m(int_arr, int_arr + int_size);
        intset n(int_arr, int_arr + int_size);

        if (n > m) {
            PRINT_MSG("Greater....");
        }
    }

    {
        intset m(int_arr, int_arr + 5);
        intset n;

        n.insert(5);
        n.insert(7);
        n.insert(8);
        n.insert(1);
        n.insert(0);

        if (n > m) {
            PRINT_MSG("Greater.....");
        }
    }

    {
        intset m(int_arr, int_arr + 5);
        intset n(int_arr, int_arr + 4);

        n.insert(5);

        if (n > m) {
            PRINT_MSG("Greater......");
        }
    }
}

MAIN(set_test_comparisons_ge)
