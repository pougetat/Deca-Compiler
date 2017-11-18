#include <iostream>
#include "lexer/lexer.h"
using namespace std;

int main(int argc, char * argv[])
{
    Lexer lexer("hello.txt");
    lexer.tokenize();

    return 0;
}