#include "Parser.h"
#include "shuntingStack.cpp"
#include "intStack.cpp"
#include <ctype.h>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <sstream>
#include <exception>

using namespace std;

namespace patch {
    template < typename T > std::string to_string( const T& n ) {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

Parser::Parser() {
    input = " ";
    last_ans = "0";
}

Parser::Parser(string input) {
    this->input = input;
    last_ans = "0";
}
string Parser::parse(string input) {
    //string result = to_string(calculate_from_rpn(shunting_yard(input)));
    return patch::to_string(calculate_from_rpn(shunting_yard(input)));
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

int Parser::getPrecedence(string s) {
    if (s.compare("^")==0) {
        return 4;
    }
    else if (s.compare("*")==0 || s.compare("/")==0) {
        return 3;
    }
    else if (s.compare("+")==0 || s.compare("-")==0) {
        return 2;
    }
    else return 0;
}

int Parser::checkPrecedence(string a, string b) {
    int ap = 0;
    int bp = 0;
    //assign precedence of a
    ap = getPrecedence(a);
    //assign precedence of b
    bp = getPrecedence(b);
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
        if (isdigit(input[j]) && input[j-1]!='_') { //make sure its not b in log_b
            //number detected
            num_digits = 0;
            while (isdigit(input[j+num_digits+1])) { //gets how many digits are in number
                num_digits++;
            }
            string number = input.substr(j,num_digits+1);
            if (input[j-1]=='-' && input[j-2]==' ') {
                number = "-" + number;
            }
            cout<<number<<endl;
            i_stack.push(atoi(number.c_str())); //converts to integer and pushes to stack
            j+=num_digits+1;
        }
        else if (input[j]==' ') {
            //space detected, just ignore
            j++;
        }
        else if ((input.substr(j, 5)).compare("sqrt:") == 0) {
            //square root
            num_digits = 0;
            while (isdigit(input[j+num_digits+6])) { //gets how many digits are in rad, i.e. sqrt:xxxx
                num_digits++;
            }
            string number = input.substr(j+5, num_digits+1);
            int rad = atoi(number.c_str());
            i_stack.push(pow(rad, 0.5));
            //cout<<i_stack.getTop()<<endl;
            j += num_digits+6;
        }
        else if ((input.substr(j, 3)).compare("rt:") == 0) {
            //nth root
            num_digits = 0;
            while (isdigit(input[j+num_digits+4])) { //gets how many digits are in rad, i.e. sqrt:xxxx
                num_digits++;
            }
            int n = atoi((input.substr(j-1,1)).c_str());
            string number = input.substr(j+3, num_digits+1);
            int rad = atoi(number.c_str());
            i_stack.push(pow(rad, (1/n)));
            j += num_digits+5;
        }
        else if ((input.substr(j, 4)).compare("log_") == 0) {
            //logarithm
            string base_str = input.substr(j+4, 1);
            int base = atoi(base_str.c_str());
            int arg = i_stack.pop();
            int result = log10(arg)/log10(base);
            i_stack.push(result);
            j+=6;
        }
        else {
            if (input[j]=='-' && isdigit(input[j+1]) && input[j-1]==' ') { //negative number
                j++;
            }
            else {
                //one of the five single char operators (+,-,*,/,^) and not negative operator
                int a = 0;
                int b = 0;
                try {
                    a = i_stack.pop();
                }
                catch (const char* e) {
                    throw e;
                }

                try {
                    b = i_stack.pop();
                }
                catch (const char* e) {
                    throw e;
                }

                cout<<"A:"<<a<<" "<<input[j]<<" B:"<<b<<endl;;

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
    }
    return i_stack.getTop();
}

string Parser::shunting_yard(string input) {
    int i = 0;
    int num_left_paren = 0;
    shuntingStack sh_stack(100);
    string output = "";
    while (i<input.length()) {
        if (isdigit(input[i]) && input[i+1]!=':' && input[i+1]!='r') {
            output.append(1, input[i]);
            int num_digits = 0;
            while (isdigit(input[i+num_digits+1])) {
                output.append(1, input[i+num_digits+1]);
                num_digits++;
            }
            i += num_digits+1;
            output.append(" ");
        }
        else if (isOperator(input.substr(i,1))) {
            if (input[i]=='-' && isdigit(input[i+1]) && input[i-1]==' ') { //negative number i.e. 5 + -24
                i++;
                output.append("-");
            }
            else {
                while (!sh_stack.isEmpty() && isOperator(sh_stack.getTop()) && ((isLeftAsso(input.substr(i,1)) && checkPrecedence(input.substr(i,1), sh_stack.getTop())==0) || checkPrecedence(input.substr(i,1), sh_stack.getTop())==-1)) {
                    output.append(sh_stack.pop());
                    output.append(" ");
                }
                sh_stack.push(input.substr(i,1));
                i++;
            }
        }
        else if ((input.substr(i,1)).compare("(")==0) {
            sh_stack.push(input.substr(i,1));
            num_left_paren++;
            i++;
            }
        else if ((input.substr(i,1)).compare(")")==0) {
            if (num_left_paren > 0) {
                while ((sh_stack.getTop()).compare("(")!=0) {
                    output.append(sh_stack.pop());
                    output.append(" ");
                    }
                num_left_paren--;
                sh_stack.pop();
                i++;
            }
            else {throw "Error with parentheses! You must have parentheses in pairs.";}
        }
        else if ((input.substr(i,1)).compare(" ")==0) {
            i++;
        }
        else if ((input.substr(i, 5)).compare("sqrt:")==0) {
            //sqrt:x
            if (input[i+5]=='-' || input[i+6]=='-') {
                //cout<<"HEY SWRT NEGATIVE"<<endl;
                throw "Negative square root detected. Imaginary numbers are not supported.";
            }
            int num_chars = 0;
            if (input[i+5]!='(' && input[i+6]!='(') { //not a sqrt:(x+y) expression
                while (input[i+num_chars+1]!=' ' && input[i+num_chars+1]!=')' && (i+num_chars+1)<input.length()) { //gets number of digits of sqrt, i.e. sqrt:xxxxx
                    num_chars++;
                }
                output.append(input.substr(i, num_chars+1));
                output.append(" ");
                i += num_chars+1;
            }
            else { //is sqrt with parentheses
                num_chars=0;
                int open_paren = 1;
                int close_paren = 0;
                while ((input.substr(i+num_chars+5, 1)).compare(")")!=0 && open_paren!=close_paren) {
                    //gets length till end of parentheses, taking into account ((54) - (5 + (50))) situations
                    if ((input.substr(i+num_chars+5, 1)).compare("(")==0) {
                        open_paren++;
                    }
                    else if ((input.substr(i+num_chars+5, 1)).compare(")")==0) {
                        close_paren++;
                    }
                    else if (i+num_chars+6 > input.length()) {
                        throw "Error detected with sqrt function. You need to close parentheses.";
                    }
                    num_chars++;
                }
                string eval = parse(input.substr(i+5, num_chars+1)); //parse expression inside ( and )
                eval = "sqrt:"+eval;
                output.append(eval);
                output.append(" ");
                i += num_chars+6;
            }
        }
        else if ((input.substr(i+1, 3)).compare("rt:")==0) {
            //nrt:x
            int num_chars = 0;
            if (input[i+4]!='(' && input[i+5]!='(') { //not a nrt:(x+y) expression
                while (input[i+num_chars+1]!=' ' && input[i+num_chars+1]!=')' && (i+num_chars+1)<input.length()) { //gets number of digits of nrt, i.e. nrt:xxxx
                    num_chars++;
                }
                output.append(input.substr(i, num_chars+1));
                output.append(" ");
                i += num_chars+1;
            }
            else { //is nrt with parentheses
                num_chars=0;
                int open_paren = 1;
                int close_paren = 0;
                while ((input.substr(i+num_chars+4, 1)).compare(")")!=0 && open_paren!=close_paren) {
                    //gets length till end of parentheses, taking into account ((54) - (5 + (50))) situations
                    if ((input.substr(i+num_chars+4, 1)).compare("(")==0) {
                        open_paren++;
                    }
                    else if ((input.substr(i+num_chars+4, 1)).compare(")")==0) {
                        close_paren++;
                    }
                    else if (i+num_chars+5 > input.length()) {
                        throw "Error detected with nrt function. You need to close parentheses.";
                    }
                    num_chars++;
                }
                string eval = parse(input.substr(i+4, num_chars+1)); //parse expression inside ( and )
                cout << eval << endl;
                eval = input.substr(i,1)+"rt:"+eval;
                cout << eval << endl;
                output.append(eval);
                output.append(" ");
                i += num_chars+5;
            }
        }
        else if ((input.substr(i, 4)).compare("log_")==0) {
            //log_b:x
            sh_stack.push(input.substr(i, 6));
            i+=6;
        }
        else if ((input.substr(i, 3)).compare("ans")==0) {
            //user using last ans
            output.append(last_ans);
            output.append(" ");
            i += 3;
        }
        else {
            throw "Invalid expression detected in input. Please try again.";
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
