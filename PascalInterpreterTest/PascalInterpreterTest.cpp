#include "pch.h"
#include "CppUnitTest.h"
#include "../PascalInterpreter/Interpreter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace PascalInterpreter;

namespace PascalInterpreterTest
{
	TEST_CLASS(PascalInterpreterTest)
	{
		public:
		
			TEST_METHOD(TestMethod1)
			{
				Interpreter interpret = Interpreter("55 + 5");
				Assert::AreEqual(interpret.Expression(), 60);
			}
	};
}
