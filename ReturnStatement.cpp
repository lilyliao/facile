
#include "ReturnStatement.h"

ReturnStatement::ReturnStatement()
{
}
	

void ReturnStatement::execute(ProgramState * state, std::ostream &outf)
{

     // get return line number from stack
	 if(!state->restorePC())
	 {
		 cout << "RETURN statement without a corresponding GOSUB," << endl;
		 exit(1);
	 }

	  
}


