#include <cilia/String.hpp>
#include <cilia/Vector.hpp>
#include <iostream>

using namespace cilia;

auto printLine(const String& str) {
	using namespace std;
	cout << str << endl;
}

//auto printLineStd(const std::string& str) {
//	using namespace std;
//	cout << str << endl;
//}

auto main() -> Int32 {
	String      str    = "Test";
	std::string strStd = "TestStd";

	printLine(str);
	printLine(strStd);
	//printLineStd(str);
	//printLineStd(strStd);

	Int i1 = str.findFirstOf("Tt");
	Int i2 = str.findFirstOf("Tt", i1 + 1);
	Int i3 = str.findFirstOf("Tt", i2 + 1);

	Int i4 = str.findLastOf("Tt");
	Int i5 = str.findLastOf("Tt", i4 - 1);
	Int i6 = str.findLastOf("Tt", i5 - 1);

	Int i7 = str.findFirstNotOf("Tt");
	Int i8 = str.findFirstNotOf("Tt", i7 + 1);
	Int i9 = str.findFirstNotOf("Tt", i8 + 1);

	Int i10 = str.findLastNotOf("Tt");
	Int i11 = str.findLastNotOf("Tt", i10 - 1);
	Int i12 = str.findLastNotOf("Tt", i11 - 1);


	Int maxSize = str.maxSize();
	str.popBack();
	str.shrinkToFit();
	auto allocator = str.getAllocator();


	Float flt1 = NaN;
	Float flt2 = Infinity;
	if (str.empty() == False) {
		std::cout << "String is not empty" << std::endl;
	}


	Array<Int> arr1 { 0, 1, 2, 3 };
	Array<Int> arr2 { 4, 5, 6, 7 };
	arr1.assign(arr2);
	arr1.pushBack(8);
	arr1.popBack();
	arr1.emplaceBack(9);
	arr1.shrinkToFit();
	Int maxSizeVec = arr1.maxSize();
	auto allocatorVec = arr1.getAllocator();


	return 0;
}
