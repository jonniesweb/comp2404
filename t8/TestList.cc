/*
 * TestList.cc
 *
 *  Created on: Mar 17, 2014
 *      Author: jon
 */
#include "List.h"
#include "gtest/gtest.h"

namespace {

// The fixture for testing class Foo.
class TestList : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  TestList() {
    // You can do set-up work for each test here.
  }

  virtual ~TestList() {
    // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  virtual void SetUp() {
    // Code here will be called immediately after the constructor (right
    // before each test).
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test (right
    // before the destructor).
  }

  // Objects declared here can be used by all tests in the test case for Foo.
};

// Tests that the Foo::Bar() method does Abc.
TEST_F(TestList, MethodBarDoesAbc) {
  const string input_filepath = "this/package/testdata/myinputfile.dat";
  const string output_filepath = "this/package/testdata/myoutputfile.dat";
//  Foo f;
//  EXPECT_EQ(0, f.Bar(input_filepath, output_filepath));
  EXPECT_EQ(input_filepath, output_filepath);
}

// Tests that Foo does Xyz.
TEST_F(TestList, DoesXyz) {
  // Exercises the Xyz feature of Foo.
}

}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

//int main(int argc, char **argv) {
//	// test equality operator
//	cout << "All tests should output 1" << endl;
//
//	List l;
//	List j;
//	bool result = (l == j) == 1;
//	cout << "Empty list test: " << result << endl;
//
//	// inequality test
//	l.addFront(new Student("1234", "bob"));
//	result = (l != j) == 0;
//	cout << "Different list test: " << result << endl;
//
//	// index test
//	Student student("1234", "bobby");
//	j.addFront(&student);
//	result = (j[0] == &student) == 1;
//	cout << "Accessing index test: " << result << endl;
//
//}

