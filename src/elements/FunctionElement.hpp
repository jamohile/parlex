#ifndef FUNCTIONELEMENT_HPP
#define FUNCTIONELEMENT_HPP

#include "core/Element.hpp"
#include <string>
#include "core/CollectionElement.hpp"
#include "core/LiteralElement.hpp"


/** Represents a (C/JS) esque function. */
/** TODO: Work in progress */

class FunctionElement : public Element {
    public:
        FunctionElement();
        ~FunctionElement();

        std::string toString(int depth);

    public:
        /** These compose a function name, argument list, and body */
        LiteralElement * identifier;
        CollectionElement * arguments;
        CollectionElement * body;
        
};

#endif /* FUNCTIONELEMENT_HPP */
