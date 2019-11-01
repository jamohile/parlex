#ifndef STATEMENTPARSER_HPP
#define STATEMENTPARSER_HPP

#include "Parser.hpp"
#include "CollectionParser.hpp"

/* Parses an individual statement, usually ";" delimited.
* This is very useful in parser development,
* when the individual elements in that statement haven't been defined yet.
*/

class StatementParser: public CollectionParser {
    public:
        StatementParser();
        ~StatementParser();
};

#endif /* STATEMENTPARSER_HPP */
