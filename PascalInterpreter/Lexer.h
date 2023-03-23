#pragma once
#ifndef LEXER_H
#define LEXER_H

#include "Token.h"
#include "TokenType.h"
#include "OperatorTokenSymbol.h"
#include <memory>

namespace PascalInterpreter 
{
	class Lexer
	{
		public:
		friend std::ostream& operator<< (std::ostream&, const Lexer&);

		public:
		Lexer(std::string txt) : text(txt)
		{
			current_char = text.at(char_position);
		}
		Lexer() = default;

		public:
		Lexer& operator= (const Lexer& rhs)
		{
			text = rhs.text;
			current_char = rhs.current_char;
			char_position = rhs.char_position;
			current_token = rhs.current_token;
			return *this;
		}

		public:
		void Error();
		void Advance();
		void SkipWhitespace();
		int Integer();
		std::shared_ptr<Token<std::string>> GetNextToken();

		private:
		std::string text;
		char current_char;
		size_t char_position = 0;
		std::shared_ptr<Token<std::string>> current_token;
	};
}

#endif LEXER_H