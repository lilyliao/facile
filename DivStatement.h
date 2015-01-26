
#ifndef DIV_STATEMENT_INCLUDED
#define DIV_STATEMENT_INCLUDED

#include "Statement.h"
#include <iostream>
#include <cstdlib>
using namespace std;

using namespace std;

class DivStatement: public Statement
{
private:
	char m_variableName;
	int m_value;
	
public:
	DivStatement(char variableName, int value);
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif

