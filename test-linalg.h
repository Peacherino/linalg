#ifndef LINALG_TEST_H
#define LINALG_TEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "lin-algebra.h"

class LinalgTest : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(LinalgTest);
    CPPUNIT_TEST(test2x2_determinant);
    CPPUNIT_TEST(test_minor);
    CPPUNIT_TEST(test_replace);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

    void test2x2_determinant();
    void test_minor();
    void test_replace();
};

#endif // LINALG_TEST_H
