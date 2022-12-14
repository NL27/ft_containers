#include "set_prelude.hpp"

void set_test_get_allocator()
{
    intset m;

    track_allocator<NAMESPACE::pair<const int, std::string> > alloc = m.get_allocator();

    NAMESPACE::pair<const int, std::string>* buff = alloc.allocate(64);

    alloc.deallocate(buff, 64);
}

MAIN(set_test_get_allocator)
