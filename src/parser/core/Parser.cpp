#include "Parser.hpp"

Parser::Parser(){
    // This is important!!! Otherwise we get weird segfaults due to C memory management.
    this -> defaultJump = NULL;
};

Parser::~Parser(){

};

void Parser::onParseComplete(){};