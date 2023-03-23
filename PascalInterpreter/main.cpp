#include "Token.h"
#include "OperatorTokenSymbol.h"
#include "TokenType.h"
#include "Lexer.h"
#include "Parser.h"

using namespace PascalInterpreter;

int main()
{
    Token<int> token("Integer", 44);
    Token<int> copiedToken;
    Token<std::string> tokenTwo("Integer", "44");
    std::string line("");
    const std::string& tokenValue = token.GetTokenType();
    std::cout << tokenValue << std::endl;
    std::cout << "This is the copied token" << std::endl;
    copiedToken = token;
    std::cout << copiedToken << std::endl;

    if (ADDITION_OPERATOR_SYMBOL == '+')
        std::cout << "Operator comparison using defined contansts works." << std::endl;

    if (token.GetTokenType().compare(INTEGER_TYPE))
        std::cout << "Oh yeah! this is an Integer type token" << std::endl;

    Lexer inputCode("2 + 2");
    std::cout << "Outputting the interpreter object." << std::endl;
    std::cout << inputCode << std::endl;

    std::cout << "Tesitng out the interpreter" << std::endl;
    Lexer lexAdd = Lexer("44 + 4");
    Parser parseAdd = Parser(lexAdd);
    auto addResult = parseAdd.Expression();
    std::cout << addResult << std::endl;

    Lexer lexSub = Lexer("4 - 4");
    Parser parseSub = Parser(lexSub);
    auto subResult = parseSub.Expression();
    std::cout << subResult << std::endl;

    Lexer lexMult = Lexer("4 * 4");
    Parser parseMult = Parser(lexMult);
    auto multResult = parseMult.Expression();
    std::cout << multResult << std::endl;

    Lexer lexDiv = Lexer("4 / 4");
    Parser parseDiv = Parser(lexDiv);
    auto divResult = parseDiv.Expression();
    std::cout << divResult << std::endl;

    Lexer lexMod = Lexer("4 % 16");
    Parser parseMod = Parser(lexMod);
    auto modResult = parseMod.Expression();
    std::cout << modResult << std::endl;

    Lexer lexer = Lexer("4 + 4 - 2 * 4 / 2");
    Parser parser = Parser(lexer);
    auto parserResults = parser.Expression();
    std::cout << parserResults << std::endl;

    std::cin >> line;
}