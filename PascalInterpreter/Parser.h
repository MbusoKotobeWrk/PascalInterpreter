#pragma once
#ifndef PARSER_H
#define PARSER_H

#include "Lexer.h"

namespace PascalInterpreter
{
	class Parser
	{
		public:
		Parser(const Lexer& scanner) : lexer(std::make_shared<Lexer>(scanner))
		{ 
			current_token = std::make_shared<Token<std::string>>(lexer->GetNextToken());
		}
		Parser() = default;


		public:
		void Eat(const std::string&);
		int Expression();


		private:
		int Term();
		void HandleSharedPtrSafety();

		private:
		std::shared_ptr<Token<std::string>> current_token;
		std::shared_ptr<Lexer> lexer;
	};
}

#endif