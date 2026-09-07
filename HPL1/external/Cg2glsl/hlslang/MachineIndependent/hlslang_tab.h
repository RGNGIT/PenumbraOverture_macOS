/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_HLSLANG_TAB_H_INCLUDED
# define YY_YY_HLSLANG_TAB_H_INCLUDED
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
    ATTRIBUTE = 258,               /* ATTRIBUTE  */
    CONST_QUAL = 259,              /* CONST_QUAL  */
    STATIC_QUAL = 260,             /* STATIC_QUAL  */
    BOOL_TYPE = 261,               /* BOOL_TYPE  */
    FLOAT_TYPE = 262,              /* FLOAT_TYPE  */
    INT_TYPE = 263,                /* INT_TYPE  */
    STRING_TYPE = 264,             /* STRING_TYPE  */
    FIXED_TYPE = 265,              /* FIXED_TYPE  */
    HALF_TYPE = 266,               /* HALF_TYPE  */
    BREAK = 267,                   /* BREAK  */
    CONTINUE = 268,                /* CONTINUE  */
    DO = 269,                      /* DO  */
    ELSE = 270,                    /* ELSE  */
    FOR = 271,                     /* FOR  */
    IF = 272,                      /* IF  */
    DISCARD = 273,                 /* DISCARD  */
    RETURN = 274,                  /* RETURN  */
    BVEC2 = 275,                   /* BVEC2  */
    BVEC3 = 276,                   /* BVEC3  */
    BVEC4 = 277,                   /* BVEC4  */
    IVEC2 = 278,                   /* IVEC2  */
    IVEC3 = 279,                   /* IVEC3  */
    IVEC4 = 280,                   /* IVEC4  */
    VEC2 = 281,                    /* VEC2  */
    VEC3 = 282,                    /* VEC3  */
    VEC4 = 283,                    /* VEC4  */
    HVEC2 = 284,                   /* HVEC2  */
    HVEC3 = 285,                   /* HVEC3  */
    HVEC4 = 286,                   /* HVEC4  */
    FVEC2 = 287,                   /* FVEC2  */
    FVEC3 = 288,                   /* FVEC3  */
    FVEC4 = 289,                   /* FVEC4  */
    MATRIX2 = 290,                 /* MATRIX2  */
    MATRIX3 = 291,                 /* MATRIX3  */
    MATRIX4 = 292,                 /* MATRIX4  */
    HMATRIX2 = 293,                /* HMATRIX2  */
    HMATRIX3 = 294,                /* HMATRIX3  */
    HMATRIX4 = 295,                /* HMATRIX4  */
    FMATRIX2 = 296,                /* FMATRIX2  */
    FMATRIX3 = 297,                /* FMATRIX3  */
    FMATRIX4 = 298,                /* FMATRIX4  */
    IN_QUAL = 299,                 /* IN_QUAL  */
    OUT_QUAL = 300,                /* OUT_QUAL  */
    INOUT_QUAL = 301,              /* INOUT_QUAL  */
    UNIFORM = 302,                 /* UNIFORM  */
    VARYING = 303,                 /* VARYING  */
    STRUCT = 304,                  /* STRUCT  */
    VOID_TYPE = 305,               /* VOID_TYPE  */
    WHILE = 306,                   /* WHILE  */
    SAMPLER1D = 307,               /* SAMPLER1D  */
    SAMPLER2D = 308,               /* SAMPLER2D  */
    SAMPLER3D = 309,               /* SAMPLER3D  */
    SAMPLERCUBE = 310,             /* SAMPLERCUBE  */
    SAMPLER1DSHADOW = 311,         /* SAMPLER1DSHADOW  */
    SAMPLER2DSHADOW = 312,         /* SAMPLER2DSHADOW  */
    SAMPLERRECTSHADOW = 313,       /* SAMPLERRECTSHADOW  */
    SAMPLERRECT = 314,             /* SAMPLERRECT  */
    SAMPLERGENERIC = 315,          /* SAMPLERGENERIC  */
    VECTOR = 316,                  /* VECTOR  */
    MATRIX = 317,                  /* MATRIX  */
    REGISTER = 318,                /* REGISTER  */
    TEXTURE = 319,                 /* TEXTURE  */
    SAMPLERSTATE = 320,            /* SAMPLERSTATE  */
    IDENTIFIER = 321,              /* IDENTIFIER  */
    TYPE_NAME = 322,               /* TYPE_NAME  */
    FLOATCONSTANT = 323,           /* FLOATCONSTANT  */
    INTCONSTANT = 324,             /* INTCONSTANT  */
    BOOLCONSTANT = 325,            /* BOOLCONSTANT  */
    STRINGCONSTANT = 326,          /* STRINGCONSTANT  */
    FIELD_SELECTION = 327,         /* FIELD_SELECTION  */
    LEFT_OP = 328,                 /* LEFT_OP  */
    RIGHT_OP = 329,                /* RIGHT_OP  */
    INC_OP = 330,                  /* INC_OP  */
    DEC_OP = 331,                  /* DEC_OP  */
    LE_OP = 332,                   /* LE_OP  */
    GE_OP = 333,                   /* GE_OP  */
    EQ_OP = 334,                   /* EQ_OP  */
    NE_OP = 335,                   /* NE_OP  */
    AND_OP = 336,                  /* AND_OP  */
    OR_OP = 337,                   /* OR_OP  */
    XOR_OP = 338,                  /* XOR_OP  */
    MUL_ASSIGN = 339,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 340,              /* DIV_ASSIGN  */
    ADD_ASSIGN = 341,              /* ADD_ASSIGN  */
    MOD_ASSIGN = 342,              /* MOD_ASSIGN  */
    LEFT_ASSIGN = 343,             /* LEFT_ASSIGN  */
    RIGHT_ASSIGN = 344,            /* RIGHT_ASSIGN  */
    AND_ASSIGN = 345,              /* AND_ASSIGN  */
    XOR_ASSIGN = 346,              /* XOR_ASSIGN  */
    OR_ASSIGN = 347,               /* OR_ASSIGN  */
    SUB_ASSIGN = 348,              /* SUB_ASSIGN  */
    PROFILE = 349,                 /* PROFILE  */
    LEFT_PAREN = 350,              /* LEFT_PAREN  */
    RIGHT_PAREN = 351,             /* RIGHT_PAREN  */
    LEFT_BRACKET = 352,            /* LEFT_BRACKET  */
    RIGHT_BRACKET = 353,           /* RIGHT_BRACKET  */
    LEFT_BRACE = 354,              /* LEFT_BRACE  */
    RIGHT_BRACE = 355,             /* RIGHT_BRACE  */
    DOT = 356,                     /* DOT  */
    COMMA = 357,                   /* COMMA  */
    COLON = 358,                   /* COLON  */
    EQUAL = 359,                   /* EQUAL  */
    SEMICOLON = 360,               /* SEMICOLON  */
    BANG = 361,                    /* BANG  */
    DASH = 362,                    /* DASH  */
    TILDE = 363,                   /* TILDE  */
    PLUS = 364,                    /* PLUS  */
    STAR = 365,                    /* STAR  */
    SLASH = 366,                   /* SLASH  */
    PERCENT = 367,                 /* PERCENT  */
    LEFT_ANGLE = 368,              /* LEFT_ANGLE  */
    RIGHT_ANGLE = 369,             /* RIGHT_ANGLE  */
    VERTICAL_BAR = 370,            /* VERTICAL_BAR  */
    CARET = 371,                   /* CARET  */
    AMPERSAND = 372,               /* AMPERSAND  */
    QUESTION = 373                 /* QUESTION  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 68 "hlslang.y"

    struct {
        TSourceLoc line;
        union {
            TString *string;
            float f;
            int i;
            bool b;
        };
        TSymbol* symbol;
    } lex;
    struct {
        TSourceLoc line;
        TOperator op;
        union {
            TIntermNode* intermNode;
            TIntermNodePair nodePair;
            TIntermTyped* intermTypedNode;
            TIntermAggregate* intermAggregate;
			TIntermDeclaration* intermDeclaration;
        };
        union {
            TPublicType type;
            TQualifier qualifier;
            TFunction* function;
            TParameter param;
            TTypeLine typeLine;
            TTypeList* typeList;
	    TAnnotation* ann;
	    TTypeInfo* typeInfo;
        };
    } interm;

#line 216 "hlslang_tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif




int yyparse (void* parseContextLocal);


#endif /* !YY_YY_HLSLANG_TAB_H_INCLUDED  */
