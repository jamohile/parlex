#ifndef ARGUMENTLISTPARSER_HPP
#define ARGUMENTLISTPARSER_HPP

#include "CollectionParser.hpp"
#include "../elements/core/CollectionElement.hpp"

/* Parses a generic list of arguments. 
   As this is a work in progress, it only supports lists of style (a, b, c) etc.
   This could easily be extended to allow more complex behaviour through jumps (see cpp).
*/
class ArgumentListParser : public CollectionParser {
    public:
        ArgumentListParser();
        ~ArgumentListParser();
};

#endif /* ARGUMENTLISTPARSER_HPP */
