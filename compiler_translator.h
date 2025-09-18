#ifndef __TRANSLATOR_H
#define __TRANSLATOR_H

#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <stack>

using namespace std;

/* __filename stores the name of the file globally for terminal output purposes */
extern string __filename;

/* All classes that have been defined */
class symbol;
class SymbolTable;
class quad;
class List;
class ArrayCustom;
class funct;
class ArgList;


/* Functions to convert integers, doubles to string */
string conv2string(int);
string conv2string(unsigned int);
string conv2string(double);
int conv2int(string);
bool checkconst(string);

/* To make the string of a predefined length */
string getfixedstring(string);


//%%%%%%%%%%%%%%%%%%%%%%%%    Quads    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

/* All opcodes declared here */
enum __opcode 
{
	PLUS, MINUS, MUL, DIV, MOD, SLL, SRA, SRL,
	LESS, LEQ, GRT, GEQ,
	AND, OR, LogEQ, NotEQ,
	BinAND, BinOR, BinXOR,
	UMINUS, UPLUS, NOT, EQ,
	IFGOTO, IFFalseGOTO,
	IFLessGOTO, IFGrtGOTO, IFLessEqGOTO, IFGrtEqGOTO, IFLogEqGOTO, IFNotEqGOTO,
	CALL, GTO, PAR,
	RET,
	EQARR, ARREQ,
	EQADD, EQPVAL,
	PVALEQ,
	IntDbl, DblInt, CharInt, IntChar,
	LAB
};

/* class for quads */
class quad
{
public:

	/* Stores opcode, result variable and operand variables */
	__opcode op;
	string r, s, t;

	/* Overloaded constructors for different types of operators */
	quad(__opcode, string, string, string);
	quad(__opcode, string, string);
	quad(__opcode, string);

	/* Function to print the quad in suitable format */
	void print();
};


/* Function to emit a quad to the quad array */
void emit(string, string, __opcode, string);
void emit(string, __opcode, string);
void emit(string, __opcode);

/* Function to print quads to file */
void printQuad();






//%%%%%%%%%%%%%%%%%%%%%    Lists    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

/* Class to implement lists */
class List
{
public:

	/* The list as a vector internally. Vector makes handling of list easy */
	vector<int> li;

	List();

	/* To initiate list for the only address 'addr' */
	List(int addr);

	/* To print list in suitable format. For debugging */
	void print();
};

/* Class for nextlist */
class nextlist
{
public:
	List l;
};

/* Functions to make and merge lists */
List makelist(int);
List mergelist(List &, List &);

/* Returns the current address. Required for backpatching */
int currAddr();

/* Function for backpatching a list with an address */
void backpatch(List &, int);

/* Class to implement argument list for passing to functions */
class ArgList
{
public:
	vector<symbol*> li;
	void add(symbol*);

	/* Call takes care of parameter types and call function after performing suitable type conversions */
	void call(symbol* &);
};






//%%%%%%%%%%%%%%%%%    Types    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

/* To store constant values */
union val
{
	int ival;
	unsigned int uival;
	char cval;
	double dval;
};

/* All types defined here */
enum __type
{
	TVOID, TCHAR, TINT, TDOUBLE, TPTR, TARR, TFUNC, TBLOCK, TNULL, TBOOL, TSTR
};

/* Class for type */
struct type
{
public:

	/* Contains type name. If it is a pointer or an array, then also stores number of repetions n and subtype. */
	/* If of type pointer then n = 0 */
	__type tname;
	int n;
	type* sub;
	
	/* Suitable constructors */
	type();
	type(__type);
	type(__type, int, type);

	/* Overloaded operator to check equality of two types */
	bool operator == (const type &) const;

	/* To print type in suitable format */
	void print();

	/* Returns total size of type */
	int getsize();

	/* Returns formatted string with the name of the type */
	string getname();

	/* If array or pointer, returns the base type. Otherwise returns tname */
	__type getbasetype();
};





//%%%%%%%%%%%%%%%%%%%%%    Arrays    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

/* To store details of the arrays for array indexing */
class ArrayCustom
{
public:

	/* Stores the array base and the variable containing array offset */
	string base;
	symbol* offset;
	type t;

	/* Initiates array name, offset and array type */
	ArrayCustom(string, symbol*, type);

	/* Stores array dimensions */
	vector<int> dims;

	/* Size of base type */
	int bsize;

	/* Number of dimensions */
	int dimsize;

	/* To check whether array indices have been already resolved or not */
	bool resolved;

	/* Adds an array index for array accessing */
	void addindex(symbol*);

	/* Resolves all indices and computes true address */
	void resolve();
};






//%%%%%%%%%%%%%%%%%%     Functions     %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

/* To store details of functions, its parameters and return type */
class funct
{
public:
	/* Parameter type list */
	vector<type> typelist;

	/* Return type */
	type rettype;

	/* Prints details in suitable format */
	void print();
};






//%%%%%%%%%%%%%%%%%%     Symbol Table and symbols   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

/* Symbol class */

void addstringconst(string);
string getlabel(string);

class symbol
{
public:
	/* Stores symbol name, type, whether its is constant value, its value if constant, offset, subtable, lists, array data,
	and whether it is temporary variable */
	string name;
	type t;
	bool constant;
	val v;
	int size;
	int offset;
	SymbolTable * sub;
	List fl, tl;
	ArrayCustom* arr;
	bool temporary;
	string* strconst;

	/* Constructors for various types of initiation */
	symbol();
	symbol(string);
	symbol(string, type);
	symbol(string, SymbolTable* );
	symbol(__type);
	symbol(type);

	/* To formatted name of the variable. Helpful for arrays */
	string getname();
	string getoffset();

	/* Functions to initiate various fields */
	void createarray();
	void createfunc();

	/* Prints symbol table fields in proper format */
	void print();
};

/* Symbol table can store many symbols at once */
class SymbolTable
{
public:

	/* Stores name of the table, its unique number, and list of symbols */
	string name;
	int tableNum;
	int offset, paramoffset;
	vector<symbol*> symbols;
	funct* func;

	/* Constructor with name passed as parameter */
	SymbolTable(string);

	/* Functions to lookup a variable and/or create one. Also returns errors in case of multiple declarations */
	symbol* lookup(string);
	symbol* lookup(string, type);
	symbol* lookup(symbol*);

	/* Special function to lookup parameters */
	symbol* paramlookup(symbol*);

	/* Function to get offset */
	int getoffset(string);

	/* Generates temporary */
	symbol* gentemp(__type);
	symbol* gentemp(type);

	/* Prints symbol table in suitable format */
	void print();
};

/* Global gentemp. Detect the current scope and calls the respective gentemp */
symbol* gentemp(__type);
symbol* gentemp(type);

/* Keeps track of current scope */
extern stack<SymbolTable*> scopes;

/* The global symbol table */
extern SymbolTable GlobalTab;

/* Prints all symbols in the global symbol table. Recursively calls subtables. */
void printSym();








//%%%%%%%%%%%%%%%%%%%%    Type Checking    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

/* Checks type and does necessary conversions */
void typecheck(symbol* &, symbol* &);
void typeconv(symbol* &, symbol*);
void typeconv(symbol* &, type);

/* Special function for passing parameters */
void paramtypeconv(symbol* &, type);

/* Type conversion functions */
void convDblInt(symbol* &);
void convIntBool(symbol* &);

void convBoolInt(symbol* &);
void convIntDbl(symbol* &);

void convIntChar(symbol* &);
void convCharInt(symbol* &);

#endif
