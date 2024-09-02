# CamelCaseStd
CamelCase wrapper for the classes/types of the C++ standard library,  
e.g. `class cilia::String : public std::string { ... }`.

Replacing snake_case names with cameCase:  
`str.popBack()` instead of `str.pop_back()`.

Sometimes simplifying the interface:  
`arr1.append(arr2)` instead of `arr1.append_range(arr2)`.

Sometimes using IMHO better names:  
`Array<Int> arr` instead of `vector<int> vec`.

