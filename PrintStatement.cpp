// PrintStatement.cpp:
#include "PrintStatement.h"

PrintStatement::PrintStatement(char variableName)
	: m_variableName( variableName )
{}


void PrintStatement::execute(ProgramState * state, std::ostream &outf)
{
   // get variable value
	int value=0;
	state->getVariable(m_variableName,value);
	outf << value << endl;
	state->nextPC();
}


