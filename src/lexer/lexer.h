#ifndef LEXER_H
#define LEXER_H

#include "token.h"

class Lexer {

    public:
        Lexer(string inputFile);
        void tokenize();

        string m_content;
        int m_cur_char_index;

    private:
        Token nextToken();
        string get_ident();
        void whitespace();
        void consume();
        bool match(char symbol);
        bool is_letter(char symbol);
        bool is_digit(char symbol);

};


#endif