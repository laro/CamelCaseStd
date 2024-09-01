#include <iostream>

#include <limits>
#include <cmath>

namespace cilia {
    using Int = int;
    using Int8  = int8_t;
    using Int16 = int16_t;
    using Int32 = int32_t;
    using Int64 = int64_t;

    using UInt = uint;
    using UInt8  = uint8_t;
    using UInt16 = uint16_t;
    using UInt32 = uint32_t;
    using UInt64 = uint64_t;

    using Bool = bool;
    using Char = unsigned char;

    using Float = float;
    using Float16 = _Float16;
    using Float32 = float;
    using Float64 = double;
    using BFloat16 = __bf16;


    const static Bool True = true;
    const static Bool False = false;
    const static nullptr_t NullPtr = nullptr;
    const static Float32 NaN = std::numeric_limits<Float32>::quiet_NaN();
    const static Float32 Infinity = std::numeric_limits<Float32>::infinity();


    class String : public std::string {
    public:
        using ValueType     = std::string::value_type;
        using TraitsType    = std::string::traits_type;
        using AllocatorType = std::string::allocator_type;
        using Reference      = std::string::reference;
        using ConstReference = std::string::const_reference;
        using Pointer        = std::string::pointer;
        using ConstPointer   = std::string::const_pointer;
        using Iterator             = std::string::iterator;
        using ConstIterator        = std::string::const_iterator;
        using ReverseIterator      = std::string::reverse_iterator;
        using ConstReverseIterator = std::string::const_reverse_iterator;

        using std::string::string;
        auto String(const std::string& str) : std::string(str) { }

        auto findFirstOf(const String& str, Int pos) const noexcept -> Int {
            return std::string::find_first_of(str, pos);
        }

    private:
        using std::string::find_first_of;
    };

    template <typename T, typename Allocator = std::allocator<T>>
    class Array : public std::vector<T, Allocator> {
    public:
        using std::vector<T, Allocator>::vector;

        auto pushBack(const T& element) {
            std::string::push_back(element);
        }

        auto operator [](Int i) -> T& {
            if (i < 0 || i >= this->size())
                std::terminate();

            return std::vector<T, Allocator>::operator[](i);
        }

    private:
        using std::string::push_back;
    };


    auto printLineCil(const String& str) {
        std::cout << str << std::endl;
    }

    auto printLineStd(const std::string& str) {
        std::cout << str << std::endl;
    }
}


int main() {
    using namespace cilia;
    using namespace std;

    String strCil = "TestCil";
    string strStd = "TestStd";

    printLineStd(strCil);
    printLineCil(strCil);
    printLineStd(strStd);
    printLineCil(strStd);

    return 0;
}
