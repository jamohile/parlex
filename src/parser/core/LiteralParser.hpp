#ifndef LITERALPARSER_HPP
#define LITERALPARSER_HPP

#include "CollectionParser.hpp"
#include "../../elements/core/LiteralElement.hpp"

/** Very simple, parses a single token into a string. 
 * We use a parser just to allow a nice consistent API */

class LiteralParser : public Parser {
    public:
        LiteralParser();
        ~LiteralParser();
        LiteralElement * parse(std::vector<std::string> tokens, int* index);
};

#endif /* LITERALPARSER_HPP */
