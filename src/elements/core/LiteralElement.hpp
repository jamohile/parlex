#ifndef LITERALELEMENT_HPP
#define LITERALELEMENT_HPP

#include "Element.hpp"
#include <string>

/** Represents a single string literal. 
 * This is often also used while developing, 
 * so that any constructs that cannot yet be parsed 
 * will be thrown into a Literal.
*/

class LiteralElement : public Element {
    public:
        LiteralElement(std::string literal);
        ~LiteralElement();

        std::string toString(int depth = 0);
    private:
        std::string literal;
};

#endif /* LITERALELEMENT_HPP */
