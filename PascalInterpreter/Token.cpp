#include "Token.h"

template<typename T>
const std::wstring& PascalInterpreter::Token<T>::GetType() const
{
	return token_type;
}

template<typename T>
T PascalInterpreter::Token<T>::GetValue()
{
	return value;
}
