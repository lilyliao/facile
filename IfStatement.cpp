// IfStatement.cpp:
#include "IfStatement.h"
using namespace std;

IfStatement::IfStatement(char variableName, string op, int value,int linenum)
	: m_variableName( variableName ),m_op(op), m_value( value ), m_linenum(linenum)
{}


// The IfStatement version of execute() should make two changes to the
// state of the program:
//
//    * set the value of the appropriate variable
//    * increment the program counter
void IfStatement::execute(ProgramState * state, ostream &outf)
{
	   int value=0;
       state->getVariable(m_variableName,value);
	   bool result = false;

	   // do test then set line num if true
	   if(m_op == "=" && value == m_value) result = true;
	   else if(m_op == "<>" && value != m_value) result = true;
	   else if(m_op == "<" && value < m_value) result = true;
	   else if(m_op == "<=" && value <= m_value) result = true;
	   else if(m_op == ">" && value > m_value) result = true;
	   else if(m_op == ">=" && value >= m_value) result = true;
	 

	   // condition true
	   if(result)
	   {
		    if(!state->setPC(m_linenum))// set pc to linenum
			{
			outf << "Illegal jump instruction" << endl;
			exit(1);
			}
		}


       // condition false
	   else
	   {
	   state->nextPC();
	   }
}


