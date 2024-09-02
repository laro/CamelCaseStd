#include <string>
#include <cilia/BasicTypes.hpp>

namespace cilia {

    class String : public std::string {
    public:
        using ValueType            = std::string::value_type;
        using TraitsType           = std::string::traits_type;
        using AllocatorType        = std::string::allocator_type;
        using Reference            = std::string::reference;
        using ConstReference       = std::string::const_reference;
        using Pointer              = std::string::pointer;
        using ConstPointer         = std::string::const_pointer;
        using Iterator             = std::string::iterator;
        using ConstIterator        = std::string::const_iterator;
        using ReverseIterator      = std::string::reverse_iterator;
        using ConstReverseIterator = std::string::const_reverse_iterator;

        // Take over all constructors
        using std::string::string;
        //TODO This should be a noop conversion, but currently it probably is creating a copy.
        auto String(const std::string& str) : std::string(str) { }

        auto findFirstOf(const String& str, Int pos) const noexcept -> Int {
            return std::string::find_first_of(str, pos);
        }

    private:
        // Hide the original snake_case functions
        using std::string::find_first_of;
    };

}
