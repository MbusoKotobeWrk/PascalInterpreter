#include "Interpreter.h"

namespace PascalInterpreter
{
	void Interpreter::Error()
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

	void Interpreter::Advance()
	{
		char_position += 1;
		if (char_position >= text.length())
			current_char = 0;
		else current_char = text.at(char_position);
	}

	void Interpreter::SkipWhitespace()
	{
		while (!text.empty() && isspace(text.at(char_position)))
			Advance();
	}

	int Interpreter::Integer()
	{
		std::string intToBuild("");
		auto character = text.at(char_position);
		while (!text.empty() && isdigit(current_char))
		{
			intToBuild += text.at(char_position);
			Advance();
			//character = text.at(char_position);
		}
		return std::stoi(intToBuild);
	}

	std::shared_ptr<Token<std::string>> Interpreter::GetNextToken()
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
				std::make_shared<Token<std::string>> (INTEGER_TYPE, std::to_string(Integer()));
				Advance();
				return token;
			}
			else if (current_char == ADDITION_OPERATOR_SYMBOL)
			{
				std::shared_ptr<Token<std::string>> token = 
				std::make_shared<Token<std::string>> (ADDTION_OPERATOR, std::string(1, current_char));
				Advance();
				return token;
			}
			else if (current_char == SUBTRACTION_OPERATOR_SYMBOL)
			{
				std::shared_ptr<Token<std::string>> token = 
				std::make_shared<Token<std::string>> (SUBSTRACTION_OEPRATOR, std::string(1, current_char));
				Advance();
				return token;
			}
			else if (current_char == MULTIPLICATION_OPERATOR_SYMBOL)
			{
				std::shared_ptr<Token<std::string>> token = 
				std::make_shared<Token<std::string>> (MULITPLICATION_OPERATOR, std::string(1, current_char));
				Advance();
				return token;
			}
			else if (current_char == DIVISION_OPERATOR_SYMBOL)
			{
				std::shared_ptr<Token<std::string>> token = 
				std::make_shared<Token<std::string>> (DIVISION_OPERATOR, std::string(1, current_char));
				Advance();
				return token;
			}
			else if (current_char == MODULUS_OPERATOR_SYMBOL)
			{
				std::shared_ptr<Token<std::string>> token = 
				std::make_shared<Token<std::string>> (MODULUS_OPERATOR, std::string(1, current_char));
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

	/*PARSER CODE*/

	void Interpreter::Eat(const std::string& tokenType)
	{
		if (current_token->GetTokenType()._Equal(tokenType))
			current_token = GetNextToken();
		else Error();
	}

	int Interpreter::Expression()
	{
		/*current_token = GetNextToken();

		*
		* The assumption here is that
		* the token is an integer.
		*
		auto left = current_token;
		Eat(INTEGER_TYPE);

		/**
		* The assumption here is that
		* the token is an arithmetic
		* operator e.g +, -, *, /
		*
		auto arithmeticOperator = current_token;
		if (arithmeticOperator->GetTokenType()._Equal(ADDTION_OPERATOR))
			Eat(ADDTION_OPERATOR);

		if (arithmeticOperator->GetTokenType()._Equal(SUBSTRACTION_OEPRATOR))
			Eat(SUBSTRACTION_OEPRATOR);

		if (arithmeticOperator->GetTokenType()._Equal(MULITPLICATION_OPERATOR))
			Eat(MULITPLICATION_OPERATOR);

		if (arithmeticOperator->GetTokenType()._Equal(DIVISION_OPERATOR))
			Eat(DIVISION_OPERATOR);

		if (arithmeticOperator->GetTokenType()._Equal(MODULUS_OPERATOR))
			Eat(MODULUS_OPERATOR);

		/**
		* The assumption here is that
		* the token is an integer.
		*
		auto right = current_token;
		Eat(INTEGER_TYPE);

		/**
		* At this point it is safe to assume
		* that our expression is in a good syntactic
		* structure that we expect it to be in;
		* which is-> 1 + 1
		*
		* If that is the case, we attempt to
		* process the arithmetic exression.
		*
		//TODO: Overload oeprators for TokenTypes.
		auto operatorS = arithmeticOperator->GetTokenValue().at(TOKEN_VALUE_POS);
		switch (arithmeticOperator->GetTokenValue().at(TOKEN_VALUE_POS))
		{
		case ADDITION_OPERATOR_SYMBOL:
			return std::stoi(left->GetTokenValue()) + std::stoi(right->GetTokenValue());

		case SUBTRACTION_OPERATOR_SYMBOL:
			return  std::stoi(left->GetTokenValue()) - std::stoi(right->GetTokenValue());

		case MULTIPLICATION_OPERATOR_SYMBOL:
			return  std::stoi(left->GetTokenValue()) * std::stoi(right->GetTokenValue());

		case DIVISION_OPERATOR_SYMBOL:
			return std::stoi(left->GetTokenValue()) / std::stoi(right->GetTokenValue());

		case MODULUS_OPERATOR_SYMBOL:
			return std::stoi(left->GetTokenValue()) % std::stoi(right->GetTokenValue());

		default: return -1;
			break;
		}*/
		

		/*New Expression Processing Code*/
		current_token = GetNextToken();
		int result = Term();
		while (
			!current_token->GetTokenType()._Equal(OOET) &&
			current_token->GetTokenType()._Equal(ADDTION_OPERATOR) ||
			current_token->GetTokenType()._Equal(SUBSTRACTION_OEPRATOR) ||
			current_token->GetTokenType()._Equal(MULITPLICATION_OPERATOR) ||
			current_token->GetTokenType()._Equal(DIVISION_OPERATOR) ||
			current_token->GetTokenType()._Equal(MODULUS_OPERATOR))
		{
			std::shared_ptr<Token<std::string>> token = current_token;
			if (token->GetTokenType()._Equal(ADDTION_OPERATOR))
			{
				Eat(ADDTION_OPERATOR);
				result += Term();
				HandleSharedPtrSafety();
			}
			else if (token->GetTokenType()._Equal(SUBSTRACTION_OEPRATOR))
			{
				Eat(SUBSTRACTION_OEPRATOR);
				result -= Term();
				HandleSharedPtrSafety();
			}
			else if (token->GetTokenType()._Equal(MULITPLICATION_OPERATOR))
			{
				Eat(MULITPLICATION_OPERATOR);
				result *= Term();
				HandleSharedPtrSafety();
			}
			else if (token->GetTokenType()._Equal(DIVISION_OPERATOR))
			{
				Eat(DIVISION_OPERATOR);
				result /= Term();
				HandleSharedPtrSafety();
			}
			else if (token->GetTokenType()._Equal(MODULUS_OPERATOR))
			{
				Eat(MODULUS_OPERATOR);
				result %= Term();
				HandleSharedPtrSafety();
			}
			else
			{
				Error();
			}
		}
		return result;
	}

	int Interpreter::Term()
	{
		std::shared_ptr<Token<std::string>> token = current_token;
		Eat(INTEGER_TYPE);
		return std::stoi(token->GetTokenValue());
	}

	void Interpreter::HandleSharedPtrSafety()
	{
		if (!current_token)
		{
			current_token = std::make_shared<Token<std::string>>("OOET", OOET);
		}
	}

	std::ostream& operator<< (std::ostream& out, const Interpreter& txt)
	{
		out << "Text Var" << txt.text << " " << '\n'
			<< "CurrentChar Var" << txt.current_char << " " << '\n'
			<< "CharPosition Var" << txt.char_position << " " << '\n';
		//<< "CurrentToken Obj" << *txt.current_token;
		return out;
	}
}