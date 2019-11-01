#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <string>

/** The base level element. Used to represent AST nodes. */
class Element {
    public:
        Element(std::string name = "Element");
        ~Element();

        /** Used to log the element to console. 
         * Derived classes are encouraged to make this context specific.
        **/
        virtual std::string toString(int depth = 0);
    protected:
        /* The name of this element type. Just for debugging. */
        std::string name;
};


#endif /* ELEMENT_HPP */
