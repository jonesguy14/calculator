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
    cout << "                            *** WELCOME TO OUR ***" << endl;
    cout << "      _____          _      _____ _    _ _            _______ ____  _____  \n";
    cout << "     / ____|   /\\   | |    / ____| |  | | |        /\\|__   __/ __ \\|  __ \\ \n";
    cout << "    | |       /  \\  | |   | |    | |  | | |       /  \\  | | | |  | | |__) |\n";
    cout << "    | |      / /\\ \\ | |   | |    | |  | | |      / /\\ \\ | | | |  | |  _  / \n";
    cout << "    | |____ / ____ \\| |___| |____| |__| | |____ / ____ \\| | | |__| | | \\ \\ \n";
    cout << "     \\_____/_/    \\_|______\\_____|\\____/|______/_/    \\_|_|  \\____/|_|  \\_\\ \n";
    cout << endl;
    cout << "                        *** PLEASE MAKE A SELECTION: ***" << endl;
    while (gogo) {
        cout << endl;
        cout << "CALCULATOR MENU" << endl;
        cout << "-----------------------------" << endl;
        cout << " A: Compute new expression" << endl;
        cout << "-----------------------------" << endl;
        cout << " B: Review past answers" << endl;
        cout << "-----------------------------" << endl;
        cout << " H: Help" << endl;
        cout << "-----------------------------" << endl;
        cout << " Q: Quit" << endl;
        cout << "-----------------------------" << endl;
        cout << "Choice: ";
        char selection = ' ';
        cin.get(selection);
        cin.ignore(256, '\n');
        switch (selection) {
        case 'a':
        case 'A':
            while (keep_compute) {
                P.last_ans = historian.ans();
                cout << "\nEnter your input: (enter 'BACK' to return to menu)" << endl;
                cout << "INPUT: ";
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
            cout<<"\nThe last answer was: "<<historian.ans()<<endl;
            cout<<"You can use this value in future calculations by using the 'ans' keyword.\n"<<endl;
            cout<<"All previous answers:"<<endl;
            historian.printAll();
            break;
        case 'h':
        case 'H':
            cout << "\nThis \"intelligent\" calculator will take your input and calculate a solution,\n"
                 << "avoiding floating point representation and providing an answer fit for a math\n"
                 << "textbook.\n" << endl;
            cout << "          ***HOW TO USE:***" << endl;
            cout << "---------------------------------------------------------" << endl;
            cout << "OPERATION DESIRED                      |   WHAT TO INPUT  " << endl;
            cout << "---------------------------------------------------------" << endl;
            cout << " Add x to y                            |      x + y       " << endl;
            cout << " Subtract y from x                     |      x - y       " << endl;
            cout << " Multiply x and y                      |      x * y       " << endl;
            cout << " Divide x by y                         |      x / y       " << endl;
            cout << " Calculate x to the power of y         |      x ^ y       " << endl;
            cout << " Take the square root of x             |      sqrt:x      " << endl;
            cout << " Take the nth root of x                |      nrt:x       " << endl;
            cout << " Take the log base b of x              |      log_b:x     " << endl;
            cout << " Use the previous answer               |      ans         " << endl;
            cout << "---------------------------------------------------------" << endl;
            break;
        case 'q':
        case 'Q':
            cout << "\nThank you for using the calculator! You have quit." << endl;
            gogo = false;
            cout <<"   _____  ____   ____  _____  ______     ________\n";
            cout <<"  / ____|/ __ \\ / __ \\|  __ \\|  _ \\ \\   / /  ____|\n";
            cout <<" | |  __| |  | | |  | | |  | | |_) \\ \\_/ /| |__   \n";
            cout <<" | | |_ | |  | | |  | | |  | |  _ < \\   / |  __|  \n";
            cout <<" | |__| | |__| | |__| | |__| | |_) | | |  | |____ \n";
            cout <<"  \\_____|\\____/ \\____/|_____/|____/  |_|  |______|\n";
            break;
        default:
            cout << "\nINVALID CHOICE! Please choose again." << endl;
            cout << endl;
            break;
        }
    }

    return 0;
}
