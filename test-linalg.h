#ifndef LINALG_TEST_H
#define LINALG_TEST_H

#include "lin-algebra.h"
#include <cppunit/extensions/HelperMacros.h>

class LinalgTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(LinalgTest);
  CPPUNIT_TEST(test2x2_determinant);
  CPPUNIT_TEST(test_minor);
  CPPUNIT_TEST(test_replace);
  CPPUNIT_TEST(test3x3_determinant);
  CPPUNIT_TEST(test_solve);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp();
  void tearDown();

  void test2x2_determinant();
  void test_minor();
  void test_replace();
  void test3x3_determinant();
  void test_solve();
};

#endif // LINALG_TEST_H
