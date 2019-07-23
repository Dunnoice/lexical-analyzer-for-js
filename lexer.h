#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>
#include <set>

#define a 46
#define b 25

struct Token
{
	std::string status;
	std::string value;
	int line;
	int position;
};

enum STATUS
{
	START,
	IDENT,
	NUMBER,
	REALNUMBER_ONE,
	REALNUMBER_DOT,
	STRING,
	STRING_END,
	STRING_SLASH,
	SLASH,
	ONE_LC,
	MULTI_LC,
	MULTI_LC_PRE_END,
	MULTI_LC_END,
	STAR,
	PLUS,
	PLUSPLUS,
	MINUS,
	MINUSMINUS,
	PERCENT,
	NOT,
	EQUAL,
	TWO_EQUAL,
	THREE_EQUAL,
	SLASHEQUAL,
	STAREQUAL,
	PLUSEQUAL,
	MINUSEQUAL,
	PERCENTEQUAL,
	NOTEQUAL,
	NOT_TWO_EQUAL,
	OPEN_ROUND_BRACKET,
	CLOSE_ROUND_BRACKET,
	OPEN_CURLY_BRACKET,
	CLOSE_CURLY_BRACKET,
	COMMA,
	SEMICOLON,
	AND,
	ANDEQUAL,
	ANDAND,
	OR,
	OREQUAL,
	OROR,
	MORE,
	MOREOREQUAL,
	LESS,
	LESSOREQUAL,
	ERROR
};

struct State
{
	STATUS status;
	bool action;
};

extern std::string statusNames[a];
extern State table[a][b];
extern std::string regexes[b];
extern std::set<std::string> keywords;
extern std::set<std::string> reserved_names;
extern std::set<STATUS> skip;
extern STATUS status;
extern STATUS oldStatus;
extern bool action;
extern std::string str;

std::vector<Token> parse(std::string filename);
int getIndex(std::string s);
int checkSymbol(std::vector<Token> &tokens, std::string s, int line, int position);
void checkWord(std::vector<Token> &tokens, std::string str, int line, int position);

#endif //LEXER_H