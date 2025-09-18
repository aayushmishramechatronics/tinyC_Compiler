/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "compiler_rules_actions.y"


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

#line 115 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    AUTO = 258,                    /* AUTO  */
    BREAK = 259,                   /* BREAK  */
    CASE = 260,                    /* CASE  */
    CHAR = 261,                    /* CHAR  */
    CONST = 262,                   /* CONST  */
    CONTINUE = 263,                /* CONTINUE  */
    DEFAULT = 264,                 /* DEFAULT  */
    DO = 265,                      /* DO  */
    DOUBLE = 266,                  /* DOUBLE  */
    ELSE = 267,                    /* ELSE  */
    ENUM = 268,                    /* ENUM  */
    EXTERN = 269,                  /* EXTERN  */
    FLOAT = 270,                   /* FLOAT  */
    FOR = 271,                     /* FOR  */
    GOTO = 272,                    /* GOTO  */
    IF = 273,                      /* IF  */
    INLINE = 274,                  /* INLINE  */
    INT = 275,                     /* INT  */
    LONG = 276,                    /* LONG  */
    REGISTER = 277,                /* REGISTER  */
    RESTRICT = 278,                /* RESTRICT  */
    RETURN = 279,                  /* RETURN  */
    SHORT = 280,                   /* SHORT  */
    SIGNED = 281,                  /* SIGNED  */
    SIZEOF = 282,                  /* SIZEOF  */
    STATIC = 283,                  /* STATIC  */
    STRUCT = 284,                  /* STRUCT  */
    SWITCH = 285,                  /* SWITCH  */
    TYPEDEF = 286,                 /* TYPEDEF  */
    UNION = 287,                   /* UNION  */
    UNSIGNED = 288,                /* UNSIGNED  */
    VOID = 289,                    /* VOID  */
    VOLATILE = 290,                /* VOLATILE  */
    WHILE = 291,                   /* WHILE  */
    BOOL = 292,                    /* BOOL  */
    COMPLEX = 293,                 /* COMPLEX  */
    IMAGINARY = 294,               /* IMAGINARY  */
    ACC = 295,                     /* ACC  */
    INC = 296,                     /* INC  */
    DEC = 297,                     /* DEC  */
    SHL = 298,                     /* SHL  */
    SHR = 299,                     /* SHR  */
    LTE = 300,                     /* LTE  */
    GTE = 301,                     /* GTE  */
    EQUAL = 302,                   /* EQUAL  */
    NEQUAL = 303,                  /* NEQUAL  */
    LogAND = 304,                  /* LogAND  */
    LogOR = 305,                   /* LogOR  */
    ELIP = 306,                    /* ELIP  */
    AssSTAR = 307,                 /* AssSTAR  */
    AssDIV = 308,                  /* AssDIV  */
    AssMOD = 309,                  /* AssMOD  */
    AssPLUS = 310,                 /* AssPLUS  */
    AssMINUS = 311,                /* AssMINUS  */
    AssSHL = 312,                  /* AssSHL  */
    AssSHR = 313,                  /* AssSHR  */
    AssBinAND = 314,               /* AssBinAND  */
    AssXOR = 315,                  /* AssXOR  */
    AssBinOR = 316,                /* AssBinOR  */
    IDENTIFIER = 317,              /* IDENTIFIER  */
    CONSTANT = 318,                /* CONSTANT  */
    STRING_LITERAL = 319,          /* STRING_LITERAL  */
    IFX = 320                      /* IFX  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define AUTO 258
#define BREAK 259
#define CASE 260
#define CHAR 261
#define CONST 262
#define CONTINUE 263
#define DEFAULT 264
#define DO 265
#define DOUBLE 266
#define ELSE 267
#define ENUM 268
#define EXTERN 269
#define FLOAT 270
#define FOR 271
#define GOTO 272
#define IF 273
#define INLINE 274
#define INT 275
#define LONG 276
#define REGISTER 277
#define RESTRICT 278
#define RETURN 279
#define SHORT 280
#define SIGNED 281
#define SIZEOF 282
#define STATIC 283
#define STRUCT 284
#define SWITCH 285
#define TYPEDEF 286
#define UNION 287
#define UNSIGNED 288
#define VOID 289
#define VOLATILE 290
#define WHILE 291
#define BOOL 292
#define COMPLEX 293
#define IMAGINARY 294
#define ACC 295
#define INC 296
#define DEC 297
#define SHL 298
#define SHR 299
#define LTE 300
#define GTE 301
#define EQUAL 302
#define NEQUAL 303
#define LogAND 304
#define LogOR 305
#define ELIP 306
#define AssSTAR 307
#define AssDIV 308
#define AssMOD 309
#define AssPLUS 310
#define AssMINUS 311
#define AssSHL 312
#define AssSHR 313
#define AssBinAND 314
#define AssXOR 315
#define AssBinOR 316
#define IDENTIFIER 317
#define CONSTANT 318
#define STRING_LITERAL 319
#define IFX 320

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 46 "compiler_rules_actions.y"

	class symbol* sym;
	class ArgList* al;
	class nextlist* nl;
	int add;
	char null;

#line 306 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_AUTO = 3,                       /* AUTO  */
  YYSYMBOL_BREAK = 4,                      /* BREAK  */
  YYSYMBOL_CASE = 5,                       /* CASE  */
  YYSYMBOL_CHAR = 6,                       /* CHAR  */
  YYSYMBOL_CONST = 7,                      /* CONST  */
  YYSYMBOL_CONTINUE = 8,                   /* CONTINUE  */
  YYSYMBOL_DEFAULT = 9,                    /* DEFAULT  */
  YYSYMBOL_DO = 10,                        /* DO  */
  YYSYMBOL_DOUBLE = 11,                    /* DOUBLE  */
  YYSYMBOL_ELSE = 12,                      /* ELSE  */
  YYSYMBOL_ENUM = 13,                      /* ENUM  */
  YYSYMBOL_EXTERN = 14,                    /* EXTERN  */
  YYSYMBOL_FLOAT = 15,                     /* FLOAT  */
  YYSYMBOL_FOR = 16,                       /* FOR  */
  YYSYMBOL_GOTO = 17,                      /* GOTO  */
  YYSYMBOL_IF = 18,                        /* IF  */
  YYSYMBOL_INLINE = 19,                    /* INLINE  */
  YYSYMBOL_INT = 20,                       /* INT  */
  YYSYMBOL_LONG = 21,                      /* LONG  */
  YYSYMBOL_REGISTER = 22,                  /* REGISTER  */
  YYSYMBOL_RESTRICT = 23,                  /* RESTRICT  */
  YYSYMBOL_RETURN = 24,                    /* RETURN  */
  YYSYMBOL_SHORT = 25,                     /* SHORT  */
  YYSYMBOL_SIGNED = 26,                    /* SIGNED  */
  YYSYMBOL_SIZEOF = 27,                    /* SIZEOF  */
  YYSYMBOL_STATIC = 28,                    /* STATIC  */
  YYSYMBOL_STRUCT = 29,                    /* STRUCT  */
  YYSYMBOL_SWITCH = 30,                    /* SWITCH  */
  YYSYMBOL_TYPEDEF = 31,                   /* TYPEDEF  */
  YYSYMBOL_UNION = 32,                     /* UNION  */
  YYSYMBOL_UNSIGNED = 33,                  /* UNSIGNED  */
  YYSYMBOL_VOID = 34,                      /* VOID  */
  YYSYMBOL_VOLATILE = 35,                  /* VOLATILE  */
  YYSYMBOL_WHILE = 36,                     /* WHILE  */
  YYSYMBOL_BOOL = 37,                      /* BOOL  */
  YYSYMBOL_COMPLEX = 38,                   /* COMPLEX  */
  YYSYMBOL_IMAGINARY = 39,                 /* IMAGINARY  */
  YYSYMBOL_ACC = 40,                       /* ACC  */
  YYSYMBOL_INC = 41,                       /* INC  */
  YYSYMBOL_DEC = 42,                       /* DEC  */
  YYSYMBOL_SHL = 43,                       /* SHL  */
  YYSYMBOL_SHR = 44,                       /* SHR  */
  YYSYMBOL_LTE = 45,                       /* LTE  */
  YYSYMBOL_GTE = 46,                       /* GTE  */
  YYSYMBOL_EQUAL = 47,                     /* EQUAL  */
  YYSYMBOL_NEQUAL = 48,                    /* NEQUAL  */
  YYSYMBOL_LogAND = 49,                    /* LogAND  */
  YYSYMBOL_LogOR = 50,                     /* LogOR  */
  YYSYMBOL_ELIP = 51,                      /* ELIP  */
  YYSYMBOL_AssSTAR = 52,                   /* AssSTAR  */
  YYSYMBOL_AssDIV = 53,                    /* AssDIV  */
  YYSYMBOL_AssMOD = 54,                    /* AssMOD  */
  YYSYMBOL_AssPLUS = 55,                   /* AssPLUS  */
  YYSYMBOL_AssMINUS = 56,                  /* AssMINUS  */
  YYSYMBOL_AssSHL = 57,                    /* AssSHL  */
  YYSYMBOL_AssSHR = 58,                    /* AssSHR  */
  YYSYMBOL_AssBinAND = 59,                 /* AssBinAND  */
  YYSYMBOL_AssXOR = 60,                    /* AssXOR  */
  YYSYMBOL_AssBinOR = 61,                  /* AssBinOR  */
  YYSYMBOL_IDENTIFIER = 62,                /* IDENTIFIER  */
  YYSYMBOL_CONSTANT = 63,                  /* CONSTANT  */
  YYSYMBOL_STRING_LITERAL = 64,            /* STRING_LITERAL  */
  YYSYMBOL_IFX = 65,                       /* IFX  */
  YYSYMBOL_66_ = 66,                       /* ';'  */
  YYSYMBOL_67_ = 67,                       /* ','  */
  YYSYMBOL_68_ = 68,                       /* '='  */
  YYSYMBOL_69_ = 69,                       /* '{'  */
  YYSYMBOL_70_ = 70,                       /* '}'  */
  YYSYMBOL_71_ = 71,                       /* '('  */
  YYSYMBOL_72_ = 72,                       /* ')'  */
  YYSYMBOL_73_ = 73,                       /* '['  */
  YYSYMBOL_74_ = 74,                       /* ']'  */
  YYSYMBOL_75_ = 75,                       /* '*'  */
  YYSYMBOL_76_ = 76,                       /* '.'  */
  YYSYMBOL_77_ = 77,                       /* ':'  */
  YYSYMBOL_78_ = 78,                       /* '&'  */
  YYSYMBOL_79_ = 79,                       /* '+'  */
  YYSYMBOL_80_ = 80,                       /* '-'  */
  YYSYMBOL_81_ = 81,                       /* '~'  */
  YYSYMBOL_82_ = 82,                       /* '!'  */
  YYSYMBOL_83_ = 83,                       /* '/'  */
  YYSYMBOL_84_ = 84,                       /* '%'  */
  YYSYMBOL_85_ = 85,                       /* '<'  */
  YYSYMBOL_86_ = 86,                       /* '>'  */
  YYSYMBOL_87_ = 87,                       /* '^'  */
  YYSYMBOL_88_ = 88,                       /* '|'  */
  YYSYMBOL_89_ = 89,                       /* '?'  */
  YYSYMBOL_YYACCEPT = 90,                  /* $accept  */
  YYSYMBOL_translation_unit = 91,          /* translation_unit  */
  YYSYMBOL_external_declaration = 92,      /* external_declaration  */
  YYSYMBOL_function_definition = 93,       /* function_definition  */
  YYSYMBOL_declaration_list = 94,          /* declaration_list  */
  YYSYMBOL_declaration = 95,               /* declaration  */
  YYSYMBOL_declaration_specifiers = 96,    /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 97,      /* init_declarator_list  */
  YYSYMBOL_init_declarator = 98,           /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 99,   /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 100,           /* type_specifier  */
  YYSYMBOL_specifier_qualifier_list = 101, /* specifier_qualifier_list  */
  YYSYMBOL_enum_specifier = 102,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 103,          /* enumerator_list  */
  YYSYMBOL_enumerator = 104,               /* enumerator  */
  YYSYMBOL_enumeration_constant = 105,     /* enumeration_constant  */
  YYSYMBOL_type_qualifier = 106,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 107,       /* function_specifier  */
  YYSYMBOL_declarator = 108,               /* declarator  */
  YYSYMBOL_direct_declarator = 109,        /* direct_declarator  */
  YYSYMBOL_push_sym = 110,                 /* push_sym  */
  YYSYMBOL_pointer = 111,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 112,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 113,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 114,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 115,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 116,          /* identifier_list  */
  YYSYMBOL_type_name = 117,                /* type_name  */
  YYSYMBOL_initializer = 118,              /* initializer  */
  YYSYMBOL_initializer_list = 119,         /* initializer_list  */
  YYSYMBOL_designation = 120,              /* designation  */
  YYSYMBOL_designator_list = 121,          /* designator_list  */
  YYSYMBOL_designator = 122,               /* designator  */
  YYSYMBOL_statement = 123,                /* statement  */
  YYSYMBOL_labeled_statement = 124,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 125,       /* compound_statement  */
  YYSYMBOL_block_item_list = 126,          /* block_item_list  */
  YYSYMBOL_block_item = 127,               /* block_item  */
  YYSYMBOL_expression_statement = 128,     /* expression_statement  */
  YYSYMBOL_selection_statement = 129,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 130,      /* iteration_statement  */
  YYSYMBOL_temp = 131,                     /* temp  */
  YYSYMBOL_bool_temp = 132,                /* bool_temp  */
  YYSYMBOL_bool_expression = 133,          /* bool_expression  */
  YYSYMBOL_jump_statement = 134,           /* jump_statement  */
  YYSYMBOL_primary_expression = 135,       /* primary_expression  */
  YYSYMBOL_postfix_expression = 136,       /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 137, /* argument_expression_list  */
  YYSYMBOL_unary_expression = 138,         /* unary_expression  */
  YYSYMBOL_cast_expression = 139,          /* cast_expression  */
  YYSYMBOL_nb_cast_expression = 140,       /* nb_cast_expression  */
  YYSYMBOL_multiplicative_expression = 141, /* multiplicative_expression  */
  YYSYMBOL_nb_multiplicative_expression = 142, /* nb_multiplicative_expression  */
  YYSYMBOL_additive_expression = 143,      /* additive_expression  */
  YYSYMBOL_nb_additive_expression = 144,   /* nb_additive_expression  */
  YYSYMBOL_shift_expression = 145,         /* shift_expression  */
  YYSYMBOL_nb_shift_expression = 146,      /* nb_shift_expression  */
  YYSYMBOL_relational_expression = 147,    /* relational_expression  */
  YYSYMBOL_nb_relational_expression = 148, /* nb_relational_expression  */
  YYSYMBOL_equality_expression = 149,      /* equality_expression  */
  YYSYMBOL_nb_equality_expression = 150,   /* nb_equality_expression  */
  YYSYMBOL_and_expression = 151,           /* and_expression  */
  YYSYMBOL_nb_and_expression = 152,        /* nb_and_expression  */
  YYSYMBOL_exclusive_or_expression = 153,  /* exclusive_or_expression  */
  YYSYMBOL_nb_exclusive_or_expression = 154, /* nb_exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 155,  /* inclusive_or_expression  */
  YYSYMBOL_nb_inclusive_or_expression = 156, /* nb_inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 157,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 158,    /* logical_or_expression  */
  YYSYMBOL_bool_inclusive_or_expression = 159, /* bool_inclusive_or_expression  */
  YYSYMBOL_bool_logical_or_expression = 160, /* bool_logical_or_expression  */
  YYSYMBOL_bool_logical_and_expression = 161, /* bool_logical_and_expression  */
  YYSYMBOL_conditional_expression = 162,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 163,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 164,      /* assignment_operator  */
  YYSYMBOL_expression = 165,               /* expression  */
  YYSYMBOL_constant_expression = 166,      /* constant_expression  */
  YYSYMBOL_address_nonterm = 167,          /* address_nonterm  */
  YYSYMBOL_jump_nonterm = 168              /* jump_nonterm  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  34
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1391

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  90
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  79
/* YYNRULES -- Number of rules.  */
#define YYNRULES  224
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  395

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   320


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    82,     2,     2,     2,    84,    78,     2,
      71,    72,    75,    79,    67,    80,    76,    83,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    77,    66,
      85,    68,    86,    89,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    73,     2,    74,    87,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    69,    88,    70,    81,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   205,   205,   206,   209,   210,   213,   226,   241,   242,
     255,   260,   263,   264,   265,   266,   267,   268,   269,   270,
     273,   274,   277,   283,   296,   297,   298,   299,   302,   307,
     312,   313,   318,   319,   320,   325,   326,   327,   328,   329,
     330,   333,   334,   335,   336,   339,   340,   341,   342,   343,
     346,   347,   350,   351,   354,   357,   358,   359,   362,   365,
     369,   372,   383,   384,   385,   386,   397,   404,   405,   406,
     407,   408,   409,   418,   422,   429,   441,   442,   447,   448,
     455,   456,   459,   460,   463,   464,   467,   473,   476,   477,
     480,   483,   484,   485,   488,   489,   490,   491,   494,   497,
     498,   501,   502,   515,   516,   517,   518,   519,   520,   523,
     524,   525,   528,   532,   538,   539,   548,   552,   555,   565,
     571,   579,   591,   594,   603,   610,   620,   623,   625,   630,
     631,   634,   646,   647,   648,   649,   677,   689,   690,   691,
     697,   698,   717,   725,   726,   727,   728,   758,   789,   790,
     793,   800,   809,   810,   837,   861,   878,   890,   895,   901,
     902,   907,   908,   911,   921,   937,   949,   950,   956,   962,
     971,   984,   985,   991,   999,  1012,  1013,  1020,  1029,  1042,
    1043,  1054,  1065,  1076,  1089,  1102,  1103,  1114,  1127,  1139,
    1140,  1154,  1167,  1168,  1182,  1195,  1196,  1210,  1223,  1224,
    1240,  1241,  1257,  1272,  1287,  1303,  1304,  1323,  1324,  1337,
    1338,  1339,  1340,  1341,  1342,  1343,  1344,  1345,  1346,  1347,
    1350,  1351,  1354,  1362,  1368
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "AUTO", "BREAK",
  "CASE", "CHAR", "CONST", "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE",
  "ENUM", "EXTERN", "FLOAT", "FOR", "GOTO", "IF", "INLINE", "INT", "LONG",
  "REGISTER", "RESTRICT", "RETURN", "SHORT", "SIGNED", "SIZEOF", "STATIC",
  "STRUCT", "SWITCH", "TYPEDEF", "UNION", "UNSIGNED", "VOID", "VOLATILE",
  "WHILE", "BOOL", "COMPLEX", "IMAGINARY", "ACC", "INC", "DEC", "SHL",
  "SHR", "LTE", "GTE", "EQUAL", "NEQUAL", "LogAND", "LogOR", "ELIP",
  "AssSTAR", "AssDIV", "AssMOD", "AssPLUS", "AssMINUS", "AssSHL", "AssSHR",
  "AssBinAND", "AssXOR", "AssBinOR", "IDENTIFIER", "CONSTANT",
  "STRING_LITERAL", "IFX", "';'", "','", "'='", "'{'", "'}'", "'('", "')'",
  "'['", "']'", "'*'", "'.'", "':'", "'&'", "'+'", "'-'", "'~'", "'!'",
  "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "$accept",
  "translation_unit", "external_declaration", "function_definition",
  "declaration_list", "declaration", "declaration_specifiers",
  "init_declarator_list", "init_declarator", "storage_class_specifier",
  "type_specifier", "specifier_qualifier_list", "enum_specifier",
  "enumerator_list", "enumerator", "enumeration_constant",
  "type_qualifier", "function_specifier", "declarator",
  "direct_declarator", "push_sym", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "type_name", "initializer", "initializer_list",
  "designation", "designator_list", "designator", "statement",
  "labeled_statement", "compound_statement", "block_item_list",
  "block_item", "expression_statement", "selection_statement",
  "iteration_statement", "temp", "bool_temp", "bool_expression",
  "jump_statement", "primary_expression", "postfix_expression",
  "argument_expression_list", "unary_expression", "cast_expression",
  "nb_cast_expression", "multiplicative_expression",
  "nb_multiplicative_expression", "additive_expression",
  "nb_additive_expression", "shift_expression", "nb_shift_expression",
  "relational_expression", "nb_relational_expression",
  "equality_expression", "nb_equality_expression", "and_expression",
  "nb_and_expression", "exclusive_or_expression",
  "nb_exclusive_or_expression", "inclusive_or_expression",
  "nb_inclusive_or_expression", "logical_and_expression",
  "logical_or_expression", "bool_inclusive_or_expression",
  "bool_logical_or_expression", "bool_logical_and_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "address_nonterm", "jump_nonterm", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-282)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-205)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1318,  -282,  -282,  -282,  -282,   -45,  -282,  -282,  -282,  -282,
    -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,
    -282,  -282,  1281,  -282,  -282,  -282,    47,  1318,  1318,  -282,
    1318,  1318,   -56,   -43,  -282,  -282,  -282,  -282,    59,    30,
     -18,  -282,   874,    26,   -48,  -282,  -282,  -282,  -282,   -43,
    -282,    20,  -282,   -10,   -33,  -282,  -282,    30,  -282,    59,
     987,   324,   911,  -282,    47,  -282,   664,     4,    26,    62,
      80,  -282,  1111,  -282,  -282,  -282,  -282,    36,  1135,  1160,
    1160,  -282,  -282,  -282,   963,   640,  1111,  1160,  1111,  1111,
    1111,  1111,  -282,  -282,   191,   236,  -282,   -11,    53,   136,
     141,   144,   181,    22,    40,   193,   195,    38,    60,    84,
     110,    66,   115,    98,   -42,   -38,   160,  -282,  -282,   148,
    1111,   162,   157,  -282,   192,   188,   197,  1111,   215,   216,
     175,  -282,  -282,  -282,  -282,  -282,  -282,   196,  -282,  -282,
    -282,  -282,  -282,  -282,   179,  -282,  -282,   749,  -282,  1013,
     689,   227,   829,    83,  -282,  -282,  -282,  -282,  -282,  -282,
     640,  -282,   640,  -282,  -282,  1111,   244,  -282,    81,   987,
      67,  -282,  1352,  -282,  1352,   235,    11,  -282,  -282,  -282,
    -282,  -282,  -282,   246,  -282,  -282,  1037,  1111,   247,  -282,
    -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,
    1111,  1111,  1111,  1111,  1111,  1111,  1111,  1111,  1111,  1111,
    1111,  1111,  1111,  1111,  1111,  1111,  1111,  -282,  -282,  -282,
    -282,   233,  -282,   563,   563,   484,   245,  1111,   248,   249,
    1111,  -282,   563,  -282,   404,  -282,  1111,   749,   238,  -282,
    1111,  -282,  1062,   239,  -282,  -282,  -282,    59,   243,   250,
    -282,   108,  -282,   251,   252,   262,  -282,   913,  -282,  -282,
    -282,  -282,  -282,  -282,  1086,  -282,  -282,  -282,   117,  -282,
       2,  -282,  -282,  -282,  -282,  -282,  -282,  -282,    53,    53,
    -282,   141,   141,  -282,   181,   181,   181,   181,  -282,    40,
      40,  -282,   195,  -282,    60,  -282,   110,  1111,  1111,  1111,
     563,  -282,  -282,   253,   254,  -282,   281,   249,  -282,   119,
    1111,  -282,  -282,  -282,   282,  -282,   290,  -282,  -282,  -282,
    -282,  1240,   256,  -282,   286,   286,  -282,  -282,  -282,   987,
     963,  -282,  1111,  -282,  -282,  -282,   160,   249,    66,  -282,
    -282,   289,  1111,  -282,  -282,   563,   295,  -282,  -282,  -282,
    -282,  -282,  -282,   135,  -282,   291,   298,   304,  1111,   563,
    -282,  -282,   937,  -282,  -282,  1111,  1111,   305,  -282,  -282,
     563,  -282,  1111,   300,   301,  -282,   310,  -282,  -282,   308,
     563,  1111,  -282,  -282,  -282,  -282,  -282,  -282,   563,   303,
    -282,  -282,   563,  -282,  -282
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    26,    29,    55,    34,     0,    24,    33,    58,    31,
      32,    27,    56,    30,    35,    25,    36,    28,    57,    37,
      38,    39,     0,     2,     4,     5,     0,    13,    15,    40,
      17,    19,    49,     0,     1,     3,    61,    11,     0,    77,
       0,    20,    22,    60,     0,    12,    14,    16,    18,     0,
      54,     0,    50,    52,     0,    80,    79,    76,    10,     0,
       0,     0,     0,     8,     0,     7,     0,     0,    59,     0,
       0,    46,     0,    62,    81,    78,    21,    22,     0,     0,
       0,   136,   137,   138,     0,     0,     0,     0,     0,     0,
       0,     0,    23,   140,   152,   163,   166,   171,     0,   175,
       0,   179,     0,   185,     0,   189,     0,   192,     0,   195,
       0,   198,     0,   200,   205,     0,     0,   207,    91,     0,
       0,     0,     0,   223,     0,     0,     0,   128,     0,     0,
     136,   119,   113,   116,   117,   103,   104,   223,   114,   105,
     106,   107,   108,   220,     0,     9,     6,     0,    66,     0,
       0,     0,     0,     0,    45,    48,    51,   163,   222,    53,
       0,   161,     0,   153,   154,     0,     0,    95,     0,     0,
       0,    99,    42,    90,    44,     0,     0,   156,   155,   157,
     158,   159,   160,     0,   146,   147,     0,     0,     0,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   209,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   223,   223,   223,
     134,     0,   133,     0,     0,   128,     0,     0,     0,   127,
       0,   223,     0,   112,     0,   118,     0,     0,     0,    71,
       0,    64,     0,     0,    65,    88,    74,    87,     0,    82,
      84,     0,    47,     0,     0,     0,   102,     0,    92,    94,
      98,   100,    41,    43,     0,   139,   145,   143,     0,   150,
       0,   144,   208,   165,   167,   168,   169,   170,   172,   173,
     174,   176,   177,   178,   182,   183,   180,   181,   184,   186,
     187,   188,   190,   191,   193,   194,   196,     0,     0,     0,
       0,   111,   223,     0,     0,   132,     0,   131,   135,     0,
       0,   109,   115,   221,     0,    68,     0,    70,    63,    86,
      72,     0,     0,    73,   162,     0,   101,    93,    97,     0,
       0,   164,     0,   142,   141,   204,   201,   224,   202,   199,
     110,     0,   128,   223,   223,     0,     0,    67,    69,    83,
      85,    89,    96,     0,   151,     0,     0,     0,   130,     0,
     122,   223,     0,   148,   223,     0,   128,     0,   129,   224,
       0,   149,     0,     0,     0,   223,   121,   224,   224,     0,
       0,   128,   223,   123,   206,   124,   126,   224,     0,     0,
     120,   223,     0,   224,   125
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -282,  -282,   354,  -282,  -282,   -26,     0,  -282,   318,  -282,
     -80,    21,  -282,   329,   -60,  -282,    32,  -282,   -17,   335,
    -282,    13,   -51,  -282,  -282,    61,  -282,    50,   -57,    51,
    -251,  -282,   210,  -169,  -282,   -24,  -282,   149,  -282,  -282,
    -282,  -159,  -282,  -281,  -282,  -282,  -282,  -282,   -46,   -29,
      57,    44,    71,    72,    74,    28,    46,    70,    86,   170,
     171,   174,   176,   180,   182,    93,  -282,   100,  -282,  -282,
    -282,   103,   -70,   -59,  -282,   -81,  -109,  -117,  -254
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    22,    23,    24,    62,    25,    64,    40,    41,    27,
      28,   173,    29,    51,    52,    53,    30,    31,    77,    43,
      67,    44,    57,   248,   249,   250,   251,   175,   167,   168,
     169,   170,   171,   134,   135,   136,   137,   138,   139,   140,
     141,   228,   367,   306,   142,    93,    94,   268,    95,    96,
     274,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   339,
     115,   116,   117,   143,   200,   144,   159,   224,   355
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      26,   118,   158,    92,   176,   172,   329,   151,  -203,    42,
     156,   221,   217,    49,    36,   150,    63,    32,    65,    50,
     234,    54,    26,    38,    33,   118,   157,    45,    46,   346,
      47,    48,   161,   163,   164,   133,   145,     3,   146,    73,
     157,   178,   157,   157,   157,   157,   229,  -203,    58,    59,
     158,   218,    56,    12,   301,   302,   255,   177,    72,   179,
     180,   181,   182,   311,  -170,    18,   304,  -184,  -184,   236,
      75,    55,  -170,  -170,   157,   152,   334,   368,   236,   176,
     172,   176,   172,   265,   373,   208,   209,    70,   238,    74,
      71,   243,   172,   156,   172,   158,   237,   -75,    55,    66,
     297,   298,   299,   157,    60,    39,   270,  -184,  -184,    36,
     118,   329,   259,    37,   310,   376,  -191,   174,    38,   157,
     177,    36,    39,   383,   384,   210,   211,   269,   201,   153,
      38,   340,   154,   389,    39,   260,   202,   203,   214,   394,
     165,   272,    50,   166,   229,    50,   307,  -204,   257,   309,
     155,   258,   247,   252,  -197,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,  -194,   273,   273,   273,   322,   360,   313,   314,    55,
     323,   316,    74,   357,   332,   341,   236,  -178,  -178,   333,
     369,   345,   174,   262,   174,   263,   157,   215,   118,   303,
     328,   377,   362,   216,   174,   363,   174,   374,   133,   219,
     253,   386,   254,   177,   220,  -174,  -174,   337,   157,   390,
     204,   205,   387,   393,   206,   207,   358,   359,   222,   307,
     319,   183,   184,   185,   223,   331,   283,   283,   283,   283,
    -188,  -188,   212,   213,   370,   235,   236,   372,   277,   277,
     226,   157,   232,   157,   284,   285,   286,   287,   381,   275,
     276,   229,   186,   225,   187,   388,   233,   188,   227,    74,
     118,   118,   352,   354,   392,   278,   279,   307,   280,   280,
     281,   282,   288,   288,   307,   229,   230,   231,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   289,   290,
     229,   244,   378,   118,   199,   328,   256,   264,   266,   271,
     300,   305,   315,   318,   308,   320,   236,   321,   351,   342,
     343,   247,   382,   324,   325,   356,   157,     1,   119,   120,
       2,     3,   121,   122,   123,     4,   326,     5,     6,     7,
     124,   125,   126,     8,     9,    10,    11,    12,   127,    13,
      14,    78,    15,   344,   128,   330,   347,    16,    17,    18,
     129,    19,    20,    21,   348,    79,    80,   361,   364,   365,
     366,   375,   379,   380,   385,   391,    35,    76,    69,    68,
     261,   353,   350,   312,   291,   292,   130,    82,    83,   293,
     131,   294,   338,    61,   132,    85,   295,   335,   296,    86,
     336,     0,    87,    88,    89,    90,    91,     1,   119,   120,
       2,     3,   121,   122,   123,     4,     0,     5,     6,     7,
     124,   125,   126,     8,     9,    10,    11,    12,   127,    13,
      14,    78,    15,     0,   128,     0,     0,    16,    17,    18,
     129,    19,    20,    21,     0,    79,    80,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   130,    82,    83,     0,
     131,     0,     0,    61,     0,    85,     0,     0,     0,    86,
       0,     0,    87,    88,    89,    90,    91,     1,     0,     0,
       2,     3,     0,     0,     0,     4,     0,     5,     6,     7,
       0,     0,     0,     8,     9,    10,    11,    12,     0,    13,
      14,    78,    15,     0,     0,     0,     0,    16,    17,    18,
       0,    19,    20,    21,     0,    79,    80,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    81,    82,    83,     0,
       0,     0,     0,     0,     0,    85,     0,     0,     0,    86,
       0,     0,    87,    88,    89,    90,    91,   119,   120,     0,
       0,   121,   122,   123,     0,     0,     0,     0,     0,   124,
     125,   126,     0,     0,     0,     0,     0,   127,     0,     0,
      78,     0,     0,   128,     0,     0,     0,     0,     0,   129,
       0,     0,     0,     0,    79,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   130,    82,    83,     0,   131,
       0,     0,    61,     0,    85,     0,     0,     0,    86,     0,
       0,    87,    88,    89,    90,    91,     2,     3,     0,     0,
       0,     4,     0,     5,     0,     7,     0,     0,     0,     0,
       9,    10,     0,    12,     0,    13,    14,    78,     0,     0,
       0,     3,     0,    16,    17,    18,     0,    19,    20,    21,
       0,    79,    80,     0,     0,     0,     0,    12,     0,     0,
       0,    78,   147,     0,     0,     0,     3,     0,     0,    18,
       0,     0,    81,    82,    83,    79,    80,     0,     0,     0,
       0,    85,    12,     0,     0,    86,    78,   240,    87,    88,
      89,    90,    91,     0,    18,     0,    81,    82,    83,     0,
      79,    80,     0,     0,     0,    85,     0,     0,   148,   149,
       0,     0,    87,    88,    89,    90,    91,     0,     0,     0,
       0,    81,    82,    83,     0,     0,     3,     0,     0,     0,
      85,     0,     0,   241,   242,     0,     0,    87,    88,    89,
      90,    91,    12,     0,     0,     0,    78,     0,     0,     0,
       0,     0,     0,     0,    18,     0,     0,     0,     0,     0,
      79,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    81,    82,    83,     0,     0,     0,     0,     0,     0,
      85,     0,     0,     0,    86,     0,     0,    87,    88,    89,
      90,    91,     1,     0,     0,     2,     3,     0,     0,     0,
       4,     0,     5,     6,     7,     0,     0,     0,     8,     9,
      10,    11,    12,     0,    13,    14,     0,    15,     0,     0,
       0,     0,    16,    17,    18,     0,    19,    20,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,     0,
       2,     3,     0,     0,     0,     4,     0,     5,     6,     7,
       0,   245,     0,     8,     9,    10,    11,    12,     0,    13,
      14,   246,    15,     0,     0,     0,     0,    16,    17,    18,
       0,    19,    20,    21,     1,     0,     0,     2,     3,     0,
       0,     0,     4,     0,     5,     6,     7,     0,     0,     0,
       8,     9,    10,    11,    12,     0,    13,    14,     0,    15,
      78,     0,    60,    61,    16,    17,    18,     0,    19,    20,
      21,     0,     0,     0,    79,    80,     0,     0,     0,     0,
       0,     0,     0,     0,    78,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    81,    82,    83,    79,    80,
      61,     0,    84,   327,    85,     0,   165,     0,    86,   166,
      78,    87,    88,    89,    90,    91,     0,     0,     0,    81,
      82,    83,     0,     0,    79,    80,    84,   371,    85,     0,
     165,     0,    86,   166,    78,    87,    88,    89,    90,    91,
       0,     0,     0,     0,     0,    81,    82,    83,    79,    80,
       0,     0,    84,     0,    85,     0,   165,     0,    86,   166,
      78,    87,    88,    89,    90,    91,     0,     0,     0,    81,
      82,    83,     0,     0,    79,    80,    84,     0,    85,     0,
       0,     0,    86,     0,    78,    87,    88,    89,    90,    91,
       0,     0,     0,     0,     0,    81,    82,    83,    79,    80,
       0,     0,     0,     0,    85,     0,     0,   239,    86,    78,
       0,    87,    88,    89,    90,    91,     0,     0,     0,    81,
      82,    83,     0,    79,    80,     0,     0,     0,    85,   267,
       0,     0,    86,    78,     0,    87,    88,    89,    90,    91,
       0,     0,     0,     0,    81,    82,    83,    79,    80,     0,
       0,     0,     0,    85,     0,     0,   317,    86,    78,     0,
      87,    88,    89,    90,    91,     0,     0,     0,    81,    82,
      83,     0,    79,    80,     0,   330,     0,    85,     0,     0,
       0,    86,    78,     0,    87,    88,    89,    90,    91,     0,
       0,     0,     0,    81,    82,    83,    79,    80,     0,     0,
       0,     0,    85,     0,     0,     0,    86,    78,     0,    87,
      88,    89,    90,    91,     0,     0,     0,    81,    82,    83,
       0,    79,    80,     0,     0,     0,   160,     0,     0,     0,
      86,     0,     0,    87,    88,    89,    90,    91,     0,     0,
       0,     0,    81,    82,    83,     0,     0,     0,     0,     0,
       0,   162,     0,     0,     0,    86,     0,     0,    87,    88,
      89,    90,    91,     1,     0,     0,     2,     3,     0,     0,
       0,     4,     0,     5,     6,     7,     0,     0,     0,     8,
       9,    10,    11,    12,     0,    13,    14,     0,    15,     0,
       0,     0,     0,    16,    17,    18,     0,    19,    20,    21,
       0,    34,     0,     0,     1,     0,     0,     2,     3,     0,
       0,   349,     4,     0,     5,     6,     7,     0,     0,     0,
       8,     9,    10,    11,    12,     0,    13,    14,     0,    15,
       0,     0,     0,     0,    16,    17,    18,     0,    19,    20,
      21,     1,     0,     0,     2,     3,     0,     0,     0,     4,
       0,     5,     6,     7,     0,     0,     0,     8,     9,    10,
      11,    12,     0,    13,    14,     0,    15,     0,     0,     0,
       0,    16,    17,    18,     0,    19,    20,    21,     2,     3,
       0,     0,     0,     4,     0,     5,     0,     7,     0,     0,
       0,     0,     9,    10,     0,    12,     0,    13,    14,     0,
       0,     0,     0,     0,     0,    16,    17,    18,     0,    19,
      20,    21
};

static const yytype_int16 yycheck[] =
{
       0,    60,    72,    60,    85,    85,   257,    66,    50,    26,
      70,   120,    50,    69,    62,    66,    42,    62,    42,    62,
     137,    38,    22,    71,    69,    84,    72,    27,    28,   310,
      30,    31,    78,    79,    80,    61,    62,     7,    62,    72,
      86,    87,    88,    89,    90,    91,   127,    89,    66,    67,
     120,    89,    39,    23,   223,   224,   165,    86,    68,    88,
      89,    90,    91,   232,    75,    35,   225,    45,    46,    67,
      57,    39,    83,    84,   120,    71,    74,   358,    67,   160,
     160,   162,   162,    72,   365,    45,    46,    67,   147,    57,
      70,   150,   172,   153,   174,   165,   147,    71,    66,    73,
     217,   218,   219,   149,    68,    75,   187,    85,    86,    62,
     169,   362,   169,    66,   231,   369,    78,    85,    71,   165,
     149,    62,    75,   377,   378,    85,    86,   186,    75,    67,
      71,   300,    70,   387,    75,    68,    83,    84,    78,   393,
      73,   200,    62,    76,   225,    62,   227,    49,    67,   230,
      70,    70,   152,    70,    88,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,    87,   201,   202,   203,    67,   345,   236,   237,   147,
      72,   240,   150,   342,    67,   302,    67,    43,    44,    72,
     359,    72,   160,   172,   162,   174,   242,    87,   257,   225,
     257,   370,    67,    88,   172,    70,   174,   366,   234,    49,
     160,   380,   162,   242,    66,    79,    80,   298,   264,   388,
      79,    80,   381,   392,    43,    44,   343,   344,    66,   310,
     247,    40,    41,    42,    77,   264,   208,   209,   210,   211,
      47,    48,    47,    48,   361,    66,    67,   364,   204,   205,
      62,   297,    77,   299,   208,   209,   210,   211,   375,   202,
     203,   342,    71,    71,    73,   382,    70,    76,    71,   237,
     329,   330,   329,   332,   391,   204,   205,   358,   206,   207,
     206,   207,   212,   213,   365,   366,    71,    71,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,   212,   213,
     381,    74,   372,   362,    68,   362,    62,    72,    62,    62,
      77,    66,    74,    74,    66,    72,    67,    67,    62,    66,
      66,   321,    12,    72,    72,    36,   372,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    74,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    72,    30,    69,    74,    33,    34,    35,
      36,    37,    38,    39,    74,    41,    42,    72,    77,    71,
      66,    66,    72,    72,    66,    72,    22,    59,    49,    44,
     170,   330,   321,   234,   214,   214,    62,    63,    64,   215,
      66,   215,   299,    69,    70,    71,   216,   297,   216,    75,
     297,    -1,    78,    79,    80,    81,    82,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    30,    -1,    -1,    33,    34,    35,
      36,    37,    38,    39,    -1,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,    -1,
      66,    -1,    -1,    69,    -1,    71,    -1,    -1,    -1,    75,
      -1,    -1,    78,    79,    80,    81,    82,     3,    -1,    -1,
       6,     7,    -1,    -1,    -1,    11,    -1,    13,    14,    15,
      -1,    -1,    -1,    19,    20,    21,    22,    23,    -1,    25,
      26,    27,    28,    -1,    -1,    -1,    -1,    33,    34,    35,
      -1,    37,    38,    39,    -1,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    75,
      -1,    -1,    78,    79,    80,    81,    82,     4,     5,    -1,
      -1,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    16,
      17,    18,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      27,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    64,    -1,    66,
      -1,    -1,    69,    -1,    71,    -1,    -1,    -1,    75,    -1,
      -1,    78,    79,    80,    81,    82,     6,     7,    -1,    -1,
      -1,    11,    -1,    13,    -1,    15,    -1,    -1,    -1,    -1,
      20,    21,    -1,    23,    -1,    25,    26,    27,    -1,    -1,
      -1,     7,    -1,    33,    34,    35,    -1,    37,    38,    39,
      -1,    41,    42,    -1,    -1,    -1,    -1,    23,    -1,    -1,
      -1,    27,    28,    -1,    -1,    -1,     7,    -1,    -1,    35,
      -1,    -1,    62,    63,    64,    41,    42,    -1,    -1,    -1,
      -1,    71,    23,    -1,    -1,    75,    27,    28,    78,    79,
      80,    81,    82,    -1,    35,    -1,    62,    63,    64,    -1,
      41,    42,    -1,    -1,    -1,    71,    -1,    -1,    74,    75,
      -1,    -1,    78,    79,    80,    81,    82,    -1,    -1,    -1,
      -1,    62,    63,    64,    -1,    -1,     7,    -1,    -1,    -1,
      71,    -1,    -1,    74,    75,    -1,    -1,    78,    79,    80,
      81,    82,    23,    -1,    -1,    -1,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    -1,    -1,    75,    -1,    -1,    78,    79,    80,
      81,    82,     3,    -1,    -1,     6,     7,    -1,    -1,    -1,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    -1,    25,    26,    -1,    28,    -1,    -1,
      -1,    -1,    33,    34,    35,    -1,    37,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,
       6,     7,    -1,    -1,    -1,    11,    -1,    13,    14,    15,
      -1,    62,    -1,    19,    20,    21,    22,    23,    -1,    25,
      26,    72,    28,    -1,    -1,    -1,    -1,    33,    34,    35,
      -1,    37,    38,    39,     3,    -1,    -1,     6,     7,    -1,
      -1,    -1,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      19,    20,    21,    22,    23,    -1,    25,    26,    -1,    28,
      27,    -1,    68,    69,    33,    34,    35,    -1,    37,    38,
      39,    -1,    -1,    -1,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    64,    41,    42,
      69,    -1,    69,    70,    71,    -1,    73,    -1,    75,    76,
      27,    78,    79,    80,    81,    82,    -1,    -1,    -1,    62,
      63,    64,    -1,    -1,    41,    42,    69,    70,    71,    -1,
      73,    -1,    75,    76,    27,    78,    79,    80,    81,    82,
      -1,    -1,    -1,    -1,    -1,    62,    63,    64,    41,    42,
      -1,    -1,    69,    -1,    71,    -1,    73,    -1,    75,    76,
      27,    78,    79,    80,    81,    82,    -1,    -1,    -1,    62,
      63,    64,    -1,    -1,    41,    42,    69,    -1,    71,    -1,
      -1,    -1,    75,    -1,    27,    78,    79,    80,    81,    82,
      -1,    -1,    -1,    -1,    -1,    62,    63,    64,    41,    42,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    74,    75,    27,
      -1,    78,    79,    80,    81,    82,    -1,    -1,    -1,    62,
      63,    64,    -1,    41,    42,    -1,    -1,    -1,    71,    72,
      -1,    -1,    75,    27,    -1,    78,    79,    80,    81,    82,
      -1,    -1,    -1,    -1,    62,    63,    64,    41,    42,    -1,
      -1,    -1,    -1,    71,    -1,    -1,    74,    75,    27,    -1,
      78,    79,    80,    81,    82,    -1,    -1,    -1,    62,    63,
      64,    -1,    41,    42,    -1,    69,    -1,    71,    -1,    -1,
      -1,    75,    27,    -1,    78,    79,    80,    81,    82,    -1,
      -1,    -1,    -1,    62,    63,    64,    41,    42,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    -1,    75,    27,    -1,    78,
      79,    80,    81,    82,    -1,    -1,    -1,    62,    63,    64,
      -1,    41,    42,    -1,    -1,    -1,    71,    -1,    -1,    -1,
      75,    -1,    -1,    78,    79,    80,    81,    82,    -1,    -1,
      -1,    -1,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    -1,    -1,    75,    -1,    -1,    78,    79,
      80,    81,    82,     3,    -1,    -1,     6,     7,    -1,    -1,
      -1,    11,    -1,    13,    14,    15,    -1,    -1,    -1,    19,
      20,    21,    22,    23,    -1,    25,    26,    -1,    28,    -1,
      -1,    -1,    -1,    33,    34,    35,    -1,    37,    38,    39,
      -1,     0,    -1,    -1,     3,    -1,    -1,     6,     7,    -1,
      -1,    51,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      19,    20,    21,    22,    23,    -1,    25,    26,    -1,    28,
      -1,    -1,    -1,    -1,    33,    34,    35,    -1,    37,    38,
      39,     3,    -1,    -1,     6,     7,    -1,    -1,    -1,    11,
      -1,    13,    14,    15,    -1,    -1,    -1,    19,    20,    21,
      22,    23,    -1,    25,    26,    -1,    28,    -1,    -1,    -1,
      -1,    33,    34,    35,    -1,    37,    38,    39,     6,     7,
      -1,    -1,    -1,    11,    -1,    13,    -1,    15,    -1,    -1,
      -1,    -1,    20,    21,    -1,    23,    -1,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    35,    -1,    37,
      38,    39
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,    11,    13,    14,    15,    19,    20,
      21,    22,    23,    25,    26,    28,    33,    34,    35,    37,
      38,    39,    91,    92,    93,    95,    96,    99,   100,   102,
     106,   107,    62,    69,     0,    92,    62,    66,    71,    75,
      97,    98,   108,   109,   111,    96,    96,    96,    96,    69,
      62,   103,   104,   105,   108,   106,   111,   112,    66,    67,
      68,    69,    94,    95,    96,   125,    73,   110,   109,   103,
      67,    70,    68,    72,   106,   111,    98,   108,    27,    41,
      42,    62,    63,    64,    69,    71,    75,    78,    79,    80,
      81,    82,   118,   135,   136,   138,   139,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   160,   161,   162,   163,     4,
       5,     8,     9,    10,    16,    17,    18,    24,    30,    36,
      62,    66,    70,    95,   123,   124,   125,   126,   127,   128,
     129,   130,   134,   163,   165,    95,   125,    28,    74,    75,
     112,   163,    71,    67,    70,    70,   104,   138,   162,   166,
      71,   138,    71,   138,   138,    73,    76,   118,   119,   120,
     121,   122,   100,   101,   106,   117,   165,   139,   138,   139,
     139,   139,   139,    40,    41,    42,    71,    73,    76,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    68,
     164,    75,    83,    84,    79,    80,    43,    44,    45,    46,
      85,    86,    47,    48,    78,    87,    88,    50,    89,    49,
      66,   166,    66,    77,   167,    71,    62,    71,   131,   165,
      71,    71,    77,    70,   167,    66,    67,   112,   163,    74,
      28,    74,    75,   163,    74,    62,    72,    96,   113,   114,
     115,   116,    70,   117,   117,   166,    62,    67,    70,   118,
      68,   122,   101,   101,    72,    72,    62,    72,   137,   163,
     165,    62,   163,   139,   140,   140,   140,   141,   142,   142,
     143,   144,   144,   145,   146,   146,   146,   146,   147,   148,
     148,   149,   150,   151,   152,   153,   154,   167,   167,   167,
      77,   123,   123,    95,   131,    66,   133,   165,    66,   165,
     167,   123,   127,   163,   163,    74,   163,    74,    74,   108,
      72,    67,    67,    72,    72,    72,    74,    70,   118,   120,
      69,   139,    67,    72,    74,   157,   161,   165,   155,   159,
     123,   167,    66,    66,    72,    72,   133,    74,    74,    51,
     115,    62,   118,   119,   163,   168,    36,   131,   167,   167,
     123,    72,    67,    70,    77,    71,    66,   132,   133,   123,
     167,    70,   167,   133,   131,    66,   168,   123,   162,    72,
      72,   167,    12,   168,   168,    66,   123,   131,   167,   168,
     123,    72,   167,   123,   168
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    90,    91,    91,    92,    92,    93,    93,    94,    94,
      95,    95,    96,    96,    96,    96,    96,    96,    96,    96,
      97,    97,    98,    98,    99,    99,    99,    99,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   101,   101,   101,   101,   102,   102,   102,   102,   102,
     103,   103,   104,   104,   105,   106,   106,   106,   107,   108,
     108,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   110,   111,   111,   111,   111,
     112,   112,   113,   113,   114,   114,   115,   115,   116,   116,
     117,   118,   118,   118,   119,   119,   119,   119,   120,   121,
     121,   122,   122,   123,   123,   123,   123,   123,   123,   124,
     124,   124,   125,   125,   126,   126,   127,   127,   128,   128,
     129,   129,   129,   130,   130,   130,   130,   131,   131,   132,
     132,   133,   134,   134,   134,   134,   135,   135,   135,   135,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     137,   137,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   139,   139,   140,   141,   141,   141,   141,
     142,   143,   143,   143,   144,   145,   145,   145,   146,   147,
     147,   147,   147,   147,   148,   149,   149,   149,   150,   151,
     151,   152,   153,   153,   154,   155,   155,   156,   157,   157,
     158,   158,   159,   160,   161,   162,   162,   163,   163,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     165,   165,   166,   167,   168
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     4,     3,     1,     2,
       3,     2,     2,     1,     2,     1,     2,     1,     2,     1,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     2,     1,     5,     4,     6,     5,     2,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     2,
       1,     1,     3,     5,     4,     4,     3,     6,     5,     6,
       5,     4,     5,     5,     4,     0,     2,     1,     3,     2,
       1,     2,     1,     3,     1,     3,     2,     1,     1,     3,
       1,     1,     3,     4,     2,     1,     4,     3,     2,     1,
       2,     3,     2,     1,     1,     1,     1,     1,     1,     3,
       4,     3,     3,     2,     1,     3,     1,     1,     2,     1,
      10,     7,     5,     8,     9,    14,     9,     1,     0,     1,
       0,     1,     3,     2,     2,     3,     1,     1,     1,     3,
       1,     4,     4,     3,     3,     3,     2,     2,     6,     7,
       1,     3,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     4,     1,     4,     1,     1,     3,     3,     3,
       1,     1,     3,     3,     1,     1,     3,     3,     1,     1,
       3,     3,     3,     3,     1,     1,     3,     3,     1,     1,
       3,     1,     1,     3,     1,     1,     3,     1,     1,     4,
       1,     4,     1,     1,     1,     1,     9,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     0,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 6: /* function_definition: declaration_specifiers declarator declaration_list compound_statement  */
#line 214 "compiler_rules_actions.y"
                                                                {
									/* Backpatch the compound statement */
									backpatch((yyvsp[0].nl)->l, currAddr()+1);

									/* Pops the current scope since the function scope has ended */
									scopes.pop();

									/* Emit return. This may cause multiple return statements.
									But that is unavoidable since there may be missing return statements in
									the code, which wont let the function return */
									// emit("", RET);
								}
#line 2239 "y.tab.c"
    break;

  case 7: /* function_definition: declaration_specifiers declarator compound_statement  */
#line 227 "compiler_rules_actions.y"
                                                                {
									/* Backpatch the compound statement */
									backpatch((yyvsp[0].nl)->l, currAddr()+1);

									/* Pops the current scope since the function scope has ended */
									scopes.pop();

									/* Emit return. This may cause multiple return statements.
									But that is unavoidable since there may be missing return statements in
									the code, which wont let the function return */
									// emit("", RET);
								}
#line 2256 "y.tab.c"
    break;

  case 10: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 256 "compiler_rules_actions.y"
                                                                {
									/* Type reading has ended. Reset currtype */
									currtype = TNULL;
								}
#line 2265 "y.tab.c"
    break;

  case 22: /* init_declarator: declarator  */
#line 278 "compiler_rules_actions.y"
                                                                {
									/* Lookup variable in symbol table */
									if(((yyvsp[0].sym)->t).tname != TFUNC) (yyval.sym) = scopes.top()->lookup((yyvsp[0].sym));
									else yyerror("Cannot declare function without definition");
								}
#line 2275 "y.tab.c"
    break;

  case 23: /* init_declarator: declarator '=' initializer  */
#line 284 "compiler_rules_actions.y"
                                                                {
									/* Initialize if possible. Otherwise report error */
									if(((yyvsp[-2].sym)->t).tname == TARR) yyerror("Cannot initialize arrays");
									if(((yyvsp[-2].sym)->t).tname == TFUNC) yyerror("Cannot initialize functions");
									(yyval.sym) = scopes.top()->lookup((yyvsp[-2].sym));

									/* Perform suitable type conversions */
									typeconv((yyvsp[0].sym), (yyval.sym));
									emit((yyvsp[-2].sym)->getname(), EQ, (yyvsp[0].sym)->getname());
								}
#line 2290 "y.tab.c"
    break;

  case 28: /* type_specifier: VOID  */
#line 303 "compiler_rules_actions.y"
                                                                {
									/* Save current type for future usage */
									currtype = TVOID;
								}
#line 2299 "y.tab.c"
    break;

  case 29: /* type_specifier: CHAR  */
#line 308 "compiler_rules_actions.y"
                                                                {
									/* Save current type for future usage */
									currtype = TCHAR;
								}
#line 2308 "y.tab.c"
    break;

  case 31: /* type_specifier: INT  */
#line 314 "compiler_rules_actions.y"
                                                                {
									/* Save current type for future usage */
									currtype = TINT;
								}
#line 2317 "y.tab.c"
    break;

  case 34: /* type_specifier: DOUBLE  */
#line 321 "compiler_rules_actions.y"
                                                                {
									/* Save current type for future usage */
									currtype = TDOUBLE;
								}
#line 2326 "y.tab.c"
    break;

  case 59: /* declarator: pointer direct_declarator  */
#line 366 "compiler_rules_actions.y"
                                                                {
									(yyval.sym) = (yyvsp[0].sym);
								}
#line 2334 "y.tab.c"
    break;

  case 61: /* direct_declarator: IDENTIFIER  */
#line 373 "compiler_rules_actions.y"
                                                                {
									/* Save current type and also initiate function class.
										The function class will be used if the identifier is a function name */

									(yyvsp[0].sym)->t = currtype;
									currfunc = new symbol((yyvsp[0].sym)->getname(), TFUNC);
									currfunc->createfunc();
									(currfunc->sub->func)->rettype = currtype;
									(yyval.sym) = (yyvsp[0].sym);
								}
#line 2349 "y.tab.c"
    break;

  case 65: /* direct_declarator: direct_declarator '[' assignment_expression ']'  */
#line 387 "compiler_rules_actions.y"
                                                                {
									/* Add array index after proper checks.
									Array indexing possible with only integer type indices */

									if((yyvsp[-1].sym)->constant != 1) yyerror("Cannot initialize array with non-constant size");
									if(((yyvsp[-1].sym)->t).tname != TINT) yyerror("Cannot initialize array with non-integer size");
									(yyvsp[-3].sym)->t = type(TARR, (yyvsp[-1].sym)->v.ival, (yyvsp[-3].sym)->t);
									currtype = type(TARR, (yyvsp[-1].sym)->v.ival, currtype);
									(yyval.sym) = (yyvsp[-3].sym);
								}
#line 2364 "y.tab.c"
    break;

  case 66: /* direct_declarator: direct_declarator '[' ']'  */
#line 398 "compiler_rules_actions.y"
                                                                {
									/* Array declaration for parameters */
									(yyvsp[-2].sym)->t = type(TARR, 0, (yyvsp[-2].sym)->t);
									currtype = type(TARR, 0, currtype);
									(yyval.sym) = (yyvsp[-2].sym);
								}
#line 2375 "y.tab.c"
    break;

  case 72: /* direct_declarator: direct_declarator push_sym '(' parameter_type_list ')'  */
#line 410 "compiler_rules_actions.y"
                                                                {
									/* Push_sym stores the symbol* pointer for the function that is
										being declared.
										This is passed on to the 'direct_declarator'.
										*/

									(yyval.sym) = (yyvsp[-3].sym);
								}
#line 2388 "y.tab.c"
    break;

  case 73: /* direct_declarator: direct_declarator push_sym '(' identifier_list ')'  */
#line 419 "compiler_rules_actions.y"
                                                                {
									(yyval.sym) = (yyvsp[-3].sym);
								}
#line 2396 "y.tab.c"
    break;

  case 74: /* direct_declarator: direct_declarator push_sym '(' ')'  */
#line 423 "compiler_rules_actions.y"
                                                                {
									(yyval.sym) = (yyvsp[-2].sym);
								}
#line 2404 "y.tab.c"
    break;

  case 75: /* push_sym: %empty  */
#line 429 "compiler_rules_actions.y"
                                                                {
									/* push_sym performs lookup for the current function declaration,
									ans also pushes its symboltable into the scope stack, so that its variables
									can be declared in its scope
									*/
									scopes.top()->lookup(currfunc);
									scopes.push(currfunc->sub);
									emit(currfunc->name, LAB);
									(yyval.sym) = currfunc;
								}
#line 2419 "y.tab.c"
    break;

  case 77: /* pointer: '*'  */
#line 443 "compiler_rules_actions.y"
                                                                {
									/* Updates currtype to a pointer of the previous type */
									currtype = type(TPTR,0,currtype);
								}
#line 2428 "y.tab.c"
    break;

  case 79: /* pointer: '*' pointer  */
#line 449 "compiler_rules_actions.y"
                                                                {
									/* Updates currtype to a pointer of the previous type */
									currtype = type(TPTR,0,currtype);
								}
#line 2437 "y.tab.c"
    break;

  case 86: /* parameter_declaration: declaration_specifiers declarator  */
#line 468 "compiler_rules_actions.y"
                                                                {
									/* Saves the paramter types into the functions symbol table. */
									scopes.top()->paramlookup((yyvsp[0].sym));
									(scopes.top()->func)->typelist.push_back(currtype);
								}
#line 2447 "y.tab.c"
    break;

  case 112: /* compound_statement: '{' block_item_list '}'  */
#line 529 "compiler_rules_actions.y"
                                                                {
									(yyval.nl) = (yyvsp[-1].nl);
								}
#line 2455 "y.tab.c"
    break;

  case 113: /* compound_statement: '{' '}'  */
#line 533 "compiler_rules_actions.y"
                                                                {
									(yyval.nl) = new nextlist();
								}
#line 2463 "y.tab.c"
    break;

  case 115: /* block_item_list: block_item_list address_nonterm block_item  */
#line 540 "compiler_rules_actions.y"
                                                                {
									/* Previous block must be backpatched before current block starts */

									backpatch((yyvsp[-2].nl)->l, (yyvsp[-1].add));
									(yyval.nl) = (yyvsp[0].nl);
								}
#line 2474 "y.tab.c"
    break;

  case 116: /* block_item: declaration  */
#line 549 "compiler_rules_actions.y"
                                                                {
									(yyval.nl) = new nextlist();
								}
#line 2482 "y.tab.c"
    break;

  case 118: /* expression_statement: expression ';'  */
#line 556 "compiler_rules_actions.y"
                                                                {
									if(((yyvsp[-1].sym)->t).tname == TBOOL)
									{
										/* If dangling boolean, then backpatch it */
										backpatch((yyvsp[-1].sym)->tl, currAddr()+1);
										backpatch((yyvsp[-1].sym)->fl, currAddr()+1);
									}
									(yyval.nl) = new nextlist();
								}
#line 2496 "y.tab.c"
    break;

  case 119: /* expression_statement: ';'  */
#line 566 "compiler_rules_actions.y"
                                                                {
									(yyval.nl) = new nextlist();
								}
#line 2504 "y.tab.c"
    break;

  case 120: /* selection_statement: IF '(' bool_expression ')' address_nonterm statement jump_nonterm ELSE address_nonterm statement  */
#line 572 "compiler_rules_actions.y"
                                                                {
									backpatch((yyvsp[-7].sym)->tl, (yyvsp[-5].add));
									backpatch((yyvsp[-7].sym)->fl, (yyvsp[-1].add));
									(yyval.nl) = new nextlist();
									(yyval.nl)->l = mergelist((yyvsp[-4].nl)->l, (yyvsp[-3].nl)->l);
									(yyval.nl)->l = mergelist((yyval.nl)->l, (yyvsp[0].nl)->l);
								}
#line 2516 "y.tab.c"
    break;

  case 121: /* selection_statement: IF '(' bool_expression ')' address_nonterm statement jump_nonterm  */
#line 580 "compiler_rules_actions.y"
                                                                {
									/* This produces a redundant GOTO due to 'jump_nonterm' nonterminal.
										The 'jump_nonterm' is essential for the grammar to parse, without which
										a reduce/reduce conflict occurs.
										*/
									backpatch((yyvsp[-4].sym)->tl, (yyvsp[-2].add));
									(yyval.nl) = new nextlist();
									(yyval.nl)->l = (yyvsp[-4].sym)->fl;
									(yyval.nl)->l = mergelist((yyval.nl)->l, (yyvsp[-1].nl)->l);
									(yyval.nl)->l = mergelist((yyval.nl)->l, (yyvsp[0].nl)->l);
								}
#line 2532 "y.tab.c"
    break;

  case 123: /* iteration_statement: WHILE '(' address_nonterm bool_expression ')' address_nonterm statement jump_nonterm  */
#line 595 "compiler_rules_actions.y"
                                                                {
									backpatch((yyvsp[0].nl)->l, (yyvsp[-5].add));
									backpatch((yyvsp[-1].nl)->l, (yyvsp[-5].add));
									backpatch((yyvsp[-4].sym)->tl, (yyvsp[-2].add));

									(yyval.nl) = new nextlist();
									(yyval.nl)->l = (yyvsp[-4].sym)->fl;
								}
#line 2545 "y.tab.c"
    break;

  case 124: /* iteration_statement: DO address_nonterm statement address_nonterm WHILE '(' bool_expression ')' ';'  */
#line 604 "compiler_rules_actions.y"
                                                                {
									backpatch((yyvsp[-2].sym)->tl, (yyvsp[-7].add));
									backpatch((yyvsp[-6].nl)->l, (yyvsp[-5].add));
									(yyval.nl) = new nextlist();
									(yyval.nl)->l = (yyvsp[-2].sym)->fl;
								}
#line 2556 "y.tab.c"
    break;

  case 125: /* iteration_statement: FOR '(' temp ';' address_nonterm bool_temp ';' address_nonterm temp jump_nonterm ')' address_nonterm statement jump_nonterm  */
#line 611 "compiler_rules_actions.y"
                                                                {
									backpatch((yyvsp[-8].sym)->tl, (yyvsp[-2].add));
									backpatch((yyvsp[0].nl)->l, (yyvsp[-6].add));
									backpatch((yyvsp[-1].nl)->l, (yyvsp[-6].add));
									backpatch((yyvsp[-4].nl)->l, (yyvsp[-9].add));

									(yyval.nl) = new nextlist();
									(yyval.nl)->l = (yyvsp[-8].sym)->fl;
								}
#line 2570 "y.tab.c"
    break;

  case 128: /* temp: %empty  */
#line 625 "compiler_rules_actions.y"
                                                                {
									(yyval.sym) = 0;
								}
#line 2578 "y.tab.c"
    break;

  case 131: /* bool_expression: expression  */
#line 635 "compiler_rules_actions.y"
                                                                {
									/* This augmentation has been provided to convert ints to bool inplace.
										Calling the convIntBool at an other place can cause the intermediate
										codes to be jumped due to the GOTOs of the conversion
										*/
									convDblInt((yyvsp[0].sym));
									convIntBool((yyvsp[0].sym));
									(yyval.sym) = (yyvsp[0].sym);
								}
#line 2592 "y.tab.c"
    break;

  case 135: /* jump_statement: RETURN temp ';'  */
#line 650 "compiler_rules_actions.y"
                                                                {
									if((yyvsp[-1].sym) == 0)
									{
										/* There is nothing to return, then emit return only */
										emit("", RET);
									}
									else
									{
										/* Otherwise return the expression */
										type ty = (scopes.top()->func)->rettype;
										typeconv((yyvsp[-1].sym), ty);
										emit((yyvsp[-1].sym)->getname(), RET);
									}
									(yyval.nl) = new nextlist();
								}
#line 2612 "y.tab.c"
    break;

  case 136: /* primary_expression: IDENTIFIER  */
#line 678 "compiler_rules_actions.y"
                                                                {
									/* Lookup identifier in the symbol table to use the variable in expressions */

									(yyval.sym) = scopes.top()->lookup((yyvsp[0].sym)->getname());
									(yyval.sym) = new symbol(*(yyval.sym));
									if(((yyval.sym)->t).tname == TARR)
									{
										(yyval.sym) = gentemp(type(TPTR, 0, ((yyval.sym)->t).getbasetype()));
										emit((yyval.sym)->getname(), EQADD, (yyvsp[0].sym)->getname());
									}
								}
#line 2628 "y.tab.c"
    break;

  case 139: /* primary_expression: '(' expression ')'  */
#line 692 "compiler_rules_actions.y"
                                                                {
									(yyval.sym) = (yyvsp[-1].sym);
								}
#line 2636 "y.tab.c"
    break;

  case 141: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 699 "compiler_rules_actions.y"
                                                                {
									/* Resolve array addresses after from checks. */
									/* Array indices are added to the array class of the symbol for resolution */

									if(((yyvsp[-1].sym)->t).tname != TINT) yyerror("Cannot access non-integer index");
									if(((yyvsp[-3].sym)->t).tname != TARR && ((yyvsp[-3].sym)->t).tname != TPTR)
										yyerror("Cannot access non-array or non-pointer variable");

									convCharInt((yyvsp[-1].sym));
									convBoolInt((yyvsp[-1].sym));

									symbol* temp = gentemp(TINT);
									(yyvsp[-3].sym)->arr = new ArrayCustom((yyvsp[-3].sym)->getname(), temp, ((yyvsp[-3].sym)->t).getbasetype());
									emit(temp->getname(), EQ, (yyvsp[-1].sym)->getname());
									emit(temp->getname(), temp->getname(), MUL, conv2string(type(((yyvsp[-3].sym)->t).getbasetype()).getsize()));
									(yyval.sym) = (yyvsp[-3].sym);
									(yyval.sym)->t = ((yyval.sym)->t).getbasetype();
								}
#line 2659 "y.tab.c"
    break;

  case 142: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 718 "compiler_rules_actions.y"
                                                                {
									/* Calls function after suitable checks */

									if(((yyvsp[-3].sym)->t).tname != TFUNC) yyerror("Cannot call non function identifiers");
									(yyvsp[-1].al)->call((yyvsp[-3].sym));
									(yyval.sym) = (yyvsp[-3].sym);
								}
#line 2671 "y.tab.c"
    break;

  case 146: /* postfix_expression: postfix_expression INC  */
#line 729 "compiler_rules_actions.y"
                                                                {
									/* Saves the previous value of the variable for use in the expression,
									increments the variable and propagates the temporary */

									/* Post increment can only occur for non-temporary and integer type variables */

									if((yyvsp[-1].sym)->temporary) yyerror("Cannot increment temporary variable");
									if(((yyvsp[-1].sym)->t).getbasetype() != TINT && ((yyvsp[-1].sym)->t).getbasetype() != TPTR)
										yyerror("Invalid use of increment operator on non-integer type");
									if((yyvsp[-1].sym)->arr != 0)
									{
										/* If type is ARRAY, then the resolved array needs to be stored in a
											temporary variable, which is incremented and stored back to the array location */
										(yyval.sym) = gentemp(((yyvsp[-1].sym)->t).getbasetype());
										emit((yyval.sym)->getname(), (yyvsp[-1].sym)->getname(), EQARR, (yyvsp[-1].sym)->getoffset());
										symbol* temp = gentemp(((yyvsp[-1].sym)->t).getbasetype());
										emit(temp->getname(), (yyvsp[-1].sym)->getname(), EQARR, (yyvsp[-1].sym)->getoffset());
										emit(temp->getname(), temp->getname(), PLUS, "1");
										emit((yyvsp[-1].sym)->getname(), (yyvsp[-1].sym)->getoffset(), ARREQ, temp->getname());
									}
									else
									{
										(yyval.sym) = gentemp(((yyvsp[-1].sym)->t).tname);
										symbol* temp1 = gentemp(TINT);
										emit(temp1->getname(), EQ, "1");
										emit((yyval.sym)->getname(), EQ, (yyvsp[-1].sym)->getname());
										emit((yyvsp[-1].sym)->getname(), (yyvsp[-1].sym)->getname(), PLUS, temp1->getname());
									}
								}
#line 2705 "y.tab.c"
    break;

  case 147: /* postfix_expression: postfix_expression DEC  */
#line 759 "compiler_rules_actions.y"
                                                                {
									/* Saves the previous value of the variable for use in the expression,
									decrements the variable and propagates the temporary */

									/* Post decrement can only occur for non-temporary and integer type variables */

									if((yyvsp[-1].sym)->temporary) yyerror("Cannot decrement temporary variable");
									if(((yyvsp[-1].sym)->t).getbasetype() != TINT && ((yyvsp[-1].sym)->t).getbasetype() != TPTR)
										yyerror("Invalid use of decrement operator on non-integer type");

									if((yyvsp[-1].sym)->arr != 0)
									{
										/* If type is ARRAY, then the resolved array needs to be stored in a
											temporary variable, which is decremented and stored back to the array location */
										(yyval.sym) = gentemp(((yyvsp[-1].sym)->t).getbasetype());
										emit((yyval.sym)->getname(), (yyvsp[-1].sym)->getname(), EQARR, (yyvsp[-1].sym)->getoffset());
										symbol* temp = gentemp(((yyvsp[-1].sym)->t).getbasetype());
										emit(temp->getname(), (yyvsp[-1].sym)->getname(), EQARR, (yyvsp[-1].sym)->getoffset());
										emit(temp->getname(), temp->getname(), MINUS, "1");
										emit((yyvsp[-1].sym)->getname(), (yyvsp[-1].sym)->getoffset(), ARREQ, temp->getname());
									}
									else
									{
										(yyval.sym) = gentemp(((yyvsp[-1].sym)->t).tname);
										symbol* temp1 = gentemp(TINT);
										emit(temp1->getname(), EQ, "1");
										emit((yyval.sym)->getname(), EQ, (yyvsp[-1].sym)->getname());
										emit((yyvsp[-1].sym)->getname(), (yyvsp[-1].sym)->getname(), MINUS, temp1->getname());
									}
								}
#line 2740 "y.tab.c"
    break;

  case 150: /* argument_expression_list: assignment_expression  */
#line 794 "compiler_rules_actions.y"
                                                                {
									/* Initiates an arglist for argument passing */

									(yyval.al) = new ArgList();
									(yyval.al)->add((yyvsp[0].sym));
								}
#line 2751 "y.tab.c"
    break;

  case 151: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 801 "compiler_rules_actions.y"
                                                                {
									/* Saves an argument to the arglist for the function call. */

									(yyvsp[-2].al)->add((yyvsp[0].sym));
									(yyval.al) = (yyvsp[-2].al);
								}
#line 2762 "y.tab.c"
    break;

  case 153: /* unary_expression: INC unary_expression  */
#line 811 "compiler_rules_actions.y"
                                                                {
									/* Pre-increment can only be performed on non-temporary and integer type variables */
									/* Increments the variable and propagates it. */

									if((yyvsp[0].sym)->temporary) yyerror("Cannot increment temporary variable");
									if(((yyvsp[0].sym)->t).getbasetype() != TINT && ((yyvsp[0].sym)->t).getbasetype() != TPTR)
										yyerror("Invalid use of increment operator on non-integer type");

									if((yyvsp[0].sym)->arr != 0)
									{
										/* If type is ARRAY, then the resolved array needs to be stored in a
											temporary variable, which is incremented and stored back to the array location */
										symbol* temp = gentemp(((yyvsp[0].sym)->t).getbasetype());
										emit(temp->getname(), (yyvsp[0].sym)->getname(), EQARR, (yyvsp[0].sym)->getoffset());
										emit(temp->getname(), temp->getname(), PLUS, "1");
										emit((yyvsp[0].sym)->getname(), (yyvsp[0].sym)->getoffset(), ARREQ, temp->getname());
										(yyval.sym) = (yyvsp[0].sym);
									}
									else
									{
										symbol* temp1 = gentemp(TINT);
										emit(temp1->getname(), EQ, "1");
										emit((yyvsp[0].sym)->getname(), (yyvsp[0].sym)->getname(), PLUS, temp1->getname());
										(yyval.sym) = (yyvsp[0].sym);
									}
								}
#line 2793 "y.tab.c"
    break;

  case 154: /* unary_expression: DEC unary_expression  */
#line 838 "compiler_rules_actions.y"
                                                                {
									if((yyvsp[0].sym)->temporary) yyerror("Cannot decrement temporary variable");
									if(((yyvsp[0].sym)->t).getbasetype() != TINT && ((yyvsp[0].sym)->t).getbasetype() != TPTR)
										yyerror("Invalid use of increment operator on non-integer type");

									if((yyvsp[0].sym)->arr != 0)
									{
										/* If type is ARRAY, then the resolved array needs to be stored in a
											temporary variable, which is decremented and stored back to the array location */
										symbol* temp = gentemp(((yyvsp[0].sym)->t).getbasetype());
										emit(temp->getname(), (yyvsp[0].sym)->getname(), EQARR, (yyvsp[0].sym)->getoffset());
										emit(temp->getname(), temp->getname(), MINUS, "1");
										emit((yyvsp[0].sym)->getname(), (yyvsp[0].sym)->getoffset(), ARREQ, temp->getname());
										(yyval.sym) = (yyvsp[0].sym);
									}
									else
									{
										symbol* temp1 = gentemp(TINT);
										emit(temp1->getname(), EQ, "1");
										emit((yyvsp[0].sym)->getname(), (yyvsp[0].sym)->getname(), MINUS, temp1->getname());
										(yyval.sym) = (yyvsp[0].sym);
									}
								}
#line 2821 "y.tab.c"
    break;

  case 155: /* unary_expression: '&' unary_expression  */
#line 862 "compiler_rules_actions.y"
                                                                {
									/* Address can be resolved only for variables that have been declared */
									if((yyvsp[0].sym)->temporary && (yyvsp[0].sym)->arr == 0) yyerror("Cannot resolve address of temporary variable");

									type ty = ((yyvsp[0].sym)->t).getbasetype();
									ty = type(TPTR, 0, ty);
									(yyval.sym) = gentemp(ty);
									if((yyvsp[0].sym)->arr != 0)
									{
										emit((yyval.sym)->getname(), (yyvsp[0].sym)->getname(), PLUS, (yyvsp[0].sym)->getoffset());
									}
									else
									{
										emit((yyval.sym)->getname(), EQADD, (yyvsp[0].sym)->name);
									}
								}
#line 2842 "y.tab.c"
    break;

  case 156: /* unary_expression: '*' cast_expression  */
#line 879 "compiler_rules_actions.y"
                                                                {
									/* Pointer operator can be applied only on pointer type variables */
									if(((yyvsp[0].sym)->t).tname != TPTR) yyerror("Cannot resolve pointer operator of non-pointer variable");

									symbol* temp = gentemp(TINT);
									(yyvsp[0].sym)->arr = new ArrayCustom((yyvsp[0].sym)->getname(), temp, ((yyvsp[0].sym)->t).getbasetype());
									emit(temp->getname(), EQ, "0");
									emit(temp->getname(), temp->getname(), MUL, conv2string(type(((yyvsp[0].sym)->t).getbasetype()).getsize()));
									(yyval.sym) = (yyvsp[0].sym);
									(yyval.sym)->t = ((yyval.sym)->t).getbasetype();
								}
#line 2858 "y.tab.c"
    break;

  case 157: /* unary_expression: '+' cast_expression  */
#line 891 "compiler_rules_actions.y"
                                                                {
									convBoolInt((yyvsp[0].sym));
									(yyval.sym) = (yyvsp[0].sym);
								}
#line 2867 "y.tab.c"
    break;

  case 158: /* unary_expression: '-' cast_expression  */
#line 896 "compiler_rules_actions.y"
                                                                {
									convBoolInt((yyvsp[0].sym));
									(yyval.sym) = gentemp(((yyvsp[0].sym)->t).tname);
									emit((yyval.sym)->getname(), UMINUS, (yyvsp[0].sym)->getname());
								}
#line 2877 "y.tab.c"
    break;

  case 160: /* unary_expression: '!' cast_expression  */
#line 903 "compiler_rules_actions.y"
                                                                {
									convIntBool((yyvsp[0].sym));
									swap((yyvsp[0].sym)->tl, (yyvsp[0].sym)->fl);
								}
#line 2886 "y.tab.c"
    break;

  case 163: /* cast_expression: unary_expression  */
#line 912 "compiler_rules_actions.y"
                                                                {
									if((yyvsp[0].sym)->arr != 0)
									{
										/* Array address is resolved at this point. */
										(yyval.sym) = gentemp(((yyvsp[0].sym)->t).getbasetype());
										emit((yyval.sym)->getname(), (yyvsp[0].sym)->getname(), EQARR, (yyvsp[0].sym)->getoffset());
									}
									else (yyval.sym) = (yyvsp[0].sym);
								}
#line 2900 "y.tab.c"
    break;

  case 164: /* cast_expression: '(' type_name ')' cast_expression  */
#line 922 "compiler_rules_actions.y"
                                                                {
									/* Explicit ype conversion */
									convBoolInt((yyvsp[0].sym));
									if(((yyvsp[0].sym)->t).tname == TARR)
									{
										if(((yyvsp[0].sym)->arr)->dims.size() == 0) (yyval.sym) = gentemp(((yyvsp[0].sym)->t).getbasetype());
										else (yyval.sym) = gentemp(type(TPTR, 0, type(TINT)));
										emit((yyval.sym)->getname(), EQ, (yyvsp[0].sym)->getname());
										(yyvsp[0].sym) = (yyval.sym);
									}
									typeconv((yyvsp[0].sym), new symbol(currtype));
									(yyval.sym) = (yyvsp[0].sym);
								}
#line 2918 "y.tab.c"
    break;

  case 165: /* nb_cast_expression: cast_expression  */
#line 938 "compiler_rules_actions.y"
                                                                {
									/* This augmentation helps in inplace conversion from bool to int.
									 Calling the convBoolInt() function from some other place can cause the intermediate
									 instructions to get skipped due to the gotos of the conversion */
									/* This augmentation has usage in the arithmetic operations, which require the operands
									to be of non-boolean type */
									convBoolInt((yyvsp[0].sym));
									(yyval.sym) = (yyvsp[0].sym);
								}
#line 2932 "y.tab.c"
    break;

  case 167: /* multiplicative_expression: nb_multiplicative_expression '*' nb_cast_expression  */
#line 951 "compiler_rules_actions.y"
                                                                {
									typecheck((yyvsp[-2].sym), (yyvsp[0].sym));
									(yyval.sym) = gentemp(((yyvsp[-2].sym)->t).tname);
									emit((yyval.sym)->getname(), (yyvsp[-2].sym)->getname(), MUL, (yyvsp[0].sym)->getname());
								}
#line 2942 "y.tab.c"
    break;

  case 168: /* multiplicative_expression: nb_multiplicative_expression '/' nb_cast_expression  */
#line 957 "compiler_rules_actions.y"
                                                                {
									typecheck((yyvsp[-2].sym), (yyvsp[0].sym));
									(yyval.sym) = gentemp(((yyvsp[-2].sym)->t).tname);
									emit((yyval.sym)->getname(), (yyvsp[-2].sym)->getname(), DIV, (yyvsp[0].sym)->getname());
								}
#line 2952 "y.tab.c"
    break;

  case 169: /* multiplicative_expression: nb_multiplicative_expression '%' nb_cast_expression  */
#line 963 "compiler_rules_actions.y"
                                                                {
									typecheck((yyvsp[-2].sym), (yyvsp[0].sym));
									if(((yyvsp[-2].sym)->t).tname != TINT) yyerror("'%' operator on non-integer types");
									(yyval.sym) = gentemp(((yyvsp[-2].sym)->t).tname);
									emit((yyval.sym)->getname(), (yyvsp[-2].sym)->getname(), MOD, (yyvsp[0].sym)->getname());
								}
#line 2963 "y.tab.c"
    break;

  case 170: /* nb_multiplicative_expression: multiplicative_expression  */
#line 972 "compiler_rules_actions.y"
                                                                {
									/* This augmentation helps in inplace conversion from bool to int.
									 Calling the convBoolInt() function from some other place can cause the intermediate
									 instructions to get skipped due to the gotos of the conversion */
									/* This augmentation has usage in the arithmetic operations, which require the operands
									to be of non-boolean type */

									convBoolInt((yyvsp[0].sym));
									(yyval.sym) = (yyvsp[0].sym);
								}
#line 2978 "y.tab.c"
    break;

  case 172: /* additive_expression: nb_additive_expression '+' nb_multiplicative_expression  */
#line 986 "compiler_rules_actions.y"
                                                                {
									typecheck((yyvsp[-2].sym), (yyvsp[0].sym));
									(yyval.sym) = gentemp(((yyvsp[-2].sym)->t).getbasetype());
									emit((yyval.sym)->getname(), (yyvsp[-2].sym)->getname(), PLUS, (yyvsp[0].sym)->getname());
								}
#line 2988 "y.tab.c"
    break;

  case 173: /* additive_expression: nb_additive_expression '-' nb_multiplicative_expression  */
#line 992 "compiler_rules_actions.y"
                                                                {
									typecheck((yyvsp[-2].sym), (yyvsp[0].sym));
									(yyval.sym) = gentemp(((yyvsp[-2].sym)->t).getbasetype());
									emit((yyval.sym)->getname(), (yyvsp[-2].sym)->getname(), MINUS, (yyvsp[0].sym)->getname());
								}
#line 2998 "y.tab.c"
    break;

  case 174: /* nb_additive_expression: additive_expression  */
#line 1000 "compiler_rules_actions.y"
                                                                {
									/* This augmentation helps in inplace conversion from bool to int.
									 Calling the convBoolInt() function from some other place can cause the intermediate
									 instructions to get skipped due to the gotos of the conversion */
									/* This augmentation has usage in the arithmetic operations, which require the operands
									to be of non-boolean type */

									convBoolInt((yyvsp[0].sym));
									(yyval.sym) = (yyvsp[0].sym);
								}
#line 3013 "y.tab.c"
    break;

  case 176: /* shift_expression: nb_shift_expression SHL nb_additive_expression  */
#line 1014 "compiler_rules_actions.y"
                                                                {
									typecheck((yyvsp[-2].sym), (yyvsp[0].sym));
									if(((yyvsp[-2].sym)->t).tname != TINT) yyerror("'<<' operator on non-integer types");
									(yyval.sym) = gentemp(((yyvsp[-2].sym)->t).tname);
									emit((yyval.sym)->getname(), (yyvsp[-2].sym)->getname(), SLL, (yyvsp[0].sym)->getname());
								}
#line 3024 "y.tab.c"
    break;

  case 177: /* shift_expression: nb_shift_expression SHR nb_additive_expression  */
#line 1021 "compiler_rules_actions.y"
                                                                {
									typecheck((yyvsp[-2].sym), (yyvsp[0].sym));
									if(((yyvsp[-2].sym)->t).tname != TINT) yyerror("'>>' operator on non-integer types");
									(yyval.sym) = gentemp(((yyvsp[-2].sym)->t).tname);
									emit((yyval.sym)->getname(), (yyvsp[-2].sym)->getname(), SRL, (yyvsp[0].sym)->getname());
								}
#line 3035 "y.tab.c"
    break;

  case 178: /* nb_shift_expression: shift_expression  */
#line 1030 "compiler_rules_actions.y"
                                                                {
									/* This augmentation helps in inplace conversion from bool to int.
									 Calling the convBoolInt() function from some other place can cause the intermediate
									 instructions to get skipped due to the gotos of the conversion */
									/* This augmentation has usage in the arithmetic operations, which require the operands
									to be of non-boolean type */

									convBoolInt((yyvsp[0].sym));
									(yyval.sym) = (yyvsp[0].sym);
								}
#line 3050 "y.tab.c"
    break;

  case 180: /* relational_expression: nb_relational_expression '<' nb_shift_expression  */
#line 1044 "compiler_rules_actions.y"
                                                                {
									if(((yyvsp[-2].sym)->t).tname != TCHAR || ((yyvsp[0].sym)->t).tname != TCHAR) typecheck((yyvsp[-2].sym), (yyvsp[0].sym));

									emit("", (yyvsp[-2].sym)->getname(), IFLessGOTO, (yyvsp[0].sym)->getname());
									(yyval.sym) = new symbol(TBOOL);
									(yyval.sym)->tl = makelist(currAddr());
									emit("",GTO);
									(yyval.sym)->fl = makelist(currAddr());
									(yyval.sym)->t = type(TBOOL);
								}
#line 3065 "y.tab.c"
    break;

  case 181: /* relational_expression: nb_relational_expression '>' nb_shift_expression  */
#line 1055 "compiler_rules_actions.y"
                                                                {
									if(((yyvsp[-2].sym)->t).tname != TCHAR || ((yyvsp[0].sym)->t).tname != TCHAR) typecheck((yyvsp[-2].sym), (yyvsp[0].sym));

									emit("", (yyvsp[-2].sym)->getname(), IFGrtGOTO, (yyvsp[0].sym)->getname());
									(yyval.sym) = new symbol(TBOOL);
									(yyval.sym)->tl = makelist(currAddr());
									emit("",GTO);
									(yyval.sym)->fl = makelist(currAddr());
									(yyval.sym)->t = type(TBOOL);
								}
#line 3080 "y.tab.c"
    break;

  case 182: /* relational_expression: nb_relational_expression LTE nb_shift_expression  */
#line 1066 "compiler_rules_actions.y"
                                                                {
									if(((yyvsp[-2].sym)->t).tname != TCHAR || ((yyvsp[0].sym)->t).tname != TCHAR) typecheck((yyvsp[-2].sym), (yyvsp[0].sym));

									emit("", (yyvsp[-2].sym)->getname(), IFLessEqGOTO, (yyvsp[0].sym)->getname());
									(yyval.sym) = new symbol(TBOOL);
									(yyval.sym)->tl = makelist(currAddr());
									emit("",GTO);
									(yyval.sym)->fl = makelist(currAddr());
									(yyval.sym)->t = type(TBOOL);
								}
#line 3095 "y.tab.c"
    break;

  case 183: /* relational_expression: nb_relational_expression GTE nb_shift_expression  */
#line 1077 "compiler_rules_actions.y"
                                                                {
									if(((yyvsp[-2].sym)->t).tname != TCHAR || ((yyvsp[0].sym)->t).tname != TCHAR) typecheck((yyvsp[-2].sym), (yyvsp[0].sym));

									emit("", (yyvsp[-2].sym)->getname(), IFGrtEqGOTO, (yyvsp[0].sym)->getname());
									(yyval.sym) = new symbol(TBOOL);
									(yyval.sym)->tl = makelist(currAddr());
									emit("",GTO);
									(yyval.sym)->fl = makelist(currAddr());
									(yyval.sym)->t = type(TBOOL);
								}
#line 3110 "y.tab.c"
    break;

  case 184: /* nb_relational_expression: relational_expression  */
#line 1090 "compiler_rules_actions.y"
                                                                {
									/* This augmentation helps in inplace conversion from bool to int.
									 Calling the convBoolInt() function from some other place can cause the intermediate
									 instructions to get skipped due to the gotos of the conversion */
									/* This augmentation has usage in the arithmetic operations, which require the operands
									to be of non-boolean type */

									convBoolInt((yyvsp[0].sym));
									(yyval.sym) = (yyvsp[0].sym);
								}
#line 3125 "y.tab.c"
    break;

  case 186: /* equality_expression: nb_equality_expression EQUAL nb_relational_expression  */
#line 1104 "compiler_rules_actions.y"
                                                                {
									if(((yyvsp[-2].sym)->t).tname != TCHAR || ((yyvsp[0].sym)->t).tname != TCHAR) typecheck((yyvsp[-2].sym), (yyvsp[0].sym));

									emit("", (yyvsp[-2].sym)->getname(), IFLogEqGOTO, (yyvsp[0].sym)->getname());
									(yyval.sym) = new symbol(TBOOL);
									(yyval.sym)->tl = makelist(currAddr());
									emit("",GTO);
									(yyval.sym)->fl = makelist(currAddr());
									(yyval.sym)->t = type(TBOOL);
								}
#line 3140 "y.tab.c"
    break;

  case 187: /* equality_expression: nb_equality_expression NEQUAL nb_relational_expression  */
#line 1115 "compiler_rules_actions.y"
                                                                {
									if(((yyvsp[-2].sym)->t).tname != TCHAR || ((yyvsp[0].sym)->t).tname != TCHAR) typecheck((yyvsp[-2].sym), (yyvsp[0].sym));

									emit("", (yyvsp[-2].sym)->getname(), IFNotEqGOTO, (yyvsp[0].sym)->getname());
									(yyval.sym) = new symbol(TBOOL);
									(yyval.sym)->tl = makelist(currAddr());
									emit("",GTO);
									(yyval.sym)->fl = makelist(currAddr());
									(yyval.sym)->t = type(TBOOL);
								}
#line 3155 "y.tab.c"
    break;

  case 188: /* nb_equality_expression: equality_expression  */
#line 1128 "compiler_rules_actions.y"
                                                                {
									/* This augmentation helps in inplace conversion from bool to int.
									 Calling the convBoolInt() function from some other place can cause the intermediate
									 instructions to get skipped due to the gotos of the conversion */
									/* This augmentation has usage in the arithmetic operations, which require the operands
									to be of non-boolean type */

									convBoolInt((yyvsp[0].sym));
									(yyval.sym) = (yyvsp[0].sym);
								}
#line 3170 "y.tab.c"
    break;

  case 190: /* and_expression: nb_and_expression '&' nb_equality_expression  */
#line 1141 "compiler_rules_actions.y"
                                                                {
									convBoolInt((yyvsp[-2].sym));
									convBoolInt((yyvsp[0].sym));
									convDblInt((yyvsp[-2].sym));
									convDblInt((yyvsp[0].sym));
									convCharInt((yyvsp[-2].sym));
									convCharInt((yyvsp[0].sym));

									(yyval.sym) = gentemp(TINT);
									emit((yyval.sym)->getname(), (yyvsp[-2].sym)->getname(), BinAND, (yyvsp[0].sym)->getname());
								}
#line 3186 "y.tab.c"
    break;

  case 191: /* nb_and_expression: and_expression  */
#line 1155 "compiler_rules_actions.y"
                                                                {
									/* This augmentation helps in inplace conversion from bool to int.
									 Calling the convBoolInt() function from some other place can cause the intermediate
									 instructions to get skipped due to the gotos of the conversion */
									/* This augmentation has usage in the arithmetic operations, which require the operands
									to be of non-boolean type */

									convBoolInt((yyvsp[0].sym));
									(yyval.sym) = (yyvsp[0].sym);
								}
#line 3201 "y.tab.c"
    break;

  case 193: /* exclusive_or_expression: nb_exclusive_or_expression '^' nb_and_expression  */
#line 1169 "compiler_rules_actions.y"
                                                                {
									convBoolInt((yyvsp[-2].sym));
									convBoolInt((yyvsp[0].sym));
									convDblInt((yyvsp[-2].sym));
									convDblInt((yyvsp[0].sym));
									convCharInt((yyvsp[-2].sym));
									convCharInt((yyvsp[0].sym));

									(yyval.sym) = gentemp(TINT);
									emit((yyval.sym)->getname(), (yyvsp[-2].sym)->getname(), BinXOR, (yyvsp[0].sym)->getname());
								}
#line 3217 "y.tab.c"
    break;

  case 194: /* nb_exclusive_or_expression: exclusive_or_expression  */
#line 1183 "compiler_rules_actions.y"
                                                                {
									/* This augmentation helps in inplace conversion from bool to int.
									 Calling the convBoolInt() function from some other place can cause the intermediate
									 instructions to get skipped due to the gotos of the conversion */
									/* This augmentation has usage in the arithmetic operations, which require the operands
									to be of non-boolean type */

									convBoolInt((yyvsp[0].sym));
									(yyval.sym) = (yyvsp[0].sym);
								}
#line 3232 "y.tab.c"
    break;

  case 196: /* inclusive_or_expression: nb_inclusive_or_expression '|' nb_exclusive_or_expression  */
#line 1197 "compiler_rules_actions.y"
                                                                {
									convBoolInt((yyvsp[-2].sym));
									convBoolInt((yyvsp[0].sym));
									convDblInt((yyvsp[-2].sym));
									convDblInt((yyvsp[0].sym));
									convCharInt((yyvsp[-2].sym));
									convCharInt((yyvsp[0].sym));

									(yyval.sym) = gentemp(TINT);
									emit((yyval.sym)->getname(), (yyvsp[-2].sym)->getname(), BinOR, (yyvsp[0].sym)->getname());
								}
#line 3248 "y.tab.c"
    break;

  case 197: /* nb_inclusive_or_expression: inclusive_or_expression  */
#line 1211 "compiler_rules_actions.y"
                                                                {
									/* This augmentation helps in inplace conversion from bool to int.
									 Calling the convBoolInt() function from some other place can cause the intermediate
									 instructions to get skipped due to the gotos of the conversion */
									/* This augmentation has usage in the arithmetic operations, which require the operands
									to be of non-boolean type */

									convBoolInt((yyvsp[0].sym));
									(yyval.sym) = (yyvsp[0].sym);
								}
#line 3263 "y.tab.c"
    break;

  case 199: /* logical_and_expression: bool_logical_and_expression LogAND address_nonterm bool_inclusive_or_expression  */
#line 1225 "compiler_rules_actions.y"
                                                                {
									/* The address_nonterm nonterminal has been provided to backpatch the truelists
									and falselists of the boolean expression.
									Such backpatching helps in efficient conversion of boolean functions to 3 address
									codes
									*/

									(yyval.sym) = new symbol(TBOOL);
									backpatch((yyvsp[-3].sym)->tl, (yyvsp[-1].add));
									(yyval.sym)->tl = (yyvsp[0].sym)->tl;
									(yyval.sym)->fl = mergelist((yyvsp[-3].sym)->fl, (yyvsp[0].sym)->fl);
								}
#line 3280 "y.tab.c"
    break;

  case 201: /* logical_or_expression: bool_logical_or_expression LogOR address_nonterm bool_logical_and_expression  */
#line 1242 "compiler_rules_actions.y"
                                                                {
									/* The address_nonterm nonterminal has been provided to backpatch the truelists
									and falselists of the boolean expression.
									Such backpatching helps in efficient conversion of boolean functions to 3 address
									codes
									*/

									(yyval.sym) = new symbol(TBOOL);
									backpatch((yyvsp[-3].sym)->fl, (yyvsp[-1].add));
									(yyval.sym)->fl = (yyvsp[0].sym)->fl;
									(yyval.sym)->tl = mergelist((yyvsp[-3].sym)->tl, (yyvsp[0].sym)->tl);
								}
#line 3297 "y.tab.c"
    break;

  case 202: /* bool_inclusive_or_expression: inclusive_or_expression  */
#line 1258 "compiler_rules_actions.y"
                                                                {
									/* This augmentation helps in inplace conversion from int or double to bool.
									 Calling the convIntBool() function from some other place can cause the intermediate
									 instructions to get skipped due to the gotos of the conversion */
									/* This augmentation has usage in the arithmetic operations, which require the operands
									to be of boolean type */

									convDblInt((yyvsp[0].sym));
									convCharInt((yyvsp[0].sym));
									convIntBool((yyvsp[0].sym));
									(yyval.sym) = (yyvsp[0].sym);
								}
#line 3314 "y.tab.c"
    break;

  case 203: /* bool_logical_or_expression: logical_or_expression  */
#line 1273 "compiler_rules_actions.y"
                                                                {
									/* This augmentation helps in inplace conversion from int or double to bool.
									 Calling the convIntBool() function from some other place can cause the intermediate
									 instructions to get skipped due to the gotos of the conversion */
									/* This augmentation has usage in the arithmetic operations, which require the operands
									to be of boolean type */

									convDblInt((yyvsp[0].sym));
									convCharInt((yyvsp[0].sym));
									convIntBool((yyvsp[0].sym));
									(yyval.sym) = (yyvsp[0].sym);
								}
#line 3331 "y.tab.c"
    break;

  case 204: /* bool_logical_and_expression: logical_and_expression  */
#line 1288 "compiler_rules_actions.y"
                                                                {
									/* This augmentation helps in inplace conversion from int or double to bool.
									 Calling the convIntBool() function from some other place can cause the intermediate
									 instructions to get skipped due to the gotos of the conversion */
									/* This augmentation has usage in the arithmetic operations, which require the operands
									to be of boolean type */

									convDblInt((yyvsp[0].sym));
									convCharInt((yyvsp[0].sym));
									convIntBool((yyvsp[0].sym));
									(yyval.sym) = (yyvsp[0].sym);
								}
#line 3348 "y.tab.c"
    break;

  case 206: /* conditional_expression: bool_logical_or_expression '?' address_nonterm expression jump_nonterm ':' address_nonterm conditional_expression jump_nonterm  */
#line 1305 "compiler_rules_actions.y"
                                                                {
									/* Suitable non terminals with empty transitions have been put to place jumps at proper
									places to compute the function */

									backpatch((yyvsp[-8].sym)->tl, (yyvsp[-6].add));
									backpatch((yyvsp[-8].sym)->fl, (yyvsp[-2].add));
									typecheck((yyvsp[-5].sym), (yyvsp[-1].sym));
									(yyval.sym) = gentemp(((yyvsp[-5].sym)->t).tname);
									emit((yyval.sym)->getname(), EQ, (yyvsp[-5].sym)->getname());
									backpatch((yyvsp[-4].nl)->l, currAddr());
									emit("", GTO);
									List li = List(currAddr());
									emit((yyval.sym)->getname(), EQ, (yyvsp[-1].sym)->getname());
									backpatch((yyvsp[0].nl)->l, currAddr());
									backpatch(li, currAddr()+1);
								}
#line 3369 "y.tab.c"
    break;

  case 208: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 1325 "compiler_rules_actions.y"
                                                                {
									convBoolInt((yyvsp[0].sym));
									typeconv((yyvsp[0].sym),(yyvsp[-2].sym));
									if((yyvsp[-2].sym)->arr != 0)
									{
										emit((yyvsp[-2].sym)->getname(), (yyvsp[-2].sym)->getoffset(), ARREQ, (yyvsp[0].sym)->getname());
									}
									else emit((yyvsp[-2].sym)->getname(), EQ, (yyvsp[0].sym)->getname());
									(yyval.sym) = (yyvsp[-2].sym);
								}
#line 3384 "y.tab.c"
    break;

  case 223: /* address_nonterm: %empty  */
#line 1362 "compiler_rules_actions.y"
                                                                {
									(yyval.add) = currAddr()+1;
								}
#line 3392 "y.tab.c"
    break;

  case 224: /* jump_nonterm: %empty  */
#line 1368 "compiler_rules_actions.y"
                                                                {
									/* Emits a goto required for certain control statements */
									emit("", GTO);
									(yyval.nl) = new nextlist();
									(yyval.nl)->l = makelist(currAddr());
								}
#line 3403 "y.tab.c"
    break;


#line 3407 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1382 "compiler_rules_actions.y"



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
