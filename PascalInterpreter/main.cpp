#include "Token.h"
#include "OperatorTokenSymbol.h"
#include "TokenType.h"
#include "Interpreter.h"

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

    Interpreter inputCode("2 + 2");
    std::cout << "Outputting the interpreter object." << std::endl;
    std::cout << inputCode << std::endl;

    std::cout << "Tesitng out the interpreter" << std::endl;
    Interpreter interpreter = Interpreter("44 + 4");
    auto result = interpreter.Expression();
    std::cout << result << std::endl;

    Interpreter interpreterSub = Interpreter("4 - 4");
    auto subResult = interpreterSub.Expression();
    std::cout << subResult << std::endl;

    Interpreter interpreterTimes = Interpreter("4 * 4");
    auto timesResult = interpreterTimes.Expression();
    std::cout << timesResult << std::endl;

    Interpreter interpreterDiv = Interpreter("4 / 4");
    auto divResult = interpreterDiv.Expression();
    std::cout << divResult << std::endl;

    Interpreter interpreterMod = Interpreter("4 % 16");
    auto modResult = interpreterMod.Expression();
    std::cout << modResult << std::endl;

    Interpreter interprete = Interpreter("4 + 4 - 2 * 4 / 2");
    auto interpretersResults = interprete.Expression();
    std::cout << interpretersResults << std::endl;

    std::cin >> line;
}