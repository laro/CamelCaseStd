#pragma once
#include <utility>

namespace cilia {

//	template <typename T1, typename T2>
//	class Pair : public std::pair<T1, T2> {
//	public:
//		// Take over all constructors
//		using std::pair<T1, T2>::pair;
//
//		// Allow functions with a Map parameter to also take std::map.
//		//TODO This should be a NoOp conversion, but currently it probably is creating a copy.
//		Pair(const std::pair<T1, T2>& pair) noexcept { }
//
//		// This is the move constructor.
//		Pair(std::pair<T1, T2>&& pair) : std::pair<T1, T2>(std::move(pair)) { }
//	};

	template <typename T1, typename T2>
	using Pair = std::pair<T1, T2>;

}
