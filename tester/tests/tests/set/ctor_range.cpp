#include "set_prelude.hpp"

void set_test_ctor_range()
{
    SETUP_ARRAYS();

    {
        track_allocator<NAMESPACE::pair<const int, std::string> > alloc;
        intset m(int_arr, int_arr + int_size, std::less<int>(), alloc);

        PRINT_ALL(m);

        intset m2(m.begin(), m.end());

        PRINT_ALL(m);
        PRINT_ALL(m2);
    }

    {
        strset m1(str_arr, str_arr + str_size);

        PRINT_ALL(m1);

        strset m2(str_arr, str_arr + str_size);

        PRINT_ALL(m1);
        PRINT_ALL(m2);
    }
}

MAIN(set_test_ctor_range)
