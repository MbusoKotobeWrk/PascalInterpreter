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
	template<class T>
	class Interpreter
	{
	public:

	public:
		Interpreter() = default;
		Interpreter(const Interpreter& obj) :
			text(obj.text), current_char(obj.current_char), 
			char_position(obj.char_position), currentToken(obj.currentToken)
		{}

		Interpreter& operator= (const Interpreter& rhs)
		{
			text = rhs.text;
			current_char = rhs.current_char;
			char_position = rhs.char_position;
			currentToken = rhs.currentToken;
			return *this;
		}

		Token<T>& operator= (const Token<T>& rhs)
		{
			currentToken = rhs;
			return *currentToken;
		}

		Token<T>* operator= (const Token<T>* rhs)
		{
			currentToken = rhs;
			return &currentToken;
		}

		Interpreter(const std::string& txt) :
			text(txt) 
		{}

		Interpreter(const std::string& txt, char curr_char, size_t pos) :
			text(txt), current_char(current_char), char_position(pos)
		{}
		
		Token<T>* GetNextToken() const
		{
			while (!isblank(current_char))
			{
				if (isspace(current_char))
					SkipWhitespace();

				if (isdigit(current_char))
					return new Token<int>(INTEGER_TYPE, Integer());

				if (current_char == ADDITION_OPERATOR_SYMBOL)
					return new Token<char>(ADDTION_OPERATOR, current_char);

				if (current_char == SUBTRACTION_OPERATOR_SYMBOL)
					return new Token<char>(SUBSTRACTION_OEPRATOR, current_char);

				if (current_char == MULTIPLICATION_OPERATOR_SYMBOL)
					return new Token<char>(MULITPLICATION_OPERATOR, current_char);

				if (current_char == DIVISION_OPERATOR_SYMBOL)
					return new Token<char>(DIVISION_OPERATOR, current_char);

				if (current_char == MODULUS_OPERATOR_SYMBOL)
					return new Token<char>(MODULUS_OPERATOR, current_char);
			}
		}

	public:
		void Error();
		void Advance();
		void SkipWhitespace();
		int Integer(); 
		//Token<T>* GetNextToken() const;
		void Eat(const std::string&);
		int Expression();


	private:
		std::string text;
		char current_char;
		size_t char_position = 0;
		Token<T> currentToken;
	};
}

#endif // !INTERPRETER_H

