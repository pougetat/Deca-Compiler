#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <map>
using namespace std;

enum TokenType 
{
    // keywords
    TOKEN_ASM = 0,
    TOKEN_CLASS,
    TOKEN_EXTENDS,
    TOKEN_ELSE,
    TOKEN_FALSE,
    TOKEN_IF,
    TOKEN_INSTANCEOF,
    TOKEN_NEW,
    TOKEN_NULL,
    TOKEN_READINT,
    TOKEN_READFLOAT,
    TOKEN_PRINT,
    TOKEN_PRINTLN,
    TOKEN_PRINTLNX,
    TOKEN_PRINTX,
    TOKEN_PROTECTED,
    TOKEN_RETURN,
    TOKEN_THIS,
    TOKEN_TRUE,
    TOKEN_WHILE,

    // identifier
    TOKEN_IDENT,

    // operators
    TOKEN_COMP_LESS,
    TOKEN_COMP_LESSEQ,
    TOKEN_COMP_MORE,
    TOKEN_COMP_MOREEQ,
    TOKEN_OP_PLUS,
    TOKEN_OP_MINUS,
    TOKEN_OP_MULT,
    TOKEN_OP_DIV,
    TOKEN_OP_MOD,
    TOKEN_OP_DOT,
    TOKEN_NOT,
    TOKEN_NEQ,
    TOKEN_OP_ASSIGN,
    TOKEN_COMP_EQ,
    TOKEN_AND,
    TOKEN_OR,

    // seperators
    TOKEN_COMMA,
    TOKEN_OPARENT,
    TOKEN_CPARENT,
    TOKEN_OBRACE,
    TOKEN_CBRACE,
    TOKEN_SEMICOLON,

    // literals
    TOKEN_LITERAL_INT,
    TOKEN_LITERAL_FLOAT,
    TOKEN_LITERAL_STRING,

    // EOF
    TOKEN_EOF
};

static const char* token_names[] =
{
    "TOKEN_ASM", "TOKEN_CLASS", "TOKEN_EXTENDS", "TOKEN_ELSE", "TOKEN_FALSE",
    "TOKEN_IF", "TOKEN_INSTANCEOF", "TOKEN_NEW", "TOKEN_NULL", "TOKEN_READINT",
    "TOKEN_READFLOAT", "TOKEN_PRINT", "TOKEN_PRINTLN", "TOKEN_PRINTLNX",
    "TOKEN_PRINTX", "TOKEN_PROTECTED", "TOKEN_RETURN", "TOKEN_THIS", "TOKEN_TRUE",
    "TOKEN_WHILE", "TOKEN_IDENT", "TOKEN_COMP_LESS", "TOKEN_COMP_LESSEQ",
    "TOKEN_COMP_MORE", "TOKEN_COMP_MOREEQ", "TOKEN_OP_PLUS", "TOKEN_OP_MINUS",
    "TOKEN_OP_MULT", "TOKEN_OP_DIV", "TOKEN_OP_MOD", "TOKEN_OP_DOT", "TOKEN_NOT",
    "TOKEN_NEQ", "TOKEN_OP_ASSIGN", "TOKEN_COMP_EQ", "TOKEN_AND", "TOKEN_OR",
    "TOKEN_COMMA", "TOKEN_OPARENT", "TOKEN_CPARENT", "TOKEN_OBRACE", "TOKEN_CBRACE",
    "TOKEN_SEMICOLON", "TOKEN_LITERAL_INT", "TOKEN_LITERAL_FLOAT",
    "TOKEN_LITERAL_STRING", "TOKEN_EOF"
};

static map<string, TokenType> keyword_map =
{
    {"asm", TOKEN_ASM},
    {"class", TOKEN_CLASS},
    {"extends", TOKEN_EXTENDS},
    {"else", TOKEN_ELSE},
    {"false", TOKEN_FALSE},
    {"if", TOKEN_IF},
    {"instanceof", TOKEN_INSTANCEOF},
    {"new", TOKEN_NEW},
    {"null", TOKEN_NULL},
    {"readint", TOKEN_READINT},
    {"readfloat", TOKEN_READFLOAT},
    {"print", TOKEN_PRINT},
    {"println", TOKEN_PRINTLN},
    {"printlnx", TOKEN_PRINTLNX},
    {"printx", TOKEN_PRINTX},
    {"protected", TOKEN_PROTECTED},
    {"return", TOKEN_RETURN},
    {"this", TOKEN_THIS},
    {"true", TOKEN_TRUE},
    {"while", TOKEN_WHILE}
};

class Token {

    public:

        Token(TokenType token_type, string token_string);

        TokenType m_token_type;
        string m_token_string;

};

#endif