#include "Element.hpp"

Element::Element(std::string name): name(name) {};
Element::~Element(){};

std::string Element::toString(int depth){
    return std::string(depth, ' ') + this->name + "\n";
}