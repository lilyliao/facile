// GotoStatement.cpp:
#include "GotoStatement.h"

GotoStatement::GotoStatement(int linenum)
	: m_linenum( linenum )
{}


void GotoStatement::execute(ProgramState * state, std::ostream &outf)
{

	if(!state->setPC(m_linenum))
	{
		outf << "Illegal jump instruction" << endl;
	}
}


