// SubStatement.cpp:
#include "SubStatement.h"

SubStatement::SubStatement(char variableName,int value)
	: m_variableName( variableName ),m_value(value)
{}


void SubStatement::execute(ProgramState * state, std::ostream &outf)
{


	 // get value
	int value=0;
	state->getVariable(m_variableName,value);
	value = value - m_value; // do operation
	// assign value
	state->setVariable(m_variableName,value);
	state->nextPC();
}


