# CamelCaseStd
CamelCase wrapper for the classes/types of the C++ standard library,  
e.g. `class cilia::String : public std::string { ... }`.

So roughly a variant of Qt with the standard library classes as base (but with exceptions, and with namespaces instead of the prefix "Q").

- Replacing lowercase / snake_case type names with upper CamelCase:
    - `Int`, `Int32`, `String`, `ForwardList` ...
        - instead of `int`, `int32_t`, `string`, `forward_list` ...

- Replacing lowercase / snake_case function names with (lower) camelCase:  
  `str.popBack()` instead of `str.pop_back()`.

- Sometimes simplifying the interface:  
  `arr1.append(arr2)` instead of `arr1.append_range(arr2)`.

- Sometimes using IMHO better names:  
    - `Array<Int> arr` instead of `vector<int> vec`,
    - `FixedSizeArray<Int> arr` instead of `array<int> arr`.

- Changing the type used for size() and index-based access (`operator[]`) from unsigned `size_t` to signed `Int`.

- Checking the array bounds with index-based access,
    - but only if not already checked by the compiler,
        - and not in "UsafeRelease" builds.
 
- Problem No-Op Conversion:
    - Unable to cast a standard base class like `std::string` to its CamelCase counterpart `cilia::String` (without creating a copy).
    - A plain casting constructor is not sufficient, as it creates a copy instead of just using the `std::string`:
        ```
        namespace cilia {
            class String : std::string {
                String(std::string& str) : string(str) { }
            }
        }
        ```
    - Currently only possible if we can change the `std` base class and add an `operator cilia::String&`
        ```
        namespace std {
            class string {
                operator cilia::String&() {
                    return *reinterpret_cast<String*>(this);
                }
            }
        }
        ```
        - This is not desirable,
            - we _want_ to keep the `std` files separate from the new `cilia` files,
            - and it is practically impossible to do anyway (as we cannot change the standard library).
    - So we need one of these:
        - a global cast operator (from `std::string&` to `cilia::String&`)
            ```
            operator cilia::String&(std::string& str) {
                return *reinterpret_cast<String*>(&str);
            }
            ```
        - a kind of no-op constructor
            ```
            namespace cilia {
                class String : std::string {
                    String&(std::string& str) {
                        return *reinterpret_cast<String*>(&str);
                    }
                }
            }
            ```
        - an externally defined cast operator
            ```
            std::string::operator cilia::String&() {
                return *reinterpret_cast<cilia::String*>(this);
            }
            ```
        - a new rule, that classes, when necessary, will be cast to derived classes, if those do not add any member variables


- TODO Next
    - Exception.hpp
    - Signals and callbacks ("slots")
        - std::function
