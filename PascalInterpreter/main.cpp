#include "Interpreter.h"
#include <iostream>

using namespace PascalInterpreter;

int main()
{
	Interpreter<std::wstring> interpret = Interpreter<std::wstring>(L"5 + 5");
	auto result = interpret.Expression();
	std::wcout << result << std::endl;
	system("pause");
	return 0;
}