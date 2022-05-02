#pragma once
#ifndef TOKEN_H
#define TOKEN_H

#include <string>


namespace PascalInterpreter 
{
	template <typename T>
	class Token
	{

	public:
		Token<T>() = default;
		Token(const std::wstring& tokenType, T val) : token_type(tokenType), value(val)
		{	}

	public:
		const std::wstring& GetType() const;
		T GetValue();

	private:
		const std::wstring token_type;
		T value;
	};

}

#endif
