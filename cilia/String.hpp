#pragma once
#include <string>
#include <exception> // terminate()
#include "cilia/BasicTypes.hpp"

namespace cilia {
	class String2;

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
		// (this seems to create "String(const String& str)", but not "String(const std::string& str)").
		using std::string::string;

		// Allow functions with a String parameter to also take std::string.
		// This, unfortunately, is creating a copy.
		String(const std::string& str) : std::string(str) { }
		String(std::string&& str) : std::string(str) { }
		// How about a no-op (non-copying) converting constructor?
		//String&(std::string&) { }
		//const String&(const std::string&) { }

		// NoOp casting from String to String2
		// Unfortunately we need to define it here, in String. AFAIK it is not possible to define it in String2.
		// So for std::string we need to use constructor casting (unfortunately creating a copy), as we cannot change <string> itself.
		operator String2&() {
			return *reinterpret_cast<String2*>(this);
		}
		operator const String2& () const {
			return *reinterpret_cast<const String2*>(this);
		}


		auto size() const -> Int {
			return Int(std::string::size());
		}


		/// Checks whether the given index is within bounds.
		/// If not, it will terminate the program (or maybe throw an exception).
		auto EnsureIndexIsWithinBounds(Int i) const {
#if defined(EVEN_FASTER_BUT_UNSAFE_RELEASE_BUILD) || (_HAS_ITERATOR_DEBUGGING > 0) || defined(_GLIBCXX_DEBUG)
			// Do not check bounds here, when
			// - we are compiling as EvenFasterButUnsafeRelease  or
			// - bounds checking is already enabled/done by MSVC ("iterator debugging") or GCC.
#else
			if (UInt(i) >= UInt(size()))
				std::terminate();
				//Or throw std::out_of_range("String index is out of bounds");
#endif
		}

		auto operator[](Int i) -> Reference {
			EnsureIndexIsWithinBounds(i);
			return std::string::operator[](i);
		}
		auto operator[](Int i) const -> ConstReference {
			EnsureIndexIsWithinBounds(i);
			return std::string::operator[](i);
		}


		auto findFirstOf(const String& str, Int pos = 0) const noexcept -> Int {
			return Int(std::string::find_first_of(str, pos));
		}
		auto findFirstOf(const char* str, Int pos = 0) const -> Int {
			return Int(std::string::find_first_of(str, pos));
		}
		auto findFirstOf(const char* str, Int pos, Int n) const -> Int {
			return Int(std::string::find_first_of(str, pos, n));
		}
		auto findFirstOf(char c, Int pos = 0) const -> Int {
			return Int(std::string::find_first_of(c, pos));
		}

		auto findLastOf(const String& str, Int pos = NPos) const noexcept -> Int {
			return Int(std::string::find_last_of(str, pos));
		}
		auto findLastOf(const char* str, Int pos = NPos) const -> Int {
			return Int(std::string::find_last_of(str, pos));
		}
		auto findLastOf(const char* str, Int pos, Int n) const -> Int {
			return Int(std::string::find_last_of(str, pos, n));
		}
		auto findLastOf(char c, Int pos = NPos) const -> Int {
			return Int(std::string::find_last_of(c, pos));
		}

		auto findFirstNotOf(const String& str, Int pos = 0) const noexcept -> Int {
			return Int(std::string::find_first_not_of(str, pos));
		}
		auto findFirstNotOf(const char* str, Int pos = 0) const -> Int {
			return Int(std::string::find_first_not_of(str, pos));
		}
		auto findFirstNotOf(const char* str, Int pos, Int n) const -> Int {
			return Int(std::string::find_first_not_of(str, pos, n));
		}
		auto findFirstNotOf(char c, Int pos = 0) const -> Int {
			return Int(std::string::find_first_not_of(c, pos));
		}

		auto findLastNotOf(const String& str, Int pos = NPos) const noexcept -> Int {
			return Int(std::string::find_last_not_of(str, pos));
		}
		auto findLastNotOf(const char* str, Int pos = NPos) const -> Int {
			return Int(std::string::find_last_not_of(str, pos));
		}
		auto findLastNotOf(const char* str, Int pos, Int n) const -> Int {
			return Int(std::string::find_last_not_of(str, pos, n));
		}
		auto findLastNotOf(char c, Int pos = NPos) const -> Int {
			return Int(std::string::find_last_not_of(c, pos));
		}

		auto maxSize() const noexcept -> Int {
			return max_size();
		}

		auto shrinkToFit() {
			shrink_to_fit();
		}

		auto pushBack(Char c) {
			push_back(c);
		}

		auto popBack() {
			pop_back();
		}

		auto getAllocator() const noexcept -> AllocatorType {
			return get_allocator();
		}

		static const Int NPos = -1;


	private:
		// Hide the original snake_case names
		using std::string::find_first_of;
		using std::string::find_last_of;
		using std::string::find_first_not_of;
		using std::string::find_last_not_of;
		using std::string::max_size;
		using std::string::shrink_to_fit;
		using std::string::push_back;
		using std::string::pop_back;
		using std::string::get_allocator;
		using std::string::npos;
	};

	// String2 is just a test for how to implement NoOp conversion from base to
	// child class.
	class String2 : public String {
	public:
		// Take over all constructors
		using String::String;

		// Allow functions with a String2 parameter to also take String.
		//TODO Unfortunately there is no way to define an external conversion operator.
		//     We need to add this to the base class "String":
		//       operator String2() { return *reinterpret_cast<String2*>(this); }
	};

	// // Not possible in C++26
	// No globally defined cast operator like this:
	//	operator String (std::string& str) {
	//		return *reinterpret_cast<const String*>(&str);
	//	}
	//
	// And there is no way to define an external conversion operator like this:
	//	std::string::operator String& (std::string& str) {
	//		return *reinterpret_cast<String*>(&str);
	//	}

}
