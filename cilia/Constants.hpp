#include <cstddef>
#include <limits>

namespace cilia {

    const static Bool True = true;
    const static Bool False = false;
    const static nullptr_t NullPtr = nullptr;
    const static Float32 NaN = std::numeric_limits<Float32>::quiet_NaN();
    const static Float32 Infinity = std::numeric_limits<Float32>::infinity();

}
