
#ifndef IF_STATEMENT_INCLUDED
#define IF_STATEMENT_INCLUDED

#include "Statement.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class IfStatement: public Statement
{
private:
	char m_variableName;
	string m_op;
	int m_value;
	int m_linenum;
	
public:
	IfStatement(char variableName, string op, int value, int linenum);
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif

