%error-verbose
%{

	#include <iostream>
	#include <fstream>
	#include <string>
	#include <vector>
	#include "compiler_translator.h"

	#define YYDEBUG 1
	using namespace std;

	extern int yylex();
	extern char * yytext;

	/* __line counts the line number for error reporting */
	extern int __line;

	void yyerror(const char * s);
	void yyerror(string s);

	/* Currtype stores the current type being read. Useful for updating array types while reading array dimensions */
	type currtype;

	/* Currfunc stores the function parameters while function declaration is being read */
	symbol* currfunc;


	/* The union can store 3 different types:
		1. The pointer to the symbol table
		2. The argument list for function parameters.
			This is required since there can be recursive functions calls in a way
			that the result of one function is passed as a parameter to the second.
		3. Nextlist for control statements.
		4. Address of the current instruction.
		5. Null parameter denoting that the type is unused since many production rules have not been used.
			This is useful for debugging and readability.

		NOTE: Since we haven't removed the production rules, a lot of warning messages appear while compilation.
		These are unavoidable since there are no production rules for the unused rules.
		Also if some code which requires the unused rules is compiled, it may result in a SEGMENTATION FAULT,
		as the propagation rules for different types are invalid.
	*/
%}

%union{
	class symbol* sym;
	class ArgList* al;
	class nextlist* nl;
	int add;
	char null;
}

%token <null> AUTO
%token <null> BREAK
%token <null> CASE
%token <null> CHAR
%token <null> CONST
%token <null> CONTINUE
%token <null> DEFAULT
%token <null> DO
%token <null> DOUBLE
%token <null> ELSE
%token <null> ENUM
%token <null> EXTERN
%token <null> FLOAT
%token <null> FOR
%token <null> GOTO
%token <null> IF
%token <null> INLINE
%token <null> INT
%token <null> LONG
%token <null> REGISTER
%token <null> RESTRICT
%token <null> RETURN
%token <null> SHORT
%token <null> SIGNED
%token <null> SIZEOF
%token <null> STATIC
%token <null> STRUCT
%token <null> SWITCH
%token <null> TYPEDEF
%token <null> UNION
%token <null> UNSIGNED
%token <null> VOID
%token <null> VOLATILE
%token <null> WHILE
%token <null> BOOL
%token <null> COMPLEX
%token <null> IMAGINARY

%token <null> ACC
%token <null> INC
%token <null> DEC
%token <null> SHL
%token <null> SHR
%token <null> LTE
%token <null> GTE
%token <null> EQUAL
%token <null> NEQUAL
%token <null> LogAND
%token <null> LogOR
%token <null> ELIP
%token <null> AssSTAR
%token <null> AssDIV
%token <null> AssMOD
%token <null> AssPLUS
%token <null> AssMINUS
%token <null> AssSHL
%token <null> AssSHR
%token <null> AssBinAND
%token <null> AssXOR
%token <null> AssBinOR

%token <sym> IDENTIFIER
%token <sym> CONSTANT
%token <str> STRING_LITERAL

%type <sym> translation_unit
%type <sym> external_declaration
%type <sym> function_definition
%type <sym> push_sym
%type <sym> declaration_list
%type <sym> declaration
%type <sym> declaration_specifiers
%type <sym> init_declarator_list
%type <sym> init_declarator
%type <sym> storage_class_specifier
%type <sym> type_specifier
%type <sym> specifier_qualifier_list
%type <sym> enum_specifier
%type <sym> enumerator_list
%type <sym> enumerator
%type <sym> enumeration_constant
%type <sym> type_qualifier
%type <sym> function_specifier
%type <sym> declarator
%type <sym> direct_declarator
%type <sym> pointer
%type <sym> type_qualifier_list
%type <sym> parameter_type_list
%type <sym> parameter_list
%type <sym> parameter_declaration
%type <sym> identifier_list
%type <sym> type_name
%type <sym> initializer
%type <sym> initializer_list
%type <sym> designation
%type <sym> designator_list
%type <sym> designator
%type <nl> statement
%type <nl> labeled_statement
%type <nl> compound_statement
%type <nl> block_item_list
%type <nl> block_item
%type <nl> expression_statement
%type <nl> selection_statement
%type <nl> iteration_statement
%type <nl> jump_statement
%type <sym> temp
%type <sym> bool_temp
%type <sym> bool_expression
%type <sym> primary_expression
%type <sym> postfix_expression
%type <al> argument_expression_list
%type <sym> unary_expression
%type <sym> cast_expression
%type <sym> multiplicative_expression
%type <sym> additive_expression
%type <sym> shift_expression
%type <sym> relational_expression
%type <sym> equality_expression
%type <sym> and_expression
%type <sym> exclusive_or_expression
%type <sym> inclusive_or_expression
%type <sym> nb_cast_expression
%type <sym> nb_multiplicative_expression
%type <sym> nb_additive_expression
%type <sym> nb_shift_expression
%type <sym> nb_relational_expression
%type <sym> nb_equality_expression
%type <sym> nb_and_expression
%type <sym> nb_exclusive_or_expression
%type <sym> nb_inclusive_or_expression
%type <sym> bool_inclusive_or_expression
%type <sym> logical_and_expression
%type <sym> bool_logical_and_expression
%type <sym> logical_or_expression
%type <sym> bool_logical_or_expression
%type <sym> conditional_expression
%type <sym> assignment_expression
%type <sym> assignment_operator
%type <sym> expression
%type <sym> constant_expression

%type <add> address_nonterm
%type <nl> jump_nonterm

%nonassoc IFX
%nonassoc ELSE

%%


translation_unit 			:	external_declaration
							| 	translation_unit external_declaration
							;

external_declaration 		:	function_definition
							| 	declaration
							;

function_definition 		:	declaration_specifiers declarator declaration_list compound_statement
								{
									/* Backpatch the compound statement */
									backpatch($4->l, currAddr()+1);

									/* Pops the current scope since the function scope has ended */
									scopes.pop();

									/* Emit return. This may cause multiple return statements.
									But that is unavoidable since there may be missing return statements in
									the code, which wont let the function return */
									// emit("", RET);
								}
							| 	declaration_specifiers declarator compound_statement
								{
									/* Backpatch the compound statement */
									backpatch($3->l, currAddr()+1);

									/* Pops the current scope since the function scope has ended */
									scopes.pop();

									/* Emit return. This may cause multiple return statements.
									But that is unavoidable since there may be missing return statements in
									the code, which wont let the function return */
									// emit("", RET);
								}
							;

declaration_list 			:	declaration
							| 	declaration_list declaration
							;











declaration 				:	declaration_specifiers init_declarator_list ';'
								{
									/* Type reading has ended. Reset currtype */
									currtype = TNULL;
								} 
							| 	declaration_specifiers ';'
							;

declaration_specifiers 		:	storage_class_specifier declaration_specifiers
							| 	storage_class_specifier
							| 	type_specifier declaration_specifiers
							| 	type_specifier
							| 	type_qualifier declaration_specifiers
							| 	type_qualifier
							| 	function_specifier declaration_specifiers
							| 	function_specifier
							;

init_declarator_list 		:	init_declarator 
							| 	init_declarator_list ',' init_declarator
							;

init_declarator 			:	declarator
								{
									/* Lookup variable in symbol table */
									if(($1->t).tname != TFUNC) $$ = scopes.top()->lookup($1);
									else yyerror("Cannot declare function without definition");
								}
							| 	declarator '=' initializer
								{
									/* Initialize if possible. Otherwise report error */
									if(($1->t).tname == TARR) yyerror("Cannot initialize arrays");
									if(($1->t).tname == TFUNC) yyerror("Cannot initialize functions");
									$$ = scopes.top()->lookup($1);

									/* Perform suitable type conversions */
									typeconv($3, $$);
									emit($1->getname(), EQ, $3->getname());
								}
							;

storage_class_specifier 	:	EXTERN
							| 	STATIC
							| 	AUTO
							| 	REGISTER
							;

type_specifier 				:	VOID
								{
									/* Save current type for future usage */
									currtype = TVOID;
								}
							| 	CHAR
								{
									/* Save current type for future usage */
									currtype = TCHAR;
								}
							| 	SHORT
							| 	INT
								{
									/* Save current type for future usage */
									currtype = TINT;
								}
							| 	LONG
							| 	FLOAT
							| 	DOUBLE
								{
									/* Save current type for future usage */
									currtype = TDOUBLE;
								}
							| 	SIGNED
							| 	UNSIGNED
							| 	BOOL
							| 	COMPLEX
							| 	IMAGINARY
							| 	enum_specifier
							;

specifier_qualifier_list 	:	type_specifier specifier_qualifier_list
							| 	type_specifier
							| 	type_qualifier specifier_qualifier_list
							| 	type_qualifier
							;

enum_specifier 				:	ENUM IDENTIFIER '{' enumerator_list '}'
							|	ENUM '{' enumerator_list '}'
							| 	ENUM IDENTIFIER '{' enumerator_list ',' '}'
							| 	ENUM '{' enumerator_list ',' '}'
							| 	ENUM IDENTIFIER
							;

enumerator_list 			:	enumerator
							| 	enumerator_list ',' enumerator
							;

enumerator 					:	enumeration_constant
							| 	enumeration_constant '=' constant_expression
							;

enumeration_constant 		:	IDENTIFIER
							;

type_qualifier 				:	CONST
							| 	RESTRICT
							| 	VOLATILE
							;

function_specifier 			:	INLINE
							;

declarator 					:	pointer direct_declarator
								{
									$$ = $2;
								}
							| 	direct_declarator
							;

direct_declarator 			:	IDENTIFIER
								{
									/* Save current type and also initiate function class.
										The function class will be used if the identifier is a function name */

									$1->t = currtype;
									currfunc = new symbol($1->getname(), TFUNC);
									currfunc->createfunc();
									(currfunc->sub->func)->rettype = currtype;
									$$ = $1;
								}
							| 	'(' declarator ')'
							| 	direct_declarator '[' type_qualifier_list assignment_expression ']'
							| 	direct_declarator '[' type_qualifier_list ']'
							| 	direct_declarator '[' assignment_expression ']'
								{
									/* Add array index after proper checks.
									Array indexing possible with only integer type indices */

									if($3->constant != 1) yyerror("Cannot initialize array with non-constant size");
									if(($3->t).tname != TINT) yyerror("Cannot initialize array with non-integer size");
									$1->t = type(TARR, $3->v.ival, $1->t);
									currtype = type(TARR, $3->v.ival, currtype);
									$$ = $1;
								}
							| 	direct_declarator '[' ']'
								{
									/* Array declaration for parameters */
									$1->t = type(TARR, 0, $1->t);
									currtype = type(TARR, 0, currtype);
									$$ = $1;
								}
							| 	direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'
							| 	direct_declarator '[' STATIC assignment_expression ']'
							| 	direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'
							| 	direct_declarator '[' type_qualifier_list '*' ']'
							| 	direct_declarator '[' '*' ']'
							| 	direct_declarator push_sym '(' parameter_type_list ')'
								{
									/* Push_sym stores the symbol* pointer for the function that is
										being declared.
										This is passed on to the 'direct_declarator'.
										*/

									$$ = $2;
								}
							| 	direct_declarator push_sym '(' identifier_list ')'
								{
									$$ = $2;
								}
							| 	direct_declarator push_sym '(' ')'
								{
									$$ = $2;
								}
							;

push_sym					:
								{
									/* push_sym performs lookup for the current function declaration,
									ans also pushes its symboltable into the scope stack, so that its variables
									can be declared in its scope
									*/
									scopes.top()->lookup(currfunc);
									scopes.push(currfunc->sub);
									emit(currfunc->name, LAB);
									$$ = currfunc;
								}
							;

pointer 					:	'*' type_qualifier_list
							| 	'*'
								{
									/* Updates currtype to a pointer of the previous type */
									currtype = type(TPTR,0,currtype);
								}
							| 	'*' type_qualifier_list pointer
							| 	'*' pointer
								{
									/* Updates currtype to a pointer of the previous type */
									currtype = type(TPTR,0,currtype);
								}
							;

type_qualifier_list 		:	type_qualifier
							| 	type_qualifier_list type_qualifier
							;

parameter_type_list 		:	parameter_list
							| 	parameter_list ',' ELIP
							;

parameter_list 				:	parameter_declaration
							| 	parameter_list ',' parameter_declaration
							;

parameter_declaration 		:	declaration_specifiers declarator
								{
									/* Saves the paramter types into the functions symbol table. */
									scopes.top()->paramlookup($2);
									(scopes.top()->func)->typelist.push_back(currtype);
								}
							| 	declaration_specifiers
							;

identifier_list 			:	IDENTIFIER
							| 	identifier_list ',' IDENTIFIER
							;

type_name 					:	specifier_qualifier_list
							;

initializer 				:	assignment_expression
							| 	'{' initializer_list '}'
							| 	'{' initializer_list ',' '}'
							;

initializer_list 			:	designation initializer
							| 	initializer
							| 	initializer_list ',' designation initializer
							| 	initializer_list ',' initializer
							;

designation 				:	designator_list '='
							;

designator_list 			:	designator
							| 	designator_list designator
							;

designator 					:	'[' constant_expression ']'
							| 	'.' IDENTIFIER
							;











statement 					:	labeled_statement
							| 	compound_statement
							| 	expression_statement
							| 	selection_statement
							| 	iteration_statement
							| 	jump_statement
							;

labeled_statement 			:	IDENTIFIER ':' statement
							| 	CASE constant_expression ':' statement
							| 	DEFAULT ':' statement
							;

compound_statement 			:	'{' block_item_list '}'
								{
									$$ = $2;
								}
							| 	'{' '}'
								{
									$$ = new nextlist();
								}
							;

block_item_list 			:	block_item
							| 	block_item_list address_nonterm block_item
								{
									/* Previous block must be backpatched before current block starts */

									backpatch($1->l, $2);
									$$ = $3;
								}
							;

block_item 					:	declaration
								{
									$$ = new nextlist();
								}
							| 	statement
							;

expression_statement 		:	expression ';'
								{
									if(($1->t).tname == TBOOL)
									{
										/* If dangling boolean, then backpatch it */
										backpatch($1->tl, currAddr()+1);
										backpatch($1->fl, currAddr()+1);
									}
									$$ = new nextlist();
								}
							|	';'
								{
									$$ = new nextlist();
								}
							;

selection_statement 		: 	IF '(' bool_expression ')' address_nonterm statement jump_nonterm ELSE address_nonterm statement
								{
									backpatch($3->tl, $5);
									backpatch($3->fl, $9);
									$$ = new nextlist();
									$$->l = mergelist($6->l, $7->l);
									$$->l = mergelist($$->l, $10->l);
								}
							| 	IF '(' bool_expression ')' address_nonterm statement jump_nonterm %prec IFX
								{
									/* This produces a redundant GOTO due to 'jump_nonterm' nonterminal.
										The 'jump_nonterm' is essential for the grammar to parse, without which
										a reduce/reduce conflict occurs.
										*/
									backpatch($3->tl, $5);
									$$ = new nextlist();
									$$->l = $3->fl;
									$$->l = mergelist($$->l, $6->l);
									$$->l = mergelist($$->l, $7->l);
								}
							| 	SWITCH '(' expression ')' statement
							;

iteration_statement 		:	WHILE '(' address_nonterm bool_expression ')' address_nonterm statement jump_nonterm
								{
									backpatch($8->l, $3);
									backpatch($7->l, $3);
									backpatch($4->tl, $6);

									$$ = new nextlist();
									$$->l = $4->fl;
								}
							| 	DO address_nonterm statement address_nonterm WHILE '(' bool_expression ')' ';'
								{
									backpatch($7->tl, $2);
									backpatch($3->l, $4);
									$$ = new nextlist();
									$$->l = $7->fl;
								}
							| 	FOR '(' temp ';' address_nonterm bool_temp ';' address_nonterm temp jump_nonterm ')' address_nonterm statement jump_nonterm
								{
									backpatch($6->tl, $12);
									backpatch($14->l, $8);
									backpatch($13->l, $8);
									backpatch($10->l, $5);

									$$ = new nextlist();
									$$->l = $6->fl;
								}
							| 	FOR '(' declaration ';' temp ';' temp ')' statement
							;

temp 						:	expression
							| 	
								{
									$$ = 0;
								}
							;

bool_temp 					:	bool_expression
							| 	
							;

bool_expression				: 	expression
								{
									/* This augmentation has been provided to convert ints to bool inplace.
										Calling the convIntBool at an other place can cause the intermediate
										codes to be jumped due to the GOTOs of the conversion
										*/
									convDblInt($1);
									convIntBool($1);
									$$ = $1;
								}
							;

jump_statement 				:	GOTO IDENTIFIER ';'
							| 	CONTINUE ';'
							| 	BREAK ';'
							| 	RETURN temp ';'
								{
									if($2 == 0)
									{
										/* There is nothing to return, then emit return only */
										emit("", RET);
									}
									else
									{
										/* Otherwise return the expression */
										type ty = (scopes.top()->func)->rettype;
										typeconv($2, ty);
										emit($2->getname(), RET);
									}
									$$ = new nextlist();
								}
							;











primary_expression			: 	IDENTIFIER
								{
									/* Lookup identifier in the symbol table to use the variable in expressions */

									$$ = scopes.top()->lookup($1->getname());
									$$ = new symbol(*$$);
									if(($$->t).tname == TARR)
									{
										$$ = gentemp(type(TPTR, 0, ($$->t).getbasetype()));
										emit($$->getname(), EQADD, $1->getname());
									}
								}
							|	CONSTANT
							| 	STRING_LITERAL
							| 	'(' expression ')'
								{
									$$ = $2;
								}
							;

postfix_expression 			: 	primary_expression
							| 	postfix_expression '[' expression ']'
								{
									/* Resolve array addresses after from checks. */
									/* Array indices are added to the array class of the symbol for resolution */

									if(($3->t).tname != TINT) yyerror("Cannot access non-integer index");
									if(($1->t).tname != TARR && ($1->t).tname != TPTR)
										yyerror("Cannot access non-array or non-pointer variable");

									convCharInt($3);
									convBoolInt($3);

									symbol* temp = gentemp(TINT);
									$1->arr = new ArrayCustom($1->getname(), temp, ($1->t).getbasetype());
									emit(temp->getname(), EQ, $3->getname());
									emit(temp->getname(), temp->getname(), MUL, conv2string(type(($1->t).getbasetype()).getsize()));
									$$ = $1;
									$$->t = ($$->t).getbasetype();
								}
							| 	postfix_expression '(' argument_expression_list ')'
								{
									/* Calls function after suitable checks */

									if(($1->t).tname != TFUNC) yyerror("Cannot call non function identifiers");
									$3->call($1);
									$$ = $1;
								}
							| 	postfix_expression '(' ')'
							| 	postfix_expression '.' IDENTIFIER
							| 	postfix_expression ACC IDENTIFIER
							|	postfix_expression INC
								{
									/* Saves the previous value of the variable for use in the expression,
									increments the variable and propagates the temporary */

									/* Post increment can only occur for non-temporary and integer type variables */

									if($1->temporary) yyerror("Cannot increment temporary variable");
									if(($1->t).getbasetype() != TINT && ($1->t).getbasetype() != TPTR)
										yyerror("Invalid use of increment operator on non-integer type");
									if($1->arr != 0)
									{
										/* If type is ARRAY, then the resolved array needs to be stored in a
											temporary variable, which is incremented and stored back to the array location */
										$$ = gentemp(($1->t).getbasetype());
										emit($$->getname(), $1->getname(), EQARR, $1->getoffset());
										symbol* temp = gentemp(($1->t).getbasetype());
										emit(temp->getname(), $1->getname(), EQARR, $1->getoffset());
										emit(temp->getname(), temp->getname(), PLUS, "1");
										emit($1->getname(), $1->getoffset(), ARREQ, temp->getname());
									}
									else
									{
										$$ = gentemp(($1->t).tname);
										symbol* temp1 = gentemp(TINT);
										emit(temp1->getname(), EQ, "1");
										emit($$->getname(), EQ, $1->getname());
										emit($1->getname(), $1->getname(), PLUS, temp1->getname());
									}
								}
							| 	postfix_expression DEC
								{
									/* Saves the previous value of the variable for use in the expression,
									decrements the variable and propagates the temporary */

									/* Post decrement can only occur for non-temporary and integer type variables */

									if($1->temporary) yyerror("Cannot decrement temporary variable");
									if(($1->t).getbasetype() != TINT && ($1->t).getbasetype() != TPTR)
										yyerror("Invalid use of decrement operator on non-integer type");

									if($1->arr != 0)
									{
										/* If type is ARRAY, then the resolved array needs to be stored in a
											temporary variable, which is decremented and stored back to the array location */
										$$ = gentemp(($1->t).getbasetype());
										emit($$->getname(), $1->getname(), EQARR, $1->getoffset());
										symbol* temp = gentemp(($1->t).getbasetype());
										emit(temp->getname(), $1->getname(), EQARR, $1->getoffset());
										emit(temp->getname(), temp->getname(), MINUS, "1");
										emit($1->getname(), $1->getoffset(), ARREQ, temp->getname());
									}
									else
									{
										$$ = gentemp(($1->t).tname);
										symbol* temp1 = gentemp(TINT);
										emit(temp1->getname(), EQ, "1");
										emit($$->getname(), EQ, $1->getname());
										emit($1->getname(), $1->getname(), MINUS, temp1->getname());
									}
								}
							| 	'(' type_name ')' '{' initializer_list '}'
							| 	'(' type_name ')' '{' initializer_list ',' '}'
							;

argument_expression_list	:	assignment_expression
								{
									/* Initiates an arglist for argument passing */

									$$ = new ArgList();
									$$->add($1);
								}
							| 	argument_expression_list ',' assignment_expression
								{
									/* Saves an argument to the arglist for the function call. */

									$1->add($3);
									$$ = $1;
								}
							;

unary_expression			:	postfix_expression
							| 	INC unary_expression
								{
									/* Pre-increment can only be performed on non-temporary and integer type variables */
									/* Increments the variable and propagates it. */

									if($2->temporary) yyerror("Cannot increment temporary variable");
									if(($2->t).getbasetype() != TINT && ($2->t).getbasetype() != TPTR)
										yyerror("Invalid use of increment operator on non-integer type");

									if($2->arr != 0)
									{
										/* If type is ARRAY, then the resolved array needs to be stored in a
											temporary variable, which is incremented and stored back to the array location */
										symbol* temp = gentemp(($2->t).getbasetype());
										emit(temp->getname(), $2->getname(), EQARR, $2->getoffset());
										emit(temp->getname(), temp->getname(), PLUS, "1");
										emit($2->getname(), $2->getoffset(), ARREQ, temp->getname());
										$$ = $2;
									}
									else
									{
										symbol* temp1 = gentemp(TINT);
										emit(temp1->getname(), EQ, "1");
										emit($2->getname(), $2->getname(), PLUS, temp1->getname());
										$$ = $2;
									}
								}
							| 	DEC unary_expression
								{
									if($2->temporary) yyerror("Cannot decrement temporary variable");
									if(($2->t).getbasetype() != TINT && ($2->t).getbasetype() != TPTR)
										yyerror("Invalid use of increment operator on non-integer type");

									if($2->arr != 0)
									{
										/* If type is ARRAY, then the resolved array needs to be stored in a
											temporary variable, which is decremented and stored back to the array location */
										symbol* temp = gentemp(($2->t).getbasetype());
										emit(temp->getname(), $2->getname(), EQARR, $2->getoffset());
										emit(temp->getname(), temp->getname(), MINUS, "1");
										emit($2->getname(), $2->getoffset(), ARREQ, temp->getname());
										$$ = $2;
									}
									else
									{
										symbol* temp1 = gentemp(TINT);
										emit(temp1->getname(), EQ, "1");
										emit($2->getname(), $2->getname(), MINUS, temp1->getname());
										$$ = $2;
									}
								}
							| 	'&' unary_expression
								{
									/* Address can be resolved only for variables that have been declared */
									if($2->temporary && $2->arr == 0) yyerror("Cannot resolve address of temporary variable");

									type ty = ($2->t).getbasetype();
									ty = type(TPTR, 0, ty);
									$$ = gentemp(ty);
									if($2->arr != 0)
									{
										emit($$->getname(), $2->getname(), PLUS, $2->getoffset());
									}
									else
									{
										emit($$->getname(), EQADD, $2->name);
									}
								}
							| 	'*' cast_expression
								{
									/* Pointer operator can be applied only on pointer type variables */
									if(($2->t).tname != TPTR) yyerror("Cannot resolve pointer operator of non-pointer variable");

									symbol* temp = gentemp(TINT);
									$2->arr = new ArrayCustom($2->getname(), temp, ($2->t).getbasetype());
									emit(temp->getname(), EQ, "0");
									emit(temp->getname(), temp->getname(), MUL, conv2string(type(($2->t).getbasetype()).getsize()));
									$$ = $2;
									$$->t = ($$->t).getbasetype();
								}
							| 	'+' cast_expression
								{
									convBoolInt($2);
									$$ = $2;
								}
							| 	'-' cast_expression
								{
									convBoolInt($2);
									$$ = gentemp(($2->t).tname);
									emit($$->getname(), UMINUS, $2->getname());
								}
							| 	'~' cast_expression
							| 	'!' cast_expression
								{
									convIntBool($2);
									swap($2->tl, $2->fl);
								}
							| 	SIZEOF unary_expression
							| 	SIZEOF '(' type_name ')'
							;

cast_expression 			:	unary_expression
								{
									if($1->arr != 0)
									{
										/* Array address is resolved at this point. */
										$$ = gentemp(($1->t).getbasetype());
										emit($$->getname(), $1->getname(), EQARR, $1->getoffset());
									}
									else $$ = $1;
								}
							| 	'(' type_name ')' cast_expression
								{
									/* Explicit ype conversion */
									convBoolInt($4);
									if(($4->t).tname == TARR)
									{
										if(($4->arr)->dims.size() == 0) $$ = gentemp(($4->t).getbasetype());
										else $$ = gentemp(type(TPTR, 0, type(TINT)));
										emit($$->getname(), EQ, $4->getname());
										$4 = $$;
									}
									typeconv($4, new symbol(currtype));
									$$ = $4;
								}
							;

nb_cast_expression			:	cast_expression
								{
									/* This augmentation helps in inplace conversion from bool to int.
									 Calling the convBoolInt() function from some other place can cause the intermediate
									 instructions to get skipped due to the gotos of the conversion */
									/* This augmentation has usage in the arithmetic operations, which require the operands
									to be of non-boolean type */
									convBoolInt($1);
									$$ = $1;
								}
							;

multiplicative_expression 	:	cast_expression
							| 	nb_multiplicative_expression '*' nb_cast_expression
								{
									typecheck($1, $3);
									$$ = gentemp(($1->t).tname);
									emit($$->getname(), $1->getname(), MUL, $3->getname());
								}
							| 	nb_multiplicative_expression '/' nb_cast_expression
								{
									typecheck($1, $3);
									$$ = gentemp(($1->t).tname);
									emit($$->getname(), $1->getname(), DIV, $3->getname());
								}
							| 	nb_multiplicative_expression '%' nb_cast_expression
								{
									typecheck($1, $3);
									if(($1->t).tname != TINT) yyerror("'%' operator on non-integer types");
									$$ = gentemp(($1->t).tname);
									emit($$->getname(), $1->getname(), MOD, $3->getname());
								}
							;

nb_multiplicative_expression:	multiplicative_expression
								{
									/* This augmentation helps in inplace conversion from bool to int.
									 Calling the convBoolInt() function from some other place can cause the intermediate
									 instructions to get skipped due to the gotos of the conversion */
									/* This augmentation has usage in the arithmetic operations, which require the operands
									to be of non-boolean type */

									convBoolInt($1);
									$$ = $1;
								}
							;

additive_expression 		:	multiplicative_expression
							| 	nb_additive_expression '+' nb_multiplicative_expression
								{
									typecheck($1, $3);
									$$ = gentemp(($1->t).getbasetype());
									emit($$->getname(), $1->getname(), PLUS, $3->getname());
								}
							| 	nb_additive_expression '-' nb_multiplicative_expression
								{
									typecheck($1, $3);
									$$ = gentemp(($1->t).getbasetype());
									emit($$->getname(), $1->getname(), MINUS, $3->getname());
								}
							;

nb_additive_expression		: 	additive_expression
								{
									/* This augmentation helps in inplace conversion from bool to int.
									 Calling the convBoolInt() function from some other place can cause the intermediate
									 instructions to get skipped due to the gotos of the conversion */
									/* This augmentation has usage in the arithmetic operations, which require the operands
									to be of non-boolean type */

									convBoolInt($1);
									$$ = $1;
								}
							;

shift_expression 			:	additive_expression
							| 	nb_shift_expression SHL nb_additive_expression
								{
									typecheck($1, $3);
									if(($1->t).tname != TINT) yyerror("'<<' operator on non-integer types");
									$$ = gentemp(($1->t).tname);
									emit($$->getname(), $1->getname(), SLL, $3->getname());
								}
							| 	nb_shift_expression SHR nb_additive_expression
								{
									typecheck($1, $3);
									if(($1->t).tname != TINT) yyerror("'>>' operator on non-integer types");
									$$ = gentemp(($1->t).tname);
									emit($$->getname(), $1->getname(), SRL, $3->getname());
								}
							;

nb_shift_expression			:	shift_expression
								{
									/* This augmentation helps in inplace conversion from bool to int.
									 Calling the convBoolInt() function from some other place can cause the intermediate
									 instructions to get skipped due to the gotos of the conversion */
									/* This augmentation has usage in the arithmetic operations, which require the operands
									to be of non-boolean type */

									convBoolInt($1);
									$$ = $1;
								}
							;

relational_expression 		:	shift_expression
							| 	nb_relational_expression '<' nb_shift_expression
								{
									if(($1->t).tname != TCHAR || ($3->t).tname != TCHAR) typecheck($1, $3);

									emit("", $1->getname(), IFLessGOTO, $3->getname());
									$$ = new symbol(TBOOL);
									$$->tl = makelist(currAddr());
									emit("",GTO);
									$$->fl = makelist(currAddr());
									$$->t = type(TBOOL);
								}
							|	nb_relational_expression '>' nb_shift_expression
								{
									if(($1->t).tname != TCHAR || ($3->t).tname != TCHAR) typecheck($1, $3);

									emit("", $1->getname(), IFGrtGOTO, $3->getname());
									$$ = new symbol(TBOOL);
									$$->tl = makelist(currAddr());
									emit("",GTO);
									$$->fl = makelist(currAddr());
									$$->t = type(TBOOL);
								}
							| 	nb_relational_expression LTE nb_shift_expression
								{
									if(($1->t).tname != TCHAR || ($3->t).tname != TCHAR) typecheck($1, $3);

									emit("", $1->getname(), IFLessEqGOTO, $3->getname());
									$$ = new symbol(TBOOL);
									$$->tl = makelist(currAddr());
									emit("",GTO);
									$$->fl = makelist(currAddr());
									$$->t = type(TBOOL);
								}
							| 	nb_relational_expression GTE nb_shift_expression
								{
									if(($1->t).tname != TCHAR || ($3->t).tname != TCHAR) typecheck($1, $3);

									emit("", $1->getname(), IFGrtEqGOTO, $3->getname());
									$$ = new symbol(TBOOL);
									$$->tl = makelist(currAddr());
									emit("",GTO);
									$$->fl = makelist(currAddr());
									$$->t = type(TBOOL);
								}
							;

nb_relational_expression	:	relational_expression
								{
									/* This augmentation helps in inplace conversion from bool to int.
									 Calling the convBoolInt() function from some other place can cause the intermediate
									 instructions to get skipped due to the gotos of the conversion */
									/* This augmentation has usage in the arithmetic operations, which require the operands
									to be of non-boolean type */

									convBoolInt($1);
									$$ = $1;
								}
							;

equality_expression 		:	relational_expression
							| 	nb_equality_expression EQUAL nb_relational_expression
								{
									if(($1->t).tname != TCHAR || ($3->t).tname != TCHAR) typecheck($1, $3);

									emit("", $1->getname(), IFLogEqGOTO, $3->getname());
									$$ = new symbol(TBOOL);
									$$->tl = makelist(currAddr());
									emit("",GTO);
									$$->fl = makelist(currAddr());
									$$->t = type(TBOOL);
								}
							| 	nb_equality_expression NEQUAL nb_relational_expression
								{
									if(($1->t).tname != TCHAR || ($3->t).tname != TCHAR) typecheck($1, $3);

									emit("", $1->getname(), IFNotEqGOTO, $3->getname());
									$$ = new symbol(TBOOL);
									$$->tl = makelist(currAddr());
									emit("",GTO);
									$$->fl = makelist(currAddr());
									$$->t = type(TBOOL);
								}
							;

nb_equality_expression		: 	equality_expression
								{
									/* This augmentation helps in inplace conversion from bool to int.
									 Calling the convBoolInt() function from some other place can cause the intermediate
									 instructions to get skipped due to the gotos of the conversion */
									/* This augmentation has usage in the arithmetic operations, which require the operands
									to be of non-boolean type */

									convBoolInt($1);
									$$ = $1;
								}

and_expression 				:	equality_expression
							| 	nb_and_expression '&' nb_equality_expression
								{
									convBoolInt($1);
									convBoolInt($3);
									convDblInt($1);
									convDblInt($3);
									convCharInt($1);
									convCharInt($3);

									$$ = gentemp(TINT);
									emit($$->getname(), $1->getname(), BinAND, $3->getname());
								}
							;

nb_and_expression			:	and_expression
								{
									/* This augmentation helps in inplace conversion from bool to int.
									 Calling the convBoolInt() function from some other place can cause the intermediate
									 instructions to get skipped due to the gotos of the conversion */
									/* This augmentation has usage in the arithmetic operations, which require the operands
									to be of non-boolean type */

									convBoolInt($1);
									$$ = $1;
								}
							;

exclusive_or_expression 	:	and_expression
							| 	nb_exclusive_or_expression '^' nb_and_expression
								{
									convBoolInt($1);
									convBoolInt($3);
									convDblInt($1);
									convDblInt($3);
									convCharInt($1);
									convCharInt($3);

									$$ = gentemp(TINT);
									emit($$->getname(), $1->getname(), BinXOR, $3->getname());
								}
							;

nb_exclusive_or_expression	: 	exclusive_or_expression
								{
									/* This augmentation helps in inplace conversion from bool to int.
									 Calling the convBoolInt() function from some other place can cause the intermediate
									 instructions to get skipped due to the gotos of the conversion */
									/* This augmentation has usage in the arithmetic operations, which require the operands
									to be of non-boolean type */

									convBoolInt($1);
									$$ = $1;
								}
							;

inclusive_or_expression 	:	exclusive_or_expression
							| 	nb_inclusive_or_expression '|' nb_exclusive_or_expression
								{
									convBoolInt($1);
									convBoolInt($3);
									convDblInt($1);
									convDblInt($3);
									convCharInt($1);
									convCharInt($3);

									$$ = gentemp(TINT);
									emit($$->getname(), $1->getname(), BinOR, $3->getname());
								}
							;

nb_inclusive_or_expression	: 	inclusive_or_expression
								{
									/* This augmentation helps in inplace conversion from bool to int.
									 Calling the convBoolInt() function from some other place can cause the intermediate
									 instructions to get skipped due to the gotos of the conversion */
									/* This augmentation has usage in the arithmetic operations, which require the operands
									to be of non-boolean type */

									convBoolInt($1);
									$$ = $1;
								}
							;

logical_and_expression 		:	inclusive_or_expression
							| 	bool_logical_and_expression LogAND address_nonterm bool_inclusive_or_expression
								{
									/* The address_nonterm nonterminal has been provided to backpatch the truelists
									and falselists of the boolean expression.
									Such backpatching helps in efficient conversion of boolean functions to 3 address
									codes
									*/

									$$ = new symbol(TBOOL);
									backpatch($1->tl, $3);
									$$->tl = $4->tl;
									$$->fl = mergelist($1->fl, $4->fl);
								}
							;


logical_or_expression 		:	logical_and_expression
							| 	bool_logical_or_expression LogOR address_nonterm bool_logical_and_expression
								{
									/* The address_nonterm nonterminal has been provided to backpatch the truelists
									and falselists of the boolean expression.
									Such backpatching helps in efficient conversion of boolean functions to 3 address
									codes
									*/

									$$ = new symbol(TBOOL);
									backpatch($1->fl, $3);
									$$->fl = $4->fl;
									$$->tl = mergelist($1->tl, $4->tl);
								}
							;


bool_inclusive_or_expression:	inclusive_or_expression
								{
									/* This augmentation helps in inplace conversion from int or double to bool.
									 Calling the convIntBool() function from some other place can cause the intermediate
									 instructions to get skipped due to the gotos of the conversion */
									/* This augmentation has usage in the arithmetic operations, which require the operands
									to be of boolean type */

									convDblInt($1);
									convCharInt($1);
									convIntBool($1);
									$$ = $1;
								}
							;

bool_logical_or_expression	:	logical_or_expression
								{
									/* This augmentation helps in inplace conversion from int or double to bool.
									 Calling the convIntBool() function from some other place can cause the intermediate
									 instructions to get skipped due to the gotos of the conversion */
									/* This augmentation has usage in the arithmetic operations, which require the operands
									to be of boolean type */

									convDblInt($1);
									convCharInt($1);
									convIntBool($1);
									$$ = $1;
								}
							;

bool_logical_and_expression	:	logical_and_expression
								{
									/* This augmentation helps in inplace conversion from int or double to bool.
									 Calling the convIntBool() function from some other place can cause the intermediate
									 instructions to get skipped due to the gotos of the conversion */
									/* This augmentation has usage in the arithmetic operations, which require the operands
									to be of boolean type */

									convDblInt($1);
									convCharInt($1);
									convIntBool($1);
									$$ = $1;
								}
							;


conditional_expression 		:	logical_or_expression
							| 	bool_logical_or_expression '?' address_nonterm expression jump_nonterm ':' address_nonterm conditional_expression jump_nonterm
								{
									/* Suitable non terminals with empty transitions have been put to place jumps at proper
									places to compute the function */

									backpatch($1->tl, $3);
									backpatch($1->fl, $7);
									typecheck($4, $8);
									$$ = gentemp(($4->t).tname);
									emit($$->getname(), EQ, $4->getname());
									backpatch($5->l, currAddr());
									emit("", GTO);
									List li = List(currAddr());
									emit($$->getname(), EQ, $8->getname());
									backpatch($9->l, currAddr());
									backpatch(li, currAddr()+1);
								}
							;

assignment_expression 		:	conditional_expression
							| 	unary_expression assignment_operator assignment_expression
								{
									convBoolInt($3);
									typeconv($3,$1);
									if($1->arr != 0)
									{
										emit($1->getname(), $1->getoffset(), ARREQ, $3->getname());
									}
									else emit($1->getname(), EQ, $3->getname());
									$$ = $1;
								}
							;

assignment_operator 		:	'='
							| 	AssSTAR
							| 	AssDIV
							| 	AssMOD
							| 	AssPLUS
							| 	AssMINUS
							| 	AssSHL
							| 	AssSHR
							| 	AssBinAND
							| 	AssXOR
							| 	AssBinOR
							;

expression 					:	assignment_expression
							| 	expression ',' assignment_expression
							;

constant_expression 		:	conditional_expression
							;





address_nonterm 			:
								{
									$$ = currAddr()+1;
								}
							;

jump_nonterm				:
								{
									/* Emits a goto required for certain control statements */
									emit("", GTO);
									$$ = new nextlist();
									$$->l = makelist(currAddr());
								}
							;







%%


/* The error function reports the line number and file where the error has occured. */
void yyerror(const char *s)
{
	cout<<__filename<<": Line "<<__line<<":\t"<<s<<endl;
	printQuad();
	printSym();
	exit(1);
}

void yyerror(string s)
{
	cout<<__filename<<": Line "<<__line<<":\t"<<s<<endl;
	printQuad();
	printSym();
	exit(1);
}
