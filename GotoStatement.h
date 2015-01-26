
#ifndef GOTO_STATEMENT_INCLUDED
#define GOTO_STATEMENT_INCLUDED

#include "Statement.h"
#include <iostream>
using namespace std;

class GotoStatement: public Statement
{
private:
	int m_linenum;
	
public:
	GotoStatement(int linenum);
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif

