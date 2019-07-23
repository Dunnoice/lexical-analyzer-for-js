#include <iostream>
#include <fstream>
#include <vector>

#include "lexer.h"

int main()
{
	std::vector<Token> tokens = parse("input.js");
	std::cout << "tokens.size() " << tokens.size() << std::endl;
	for (int i = 0; i < tokens.size(); i++)
	{
		std::cout << tokens[i].status << "]  " << tokens[i].value << "  [" << tokens[i].line << ":" << tokens[i].position << std::endl;
	}

	char N;
	std::cin >> N;
	return 0;
}
