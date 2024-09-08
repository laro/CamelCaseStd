#pragma once
#include <string>
#include "cilia/BasicTypes.hpp"

namespace cilia {

	class StringView : public std::string_view {
	public:
		using ValueType            = std::string_view::value_type;
		using TraitsType           = std::string_view::traits_type;
		using Reference            = std::string_view::reference;
		using ConstReference       = std::string_view::const_reference;
		using Pointer              = std::string_view::pointer;
		using ConstPointer         = std::string_view::const_pointer;
		using Iterator             = std::string_view::iterator;
		using ConstIterator        = std::string_view::const_iterator;
		using ReverseIterator      = std::string_view::reverse_iterator;
		using ConstReverseIterator = std::string_view::const_reverse_iterator;

		// Take over all constructors
		using std::string_view::string_view;

		// Allow functions with a StringView parameter to also take std::string_view.
		//TODO Unclear, why I have to add a constructor for String.
		//     Didn't have string_view a "ctach all" constructor for nearly everything?
		StringView(const String& str) : std::string_view(str) { }
		StringView(String&& str) : std::string_view(str) { }
		//TODO This should be a NoOp conversion, but currently it probably is creating a copy.
		StringView(const std::string_view& str) : std::string_view(str) { }
		StringView(std::string_view&& str) : std::string_view(str) { }
		//TODO Unfortunately there is no way to define an external conversion operator.
		//     We would need to add this to std::string_view (which is not possible):
		//       operator StringView() { return *(StringView*)(this); }


		auto findFirstOf(const StringView& str, Int pos = 0) const noexcept -> Int {
			return Int(std::string_view::find_first_of(str, pos));
		}
		auto findFirstOf(const char* str, Int pos = 0) const -> Int {
			return Int(std::string_view::find_first_of(str, pos));
		}
		auto findFirstOf(const char* str, Int pos, Int n) const -> Int {
			return Int(std::string_view::find_first_of(str, pos, n));
		}
		auto findFirstOf(char c, Int pos = 0) const -> Int {
			return Int(std::string_view::find_first_of(c, pos));
		}

		auto findLastOf(const StringView& str, Int pos = NPos) const noexcept -> Int {
			return Int(std::string_view::find_last_of(str, pos));
		}
		auto findLastOf(const char* str, Int pos = NPos) const -> Int {
			return Int(std::string_view::find_last_of(str, pos));
		}
		auto findLastOf(const char* str, Int pos, Int n) const -> Int {
			return Int(std::string_view::find_last_of(str, pos, n));
		}
		auto findLastOf(char c, Int pos = NPos) const -> Int {
			return Int(std::string_view::find_last_of(c, pos));
		}

		auto findFirstNotOf(const StringView& str, Int pos = 0) const noexcept -> Int {
			return Int(std::string_view::find_first_not_of(str, pos));
		}
		auto findFirstNotOf(const char* str, Int pos = 0) const -> Int {
			return Int(std::string_view::find_first_not_of(str, pos));
		}
		auto findFirstNotOf(const char* str, Int pos, Int n) const -> Int {
			return Int(std::string_view::find_first_not_of(str, pos, n));
		}
		auto findFirstNotOf(char c, Int pos = 0) const -> Int {
			return Int(std::string_view::find_first_not_of(c, pos));
		}

		auto findLastNotOf(const StringView& str, Int pos = NPos) const noexcept -> Int {
			return Int(std::string_view::find_last_not_of(str, pos));
		}
		auto findLastNotOf(const char* str, Int pos = NPos) const -> Int {
			return Int(std::string_view::find_last_not_of(str, pos));
		}
		auto findLastNotOf(const char* str, Int pos, Int n) const -> Int {
			return Int(std::string_view::find_last_not_of(str, pos, n));
		}
		auto findLastNotOf(char c, Int pos = NPos) const -> Int {
			return Int(std::string_view::find_last_not_of(c, pos));
		}

		auto maxSize() const noexcept -> Int {
			return max_size();
		}

		constexpr auto popBack() {
			remove_suffix(1);
		}

		constexpr auto removeSuffix(Int n) {
			remove_suffix(n);
		}

		constexpr auto removePrefix(Int n) {
			remove_prefix(n);
		}

		constexpr auto startsWith(StringView sv) const noexcept -> Bool {
			return starts_with(sv);
		}
		constexpr auto startsWith(Char ch) const noexcept -> Bool {
			return starts_with(ch);
		}
		//constexpr auto startsWith(const Char* sz) const noexcept -> Bool {
		//	return starts_with(sz);
		//}

		constexpr auto endsWith(StringView sv) const noexcept -> Bool {
			return ends_with(sv);
		}
		constexpr auto endsWith(Char ch) const noexcept -> Bool {
			return ends_with(ch);
		}
		//constexpr auto endsWith(const Char* sz) const noexcept -> Bool {
		//	return ends_with(sz);
		//}

		static const Int NPos = -1;


	private:
		// Hide the original snake_case names
		using std::string_view::find_first_of;
		using std::string_view::find_last_of;
		using std::string_view::find_first_not_of;
		using std::string_view::find_last_not_of;
		using std::string_view::starts_with;
		using std::string_view::ends_with;
		using std::string_view::max_size;
		using std::string_view::npos;
	};

}
