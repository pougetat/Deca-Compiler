#ifndef LEXER_H
#define LEXER_H

#include "token.h"
#include <vector>

using namespace std;

class Lexer {

    public:

        Lexer(string inputFile);
        vector<Token> tokenize();

    private:

        Token nextToken();
        string get_ident();
        string get_literal_int();
        string get_literal_string();
        void whitespace();
        void consume();
        bool match(char symbol);
        bool is_letter(char symbol);
        bool is_digit(char symbol);

        string m_content;
        int m_cur_char_index;

};


#endif