// ProgramState.cpp

// The ProgramState class encapsulates the state of an executing Facile
// program.  The state of a Facile program consists of three parts:
//
//    * The program counter, which specifies the line number of the
//      statement that will execute next.
//    * An array of 26 integers, holding the current values of the 26
//      variables.
//    * A stack of integers, which is used to hold return lines for GOSUB
//      statements.
//


#include "ProgramState.h"

ProgramState::ProgramState(int numLines): m_numLines(numLines)
{
  m_pc = 1; // start at line 1
    m_executing=true;
  // ckear all variables
  for(int i=0;i<26;i++)
  {
	  m_variables[i] = 0;
  }
}


// assign pc
bool ProgramState::setPC(int pc)
   {
	if(pc < 1 || pc>= m_numLines) return false;
      m_pc = pc;
	return true;

   }

// return pc
int ProgramState::getPC()
{
    return m_pc;
}

// next linenum
void ProgramState::nextPC()
{
     m_pc++;
	 if(m_pc == m_numLines) // stop executing
		 m_executing = false;
}

// save pc in stack
void ProgramState::savePC()
{
  m_stk.push(m_pc);
}


// restore pc from stack
bool ProgramState::restorePC()
{
	if(m_stk.empty())
	{
		return false;
	}

	m_pc = m_stk.top();
	m_stk.pop();
	return true;

}

// stop excuting
void ProgramState::setDone()
	{
		m_executing = false;
	}

// return true if executing
bool ProgramState::isExecuting()
	{
		return m_executing;
	}

// assign value to a variable
bool ProgramState::setVariable(char variableName, int value)
{
	// get variable index
	int index = variableName - 'A';

	// check index bounds
	if(index < 0 || index >= 26)
	{
		return false;
	}

	m_variables[index] = value;
	return true;
}

// return value of variable
bool ProgramState::getVariable(char variableName, int &value)
{

		// get variable index
	int index = variableName - 'A';

	// check index bounds
	if(index < 0 || index >= 26)
	{
		return false;
	}

	value = m_variables[index];

	return true;
}

