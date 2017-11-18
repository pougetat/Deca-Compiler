#include <fstream>
#include "lexer.h"
#include "token.h"

Lexer::Lexer(string input_file)
{
	// reading input file to string
	ifstream input_stream(input_file);
	m_content = string(
		(istreambuf_iterator<char>(input_stream)),
		istreambuf_iterator<char>()
	);
	m_cur_char_index = 0;

}

void Lexer::tokenize()
{
	Token token = nextToken();

	while (token.m_token_type != TOKEN_EOF)
	{
		cout << token.m_token_string << endl;
		token = nextToken();
	}

}

Token Lexer::nextToken()
{
	while (m_cur_char_index != m_content.length())
	{
		char cur_char = m_content[m_cur_char_index];
		switch(cur_char)
		{
			case ' ': case '\t': case '\n': case '\r':
			{
				whitespace();
				break;
			}

			// recognizing identifier token
			case 'A' ... 'Z': case 'a' ... 'z': case '_': case '$':
			{
				string ident = get_ident();
				return Token(TOKEN_IDENT, ident);
			}

			// recognizing operator tokens
			case '<':
			{
				consume();
				if (match('=')) {
					consume();
					return Token(TOKEN_COMP_LESSEQ, "<=");
				}
				return Token(TOKEN_COMP_LESS, "<");
			}
			case '>':
			{
				consume();
				if (match('=')) {
					consume();
					return Token(TOKEN_COMP_MOREEQ, ">=");
				}
				return Token(TOKEN_COMP_MORE, ">");
			}
			case '+':
			{
				consume();
				return Token(TOKEN_OP_PLUS, "+");
			}
			case '-':
			{
				consume();
				return Token(TOKEN_OP_MINUS, "-");
			}
			case '*':
			{
				consume();
				return Token(TOKEN_OP_MULT, "*");
			}
			case '/':
			{
				consume();
				return Token(TOKEN_OP_DIV, "/");
			}
			case '%':
			{
				consume();
				return Token(TOKEN_OP_MOD, "%");
			}
			case '.':
			{
				consume();
				return Token(TOKEN_OP_DOT, ".");
			}
			case '!':
			{
				consume();
				if (match('=')) {
					consume();
					return Token(TOKEN_NEQ, "!=");
				}
				return Token(TOKEN_NOT, "!");
			}
			case '=':
			{
				consume();
				if (match('=')) {
					consume();
					return Token(TOKEN_COMP_EQ, "==");
				}
				return Token(TOKEN_OP_ASSIGN, "=");
			}
			case '&':
			{
				consume();
				if (match('&')) {
					consume();
					return Token(TOKEN_AND, "&&");
				}
				throw runtime_error("EXPECTED &");
			}
			case '|':
			{
				consume();
				if (match('|')) {
					consume();
					return Token(TOKEN_OR, "||");
				}
				throw runtime_error("EXPECTED |");
			}

			// recognizing seperator tokens
			case ',':
			{
				consume();
				return Token(TOKEN_COMMA, ",");
			}
			case '(':
			{
				consume();
				return Token(TOKEN_OPARENT, "(");
			}
			case ')':
			{
				consume();
				return Token(TOKEN_CPARENT, ")");
			}
			case '{':
			{
				consume();
				return Token(TOKEN_OBRACE, "{");
			}
			case '}':
			{
				consume();
				return Token(TOKEN_CBRACE, "}");
			}
			case ';':
			{
				consume();
				return Token(TOKEN_SEMICOLON, ";");
			}

			default:
				cout << "LEXING ERROR" << endl;
				m_cur_char_index = m_content.length();

		}
	}
	return Token(TOKEN_EOF, "EOF");
}

void Lexer::whitespace()
{
	while (m_content[m_cur_char_index] == ' ' ||
			m_content[m_cur_char_index] == '\t' ||
			m_content[m_cur_char_index] == '\n' ||
			m_content[m_cur_char_index] == '\r')
	{
		consume();
	}
}

void Lexer::consume()
{
	m_cur_char_index++;
}

bool Lexer::match(char symbol)
{
	if (m_cur_char_index < m_content.length() &&
		m_content[m_cur_char_index] == symbol)
	{
		return true;
	}
	return false;
}

bool Lexer::is_letter(char symbol)
{
	return (
		(symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z')
	);
}

bool Lexer::is_digit(char symbol)
{
	return (
		(symbol >= '0' && symbol <= '9')
	);
}

string Lexer::get_ident()
{
	string ident(1, m_content[m_cur_char_index]);

	consume();

	while (
		m_cur_char_index < m_content.length()
			&&
		(
			is_letter(m_content[m_cur_char_index]) ||
			is_digit(m_content[m_cur_char_index]) ||
			m_content[m_cur_char_index] == '_' ||
			m_content[m_cur_char_index] == '$')
		)
	{
		ident += string(1, m_content[m_cur_char_index]);
		consume();
	}

	return ident;

}