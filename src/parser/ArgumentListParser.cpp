#include "ArgumentListParser.hpp"
#include "LiteralParser.hpp"
#include "../elements/core/LiteralElement.hpp"
#include <iostream>

/** Provides argument list parsing, which could be used by things like if statements, functions, etc.
 * Right now, we assume a structure like (a, b, c),
 * This could easily be extended through more jumps, 
 * and jumping to more complex sub parsers than Literal.
 */

/**
 * We also specify to CollectionParser that ArgumentList ends with a ")"
 **/
ArgumentListParser::ArgumentListParser() : CollectionParser(")", "ArgumentList"){
    /** Ignore this, since it is the starting character.*/
    this->jumps["("] = NULL; 
    /** These aren't necessary as we are tokenized already*/
    this->jumps[","] = NULL; 
    /** For now, just interpret everything as a literal. This could be changed
     * for language specific use. */
    this->defaultJump = new LiteralParser();
};