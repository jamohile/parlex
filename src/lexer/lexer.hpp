#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <unordered_set>

using namespace std;

/** Import a text file */
string import(string path);

/* Convert text to a tokenized list */
vector<string> tokenize(string raw);

/* Used by tokenizer. */
unordered_set<char> getPunctuation();

#endif /* LEXER_HPP */
