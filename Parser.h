#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include <iostream>

using namespace std;

class Parser {
public:
    Parser();
    Parser(string);
    double parse(string);
    string input;
    string shunting_yard(string);

private:
    bool isOperator(char);
    bool isLeftAsso(char);
    int checkPrecedence(char, char);
    double calculate_from_rpn(string);

};


#endif // PARSER_H_INCLUDED
