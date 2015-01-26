// DivStatement.cpp:
#include "DivStatement.h"

DivStatement::DivStatement(char variableName,int value)
	: m_variableName( variableName ),m_value(value)
{}


void DivStatement::execute(ProgramState * state, std::ostream &outf)
{

	// get value
	int value=0;
	state->getVariable(m_variableName,value);

	if(m_value == 0)
	{
		outf << "Divide by zero exception" << endl;
		exit(1);
	}
	value = value / m_value; // do operation
	// assign value
	state->setVariable(m_variableName,value);
	state->nextPC();
}


