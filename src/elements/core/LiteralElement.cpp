#include "LiteralElement.hpp"
#include <string>

LiteralElement::LiteralElement(std::string literal): Element("Literal"), literal(literal){
    
};

std::string LiteralElement::toString(int depth){
    return std::string(depth, ' ') + "Literal: " + this -> literal + "\n";
}