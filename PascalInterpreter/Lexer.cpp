#include "Lexer.h"

namespace PascalInterpreter
{
	void Lexer::Error()
	{
		try
		{
			throw std::logic_error::logic_error("Error parsing input!");
		}
		catch (const std::exception& exceptionObject)
		{
			std::cerr << exceptionObject.what();
		}
	}

	void Lexer::Advance()
	{
		char_position += 1;
		if (char_position >= text.length())
			current_char = 0;
		else current_char = text.at(char_position);
	}

	void Lexer::SkipWhitespace()
	{
		while (!text.empty() && isspace(text.at(char_position)))
			Advance();
	}

	int Lexer::Integer()
	{
		std::string intToBuild("");
		auto character = text.at(char_position);
		while (!text.empty() && isdigit(current_char))
		{
			intToBuild += text.at(char_position);
			Advance();
		}
		return std::stoi(intToBuild);
	}

	std::shared_ptr<Token<std::string>> Lexer::GetNextToken()
	{
		while (current_char != '\0')
		{
			if (isspace(current_char))
			{
				SkipWhitespace();
			}
			else if (isdigit(current_char))
			{
				std::shared_ptr<Token<std::string>> token =
					std::make_shared<Token<std::string>>(INTEGER_TYPE, std::to_string(Integer()));
				Advance();
				return token;
			}
			else if (current_char == ADDITION_OPERATOR_SYMBOL)
			{
				std::shared_ptr<Token<std::string>> token =
					std::make_shared<Token<std::string>>(ADDTION_OPERATOR, std::string(1, current_char));
				Advance();
				return token;
			}
			else if (current_char == SUBTRACTION_OPERATOR_SYMBOL)
			{
				std::shared_ptr<Token<std::string>> token =
					std::make_shared<Token<std::string>>(SUBSTRACTION_OEPRATOR, std::string(1, current_char));
				Advance();
				return token;
			}
			else if (current_char == MULTIPLICATION_OPERATOR_SYMBOL)
			{
				std::shared_ptr<Token<std::string>> token =
					std::make_shared<Token<std::string>>(MULITPLICATION_OPERATOR, std::string(1, current_char));
				Advance();
				return token;
			}
			else if (current_char == DIVISION_OPERATOR_SYMBOL)
			{
				std::shared_ptr<Token<std::string>> token =
					std::make_shared<Token<std::string>>(DIVISION_OPERATOR, std::string(1, current_char));
				Advance();
				return token;
			}
			else if (current_char == MODULUS_OPERATOR_SYMBOL)
			{
				std::shared_ptr<Token<std::string>> token =
					std::make_shared<Token<std::string>>(MODULUS_OPERATOR, std::string(1, current_char));
				Advance();
				return token;
			}
			else
			{
				Error();
			}
		}
		return nullptr;
	}

	//TODO: Add current_token console print out.
	//Currently not printing out the current_token ptr_object
	std::ostream& operator<< (std::ostream& outputStream, const Lexer& lexer)
	{
		outputStream << lexer.text << lexer.current_char << lexer.char_position;
		return outputStream;
	}
}