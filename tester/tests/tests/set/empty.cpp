#include "set_prelude.hpp"

void set_test_empty()
{
    SETUP_ARRAYS();

    {
        strset m;

        PRINT_LINE("Empty:", m.empty() ? "true" : "false");

        m.insert("Hello");

        PRINT_LINE("Empty:", m.empty() ? "true" : "false");

        m.erase(m.begin());

        PRINT_LINE("Empty:", m.empty() ? "true" : "false");
    }

    {
        intset m(int_arr, int_arr + int_size);

        PRINT_LINE("Empty:", m.empty() ? "true" : "false");
    }
}

MAIN(set_test_empty)
