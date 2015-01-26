// Facile.cpp
#include "Statement.h"
#include "LetStatement.h"
#include "PrintStatement.h"
#include "AddStatement.h"
#include "SubStatement.h"
#include "MultStatement.h"
#include "DivStatement.h"
#include "GotoStatement.h"
#include "IfStatement.h"
#include "GoSubStatement.h"
#include "ReturnStatement.h"
#include "EndStatement.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream> 
#include <fstream>
#include <cstdlib>


using namespace std;

// parseProgram() takes a filename as a parameter, opens and reads the
// contents of the file, and returns an vector of pointers to Statement.
void parseProgram(istream& inf, vector<Statement *> & program);

// parseLine() takes a line from the input file and returns a Statement
// pointer of the appropriate type.  This will be a handy method to call
// within your parseProgram() method.
Statement * parseLine(string line);

// interpretProgram() reads a program from the given input stream
// and interprets it, writing any output to the given output stream.
// Note:  you are required to implement this function!
void interpretProgram(istream& inf, ostream& outf);


int main()
{
        cout << "Enter Facile program file name: ";
        string filename;
        getline(cin, filename);
        ifstream infile(filename.c_str());
        if (!infile)
        {
                cout << "Cannot open " << filename << "!" << endl;
                return 1;
        }
        interpretProgram(infile, cout);

		cin.get();
		return 0;
}



void parseProgram(istream &inf, vector<Statement *> & program)
{
	
	program.push_back(NULL);
	
	string line;
	while( ! inf.eof())
	{
		getline(inf, line);
		program.push_back( parseLine( line ) );
	}
}


Statement * parseLine(string line)
{
	Statement * statement=NULL;	
	stringstream ss;
	string type;
	char var;
	int val;
	string op;
	int linenum;

	ss << line;
	ss >> type;
	
	if ( type == "LET" )
	{
		ss >> var;
		ss >> val;
		// Note:  Because the project spec states that we can assume the file
		//	  contains a syntactically legal Facile program, we know that
		//	  any line that begins with "LET" will be followed by a space
		//	  and then a variable (single character) and then an integer value.
		statement = new LetStatement(var, val);
	}

	// Incomplete;  TODO:  Finish this function!

    else if ( type == "PRINT" )
	{

        ss >> var;
		statement = new PrintStatement(var);
	}

		
	else if ( type == "ADD" )
	{
		ss >> var;
		ss >> val;
		statement = new AddStatement(var, val);
	}

	else if ( type == "SUB" )
	{
		ss >> var;
		ss >> val;
		statement = new SubStatement(var, val);
	}

	else if ( type == "MULT" )
	{
		ss >> var;
		ss >> val;
		statement = new MultStatement(var, val);
	}

	else if ( type == "DIV" )
	{
		ss >> var;
		ss >> val;
		statement = new DivStatement(var, val);
	}

	else if ( type == "GOTO" )
	{
		ss >> linenum;
		statement = new GotoStatement(linenum);
	}

	else if ( type == "IF" )
	{
		ss >> var;
		ss >> op;
		ss >> val;
		ss >> type; // THEN
		ss >> linenum;
		statement = new IfStatement(var,op,val,linenum);
	}

	else if ( type == "GOSUB" )
	{
		ss >> linenum;
		statement = new GoSubStatement(linenum);
	}
		

	else if ( type == "RETURN" )
	{
		statement = new ReturnStatement();
	}

	else if ( type == "END" || type == "." )
	{
		statement = new EndStatement();
	}

	else 	statement = new EndStatement();

	return statement;
}


void interpretProgram(istream& inf, ostream& outf)
{
	vector<Statement *> program;
	parseProgram( inf, program );
	
	// Incomplete;  TODO:  Finish this function!
    unsigned int i;
	
	ProgramState state(program.size());

	while(state.isExecuting())
	{
		program[state.getPC()]->execute(&state, outf);
	}

	// free all memory
	for(i=1;i<program.size();i++)
	{
		delete program[i];
	}
}

