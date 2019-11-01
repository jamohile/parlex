#include "./lexer/lexer.hpp"
#include "./parser/common/RootParser.hpp"
#include "./elements/core/CollectionElement.hpp"

int main(int argc, char ** argv){

    /* Get a tokenized list of strings from the source file. */
    vector<string> tokens = tokenize(import(argv[1]));

    /* Define a top level parser */
    int i = 0;
    RootParser rp;

    CollectionElement * root = rp.parse(tokens, &i);

    /*Log the parsed AST*/
    std::cout << root->toString() << std::endl;

    return 0;
}