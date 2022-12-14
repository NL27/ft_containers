#include "vector_prelude.hpp"

int main()
{
    SETUP;

    timer t;
    for (int i = 0; i < 2; ++i) {
        NAMESPACE::vector<int> v;

        for (std::size_t i = 0; i < MAXSIZE / 2; ++i) {
            v.insert(v.end(), rand());
        }
        BLOCK_OPTIMIZATION(v);
    }

    for (int i = 0; i < 2; ++i) {
        NAMESPACE::vector<int> v;

        for (std::size_t i = 0; i < 200000; ++i) {
            v.insert(v.begin(), rand());
        }
        BLOCK_OPTIMIZATION(v);
    }

    for (int i = 0; i < 2; ++i) {
        NAMESPACE::vector<int> v;

        for (std::size_t i = 0; i < 5000; ++i) {
            v.insert(v.end(), rand());
        }
        for (std::size_t i = 0; i < 200000; ++i) {
            v.insert(v.begin() + 450, rand());
        }
        BLOCK_OPTIMIZATION(v);
    }
    PRINT_TIME(t);
}
