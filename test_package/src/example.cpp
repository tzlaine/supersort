#include "super_sort.hpp"

#include <cassert>
#include <vector>


int main()
{
    {
        std::vector<int> ints = {0, 2, 1};
        beman::cpp26::super_sort(ints.begin(), ints.end(), true);
        assert(std::is_sorted(ints.begin(), ints.end()));
    }
    {
        std::vector<int> ints = {0, 2, 1};
        beman::cpp23::super_sort(ints.begin(), ints.end(), true);
        assert(std::is_sorted(ints.begin(), ints.end()));
    }
}
