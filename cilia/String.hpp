#pragma once
#include <string>
#include "cilia/BasicTypes.hpp"

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

		// Allow functions with a String parameter to also take std::string.
		//TODO This should be a NoOp conversion, but currently it probably is creating a copy.
		String(const std::string& str) : std::string(str) { }
		String(std::string&& str) : std::string(str) { }
		//TODO Unfortunately there is no way to define an external conversion operator.
		//     We would need to add this to std::string (which is not possible):
		//       operator String() { return *(String*)(this); }


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

}
