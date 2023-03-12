#pragma once
#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <string>

namespace PascalInterpreter
{
    template<class T>
    class Token
    {
        template<typename T>
        friend std::ostream& operator<<(std::ostream& output, const Token<T>& token);

        public:
        Token<T>(std::string type, T value) : token_type(type), token_value(value)
        {}
        Token<T>(T value) : token_value(value), token_type("")
        {}
        Token<T>() = default;

        public:
        Token<T>& operator=(const Token<T>& rhs)
        {
            token_value = rhs.token_value;
            token_type = rhs.token_type;
            return *this;
        }

        public:
        const T GetTokenValue() const { return token_value; }
        const std::string& GetTokenType() const { return token_type; }

        private:
        T token_value = 0;
        std::string token_type = std::string("");
    };

    template<typename T>
    std::ostream& operator<<(std::ostream& output, const Token<T>& token)
    {
        output << token.token_value << token.token_type;
        return output;
    }
}
#endif // !TOKEN_H
