#ifndef BEMAN_SUPER_SORT
#define BEMAN_SUPER_SORT

#include <algorithm>


// This macro should come from a header made available by the super project.
#if 202302L < __cplusplus
#define BEMAN_NAMESPACE inline namespace
#else
#define BEMAN_NAMESPACE namespace
#endif


namespace beman {

    BEMAN_NAMESPACE cpp26 {

        /** Sorts the range [first, last).  Is super fast. */
        template<typename I>
        void super_sort(I first, I last, bool do_it_super) {
            std::sort(first, last);
        }

    }

    BEMAN_NAMESPACE cpp23 {

        /** Sorts the range [first, last).  Is super fast.  This is a
            compatibility backport of std::super_sort() usable in C++23
            builds. */
        template<typename I>
        void super_sort(I first, I last, bool do_it_super) {
            cpp26::super_sort(first, last, do_it_super);
        }

    }

}

#endif
