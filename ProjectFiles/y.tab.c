
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */


/* Line 189 of yacc.c  */
#line 73 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     OCBRACKET = 258,
     CCBRACKET = 259,
     ORBRACKET = 260,
     CRBRACKET = 261,
     SEMICOLON = 262,
     COLON = 263,
     COMMA = 264,
     PLUSEQUAL = 265,
     MINUSEQUAL = 266,
     MULTIPLYEQUAL = 267,
     DIVIDEEQUAL = 268,
     INC = 269,
     DEC = 270,
     GREATERTHAN = 271,
     LESSTHAN = 272,
     GREATERTHANOREQUAL = 273,
     LESSTHANOREQUAL = 274,
     EQUALEQUAL = 275,
     NOTEQUAL = 276,
     PLUS = 277,
     MINUS = 278,
     MULTIPLY = 279,
     DIVIDE = 280,
     ASSIGN = 281,
     REM = 282,
     AND = 283,
     OR = 284,
     NOT = 285,
     WHILE = 286,
     DO = 287,
     FOR = 288,
     IF = 289,
     ELSE = 290,
     PRINT = 291,
     BOOL = 292,
     INT = 293,
     FLOAT = 294,
     CHAR = 295,
     STRING = 296,
     CONST = 297,
     BREAK = 298,
     SWITCH = 299,
     CASE = 300,
     FALSE = 301,
     TRUE = 302,
     RETURN = 303,
     DEFAULT = 304,
     EXIT = 305,
     IFX = 306,
     UMINUS = 307,
     INTEGER = 308,
     FLOATNUMBER = 309,
     TEXT = 310,
     CHARACTER = 311,
     IDENTIFIER = 312
   };
#endif
/* Tokens.  */
#define OCBRACKET 258
#define CCBRACKET 259
#define ORBRACKET 260
#define CRBRACKET 261
#define SEMICOLON 262
#define COLON 263
#define COMMA 264
#define PLUSEQUAL 265
#define MINUSEQUAL 266
#define MULTIPLYEQUAL 267
#define DIVIDEEQUAL 268
#define INC 269
#define DEC 270
#define GREATERTHAN 271
#define LESSTHAN 272
#define GREATERTHANOREQUAL 273
#define LESSTHANOREQUAL 274
#define EQUALEQUAL 275
#define NOTEQUAL 276
#define PLUS 277
#define MINUS 278
#define MULTIPLY 279
#define DIVIDE 280
#define ASSIGN 281
#define REM 282
#define AND 283
#define OR 284
#define NOT 285
#define WHILE 286
#define DO 287
#define FOR 288
#define IF 289
#define ELSE 290
#define PRINT 291
#define BOOL 292
#define INT 293
#define FLOAT 294
#define CHAR 295
#define STRING 296
#define CONST 297
#define BREAK 298
#define SWITCH 299
#define CASE 300
#define FALSE 301
#define TRUE 302
#define RETURN 303
#define DEFAULT 304
#define EXIT 305
#define IFX 306
#define UMINUS 307
#define INTEGER 308
#define FLOATNUMBER 309
#define TEXT 310
#define CHARACTER 311
#define IDENTIFIER 312




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 102 "mylang.y"

    int IntgerValue;                 /* integer value */
	float FloatValue;               /* float Value */
    char * StringValue;              /* string value */
	char * ChValue;               /* character value */
	char * ID ;                    /*IDENTIFIER Value */
	int* dummy;



/* Line 214 of yacc.c  */
#line 234 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */

/* Line 264 of yacc.c  */
#line 119 "mylang.y"
 
	#include <stdio.h>
	#include <stdlib.h>
	#include <stdarg.h>
	#include <string.h>	
	#include"SymbolTable.h"
	int yyerror(char *);
	int yylex(void);
	int yylineno;
	int IDCount=0;
	int QuadCount=0;
	int SCOPE_Number=0;
	FILE * outFile;
	FILE * inFile;
	FILE *outSymbol;
	void ThrowError(char *Message, char *rVar);							//--  A Function to Terminate the Program and Report an Semantic Error
	void CreateID(int type , char*rName,int rID,int ScopeNum);			// -- Create a Symbol given its type and Name 
	void  getIDENTIFIER(char*rName,int ScopeNum);						//--  set Symbol Value to be Initilized. 
	void usedIDENTIFIER(char*rName,int ScopeNum );					    //--  set that Symbol is Used as a RHS in any operation 
	char * conctanteStr(char* str1,char*str2);							//--  a function to conctante two strings 
	bool checktypeIDENTIFER(int LeftType,int RightType,char* Right);	//--  Check Left and Right hand side in Assigment operation;
	char* idtypeString[10] = { "Integer", "Float", "Char", "String", "Bool", "ConstIntger", "ConstFloat", "ConstChar", "ConstString", "ConstBool" };
	int FuncArgTypes[10];												//Assuming Max 10 arguments 
	int ArgCounter=0;													//Argument Counter
	void CreateFunction(int type , char*rName,int rID,int ScopeNum,int rArgCounter,int *ArrOfTypes); // Create a Symbol For a Function
	char*RightHandSide[2];
	int RightCount=0;
	

/* Line 264 of yacc.c  */
#line 276 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   300

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNRULES -- Number of states.  */
#define YYNSTATES  187

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   312

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      55,    56,    57
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    13,    18,    24,    31,
      37,    45,    58,    64,    72,    78,    82,    84,    86,    90,
      95,    97,   100,   102,   117,   124,   128,   130,   131,   132,
     137,   140,   141,   147,   152,   158,   159,   160,   162,   165,
     167,   169,   171,   173,   175,   177,   179,   181,   185,   189,
     193,   197,   201,   204,   207,   211,   214,   217,   221,   225,
     229,   233,   235,   239,   243,   247,   250,   254,   258,   262,
     266,   270,   274,   278,   280,   282,   284,   286,   288,   290,
     292,   298,   306
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      59,     0,    -1,    60,    -1,    60,    61,    -1,    -1,    73,
      57,     7,    -1,    57,    26,    79,     7,    -1,    73,    57,
      26,    79,     7,    -1,    42,    73,    57,    26,    79,     7,
      -1,    31,     5,    79,     6,    61,    -1,    32,    68,    31,
       5,    79,     6,     7,    -1,    33,     5,    38,    62,    26,
      53,     7,    79,     7,    76,     6,    68,    -1,    34,     5,
      79,     6,    68,    -1,    34,     5,    79,     6,    68,    35,
      68,    -1,    44,     5,    57,     6,    69,    -1,    36,    79,
       7,    -1,    63,    -1,    64,    -1,    57,    26,    64,    -1,
      73,    57,    26,    64,    -1,    68,    -1,    75,     7,    -1,
      57,    -1,    73,    57,     5,    66,    67,     6,     3,    70,
      72,    48,    79,     7,     4,    71,    -1,    57,     5,    66,
      65,     6,     7,    -1,    57,     9,    65,    -1,    57,    -1,
      -1,    -1,    73,    57,     9,    67,    -1,    73,    57,    -1,
      -1,     3,    70,    72,     4,    71,    -1,     3,    70,     4,
      71,    -1,     3,    70,    80,     4,    71,    -1,    -1,    -1,
      61,    -1,    72,    61,    -1,    38,    -1,    39,    -1,    40,
      -1,    41,    -1,    37,    -1,    54,    -1,    53,    -1,    57,
      -1,    74,    22,    74,    -1,    74,    23,    74,    -1,    74,
      24,    74,    -1,    74,    25,    74,    -1,    74,    27,    74,
      -1,    57,    14,    -1,    57,    15,    -1,     5,    74,     6,
      -1,    57,    14,    -1,    57,    15,    -1,    57,    10,    74,
      -1,    57,    11,    74,    -1,    57,    12,    74,    -1,    57,
      13,    74,    -1,    75,    -1,    57,    26,    74,    -1,    79,
      28,    79,    -1,    79,    29,    79,    -1,    30,    79,    -1,
      78,    16,    78,    -1,    78,    17,    78,    -1,    78,    18,
      78,    -1,    78,    19,    78,    -1,    78,    21,    78,    -1,
      78,    20,    78,    -1,     5,    77,     6,    -1,    74,    -1,
      56,    -1,    46,    -1,    47,    -1,    55,    -1,    78,    -1,
      77,    -1,    49,     8,    72,    43,     7,    -1,    45,    53,
       8,    72,    43,     7,    80,    -1,    45,    53,     8,    72,
      80,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   152,   152,   155,   156,   159,   166,   184,   202,   219,
     221,   223,   229,   231,   233,   236,   238,   239,   240,   254,
     272,   273,   276,   277,   292,   311,   312,   313,   315,   316,
     317,   318,   323,   324,   327,   329,   330,   331,   332,   334,
     335,   336,   337,   338,   341,   348,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   365,   366,   367,   368,   369,
     370,   374,   375,   377,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   389,   390,   391,   392,   393,   399,   400,
     402,   403,   404
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "OCBRACKET", "CCBRACKET", "ORBRACKET",
  "CRBRACKET", "SEMICOLON", "COLON", "COMMA", "PLUSEQUAL", "MINUSEQUAL",
  "MULTIPLYEQUAL", "DIVIDEEQUAL", "INC", "DEC", "GREATERTHAN", "LESSTHAN",
  "GREATERTHANOREQUAL", "LESSTHANOREQUAL", "EQUALEQUAL", "NOTEQUAL",
  "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "ASSIGN", "REM", "AND", "OR",
  "NOT", "WHILE", "DO", "FOR", "IF", "ELSE", "PRINT", "BOOL", "INT",
  "FLOAT", "CHAR", "STRING", "CONST", "BREAK", "SWITCH", "CASE", "FALSE",
  "TRUE", "RETURN", "DEFAULT", "EXIT", "IFX", "UMINUS", "INTEGER",
  "FLOATNUMBER", "TEXT", "CHARACTER", "IDENTIFIER", "$accept", "mystart",
  "startProgram", "stmt", "create", "function", "callFunction", "callList",
  "resetCounter", "argList", "blockScope", "switchScope", "scopeOpen",
  "scopeClose", "manyStatements", "type", "equalFamily", "increments",
  "forExpression", "booleanExpression", "DataTypes", "expression",
  "caseExpression", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    60,    60,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    62,    63,    64,    65,    65,    65,    66,    67,
      67,    67,    68,    68,    69,    70,    71,    72,    72,    73,
      73,    73,    73,    73,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    75,    75,    75,    75,    75,
      75,    76,    76,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    78,    78,    78,    78,    78,    79,    79,
      80,    80,    80
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     4,     5,     6,     5,
       7,    12,     5,     7,     5,     3,     1,     1,     3,     4,
       1,     2,     1,    14,     6,     3,     1,     0,     0,     4,
       2,     0,     5,     4,     5,     0,     0,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     2,     2,     3,     2,     2,     3,     3,     3,
       3,     1,     3,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       5,     7,     5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,    35,     0,     0,     0,     0,     0,
      43,    39,    40,    41,    42,     0,     0,     0,     3,    16,
      17,    20,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    75,    76,    45,    44,    77,    74,    46,    73,    79,
      78,     0,     0,     0,    28,     0,     0,     0,     0,    55,
      56,     0,     0,    21,    36,    37,     0,     0,     0,     0,
       0,    73,    79,     0,    65,    52,    53,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    15,     0,
       0,     0,     0,    27,     0,    57,    58,    59,    60,    46,
      18,     0,    28,     5,     0,    33,    36,    38,     0,     0,
      22,     0,     0,    54,    72,    47,    48,    49,    50,    51,
      66,    67,    68,    69,    71,    70,    63,    64,     0,     0,
      26,     0,     0,     6,    31,    19,     0,    32,     9,     0,
       0,    12,     0,    35,    14,    27,     0,     0,     0,     7,
       0,     0,     0,     8,     0,    25,    24,     0,    30,    10,
       0,    13,     0,     0,     0,    35,    31,     0,     0,     0,
      36,     0,    29,     0,     0,     0,    34,     0,     0,    61,
       0,     0,     0,     0,     0,     0,     0,    82,    80,     0,
      62,    11,     0,     0,    81,    36,    23
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    55,   101,    19,    20,   121,    83,   137,
      21,   134,    24,    95,    56,    22,    38,    23,   170,    39,
      40,    41,   154
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -160
static const yytype_int16 yypact[] =
{
    -160,    16,   221,  -160,  -160,    13,    50,    19,    45,    33,
    -160,  -160,  -160,  -160,  -160,   259,    86,   181,  -160,  -160,
    -160,  -160,    35,    48,    28,    33,    68,    69,    33,    33,
      33,  -160,  -160,  -160,  -160,  -160,  -160,    15,   268,  -160,
     267,    18,    49,    75,  -160,    21,    21,    21,    21,  -160,
    -160,    47,   116,  -160,  -160,  -160,    78,     5,   120,    79,
       7,   195,   135,    55,  -160,  -160,  -160,    21,    21,    21,
      21,    21,   100,   100,   100,   100,   100,   100,  -160,    33,
      33,   113,   138,    92,    21,   268,   268,   268,   268,   119,
    -160,    20,  -160,  -160,    47,  -160,  -160,  -160,   221,    33,
    -160,   125,    50,  -160,  -160,   201,   201,  -160,  -160,  -160,
    -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,    33,   149,
     155,   152,   195,  -160,   259,  -160,   101,  -160,  -160,    11,
     114,   163,   131,  -160,  -160,    92,   161,   184,   142,  -160,
     193,   214,    50,  -160,   -35,  -160,  -160,   220,   218,  -160,
      33,  -160,   189,   226,   240,  -160,   259,   133,   237,   221,
    -160,   221,  -160,   191,   221,   172,  -160,   199,   256,  -160,
     243,   140,   239,    33,    21,    50,   244,  -160,  -160,   159,
     268,  -160,   -35,   246,  -160,  -160,  -160
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -160,  -160,  -160,    -2,  -160,  -160,   -43,   129,   187,   124,
      -5,  -160,  -118,   -87,   -33,   -11,   -26,   118,  -160,   260,
     200,   -23,  -159
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      18,    26,    57,    61,    42,    60,    63,    64,    90,   127,
     152,    98,   177,   102,   153,   144,     3,   140,    25,    85,
      86,    87,    88,   184,    27,    78,    84,   123,    91,    65,
      66,     4,    54,    79,    80,    79,    80,   161,    29,    79,
      80,   105,   106,   107,   108,   109,    79,    80,    79,    80,
      28,   125,    29,     4,    97,    53,   116,   117,   122,     5,
       6,     7,     8,    30,     9,    10,    11,    12,    13,    14,
      15,   126,    16,   166,    33,    34,   129,    30,    37,    31,
      32,     4,    96,    79,    80,    17,    33,    34,    35,    36,
      37,    43,    52,    31,    32,   132,   128,   131,   186,    58,
      33,    34,    35,    36,    89,    84,    81,    59,   139,     5,
       6,     7,     8,   138,     9,    10,    11,    12,    13,    14,
      15,    92,    16,    93,    44,    99,   165,   157,   167,    79,
      80,   171,    82,    65,    66,    17,   100,   151,   143,   118,
     163,   104,    94,     4,   119,   138,    31,    32,   180,   120,
     179,   130,   133,    33,    34,    35,    36,    37,   136,    79,
      80,    79,    80,    97,   135,    97,   183,   141,   146,    97,
     181,     5,     6,     7,     8,     4,     9,    10,    11,    12,
      13,    14,    15,   176,    16,   152,    44,    79,    80,   153,
     147,    45,    46,    47,    48,    49,    50,    17,   142,   148,
     149,   103,     4,     5,     6,     7,     8,    51,     9,    10,
      11,    12,    13,    14,    15,   172,    16,    67,    68,    69,
      70,   150,    71,   155,     4,    69,    70,   156,    71,    17,
       5,     6,     7,     8,   159,     9,    10,    11,    12,    13,
      14,    15,   158,    16,   160,   164,   178,   173,   168,   175,
     185,   182,     5,     6,     7,     8,    17,     9,    10,    11,
      12,    13,    14,    15,   145,    16,    45,    46,    47,    48,
      49,    50,   110,   111,   112,   113,   114,   115,    17,   124,
     162,   169,   174,    72,    73,    74,    75,    76,    77,    62,
      67,    68,    69,    70,     0,    71,    10,    11,    12,    13,
      14
};

static const yytype_int16 yycheck[] =
{
       2,     6,    25,    29,    15,    28,    29,    30,    51,    96,
      45,     6,   171,     6,    49,   133,     0,     6,     5,    45,
      46,    47,    48,   182,     5,     7,     5,     7,    51,    14,
      15,     3,     4,    28,    29,    28,    29,   155,     5,    28,
      29,    67,    68,    69,    70,    71,    28,    29,    28,    29,
       5,    94,     5,     3,    56,     7,    79,    80,    84,    31,
      32,    33,    34,    30,    36,    37,    38,    39,    40,    41,
      42,    94,    44,   160,    53,    54,    99,    30,    57,    46,
      47,     3,     4,    28,    29,    57,    53,    54,    55,    56,
      57,     5,    57,    46,    47,   118,    98,   102,   185,    31,
      53,    54,    55,    56,    57,     5,    57,    38,     7,    31,
      32,    33,    34,   124,    36,    37,    38,    39,    40,    41,
      42,     5,    44,     7,     5,     5,   159,   150,   161,    28,
      29,   164,    57,    14,    15,    57,    57,   142,     7,    26,
       7,     6,    26,     3,     6,   156,    46,    47,   174,    57,
     173,    26,     3,    53,    54,    55,    56,    57,     6,    28,
      29,    28,    29,   165,     9,   167,     7,    53,     7,   171,
     175,    31,    32,    33,    34,     3,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,     5,    28,    29,    49,
       6,    10,    11,    12,    13,    14,    15,    57,    35,    57,
       7,     6,     3,    31,    32,    33,    34,    26,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    22,    23,    24,
      25,     7,    27,     3,     3,    24,    25,     9,    27,    57,
      31,    32,    33,    34,     8,    36,    37,    38,    39,    40,
      41,    42,    53,    44,     4,     8,     7,    48,    57,     6,
       4,     7,    31,    32,    33,    34,    57,    36,    37,    38,
      39,    40,    41,    42,   135,    44,    10,    11,    12,    13,
      14,    15,    72,    73,    74,    75,    76,    77,    57,    92,
     156,   163,    26,    16,    17,    18,    19,    20,    21,    29,
      22,    23,    24,    25,    -1,    27,    37,    38,    39,    40,
      41
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    59,    60,     0,     3,    31,    32,    33,    34,    36,
      37,    38,    39,    40,    41,    42,    44,    57,    61,    63,
      64,    68,    73,    75,    70,     5,    68,     5,     5,     5,
      30,    46,    47,    53,    54,    55,    56,    57,    74,    77,
      78,    79,    73,     5,     5,    10,    11,    12,    13,    14,
      15,    26,    57,     7,     4,    61,    72,    79,    31,    38,
      79,    74,    77,    79,    79,    14,    15,    22,    23,    24,
      25,    27,    16,    17,    18,    19,    20,    21,     7,    28,
      29,    57,    57,    66,     5,    74,    74,    74,    74,    57,
      64,    79,     5,     7,    26,    71,     4,    61,     6,     5,
      57,    62,     6,     6,     6,    74,    74,    74,    74,    74,
      78,    78,    78,    78,    78,    78,    79,    79,    26,     6,
      57,    65,    74,     7,    66,    64,    79,    71,    61,    79,
      26,    68,    79,     3,    69,     9,     6,    67,    73,     7,
       6,    53,    35,     7,    70,    65,     7,     6,    57,     7,
       7,    68,    45,    49,    80,     3,     9,    79,    53,     8,
       4,    70,    67,     7,     8,    72,    71,    72,    57,    75,
      76,    72,    43,    48,    26,     6,    43,    80,     7,    79,
      74,    68,     7,     7,    80,     4,    71
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 5:

/* Line 1455 of yacc.c  */
#line 159 "mylang.y"
    {
																				(yyval.dummy)=NULL;
																				CreateID((yyvsp[(1) - (3)].IntgerValue),(yyvsp[(2) - (3)].ID),IDCount++,SCOPE_Number);
																				printf("Declaration\n");
																				setQuad(0," "," ",(yyvsp[(2) - (3)].ID),QuadCount++);
																			}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 166 "mylang.y"
    {
																				(yyval.dummy)=NULL;
																			
																			if(checktypeIDENTIFER(getSymbolType((yyvsp[(1) - (4)].ID)),(yyvsp[(3) - (4)].IntgerValue),(yyvsp[(1) - (4)].ID)))
																				{
																					getIDENTIFIER((yyvsp[(1) - (4)].ID),SCOPE_Number);
																					printf("Assignment\n");
																					setQuad(1,RightHandSide[0]," ",(yyvsp[(1) - (4)].ID),QuadCount++);
																				}
																			else 
																				{
																					char*str1=conctanteStr((yyvsp[(1) - (4)].ID)," of Type");
																					char* str2=conctanteStr(str1,idtypeString[getSymbolType((yyvsp[(1) - (4)].ID))]);
																			
																				ThrowError("Error: incompatible types ",str2);
																				}
																			}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 184 "mylang.y"
    {
																			(yyval.dummy)=NULL;
																			printf("%d ID  %d   expression\n",(yyvsp[(1) - (5)].IntgerValue),(yyvsp[(4) - (5)].IntgerValue));
																			CreateID((yyvsp[(1) - (5)].IntgerValue),(yyvsp[(2) - (5)].ID),IDCount++,SCOPE_Number);
																			if(checktypeIDENTIFER(getSymbolType((yyvsp[(2) - (5)].ID)),(yyvsp[(4) - (5)].IntgerValue),(yyvsp[(2) - (5)].ID)))
																			{
																			getIDENTIFIER((yyvsp[(2) - (5)].ID),SCOPE_Number);// setValue here 
																			printf("Declaration and Assignment\n");
																			}
																			else
																				{
																					char*str1=conctanteStr((yyvsp[(2) - (5)].ID)," of Type ");
																					char* str2=conctanteStr(str1,idtypeString[getSymbolType((yyvsp[(2) - (5)].ID))]);
												
																				ThrowError("Error: incompatible types ",str2);
																				}
																			}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 202 "mylang.y"
    {
																				(yyval.dummy)=NULL;
																				CreateID((yyvsp[(2) - (6)].IntgerValue)+5,(yyvsp[(3) - (6)].ID),IDCount++,SCOPE_Number);
																			if(checktypeIDENTIFER(getSymbolType((yyvsp[(3) - (6)].ID)),(yyvsp[(5) - (6)].IntgerValue),(yyvsp[(3) - (6)].ID)))
																			{
																				printf("Constant assignment\n");
																			}
																			else
																				{
																					char*str1=conctanteStr((yyvsp[(3) - (6)].ID)," of Type ");
																					char* str2=conctanteStr(str1,idtypeString[getSymbolType((yyvsp[(3) - (6)].ID))]);
																			
																				ThrowError("Error: incompatible types ",str2);
																				}
																			;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 219 "mylang.y"
    {(yyval.dummy)=NULL;printf("While loop\n");}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 221 "mylang.y"
    {(yyval.dummy)=NULL;printf("Do while\n");}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 226 "mylang.y"
    {(yyval.dummy)=NULL;printf("For loop\n");}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 229 "mylang.y"
    {(yyval.dummy)=NULL;printf("If statement\n");}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 231 "mylang.y"
    {(yyval.dummy)=NULL;printf("If-Elsestatement\n");}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 233 "mylang.y"
    {(yyval.dummy)=NULL;usedIDENTIFIER((yyvsp[(3) - (5)].ID),SCOPE_Number);printf("Switch case\n");}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 236 "mylang.y"
    {(yyval.dummy)=NULL;printf("Print\n");}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 238 "mylang.y"
    {(yyval.dummy)=NULL;printf("Function Body\n");}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 239 "mylang.y"
    {(yyval.dummy)=NULL;printf("Function Call\n");}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 240 "mylang.y"
    {
																				(yyval.dummy)=NULL;
																				if(checktypeIDENTIFER(getSymbolType((yyvsp[(1) - (3)].ID)),(yyvsp[(3) - (3)].IntgerValue),(yyvsp[(1) - (3)].ID)))
																				{
																					getIDENTIFIER((yyvsp[(1) - (3)].ID),SCOPE_Number);
																					printf("Function Call\n");}
																				else 
																				{
																					char*str1=conctanteStr((yyvsp[(1) - (3)].ID)," of Type");
																					char* str2=conctanteStr(str1,idtypeString[getSymbolType((yyvsp[(1) - (3)].ID))]);
																			
																					ThrowError("Error: incompatible types ",str2);
																				}
																			}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 254 "mylang.y"
    {	
																				(yyval.dummy)=NULL;
																				CreateID((yyvsp[(1) - (4)].IntgerValue),(yyvsp[(2) - (4)].ID),IDCount++,SCOPE_Number);
																				if(checktypeIDENTIFER(getSymbolType((yyvsp[(2) - (4)].ID)),(yyvsp[(4) - (4)].IntgerValue),(yyvsp[(2) - (4)].ID)))
																				{
		
																					getIDENTIFIER((yyvsp[(2) - (4)].ID),SCOPE_Number);// setValue here 
																					printf("Function Call\n");
																				}
																				else
																				{
																					char*str1=conctanteStr((yyvsp[(2) - (4)].ID)," of Type ");
																					char* str2=conctanteStr(str1,idtypeString[getSymbolType((yyvsp[(2) - (4)].ID))]);
												
																				ThrowError("Error: incompatible types ",str2);
																				}
																			}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 272 "mylang.y"
    {(yyval.dummy)=NULL;printf("New  block\n");}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 273 "mylang.y"
    {(yyval.dummy)=NULL;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 276 "mylang.y"
    {CreateID(0,(yyvsp[(1) - (1)].ID) ,IDCount++,SCOPE_Number+1);getIDENTIFIER((yyvsp[(1) - (1)].ID),SCOPE_Number);}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 278 "mylang.y"
    {
																																(yyval.dummy)=NULL;
																																if((yyvsp[(1) - (14)].IntgerValue) !=(yyvsp[(11) - (14)].IntgerValue))//check return types 
																																{
																																	ThrowError("Error: incompatible return types of Function ",(yyvsp[(2) - (14)].ID));
																																	ThrowError("Error: incompatible return types of Function ",(yyvsp[(2) - (14)].ID));
																																}
																																else
																																{
																																	CreateFunction((yyvsp[(1) - (14)].IntgerValue),(yyvsp[(2) - (14)].ID),IDCount++,SCOPE_Number,ArgCounter,FuncArgTypes);
																																	printf("function\n");
																																}
																															}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 293 "mylang.y"
    {
																	(yyval.IntgerValue)=getSymbolType((yyvsp[(1) - (6)].ID));
																	int num =checkArgType(ArgCounter,FuncArgTypes,(yyvsp[(1) - (6)].ID),SCOPE_Number);
																	if(num==-25)
																	{
																		ThrowError("Error: undefined Function With Name ",(yyvsp[(1) - (6)].ID));
																	}
																	else if(num== 0)
																	{
																		ThrowError("Error: mismatch argument number of function ",(yyvsp[(1) - (6)].ID));
																	}
																	else if(num ==-1)
																	{
																		ThrowError("Error: incompatible types of Function ",(yyvsp[(1) - (6)].ID));
																	}
																}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 311 "mylang.y"
    {usedIDENTIFIER((yyvsp[(1) - (3)].ID),SCOPE_Number); FuncArgTypes[ArgCounter++]=getSymbolType((yyvsp[(1) - (3)].ID));}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 312 "mylang.y"
    {usedIDENTIFIER((yyvsp[(1) - (1)].ID),SCOPE_Number);  FuncArgTypes[ArgCounter++]=getSymbolType((yyvsp[(1) - (1)].ID));}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 315 "mylang.y"
    {ArgCounter=0;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 316 "mylang.y"
    {CreateID((yyvsp[(1) - (4)].IntgerValue),(yyvsp[(2) - (4)].ID),IDCount++,SCOPE_Number+1); FuncArgTypes[ArgCounter++]=(yyvsp[(1) - (4)].IntgerValue);}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 317 "mylang.y"
    {CreateID((yyvsp[(1) - (2)].IntgerValue),(yyvsp[(2) - (2)].ID),IDCount++,SCOPE_Number+1); FuncArgTypes[ArgCounter++]=(yyvsp[(1) - (2)].IntgerValue);}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 323 "mylang.y"
    {(yyval.dummy)=NULL;printf("blockScope\n");}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 324 "mylang.y"
    {(yyval.dummy)=NULL;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 327 "mylang.y"
    {printf("Switch Case block\n");}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 329 "mylang.y"
    {(yyval.dummy)=NULL; SCOPE_Number++;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 330 "mylang.y"
    {(yyval.dummy)=NULL;DeadSymbols(SCOPE_Number); SCOPE_Number--;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 331 "mylang.y"
    {(yyval.dummy)=(yyvsp[(1) - (1)].dummy);}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 332 "mylang.y"
    {(yyval.dummy)=NULL;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 334 "mylang.y"
    {(yyval.IntgerValue)=0;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 335 "mylang.y"
    {(yyval.IntgerValue)=1;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 336 "mylang.y"
    {(yyval.IntgerValue)=2;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 337 "mylang.y"
    {(yyval.IntgerValue)=3;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 338 "mylang.y"
    {(yyval.IntgerValue)=4;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 341 "mylang.y"
    {
												(yyval.IntgerValue)=1;
												char c[3] = {};
												//sprintf(c,"%f",$1);
													gcvt((yyvsp[(1) - (1)].FloatValue),6,c);
												RightHandSide[RightCount++]=c;
											   }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 348 "mylang.y"
    {
												(yyval.IntgerValue)=0;
												char c[3] = {}; 
												sprintf(c,"%d",(yyvsp[(1) - (1)].IntgerValue));
												RightHandSide[RightCount++]=c;
											   }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 354 "mylang.y"
    {(yyval.IntgerValue)=getSymbolType((yyvsp[(1) - (1)].ID));usedIDENTIFIER((yyvsp[(1) - (1)].ID),SCOPE_Number);RightHandSide[RightCount++]=(yyvsp[(1) - (1)].ID); }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 355 "mylang.y"
    {if((yyvsp[(1) - (3)].IntgerValue)==(yyvsp[(3) - (3)].IntgerValue)){(yyval.IntgerValue)=(yyvsp[(1) - (3)].IntgerValue); }else ThrowError("Conflict dataTypes in Addition \n "," "); }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 356 "mylang.y"
    {if((yyvsp[(1) - (3)].IntgerValue)==(yyvsp[(3) - (3)].IntgerValue)){(yyval.IntgerValue)=(yyvsp[(1) - (3)].IntgerValue); } else ThrowError("Conflict dataTypes in Subtraction \n "," "); }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 357 "mylang.y"
    {if((yyvsp[(1) - (3)].IntgerValue)==(yyvsp[(3) - (3)].IntgerValue)){(yyval.IntgerValue)=(yyvsp[(1) - (3)].IntgerValue); } else ThrowError("Conflict dataTypes in Multipication \n "," "); }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 358 "mylang.y"
    {if((yyvsp[(1) - (3)].IntgerValue)==(yyvsp[(3) - (3)].IntgerValue)){(yyval.IntgerValue)=(yyvsp[(1) - (3)].IntgerValue); } else ThrowError("Conflict dataTypes in Divison \n "," "); }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 359 "mylang.y"
    {if((yyvsp[(1) - (3)].IntgerValue)==(yyvsp[(3) - (3)].IntgerValue)){(yyval.IntgerValue)=(yyvsp[(1) - (3)].IntgerValue); } else ThrowError("Conflict dataTypes in reminder \n "," "); }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 360 "mylang.y"
    {(yyval.IntgerValue)=getSymbolType((yyvsp[(1) - (2)].ID));usedIDENTIFIER((yyvsp[(1) - (2)].ID),SCOPE_Number);}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 361 "mylang.y"
    {(yyval.IntgerValue)=getSymbolType((yyvsp[(1) - (2)].ID));usedIDENTIFIER((yyvsp[(1) - (2)].ID),SCOPE_Number);}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 362 "mylang.y"
    {(yyval.IntgerValue)=(yyvsp[(2) - (3)].IntgerValue);}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 365 "mylang.y"
    {(yyval.dummy)=NULL;usedIDENTIFIER((yyvsp[(1) - (2)].ID),SCOPE_Number);}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 366 "mylang.y"
    {(yyval.dummy)=NULL;usedIDENTIFIER((yyvsp[(1) - (2)].ID),SCOPE_Number);}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 367 "mylang.y"
    {(yyval.dummy)=NULL;usedIDENTIFIER((yyvsp[(1) - (3)].ID),SCOPE_Number);}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 368 "mylang.y"
    {(yyval.dummy)=NULL;usedIDENTIFIER((yyvsp[(1) - (3)].ID),SCOPE_Number);}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 369 "mylang.y"
    {(yyval.dummy)=NULL;usedIDENTIFIER((yyvsp[(1) - (3)].ID),SCOPE_Number);}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 370 "mylang.y"
    {(yyval.dummy)=NULL;usedIDENTIFIER((yyvsp[(1) - (3)].ID),SCOPE_Number);}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 374 "mylang.y"
    {(yyval.dummy)=NULL;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 375 "mylang.y"
    {(yyval.dummy)=NULL; getIDENTIFIER((yyvsp[(1) - (3)].ID),SCOPE_Number+1);}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 377 "mylang.y"
    {(yyval.dummy)=NULL;if((yyvsp[(1) - (3)].IntgerValue)!=(yyvsp[(3) - (3)].IntgerValue)) ThrowError("Conflict dataTypes in AND Operation \n "," "); }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 378 "mylang.y"
    {(yyval.dummy)=NULL;if((yyvsp[(1) - (3)].IntgerValue)!=(yyvsp[(3) - (3)].IntgerValue)) ThrowError("Conflict dataTypes in OR Operation \n "," "); }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 379 "mylang.y"
    {(yyval.dummy)=NULL;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 380 "mylang.y"
    {(yyval.dummy)=NULL;if((yyvsp[(1) - (3)].IntgerValue)!=(yyvsp[(3) - (3)].IntgerValue)) ThrowError("Conflict dataTypes in GREATERTHAN Operation \n "," "); }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 381 "mylang.y"
    {(yyval.dummy)=NULL;if((yyvsp[(1) - (3)].IntgerValue)!=(yyvsp[(3) - (3)].IntgerValue)) ThrowError("Conflict dataTypes in LESSTHAN Operation \n "," "); }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 382 "mylang.y"
    {(yyval.dummy)=NULL;if((yyvsp[(1) - (3)].IntgerValue)!=(yyvsp[(3) - (3)].IntgerValue)) ThrowError("Conflict dataTypes in GREATERTHANOREQUAL Operation \n "," "); }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 383 "mylang.y"
    {(yyval.dummy)=NULL;if((yyvsp[(1) - (3)].IntgerValue)!=(yyvsp[(3) - (3)].IntgerValue)) ThrowError("Conflict dataTypes in LESSTHANOREQUAL Operation \n "," "); }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 384 "mylang.y"
    {(yyval.dummy)=NULL;if((yyvsp[(1) - (3)].IntgerValue)!=(yyvsp[(3) - (3)].IntgerValue)) ThrowError("Conflict dataTypes in NOTEQUAL Operation \n "," "); }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 385 "mylang.y"
    {(yyval.dummy)=NULL;if((yyvsp[(1) - (3)].IntgerValue)!=(yyvsp[(3) - (3)].IntgerValue)) ThrowError("Conflict dataTypes in EQUALEQUAL Operation \n "," "); }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 386 "mylang.y"
    {(yyval.dummy)=NULL;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 389 "mylang.y"
    {(yyval.IntgerValue)=(yyvsp[(1) - (1)].IntgerValue);}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 390 "mylang.y"
    {(yyval.IntgerValue)=2;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 391 "mylang.y"
    {(yyval.IntgerValue)=4;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 392 "mylang.y"
    {(yyval.IntgerValue)=4;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 393 "mylang.y"
    {(yyval.IntgerValue)=3;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 399 "mylang.y"
    {{(yyval.IntgerValue)=(yyvsp[(1) - (1)].IntgerValue);}}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 400 "mylang.y"
    {{(yyval.IntgerValue)=4;}}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 402 "mylang.y"
    {(yyval.dummy)=NULL;printf(" Case Statment\n");}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 403 "mylang.y"
    {(yyval.dummy)=NULL;printf(" Case Statment\n");}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 404 "mylang.y"
    {(yyval.dummy)=NULL;printf(" Case Statment\n");}
    break;



/* Line 1455 of yacc.c  */
#line 2307 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 407 "mylang.y"
 
void CreateID(int type , char*rName,int rID,int ScopeNum)
{
	if(CheckIDENTIFYER(rName))
	ThrowError("Already Declared IDENTIFIER with Name ",rName);
	//printf("IDENTIFIER with Name %s is Already Declared \n",rName);
	else
	{
		bool isConstant=(type>4)?true:false;
		SymbolData* rSymbol=setSymbol(type,0,false,0,rName,!isConstant,ScopeNum);
		if(isConstant)
		{
			rSymbol->Initilzation=true;
			pushSymbol(rID,rSymbol);
			printf("Constant Symbol is created with Name %s \n",rName);	
		}
		else 
		{
			pushSymbol(rID,rSymbol);
			printf(" Symbol is created with Name %s \n",rName);
		}
	}
}
void CreateFunction(int type , char*rName,int rID,int ScopeNum,int rArgCounter,int *ArrOfTypes)
{
	if(CheckIDENTIFYER(rName))
	ThrowError("Already Declared IDENTIFIER with Name ",rName);
	//printf("IDENTIFIER with Name %s is Already Declared \n",rName);
	else
	{
		bool isConstant=(type>4)?true:false;// constant function ? XD
		SymbolData* rSymbol=setSymbol(type,0,false,0,rName,!isConstant,ScopeNum);
		if(isConstant)
		{
			rSymbol->Initilzation=true;
			setFuncArg(rArgCounter,ArrOfTypes,rSymbol);
			pushSymbol(rID,rSymbol);
			printf("Constant Symbol Function is created with Name %s \n",rName);	
		}
		else 
		{
			setFuncArg(rArgCounter,ArrOfTypes,rSymbol);
			pushSymbol(rID,rSymbol);
			printf(" Symbol Function is created with Name %s \n",rName);
		}
		
	}

}
void getIDENTIFIER(char*rName,int ScopeNum)
{
	SymbolNode * rSymbol=getID(rName, ScopeNum);
	if(!rSymbol)
	//printf("IDENTIFIER with Name %s is not Declared with this scope\n",rName);
	ThrowError("Not Declared in This Scope Identifiyer with Name \n ",rName);
	else
	{
		//printf("IDENTIFIER with Name is Initilized %s \n",rName);
		if(!rSymbol->DATA->Modifiable)
			ThrowError("Can't Modify a Constant Identifiyer with Name \n ",rName);
		else
			rSymbol->DATA->Initilzation=true;
	}
}
void usedIDENTIFIER(char*rName,int ScopeNum)
{
	SymbolNode * rSymbol=getID(rName, ScopeNum);
	if(!rSymbol)
	ThrowError("Not Declared in This Scope Identifiyer with Name \n ",rName);
	else
	{
		printf("IDENTIFIER with Name is Used %s \n",rName);
		if(!rSymbol->DATA->Initilzation)printf("Warning :IDENTIFIER with Name %s is not Initilized and is being used.  \n",rName);// don't quit just a warning
		rSymbol->DATA->Used=true;
	}
}
bool checktypeIDENTIFER(int LeftType,int RightType,char* Right)
{
	/*if(LeftType!=RightType)
	{
		printf("IDENTIFIER with Name  %s has error Type conflict \n",Right);
		return false;
	}
	else
	{
		printf("IDENTIFIER with Name  %s has correct type \n",Right);
		return true;
	}*/
	bool correct = ((LeftType==RightType) || (LeftType-5 ==RightType))?true:false; // here i check both constants types and types 
	return correct;

}
void ThrowError(char *Message, char *rVar)
{
	fclose(inFile);
	//int x = remove("output.txt");
	inFile = fopen("output.txt","w");
	fprintf(inFile, "Syntax Error Could not parse quadruples\n");
 	fprintf(inFile, "line number: %d %s : %s\n", yylineno,Message,rVar);
	printf("line number: %d %s : %s\n", yylineno,Message,rVar);
	fclose(outSymbol);
	 remove("mySymbols.txt");
	outSymbol = fopen("mySymbols.txt","w");
	fprintf(outSymbol, "Syntax Error was Found\n");
 	fprintf(outSymbol, "line number: %d %s : %s\n", yylineno,Message,rVar);
 	exit(0);
};



// needed ?
 int yyerror(char *s) {  int lineno=++yylineno;   fprintf(stderr, "line number : %d %s\n", lineno,s);     return 0; }
 
 char * conctanteStr(char* str1,char*str2)
 {  
      char * str3 = (char *) malloc(1 + strlen(str1)+ strlen(str2) );
      strcpy(str3, str1);
      strcat(str3, str2);
	return str3;
 
 }
 int main(void) {
	
	inFile = fopen("input.txt", "r");
	outFile=fopen("output.txt","w");
	FILE *TestQuad=fopen("Quad.txt","w");
	outSymbol=fopen("mySymbols.txt","w");
	if(!yyparse()) {
		printf("\nParsing complete\n");
		PrintSymbolTable(outSymbol);
		DestroyList();
		PrintQuadList(TestQuad);
		// -- TO-DO DestroyQuadList() to free allocated memory .. 
		fprintf(outFile,"Completed");
	}
	else {
		printf("\nParsing failed\n %d",yylineno);
		return 0;
	}
	
	fclose(inFile);
	fclose(outFile);
    return 0;
}
