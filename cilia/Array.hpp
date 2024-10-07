#pragma once
#include <vector>
#include <exception> // terminate()
#include "cilia/BasicTypes.hpp"

namespace cilia {

	template <typename T, typename Allocator = std::allocator<T>>
	class Array : public std::vector<T, Allocator> {
	public:
		using ValueType            = std::vector<T, Allocator>::value_type;
		using AllocatorType        = std::vector<T, Allocator>::allocator_type;
		using SizeType             = std::vector<T, Allocator>::size_type;
		using Reference            = std::vector<T, Allocator>::reference;
		using ConstReference       = std::vector<T, Allocator>::const_reference;
		using Pointer              = std::vector<T, Allocator>::pointer;
		using ConstPointer         = std::vector<T, Allocator>::const_pointer;
		using Iterator             = std::vector<T, Allocator>::iterator;
		using ConstIterator        = std::vector<T, Allocator>::const_iterator;
		using ReverseIterator      = std::vector<T, Allocator>::reverse_iterator;
		using ConstReverseIterator = std::vector<T, Allocator>::const_reverse_iterator;

		// Take over all constructors
		using std::vector<T, Allocator>::vector;

		// Allow functions with an Array parameter to also take std::vector.
		//TODO This should be a NoOp conversion, but currently it probably is creating a copy.
		Array(const std::vector<T, Allocator>& vec) : std::vector<T, Allocator>(vec) { }
		Array(std::vector<T, Allocator>&& vec) : std::vector<T, Allocator>(vec) { }

		auto pushBack(const T& element) {
			std::vector<T, Allocator>::push_back(element);
		}
		auto pushBack(T&& element) {
			std::vector<T, Allocator>::push_back(element);
		}

		auto popBack() {
			std::vector<T, Allocator>::pop_back();
		}

		template<class... Args>
		auto emplaceBack(Args&&... args) -> Reference {
			return std::vector<T, Allocator>::emplace_back(args...);
		}

		auto operator [](Int i) -> Reference {
			// Bounds check
			if (i < 0 || i >= this->size())
				std::terminate();

			return std::vector<T, Allocator>::operator[](i);
		}
		auto operator [](Int i) const -> ConstReference {
			// Bounds check
			if (i < 0 || i >= this->size())
				std::terminate();

			return std::vector<T, Allocator>::operator[](i);
		}

		using std::vector<T, Allocator>::assign;
		template<typename R> //TODO Restrict to ranges
		constexpr void assign(R&& range) {
			std::vector<T, Allocator>::assign_range(range);
		}

        auto append(const T& element) {
            std::vector<T, Allocator>::push_back(element);
        }
        auto append(T&& element) {
            std::vector<T, Allocator>::push_back(element);
        }
		template<typename R> //TODO Restrict to ranges
		constexpr void append(R&& range) {
			std::vector<T, Allocator>::append_range(range);
		}

		using std::vector<T, Allocator>::insert;
		template<typename R> //TODO Restrict to ranges
		constexpr void insert(ConstIterator pos, R&& range) {
			std::vector<T, Allocator>::insert_range(pos, range);
		}

		auto maxSize() const noexcept -> Int {
			return max_size();
		}

		auto shrinkToFit() {
			shrink_to_fit();
		}

		auto getAllocator() const noexcept -> AllocatorType {
			return std::vector<T, Allocator>::get_allocator();
		}

		//TODO Kennt VS 17.11 wohl noch gar nicht
		//template<typename T, typename Allocator, typename Pred>
		//constexpr auto eraseIf(Array<T, Allocator>& arr, Pred pred) -> Array<T, Allocator>::SizeType {
		//	return std::vector<T, Allocator>::erase_if(arr, pred);
		//}

	private:
		// Hide the original snake_case names
		using std::vector<T, Allocator>::append_range;
		using std::vector<T, Allocator>::insert_range;
		using std::vector<T, Allocator>::push_back;
		using std::vector<T, Allocator>::pop_back;
		using std::vector<T, Allocator>::emplace_back;
		using std::vector<T, Allocator>::max_size;
		using std::vector<T, Allocator>::shrink_to_fit;
		using std::vector<T, Allocator>::get_allocator;
		//using std::vector<T, Allocator>::erase_if;
	};

}
