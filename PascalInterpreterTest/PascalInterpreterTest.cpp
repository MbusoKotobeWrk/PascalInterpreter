#include "pch.h"
#include "CppUnitTest.h"
#include "../PascalInterpreter/Interpreter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace PascalInterpreter;

namespace PascalInterpreterTest
{
	TEST_CLASS(PascalInterpreterTest)
	{
		public:
		
			TEST_METHOD(TestMethod1)
			{
				Interpreter<int> interpret = Interpreter<int>(L"55 + 5");
				Assert::AreEqual(interpret.Integer(), 60);
			}
	};
}
