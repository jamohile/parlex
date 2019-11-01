#include "RootParser.hpp"
#include "BlockParser.hpp"
#include "ArgumentListParser.hpp"

/** Parses the top level of a source. */
RootParser::RootParser(): CollectionParser("", "RootElement"){
    this->jumps["("] = new ArgumentListParser();
    this->jumps["{"] = new BlockParser();
};

RootParser::~RootParser(){

};
