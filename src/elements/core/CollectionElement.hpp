#ifndef COLLECTIONELEMENT_HPP
#define COLLECTIONELEMENT_HPP

#include "Element.hpp"
#include <vector>

/** This is the most important Element subclass.
 *  Most other elements will derive from this.
 * It is used to represent an arbitrary collection of sub elements according to some parse rules.
 */

class CollectionElement : public Element {
    public:
        CollectionElement(std::string name = "CollectionElement");
        ~CollectionElement();

        void addElement(Element * e);

        std::string toString(int depth = 0);

        std::vector<Element *> elements;

};


#endif /* COLLECTIONELEMENT_HPP */
