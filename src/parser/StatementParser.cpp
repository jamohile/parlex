#include "StatementParser.hpp"
#include "LiteralParser.hpp"
#include "ArgumentListParser.hpp"

/* Parses an individual statement, usually ";" delimited.
* This is very useful in parser development,
* when the individual elements in that statement haven't been defined yet.
*/

StatementParser::StatementParser() : CollectionParser(";", "StatementElement"){
    this->defaultJump = new LiteralParser();
    this->jumps["("] = new ArgumentListParser();
};

StatementParser::~StatementParser(){};