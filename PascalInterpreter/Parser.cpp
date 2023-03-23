#include "Parser.h"

namespace PascalInterpreter
{
	void Parser::Eat(const std::string& tokenType)
	{
		if (current_token->GetTokenType()._Equal(tokenType))
			current_token = lexer->GetNextToken();
		else lexer->Error();
	}

	int Parser::Term()
	{
		std::shared_ptr<Token<std::string>> token = current_token;
		Eat(INTEGER_TYPE);
		return std::stoi(token->GetTokenValue());
	}

	void Parser::HandleSharedPtrSafety()
	{
		if (!current_token)
		{
			current_token = std::make_shared<Token<std::string>>("OOET", OOET);
		}
	}

	int Parser::Expression()
	{
		//current_token = lexer->GetNextToken();
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
				lexer->Error();
			}
		}
		return result;
	}
}