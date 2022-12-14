#include "leak_checker.hpp"

#include <iostream>

void leak_checker::check_leaks()
{
    if (tracker.allocation_empty()) {
        std::cout << "========================================\n";
        std::cout << "No leak detected\n";
        std::cout << "========================================" << std::endl;
    } else {
        std::cout << "========================================\n";
        std::cout << tracker.allocation_count() << " Leak(s) detected\n";
        std::cout << "========================================" << std::endl;
    }
}

void leak_checker::check_alive_objects()
{
    if (tracker.constructs_empty()) {
        std::cout << "========================================\n";
        std::cout << "Every objects destroyed\n";
        std::cout << "========================================" << std::endl;
    } else {
        std::cout << "========================================\n";
        std::cout << tracker.constructs_count() << " Alive object(s)\n";
        std::cout << "========================================" << std::endl;
    }
}

void leak_checker::check_all()
{
    check_leaks();
    check_alive_objects();
}

memory_tracker leak_checker::tracker = memory_tracker();
