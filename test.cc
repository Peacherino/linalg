#include "lin-algebra.h"

#include <cppunit/ui/text/TestRunner.h>
#include "test-linalg.h"


int main() {
    CppUnit::TextUi::TestRunner runner;
    runner.addTest(LinalgTest::suite());
    runner.run();
    return 0;
}
