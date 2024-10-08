#include "cilia/String.hpp"
#include "cilia/StringView.hpp"
#include "cilia/Array.hpp"
#include "cilia/FixedSizeArray.hpp"
#include "cilia/Map.hpp"
#include "cilia/Exception.hpp"
#include "cilia/Signal.hpp"
#include <iostream>

using namespace cilia;


auto printLine(const String& str) {
	using namespace std;
	cout << str << endl;
}

auto printLineStd(const std::string& str) {
	using namespace std;
	cout << str << endl;
}

auto printLineString2(const String2& str) {
	using namespace std;
	cout << str << endl;
}

auto checkStringView(StringView str) {
	using namespace std;
	cout << str << endl;

	Bool b1 = str.startsWith("Test");
	Bool b2 = str.endsWith("Test");
	str.removePrefix(1);
	str.removeSuffix(1);
}

auto append(String2& str, char ch) {
	str.pushBack(ch);
}


auto onTest3Args(Int i, Float f, String s) {
	using namespace std;
	cout << "i = " << i << ", f = " << f << ", s = " << s << endl;
}

auto onTest2Args(Int i, Float f) {
	using namespace std;
	cout << "i = " << i << ", f = " << f << endl;
}

auto onTest1Arg(Int i) {
	using namespace std;
	cout << "i = " << i << endl;
}

auto onTest0Args() {
	using namespace std;
	cout << endl;
}


auto main() -> Int32 {
	using namespace std;

	String       str      = "Test";
	const String strConst = "TestConst";
	string       strStd   = "TestStd";

	printLine(str);
	printLine(strStd);
	printLineStd(str);
	checkStringView(str);


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
	str.pushBack('X');
	str.popBack();
	str.shrinkToFit();
	auto allocator = str.getAllocator();


	printLineString2(str);
	printLineString2(strConst);
	append(str, 'X');
	String2 str2 = "Test2";
	printLine(str2);
	printLineStd(str2);
	checkStringView(str2);



	Float flt1 = NaN;
	Float flt2 = Infinity;
	if (str.empty() == False) {
		cout << "String is not empty" << endl;
	}


	Array<Int> arr1 { 0, 1, 2, 3 };
	Array<Int> arr2 { 4, 5, 6, 7 };
	arr1.append(arr2);
	arr1.insert(arr1.begin() + 4, arr2);
	arr1.assign(arr2);
	arr1.pushBack(8);
	arr1.popBack();
	arr1.emplaceBack(9);
	arr1.shrinkToFit();
	Int maxSizeVec = arr1.maxSize();
	auto allocatorVec = arr1.getAllocator();


	class ContactInfo {
	public:
		String firstName;
		String familyName;
		String phone;
	};
	Map<String, ContactInfo> map1;
	map1["A"] = ContactInfo("Sean", "Connery", "0123456789");
	map1["A"] = ContactInfo { .firstName = "Sean", .familyName="Connery", .phone="0123456789" };
	map1["B"] = ContactInfo("Roger", "Moore", "012345678");
	Map<String, ContactInfo> map2;
	map2["C"] = ContactInfo("Pierce", "Brosnan", "01234567");
	Bool containsD1 = map2.contains("D");
	map2["D"] = ContactInfo("Daniel");
	map2["D"] = ContactInfo("Daniel", "Craig");
	map2["D"] = ContactInfo("Daniel", "Craig", "012345");
	Bool containsD2 = map2.contains("D");

	map1.insert(map2);
	map1.insertOrAssign("D", ContactInfo("Daniel", "Craig", "0123456"));
	map1.insertOrAssign("E", ContactInfo("Timothy", "Dalton", "012345"));

	auto lowerBound = map1.lowerBound("B");
	auto upperBound = map1.upperBound("B");

	auto keyComparer   = map1.keyComp();
	auto valueComparer = map1.valueComp();


	FixedSizeArray<Int, 3> arr3;
	FixedSizeArray<Int, 3> arr4 = { 0, 1, 2 };
	array<Int, 3>          arr5 = { 0, 1, 2 };
	//TODO
	//FixedSizeArray<Char, 4> arr6 = toFixedSizeArray("Foo");


	try {
		throw Exception("Test");
	} catch (const Exception& ex) {
		cout << "Exception " << ex.what() << endl;
	} catch (const exception& ex) {
		cout << "exception " << ex.what() << endl;
	} catch (...) {
		cout << "Unknown exception" << endl;
	}

	try {
		throw Exception1("Test");
	} catch (const Exception2& ex) {
		cout << "Exception2 " << ex.what() << endl;
	} catch (...) {
		cout << "Unknown exception" << endl;
	}

	try {
		throw Exception2("Test");
	} catch (const Exception1& ex) {
		cout << "Exception1 " << ex.what() << endl;
	} catch (...) {
		cout << "Unknown exception" << endl;
	}

	try {
		throw runtime_error("Test");
	} catch (const Exception& ex) {
		cout << "Exception " << ex.what() << endl;
		//} catch (const exception& ex) {
		//	cout << "exception " << ex.what() << endl;
	} catch (...) {
		cout << "Unknown exception" << endl;
	}

	try {
		throw exception();
	} catch (const Exception& ex) {
		cout << "Exception " << ex.what() << endl;
	//} catch (const exception& ex) {
	//	cout << "exception " << ex.what() << endl;
	} catch (const ExceptionBase& ex) {
		cout << "ExceptionBase " << ex.what() << endl;
	} catch (...) {
		cout << "Unknown exception" << endl;
	}


	Signal<Int, Float, String> testSignal;
	testSignal.connect(&onTest3Args);

	// Nice to have:
	testSignal.connect(&onTest2Args);
	testSignal.connect(&onTest1Arg);
	testSignal.connect(&onTest0Args);

	//TODO Would be nice to have:
	//testSignal.disconnect(&onTest3Args);
	//testSignal.disconnect(&onTest2Args);
	//testSignal.disconnect(&onTest1Arg);
	//testSignal.disconnect(&onTest0Args);

	testSignal.emit(1, 3.1415f, "Test Signal");


	return 0;
}
