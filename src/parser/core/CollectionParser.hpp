#ifndef COLLECTIONPARSER_HPP
#define COLLECTIONPARSER_HPP

#include <string>
#include "../../elements/core/CollectionElement.hpp"
#include "Parser.hpp"

/** Arguably the most important parser, since most things derive from collection.
 * This parses general "multiple statement" style logic. 
 * This includes lists of arguments, function bodies, class declarations, etc.
 */
class CollectionParser : public Parser{
    public:
        CollectionParser(std::string delimiter = "", std::string rootName = "CollectionElement");
        ~CollectionParser();

        CollectionElement * parse(std::vector<std::string> tokens, int* index);
    private:
        /**
         * Since all collection parsers iterate an unknown number of entities, 
         * the delimited signals "this collection is done." e.g. "{" or ";"
         */ 
        std::string delimiter;
        /** Since so many parsers extend this, we allow for custom root names. 
         * For example, "RootElement", "BlockElement". This allows for custom parsers
         * to extend CollectionParser without needing the overhead of a new element.
         * (They inherit CollectionElement)
        */
        std::string rootName;
};

#endif /* COLLECTIONPARSER_HPP */
