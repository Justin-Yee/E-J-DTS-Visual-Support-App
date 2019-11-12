#include <igloo/igloo.h>
#include <../ViewReport.h>
using namespace igloo;
/* Example
Context(AnyDescriptiveName){ //its not important
 Can declare objects here
 Object objects = new Object

  Spec(DescriptiveTestName){
	int TestValue = ReturnNumber(69);
	int TrueValue = 69;
	Assert::That(TestValue, Equals(TrueValue));// if Test isnt 69, then fails
	}

  Spec(test2){
   Assert::That(blah, !Equals(blah2));
  }

 };

 
 https://github.com/joakimkarlsson/igloo/blob/master/tests/igloo_tests.cpp
*/
int main() {
	// Run all the tests defined above
	return TestRunner::RunAllTests();
}
