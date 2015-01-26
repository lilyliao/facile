// AddStatement.cpp:
#include "AddStatement.h"

AddStatement::AddStatement(char variableName,int value)
	: m_variableName( variableName ),m_value(value)
{}


void AddStatement::execute(ProgramState * state, std::ostream &outf)
{

	// get value
	int value=0;
	state->getVariable(m_variableName,value);
	value = value + m_value; // do operation
	// assign value
	state->setVariable(m_variableName,value);
	state->nextPC();
}


