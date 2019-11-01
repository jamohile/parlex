#include "BlockParser.hpp"
#include "StatementParser.hpp"
#include "FunctionParser.hpp"

/**
 * Used to parse generic "block style" constructs, such as function bodies.
 **/
BlockParser::BlockParser(): CollectionParser("}", "BlockElement"){
    this->jumps["{"] = NULL;
    /** For example, this generic block may allow sub functions. */
    /** It's possible to extend the block parser and remove this behaviour. */
    this->jumps["function"] = new FunctionParser();
    this->defaultJump = new StatementParser();
};

BlockParser::~BlockParser(){

};
