#include "lexer.hpp"

string import(string path){
    string input;
    ifstream file (path);

    char c;
    bool pendingSpace;
    while (file.get(c)){
        input += c;
    }
    file.close();

    return input;
}

/** Take a file of raw source text, convert it into a tokenized array. */
/** This includes removing uneeded whitespace. */
vector<string> tokenize(string raw){
    vector<string> tokens;
    // Used to know whether a character is punctuation or not.
    unordered_set<char> punctuation = getPunctuation();

    char c;
    string buffer;

    // Go through all characters.
    for(int i = 0; i < raw.size(); i++){
        c = raw[i];
        // If the character is a 'terminating character', clear the buffer.
        if(c == ' ' || punctuation.find(c) != punctuation.end()){
            if(buffer.size() > 0){
                tokens.push_back(buffer);
                buffer = "";
            }

            if(c != ' '){
                tokens.push_back(string(1, c));
            }
        }else{
            // Otherwise, add characters to the buffer to be grouped as a token.
            if(c != '\n'){
                buffer += c;                
            }

        }
    }

    if(buffer.size() > 0){
        tokens.push_back(buffer);
    }

    return tokens;
}

unordered_set<char> getPunctuation(){
    unordered_set<char> punctuation;
    punctuation.insert(',');
    punctuation.insert('.');
    punctuation.insert(';');
    punctuation.insert('(');
    punctuation.insert(')');
    punctuation.insert('{');
    punctuation.insert('}');
    return punctuation;
}