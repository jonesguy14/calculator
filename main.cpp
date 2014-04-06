#include "Parser.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    bool gogo = true;
    while (gogo) {
        cout << "Welcome to the calculator!" << endl;
        cout << "Enter your input" << endl;
        string input = "";
        getline(cin, input);
        Parser P;
        cout<<P.parse(input)<<endl;
        cout<<"Keep going? (0 or 1)"<<endl;
        int yn = 0;
        cin >> yn;
        if (yn==0) {gogo = false;}
    }

    return 0;
}
