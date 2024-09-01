#include <cilia/String.hpp>
#include <cilia/Vector.hpp>

int main() {
    using namespace cilia;
    using namespace std;

    String strCil = "TestCil";
    string strStd = "TestStd";

    printLineStd(strCil);
    printLineCil(strCil);
    printLineStd(strStd);
    printLineCil(strStd);

    return 0;
}
