#pragma once
#include <map>
#include <exception> // terminate()
#include "cilia/BasicTypes.hpp"
#include "cilia/Pair.hpp" //TODO "cilia/utility.hpp"

namespace cilia {

	template<
		typename Key,
		typename T,
		typename Compare = std::less<Key>,
		typename Allocator = std::allocator<Pair<const Key, T>>
	>
	class Map : public std::map<Key, T, Compare, Allocator> {
	public:
		using KeyType              = std::map<Key, T, Compare, Allocator>::key_type;
		using MappedType           = std::map<Key, T, Compare, Allocator>::mapped_type;
		using ValueType            = std::map<Key, T, Compare, Allocator>::value_type;
		using AllocatorType        = std::map<Key, T, Compare, Allocator>::allocator_type;
		using SizeType             = std::map<Key, T, Compare, Allocator>::size_type;
		using KeyCompare           = std::map<Key, T, Compare, Allocator>::key_compare;
		using ValueCompare         = std::map<Key, T, Compare, Allocator>::value_compare;
		using Reference            = std::map<Key, T, Compare, Allocator>::reference;
		using ConstReference       = std::map<Key, T, Compare, Allocator>::const_reference;
		using Pointer              = std::map<Key, T, Compare, Allocator>::pointer;
		using ConstPointer         = std::map<Key, T, Compare, Allocator>::const_pointer;
		using Iterator             = std::map<Key, T, Compare, Allocator>::iterator;
		using ConstIterator        = std::map<Key, T, Compare, Allocator>::const_iterator;
		using ReverseIterator      = std::map<Key, T, Compare, Allocator>::reverse_iterator;
		using ConstReverseIterator = std::map<Key, T, Compare, Allocator>::const_reverse_iterator;
		using NodeType             = std::map<Key, T, Compare, Allocator>::node_type;
		

		// Take over all constructors
		using std::map<Key, T, Compare, Allocator>::map;

		// Allow functions with a Map parameter to also take std::map.
		//TODO This should be a NoOp conversion, but currently it probably is creating a copy.
		Map(const std::map<Key, T, Compare, Allocator>& vec) : std::map<Key, T, Compare, Allocator>(vec) { }
		Map(std::map<Key, T, Compare, Allocator>&& vec) : std::map<Key, T, Compare, Allocator>(vec) { }

		using std::map<Key, T, Compare, Allocator>::insert;
		template<typename R> //TODO Auf Ranges beschränken
		constexpr auto insert(R&& range) {
			std::map<Key, T, Compare, Allocator>::insert_range(range);
		}

		template<typename M>
		constexpr auto insertOrAssign(const Key& key, M&& obj) -> Pair<Iterator, Bool> {
			return std::map<Key, T, Compare, Allocator>::insert_or_assign(key, obj);
		}
		template<typename M>
		constexpr auto insertOrAssign(Key&& key, M&& obj) -> Pair<Iterator, Bool> {
			return std::map<Key, T, Compare, Allocator>::insert_or_assign(key, obj);
		}
		template<typename K, typename M>
		constexpr auto insertOrAssign(K&& key, M&& obj) -> Pair<Iterator, Bool> {
			return std::map<Key, T, Compare, Allocator>::insert_or_assign(key, obj);
		}
		template<typename M>
		constexpr auto insertOrAssign(ConstIterator hint, const Key& key, M&& obj) -> Iterator {
			return std::map<Key, T, Compare, Allocator>::insert_or_assign(hint, key, obj);
		}
		template<typename M>
		constexpr auto insertOrAssign(ConstIterator hint, Key&& key, M&& obj) -> Iterator {
			return std::map<Key, T, Compare, Allocator>::insert_or_assign(hint, key, obj);
		}
		template<typename K, typename M>
		constexpr auto insertOrAssign(ConstIterator hint, K&& key, M&& obj) -> Iterator {
			return std::map<Key, T, Compare, Allocator>::insert_or_assign(hint, key, obj);
		}

		auto maxSize() const noexcept -> Int {
			return max_size();
		}

		auto getAllocator() const noexcept -> AllocatorType {
			return std::map<Key, T, Compare, Allocator>::get_allocator();
		}

		template<typename... Args>
		auto emplaceHint(ConstIterator hint, Args&&... args) -> Iterator {
			return std::map<Key, T, Compare, Allocator>::emplace_hint(hint, std::forward<Args>(args)...);
		}

		template<typename M>
		constexpr auto tryEmplace(const Key& key, M&& obj) -> Pair<Iterator, Bool> {
			return std::map<Key, T, Compare, Allocator>::try_emplace(key, obj);
		}
		template<typename M>
		constexpr auto tryEmplace(Key&& key, M&& obj) -> Pair<Iterator, Bool> {
			return std::map<Key, T, Compare, Allocator>::try_emplace(key, obj);
		}
		template<typename K, typename M>
		constexpr auto tryEmplace(K&& key, M&& obj) -> Pair<Iterator, Bool> {
			return std::map<Key, T, Compare, Allocator>::try_emplace(key, obj);
		}
		template<typename M>
		constexpr auto tryEmplace(ConstIterator hint, const Key& key, M&& obj) -> Pair<Iterator, Bool> {
			return std::map<Key, T, Compare, Allocator>::try_emplace(hint, key, obj);
		}
		template<typename M>
		constexpr auto tryEmplace(ConstIterator hint, Key&& key, M&& obj) -> Pair<Iterator, Bool> {
			return std::map<Key, T, Compare, Allocator>::try_emplace(hint, key, obj);
		}
		template<typename K, typename M>
		constexpr auto tryEmplace(ConstIterator hint, K&& key, M&& obj) -> Pair<Iterator, Bool> {
			return std::map<Key, T, Compare, Allocator>::try_emplace(hint, key, obj);
		}

		auto equal_range(const Key& key) -> Pair<Iterator, Iterator> {
			return std::map<Key, T, Compare, Allocator>::equal_range(key);
		}
		auto equal_range(const Key& key) const -> Pair<ConstIterator, ConstIterator> {
			return std::map<Key, T, Compare, Allocator>::equal_range(key);
		}
		template<class K>
		auto equal_range(const K& key) -> Pair<Iterator, Iterator> {
			return std::map<Key, T, Compare, Allocator>::equal_range(key);
		}
		template<class K>
		auto equalRange(const K& key) const -> Pair<ConstIterator, ConstIterator> {
			return std::map<Key, T, Compare, Allocator>::equal_range(key);
		}

		auto lowerBound(const Key& key) -> Iterator {
			return std::map<Key, T, Compare, Allocator>::lower_bound(key);
		}
		auto lowerBound(const Key& key) const -> ConstIterator {
			return std::map<Key, T, Compare, Allocator>::lower_bound(key);
		}
		template<class K>
		auto lowerBound(const K& key) -> Iterator {
			return std::map<Key, T, Compare, Allocator>::lower_bound(key);
		}
		template<class K>
		auto lowerBound(const K& key) const -> ConstIterator {
			return std::map<Key, T, Compare, Allocator>::lower_bound(key);
		}

		auto upperBound(const Key& key) -> Iterator {
			return std::map<Key, T, Compare, Allocator>::upper_bound(key);
		}
		auto upperBound(const Key& key) const -> ConstIterator {
			return std::map<Key, T, Compare, Allocator>::upper_bound(key);
		}
		template<class K>
		auto upperBound(const K& key) -> Iterator {
			return std::map<Key, T, Compare, Allocator>::upper_bound(key);
		}
		template<class K>
		auto upperBound(const K& key) const -> ConstIterator {
			return std::map<Key, T, Compare, Allocator>::upper_bound(key);
		}

		auto keyComp() const -> KeyCompare {
			return std::map<Key, T, Compare, Allocator>::key_comp();
		}

		auto valueComp() const -> ValueCompare {
			return std::map<Key, T, Compare, Allocator>::value_comp();
		}

	private:
		// Hide the original snake_case names
		using std::map<Key, T, Compare, Allocator>::insert_range;
		using std::map<Key, T, Compare, Allocator>::insert_or_assign;
		using std::map<Key, T, Compare, Allocator>::max_size;
		using std::map<Key, T, Compare, Allocator>::get_allocator;
		using std::map<Key, T, Compare, Allocator>::emplace_hint;
		using std::map<Key, T, Compare, Allocator>::try_emplace;
        using std::map<Key, T, Compare, Allocator>::equal_range;
		using std::map<Key, T, Compare, Allocator>::lower_bound;
		using std::map<Key, T, Compare, Allocator>::upper_bound;
		using std::map<Key, T, Compare, Allocator>::key_comp;
		using std::map<Key, T, Compare, Allocator>::value_comp;
	};

}
