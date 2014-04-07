#include "Parser.h"
#include "History.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    bool gogo = true;
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
            P.last_ans = historian.ans();
            cout << "Enter your input:" << endl;
            getline(cin, input);
            result = P.parse(input);
            historian.add(result);
            cout << "Result: " << result << endl;
            break;
        case 'b':
        case 'B':
            cout<<"The last answer was: "<<historian.ans()<<endl;
            break;
        case 'h':
        case 'H':
            cout << "This \"intelligent\" calculator will take your input and calculate a solution,\n"
                 << "avoiding floating point representation and providing an answer fit for a math\n"
                 << "textbook." << endl;
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
