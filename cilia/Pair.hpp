#pragma once
#include <utility>

namespace cilia {

    //template <typename T1, typename T2>
    //class Pair : public std::pair<T1, T2> { };
    template <typename T1, typename T2>
    using Pair = std::pair<T1, T2>;

}
