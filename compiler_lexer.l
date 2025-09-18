%{
	#include "y.tab.h"
	#include <iostream>
	#include <math.h>
	#include "compiler_translator.h"

	using namespace std;

	/* __line stores the current line number being parsed */
	int __line = 1;

%}

WS 						[ \t]
NEWLINE 				\n
COMMENT 				{SINGLELINE_COMMENT}|{MULTILINE_COMMENT}
SINGLELINE_COMMENT		"//"[^\n]*
NOT_STAR				[^"*"]|\n
NOT_SLASH 				[^"/"]|\n
NOT_SLASH_STAR 			[^"/""*"]|\n
MULTILINE_COMMENT		"/*"{NOT_STAR}*"*"("*"|({NOT_SLASH_STAR}{NOT_STAR}*"*"))*"/"

KEYWORD 				{KEYWORD_SET1}|{KEYWORD_SET2}|{KEYWORD_SET3}|{KEYWORD_SET4}
KEYWORD_SET1			"auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"
KEYWORD_SET2			"enum"|"extern"|"float"|"for"|"goto"|"if"|"inline"|"int"|"long"|"register"
KEYWORD_SET3			"restrict"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"
KEYWORD_SET4			"unsigned"|"void"|"volatile"|"while"|"_Bool"|"_Complex"|"_Imaginary"

DIGIT					[0-9]
IDENTIFIER_NONDIGIT 	[a-zA-Z]|"_"
IDENTIFIER 				{IDENTIFIER_NONDIGIT}({IDENTIFIER_NONDIGIT}|{DIGIT})*

NONZERO_DIGIT 			[1-9]
INTEGER_CONSTANT 		({NONZERO_DIGIT}{DIGIT}*)|("0")
DIGIT_SEQUENCE 			{DIGIT}+
FRACTIONAL_CONSTANT 	({DIGIT_SEQUENCE}?"."{DIGIT_SEQUENCE})|({DIGIT_SEQUENCE}".")
SIGN 					"+"|"-"
EXPONENT_PART 			(e|E){SIGN}?{DIGIT_SEQUENCE} 
FLOATING_CONSTANT 		({FRACTIONAL_CONSTANT}{EXPONENT_PART}?)|({DIGIT_SEQUENCE}{EXPONENT_PART})
ENUMERATION_CONSTANT 	{IDENTIFIER}
ESCAPE_SEQUENCE 		"\\\'"|"\\\""|"\\\?"|"\\\\"|"\\a"|"\\b"|"\\f"|"\\n"|"\\r"|"\\t"|"\\v"|"\\0"
C_CHAR 					[^("\'"|"\\"|\n)]|{ESCAPE_SEQUENCE}
CHARACTER_SEQUENCE 		{C_CHAR}+
CHARACTER_CONSTANT 		"\'"{CHARACTER_SEQUENCE}"\'"
CONSTANT 				{INTEGER_CONSTANT}|{FLOATING_CONSTANT}|{ENUMERATION_CONSTANT}|{CHARACTER_CONSTANT}

STRING_LITERAL 			"\""{S_CHAR_SEQUENCE}?"\""
S_CHAR 					[^"\"""\\"\n]|{ESCAPE_SEQUENCE}
S_CHAR_SEQUENCE 		{S_CHAR}+

PUNCTUATOR  			{PUNCTUATOR_SET1}|{PUNCTUATOR_SET2}|{PUNCTUATOR_SET3}|{PUNCTUATOR_SET4}|{PUNCTUATOR_SET5}|{PUNCTUATOR_SET6}
PUNCTUATOR_SET1 		"["|"]"|"("|")"|"{"|"}"|"."|"->"
PUNCTUATOR_SET2 		"++"|"--"|"&"|"*"|"+"|"-"|"~"|"!"
PUNCTUATOR_SET3 		"/"|"%"|"<<"|">>"|"<"|">"|"<="|">="|"=="|"!="|"^"|"|"|"&&"|"||"
PUNCTUATOR_SET4 		"?"|":"|";"|"..."
PUNCTUATOR_SET5 		"="|"*="|"/="|"%="|"+="|"-="|"<<="|">>="|"&="|"^="|"|="
PUNCTUATOR_SET6			","|"#"

%%
{WS}		{

}

{COMMENT}	{

	/* Newlines in the comments need to be incremented */
	for(int i = 0; yytext[i]!=0; i++) if(yytext[i] == '\n') __line++;
}

{NEWLINE}		{
	__line++;
}

{KEYWORD}		{
	if(strcmp(yytext,"auto") == 0) 		return AUTO;
	if(strcmp(yytext,"break") == 0) 	return BREAK;
	if(strcmp(yytext,"case") == 0) 		return CASE;
	if(strcmp(yytext,"char") == 0) 		return CHAR;
	if(strcmp(yytext,"const") == 0) 	return CONST;
	if(strcmp(yytext,"continue") == 0) 	return CONTINUE;
	if(strcmp(yytext,"default") == 0) 	return DEFAULT;
	if(strcmp(yytext,"do") == 0) 		return DO;
	if(strcmp(yytext,"double") == 0) 	return DOUBLE;
	if(strcmp(yytext,"else") == 0) 		return ELSE;
	if(strcmp(yytext,"enum") == 0) 		return ENUM;
	if(strcmp(yytext,"extern") == 0) 	return EXTERN;
	if(strcmp(yytext,"float") == 0) 	return FLOAT;
	if(strcmp(yytext,"for") == 0) 		return FOR;
	if(strcmp(yytext,"goto") == 0) 		return GOTO;
	if(strcmp(yytext,"if") == 0) 		return IF;
	if(strcmp(yytext,"inline") == 0) 	return INLINE;
	if(strcmp(yytext,"int") == 0) 		return INT;
	if(strcmp(yytext,"long") == 0) 		return LONG;
	if(strcmp(yytext,"register") == 0) 	return REGISTER;
	if(strcmp(yytext,"restrict") == 0) 	return RESTRICT;
	if(strcmp(yytext,"return") == 0) 	return RETURN;
	if(strcmp(yytext,"short") == 0) 	return SHORT;
	if(strcmp(yytext,"signed") == 0) 	return SIGNED;
	if(strcmp(yytext,"sizeof") == 0) 	return SIZEOF;
	if(strcmp(yytext,"static") == 0) 	return STATIC;
	if(strcmp(yytext,"struct") == 0) 	return STRUCT;
	if(strcmp(yytext,"switch") == 0) 	return SWITCH;
	if(strcmp(yytext,"typedef") == 0) 	return TYPEDEF;
	if(strcmp(yytext,"union") == 0) 	return UNION;
	if(strcmp(yytext,"unsigned") == 0) 	return UNSIGNED;
	if(strcmp(yytext,"void") == 0) 		return VOID;
	if(strcmp(yytext,"volatile") == 0) 	return VOLATILE;
	if(strcmp(yytext,"while") == 0) 	return WHILE;
	if(strcmp(yytext,"_Bool") == 0) 	return BOOL;
	if(strcmp(yytext,"_Complex") == 0) 	return COMPLEX;
	if(strcmp(yytext,"_Imaginary") == 0)return IMAGINARY;
}

{IDENTIFIER}	{
	yylval.sym = new symbol(yytext);
	return IDENTIFIER;
}

{INTEGER_CONSTANT}	{
	yylval.sym = gentemp(TINT);
	yylval.sym->constant = 1;
	yylval.sym->v.ival = atoi(yytext);
	emit(yylval.sym->name, EQ, string(yytext));
	return CONSTANT;
}

{FLOATING_CONSTANT}	{
	yylval.sym = gentemp(TDOUBLE);
	yylval.sym->constant = 1;
	yylval.sym->v.dval = atof(yytext); 
	emit(yylval.sym->name, EQ, string(yytext));
	return CONSTANT;
}

{CHARACTER_CONSTANT} {
	yylval.sym = gentemp(TCHAR);
	emit(yylval.sym->name, EQ, string(yytext));
	return CONSTANT;
}

{STRING_LITERAL} {
	yylval.sym = new symbol(TSTR);
	string* temp = new string(yytext);
	addstringconst(*temp);
	yylval.sym->strconst = temp;
	yylval.sym->name = "$"+getlabel(*temp);
	return STRING_LITERAL;
}

{PUNCTUATOR}	{
	if(strcmp(yytext,"->") == 0) return ACC;
	if(strcmp(yytext,"++") == 0) return INC;
	if(strcmp(yytext,"--") == 0) return DEC;
	if(strcmp(yytext,"<<") == 0) return SHL;
	if(strcmp(yytext,">>") == 0) return SHR;
	if(strcmp(yytext,"<=") == 0) return LTE;
	if(strcmp(yytext,">=") == 0) return GTE;
	if(strcmp(yytext,"==") == 0) return EQUAL;
	if(strcmp(yytext,"!=") == 0) return NEQUAL;
	if(strcmp(yytext,"&&") == 0) return LogAND;
	if(strcmp(yytext,"||") == 0) return LogOR;
	if(strcmp(yytext,"...") == 0) return ELIP;
	if(strcmp(yytext,"*=") == 0) return AssSTAR;
	if(strcmp(yytext,"/=") == 0) return AssDIV;
	if(strcmp(yytext,"%=") == 0) return AssMOD;
	if(strcmp(yytext,"+=") == 0) return AssPLUS;
	if(strcmp(yytext,"-=") == 0) return AssMINUS;
	if(strcmp(yytext,"<<=") == 0) return AssSHL;
	if(strcmp(yytext,">>=") == 0) return AssSHR;
	if(strcmp(yytext,"&=") == 0) return AssBinAND;
	if(strcmp(yytext,"^=") == 0) return AssXOR;
	if(strcmp(yytext,"|=") == 0) return AssBinOR;

	return yytext[0];
}

.				{
	return yytext[0];
}
%%