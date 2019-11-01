#include "FunctionElement.hpp"

FunctionElement::FunctionElement() : Element("FunctionElement"), identifier(NULL), arguments(NULL), body(NULL) {};
FunctionElement::~FunctionElement(){};

std::string FunctionElement::toString(int depth){
    /** Generate a rough name then recursively compose the rest of the string. */
    std::string root = std::string(depth, ' ') + "Function: " + this->identifier->toString();
    root += this->arguments->toString(depth + 4);
    root += this->body->toString(depth + 4);
    return root;
}