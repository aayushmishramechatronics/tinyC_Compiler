#ifndef __TRANSLATOR_CPP
#define __TRANSLATOR_CPP

#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <map>
#include <iostream>
#include "compiler_translator.h"
#include "y.tab.h"

using namespace std;

extern void yyerror(const char *);
extern void yyerror(string s);

ofstream symout;
ofstream quadout;

/* To store filename globally for terminal outputs */
string __filename;

/* Functions to convert integers, doubles to string */
string conv2string(int v)
{
	stringstream sbuff;
	sbuff<<v;
	return sbuff.str();
}

string conv2string(unsigned int v)
{
	stringstream sbuff;
	sbuff<<v;
	return sbuff.str();
}

string conv2string(double v)
{
	stringstream sbuff;
	sbuff<<v;
	return sbuff.str();
}

int conv2int(string s)
{
	return atoi(s.c_str());
}

bool checkconst(string a)
{
	if(a[0] == '$') return 1;
	return conv2string(atoi(a.c_str())) == a;
}
/* To make the string of a predefined length */
string getfixedstring(string s)
{
	while(s.length()<20) s.append(" ");
	s.append(" ");
	return s;
}



//%%%%%%%%%%%%%%%%%%%%%%%%    Quads    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

/* class constructors and member function definitions for quads */
quad::quad(__opcode OP, string R, string S, string T)
: op(OP), r(R), s(S), t(T)
{}

quad::quad(__opcode OP, string R, string T)
: op(OP), r(R), s(""), t(T)
{}

quad::quad(__opcode OP, string T)
: op(OP), r(""), s(""), t(T)
{}

/* Prints the quad to proper three address format. The format varies for all opcodes so the switch function has been used */
void quad::print()
{
	switch(op)
	{
		case PLUS:
			quadout<<t<<" = "<<r<<" + "<<s<<endl;
			break;
		case MINUS:
			quadout<<t<<" = "<<r<<" - "<<s<<endl;
			break;
		case MUL:
			quadout<<t<<" = "<<r<<" * "<<s<<endl;
			break;
		case DIV:
			quadout<<t<<" = "<<r<<" / "<<s<<endl;
			break;
		case MOD:
			quadout<<t<<" = "<<r<<" % "<<s<<endl;
			break;
		case SLL:
			quadout<<t<<" = "<<r<<" << "<<s<<endl;
			break;
		case SRL:
			quadout<<t<<" = "<<r<<" >> "<<s<<endl;
			break;
		case SRA:
			quadout<<t<<" = "<<r<<" >> "<<s<<endl;
			break;
		case LESS:
			quadout<<t<<" = "<<r<<" < "<<s<<endl;
			break;
		case LEQ:
			quadout<<t<<" = "<<r<<" <= "<<s<<endl;
			break;
		case GRT:
			quadout<<t<<" = "<<r<<" > "<<s<<endl;
			break;
		case GEQ:
			quadout<<t<<" = "<<r<<" >= "<<s<<endl;
			break;
		case AND:
			quadout<<t<<" = "<<r<<" and "<<s<<endl;
			break;
		case OR:
			quadout<<t<<" = "<<r<<" or "<<s<<endl;
			break;
		case LogEQ:
			quadout<<t<<" = "<<r<<" == "<<s<<endl;
			break;
		case NotEQ:
			quadout<<t<<" = "<<r<<" != "<<s<<endl;
			break;
		case BinXOR:
			quadout<<t<<" = "<<r<<" ^ "<<s<<endl;
			break;
		case BinAND:
			quadout<<t<<" = "<<r<<" & "<<s<<endl;
			break;
		case BinOR:
			quadout<<t<<" = "<<r<<" | "<<s<<endl;
			break;
		case UMINUS:
			quadout<<t<<" = - "<<r<<endl;
			break;
		case UPLUS:
			quadout<<t<<" = + "<<r<<endl;
			break;
		case NOT:
			quadout<<t<<" = ! "<<r<<endl;
			break;
		case IntDbl:
			quadout<<t<<" = IntDbl "<<r<<endl;
			break;
		case DblInt:
			quadout<<t<<" = DblInt "<<r<<endl;
			break;
		case CharInt:
			quadout<<t<<" = CharInt "<<r<<endl;
			break;
		case IntChar:
			quadout<<t<<" = IntChar "<<r<<endl;
			break;
		case EQ:
			quadout<<t<<" = "<<r<<endl;
			break;
		case IFGOTO:
			quadout<<"IF "<<r<<" GOTO "<<t<<endl;
			break;
		case IFFalseGOTO:
			quadout<<"IFFALSE "<<r<<" GOTO "<<t<<endl;
			break;
		case IFLessGOTO:
			quadout<<"IF "<<r<<" < "<<s<<" GOTO "<<t<<endl;
			break;
		case IFGrtGOTO:
			quadout<<"IF "<<r<<" > "<<s<<" GOTO "<<t<<endl;
			break;
		case IFLessEqGOTO:
			quadout<<"IF "<<r<<" <= "<<s<<" GOTO "<<t<<endl;
			break;
		case IFGrtEqGOTO:
			quadout<<"IF "<<r<<" >= "<<s<<" GOTO "<<t<<endl;
			break;
		case IFLogEqGOTO:
			quadout<<"IF "<<r<<" == "<<s<<" GOTO "<<t<<endl;
			break;
		case IFNotEqGOTO:
			quadout<<"IF "<<r<<" != "<<s<<" GOTO "<<t<<endl;
			break;
		case CALL:
			quadout<<t<<" = CALL "<<r<<", "<<s<<endl;
			break;
		case GTO:
			quadout<<"GOTO "<<t<<endl;
			break;
		case PAR:
			quadout<<"PARAM "<<t<<endl;
			break;
		case RET:
			quadout<<"RETURN "<<t<<endl;
			break;
		case EQARR:
			quadout<<t<<" = "<<r<<"["<<s<<"]"<<endl;
			break;
		case ARREQ:
			quadout<<t<<"["<<r<<"]"<<" = "<<s<<endl;
			break;
		case EQADD:
			quadout<<t<<" = & "<<r<<endl;
			break;
		case EQPVAL:
			quadout<<t<<" = * "<<r<<endl;
			break;
		case PVALEQ:
			quadout<<"*"<<t<<" = "<<r<<endl;
			break;
		case LAB:
			quadout<<"LABEL "<<t<<": "<<endl;
			break;
		default: quadout<<"Not defined: "<<op<<endl;
	}
}


/* Array to store all emitted quads */
vector<quad> __quadArr;

/* Overloaded emit functions */
void emit(string res, string r, __opcode op, string s)
{
	__quadArr.push_back(quad(op, r, s, res));
}

void emit(string res, __opcode op, string r)
{
	__quadArr.push_back(quad(op, r, res));
}

void emit(string res, __opcode op)
{
	__quadArr.push_back(quad(op, res));
}

/* Returns current instruction address */
int currAddr()
{
	return __quadArr.size()-1;
}

/* Prints quads in suitable format */
void printQuad()
{
	for(int i=0; i<__quadArr.size(); i++)
	{
		quadout << i << ": ";
		__quadArr[i].print();
	}
}







//%%%%%%%%%%%%%%%%%%%%%    Lists    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

/* List constructors and member functions */
List::List() {}

List::List(int ind)
{
	li.push_back(ind);
}

void List::print()
{
	for(int i=0; i<li.size(); i++) cout<<li[i]<<" ";
	cout<<endl;
}


/* Global functions for list making, merging and backpatching*/
List makelist(int ind)
{
	return List(ind);
}

/* Returns merged lists */
List mergelist(List& a, List& b)
{
	List ret = List();
	for(int i=0; i<a.li.size(); i++) ret.li.push_back(a.li[i]);
	for(int i=0; i<b.li.size(); i++) ret.li.push_back(b.li[i]);
	return ret;	
}

void backpatch(List& a, int ind)
{
	int updateInd;
	for(int i=0; i<a.li.size(); i++)
	{
		updateInd = a.li[i];
		__quadArr[updateInd].t = conv2string(ind);
	}
}

/* Adds argument to the list. Accumulates arguments till the function call */
void ArgList::add(symbol* a)
{
	li.push_back(a);
}

/* Calls the function after proper processing of the arguments */
void ArgList::call(symbol* &a)
{
	/* Checks parameter types from the symbol table of the function and does necessary type conversions */
	SymbolTable* temp = a->sub;
	if(li.size() != (temp->func)->typelist.size())
		yyerror("Expected "+conv2string((int)(temp->func)->typelist.size())+" parameters. Found "+conv2string((int)li.size()));

	/* All type conversions performed in a single loop to avoid overlapping with the parameter passing phase */
	for(int i=0; i<li.size(); i++)
	{
		paramtypeconv(li[i], (temp->func)->typelist[i]);
	}

	/* All paramters passed together after type conversion is performed */
	for(int i=li.size()-1; i>=0; i--)
	{
		emit(li[i]->getname(),PAR);
	}

	/* Function call performed */
	symbol* t1 = gentemp((temp->func)->rettype);
	emit(t1->getname(), a->getname(), CALL, conv2string((int)li.size()));
	a = t1;
}







//%%%%%%%%%%%%%%%%%    Types    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

/* Overloaded "==" operator. If type is a basic type, then return by checking opcodes. Otherwise, check equality of subtypes and n */
bool type::operator == (const type &x) const
{
	if(tname != x.tname) return 0;
	if(tname != TARR && tname != TPTR) return 1;
	if(tname == TARR && n != x.n) return 0;
	if(*sub == *(x.sub)) return 1;
	return 0;
}

/* Constructors and member functions of type class */
type::type():tname(TVOID), n(0), sub(0) {}
type::type(__type t):tname(t), n(0), sub(0) {}
type::type(__type t, int N, type subtype): tname(t), n(N), sub(0)
{
	sub = new type(subtype);
}

/* Returns full formatted name of the type */
string type::getname()
{
	string ret;
	if(tname == TARR) ret = "arr("+conv2string(n)+", "+sub->getname()+")";
	else if(tname == TPTR) ret = "ptr("+sub->getname()+")";
	else
	{
		switch(tname)
		{
			case TVOID: ret = "void";
				break;
			case TCHAR: ret = "char";
				break;
			case TINT: ret = "int";
				break;
			case TDOUBLE: ret = "double";
				break;
			case TFUNC: ret = "func";
				break;
			case TBLOCK: ret = "block";
				break;
			case TSTR: ret = "string";
				break;
			default: ret = "type not defined";
		}
	}

	return ret;
}

/* Returns complete size of the type */
int type::getsize()
{
	switch(tname)
	{
		case TCHAR: return 1;

		case TINT: return 4;

		case TDOUBLE: return 8;

		case TPTR: return 4;

		case TARR: return n*(sub->getsize());

		case TFUNC: return 0;

		case TSTR: return 4;
	}
	return 4;
}

/* Returns the base type for arrays and pointers */
__type type::getbasetype()
{
	type ty = *this;
	while(ty.sub != 0) ty = *(ty.sub);
	return ty.tname;
}







//%%%%%%%%%%%%%%%%%%%%%    Arrays    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

/* Function to initiate the array access */
/* Stores the array dimensions for complete resolution of the true address */
ArrayCustom::ArrayCustom(string bs, symbol* sym, type ty): base(bs), offset(sym), t(ty), resolved(0)
{
	// while(ty.sub != 0)
	// {
	// 	dims.push_back(ty.n);
	// 	ty = *(ty.sub);
	// }

	// bsize = ty.getsize();
	// dimsize = dims.size();

	// emit(offset->name, EQ, "0");
}

// void array::addindex(symbol* a)
// {
// 	if(dims.size() == 0) yyerror("Too many array dimensions");
// 	emit(offset->name,offset->name,MUL,conv2string(dims.back()));
// 	emit(offset->name,offset->name, PLUS, a->name);
// 	dims.pop_back();
// }

// void array::resolve()
// {
// 	if(!resolved)
// 	{
// 		resolved = 1;
// 		emit(offset->getname(), offset->getname(), MUL, conv2string(bsize));
// 	}
// }









//%%%%%%%%%%%%%%%%%%     Functions     %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

/* Prints function parameter type list and return types in suitable format */
void funct::print()
{
	string s = "ParamType: ";
	for(int i=0; i<typelist.size(); i++) s = s+typelist[i].getname()+", ";
	s = s+" RetType: "+rettype.getname();
	symout<<s<<endl;
}








//%%%%%%%%%%%%%%%%%%     Symbol Table and symbols   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


map<string, string> __stringtab;

int stringcnt = 0;

void addstringconst(string s)
{
	string lab = ".LC"+conv2string(stringcnt++);
	if(__stringtab.find(s) == __stringtab.end()) __stringtab[s] = lab;
}

string getlabel(string s)
{
	return __stringtab[s];
}

/* Constructors and member functions for symbol classs */
symbol::symbol(): name(""), t(), size(0), offset(0), sub(0), constant(0), arr(0), temporary(0), strconst(0)
{}

symbol::symbol(string id): name(id), t(), size(0), offset(0), sub(0), constant(0), arr(0), temporary(0), strconst(0)
{}

symbol::symbol(string id, type ty): name(id), t(ty), size(0), offset(0), sub(0), constant(0), arr(0), temporary(0), strconst(0)
{}

symbol::symbol(__type ty): name(""), t(ty), size(0), offset(0), sub(0), constant(0), arr(0), temporary(0), strconst(0)
{}

symbol::symbol(type ty): name(""), t(ty), size(0), offset(0), sub(0), constant(0), arr(0), temporary(0), strconst(0)
{}

symbol::symbol(string id, SymbolTable* subtab): name(id), t(TFUNC), size(0), offset(0), sub(subtab), constant(0), arr(0), temporary(0), strconst(0)
{} 

/* Returns full formatted name of the symbol. Useful for arrays */
string symbol::getname()
{
	// string ret = "";
	// if(t.tname == TARR)
	// {
	// 	if((arr->dims).size())
	// 	{
	// 		arr->resolve();
	// 		symbol* t1 = gentemp(type(TPTR, 0, type(TINT)));
	// 		emit(t1->getname(), name, PLUS, (arr->offset)->getname());
	// 		*this = *t1;
	// 		return name;
	// 	}
	// 	else
	// 	{
	// 		arr->resolve();
	// 		ret = name;
	// 	}
	// }
	// else ret = name;

	// return ret;
	return name;
}

string symbol::getoffset()
{
	// string ret = "";
	// if(t.tname == TARR)
	// {
	// 	if((arr->dims).size())
	// 	{
	// 		arr->resolve();
	// 		symbol* t1 = gentemp(type(TPTR, 0, type(TINT)));
	// 		emit(t1->getname(), name, PLUS, (arr->offset)->getname());
	// 		*this = *t1;
	// 		return arr->offset->getname();
	// 	}
	// 	else
	// 	{
	// 		arr->resolve();
	// 		ret = arr->offset->getname();
	// 	}
	// }
	// else yyerror(name+": not an array");
	// return ret;

	if(arr->offset == 0) yyerror(name+": Not an array");
	return arr->offset->getname();
}

/* Prints the fields to the output file in suitable format */
void symbol::print()
{
	symout<<getfixedstring(name);
	symout<<getfixedstring(t.getname());

	if(constant)
	{
		switch(t.tname)
		{
			case TCHAR: symout<<getfixedstring(conv2string(v.cval));
				break;
			case TINT: symout<<getfixedstring(conv2string(v.ival));
				break;
			case TDOUBLE: symout<<getfixedstring(conv2string(v.dval));
				break;
			case TPTR: symout<<getfixedstring(conv2string(v.uival));
				break;
			default: symout<<getfixedstring("null");
		}
	}
	else
	{
		symout<<getfixedstring("null");
	}

	symout<<getfixedstring(conv2string(size));
	symout<<getfixedstring(conv2string(offset));

	if(t.tname == TFUNC || t.tname == TBLOCK)
	{
		symout<<getfixedstring(conv2string(sub->tableNum))<<endl;
	}
	else symout<<getfixedstring("null")<<endl;
}


/* Initiates the array class of the symbol when required */
// void symbol::createarray()
// {
// 	arr = new array(name, gentemp(TINT), t);
// }

/* Initiates the function class of the symbol when required. */
void symbol::createfunc()
{
	sub = new SymbolTable(name);
	sub->func = new funct();
}


/* Stores the number of symbol tables and temporary variables.*/
/* Used for generating unique temporary every time */
int __tableSize = 1;
int __tempSize = 1;

/* Constructors and member functions for the symbol table */
SymbolTable::SymbolTable(string s)
{
	name = s;
	tableNum = GlobalTab.symbols.size()+1;
	offset = 0, paramoffset = 8;
	func = 0;
}

/* Searches for the variable in the symbol table. */
/* Returns pointer to its symbol, if it exists. */
/* Otherwise prints error and exits. */
symbol* SymbolTable::lookup(string id)
{
	for(int i=0; i<symbols.size(); i++) if(symbols[i]->name == id) return symbols[i];
	for(int i=0; i<GlobalTab.symbols.size(); i++) if((GlobalTab.symbols[i])->name == id) return GlobalTab.symbols[i];
	yyerror("Variable '"+id+"' not declared");
}

/* Searches for the symbol in the symbol table. If it exists then throws error.
Otherwise adds it to the symbol table. Useful for creating new variables */
symbol* SymbolTable::lookup(symbol* a)
{
	for(int i=0; i<symbols.size(); i++) if(symbols[i]->name == a->name) yyerror("Multiple definitions for variable '"+a->name+"'");
	a->size = (a->t).getsize();
	offset -= a->size;
	a->offset = offset;
	symbols.push_back(a);
	return symbols.back();
}

/* Peforms lookup functions for function parameters */
symbol* SymbolTable::paramlookup(symbol* a)
{
	for(int i=0; i<symbols.size(); i++) if(symbols[i]->name == a->name) yyerror("Multiple definitions for variable '"+a->name+"'");
	a->size = (a->t).getsize();
	if((a->t).tname == TARR) a->size = 4;
	a->offset = paramoffset;
	paramoffset += a->size;
	symbols.push_back(a);
	return symbols.back();
}

/* Searches for the variable in the symbol table. */
/* Returns pointer to its symbol, if it exists. */
/* Otherwise prints error and exits. */
symbol* SymbolTable::lookup(string id, type ty)
{
	for(int i=0; i<symbols.size(); i++) if(symbols[i]->name == id) yyerror("Multiple definitions for variable '"+id+"'");
	symbols.push_back(new symbol(id, ty));
	symbols.back()->size = (symbols.back()->t).getsize();
	offset -= symbols.back()->size;
	symbols.back()->offset = offset;

	return symbols.back();
}

/* Returns the offset of the variable */
int SymbolTable::getoffset(string id)
{
	for(int i=0; i<symbols.size(); i++) if((symbols[i]->name) == id)
	{
		return symbols[i]->offset;
	}
	yyerror("Variable '"+id+"' not declared");
}

/* Generates temporary, adds it to the table and returns it */
symbol* SymbolTable::gentemp(__type ty)
{
	stringstream sbuff;
	sbuff<<"t"<<__tempSize;
	__tempSize++;
	symbol* temp = lookup(sbuff.str(), ty);
	temp->temporary = 1;
	return temp;
}

/* Generates temporary, adds it to the table and returns it */
symbol* SymbolTable::gentemp(type ty)
{
	stringstream sbuff;
	sbuff<<"t"<<__tempSize;
	__tempSize++;
	symbol* temp = lookup(sbuff.str(), ty);
	temp->temporary = 1;
	return temp;
}

/* Generates temporary, adds it to the current symbol table and returns it */
symbol* gentemp(__type ty)
{
	symbol* t1 = scopes.top()->gentemp(ty);
	t1->t = type(ty);
	return t1;
}

/* Generates temporary, adds it to the current symbol table and returns it */
symbol* gentemp(type ty)
{
	symbol* t1 = scopes.top()->gentemp(ty);
	t1->t = type(ty);
	return t1;
}

/* Prints the symbol table in suitable format */
void SymbolTable::print()
{
	symout<<"Table "<<tableNum<<": "<<name<<endl;
	if(func) func->print();
	symout<<getfixedstring("Name");
	symout<<getfixedstring("Type");
	symout<<getfixedstring("Val");
	symout<<getfixedstring("Size");
	symout<<getfixedstring("Offset");
	symout<<getfixedstring("Nested Table");
	symout<<endl;
	for(int i=0; i<symbols.size(); i++) symbols[i]->print();
	symout<<endl;
	for(int i=0; i<symbols.size(); i++) if((symbols[i]->t).tname == TFUNC || (symbols[i]->t).tname == TBLOCK)
		symbols[i]->sub->print();
}

/* Initiates the global symbol table with the name "Global" */
SymbolTable GlobalTab("Global");
stack<SymbolTable*> scopes;

/* Prints all the symbols recursively */
void printSym()
{
	GlobalTab.print();
}







//%%%%%%%%%%%%%%%%%%%%    Type Checking    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

/* Performs symmetric type checking i.e. either of these may be converted, in contrast to typeconv() function.
Performs type conversions so as to make both types similar. */
void typecheck(symbol* &a, symbol* &b)
{
	convCharInt(a);
	convCharInt(b);

	if((a->t).tname == TDOUBLE && ((b->t).tname == TINT || (b->t).tname == TPTR)) convIntDbl(b);
	else if((b->t).tname == TDOUBLE && ((a->t).tname == TINT || (a->t).tname == TPTR)) convIntDbl(a);

	else if(((a->t).tname == TINT || (a->t).tname == TPTR) && (b->t).tname == TCHAR) convCharInt(b);
	else if(((b->t).tname == TINT || (b->t).tname == TPTR) && (a->t).tname == TCHAR) convCharInt(a);
	else if(((a->t).tname == TINT || (a->t).tname == TPTR) && ((b->t).tname == TINT || (b->t).tname == TPTR));
	else if((b->t).tname == (a->t).tname);
	else
	{
		yyerror("Cannot convert between types");
	}
}

/* Performs type conversion of the first parameter to match that of the second one.
Assymetrical type conversion */
void typeconv(symbol* & from, symbol* to)
{
	__type fr = (from->t).tname;
	__type t = (to->t).getbasetype();
	
	if((to->t).tname == TPTR) t = TPTR;

	if(fr == TDOUBLE && t == TINT)
	{
		convDblInt(from);
		return;
	}
	if(fr == TINT && t == TDOUBLE)
	{
		convIntDbl(from);
		return;
	}
	if(fr == TDOUBLE && t == TDOUBLE)
	{
		return;
	}
	if(fr == TDOUBLE && t == TCHAR)
	{
		convDblInt(from);
		convIntChar(from);
		return;
	}
	if(fr == TCHAR && t == TDOUBLE)
	{
		convCharInt(from);
		convIntDbl(from);
		return;
	}
	if(fr == TINT && t == TPTR)
	{
		return;
	}
	if(fr == TINT && t == TCHAR)
	{
		convIntChar(from);
		return;
	}
	if(fr == TCHAR && t == TINT)
	{
		convCharInt(from);
		return;
	}
	
	if(fr == TPTR && t == TINT)
	{
		return;
	}

	if(fr == TINT && t == TINT)
	{
		return;
	}

	if(fr == TPTR && t == TPTR)
	{
		return;
	}

	if(fr == TCHAR && t == TCHAR)
	{
		return;
	}

	if(fr == TSTR && t == TSTR)
	{
		return;
	}

	yyerror("Cannot convert from "+type(fr).getname()+" to "+type(t).getname());
}

/* Overloaded function which call the original typeconv function */
void typeconv(symbol* & from, type ty)
{
	typeconv(from, new symbol("", ty));
}

void paramtypeconv(symbol* & from, type ty)
{
	if(ty.tname == TPTR)
	{
		if(!((from->t) == ty)) yyerror("Cannot convert from "+(from->t).getname()+" to "+ty.getname());
	}
	else typeconv(from, ty);
}


/* Functions to convert between types */

void convDblInt(symbol* &a)
{
	if((a->t).tname != TDOUBLE) return;

	symbol* t1 = gentemp(TINT);
	emit(t1->getname(), DblInt, a->getname());

	a = t1;
}

void convIntBool(symbol* &a)
{
	if((a->t).tname != TINT && (a->t).tname != TPTR) return;

	symbol* t1 = new symbol(TBOOL);
	emit("", a->getname(), IFFalseGOTO, "0");
	t1->fl = makelist(currAddr());
	emit("",GTO);
	t1->tl = makelist(currAddr());

	a = t1;
}

void convBoolInt(symbol* &a)
{
	if((a->t).tname != TBOOL) return;

	symbol* t1 = gentemp(TINT);
	emit(t1->getname(), EQ, "1");
	backpatch(a->tl, currAddr());
	emit("", GTO);
	List l = List(currAddr());
	emit(t1->getname(), EQ, "0");
	backpatch(a->fl, currAddr());
	backpatch(l, currAddr()+1);

	a = t1;
}

void convIntDbl(symbol* &a)
{
	if((a->t).tname != TINT && (a->t).tname != TPTR) return;

	symbol* t1 = gentemp(TDOUBLE);
	emit(t1->getname(), IntDbl, a->getname());

	a = t1;
}

void convCharInt(symbol* &a)
{
	if((a->t).tname != TCHAR) return;

	symbol* t1 = gentemp(TINT);
	emit(t1->getname(), CharInt, a->getname());

	a = t1;
}

void convIntChar(symbol* &a)
{
	if((a->t).tname != TINT) return;

	symbol* t1 = gentemp(TCHAR);
	emit(t1->getname(), IntChar, a->getname());

	a = t1;
}


#endif
