#pragma once
#include <array>
#include <exception> // terminate()
#include "cilia/BasicTypes.hpp"

namespace cilia {

	template <typename T, Int N>
	class FixedSizeArray : public std::array<T, N> {
	public:
		using ValueType            = std::array<T, N>::value_type;
		using SizeType             = std::array<T, N>::size_type;
		using Reference            = std::array<T, N>::reference;
		using ConstReference       = std::array<T, N>::const_reference;
		using Pointer              = std::array<T, N>::pointer;
		using ConstPointer         = std::array<T, N>::const_pointer;
		using Iterator             = std::array<T, N>::iterator;
		using ConstIterator        = std::array<T, N>::const_iterator;
		using ReverseIterator      = std::array<T, N>::reverse_iterator;
		using ConstReverseIterator = std::array<T, N>::const_reverse_iterator;

		//// Take over all constructors
		//using std::array<T, N>::array;

		//// Allow functions with an FixedSizeArray parameter to also take std::array.
		////TODO This should be a NoOp conversion, but currently it probably is creating a copy.
		//FixedSizeArray(const std::array<T, N>& vec) : std::array<T, N>(vec) { }
		//FixedSizeArray(std::array<T, N>&& vec) : std::array<T, N>(vec) { }


		auto operator [](Int i) -> Reference {
			// Bounds check
			if (i < 0 || i >= this->size())
				std::terminate();

			return std::array<T, N>::operator[](i);
		}
		auto operator [](Int i) const -> ConstReference {
			// Bounds check
			if (i < 0 || i >= this->size())
				std::terminate();

			return std::array<T, N>::operator[](i);
		}


		auto maxSize() const noexcept -> Int {
			return max_size();
		}

	private:
		// Hide the original snake_case names
		using std::array<T, N>::max_size;
	};


	//TODO std::remove_cv_t<T>
	template<typename T, size_t N>
	constexpr FixedSizeArray<std::remove_cv_t<T>, N> toFixedSizeArray(T(&a)[N]) {
		return std::array<std::remove_cv_t<T>, N>{a};
	}
	template<typename T, Int N >
	constexpr FixedSizeArray<std::remove_cv_t<T>, N> toFixedSizeArray(T(&& a)[N]) {
		return std::array<std::remove_cv_t<T>, N>{a};
	}

}
