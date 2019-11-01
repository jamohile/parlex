#ifndef BLOCKPARSER_HPP
#define BLOCKPARSER_HPP

#include "../core/CollectionParser.hpp"

/**
 * Used to parse generic "block style" constructs, such as function bodies.
 **/
class BlockParser : public CollectionParser {
    public:
        BlockParser();
        ~BlockParser();    
};

#endif /* BLOCKPARSER_HPP */
