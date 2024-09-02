#include <cilia/String.hpp>
#include <cilia/Vector.hpp>
#include <iostream>

using namespace cilia;

auto printLineCil(const String& str) {
	using namespace std;
	cout << str << endl;
}

auto printLineStd(const std::string& str) {
	using namespace std;
	cout << str << endl;
}

auto main() -> Int32 {
	String      str = "Test";
	std::string strStd = "TestStd";

	printLineStd(str);
	printLineCil(str);
	printLineStd(strStd);
	printLineCil(strStd);

	Int i1 = str.findFirstOf("Tt", 0);
	Int i2 = str.findFirstOf("Tt", i1 + 1);
	Int i3 = str.findFirstOf("Tt", i2 + 1);

	Float flt1 = NaN;
	Float flt2 = Infinity;
	if (str.empty() == False) {
		std::cout << "String is not empty" << std::endl;
	}

	return 0;
}
