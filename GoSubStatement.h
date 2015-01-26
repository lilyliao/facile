
#ifndef GOSUB_STATEMENT_INCLUDED
#define GOSUB_STATEMENT_INCLUDED

#include "Statement.h"
#include <iostream>
#include <cstdlib>
using namespace std;

class GoSubStatement: public Statement
{
private:
	char m_linenum;
	
public:
	GoSubStatement(int linenum);
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif

