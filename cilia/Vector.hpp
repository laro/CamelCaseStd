#include <vector>
#include <cilia/Types.hpp>

namespace cilia {

    template <typename T, typename Allocator = std::allocator<T>>
    class Array : public std::vector<T, Allocator> {
    public:
        using std::vector<T, Allocator>::vector;

        auto pushBack(const T& element) {
            std::string::push_back(element);
        }

        auto operator [](Int i) -> T& {
            // Bounds check
            if (i < 0 || i >= this->size())
                std::terminate();

            return std::vector<T, Allocator>::operator[](i);
        }

    private:
        // Hide the original snake_case functions
        using std::string::push_back;
    };

}
