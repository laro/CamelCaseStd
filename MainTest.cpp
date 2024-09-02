#include <cilia/String.hpp>
#include <cilia/Vector.hpp>

using namespace cilia;

auto printLineCil(const String& str) {
    using namespace std;
    cout << str << endl;
}

auto printLineStd(const std::string& str) {
    using namespace std;
    cout << str << endl;
}

int main() {
    String      strCil = "TestCil";
    std::string strStd = "TestStd";

    printLineStd(strCil);
    printLineCil(strCil);
    printLineStd(strStd);
    printLineCil(strStd);

    return 0;
}
