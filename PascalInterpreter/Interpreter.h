#pragma once
#ifndef INTERPRETER_H
#define INTERPRETER_H

constexpr auto TOKEN_VALUE_POS = 0;

#include <memory>
#include <iostream>
#include "Token.h"
#include "TokenType.h"
#include "OperatorTokenSymbol.h"

namespace PascalInterpreter
{
	class Interpreter
	{
		public:


		public:
		friend std::ostream& operator<< (std::ostream&, const Interpreter&);

		public:
		Interpreter() = default;
		Interpreter(std::string txt) : text(txt)
		{
			current_char = text.at(char_position);
		}

		public:
		void Error();
		void Advance();
		void SkipWhitespace();
		int Integer();
		std::shared_ptr<Token<std::string>> GetNextToken();
		void Eat(const std::string&);
		int Expression();
		

		public:
		Interpreter& operator= (const Interpreter& rhs)
		{
			text = rhs.text;
			current_char = rhs.current_char;
			char_position = rhs.char_position;
			current_token = rhs.current_token;
			return *this;
		}

		private:
		int Term();
		void HandleSharedPtrSafety();

		private:
		std::string text;
		char current_char;
		size_t char_position = 0;
		std::shared_ptr<Token<std::string>> current_token;
	};
}
#endif
