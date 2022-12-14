#include "vector_prelude.hpp"

void vec_test_push_back()
{
    {
        doublevector v;

        for (int i = 0; i < 26; ++i) {
            v.push_back(45.0123);
            CHECK_AND_PRINT_ALL(v);
        }

        v.push_back(6);

        CHECK_AND_PRINT_ALL(v);

        v.push_back(-4356.8933);

        CHECK_AND_PRINT_ALL(v);
    }
}

MAIN(vec_test_push_back)
