#pragma once
#ifndef TOKEN_H
#define TOKEN_H

#include <string>


namespace PascalInterpreter 
{
	template<class T>
	class Token
	{

	public:
		Token<T>() = default;
		Token<T>(const Token<T>& obj) :
			token_type(obj.token_type), token_value(obj.token_value)
		{	}

		Token<T>& operator= (const Token<T>& rhs)
		{
			token_type = rhs.token_type;
			token_value = rhs.token_value;
			return *this;
		}

		Token<T>& operator= (const Token<T>* rhs)
		{
			token_type = rhs->token_type;
			token_value = rhs->token_value;
			return *this;
		}

		Token(const std::string& tokenType, T val) : token_type(tokenType), token_value(val)
		{	}

	public:
		const std::string& GetType() const;
		T GetValue();

	private:
		const std::string token_type;
		T token_value;
	};

}

#endif
