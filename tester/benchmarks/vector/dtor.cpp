#include "vector_prelude.hpp"

int main()
{
    SETUP;

    NAMESPACE::vector<int> data;

    for (std::size_t i = 0; i < MAXSIZE; ++i) {
        data.push_back(rand());
    }

    timer t;

    for (int i = 0; i < 100; ++i) {
        sum += t.get_time();
        NAMESPACE::vector<int> v(data.begin(), data.end());
        BLOCK_OPTIMIZATION(v);
        t.reset();
    }

    PRINT_SUM();
}
