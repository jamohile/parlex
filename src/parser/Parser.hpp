#ifndef PARSER_HPP
#define PARSER_HPP

#include "../elements/core/Element.hpp"
#include <unordered_map>
#include <string>

/** This class will never be used on its own, but provides an interface for
 * other parsers to follow */
class Parser {
    public: 
        Parser();
        ~Parser();

        /* Consume a vector an a current index, 
         *parse as much as possible (for given parser),
         Return an element to the caller */
        virtual Element * parse(std::vector<std::string> tokens, int* index) = 0;
    protected:
        /** See README for explanation. 
         * tldr: Jumps associate keywords with other parsers. */
        std::unordered_map<std::string, Parser *> jumps;
        Parser * defaultJump;

        // This allows derived parsers to hook onto a base parsers's parse and execute more logic.
        virtual void onParseComplete();
};

#endif /* PARSER_HPP */
