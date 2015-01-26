// GoSubStatement.cpp:
#include "GoSubStatement.h"

GoSubStatement::GoSubStatement(int linenum)
	: m_linenum( linenum )
{}


void GoSubStatement::execute(ProgramState * state, std::ostream &outf)
{

     state->nextPC(); // next pc
     state->savePC(); // save pc

	 if(!state->setPC(m_linenum))// set pc to linenum
	 {
		 outf << "Illegal jump instruction" << endl;
		 exit(1);
	 }

}


