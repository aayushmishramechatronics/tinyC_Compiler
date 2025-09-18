#include "compiler_translator.h"
#include <iostream>
#include <map>
#include "y.tab.h"

using namespace std;

extern vector<quad> __quadArr;
extern int yylex();
extern int yydebug;
extern ofstream symout;
extern ofstream quadout;
extern map<string, string> __stringtab;
ofstream asmout;

map<int, string> labels;

void makeConstants()
{
	string buff = "";
	buff += "\t.section\t.rodata\n";
	for(map<string,string>::iterator it = __stringtab.begin(); it != __stringtab.end(); it++)
		buff += "\t"+(*it).second+":\n\t.string\t"+(*it).first+"\n";
	asmout<<buff;
}

void makelabels()
{
	int labelnum = 0;
	for(int i=0; i<__quadArr.size(); i++)
	{
		if(	__quadArr[i].op == GTO ||
			__quadArr[i].op == IFGOTO ||
			__quadArr[i].op == IFFalseGOTO ||
			__quadArr[i].op == IFLessGOTO ||
			__quadArr[i].op == IFGrtGOTO ||
			__quadArr[i].op == IFLessEqGOTO ||
			__quadArr[i].op == IFGrtEqGOTO ||
			__quadArr[i].op == IFLogEqGOTO ||
			__quadArr[i].op == IFNotEqGOTO)
			labels[conv2int(__quadArr[i].t)] = ".L"+conv2string(labelnum++);
	}
}

string makePrologue(SymbolTable* curr)
{
	string buff = "";
	buff += "\t.text\n";
	buff += "\t.globl "+curr->name+"\n";
	buff += "\t.type "+curr->name+", @function\n";
	buff += curr->name + ":\n";
	buff += "\tpushl %ebp\n";
	buff += "\tmovl %esp, %ebp\n";
	buff += "\taddl $"+conv2string(curr->offset)+", %esp\n";
	return buff;
}

string makeEpilogue(SymbolTable* curr)
{
	string buff = "";
	buff += ".ret_"+curr->name+":\n";
	buff += "\tleave\n";
	buff += "\tret\n";
	return buff;
}

void makeAsm()
{
	vector<quad> & quads = __quadArr;
	string buff;
	SymbolTable* curr = &GlobalTab;
	bool scoped = false;
	int parsize = 0;
	asmout << "\t.file \""<<__filename<<".c\"\n";

	makelabels();
	makeConstants();

	for(int i=0; i<quads.size(); i++)
	{
		buff = "";
		if(labels.find(i) != labels.end()) buff += labels[i]+":\n";
		switch(quads[i].op)
		{
			case PLUS:
				buff += "\tmovl "+conv2string(curr->getoffset(quads[i].r))+"(%ebp), %eax\n";
				if(checkconst(quads[i].s)) buff += "\taddl $"+quads[i].s+", %eax\n";
				else buff += "\taddl "+conv2string(curr->getoffset(quads[i].s))+"(%ebp), %eax\n";
				buff += "\tmovl %eax, "+conv2string(curr->getoffset(quads[i].t))+"(%ebp)\n";
				break;

			case MINUS:
				buff += "\tmovl "+conv2string(curr->getoffset(quads[i].r))+"(%ebp), %eax\n";
				if(checkconst(quads[i].s)) buff += "\tsubl $"+quads[i].s+", %eax\n";
				else buff += "\tsubl "+conv2string(curr->getoffset(quads[i].s))+"(%ebp), %eax\n";
				buff += "\tmovl %eax, "+conv2string(curr->getoffset(quads[i].t))+"(%ebp)\n";
				break;

			case MUL:
				buff += "\tmovl "+conv2string(curr->getoffset(quads[i].r))+"(%ebp), %eax\n";
				if(checkconst(quads[i].s)) buff += "\timull $"+quads[i].s+", %eax\n";
				else buff += "\timull "+conv2string(curr->getoffset(quads[i].s))+"(%ebp), %eax\n";
				buff += "\tmovl %eax, "+conv2string(curr->getoffset(quads[i].t))+"(%ebp)\n";
				break;

			case DIV:
				buff += "\tmovl "+conv2string(curr->getoffset(quads[i].r))+"(%ebp), %eax\n";
				buff += "\tcltd\n";
				if(checkconst(quads[i].s)) buff += "\tidivl $"+quads[i].s+"\n";
				else buff += "\tidivl "+conv2string(curr->getoffset(quads[i].s))+"(%ebp)\n";
				buff += "\tmovl %eax, "+conv2string(curr->getoffset(quads[i].t))+"(%ebp)\n";
				break;

			case MOD:
				buff += "\tmovl "+conv2string(curr->getoffset(quads[i].r))+"(%ebp), %eax\n";
				buff += "\tcltd\n";
				if(checkconst(quads[i].s)) buff += "\tidivl $"+quads[i].s+"\n";
				else buff += "\tidivl "+conv2string(curr->getoffset(quads[i].s))+"(%ebp)\n";
				buff += "\tmovl %edx, "+conv2string(curr->getoffset(quads[i].t))+"(%ebp)\n";
				break;

			case UMINUS:
				buff += "\tmovl "+conv2string(curr->getoffset(quads[i].r))+"(%ebp), %eax\n";
				buff += "\tnegl %eax\n";
				buff += "\tmovl %eax, "+conv2string(curr->getoffset(quads[i].t))+"(%ebp)\n";
				break;

			case GTO:
				buff += "\tjmp "+labels[conv2int(quads[i].t)]+"\n";
				break;

			case IFGOTO:
				buff += "\tcmpl $0, "+conv2string(curr->getoffset(quads[i].r))+"(%ebp)\n";
				buff += "\tjne "+labels[conv2int(quads[i].t)]+"\n";
				break;

			case IFFalseGOTO:
				buff += "\tcmpl $0, "+conv2string(curr->getoffset(quads[i].r))+"(%ebp)\n";
				buff += "\tje "+labels[conv2int(quads[i].t)]+"\n";
				break;

			case IFLessGOTO:
				buff += "\tmovl "+conv2string(curr->getoffset(quads[i].r))+"(%ebp), %eax\n";
				buff += "\tcmpl "+conv2string(curr->getoffset(quads[i].s))+"(%ebp), %eax\n";
				buff += "\tjl "+labels[conv2int(quads[i].t)]+"\n";
				break;

			case IFGrtGOTO:
				buff += "\tmovl "+conv2string(curr->getoffset(quads[i].r))+"(%ebp), %eax\n";
				buff += "\tcmpl "+conv2string(curr->getoffset(quads[i].s))+"(%ebp), %eax\n";
				buff += "\tjg "+labels[conv2int(quads[i].t)]+"\n";
				break;

			case IFLessEqGOTO:
				buff += "\tmovl "+conv2string(curr->getoffset(quads[i].r))+"(%ebp), %eax\n";
				buff += "\tcmpl "+conv2string(curr->getoffset(quads[i].s))+"(%ebp), %eax\n";
				buff += "\tjle "+labels[conv2int(quads[i].t)]+"\n";
				break;

			case IFGrtEqGOTO:
				buff += "\tmovl "+conv2string(curr->getoffset(quads[i].r))+"(%ebp), %eax\n";
				buff += "\tcmpl "+conv2string(curr->getoffset(quads[i].s))+"(%ebp), %eax\n";
				buff += "\tjge "+labels[conv2int(quads[i].t)]+"\n";
				break;

			case IFLogEqGOTO:
				buff += "\tmovl "+conv2string(curr->getoffset(quads[i].r))+"(%ebp), %eax\n";
				buff += "\tcmpl "+conv2string(curr->getoffset(quads[i].s))+"(%ebp), %eax\n";
				buff += "\tje "+labels[conv2int(quads[i].t)]+"\n";
				break;

			case IFNotEqGOTO:
				buff += "\tmovl "+conv2string(curr->getoffset(quads[i].r))+"(%ebp), %eax\n";
				buff += "\tcmpl "+conv2string(curr->getoffset(quads[i].s))+"(%ebp), %eax\n";
				buff += "\tjne "+labels[conv2int(quads[i].t)]+"\n";
				break;

			case EQ:
				if(checkconst(quads[i].r))
					buff += "\tmovl $"+quads[i].r+", "+conv2string(curr->getoffset(quads[i].t))+"(%ebp)\n";
				else
				{
					buff += "\tmovl "+conv2string(curr->getoffset(quads[i].r))+"(%ebp), %eax\n";
					buff += "\tmovl %eax, "+conv2string(curr->getoffset(quads[i].t))+"(%ebp)\n";
				}
				break;

			case EQARR:
				buff += "\tmovl "+conv2string(curr->getoffset(quads[i].r))+"(%ebp), %eax\n";
				buff += "\taddl "+conv2string(curr->getoffset(quads[i].s))+"(%ebp), %eax\n";
				buff += "\tmovl 0(%eax), %ebx\n";
				buff += "\tmovl %ebx, "+conv2string(curr->getoffset(quads[i].t))+"(%ebp)\n";
				break;

			case ARREQ:
				buff += "\tmovl "+conv2string(curr->getoffset(quads[i].t))+"(%ebp), %eax\n";
				buff += "\taddl "+conv2string(curr->getoffset(quads[i].r))+"(%ebp), %eax\n";
				buff += "\tmovl "+conv2string(curr->getoffset(quads[i].s))+"(%ebp), %ebx\n";
				buff += "\tmovl %ebx, 0(%eax)\n";
				break;

			case PAR:
				if(checkconst(quads[i].t)) buff += "\tmovl "+quads[i].t+", %eax\n";
				else buff += "\tmovl "+conv2string(curr->getoffset(quads[i].t))+"(%ebp), %eax\n";
				buff += "\tpushl %eax\n";
				parsize += 4;
				break;

			case CALL:
				buff += "\tcall "+quads[i].r+"\n";
				buff += "\tmovl %eax, "+conv2string(curr->getoffset(quads[i].t))+"(%ebp)\n";
				buff += "\taddl $"+conv2string(parsize)+", %esp\n";
				parsize = 0;
				break;

			case LAB:
				if(scoped == true) buff+= makeEpilogue(curr);
				curr = GlobalTab.lookup(quads[i].t)->sub;
				buff += makePrologue(curr);
				scoped = true;
				break;

			case EQADD:
				buff += "\tleal "+conv2string(curr->getoffset(quads[i].r))+"(%ebp), %eax\n";
				buff += "\tmovl %eax, "+conv2string(curr->getoffset(quads[i].t))+"(%ebp)\n";
				break;

			case EQPVAL:
				buff += "\tmovl "+conv2string(curr->getoffset(quads[i].r))+"(%ebp), %eax\n";
				buff += "\tmovl 0(%eax), %ebx\n";
				buff += "\tmovl %ebx, "+conv2string(curr->getoffset(quads[i].t))+"(%ebp)\n";
				break;			

			case PVALEQ:
				buff += "\tmovl "+conv2string(curr->getoffset(quads[i].t))+"(%ebp), %eax\n";
				buff += "\tmovl "+conv2string(curr->getoffset(quads[i].r))+"(%ebp), %ebx\n";
				buff += "\tmovl %ebx, 0(%eax)\n";
				break;	

			case RET:
				if(quads[i].t != "") buff += "\tmovl "+conv2string(curr->getoffset(quads[i].t))+"(%ebp), %eax\n";
				buff += "\tjmp .ret_"+curr->name+"\n";
				break;
		}
		asmout<<buff;
	}
	asmout<<makeEpilogue(curr);
}





//%%%%%%%%%%%%%%%%%%     Main function     %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

/* Debug parameter if turned on, the program will print the stack operations of the parsing */
int debug = 0;

/* Initiates global variables of the program */
void init()
{
	int ind = __filename.length() - 1;
	while(ind >= 0)
	{
		if(__filename[ind] == '.') break;
		ind--;
	}

	if(ind != -1) __filename = __filename.substr(0,ind);

	string symfile = __filename + "_symtab.out";
	string quadfile = __filename + "_quads.out";
	string asmfile = __filename + ".s";
	symout.open(symfile.c_str());
	quadout.open(quadfile.c_str());
	asmout.open(asmfile.c_str());

	/* Pushes GlobalTab to the stack as the current scope */
	scopes.push(&GlobalTab);

	/* Push print, read functions to symbol table */

	symbol* temp = new symbol("printi", TFUNC);
	temp->sub = new SymbolTable("printi");
	temp->sub->paramlookup(new symbol("val", TINT));
	temp->sub->func = new funct();
	(temp->sub->func)->typelist.push_back(TINT);
	(temp->sub->func)->rettype = TVOID;
	GlobalTab.lookup(temp);

	temp = new symbol("prints", TFUNC);
	temp->sub = new SymbolTable("prints");
	temp->sub->paramlookup(new symbol("str", TSTR));
	temp->sub->func = new funct();
	(temp->sub->func)->typelist.push_back(TSTR);
	(temp->sub->func)->rettype = TVOID;
	GlobalTab.lookup(temp);

	temp = new symbol("readi", TFUNC);
	temp->sub = new SymbolTable("readi");
	temp->sub->paramlookup(new symbol("ep", type(TPTR, 0, TINT)));
	temp->sub->func = new funct();
	(temp->sub->func)->typelist.push_back(type(TPTR, 0, TINT));
	(temp->sub->func)->rettype = TINT;
	GlobalTab.lookup(temp);
}

/* Closes all file streams */
void dinit()
{
	printQuad();
	printSym();
	symout.close();
	quadout.close();
	asmout.close();
}

/* Reads from the file passed as parameter to the executable */
int main(int argc, char** argv)
{
	if(argc != 2)
	{
		cout<<"The lexer expects exactly 1 parameter for the specifying the input file name\n";
		exit(1);
	}

	freopen(argv[1],"r",stdin);
	if(stdin == 0)
	{
		cerr<<"File not found"<<endl;
		exit(1);
	}

	__filename = string(argv[1]);
	init();

	yydebug = debug;
	if(!yyparse()) cout<<string(argv[1])<<": code parsed successfully."<<endl;
	makeAsm();
	dinit();
	return 0;
}
