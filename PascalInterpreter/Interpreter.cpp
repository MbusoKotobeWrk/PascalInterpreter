#include "Interpreter.h"
#include "Token.h"

template<typename T>
void PascalInterpreter::Interpreter<T>::Error()
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

template<typename T>
void PascalInterpreter::Interpreter<T>::Advance()
{
	char_position += 1;
	if (char_position > text.length())
		current_char = 0;
	else current_char = text.at(char_position);
}

template<typename T>
void PascalInterpreter::Interpreter<T>::SkipWhitespace()
{
	while (!text.empty() && isspace(text.at(char_position)))
		Advance();
}

template<typename T>
int PascalInterpreter::Interpreter<T>::Integer()
{
	std::string intToBuild("");
	auto a = text.at(char_position);
	while (!text.empty() && isdigit(text.at(char_position)))
	{
		intToBuild += text.at(char_position);
		Advance();
		//intToBuild.append(text.at(char_position));
	}
	return std::stoi(intToBuild);
}

template<typename T>
void PascalInterpreter::Interpreter<T>::Eat(const std::string& tokenType)
{
	if (currentToken.type.compare(tokenType))
		currentToken = GetNextToken();
	else Error();
}


template<typename T>
int PascalInterpreter::Interpreter<T>::Expression()
{
	int result = 0;
	currentToken = GetNextToken();

	/**
	* The assumption here is that
	* the token is an integer.
	*/
	auto left = currentToken;
	Eat(INTEGER_TYPE);

	/**
	* The assumption here is that
	* the token is an arithmetic
	* operator e.g +, -, *, /
	*/
	auto arithmeticOperator = currentToken;
	if (arithmeticOperator.GetType().compare(ADDTION_OPERATOR))
		Eat(ADDTION_OPERATOR);

	if (arithmeticOperator.GetType().compare(SUBSTRACTION_OEPRATOR))
		Eat(SUBSTRACTION_OEPRATOR);

	if (arithmeticOperator.GetType().compare(MULITPLICATION_OPERATOR))
		Eat(MULITPLICATION_OPERATOR);

	if (arithmeticOperator.GetType().compare(DIVISION_OPERATOR))
		Eat(DIVISION_OPERATOR);

	if (arithmeticOperator.GetType().compare(MODULUS_OPERATOR))
		Eat(MODULUS_OPERATOR);

	/**
	* The assumption here is that
	* the token is an integer.
	*/
	auto right = currentToken;
	Eat(INTEGER_TYPE);

	/**
	* At this point it is safe to assume
	* that our expression is in a good syntax
	* that we expect it to be in;
	* which is-> 1 + 1
	*
	* If that is the case, we attempt to
	* process the arithmetic exression.
	*/
	if (arithmeticOperator.GetValue == ADDITION_OPERATOR_SYMBOL)
		return left.GetValue() + right.GetValue();

	if (arithmeticOperator.GetValue() == SUBTRACTION_OPERATOR_SYMBOL)
		return left.GetValue() - right.GetValue();

	if (arithmeticOperator.GetValue() == MULTIPLICATION_OPERATOR_SYMBOL)
		return left.GetValue() * right.GetValue();

	if (arithmeticOperator.GetValue() == DIVISION_OPERATOR_SYMBOL)
		return left.GetValue() / right.GetValue();

	if (arithmeticOperator.GetValue() == MODULUS_OPERATOR_SYMBOL)
		return left.GetValue() % right.GetValue();
}

