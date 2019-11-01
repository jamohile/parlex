#include "CollectionElement.hpp"

CollectionElement::CollectionElement(std::string name): Element(name){

};

CollectionElement::~CollectionElement(){

};

void CollectionElement::addElement(Element * e){
    
    this -> elements.push_back(e);
};

std::string CollectionElement::toString(int depth){
    std::string root = std::string(depth, ' ') + this->name + "\n";
    for(int i = 0; i < this -> elements.size(); i++){
        root += this->elements[i]->toString(depth + 4);
    }
    return root;
}