# CamelCaseStd
CamelCase wrapper for the classes/types of the C++ standard library,  
e.g. `class cilia::String : public std::string { ... }`.

- Replacing lowercase / snake_case type names with upper CamelCase:
	- `Int` instead of `int`,
	- `Int32` instead of `int32_t`,
	- `String` instead of `string`,
	- `ForwardList` instead of `forward_list`.

- Replacing lowercase / snake_case function names with (lower) camelCase:  
  `str.popBack()` instead of `str.pop_back()`.

- Sometimes simplifying the interface:  
  `arr1.append(arr2)` instead of `arr1.append_range(arr2)`.

- Sometimes using IMHO better names:  
	- `Array<Int> arr` instead of `vector<int> vec`,
	- `FixedSizeArray<Int> arr` instead of `array<int> arr`.

- Changing the type used for size() and indexing from unsigned `size_t` to signed `Int`.

