#pragma once
#include "cilia/String.hpp"

namespace cilia {

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

}
