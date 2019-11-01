#ifndef FUNCTIONPARSER_HPP
#define FUNCTIONPARSER_HPP

#include "Parser.hpp"
#include "../elements/FunctionElement.hpp"

class FunctionParser : public Parser {
    public: 
        FunctionParser();
        ~FunctionParser();

        FunctionElement * parse(std::vector<std::string> tokens, int* index);
};

#endif /* FUNCTIONPARSER_HPP */
