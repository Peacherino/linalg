#include "lin-algebra.h"

#include "test-linalg.h"
#include <cppunit/ui/text/TestRunner.h>

int main() {
  CppUnit::TextUi::TestRunner runner;
  runner.addTest(LinalgTest::suite());
  runner.run();
  return 0;
}
