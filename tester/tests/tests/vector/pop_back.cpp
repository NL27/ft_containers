#include "vector_prelude.hpp"

void vec_test_pop_back()
{
    SETUP_ARRAYS();

    {
        longvector v(s_long, s_long + s_size);

        v.pop_back();

        CHECK_AND_PRINT_ALL(v);

        for (int i = 0; i < 10; ++i) {
            v.pop_back();
        }

        CHECK_AND_PRINT_ALL(v);
    }
}

MAIN(vec_test_pop_back)
