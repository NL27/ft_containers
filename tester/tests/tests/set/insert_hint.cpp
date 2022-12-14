#include "set_prelude.hpp"

void set_test_insert_hint()
{
    SETUP_ARRAYS();

    {
        intset m;

        intset::iterator it = m.insert(m.end(), 64);

        PRINT_LINE("It:", *it);

        it = m.insert(m.end(), 64);

        PRINT_LINE("It:", *it);

        it = m.insert(m.end(), 100);

        PRINT_LINE("It:", *it);

        it = m.end();
        --it;

        it = m.insert(it, 100);

        PRINT_LINE("It:", *it);

        it = m.insert(it, 69);

        PRINT_LINE("It:", *it);
    }
}

MAIN(set_test_insert_hint)
