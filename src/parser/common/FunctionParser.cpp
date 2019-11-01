#include "FunctionParser.hpp"
#include "ArgumentListParser.hpp"
#include "BlockParser.hpp"
#include "../core/LiteralParser.hpp"

FunctionParser::FunctionParser(){};
FunctionParser::~FunctionParser(){};

/** Parses generic function declarations using composition. */
FunctionElement * FunctionParser::parse(std::vector<std::string> tokens, int* index) {
    FunctionElement * root = new FunctionElement();

    // Increment index by one because we want to ignore the function keyword.
    *index +=1 ;

    // Using composition, use sub parsers to explicitly extract necessary elements.
    root->identifier = (new LiteralParser())->parse(tokens, index);
    root->arguments = (new ArgumentListParser())->parse(tokens, index);
    root->body = (new BlockParser())->parse(tokens, index);

    return root;
};