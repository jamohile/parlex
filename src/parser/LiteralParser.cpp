#include "LiteralParser.hpp"

LiteralParser::LiteralParser(){};

/** Very simple, just parses a single token into a LiteralElement */
/* This overhead is necessary as it lets us maintain a constant API */
LiteralElement * LiteralParser::parse(std::vector<std::string> tokens, int* index){
    // Just create a literal element with this string.
    LiteralElement * e = new LiteralElement(tokens[*index]);
    *index += 1;
    return e;
};
