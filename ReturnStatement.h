
#ifndef RETURN_STATEMENT_INCLUDED
#define RETURN_STATEMENT_INCLUDED

#include "Statement.h"
#include <iostream>
#include <cstdlib>
using namespace std;

class ReturnStatement: public Statement
{
private:

	
public:
	ReturnStatement();
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif

