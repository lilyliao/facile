// ProgramState.h
//
// CS 32 / Summer 2014
// Project #2: What's Simple Is True
//
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
// I've provided you a start on this class, but you'll need to add methods
// to it as you go along.  In particular, you'll need methods to access and
// modify the state; these methods will be called primarily by the various
// execute() methods in the Statement subclasses, to allow the execution of
// a statement to change the state of a program.  For example, executing a
// GOTO statement will cause the program counter to be changed.

#ifndef PROGRAM_STATE_INCLUDED
#define PROGRAM_STATE_INCLUDED

#include "Stack.h"

class ProgramState
{
public:
	ProgramState(int numLines);

	// You'll need to add a variety of methods here.  Rather than trying to
	// think of what you'll need to add ahead of time, add them as you find
	// that you need them.
    bool setPC(int pc);
	int getPC();
	void nextPC();
	void savePC();
	bool restorePC();
	bool setVariable(char variableName, int value);
    bool getVariable(char variableName, int& value);
	void setDone();
	bool isExecuting();

	

private:
	int m_numLines;
	int m_pc;
	int m_variables[26]; // variables A to Z
	Stack<int> m_stk; // program stack
	bool m_executing;
};

#endif



