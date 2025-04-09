#include <stdio.h>
#include <cppunit/extensions/HelperMacros.h>
#include "lin-algebra.h"

bool vector_equal(Dvector &a, Dvector &b) {
    CPPUNIT_ASSERT_EQUAL(a.size(), b.size());
    for (int i=0; i<a.size(); ++i) {
	CPPUNIT_ASSERT_EQUAL(a[i], b[i]);
    }
    return 1;
}

bool matrix_equal(Dmatrix &a, Dmatrix &b) {
    CPPUNIT_ASSERT_EQUAL(a.size(), b.size());
    for (int row=0; row<a.size(); ++row) {
	CPPUNIT_ASSERT_EQUAL(a[row].size(), b[row].size());
	for (int col=0; col<a[row].size(); ++col) {
	    CPPUNIT_ASSERT_EQUAL(a[row][col], b[row][col]);
	}
    }
    return 1;
}

class LinalgTest : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(LinalgTest);
    CPPUNIT_TEST(test2x2_determinant);
    CPPUNIT_TEST(test_minor);
    CPPUNIT_TEST(test_replace);
    CPPUNIT_TEST(test3x3_determinant);
    CPPUNIT_TEST(test_solve);
    CPPUNIT_TEST(test_solvex);
    CPPUNIT_TEST(test_map);
    CPPUNIT_TEST_SUITE_END();


public:
    void test_solvex() {
	Dmatrix input = {{2, 1, -1},
	                 {-3, -1, 2},
			 {-2, 1, 2}};
        Dvector b = {8, -11, -3};
        Dvector out = Solvex(input, b);
	Display(out);
    }


    void setUp() {
    }

    void tearDown() {
    }

    void test2x2_determinant() {
	Dmatrix input = {{1, 2},
	                 {3, 4}};
	Display(input);
	double det = Det(input);
        CPPUNIT_ASSERT_EQUAL(-2.0, det);
    }

    void test_minor() {
	Dmatrix input = {{1, 2, 3},
	                 {4, 5, 6},
			 {7, 8, 9}};
	Dmatrix expected = {{5, 6},
	                    {8, 9}};
	Display(input);
        Dmatrix out = Minor(input, 0);
	Display(out);
	matrix_equal(out, expected);
	Dmatrix expected2 = {{4, 6},
	                     {7, 9}};
        Dmatrix out2 = Minor(input, 1);
	matrix_equal(out2, expected2);
	Display(out2);
    }
    void test_replace() {
	Dmatrix input = {{1, 2, 3},
	                 {4, 5, 6},
			 {7, 8, 9}};
	Dvector b = {10, 11, 12};
        Dmatrix out = Replace(input, 1, b);
	Display(out);
	Dmatrix expected = {{1, 10, 3},
	                    {4, 11, 6},
			    {7, 12, 9}};
	matrix_equal(out, expected);
    }

    void test3x3_determinant() {
	Dmatrix input = {{7, 2, 3},
	                 {4, 5, 6},
			 {7, 8, 10}};
	Display(input);
	double det = Det(input);
        CPPUNIT_ASSERT_EQUAL(9.0, det);
    }
    void test_solve() {
	Dmatrix input = {{2, 3, -1},
	                 {-1, 2, 3},
			 {4, -1, 1}};
	Dvector b = {5, 0, -1};
	Dvector out = Solvex(input, b);
	Dvector expected = {0.25, 1.25, -0.75};
	Display(out);
	vector_equal(expected, out);
    }
    void test_map() {
	Dmatrix input = {{1, 2, 3},
	                 {4, 5, 6},
			 {7, 8, 9}};
	std::map<std::string, double> mymap;
	std::string key = matrix_to_key(input);
	mymap[key] = 123.456;
	cout << "value for matrix key: "<< mymap[key] << endl;
    }    

};

CPPUNIT_TEST_SUITE_REGISTRATION(LinalgTest);
