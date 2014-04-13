#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <string>
using namespace std;

class Exceptions {
	
private:
	//Values
	int errorID;
	
public:
	//Values
	string errorName;

	//Constructor
	Exceptions();
	Exceptions(string errorName);

	//Destructor
	~Exceptions() {
	};

	//Methods
	int determineError(string errorName);
	int what();



};

#endif /* EXCEPTIONS_H_ */
