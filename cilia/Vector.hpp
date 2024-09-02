#include <vector>
#include <cilia/BasicTypes.hpp>

namespace cilia {

    template <typename T, typename Allocator = std::allocator<T>>
    class Array : public std::vector<T, Allocator> {
    public:
        using ValueType            = std::vector<T, Allocator>::value_type;
        using TraitsType           = std::vector<T, Allocator>::traits_type;
        using AllocatorType        = std::vector<T, Allocator>::allocator_type;
        using Reference            = std::vector<T, Allocator>::reference;
        using ConstReference       = std::vector<T, Allocator>::const_reference;
        using Pointer              = std::vector<T, Allocator>::pointer;
        using ConstPointer         = std::vector<T, Allocator>::const_pointer;
        using Iterator             = std::vector<T, Allocator>::iterator;
        using ConstIterator        = std::vector<T, Allocator>::const_iterator;
        using ReverseIterator      = std::vector<T, Allocator>::reverse_iterator;
        using ConstReverseIterator = std::vector<T, Allocator>::const_reverse_iterator;

        // Take over all construktors
        using std::vector<T, Allocator>::vector;

        auto pushBack(const T& element) {
            std::vector<T, Allocator>::push_back(element);
        }

        auto operator [](Int i) -> T& {
            // Bounds check
            if (i < 0 || i >= this->size())
                std::terminate();

            return std::vector<T, Allocator>::operator[](i);
        }

    private:
        // Hide the original snake_case functions
        using std::vector<T, Allocator>::push_back;
    };

}
