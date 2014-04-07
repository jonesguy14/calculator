#include "Parser.h"
#include "shuntingStack.cpp"
#include "intStack.cpp"
#include <ctype.h>
#include <string>
#include <math.h>
#include <stdlib.h>


Parser::Parser() {
    input = " ";
}

Parser::Parser(string input) {
    this->input = input;
}
double Parser::parse(string input) {
    return calculate_from_rpn(shunting_yard(input));
}

bool Parser::isOperator(string c) {
    if (c.compare("+")==0 || c.compare("-")==0 || c.compare("*")==0 || c.compare("/")==0 || c.compare("^")==0) {
        return true;
    }
    else return false;
}

bool Parser::isLeftAsso(string c) {
    if (c.compare("^")!=0) {
        return true;
    }
    else return false;
}

int Parser::checkPrecedence(string a, string b) {
    int ap = 0;
    int bp = 0;
    //assign precedence of a
    if (a.compare("^")==0) {
        ap = 4;
    }
    else if (a.compare("*")==0 || a.compare("/")==0) {
        ap = 3;
    }
    else if (a.compare("+")==0 || a.compare("-")==0) {
        ap = 2;
    }
    //assign precedence of b
    if (b.compare("^")==0) {
        bp = 4;
    }
    else if (b.compare("*")==0 || b.compare("/")==0) {
        bp = 3;
    }
    else if (b.compare("+")==0 || b.compare("-")==0) {
        bp = 2;
    }
    //compare precedence
    if (ap < bp) {
        return -1;
    }
    else if (ap > bp) {
        return 1;
    }
    else return 0;
}

double Parser::calculate_from_rpn(string input) {
    int j = 0;
    int num_digits = 0;
    intStack i_stack(100);
    while (j<input.length()) {
        if (isdigit(input[j])) {
            num_digits = 0;
            while (isdigit(input[j+num_digits+1])) {
                num_digits++;
            }
            string number = input.substr(j,num_digits+1);
            i_stack.push(atoi(number.c_str()));
            j+=num_digits+1;
        }
        else if (input[j]==' ') {
            j++;
        }
        else {
            int a = i_stack.pop();
            int b = i_stack.pop();
            switch (input[j]) {
            case '+':
                i_stack.push(a+b);
                break;
            case '-':
                i_stack.push(b-a);
                break;
            case '*':
                i_stack.push(a*b);
                break;
            case '/':
                i_stack.push(b/a);
                break;
            case '^':
                i_stack.push(pow(b,a));
                break;
            }
            j++;
        }
    }
    return i_stack.getTop();
}

string Parser::shunting_yard(string input) {
    int i = 0;
    shuntingStack sh_stack(100);
    string output = "";
    while (i<input.length()) {
        if (isdigit(input[i])) {
            output.append(1, input[i]);
            int num_digits = 0;
            while (isdigit(input[i+num_digits+1])) {
                output.append(1, input[i+num_digits+1]);
                num_digits++;
            }
            i+=num_digits+1;
            output.append(" ");
        }
        else if (isOperator(input.substr(i,1))) {
            while (!sh_stack.isEmpty() && isOperator(sh_stack.getTop()) && ((isLeftAsso(input.substr(i,1)) && checkPrecedence(input.substr(i,1), sh_stack.getTop())==0) || checkPrecedence(input.substr(i,1), sh_stack.getTop())==-1)) {
                output.append(sh_stack.pop());
                output.append(" ");
            }
            sh_stack.push(input.substr(i,1));
            i++;
        }
        else if ((input.substr(i,1)).compare("(")==0) {
            sh_stack.push(input.substr(i,1));
            i++;
            }
        else if ((input.substr(i,1)).compare(")")==0) {
            while ((sh_stack.getTop()).compare("(")!=0) {
                output.append(sh_stack.pop());
                output.append(" ");
                }
            sh_stack.pop();
            i++;
        }
        else if ((input.substr(i,1)).compare(" ")==0) {
            i++;
        }
        else if ((input.substr(i, 5)).compare("sqrt:")==0) {
            //sqrt:x
            sh_stack.push(input.substr(i, 5));
            i+=5;
        }
    }
    while (sh_stack.hasItems())
    {
        output.append(sh_stack.pop());
        output.append(" ");
    }
    cout<<output<<endl;
    return output;
}
