#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include <iostream>

//using namespace std;

class Parser {
    public:
        Parser();
        Parser(std::string);
        std::string parse(std::string);
        std::string input;
        std::string last_ans;
        std::string shunting_yard(std::string);

    private:
        bool isOperator(std::string);
        bool isLeftAsso(std::string);
        int getPrecedence(std::string);
        int checkPrecedence(std::string, std::string);
        double calculate_from_rpn(std::string);

};


#endif // PARSER_H_INCLUDED
