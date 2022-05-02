#pragma once
#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "Token.h"
#include "TokenType.h"
#include "OperatorTokenSymbol.h"
#include <stdexcept>
#include <iostream>

namespace PascalInterpreter 
{
	template<typename T>
	class Interpreter
	{
	public:
		Interpreter<T>() = default;
		Interpreter(const std::wstring& txt) :
			text(txt)
		{}
		Interpreter(const std::wstring& txt, wchar_t curr_char, size_t pos) :
			text(txt), current_char(current_char), char_position(pos)
		{}

	public:
		void Error();
		void Advance();
		void SkipWhitespace();
		int Integer(); 
		T& GetNextToken() const;
		void Eat(const std::wstring&);
		T Expression();


	private:
		std::wstring text;
		wchar_t current_char;
		size_t char_position;
		Token<T> currentToken;
	};
}


#endif // !INTERPRETER_H

