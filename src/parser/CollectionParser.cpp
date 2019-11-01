#include "CollectionParser.hpp"
#include "../elements/core/CollectionElement.hpp"
#include <string>
#include <vector>
#include <iostream>

CollectionParser::CollectionParser(std::string delimiter, std::string rootName): delimiter(delimiter), rootName(rootName) {};
CollectionParser::~CollectionParser(){};

/**
 * Iterates through tokens until the delimiter character.
 * On each token it will:
 *      1) if jump exists: recursively parse it.
 *      2) if it is a delimter, return.
 *      3) if a default jump exists, use that parser.
 *      4) Else, ignore it.
 **/
CollectionElement * CollectionParser::parse(std::vector<std::string> tokens, int * index){
    CollectionElement * root = new CollectionElement(this->rootName);
    // Iterate through all tokens.
    while(*index < tokens.size()){
        std::string token = tokens[*index];
        
        /*Leave if we are done.*/
        if(token == this->delimiter){
            *index += 1;
            /* Call this hook in case there is any special cleanup needed. */
            this->onParseComplete();
            return root;
        }
        // First, check if the current token is registered as a jump.
        if(this->jumps.find(token) != this->jumps.end()){
            // this token is a valid jump.
            // Get the subparser associated with this jump token.
            Parser * subParser = this->jumps.find(token)->second;
            // This is a valid check because parsers can register null jumps.
            // This lets them ignore certain keywords but continue parsing.
            if(subParser != NULL){
                // Recursively parse this element (but still in linear time.)
                // Notice we don't increment. SUBPARSERS are responsible for this.
                // This is because the subparser may need the current token for context.
                root->addElement(subParser->parse(tokens, index));
            } else{
                *index += 1;
            }
        /** Otherwise look for a default handler. */
        } else if (this->defaultJump != NULL) {
            root->addElement(this->defaultJump->parse(tokens, index));
        }else{
            /** Otherwise ignore and increment. */
            *index += 1;
        }
    }
    this->onParseComplete();
    return root;
};