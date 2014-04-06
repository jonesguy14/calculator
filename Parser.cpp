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

bool Parser::isOperator(char c) {
    if (c=='+' || c=='-' || c=='*' || c=='/' || c=='^') {
        return true;
    }
    else return false;
}

bool Parser::isLeftAsso(char c) {
    if (c!='^') {
        return true;
    }
    else return false;
}

int Parser::checkPrecedence(char a, char b) {
    int ap = 0;
    int bp = 0;
    //assign precedence of a
    if (a=='^') {
        ap = 4;
    }
    else if (a=='*' || a=='/') {
        ap = 3;
    }
    else if (a=='+' || a=='-') {
        ap = 2;
    }
    //assign precedence of b
    if (b=='^') {
        bp = 4;
    }
    else if (b=='*' || b=='/') {
        bp = 3;
    }
    else if (b=='+' || b=='-') {
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
        else if (isOperator(input[i])) {
            while (isOperator(sh_stack.getTop()) && ((isLeftAsso(input[i]) && checkPrecedence(input[i], sh_stack.getTop())==0) || checkPrecedence(input[i], sh_stack.getTop())==-1)) {
                output.append(1, sh_stack.pop());
                output.append(" ");
            }
            sh_stack.push(input[i]);
            i++;
        }
        else if (input[i]=='(') {
            sh_stack.push(input[i]);
            i++;
            }
        else if (input[i]==')') {
            while (sh_stack.getTop()!='(') {
                output.append(1, sh_stack.pop());
                output.append(" ");
                }
            sh_stack.pop();
            i++;
        }
        else if (input[i]==' ') {
            i++;
        }
    }
    while (sh_stack.hasItems())
    {
        output.append(1, sh_stack.pop());
        output.append(" ");
    }
    cout<<output<<endl;
    return output;
}
