#include "map_prelude.hpp"

int main()
{
    SETUP;

    NAMESPACE::map<int, int> data;

    for (std::size_t i = 0; i < MAXSIZE / 2; ++i) {
        data.insert(NAMESPACE::make_pair(rand(), rand()));
    }

    timer t;

    for (int i = 0; i < 10000000; ++i) {
        NAMESPACE::pair<NAMESPACE::map<int, int>::iterator, NAMESPACE::map<int, int>::iterator> eq =
            data.equal_range(rand());
        if (eq.first != data.end()) {
            eq.second->second = 64;
        }
    }

    PRINT_TIME(t);
}