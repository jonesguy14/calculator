#include "Parser.h"
#include "History.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    bool gogo = true;
    bool keep_compute = true;
    string input = "";
    Parser P;
    History historian;
    string result = " ";
    while (gogo) {
        cout << endl;
        cout << "Welcome to the calculator!" << endl;
        cout << endl;
        cout << "Choose a selection:" << endl;
        cout << endl;
        cout << "A: Compute new expression" << endl;
        cout << "B: Review past answers" << endl;
        cout << "H: Help" << endl;
        cout << "Q: Quit" << endl;
        char selection = ' ';
        cin.get(selection);
        cin.ignore(256, '\n');
        switch (selection) {
        case 'a':
        case 'A':
            while (keep_compute) {
                P.last_ans = historian.ans();
                cout << "Enter your input: (enter 'BACK' to return to menu)" << endl;
                getline(cin, input);
                if (input.find("BACK") != string::npos) {
                    //user wants to quit out
                    keep_compute = false;
                }
                else {
                    //continue to calculate
                    result = P.parse(input);
                    historian.add(result);
                    cout << "Result: " << result << endl;
                }
            }
            keep_compute = true;
            break;
        case 'b':
        case 'B':
            cout<<"The last answer was: "<<historian.ans()<<endl;
            cout<<"You can use this value in future calculations by using the 'ans' keyword.\n"<<endl;
            cout<<"All previous answers:"<<endl;
            historian.printAll();
            break;
        case 'h':
        case 'H':
            cout << "This \"intelligent\" calculator will take your input and calculate a solution,\n"
                 << "avoiding floating point representation and providing an answer fit for a math\n"
                 << "textbook." << endl;
            cout << "\nHOW TO USE:" << endl;
            cout << "This calculator can take in all integers and is able to calculate using the\n"
                 << "normal four functions: +, -, *, and /." << endl;
            cout << "You can also calculate x to the power of y by entering x^y." << endl;
            cout << "The square root of a number x can be found by entering sqrt:x." << endl;
            cout << "The nth root of x can be found by entering nrt:x" << endl;
            cout << "The log base b of a number x can be found by entering log_b:x." << endl;
            cout << "The 'ans' keyword is used to enter the previous answer obtained." << endl;
            break;
        case 'q':
        case 'Q':
            cout << "Thank you for using the calculator! You have quit." << endl;
            gogo = false;
            break;
        default:
            cout << "Invalid choice, please choose again." << endl;
            cout << endl;
            break;
        }
    }

    return 0;
}
