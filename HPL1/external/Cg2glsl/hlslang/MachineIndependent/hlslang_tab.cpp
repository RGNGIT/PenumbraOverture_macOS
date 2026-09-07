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
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 9 "hlslang.y"


/* Based on:
ANSI C Yacc grammar

In 1985, Jeff Lee published his Yacc grammar (which is accompanied by a 
matching Lex specification) for the April 30, 1985 draft version of the 
ANSI C standard.  Tom Stockfisch reposted it to net.sources in 1987; that
original, as mentioned in the answer to question 17.25 of the comp.lang.c
FAQ, can be ftp'ed from ftp.uu.net, file usenet/net.sources/ansi.c.grammar.Z.
 
I intend to keep this version as close to the current C Standard grammar as 
possible; please let me know if you discover discrepancies. 

Jutta Degener, 1995 
*/

#include "SymbolTable.h"
#include "ParseHelper.h"
#include "../../include/hlsl2glsl.h"

#define parseContext (*((TParseContext*)(parseContextLocal)))
#define YY_DECL int yylex(YYSTYPE* pyylval, void* parseContextLocal)
extern void yyerror(void*, char*);

#define FRAG_VERT_ONLY(S, L) {                                                  \
    if (parseContext.language != EShLangFragment &&                             \
        parseContext.language != EShLangVertex) {                               \
        parseContext.error(L, " supported in vertex/fragment shaders only ", S, "", "");   \
        parseContext.recover();                                                            \
    }                                                                           \
}

#define VERTEX_ONLY(S, L) {                                                     \
    if (parseContext.language != EShLangVertex) {                               \
        parseContext.error(L, " supported in vertex shaders only ", S, "", "");            \
        parseContext.recover();                                                            \
    }                                                                           \
}

#define FRAG_ONLY(S, L) {                                                       \
    if (parseContext.language != EShLangFragment) {                             \
        parseContext.error(L, " supported in fragment shaders only ", S, "", "");          \
        parseContext.recover();                                                            \
    }                                                                           \
}

#define UNSUPPORTED_FEATURE(S, L) {                                                       \
    parseContext.error(L, " not supported ", S, "", "");              \
    parseContext.recover();                                                            \
}

#define SET_BASIC_TYPE(RES,PAR,T,PREC) \
	TQualifier qual = parseContext.getDefaultQualifier(); \
	(RES).setBasic(T, qual, (PAR).line); \
	(RES).precision = PREC



#line 131 "hlslang_tab.cpp"

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

#include "hlslang_tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ATTRIBUTE = 3,                  /* ATTRIBUTE  */
  YYSYMBOL_CONST_QUAL = 4,                 /* CONST_QUAL  */
  YYSYMBOL_STATIC_QUAL = 5,                /* STATIC_QUAL  */
  YYSYMBOL_BOOL_TYPE = 6,                  /* BOOL_TYPE  */
  YYSYMBOL_FLOAT_TYPE = 7,                 /* FLOAT_TYPE  */
  YYSYMBOL_INT_TYPE = 8,                   /* INT_TYPE  */
  YYSYMBOL_STRING_TYPE = 9,                /* STRING_TYPE  */
  YYSYMBOL_FIXED_TYPE = 10,                /* FIXED_TYPE  */
  YYSYMBOL_HALF_TYPE = 11,                 /* HALF_TYPE  */
  YYSYMBOL_BREAK = 12,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 13,                  /* CONTINUE  */
  YYSYMBOL_DO = 14,                        /* DO  */
  YYSYMBOL_ELSE = 15,                      /* ELSE  */
  YYSYMBOL_FOR = 16,                       /* FOR  */
  YYSYMBOL_IF = 17,                        /* IF  */
  YYSYMBOL_DISCARD = 18,                   /* DISCARD  */
  YYSYMBOL_RETURN = 19,                    /* RETURN  */
  YYSYMBOL_BVEC2 = 20,                     /* BVEC2  */
  YYSYMBOL_BVEC3 = 21,                     /* BVEC3  */
  YYSYMBOL_BVEC4 = 22,                     /* BVEC4  */
  YYSYMBOL_IVEC2 = 23,                     /* IVEC2  */
  YYSYMBOL_IVEC3 = 24,                     /* IVEC3  */
  YYSYMBOL_IVEC4 = 25,                     /* IVEC4  */
  YYSYMBOL_VEC2 = 26,                      /* VEC2  */
  YYSYMBOL_VEC3 = 27,                      /* VEC3  */
  YYSYMBOL_VEC4 = 28,                      /* VEC4  */
  YYSYMBOL_HVEC2 = 29,                     /* HVEC2  */
  YYSYMBOL_HVEC3 = 30,                     /* HVEC3  */
  YYSYMBOL_HVEC4 = 31,                     /* HVEC4  */
  YYSYMBOL_FVEC2 = 32,                     /* FVEC2  */
  YYSYMBOL_FVEC3 = 33,                     /* FVEC3  */
  YYSYMBOL_FVEC4 = 34,                     /* FVEC4  */
  YYSYMBOL_MATRIX2 = 35,                   /* MATRIX2  */
  YYSYMBOL_MATRIX3 = 36,                   /* MATRIX3  */
  YYSYMBOL_MATRIX4 = 37,                   /* MATRIX4  */
  YYSYMBOL_HMATRIX2 = 38,                  /* HMATRIX2  */
  YYSYMBOL_HMATRIX3 = 39,                  /* HMATRIX3  */
  YYSYMBOL_HMATRIX4 = 40,                  /* HMATRIX4  */
  YYSYMBOL_FMATRIX2 = 41,                  /* FMATRIX2  */
  YYSYMBOL_FMATRIX3 = 42,                  /* FMATRIX3  */
  YYSYMBOL_FMATRIX4 = 43,                  /* FMATRIX4  */
  YYSYMBOL_IN_QUAL = 44,                   /* IN_QUAL  */
  YYSYMBOL_OUT_QUAL = 45,                  /* OUT_QUAL  */
  YYSYMBOL_INOUT_QUAL = 46,                /* INOUT_QUAL  */
  YYSYMBOL_UNIFORM = 47,                   /* UNIFORM  */
  YYSYMBOL_VARYING = 48,                   /* VARYING  */
  YYSYMBOL_STRUCT = 49,                    /* STRUCT  */
  YYSYMBOL_VOID_TYPE = 50,                 /* VOID_TYPE  */
  YYSYMBOL_WHILE = 51,                     /* WHILE  */
  YYSYMBOL_SAMPLER1D = 52,                 /* SAMPLER1D  */
  YYSYMBOL_SAMPLER2D = 53,                 /* SAMPLER2D  */
  YYSYMBOL_SAMPLER3D = 54,                 /* SAMPLER3D  */
  YYSYMBOL_SAMPLERCUBE = 55,               /* SAMPLERCUBE  */
  YYSYMBOL_SAMPLER1DSHADOW = 56,           /* SAMPLER1DSHADOW  */
  YYSYMBOL_SAMPLER2DSHADOW = 57,           /* SAMPLER2DSHADOW  */
  YYSYMBOL_SAMPLERRECTSHADOW = 58,         /* SAMPLERRECTSHADOW  */
  YYSYMBOL_SAMPLERRECT = 59,               /* SAMPLERRECT  */
  YYSYMBOL_SAMPLERGENERIC = 60,            /* SAMPLERGENERIC  */
  YYSYMBOL_VECTOR = 61,                    /* VECTOR  */
  YYSYMBOL_MATRIX = 62,                    /* MATRIX  */
  YYSYMBOL_REGISTER = 63,                  /* REGISTER  */
  YYSYMBOL_TEXTURE = 64,                   /* TEXTURE  */
  YYSYMBOL_SAMPLERSTATE = 65,              /* SAMPLERSTATE  */
  YYSYMBOL_IDENTIFIER = 66,                /* IDENTIFIER  */
  YYSYMBOL_TYPE_NAME = 67,                 /* TYPE_NAME  */
  YYSYMBOL_FLOATCONSTANT = 68,             /* FLOATCONSTANT  */
  YYSYMBOL_INTCONSTANT = 69,               /* INTCONSTANT  */
  YYSYMBOL_BOOLCONSTANT = 70,              /* BOOLCONSTANT  */
  YYSYMBOL_STRINGCONSTANT = 71,            /* STRINGCONSTANT  */
  YYSYMBOL_FIELD_SELECTION = 72,           /* FIELD_SELECTION  */
  YYSYMBOL_LEFT_OP = 73,                   /* LEFT_OP  */
  YYSYMBOL_RIGHT_OP = 74,                  /* RIGHT_OP  */
  YYSYMBOL_INC_OP = 75,                    /* INC_OP  */
  YYSYMBOL_DEC_OP = 76,                    /* DEC_OP  */
  YYSYMBOL_LE_OP = 77,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 78,                     /* GE_OP  */
  YYSYMBOL_EQ_OP = 79,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 80,                     /* NE_OP  */
  YYSYMBOL_AND_OP = 81,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 82,                     /* OR_OP  */
  YYSYMBOL_XOR_OP = 83,                    /* XOR_OP  */
  YYSYMBOL_MUL_ASSIGN = 84,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 85,                /* DIV_ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 86,                /* ADD_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 87,                /* MOD_ASSIGN  */
  YYSYMBOL_LEFT_ASSIGN = 88,               /* LEFT_ASSIGN  */
  YYSYMBOL_RIGHT_ASSIGN = 89,              /* RIGHT_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 90,                /* AND_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 91,                /* XOR_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 92,                 /* OR_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 93,                /* SUB_ASSIGN  */
  YYSYMBOL_PROFILE = 94,                   /* PROFILE  */
  YYSYMBOL_LEFT_PAREN = 95,                /* LEFT_PAREN  */
  YYSYMBOL_RIGHT_PAREN = 96,               /* RIGHT_PAREN  */
  YYSYMBOL_LEFT_BRACKET = 97,              /* LEFT_BRACKET  */
  YYSYMBOL_RIGHT_BRACKET = 98,             /* RIGHT_BRACKET  */
  YYSYMBOL_LEFT_BRACE = 99,                /* LEFT_BRACE  */
  YYSYMBOL_RIGHT_BRACE = 100,              /* RIGHT_BRACE  */
  YYSYMBOL_DOT = 101,                      /* DOT  */
  YYSYMBOL_COMMA = 102,                    /* COMMA  */
  YYSYMBOL_COLON = 103,                    /* COLON  */
  YYSYMBOL_EQUAL = 104,                    /* EQUAL  */
  YYSYMBOL_SEMICOLON = 105,                /* SEMICOLON  */
  YYSYMBOL_BANG = 106,                     /* BANG  */
  YYSYMBOL_DASH = 107,                     /* DASH  */
  YYSYMBOL_TILDE = 108,                    /* TILDE  */
  YYSYMBOL_PLUS = 109,                     /* PLUS  */
  YYSYMBOL_STAR = 110,                     /* STAR  */
  YYSYMBOL_SLASH = 111,                    /* SLASH  */
  YYSYMBOL_PERCENT = 112,                  /* PERCENT  */
  YYSYMBOL_LEFT_ANGLE = 113,               /* LEFT_ANGLE  */
  YYSYMBOL_RIGHT_ANGLE = 114,              /* RIGHT_ANGLE  */
  YYSYMBOL_VERTICAL_BAR = 115,             /* VERTICAL_BAR  */
  YYSYMBOL_CARET = 116,                    /* CARET  */
  YYSYMBOL_AMPERSAND = 117,                /* AMPERSAND  */
  YYSYMBOL_QUESTION = 118,                 /* QUESTION  */
  YYSYMBOL_YYACCEPT = 119,                 /* $accept  */
  YYSYMBOL_profile_list = 120,             /* profile_list  */
  YYSYMBOL_variable_identifier = 121,      /* variable_identifier  */
  YYSYMBOL_primary_expression = 122,       /* primary_expression  */
  YYSYMBOL_postfix_expression = 123,       /* postfix_expression  */
  YYSYMBOL_function_call = 124,            /* function_call  */
  YYSYMBOL_function_call_or_method = 125,  /* function_call_or_method  */
  YYSYMBOL_function_call_generic = 126,    /* function_call_generic  */
  YYSYMBOL_function_call_header_no_parameters = 127, /* function_call_header_no_parameters  */
  YYSYMBOL_function_call_header_with_parameters = 128, /* function_call_header_with_parameters  */
  YYSYMBOL_function_call_header = 129,     /* function_call_header  */
  YYSYMBOL_function_identifier = 130,      /* function_identifier  */
  YYSYMBOL_unary_expression = 131,         /* unary_expression  */
  YYSYMBOL_unary_operator = 132,           /* unary_operator  */
  YYSYMBOL_multiplicative_expression = 133, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 134,      /* additive_expression  */
  YYSYMBOL_shift_expression = 135,         /* shift_expression  */
  YYSYMBOL_relational_expression = 136,    /* relational_expression  */
  YYSYMBOL_equality_expression = 137,      /* equality_expression  */
  YYSYMBOL_and_expression = 138,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 139,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 140,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 141,   /* logical_and_expression  */
  YYSYMBOL_logical_xor_expression = 142,   /* logical_xor_expression  */
  YYSYMBOL_logical_or_expression = 143,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 144,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 145,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 146,      /* assignment_operator  */
  YYSYMBOL_expression = 147,               /* expression  */
  YYSYMBOL_constant_expression = 148,      /* constant_expression  */
  YYSYMBOL_declaration = 149,              /* declaration  */
  YYSYMBOL_function_prototype = 150,       /* function_prototype  */
  YYSYMBOL_function_declarator = 151,      /* function_declarator  */
  YYSYMBOL_function_header_with_parameters = 152, /* function_header_with_parameters  */
  YYSYMBOL_function_header = 153,          /* function_header  */
  YYSYMBOL_parameter_declarator = 154,     /* parameter_declarator  */
  YYSYMBOL_parameter_declaration = 155,    /* parameter_declaration  */
  YYSYMBOL_parameter_qualifier = 156,      /* parameter_qualifier  */
  YYSYMBOL_parameter_type_specifier = 157, /* parameter_type_specifier  */
  YYSYMBOL_init_declarator_list = 158,     /* init_declarator_list  */
  YYSYMBOL_single_declaration = 159,       /* single_declaration  */
  YYSYMBOL_fully_specified_type = 160,     /* fully_specified_type  */
  YYSYMBOL_type_qualifier = 161,           /* type_qualifier  */
  YYSYMBOL_type_specifier = 162,           /* type_specifier  */
  YYSYMBOL_type_specifier_nonarray = 163,  /* type_specifier_nonarray  */
  YYSYMBOL_struct_specifier = 164,         /* struct_specifier  */
  YYSYMBOL_struct_declaration_list = 165,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 166,       /* struct_declaration  */
  YYSYMBOL_struct_declarator_list = 167,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 168,        /* struct_declarator  */
  YYSYMBOL_initializer = 169,              /* initializer  */
  YYSYMBOL_declaration_statement = 170,    /* declaration_statement  */
  YYSYMBOL_statement = 171,                /* statement  */
  YYSYMBOL_simple_statement = 172,         /* simple_statement  */
  YYSYMBOL_compound_statement = 173,       /* compound_statement  */
  YYSYMBOL_174_1 = 174,                    /* $@1  */
  YYSYMBOL_175_2 = 175,                    /* $@2  */
  YYSYMBOL_statement_no_new_scope = 176,   /* statement_no_new_scope  */
  YYSYMBOL_compound_statement_no_new_scope = 177, /* compound_statement_no_new_scope  */
  YYSYMBOL_statement_list = 178,           /* statement_list  */
  YYSYMBOL_expression_statement = 179,     /* expression_statement  */
  YYSYMBOL_selection_statement = 180,      /* selection_statement  */
  YYSYMBOL_selection_rest_statement = 181, /* selection_rest_statement  */
  YYSYMBOL_condition = 182,                /* condition  */
  YYSYMBOL_iteration_statement = 183,      /* iteration_statement  */
  YYSYMBOL_184_3 = 184,                    /* $@3  */
  YYSYMBOL_185_4 = 185,                    /* $@4  */
  YYSYMBOL_186_5 = 186,                    /* $@5  */
  YYSYMBOL_for_init_statement = 187,       /* for_init_statement  */
  YYSYMBOL_conditionopt = 188,             /* conditionopt  */
  YYSYMBOL_for_rest_statement = 189,       /* for_rest_statement  */
  YYSYMBOL_jump_statement = 190,           /* jump_statement  */
  YYSYMBOL_translation_unit = 191,         /* translation_unit  */
  YYSYMBOL_external_declaration = 192,     /* external_declaration  */
  YYSYMBOL_function_definition = 193,      /* function_definition  */
  YYSYMBOL_194_6 = 194,                    /* $@6  */
  YYSYMBOL_initialization_list = 195,      /* initialization_list  */
  YYSYMBOL_initializer_list = 196,         /* initializer_list  */
  YYSYMBOL_annotation = 197,               /* annotation  */
  YYSYMBOL_annotation_list = 198,          /* annotation_list  */
  YYSYMBOL_annotation_item = 199,          /* annotation_item  */
  YYSYMBOL_ann_type = 200,                 /* ann_type  */
  YYSYMBOL_ann_literal = 201,              /* ann_literal  */
  YYSYMBOL_ann_numerical_constant = 202,   /* ann_numerical_constant  */
  YYSYMBOL_ann_literal_constructor = 203,  /* ann_literal_constructor  */
  YYSYMBOL_ann_value_list = 204,           /* ann_value_list  */
  YYSYMBOL_ann_literal_init_list = 205,    /* ann_literal_init_list  */
  YYSYMBOL_register_specifier = 206,       /* register_specifier  */
  YYSYMBOL_semantic = 207,                 /* semantic  */
  YYSYMBOL_type_info = 208,                /* type_info  */
  YYSYMBOL_sampler_initializer = 209,      /* sampler_initializer  */
  YYSYMBOL_sampler_init_list = 210,        /* sampler_init_list  */
  YYSYMBOL_sampler_init_item = 211         /* sampler_init_item  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 102 "hlslang.y"

    extern int yylex(YYSTYPE*, void*);

#line 380 "hlslang_tab.cpp"


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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  88
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2400

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  119
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  93
/* YYNRULES -- Number of rules.  */
#define YYNRULES  305
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  480

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   373


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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   182,   182,   183,   187,   219,   222,   227,   232,   237,
     243,   246,   342,   345,   438,   448,   469,   585,   588,   606,
     610,   617,   621,   628,   637,   649,   657,   718,   730,   740,
     743,   753,   763,   781,   853,   854,   855,   856,   862,   863,
     872,   881,   892,   893,   901,   912,   913,   922,   934,   935,
     945,   955,   965,   978,   979,   990,  1004,  1005,  1017,  1018,
    1030,  1031,  1043,  1044,  1057,  1058,  1071,  1072,  1085,  1086,
    1101,  1102,  1116,  1117,  1118,  1119,  1120,  1121,  1122,  1123,
    1124,  1125,  1126,  1130,  1133,  1144,  1152,  1153,  1157,  1190,
    1227,  1230,  1237,  1245,  1266,  1287,  1314,  1325,  1338,  1350,
    1362,  1380,  1409,  1414,  1424,  1429,  1439,  1442,  1445,  1448,
    1454,  1461,  1464,  1482,  1506,  1535,  1563,  1598,  1632,  1635,
    1653,  1676,  1702,  1728,  1758,  1806,  1809,  1831,  1834,  1837,
    1840,  1846,  1854,  1862,  1865,  1880,  1883,  1886,  1889,  1892,
    1895,  1898,  1909,  1920,  1931,  1935,  1939,  1943,  1947,  1951,
    1955,  1959,  1963,  1967,  1971,  1975,  1979,  1983,  1987,  1991,
    1996,  2001,  2006,  2011,  2016,  2021,  2026,  2031,  2036,  2040,
    2044,  2048,  2052,  2056,  2060,  2064,  2068,  2072,  2076,  2081,
    2093,  2103,  2111,  2114,  2129,  2161,  2165,  2171,  2176,  2182,
    2192,  2208,  2209,  2210,  2214,  2218,  2219,  2225,  2226,  2227,
    2228,  2229,  2233,  2234,  2234,  2234,  2242,  2243,  2248,  2251,
    2259,  2262,  2268,  2269,  2273,  2281,  2285,  2295,  2300,  2317,
    2317,  2322,  2322,  2329,  2329,  2342,  2345,  2351,  2354,  2360,
    2364,  2371,  2378,  2385,  2392,  2412,  2423,  2427,  2434,  2437,
    2440,  2444,  2444,  2541,  2544,  2551,  2555,  2559,  2563,  2570,
    2574,  2580,  2584,  2591,  2597,  2598,  2599,  2600,  2601,  2602,
    2603,  2604,  2605,  2606,  2607,  2608,  2609,  2610,  2611,  2612,
    2613,  2614,  2615,  2616,  2617,  2621,  2622,  2623,  2624,  2628,
    2631,  2634,  2640,  2644,  2645,  2649,  2653,  2659,  2663,  2664,
    2665,  2666,  2667,  2668,  2669,  2670,  2674,  2679,  2684,  2685,
    2689,  2690,  2691,  2692,  2693,  2694
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ATTRIBUTE",
  "CONST_QUAL", "STATIC_QUAL", "BOOL_TYPE", "FLOAT_TYPE", "INT_TYPE",
  "STRING_TYPE", "FIXED_TYPE", "HALF_TYPE", "BREAK", "CONTINUE", "DO",
  "ELSE", "FOR", "IF", "DISCARD", "RETURN", "BVEC2", "BVEC3", "BVEC4",
  "IVEC2", "IVEC3", "IVEC4", "VEC2", "VEC3", "VEC4", "HVEC2", "HVEC3",
  "HVEC4", "FVEC2", "FVEC3", "FVEC4", "MATRIX2", "MATRIX3", "MATRIX4",
  "HMATRIX2", "HMATRIX3", "HMATRIX4", "FMATRIX2", "FMATRIX3", "FMATRIX4",
  "IN_QUAL", "OUT_QUAL", "INOUT_QUAL", "UNIFORM", "VARYING", "STRUCT",
  "VOID_TYPE", "WHILE", "SAMPLER1D", "SAMPLER2D", "SAMPLER3D",
  "SAMPLERCUBE", "SAMPLER1DSHADOW", "SAMPLER2DSHADOW", "SAMPLERRECTSHADOW",
  "SAMPLERRECT", "SAMPLERGENERIC", "VECTOR", "MATRIX", "REGISTER",
  "TEXTURE", "SAMPLERSTATE", "IDENTIFIER", "TYPE_NAME", "FLOATCONSTANT",
  "INTCONSTANT", "BOOLCONSTANT", "STRINGCONSTANT", "FIELD_SELECTION",
  "LEFT_OP", "RIGHT_OP", "INC_OP", "DEC_OP", "LE_OP", "GE_OP", "EQ_OP",
  "NE_OP", "AND_OP", "OR_OP", "XOR_OP", "MUL_ASSIGN", "DIV_ASSIGN",
  "ADD_ASSIGN", "MOD_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN",
  "XOR_ASSIGN", "OR_ASSIGN", "SUB_ASSIGN", "PROFILE", "LEFT_PAREN",
  "RIGHT_PAREN", "LEFT_BRACKET", "RIGHT_BRACKET", "LEFT_BRACE",
  "RIGHT_BRACE", "DOT", "COMMA", "COLON", "EQUAL", "SEMICOLON", "BANG",
  "DASH", "TILDE", "PLUS", "STAR", "SLASH", "PERCENT", "LEFT_ANGLE",
  "RIGHT_ANGLE", "VERTICAL_BAR", "CARET", "AMPERSAND", "QUESTION",
  "$accept", "profile_list", "variable_identifier", "primary_expression",
  "postfix_expression", "function_call", "function_call_or_method",
  "function_call_generic", "function_call_header_no_parameters",
  "function_call_header_with_parameters", "function_call_header",
  "function_identifier", "unary_expression", "unary_operator",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_xor_expression",
  "logical_or_expression", "conditional_expression",
  "assignment_expression", "assignment_operator", "expression",
  "constant_expression", "declaration", "function_prototype",
  "function_declarator", "function_header_with_parameters",
  "function_header", "parameter_declarator", "parameter_declaration",
  "parameter_qualifier", "parameter_type_specifier",
  "init_declarator_list", "single_declaration", "fully_specified_type",
  "type_qualifier", "type_specifier", "type_specifier_nonarray",
  "struct_specifier", "struct_declaration_list", "struct_declaration",
  "struct_declarator_list", "struct_declarator", "initializer",
  "declaration_statement", "statement", "simple_statement",
  "compound_statement", "$@1", "$@2", "statement_no_new_scope",
  "compound_statement_no_new_scope", "statement_list",
  "expression_statement", "selection_statement",
  "selection_rest_statement", "condition", "iteration_statement", "$@3",
  "$@4", "$@5", "for_init_statement", "conditionopt", "for_rest_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", "$@6", "initialization_list", "initializer_list",
  "annotation", "annotation_list", "annotation_item", "ann_type",
  "ann_literal", "ann_numerical_constant", "ann_literal_constructor",
  "ann_value_list", "ann_literal_init_list", "register_specifier",
  "semantic", "type_info", "sampler_initializer", "sampler_init_list",
  "sampler_init_item", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-388)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-91)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1910,  -388,  -388,    26,  -388,  -388,  -388,  -388,  -388,  -388,
    -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,
    -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,
    -388,  -388,  -388,  -388,  -388,   -42,  -388,  -388,  -388,  -388,
    -388,  -388,  -388,  -388,  -388,  -388,   -78,  -388,  -388,  -388,
    -388,  2195,  -388,   -61,   -31,   -15,    67,    16,  -388,    29,
    2333,  -388,    51,  -388,  1078,  -388,  -388,  -388,    32,  2333,
     143,  -388,    54,  -388,    58,    70,   142,  -388,  -388,  -388,
    -388,  2333,   110,   125,  -388,   -66,  -388,  1727,  -388,  -388,
    2333,   128,  1999,  -388,    96,    97,   100,   106,   464,  -388,
     164,  -388,  -388,  -388,   165,  2333,   -58,  -388,  1361,    69,
     315,  -388,    95,   -70,   105,   138,  -388,  -388,  -388,  -388,
    1727,  1727,  1727,  -388,  -388,  -388,  -388,  -388,  -388,   -34,
    -388,  -388,  -388,   139,   -64,  1817,   144,  -388,  1727,    50,
      63,   104,   -55,   101,   117,   121,   126,   159,   160,   -65,
    -388,   146,  -388,  2080,   -23,    28,  -388,  -388,  -388,   173,
     176,   188,  -388,   154,   155,  -388,   170,   174,   166,  1454,
     175,   168,  -388,  -388,   163,  -388,  -388,    34,  -388,   -61,
     177,  -388,  -388,  -388,  -388,   571,  -388,  -388,  -388,  -388,
    -388,   -21,  -388,  -388,  1544,   169,   -57,   179,   180,  -388,
    -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,
    -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,
    -388,  -388,   365,  -388,   208,  -388,   215,  -388,    95,  1167,
    -388,  -388,     4,    46,  -388,  -388,  1727,  2270,  -388,  -388,
    1727,   184,  -388,  -388,  -388,  1727,  1727,  1727,  1727,  1727,
    1727,  1727,  1727,  1727,  1727,  1727,  1727,  1727,  1727,  1727,
    1727,  1727,  1727,  1727,  1727,  -388,  -388,  1727,   216,   128,
    -388,   167,   171,   172,  -388,  -388,   678,  -388,  1727,  -388,
    -388,    35,  -388,  -388,   678,  -388,  -388,  -388,  -388,  -388,
    -388,  -388,  -388,  -388,  -388,  -388,  1727,  1727,  -388,  -388,
    -388,  1727,    75,  1167,  -388,   -57,   185,  1167,   186,   -57,
     222,  -388,  -388,   187,  -388,   190,  1637,  -388,  -388,  -388,
    -388,  -388,  1727,   -14,  -388,   197,  -388,  -388,  -388,  -388,
    -388,    50,    50,    63,    63,   104,   104,   104,   104,   -55,
     -55,   101,   117,   121,   126,   159,   160,    80,   198,  -388,
    -388,  -388,  -388,  -388,   244,   892,     8,  -388,   985,   678,
    -388,  -388,   199,  -388,  -388,   194,   -57,  -388,  1167,   195,
     204,  2142,   -39,  -388,  -388,     7,  -388,  -388,  1727,   200,
     206,  -388,  -388,   985,   678,   202,   236,   209,   207,   203,
    1167,   205,  -388,  1167,  -388,  -388,  -388,  -388,  -388,    99,
     217,   210,  -388,  -388,  -388,   212,   213,  -388,   -38,  -388,
    -388,  1257,  -388,   247,  1727,  -388,   214,   218,   295,  -388,
     223,   785,  -388,   252,  -388,  1167,  -388,  -388,    74,    99,
    -388,   -47,   -45,  -388,  -388,  -388,  -388,  -388,  -388,    21,
    1727,   785,   678,  1167,  -388,  -388,  -388,  -388,  -388,  -388,
      99,    23,   224,   262,   264,   226,   266,   268,   245,   202,
    -388,  -388,  -388,  -388,  -388,  -388,   255,   238,  -388,   257,
     240,  -388,   251,   256,   258,   259,  -388,  -388,  -388,  -388
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   130,   127,   128,   140,   136,   139,   138,   137,   153,
     154,   155,   156,   157,   158,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   132,   131,     0,   135,   170,   171,   172,
     173,   176,   177,   175,   174,   169,     0,   168,   179,     2,
     240,     0,   239,   241,     0,    91,   106,     0,   111,   118,
       0,   125,   133,   178,     0,   236,   238,   129,     0,     0,
       0,     3,     0,    86,     0,    88,   106,   107,   108,   109,
      92,     0,   106,     0,    87,   288,   126,     0,     1,   237,
       0,     0,     0,   182,     0,     0,     0,     0,     0,   242,
       0,    93,   103,   105,   110,     0,   288,    94,     0,     0,
       0,   291,   290,   289,   119,     4,     7,     6,     8,    28,
       0,     0,     0,    36,    35,    37,    34,     5,    10,    29,
      12,    16,    17,     0,     0,    22,     0,    38,     0,    42,
      45,    48,    53,    56,    58,    60,    62,    64,    66,    68,
      85,     0,    26,     0,   187,     0,   185,   181,   183,     0,
       0,     0,    95,     0,     0,   221,     0,     0,     0,     0,
       0,   203,   208,   212,    38,    70,    83,     0,   194,     0,
     125,   197,   210,   196,   195,     0,   198,   199,   200,   201,
      89,    96,   102,   104,     0,   112,   288,     0,     0,   287,
     258,   254,   257,   259,   256,   255,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   249,     0,   251,     0,   294,     0,   292,   293,     0,
      30,    31,     0,   133,    14,    15,     0,     0,    20,    19,
       0,   135,    23,    25,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   134,   180,     0,     0,     0,
     184,     0,     0,     0,   232,   231,     0,   223,     0,   235,
     233,     0,   219,   202,     0,    73,    74,    76,    75,    78,
      79,    80,    81,    82,    77,    72,     0,     0,   213,   209,
     211,     0,     0,     0,    98,   288,     0,     0,   120,   288,
       0,   250,   252,     0,   295,     0,     0,   191,   124,   192,
     193,     9,     0,     0,    27,    13,    18,    24,    39,    40,
      41,    44,    43,    46,    47,    51,    52,    49,    50,    54,
      55,    57,    59,    61,    63,    65,    67,     0,     0,   188,
     186,   143,   141,   142,     0,     0,     0,   234,     0,   204,
      71,    84,     0,    99,    97,   113,   288,   117,     0,   121,
       0,     0,     0,   245,   246,     0,    33,    11,     0,   189,
       0,   226,   225,   228,     0,   217,     0,     0,     0,   100,
       0,   114,   122,     0,   286,   281,   279,   280,   276,     0,
       0,     0,   275,   277,   278,     0,     0,   297,     0,   298,
     243,     0,    69,     0,     0,   227,     0,     0,   216,   214,
       0,     0,   205,     0,   115,     0,   123,   283,     0,     0,
     253,     0,     0,   296,   299,   244,   247,   248,   190,     0,
     229,     0,     0,     0,   207,   220,   206,   101,   116,   285,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   230,
     224,   215,   218,   284,   282,   303,     0,     0,   300,     0,
       0,   222,     0,     0,     0,     0,   305,   304,   302,   301
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -388,  -388,  -388,  -388,  -388,  -388,  -388,   120,  -388,  -388,
    -388,  -388,   -35,  -388,   -56,   -54,  -126,   -51,   102,   103,
     107,   108,   115,   116,  -388,   -72,  -132,  -388,  -120,  -101,
      11,    14,  -388,  -388,  -388,   260,   290,   286,   265,  -388,
    -388,   -50,   -36,     0,   278,  -388,   288,   -74,  -388,   111,
    -291,    27,  -180,  -387,  -388,  -388,  -388,   -60,   327,   118,
      48,  -388,  -388,    22,  -388,  -388,  -388,  -388,  -388,  -388,
    -388,  -388,  -388,   340,  -388,  -388,  -310,  -388,  -104,  -388,
     189,    36,  -388,  -361,  -388,   -20,  -388,  -100,  -388,  -102,
    -388,  -388,    -2
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    51,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   174,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   175,   176,   296,   177,   151,
     178,   179,    54,    55,    56,   102,    80,    81,   103,    57,
      58,    59,    60,   152,    62,    63,    92,    93,   155,   156,
     318,   181,   182,   183,   184,   284,   388,   445,   446,   185,
     186,   187,   419,   387,   188,   358,   276,   355,   383,   416,
     417,   189,    64,    65,    66,    74,   319,   375,   111,   222,
     223,   224,   401,   427,   403,   428,   404,   112,   113,   114,
     320,   408,   409
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      61,    72,   232,   242,   195,   300,   374,   197,   225,   227,
     402,    52,   364,   228,    53,   150,   367,   263,   158,   452,
      82,   455,   252,   253,    68,   405,   405,   406,   406,   107,
      67,   108,   239,   226,   444,    70,   150,   109,   240,   194,
      82,   234,   235,   110,    73,   109,   109,   110,   453,   281,
     456,    61,   137,   264,   444,   110,   110,    69,   254,   255,
      86,   407,   433,   236,    61,    75,   454,   237,   457,    91,
       1,     2,     3,   137,   267,    52,   301,   392,    53,   158,
     268,   104,   302,   303,   377,   230,   231,    76,   297,   463,
      91,   304,    91,   306,   308,    85,   354,   317,   180,   424,
     321,   437,   426,   244,   384,   104,   297,   410,   327,   411,
     297,    77,    78,    79,    33,    34,   323,   458,    83,   464,
      97,    84,   150,   297,   314,   450,   335,   336,   337,   338,
     269,    90,   198,   270,   448,   199,   297,   297,   198,   298,
     357,   363,   322,    87,   347,     1,     2,     3,    87,    94,
      95,    96,   462,    91,    77,    78,    79,    98,   356,   137,
     245,   246,   247,   -90,   360,   361,   348,   395,   396,   397,
     248,   317,   249,   100,   449,   317,   450,   250,   251,   300,
     256,   257,   297,   378,   373,   180,    77,    78,    79,    33,
      34,   106,   331,   332,   154,   150,   333,   334,   159,   160,
     362,   162,   161,   365,   418,   339,   340,   369,   110,   229,
     328,   329,   330,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   150,
     190,   191,   137,   -27,   258,   238,   317,   259,   385,   243,
     261,   260,   271,   262,   265,   272,   412,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   273,   317,   274,
     275,   317,   461,   385,   391,   277,   137,   295,   283,   278,
     282,   279,   -26,   307,   313,   310,   180,   309,   198,   436,
     -21,   351,   349,   366,   180,   352,   353,   376,   370,   372,
     368,   371,   -28,   317,   439,   380,   379,   389,   390,   393,
     394,   414,   420,   413,   297,   421,   423,   422,   386,   425,
     442,   317,   429,   438,   441,   430,   431,   432,   447,   440,
     459,   200,   201,   202,   203,   204,   205,   443,   466,   465,
     467,   468,   469,   386,   470,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     471,   472,   473,   474,   475,   180,   476,   326,   180,   180,
     341,   477,   342,   478,   479,   192,   101,   343,   105,   344,
     193,   200,   201,   202,   203,   204,   205,   345,   153,   346,
     350,   460,   381,   180,   180,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     233,    99,   359,   382,    89,   415,   434,   400,     0,   451,
       0,   312,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   180,     0,     0,     0,     0,     0,     0,     0,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   180,   180,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     2,     3,
       4,     5,     6,     0,     7,     8,   163,   164,   165,   311,
     166,   167,   168,   169,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,     0,     0,
       0,    33,    34,    35,    36,   170,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,     0,     0,    47,     0,
     115,    48,   116,   117,   118,     0,   119,     0,     0,   120,
     121,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    49,   122,
       0,     0,     0,   171,   172,     0,     0,     0,     0,   173,
     123,   124,   125,   126,     1,     2,     3,     4,     5,     6,
       0,     7,     8,   163,   164,   165,     0,   166,   167,   168,
     169,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,     0,     0,     0,    33,    34,
      35,    36,   170,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,     0,     0,    47,     0,   115,    48,   116,
     117,   118,     0,   119,     0,     0,   120,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    49,   122,     0,     0,     0,
     171,   299,     0,     0,     0,     0,   173,   123,   124,   125,
     126,     1,     2,     3,     4,     5,     6,     0,     7,     8,
     163,   164,   165,     0,   166,   167,   168,   169,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,     0,     0,     0,    33,    34,    35,    36,   170,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
       0,     0,    47,     0,   115,    48,   116,   117,   118,     0,
     119,     0,     0,   120,   121,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    49,   122,     0,     0,     0,   171,     0,     0,
       0,     0,     0,   173,   123,   124,   125,   126,     1,     2,
       3,     4,     5,     6,     0,     7,     8,   163,   164,   165,
       0,   166,   167,   168,   169,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,     0,
       0,     0,    33,    34,    35,    36,   170,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,     0,     0,    47,
       0,   115,    48,   116,   117,   118,     0,   119,     0,     0,
     120,   121,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    49,
     122,     0,     0,     0,    98,     0,     0,     0,     0,     0,
     173,   123,   124,   125,   126,     1,     2,     3,     4,     5,
       6,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,     0,     0,     0,    33,
      34,    35,    36,     0,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,     0,     0,    47,     0,   115,    48,
     116,   117,   118,     0,   119,     0,     0,   120,   121,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    49,   122,     1,     2,
       3,     4,     5,     6,     0,     7,     8,   173,   123,   124,
     125,   126,     0,     0,     0,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,     0,
       0,     0,    33,    34,    35,    36,     0,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,     0,     0,    47,
       0,   115,    48,   116,   117,   118,     0,   119,     0,     0,
     120,   121,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    88,     0,
     122,     1,     2,     3,     4,     5,     6,     0,     7,     8,
       0,   123,   124,   125,   126,     0,     0,     0,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,     0,     0,     0,    33,    34,    35,    36,     0,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
       0,     0,    47,     0,     0,    48,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    49,     4,     5,     6,     0,     7,     8,     0,
       0,     0,     0,    50,     0,     0,     0,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,     0,     0,     0,     0,     0,    35,    36,     0,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,     0,
       0,    47,   315,   115,    48,   116,   117,   118,     0,   119,
       0,     0,   120,   121,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   122,     4,     5,     6,   316,     7,     8,     0,
       0,     0,     0,   123,   124,   125,   126,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,     0,     0,     0,     0,     0,    35,    36,     0,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,     0,
       0,    47,     0,   115,    48,   116,   117,   118,     0,   119,
       0,     0,   120,   121,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   122,     0,     0,     0,   316,   435,     0,     0,
       0,     0,     0,   123,   124,   125,   126,     4,     5,     6,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,     0,     0,     0,     0,     0,
      35,    36,     0,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,     0,     0,    47,     0,   115,    48,   116,
     117,   118,     0,   119,     0,     0,   120,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   122,     0,     0,   196,
       4,     5,     6,     0,     7,     8,     0,   123,   124,   125,
     126,     0,     0,     0,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,     0,     0,
       0,     0,     0,    35,    36,     0,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,     0,     0,    47,     0,
     115,    48,   116,   117,   118,     0,   119,     0,     0,   120,
     121,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   122,
       4,     5,     6,     0,     7,     8,     0,     0,     0,   280,
     123,   124,   125,   126,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,     0,     0,
       0,     0,     0,    35,    36,     0,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,     0,     0,    47,     0,
     115,    48,   116,   117,   118,     0,   119,     0,     0,   120,
     121,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   122,
       0,     0,   305,     4,     5,     6,     0,     7,     8,     0,
     123,   124,   125,   126,     0,     0,     0,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,     0,     0,     0,     0,     0,    35,    36,     0,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,     0,
       0,    47,     0,   115,    48,   116,   117,   118,     0,   119,
       0,     0,   120,   121,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   122,     4,     5,     6,   316,     7,     8,     0,
       0,     0,     0,   123,   124,   125,   126,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,     0,     0,     0,     0,     0,    35,    36,     0,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,     0,
       0,    47,     0,   115,    48,   116,   117,   118,     0,   119,
       0,     0,   120,   121,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   122,     4,     5,     6,     0,     7,     8,     0,
       0,     0,     0,   123,   124,   125,   126,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,     0,     0,     0,     0,     0,    35,   241,     0,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,     0,
       0,    47,     0,   115,    48,   116,   117,   118,     0,   119,
       0,     0,   120,   121,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   122,     1,     2,     3,     4,     5,     6,     0,
       7,     8,     0,   123,   124,   125,   126,     0,     0,     0,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,     0,     0,     0,    33,    34,    35,
      36,     0,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,     0,     0,    47,     0,     0,    48,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    49,     4,     5,     6,     0,     7,
       8,     0,     0,     0,     0,    50,     0,     0,     0,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,     0,     0,     0,     0,     0,    35,    36,
       0,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,     0,     0,    47,     0,     0,    48,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     5,     6,     0,
       7,     8,     0,     0,     0,     0,     0,     0,     0,   157,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,     0,     0,     0,     0,     0,    35,
      36,     0,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,     0,     0,    47,     0,     0,    48,   200,   201,
     202,   203,   204,   205,     0,     0,     0,     0,     0,     0,
       0,     0,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,     0,     0,     0,
     266,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     2,
       3,     4,     5,     6,     0,     7,     8,     0,     0,     0,
     395,   396,   397,   398,     0,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,     0,
       0,   399,    33,    34,    35,    36,     0,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,     0,     0,    47,
       0,     0,    48,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     5,     6,     0,
       7,     8,     0,     0,     0,     0,     0,     0,     0,    71,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,     0,     0,     0,     0,     0,    35,
      36,     0,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,     0,     0,    47,     0,   324,    48,     0,     4,
       5,     6,   325,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,     0,     0,     0,
       0,     0,    35,    36,     0,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,     0,     0,    47,     0,     0,
      48
};

static const yytype_int16 yycheck[] =
{
       0,    51,   122,   135,   106,   185,   316,   108,   112,   113,
     371,     0,   303,   113,     0,    87,   307,    82,    92,    66,
      56,    66,    77,    78,    66,    64,    64,    66,    66,    95,
       4,    97,    96,   103,   421,   113,   108,   103,   102,    97,
      76,    75,    76,   113,   105,   103,   103,   113,    95,   169,
      95,    51,    87,   118,   441,   113,   113,    99,   113,   114,
      60,   100,   100,    97,    64,    96,   113,   101,   113,    69,
       3,     4,     5,   108,    97,    64,    97,   368,    64,   153,
     103,    81,   103,   104,    98,   120,   121,   102,   102,   450,
      90,   191,    92,   194,   196,    66,   276,   229,    98,   390,
      96,   411,   393,   138,    96,   105,   102,   100,   240,   102,
     102,    44,    45,    46,    47,    48,   236,    96,   102,    96,
      66,   105,   194,   102,   228,   102,   252,   253,   254,   255,
     102,    99,    63,   105,   425,    66,   102,   102,    63,   105,
     105,    66,    96,    97,   264,     3,     4,     5,    97,     6,
       7,     8,   443,   153,    44,    45,    46,    99,   278,   194,
     110,   111,   112,    96,   296,   297,   267,    68,    69,    70,
     107,   303,   109,   103,   100,   307,   102,    73,    74,   359,
      79,    80,   102,   103,   316,   185,    44,    45,    46,    47,
      48,    66,   248,   249,    66,   267,   250,   251,   102,   102,
     301,    95,   102,   305,   384,   256,   257,   309,   113,   104,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   301,
      66,    66,   267,    95,   117,    96,   368,   116,   358,    95,
      81,   115,    69,    83,    98,    69,   378,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    69,   390,   105,
     105,   393,   442,   383,   366,    95,   301,   104,   100,    95,
      95,   105,    95,   104,    66,    95,   276,    98,    63,   411,
      96,   114,    66,    98,   284,   114,   114,   322,    66,    99,
     104,   104,    95,   425,   414,    51,    98,    98,   104,   104,
      96,    95,    66,   103,   102,    96,   103,   100,   358,   104,
      15,   443,    95,    66,    96,   105,   104,   104,    66,   105,
     440,     6,     7,     8,     9,    10,    11,   104,    66,   105,
      66,   105,    66,   383,    66,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
     105,    96,   114,    96,   114,   355,   105,   237,   358,   359,
     258,   105,   259,   105,   105,   105,    76,   260,    82,   261,
     105,     6,     7,     8,     9,    10,    11,   262,    90,   263,
     269,   441,   355,   383,   384,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
     122,    74,   284,   355,    64,   383,   408,   371,    -1,   429,
      -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   421,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   441,   442,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,   114,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    64,    -1,
      66,    67,    68,    69,    70,    -1,    72,    -1,    -1,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      -1,    -1,    -1,    99,   100,    -1,    -1,    -1,    -1,   105,
     106,   107,   108,   109,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    -1,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,    64,    -1,    66,    67,    68,
      69,    70,    -1,    72,    -1,    -1,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,
      99,   100,    -1,    -1,    -1,    -1,   105,   106,   107,   108,
     109,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      12,    13,    14,    -1,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    64,    -1,    66,    67,    68,    69,    70,    -1,
      72,    -1,    -1,    75,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,   105,   106,   107,   108,   109,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      -1,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    64,
      -1,    66,    67,    68,    69,    70,    -1,    72,    -1,    -1,
      75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
     105,   106,   107,   108,   109,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    47,
      48,    49,    50,    -1,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    64,    -1,    66,    67,
      68,    69,    70,    -1,    72,    -1,    -1,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,   105,   106,   107,
     108,   109,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    47,    48,    49,    50,    -1,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    64,
      -1,    66,    67,    68,    69,    70,    -1,    72,    -1,    -1,
      75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,    -1,
      95,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,   106,   107,   108,   109,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    47,    48,    49,    50,    -1,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    64,    -1,    -1,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,   105,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    64,    65,    66,    67,    68,    69,    70,    -1,    72,
      -1,    -1,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,     6,     7,     8,    99,    10,    11,    -1,
      -1,    -1,    -1,   106,   107,   108,   109,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    64,    -1,    66,    67,    68,    69,    70,    -1,    72,
      -1,    -1,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    -1,    -1,    -1,    99,   100,    -1,    -1,
      -1,    -1,    -1,   106,   107,   108,   109,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      49,    50,    -1,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,    64,    -1,    66,    67,    68,
      69,    70,    -1,    72,    -1,    -1,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    98,
       6,     7,     8,    -1,    10,    11,    -1,   106,   107,   108,
     109,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    49,    50,    -1,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    64,    -1,
      66,    67,    68,    69,    70,    -1,    72,    -1,    -1,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,   105,
     106,   107,   108,   109,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    49,    50,    -1,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    64,    -1,
      66,    67,    68,    69,    70,    -1,    72,    -1,    -1,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,
      -1,    -1,    98,     6,     7,     8,    -1,    10,    11,    -1,
     106,   107,   108,   109,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    64,    -1,    66,    67,    68,    69,    70,    -1,    72,
      -1,    -1,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,     6,     7,     8,    99,    10,    11,    -1,
      -1,    -1,    -1,   106,   107,   108,   109,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    64,    -1,    66,    67,    68,    69,    70,    -1,    72,
      -1,    -1,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,   106,   107,   108,   109,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    64,    -1,    66,    67,    68,    69,    70,    -1,    72,
      -1,    -1,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,   106,   107,   108,   109,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    47,    48,    49,
      50,    -1,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    64,    -1,    -1,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    49,    50,
      -1,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    64,    -1,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    49,
      50,    -1,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    64,    -1,    -1,    67,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
     100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      68,    69,    70,    71,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    99,    47,    48,    49,    50,    -1,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    64,
      -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    49,
      50,    -1,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    64,    -1,    66,    67,    -1,     6,
       7,     8,    72,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    49,    50,    -1,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    64,    -1,    -1,
      67
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    10,    11,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    47,    48,    49,    50,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    64,    67,    94,
     105,   120,   149,   150,   151,   152,   153,   158,   159,   160,
     161,   162,   163,   164,   191,   192,   193,     4,    66,    99,
     113,    94,   160,   105,   194,    96,   102,    44,    45,    46,
     155,   156,   161,   102,   105,    66,   162,    97,     0,   192,
      99,   162,   165,   166,     6,     7,     8,    66,    99,   177,
     103,   155,   154,   157,   162,   156,    66,    95,    97,   103,
     113,   197,   206,   207,   208,    66,    68,    69,    70,    72,
      75,    76,    95,   106,   107,   108,   109,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   148,   162,   165,    66,   167,   168,   100,   166,   102,
     102,   102,    95,    12,    13,    14,    16,    17,    18,    19,
      51,    99,   100,   105,   131,   144,   145,   147,   149,   150,
     162,   170,   171,   172,   173,   178,   179,   180,   183,   190,
      66,    66,   154,   157,    97,   208,    98,   148,    63,    66,
       6,     7,     8,     9,    10,    11,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,   114,   198,   199,   200,   197,   103,   197,   206,   104,
     131,   131,   147,   163,    75,    76,    97,   101,    96,    96,
     102,    50,   145,    95,   131,   110,   111,   112,   107,   109,
      73,    74,    77,    78,   113,   114,    79,    80,   117,   116,
     115,    81,    83,    82,   118,    98,   100,    97,   103,   102,
     105,    69,    69,    69,   105,   105,   185,    95,    95,   105,
     105,   147,    95,   100,   174,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,   104,   146,   102,   105,   100,
     171,    97,   103,   104,   206,    98,   148,   104,   208,    98,
      95,   114,   199,    66,   197,    65,    99,   145,   169,   195,
     209,    96,    96,   147,    66,    72,   126,   145,   131,   131,
     131,   133,   133,   134,   134,   135,   135,   135,   135,   136,
     136,   137,   138,   139,   140,   141,   142,   147,   148,    66,
     168,   114,   114,   114,   171,   186,   147,   105,   184,   178,
     145,   145,   148,    66,   169,   208,    98,   169,   104,   208,
      66,   104,    99,   145,   195,   196,   131,    98,   103,    98,
      51,   170,   179,   187,    96,   147,   160,   182,   175,    98,
     104,   208,   169,   104,    96,    68,    69,    70,    71,    99,
     200,   201,   202,   203,   205,    64,    66,   100,   210,   211,
     100,   102,   145,   103,    95,   182,   188,   189,   171,   181,
      66,    96,   100,   103,   169,   104,   169,   202,   204,    95,
     105,   104,   104,   100,   211,   100,   145,   195,    66,   147,
     105,    96,    15,   104,   172,   176,   177,    66,   169,   100,
     102,   204,    66,    95,   113,    66,    95,   113,    96,   147,
     176,   171,   169,   202,    96,   105,    66,    66,   105,    66,
      66,   105,    96,   114,    96,   114,   105,   105,   105,   105
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   119,   120,   120,   121,   122,   122,   122,   122,   122,
     123,   123,   123,   123,   123,   123,   124,   125,   125,   126,
     126,   127,   127,   128,   128,   129,   130,   130,   130,   131,
     131,   131,   131,   131,   132,   132,   132,   132,   133,   133,
     133,   133,   134,   134,   134,   135,   135,   135,   136,   136,
     136,   136,   136,   137,   137,   137,   138,   138,   139,   139,
     140,   140,   141,   141,   142,   142,   143,   143,   144,   144,
     145,   145,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   147,   147,   148,   149,   149,   150,   150,
     151,   151,   152,   152,   153,   153,   154,   154,   154,   154,
     154,   154,   155,   155,   155,   155,   156,   156,   156,   156,
     157,   158,   158,   158,   158,   158,   158,   158,   159,   159,
     159,   159,   159,   159,   159,   160,   160,   161,   161,   161,
     161,   161,   161,   162,   162,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     164,   164,   165,   165,   166,   167,   167,   168,   168,   168,
     168,   169,   169,   169,   170,   171,   171,   172,   172,   172,
     172,   172,   173,   174,   175,   173,   176,   176,   177,   177,
     178,   178,   179,   179,   180,   181,   181,   182,   182,   184,
     183,   185,   183,   186,   183,   187,   187,   188,   188,   189,
     189,   190,   190,   190,   190,   190,   191,   191,   192,   192,
     192,   194,   193,   195,   195,   196,   196,   196,   196,   197,
     197,   198,   198,   199,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   201,   201,   201,   201,   202,
     202,   202,   203,   204,   204,   205,   206,   207,   208,   208,
     208,   208,   208,   208,   208,   208,   209,   209,   210,   210,
     211,   211,   211,   211,   211,   211
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     3,
       1,     4,     1,     3,     2,     2,     1,     1,     3,     2,
       2,     2,     1,     2,     3,     2,     1,     1,     1,     1,
       2,     2,     2,     4,     1,     1,     1,     1,     1,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     5,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     2,     2,     2,     4,
       1,     1,     2,     3,     3,     4,     2,     4,     3,     4,
       5,     7,     3,     2,     3,     2,     0,     1,     1,     1,
       1,     1,     4,     6,     7,     8,     9,     6,     1,     3,
       5,     6,     7,     8,     5,     1,     2,     1,     1,     2,
       1,     1,     1,     1,     4,     1,     1,     1,     1,     1,
       1,     6,     6,     6,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     4,     1,     2,     3,     1,     3,     1,     3,     4,
       6,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     0,     0,     5,     1,     1,     2,     3,
       1,     2,     1,     2,     5,     3,     1,     1,     4,     0,
       6,     0,     8,     0,     7,     1,     1,     1,     0,     2,
       3,     2,     2,     2,     3,     2,     1,     2,     1,     1,
       1,     0,     3,     3,     4,     1,     1,     3,     3,     2,
       3,     1,     2,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     3,     3,     5,     2,     0,     1,
       1,     1,     2,     2,     2,     3,     4,     3,     1,     2,
       4,     6,     6,     4,     6,     6
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
        yyerror (parseContextLocal, YY_("syntax error: cannot back up")); \
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
                  Kind, Value, parseContextLocal); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void* parseContextLocal)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (parseContextLocal);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void* parseContextLocal)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, parseContextLocal);
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
                 int yyrule, void* parseContextLocal)
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
                       &yyvsp[(yyi + 1) - (yynrhs)], parseContextLocal);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, parseContextLocal); \
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, void* parseContextLocal)
{
  YY_USE (yyvaluep);
  YY_USE (parseContextLocal);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (void* parseContextLocal)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

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
      yychar = yylex (&yylval, parseContextLocal);
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
  case 2: /* profile_list: PROFILE  */
#line 182 "hlslang.y"
                  {(yyval.lex).string = NewPoolTString("@"); *(yyval.lex).string += *(yyvsp[0].lex).string;}
#line 2121 "hlslang_tab.cpp"
    break;

  case 3: /* profile_list: profile_list PROFILE  */
#line 183 "hlslang.y"
                                {*(yyval.lex).string += "@";  *(yyval.lex).string += *(yyvsp[0].lex).string;}
#line 2127 "hlslang_tab.cpp"
    break;

  case 4: /* variable_identifier: IDENTIFIER  */
#line 187 "hlslang.y"
                 {
        // The symbol table search was done in the lexical phase
        const TSymbol* symbol = (yyvsp[0].lex).symbol;
        const TVariable* variable;
        if (symbol == 0) {
            parseContext.error((yyvsp[0].lex).line, "undeclared identifier", (yyvsp[0].lex).string->c_str(), "");
            parseContext.recover();
            TType type(EbtFloat, EbpUndefined);
            TVariable* fakeVariable = new TVariable((yyvsp[0].lex).string, type);
            parseContext.symbolTable.insert(*fakeVariable);
            variable = fakeVariable;
        } else {
            // This identifier can only be a variable type symbol 
            if (! symbol->isVariable()) {
                parseContext.error((yyvsp[0].lex).line, "variable expected", (yyvsp[0].lex).string->c_str(), "");
                parseContext.recover();
            }
            variable = static_cast<const TVariable*>(symbol);
        }

        // don't delete $1.string, it's used by error recovery, and the pool
        // pop will reclaim the memory
		TIntermSymbol* sym = parseContext.intermediate.addSymbol(variable->getUniqueId(), 
                                                     variable->getName(),
                                                     variable->getInfo(), 
                                                     variable->getType(), (yyvsp[0].lex).line);
		sym->setGlobal(variable->isGlobal());
		(yyval.interm.intermTypedNode) = sym;
    }
#line 2161 "hlslang_tab.cpp"
    break;

  case 5: /* primary_expression: variable_identifier  */
#line 219 "hlslang.y"
                          {
        (yyval.interm.intermTypedNode) = (yyvsp[0].interm.intermTypedNode);
    }
#line 2169 "hlslang_tab.cpp"
    break;

  case 6: /* primary_expression: INTCONSTANT  */
#line 222 "hlslang.y"
                  {
        TIntermConstant* constant = parseContext.intermediate.addConstant(TType(EbtInt, EbpUndefined, EvqConst), (yyvsp[0].lex).line);
		constant->setValue((yyvsp[0].lex).i);
		(yyval.interm.intermTypedNode) = constant;
    }
#line 2179 "hlslang_tab.cpp"
    break;

  case 7: /* primary_expression: FLOATCONSTANT  */
#line 227 "hlslang.y"
                    {
        TIntermConstant* constant = parseContext.intermediate.addConstant(TType(EbtFloat, EbpUndefined, EvqConst), (yyvsp[0].lex).line);
		constant->setValue((yyvsp[0].lex).f);
		(yyval.interm.intermTypedNode) = constant;
    }
#line 2189 "hlslang_tab.cpp"
    break;

  case 8: /* primary_expression: BOOLCONSTANT  */
#line 232 "hlslang.y"
                   {
        TIntermConstant* constant = parseContext.intermediate.addConstant(TType(EbtBool, EbpUndefined, EvqConst), (yyvsp[0].lex).line);
		constant->setValue((yyvsp[0].lex).b);
		(yyval.interm.intermTypedNode) = constant;
    }
#line 2199 "hlslang_tab.cpp"
    break;

  case 9: /* primary_expression: LEFT_PAREN expression RIGHT_PAREN  */
#line 237 "hlslang.y"
                                        {
        (yyval.interm.intermTypedNode) = (yyvsp[-1].interm.intermTypedNode);
    }
#line 2207 "hlslang_tab.cpp"
    break;

  case 10: /* postfix_expression: primary_expression  */
#line 243 "hlslang.y"
                         { 
        (yyval.interm.intermTypedNode) = (yyvsp[0].interm.intermTypedNode);
    }
#line 2215 "hlslang_tab.cpp"
    break;

  case 11: /* postfix_expression: postfix_expression LEFT_BRACKET expression RIGHT_BRACKET  */
#line 246 "hlslang.y"
                                                               {
        if (!(yyvsp[-3].interm.intermTypedNode)) {
            parseContext.error((yyvsp[-2].lex).line, " left of '[' is null ", "expression", "");
            YYERROR;
        }
        TIntermTyped *exprNode = (yyvsp[-1].interm.intermTypedNode);
        //auto conversion to int
        if (exprNode->getBasicType() != EbtInt || exprNode->getNominalSize() != 1)
        {
			TIntermTyped *newNode = parseContext.intermediate.addConversion(EOpConstructInt, TType(EbtInt, EbpUndefined), exprNode);
			if (!newNode)
			{
				parseContext.error((yyvsp[-2].lex).line, "cannot convert to integer", "[]", "");
				parseContext.recover();
			}
			else
				exprNode = newNode;
        }
        
        bool isNonSquareMatrix =  (yyvsp[-3].interm.intermTypedNode)->isNonSquareMatrix();
        if (!(yyvsp[-3].interm.intermTypedNode)->isArray() && !(yyvsp[-3].interm.intermTypedNode)->isMatrix() && !(yyvsp[-3].interm.intermTypedNode)->isVector() && !isNonSquareMatrix) {
            if ((yyvsp[-3].interm.intermTypedNode)->getAsSymbolNode())
                parseContext.error((yyvsp[-2].lex).line, " left of '[' is not of type array, matrix, or vector ", (yyvsp[-3].interm.intermTypedNode)->getAsSymbolNode()->getSymbol().c_str(), "");
            else
                parseContext.error((yyvsp[-2].lex).line, " left of '[' is not of type array, matrix, or vector ", "expression", "");
            parseContext.recover();
        }
		if (exprNode->getQualifier() == EvqConst) {
			if (((((yyvsp[-3].interm.intermTypedNode)->isVector() || (yyvsp[-3].interm.intermTypedNode)->isMatrix()) && (yyvsp[-3].interm.intermTypedNode)->getType().getNominalSize() <= exprNode->getAsConstant()->toInt()) 
			    || (isNonSquareMatrix && (yyvsp[-3].interm.intermTypedNode)->getType().getNonSquareColumns() <= exprNode->getAsConstant()->toInt())) 
			    && !(yyvsp[-3].interm.intermTypedNode)->isArray() ) {
				parseContext.error((yyvsp[-2].lex).line, "", "[", "field selection out of range '%d'", exprNode->getAsConstant()->toInt());
				parseContext.recover();
			} else {
				if ((yyvsp[-3].interm.intermTypedNode)->isArray()) {
					if ((yyvsp[-3].interm.intermTypedNode)->getType().getArraySize() == 0) {
						if ((yyvsp[-3].interm.intermTypedNode)->getType().getMaxArraySize() <= exprNode->getAsConstant()->toInt()) {
							if (parseContext.arraySetMaxSize((yyvsp[-3].interm.intermTypedNode)->getAsSymbolNode(), (yyvsp[-3].interm.intermTypedNode)->getTypePointer(), exprNode->getAsConstant()->toInt(), true, (yyvsp[-2].lex).line))
								parseContext.recover(); 
						} else {
							if (parseContext.arraySetMaxSize((yyvsp[-3].interm.intermTypedNode)->getAsSymbolNode(), (yyvsp[-3].interm.intermTypedNode)->getTypePointer(), 0, false, (yyvsp[-2].lex).line))
								parseContext.recover(); 
						}
					} else if ( exprNode->getAsConstant()->toInt() >= (yyvsp[-3].interm.intermTypedNode)->getType().getArraySize()) {
						parseContext.error((yyvsp[-2].lex).line, "", "[", "array index out of range '%d'", exprNode->getAsConstant()->toInt());
						parseContext.recover();
					}
				}
				if (isNonSquareMatrix && !(yyvsp[-3].interm.intermTypedNode)->isArray())
				{
					unsigned int i = (yyvsp[-3].interm.intermTypedNode)->getType().getNonSquareFieldIndex(exprNode->getAsConstant()->toInt());
					TTypeList* fields = (yyvsp[-3].interm.intermTypedNode)->getType().getStruct();
					TIntermConstant* index = parseContext.intermediate.addConstant(TType(EbtInt, EbpUndefined, EvqConst), (yyvsp[-2].lex).line);
					index->setValue(i);
					(yyval.interm.intermTypedNode) = parseContext.intermediate.addIndex(EOpIndexDirectStruct, (yyvsp[-3].interm.intermTypedNode), index, (yyvsp[-2].lex).line);                
					(yyval.interm.intermTypedNode)->setType(*(*fields)[i].type);
				}
				else
					(yyval.interm.intermTypedNode) = parseContext.intermediate.addIndex(EOpIndexDirect, (yyvsp[-3].interm.intermTypedNode), exprNode, (yyvsp[-2].lex).line);
			}
		} else {
			if ((yyvsp[-3].interm.intermTypedNode)->isArray() && (yyvsp[-3].interm.intermTypedNode)->getType().getArraySize() == 0) {
				parseContext.error((yyvsp[-2].lex).line, "", "[", "array must be redeclared with a size before being indexed with a variable");
				parseContext.recover();
			}
			if (isNonSquareMatrix && !(yyvsp[-3].interm.intermTypedNode)->isArray())
			{
				parseContext.error((yyvsp[-2].lex).line, "", "[", "field index of non square matrix must be constant");
				parseContext.recover();
			}
			
			(yyval.interm.intermTypedNode) = parseContext.intermediate.addIndex(EOpIndexIndirect, (yyvsp[-3].interm.intermTypedNode), exprNode, (yyvsp[-2].lex).line);
		}
        if ((yyval.interm.intermTypedNode) == 0) {
            TIntermConstant* constant = parseContext.intermediate.addConstant(TType(EbtFloat, EbpUndefined, EvqConst), (yyvsp[-2].lex).line);
			constant->setValue(0.f);
			(yyval.interm.intermTypedNode) = constant;
        } else if ((yyvsp[-3].interm.intermTypedNode)->isArray()) {
            if ((yyvsp[-3].interm.intermTypedNode)->getType().getStruct())
                (yyval.interm.intermTypedNode)->setType(TType((yyvsp[-3].interm.intermTypedNode)->getType().getStruct(), (yyvsp[-3].interm.intermTypedNode)->getType().getTypeName(), EbpUndefined, (yyvsp[-3].interm.intermTypedNode)->getLine()));
            else
                (yyval.interm.intermTypedNode)->setType(TType((yyvsp[-3].interm.intermTypedNode)->getBasicType(), (yyvsp[-3].interm.intermTypedNode)->getPrecision(), EvqTemporary, (yyvsp[-3].interm.intermTypedNode)->getNominalSize(), (yyvsp[-3].interm.intermTypedNode)->isMatrix()));
                
            if ((yyvsp[-3].interm.intermTypedNode)->getType().getQualifier() == EvqConst)
                (yyval.interm.intermTypedNode)->getTypePointer()->changeQualifier(EvqConst);
        } else if ((yyvsp[-3].interm.intermTypedNode)->isMatrix() && (yyvsp[-3].interm.intermTypedNode)->getType().getQualifier() == EvqConst)         
            (yyval.interm.intermTypedNode)->setType(TType((yyvsp[-3].interm.intermTypedNode)->getBasicType(), (yyvsp[-3].interm.intermTypedNode)->getPrecision(), EvqConst, (yyvsp[-3].interm.intermTypedNode)->getNominalSize()));     
        else if ((yyvsp[-3].interm.intermTypedNode)->isMatrix())            
            (yyval.interm.intermTypedNode)->setType(TType((yyvsp[-3].interm.intermTypedNode)->getBasicType(), (yyvsp[-3].interm.intermTypedNode)->getPrecision(), EvqTemporary, (yyvsp[-3].interm.intermTypedNode)->getNominalSize()));     
        else if ((yyvsp[-3].interm.intermTypedNode)->isVector() && (yyvsp[-3].interm.intermTypedNode)->getType().getQualifier() == EvqConst)          
            (yyval.interm.intermTypedNode)->setType(TType((yyvsp[-3].interm.intermTypedNode)->getBasicType(), (yyvsp[-3].interm.intermTypedNode)->getPrecision(), EvqConst));
        else if ((yyvsp[-3].interm.intermTypedNode)->isVector())       
            (yyval.interm.intermTypedNode)->setType(TType((yyvsp[-3].interm.intermTypedNode)->getBasicType(), (yyvsp[-3].interm.intermTypedNode)->getPrecision(), EvqTemporary));
        else if (!isNonSquareMatrix)
            (yyval.interm.intermTypedNode)->setType((yyvsp[-3].interm.intermTypedNode)->getType()); 
    }
#line 2316 "hlslang_tab.cpp"
    break;

  case 12: /* postfix_expression: function_call  */
#line 342 "hlslang.y"
                    {
        (yyval.interm.intermTypedNode) = (yyvsp[0].interm.intermTypedNode);
    }
#line 2324 "hlslang_tab.cpp"
    break;

  case 13: /* postfix_expression: postfix_expression DOT FIELD_SELECTION  */
#line 345 "hlslang.y"
                                             {      
		if (!(yyvsp[-2].interm.intermTypedNode)) {
            parseContext.error((yyvsp[0].lex).line, "field selection on null object", ".", "");
            YYERROR;
		}  
        if ((yyvsp[-2].interm.intermTypedNode)->isArray()) {
            parseContext.error((yyvsp[0].lex).line, "cannot apply dot operator to an array", ".", "");
            parseContext.recover();
        }

        if ((yyvsp[-2].interm.intermTypedNode)->isVector()) {
            TVectorFields fields;
            if (! parseContext.parseVectorFields(*(yyvsp[0].lex).string, (yyvsp[-2].interm.intermTypedNode)->getNominalSize(), fields, (yyvsp[0].lex).line)) {
                fields.num = 1;
                fields.offsets[0] = 0;
                parseContext.recover();
            }

			if (fields.num == 1) {
				TIntermConstant* index = parseContext.intermediate.addConstant(TType(EbtInt, EbpUndefined, EvqConst), (yyvsp[0].lex).line);
				index->setValue(fields.offsets[0]);
				(yyval.interm.intermTypedNode) = parseContext.intermediate.addIndex(EOpIndexDirect, (yyvsp[-2].interm.intermTypedNode), index, (yyvsp[-1].lex).line);
				(yyval.interm.intermTypedNode)->setType(TType((yyvsp[-2].interm.intermTypedNode)->getBasicType(), (yyvsp[-2].interm.intermTypedNode)->getPrecision()));
			} else {
				TString vectorString = *(yyvsp[0].lex).string;
				TIntermTyped* index = parseContext.intermediate.addSwizzle(fields, (yyvsp[0].lex).line);                
				(yyval.interm.intermTypedNode) = parseContext.intermediate.addIndex(EOpVectorSwizzle, (yyvsp[-2].interm.intermTypedNode), index, (yyvsp[-1].lex).line);
				(yyval.interm.intermTypedNode)->setType(TType((yyvsp[-2].interm.intermTypedNode)->getBasicType(), (yyvsp[-2].interm.intermTypedNode)->getPrecision(), EvqTemporary, (int) vectorString.size()));  
			}
        } else if ((yyvsp[-2].interm.intermTypedNode)->isMatrix()) {
            TVectorFields fields;
            if (! parseContext.parseMatrixFields(*(yyvsp[0].lex).string, (yyvsp[-2].interm.intermTypedNode)->getNominalSize(), fields, (yyvsp[0].lex).line)) {
                fields.num = 1;
                fields.offsets[0] = 0;
                parseContext.recover();
            }

            TString vectorString = *(yyvsp[0].lex).string;
            TIntermTyped* index = parseContext.intermediate.addSwizzle(fields, (yyvsp[0].lex).line);                
            (yyval.interm.intermTypedNode) = parseContext.intermediate.addIndex(EOpMatrixSwizzle, (yyvsp[-2].interm.intermTypedNode), index, (yyvsp[-1].lex).line);
            (yyval.interm.intermTypedNode)->setType(TType((yyvsp[-2].interm.intermTypedNode)->getBasicType(), (yyvsp[-2].interm.intermTypedNode)->getPrecision(), EvqTemporary, fields.num));
                    
        } else if ((yyvsp[-2].interm.intermTypedNode)->getBasicType() == EbtStruct) {
            bool fieldFound = false;
            TTypeList* fields = (yyvsp[-2].interm.intermTypedNode)->getType().getStruct();
            if (fields == 0) {
                parseContext.error((yyvsp[-1].lex).line, "structure has no fields", "Internal Error", "");
                parseContext.recover();
                (yyval.interm.intermTypedNode) = (yyvsp[-2].interm.intermTypedNode);
            } else {
                unsigned int i;
                for (i = 0; i < fields->size(); ++i) {
                    if ((*fields)[i].type->getFieldName() == *(yyvsp[0].lex).string) {
                        fieldFound = true;
                        break;
                    }                
                }
                if (fieldFound) {
					TIntermConstant* index = parseContext.intermediate.addConstant(TType(EbtInt, EbpUndefined, EvqConst), (yyvsp[0].lex).line);
					index->setValue(i);
					(yyval.interm.intermTypedNode) = parseContext.intermediate.addIndex(EOpIndexDirectStruct, (yyvsp[-2].interm.intermTypedNode), index, (yyvsp[-1].lex).line);                
					(yyval.interm.intermTypedNode)->setType(*(*fields)[i].type);
                } else {
                    parseContext.error((yyvsp[-1].lex).line, " no such field in structure", (yyvsp[0].lex).string->c_str(), "");
                    parseContext.recover();
                    (yyval.interm.intermTypedNode) = (yyvsp[-2].interm.intermTypedNode);
                }
            }
        } else if ((yyvsp[-2].interm.intermTypedNode)->getNominalSize() == 1) {

            // HLSL allows ".xxxx" field selection on single component floats.  Handle that here.
            TVectorFields fields;

            // Check to make sure only the "x" component is accessed.
            if (! parseContext.parseVectorFields(*(yyvsp[0].lex).string, (yyvsp[-2].interm.intermTypedNode)->getNominalSize(), fields, (yyvsp[0].lex).line)) {
                fields.num = 1;
                fields.offsets[0] = 0;
                parseContext.recover();
            }

            // Create the appropriate constructor based on the number of ".x"'s there are in the selection field
            TString vectorString = *(yyvsp[0].lex).string;
            TQualifier qualifier = (yyvsp[-2].interm.intermTypedNode)->getType().getQualifier() == EvqConst ? EvqConst : EvqTemporary;
            TType type((yyvsp[-2].interm.intermTypedNode)->getBasicType(), (yyvsp[-2].interm.intermTypedNode)->getPrecision(), qualifier, (int) vectorString.size());
            (yyval.interm.intermTypedNode) = parseContext.constructBuiltIn(&type, parseContext.getConstructorOp(type),
                                               (yyval.interm.intermTypedNode), (yyvsp[-2].interm.intermTypedNode)->getLine(), false);
        } else {
            parseContext.error((yyvsp[-1].lex).line, " field selection requires structure, vector, or matrix on left hand side", (yyvsp[0].lex).string->c_str(), "");
            parseContext.recover();
            (yyval.interm.intermTypedNode) = (yyvsp[-2].interm.intermTypedNode);
        }
        // don't delete $3.string, it's from the pool
    }
#line 2422 "hlslang_tab.cpp"
    break;

  case 14: /* postfix_expression: postfix_expression INC_OP  */
#line 438 "hlslang.y"
                                {
        if (parseContext.lValueErrorCheck((yyvsp[0].lex).line, "++", (yyvsp[-1].interm.intermTypedNode)))
            parseContext.recover();
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addUnaryMath(EOpPostIncrement, (yyvsp[-1].interm.intermTypedNode), (yyvsp[0].lex).line);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.unaryOpError((yyvsp[0].lex).line, "++", (yyvsp[-1].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            (yyval.interm.intermTypedNode) = (yyvsp[-1].interm.intermTypedNode);
        }
    }
#line 2437 "hlslang_tab.cpp"
    break;

  case 15: /* postfix_expression: postfix_expression DEC_OP  */
#line 448 "hlslang.y"
                                {
        if (parseContext.lValueErrorCheck((yyvsp[0].lex).line, "--", (yyvsp[-1].interm.intermTypedNode)))
            parseContext.recover();
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addUnaryMath(EOpPostDecrement, (yyvsp[-1].interm.intermTypedNode), (yyvsp[0].lex).line);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.unaryOpError((yyvsp[0].lex).line, "--", (yyvsp[-1].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            (yyval.interm.intermTypedNode) = (yyvsp[-1].interm.intermTypedNode);
        }
    }
#line 2452 "hlslang_tab.cpp"
    break;

  case 16: /* function_call: function_call_or_method  */
#line 469 "hlslang.y"
                              {
        TFunction* fnCall = (yyvsp[0].interm).function;
        TOperator op = fnCall->getBuiltInOp();
        
        if (op == EOpArrayLength) {
            if ((yyvsp[0].interm).intermNode->getAsTyped() == 0 || (yyvsp[0].interm).intermNode->getAsTyped()->getType().getArraySize() == 0) {
                parseContext.error((yyvsp[0].interm).line, "", fnCall->getName().c_str(), "array must be declared with a size before using this method");
                parseContext.recover();
            }

			TIntermConstant* constant = parseContext.intermediate.addConstant(TType(EbtInt, EbpUndefined, EvqConst), (yyvsp[0].interm).line);
			constant->setValue((yyvsp[0].interm).intermNode->getAsTyped()->getType().getArraySize());
            (yyval.interm.intermTypedNode) = constant;
        } else if (op != EOpNull) {
            //
            // Then this should be a constructor.
            // Don't go through the symbol table for constructors.  
            // Their parameters will be verified algorithmically.
            //
            TType type(EbtVoid, EbpUndefined);  // use this to get the type back
            if (parseContext.constructorErrorCheck((yyvsp[0].interm).line, (yyvsp[0].interm).intermNode, *fnCall, op, &type)) {
                (yyval.interm.intermTypedNode) = 0;
            } else {
                //
                // It's a constructor, of type 'type'.
                //
                (yyval.interm.intermTypedNode) = parseContext.addConstructor((yyvsp[0].interm).intermNode, &type, op, fnCall, (yyvsp[0].interm).line);
            }
            
            if ((yyval.interm.intermTypedNode) == 0) {        
                parseContext.recover();
                (yyval.interm.intermTypedNode) = parseContext.intermediate.setAggregateOperator(0, op, (yyvsp[0].interm).line);
				(yyval.interm.intermTypedNode)->setType(type);
            }
        } else {
            //
            // Not a constructor.  Find it in the symbol table.
            //
            const TFunction* fnCandidate;
            bool builtIn;
            fnCandidate = parseContext.findFunction((yyvsp[0].interm).line, fnCall, &builtIn);
            
            if ( fnCandidate && fnCandidate->getMangledName() != fnCall->getMangledName()) {
                //add constructors to arguments to ensure that they have proper types
                TIntermNode *temp = parseContext.promoteFunctionArguments( (yyvsp[0].interm).intermNode,
                                      fnCandidate);
                if (temp)
                    (yyvsp[0].interm).intermNode = temp;
                else {
                    parseContext.error( (yyvsp[0].interm).intermNode->getLine(), " unable to suitably promote arguments to function",
                                        fnCandidate->getName().c_str(), "");
                    fnCandidate = 0;
                }
            }
            
            if (fnCandidate) {
                //
                // A declared function.  But, it might still map to a built-in
                // operation.
                //
                op = fnCandidate->getBuiltInOp();
                if (builtIn && op != EOpNull) {
                    //
                    // A function call mapped to a built-in operation.
                    //
                    if (fnCandidate->getParamCount() == 1) {
                        //
                        // Treat it like a built-in unary operator.
                        //
                        (yyval.interm.intermTypedNode) = parseContext.intermediate.addUnaryMath(op, (yyvsp[0].interm).intermNode, gNullSourceLoc);
                        if ((yyval.interm.intermTypedNode) == 0)  {
                            parseContext.error((yyvsp[0].interm).intermNode->getLine(), " wrong operand type", "Internal Error", 
                                "built in unary operator function.  Type: %s",
                                static_cast<TIntermTyped*>((yyvsp[0].interm).intermNode)->getCompleteString().c_str());
                            YYERROR;
                        }
                    } else {
                        (yyval.interm.intermTypedNode) = parseContext.intermediate.setAggregateOperator((yyvsp[0].interm).intermAggregate, op, (yyvsp[0].interm).line);
						(yyval.interm.intermTypedNode)->setType(fnCandidate->getReturnType());
                    }
                } else {
                    // This is a real function call
                    
                    (yyval.interm.intermTypedNode) = parseContext.intermediate.setAggregateOperator((yyvsp[0].interm).intermAggregate, EOpFunctionCall, (yyvsp[0].interm).line);
                    (yyval.interm.intermTypedNode)->setType(fnCandidate->getReturnType());                   
                    
                    (yyval.interm.intermTypedNode)->getAsAggregate()->setName(fnCandidate->getMangledName());
                    (yyval.interm.intermTypedNode)->getAsAggregate()->setPlainName(fnCandidate->getOriginalName());

                    TQualifier qual;
                    for (int i = 0; i < fnCandidate->getParamCount(); ++i) {
                        qual = (*fnCandidate)[i].type->getQualifier();
                        if (qual == EvqOut || qual == EvqInOut) {
                            if (parseContext.lValueErrorCheck((yyval.interm.intermTypedNode)->getLine(), "assign", (yyval.interm.intermTypedNode)->getAsAggregate()->getSequence()[i]->getAsTyped())) {
                                parseContext.error((yyvsp[0].interm).intermNode->getLine(), "Constant value cannot be passed for 'out' or 'inout' parameters.", "Error", "");
                                parseContext.recover();
                            }
                        }
                    }
                }
                (yyval.interm.intermTypedNode)->setType(fnCandidate->getReturnType());
            } else {
                // error message was put out by PaFindFunction()
                // Put on a dummy node for error recovery
                
				TIntermConstant* constant = parseContext.intermediate.addConstant(TType(EbtFloat, EbpUndefined, EvqConst), (yyvsp[0].interm).line);
				constant->setValue(0.f);
				(yyval.interm.intermTypedNode) = constant;
                parseContext.recover();
            }
        }
        delete fnCall;
    }
#line 2570 "hlslang_tab.cpp"
    break;

  case 17: /* function_call_or_method: function_call_generic  */
#line 585 "hlslang.y"
                            {
        (yyval.interm) = (yyvsp[0].interm);
    }
#line 2578 "hlslang_tab.cpp"
    break;

  case 18: /* function_call_or_method: postfix_expression DOT function_call_generic  */
#line 588 "hlslang.y"
                                                   {
        if ((yyvsp[-2].interm.intermTypedNode)->isArray() && (yyvsp[0].interm).function->getName() == "length") {
            //
            // implement array.length()
            //            
            (yyval.interm) = (yyvsp[0].interm);
            (yyval.interm).intermNode = (yyvsp[-2].interm.intermTypedNode);
            (yyval.interm).function->relateToOperator(EOpArrayLength);
            
        } else {
            parseContext.error((yyvsp[0].interm).line, "methods are not supported", "", "");
            parseContext.recover();
            (yyval.interm) = (yyvsp[0].interm);
        }
    }
#line 2598 "hlslang_tab.cpp"
    break;

  case 19: /* function_call_generic: function_call_header_with_parameters RIGHT_PAREN  */
#line 606 "hlslang.y"
                                                       {
        (yyval.interm) = (yyvsp[-1].interm);
        (yyval.interm).line = (yyvsp[0].lex).line;
    }
#line 2607 "hlslang_tab.cpp"
    break;

  case 20: /* function_call_generic: function_call_header_no_parameters RIGHT_PAREN  */
#line 610 "hlslang.y"
                                                     {
        (yyval.interm) = (yyvsp[-1].interm);
        (yyval.interm).line = (yyvsp[0].lex).line;
    }
#line 2616 "hlslang_tab.cpp"
    break;

  case 21: /* function_call_header_no_parameters: function_call_header VOID_TYPE  */
#line 617 "hlslang.y"
                                     {
        (yyval.interm).function = (yyvsp[-1].interm.function);
        (yyval.interm).intermNode = 0;
    }
#line 2625 "hlslang_tab.cpp"
    break;

  case 22: /* function_call_header_no_parameters: function_call_header  */
#line 621 "hlslang.y"
                           {
        (yyval.interm).function = (yyvsp[0].interm.function);
        (yyval.interm).intermNode = 0;
    }
#line 2634 "hlslang_tab.cpp"
    break;

  case 23: /* function_call_header_with_parameters: function_call_header assignment_expression  */
#line 628 "hlslang.y"
                                                 {
		if (!(yyvsp[0].interm.intermTypedNode)) {
          YYERROR;
		}
		TParameter param = { 0, 0, new TType((yyvsp[0].interm.intermTypedNode)->getType()) };
        (yyvsp[-1].interm.function)->addParameter(param);
        (yyval.interm).function = (yyvsp[-1].interm.function);
        (yyval.interm).intermNode = (yyvsp[0].interm.intermTypedNode);
    }
#line 2648 "hlslang_tab.cpp"
    break;

  case 24: /* function_call_header_with_parameters: function_call_header_with_parameters COMMA assignment_expression  */
#line 637 "hlslang.y"
                                                                       {
		if (!(yyvsp[0].interm.intermTypedNode)) {
          YYERROR;
		}
        TParameter param = { 0, 0, new TType((yyvsp[0].interm.intermTypedNode)->getType()) };
        (yyvsp[-2].interm).function->addParameter(param);
        (yyval.interm).function = (yyvsp[-2].interm).function;
        (yyval.interm).intermNode = parseContext.intermediate.growAggregate((yyvsp[-2].interm).intermNode, (yyvsp[0].interm.intermTypedNode), (yyvsp[-1].lex).line);
    }
#line 2662 "hlslang_tab.cpp"
    break;

  case 25: /* function_call_header: function_identifier LEFT_PAREN  */
#line 649 "hlslang.y"
                                     {
        (yyval.interm.function) = (yyvsp[-1].interm.function);
    }
#line 2670 "hlslang_tab.cpp"
    break;

  case 26: /* function_identifier: type_specifier  */
#line 657 "hlslang.y"
                     {
        //
        // Constructor
        //
        if ((yyvsp[0].interm.type).array) {
            //TODO : figure out how to deal with array constructors            
        }

        if ((yyvsp[0].interm.type).userDef) {
            TString tempString = "";
            TType type((yyvsp[0].interm.type));
            TFunction *function = new TFunction(&tempString, type, EOpConstructStruct);
            (yyval.interm.function) = function;
        } else {
            TOperator op = EOpNull;
            switch ((yyvsp[0].interm.type).type) {
            case EbtFloat:
                if ((yyvsp[0].interm.type).matrix) {
                    switch((yyvsp[0].interm.type).size) {
                    case 2:                                     op = EOpConstructMat2;  break;
                    case 3:                                     op = EOpConstructMat3;  break;
                    case 4:                                     op = EOpConstructMat4;  break;
                    }         
                } else {      
                    switch((yyvsp[0].interm.type).size) {
                    case 1:                                     op = EOpConstructFloat; break;
                    case 2:                                     op = EOpConstructVec2;  break;
                    case 3:                                     op = EOpConstructVec3;  break;
                    case 4:                                     op = EOpConstructVec4;  break;
                    }       
                }  
                break;               
            case EbtInt:
                switch((yyvsp[0].interm.type).size) {
                case 1:                                         op = EOpConstructInt;   break;
                case 2:       FRAG_VERT_ONLY("ivec2", (yyvsp[0].interm.type).line); op = EOpConstructIVec2; break;
                case 3:       FRAG_VERT_ONLY("ivec3", (yyvsp[0].interm.type).line); op = EOpConstructIVec3; break;
                case 4:       FRAG_VERT_ONLY("ivec4", (yyvsp[0].interm.type).line); op = EOpConstructIVec4; break;
                }         
                break;    
            case EbtBool:
                switch((yyvsp[0].interm.type).size) {
                case 1:                                         op = EOpConstructBool;  break;
                case 2:       FRAG_VERT_ONLY("bvec2", (yyvsp[0].interm.type).line); op = EOpConstructBVec2; break;
                case 3:       FRAG_VERT_ONLY("bvec3", (yyvsp[0].interm.type).line); op = EOpConstructBVec3; break;
                case 4:       FRAG_VERT_ONLY("bvec4", (yyvsp[0].interm.type).line); op = EOpConstructBVec4; break;
                }         
                break;
            }
            if (op == EOpNull) {                    
                parseContext.error((yyvsp[0].interm.type).line, "cannot construct this type", TType::getBasicString((yyvsp[0].interm.type).type), "");
                parseContext.recover();
                (yyvsp[0].interm.type).type = EbtFloat;
                op = EOpConstructFloat;
            }            
            TString tempString = "";
            TType type((yyvsp[0].interm.type));
            TFunction *function = new TFunction(&tempString, type, op);
            (yyval.interm.function) = function;
        }
    }
#line 2736 "hlslang_tab.cpp"
    break;

  case 27: /* function_identifier: IDENTIFIER  */
#line 718 "hlslang.y"
                 {
        if (parseContext.reservedErrorCheck((yyvsp[0].lex).line, *(yyvsp[0].lex).string)) 
            parseContext.recover();
        TType type(EbtVoid, EbpUndefined);
	const TString *mangled;
	if ( *(yyvsp[0].lex).string == "main")
	    mangled = NewPoolTString("xlat_main");
	else
	    mangled = (yyvsp[0].lex).string;
        TFunction *function = new TFunction( mangled, type);
        (yyval.interm.function) = function;
    }
#line 2753 "hlslang_tab.cpp"
    break;

  case 28: /* function_identifier: FIELD_SELECTION  */
#line 730 "hlslang.y"
                      {
        if (parseContext.reservedErrorCheck((yyvsp[0].lex).line, *(yyvsp[0].lex).string)) 
            parseContext.recover();
        TType type(EbtVoid, EbpUndefined);
        TFunction *function = new TFunction((yyvsp[0].lex).string, type);
        (yyval.interm.function) = function;
    }
#line 2765 "hlslang_tab.cpp"
    break;

  case 29: /* unary_expression: postfix_expression  */
#line 740 "hlslang.y"
                         {
        (yyval.interm.intermTypedNode) = (yyvsp[0].interm.intermTypedNode);
    }
#line 2773 "hlslang_tab.cpp"
    break;

  case 30: /* unary_expression: INC_OP unary_expression  */
#line 743 "hlslang.y"
                              {
        if (parseContext.lValueErrorCheck((yyvsp[-1].lex).line, "++", (yyvsp[0].interm.intermTypedNode)))
            parseContext.recover();
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addUnaryMath(EOpPreIncrement, (yyvsp[0].interm.intermTypedNode), (yyvsp[-1].lex).line);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.unaryOpError((yyvsp[-1].lex).line, "++", (yyvsp[0].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            (yyval.interm.intermTypedNode) = (yyvsp[0].interm.intermTypedNode);
        }
    }
#line 2788 "hlslang_tab.cpp"
    break;

  case 31: /* unary_expression: DEC_OP unary_expression  */
#line 753 "hlslang.y"
                              {
        if (parseContext.lValueErrorCheck((yyvsp[-1].lex).line, "--", (yyvsp[0].interm.intermTypedNode)))
            parseContext.recover();
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addUnaryMath(EOpPreDecrement, (yyvsp[0].interm.intermTypedNode), (yyvsp[-1].lex).line);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.unaryOpError((yyvsp[-1].lex).line, "--", (yyvsp[0].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            (yyval.interm.intermTypedNode) = (yyvsp[0].interm.intermTypedNode);
        }
    }
#line 2803 "hlslang_tab.cpp"
    break;

  case 32: /* unary_expression: unary_operator unary_expression  */
#line 763 "hlslang.y"
                                      {
        if ((yyvsp[-1].interm).op != EOpNull) {
            (yyval.interm.intermTypedNode) = parseContext.intermediate.addUnaryMath((yyvsp[-1].interm).op, (yyvsp[0].interm.intermTypedNode), (yyvsp[-1].interm).line);
            if ((yyval.interm.intermTypedNode) == 0) {
                const char* errorOp = "";
                switch((yyvsp[-1].interm).op) {
                case EOpNegative:   errorOp = "-"; break;
                case EOpLogicalNot: errorOp = "!"; break;
                case EOpBitwiseNot: errorOp = "~"; break;
				default: break;
                }
                parseContext.unaryOpError((yyvsp[-1].interm).line, const_cast<char*> (errorOp), (yyvsp[0].interm.intermTypedNode)->getCompleteString());
                parseContext.recover();
                (yyval.interm.intermTypedNode) = (yyvsp[0].interm.intermTypedNode);
            }
        } else
            (yyval.interm.intermTypedNode) = (yyvsp[0].interm.intermTypedNode);
    }
#line 2826 "hlslang_tab.cpp"
    break;

  case 33: /* unary_expression: LEFT_PAREN type_specifier_nonarray RIGHT_PAREN unary_expression  */
#line 781 "hlslang.y"
                                                                      {
        // cast operator, insert constructor
        TOperator op = EOpNull;
        switch ((yyvsp[-2].interm.type).type) {
        case EbtFloat:
            if ((yyvsp[-2].interm.type).matrix) {
                switch((yyvsp[-2].interm.type).size) {
                case 2:                                     op = EOpConstructMat2;  break;
                case 3:                                     op = EOpConstructMat3;  break;
                case 4:                                     op = EOpConstructMat4;  break;
                }         
            } else {      
                switch((yyvsp[-2].interm.type).size) {
                case 1:                                     op = EOpConstructFloat; break;
                case 2:                                     op = EOpConstructVec2;  break;
                case 3:                                     op = EOpConstructVec3;  break;
                case 4:                                     op = EOpConstructVec4;  break;
                }       
            }  
            break;               
        case EbtInt:
            switch((yyvsp[-2].interm.type).size) {
            case 1:                                         op = EOpConstructInt;   break;
            case 2:       FRAG_VERT_ONLY("ivec2", (yyvsp[-2].interm.type).line); op = EOpConstructIVec2; break;
            case 3:       FRAG_VERT_ONLY("ivec3", (yyvsp[-2].interm.type).line); op = EOpConstructIVec3; break;
            case 4:       FRAG_VERT_ONLY("ivec4", (yyvsp[-2].interm.type).line); op = EOpConstructIVec4; break;
            }         
            break;    
        case EbtBool:
            switch((yyvsp[-2].interm.type).size) {
            case 1:                                         op = EOpConstructBool;  break;
            case 2:       FRAG_VERT_ONLY("bvec2", (yyvsp[-2].interm.type).line); op = EOpConstructBVec2; break;
            case 3:       FRAG_VERT_ONLY("bvec3", (yyvsp[-2].interm.type).line); op = EOpConstructBVec3; break;
            case 4:       FRAG_VERT_ONLY("bvec4", (yyvsp[-2].interm.type).line); op = EOpConstructBVec4; break;
            }         
            break;
        case EbtStruct:
            op = EOpConstructStruct;
            break;
        }
        if (op == EOpNull) {                    
            parseContext.error((yyvsp[-2].interm.type).line, "cannot cast this type", TType::getBasicString((yyvsp[-2].interm.type).type), "");
            parseContext.recover();
            (yyvsp[-2].interm.type).type = EbtFloat;
            op = EOpConstructFloat;
        }            
        TString tempString = "";
        TType type((yyvsp[-2].interm.type));
        TFunction *function = new TFunction(&tempString, type, op);
        TParameter param = { 0, 0, new TType((yyvsp[0].interm.intermTypedNode)->getType()) };
        function->addParameter(param);
        TType type2(EbtVoid, EbpUndefined);  // use this to get the type back
        if (parseContext.constructorErrorCheck((yyvsp[-2].interm.type).line, (yyvsp[0].interm.intermTypedNode), *function, op, &type2)) {
            (yyval.interm.intermTypedNode) = 0;
        } else {
            //
            // It's a constructor, of type 'type'.
            //
            (yyval.interm.intermTypedNode) = parseContext.addConstructor((yyvsp[0].interm.intermTypedNode), &type2, op, function, (yyvsp[-2].interm.type).line);
        }
        
        if ((yyval.interm.intermTypedNode) == 0) {        
            parseContext.recover();
            (yyval.interm.intermTypedNode) = parseContext.intermediate.setAggregateOperator(0, op, (yyvsp[-2].interm.type).line);
        } else {
			(yyval.interm.intermTypedNode)->setType(type2);
		}
	}
#line 2899 "hlslang_tab.cpp"
    break;

  case 34: /* unary_operator: PLUS  */
#line 853 "hlslang.y"
            { (yyval.interm).line = (yyvsp[0].lex).line; (yyval.interm).op = EOpNull; }
#line 2905 "hlslang_tab.cpp"
    break;

  case 35: /* unary_operator: DASH  */
#line 854 "hlslang.y"
            { (yyval.interm).line = (yyvsp[0].lex).line; (yyval.interm).op = EOpNegative; }
#line 2911 "hlslang_tab.cpp"
    break;

  case 36: /* unary_operator: BANG  */
#line 855 "hlslang.y"
            { (yyval.interm).line = (yyvsp[0].lex).line; (yyval.interm).op = EOpLogicalNot; }
#line 2917 "hlslang_tab.cpp"
    break;

  case 37: /* unary_operator: TILDE  */
#line 856 "hlslang.y"
            { UNSUPPORTED_FEATURE("~", (yyvsp[0].lex).line);  
              (yyval.interm).line = (yyvsp[0].lex).line; (yyval.interm).op = EOpBitwiseNot; }
#line 2924 "hlslang_tab.cpp"
    break;

  case 38: /* multiplicative_expression: unary_expression  */
#line 862 "hlslang.y"
                       { (yyval.interm.intermTypedNode) = (yyvsp[0].interm.intermTypedNode); }
#line 2930 "hlslang_tab.cpp"
    break;

  case 39: /* multiplicative_expression: multiplicative_expression STAR unary_expression  */
#line 863 "hlslang.y"
                                                      {
        FRAG_VERT_ONLY("*", (yyvsp[-1].lex).line);
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addBinaryMath(EOpMul, (yyvsp[-2].interm.intermTypedNode), (yyvsp[0].interm.intermTypedNode), (yyvsp[-1].lex).line);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[-1].lex).line, "*", (yyvsp[-2].interm.intermTypedNode)->getCompleteString(), (yyvsp[0].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            (yyval.interm.intermTypedNode) = (yyvsp[-2].interm.intermTypedNode);
        }
    }
#line 2944 "hlslang_tab.cpp"
    break;

  case 40: /* multiplicative_expression: multiplicative_expression SLASH unary_expression  */
#line 872 "hlslang.y"
                                                       {
        FRAG_VERT_ONLY("/", (yyvsp[-1].lex).line); 
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addBinaryMath(EOpDiv, (yyvsp[-2].interm.intermTypedNode), (yyvsp[0].interm.intermTypedNode), (yyvsp[-1].lex).line);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[-1].lex).line, "/", (yyvsp[-2].interm.intermTypedNode)->getCompleteString(), (yyvsp[0].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            (yyval.interm.intermTypedNode) = (yyvsp[-2].interm.intermTypedNode);
        }
    }
#line 2958 "hlslang_tab.cpp"
    break;

  case 41: /* multiplicative_expression: multiplicative_expression PERCENT unary_expression  */
#line 881 "hlslang.y"
                                                         {
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addBinaryMath(EOpMod, (yyvsp[-2].interm.intermTypedNode), (yyvsp[0].interm.intermTypedNode), (yyvsp[-1].lex).line);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[-1].lex).line, "%", (yyvsp[-2].interm.intermTypedNode)->getCompleteString(), (yyvsp[0].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            (yyval.interm.intermTypedNode) = (yyvsp[-2].interm.intermTypedNode);
        }
    }
#line 2971 "hlslang_tab.cpp"
    break;

  case 42: /* additive_expression: multiplicative_expression  */
#line 892 "hlslang.y"
                                { (yyval.interm.intermTypedNode) = (yyvsp[0].interm.intermTypedNode); }
#line 2977 "hlslang_tab.cpp"
    break;

  case 43: /* additive_expression: additive_expression PLUS multiplicative_expression  */
#line 893 "hlslang.y"
                                                         {  
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addBinaryMath(EOpAdd, (yyvsp[-2].interm.intermTypedNode), (yyvsp[0].interm.intermTypedNode), (yyvsp[-1].lex).line);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[-1].lex).line, "+", (yyvsp[-2].interm.intermTypedNode)->getCompleteString(), (yyvsp[0].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            (yyval.interm.intermTypedNode) = (yyvsp[-2].interm.intermTypedNode);
        }
    }
#line 2990 "hlslang_tab.cpp"
    break;

  case 44: /* additive_expression: additive_expression DASH multiplicative_expression  */
#line 901 "hlslang.y"
                                                         {
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addBinaryMath(EOpSub, (yyvsp[-2].interm.intermTypedNode), (yyvsp[0].interm.intermTypedNode), (yyvsp[-1].lex).line);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[-1].lex).line, "-", (yyvsp[-2].interm.intermTypedNode)->getCompleteString(), (yyvsp[0].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            (yyval.interm.intermTypedNode) = (yyvsp[-2].interm.intermTypedNode);
        } 
    }
#line 3003 "hlslang_tab.cpp"
    break;

  case 45: /* shift_expression: additive_expression  */
#line 912 "hlslang.y"
                          { (yyval.interm.intermTypedNode) = (yyvsp[0].interm.intermTypedNode); }
#line 3009 "hlslang_tab.cpp"
    break;

  case 46: /* shift_expression: shift_expression LEFT_OP additive_expression  */
#line 913 "hlslang.y"
                                                   {
        UNSUPPORTED_FEATURE("<<", (yyvsp[-1].lex).line);
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addBinaryMath(EOpLeftShift, (yyvsp[-2].interm.intermTypedNode), (yyvsp[0].interm.intermTypedNode), (yyvsp[-1].lex).line);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[-1].lex).line, "<<", (yyvsp[-2].interm.intermTypedNode)->getCompleteString(), (yyvsp[0].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            (yyval.interm.intermTypedNode) = (yyvsp[-2].interm.intermTypedNode);
        }
    }
#line 3023 "hlslang_tab.cpp"
    break;

  case 47: /* shift_expression: shift_expression RIGHT_OP additive_expression  */
#line 922 "hlslang.y"
                                                    {
        UNSUPPORTED_FEATURE(">>", (yyvsp[-1].lex).line);
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addBinaryMath(EOpRightShift, (yyvsp[-2].interm.intermTypedNode), (yyvsp[0].interm.intermTypedNode), (yyvsp[-1].lex).line);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[-1].lex).line, ">>", (yyvsp[-2].interm.intermTypedNode)->getCompleteString(), (yyvsp[0].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            (yyval.interm.intermTypedNode) = (yyvsp[-2].interm.intermTypedNode);
        }
    }
#line 3037 "hlslang_tab.cpp"
    break;

  case 48: /* relational_expression: shift_expression  */
#line 934 "hlslang.y"
                       { (yyval.interm.intermTypedNode) = (yyvsp[0].interm.intermTypedNode); }
#line 3043 "hlslang_tab.cpp"
    break;

  case 49: /* relational_expression: relational_expression LEFT_ANGLE shift_expression  */
#line 935 "hlslang.y"
                                                        { 
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addBinaryMath(EOpLessThan, (yyvsp[-2].interm.intermTypedNode), (yyvsp[0].interm.intermTypedNode), (yyvsp[-1].lex).line);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[-1].lex).line, "<", (yyvsp[-2].interm.intermTypedNode)->getCompleteString(), (yyvsp[0].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            TIntermConstant* constant = parseContext.intermediate.addConstant(TType(EbtBool, EbpUndefined, EvqConst), (yyvsp[-1].lex).line);
			constant->setValue(false);
			(yyval.interm.intermTypedNode) = constant;
        }
    }
#line 3058 "hlslang_tab.cpp"
    break;

  case 50: /* relational_expression: relational_expression RIGHT_ANGLE shift_expression  */
#line 945 "hlslang.y"
                                                          { 
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addBinaryMath(EOpGreaterThan, (yyvsp[-2].interm.intermTypedNode), (yyvsp[0].interm.intermTypedNode), (yyvsp[-1].lex).line);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[-1].lex).line, ">", (yyvsp[-2].interm.intermTypedNode)->getCompleteString(), (yyvsp[0].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            TIntermConstant* constant = parseContext.intermediate.addConstant(TType(EbtBool, EbpUndefined, EvqConst), (yyvsp[-1].lex).line);
			constant->setValue(false);
			(yyval.interm.intermTypedNode) = constant;
        }
    }
#line 3073 "hlslang_tab.cpp"
    break;

  case 51: /* relational_expression: relational_expression LE_OP shift_expression  */
#line 955 "hlslang.y"
                                                    { 
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addBinaryMath(EOpLessThanEqual, (yyvsp[-2].interm.intermTypedNode), (yyvsp[0].interm.intermTypedNode), (yyvsp[-1].lex).line);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[-1].lex).line, "<=", (yyvsp[-2].interm.intermTypedNode)->getCompleteString(), (yyvsp[0].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            TIntermConstant* constant = parseContext.intermediate.addConstant(TType(EbtBool, EbpUndefined, EvqConst), (yyvsp[-1].lex).line);
			constant->setValue(false);
			(yyval.interm.intermTypedNode) = constant;
        }
    }
#line 3088 "hlslang_tab.cpp"
    break;

  case 52: /* relational_expression: relational_expression GE_OP shift_expression  */
#line 965 "hlslang.y"
                                                    { 
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addBinaryMath(EOpGreaterThanEqual, (yyvsp[-2].interm.intermTypedNode), (yyvsp[0].interm.intermTypedNode), (yyvsp[-1].lex).line);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[-1].lex).line, ">=", (yyvsp[-2].interm.intermTypedNode)->getCompleteString(), (yyvsp[0].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            TIntermConstant* constant = parseContext.intermediate.addConstant(TType(EbtBool, EbpUndefined, EvqConst), (yyvsp[-1].lex).line);
			constant->setValue(false);
			(yyval.interm.intermTypedNode) = constant;
        }
    }
#line 3103 "hlslang_tab.cpp"
    break;

  case 53: /* equality_expression: relational_expression  */
#line 978 "hlslang.y"
                            { (yyval.interm.intermTypedNode) = (yyvsp[0].interm.intermTypedNode); }
#line 3109 "hlslang_tab.cpp"
    break;

  case 54: /* equality_expression: equality_expression EQ_OP relational_expression  */
#line 979 "hlslang.y"
                                                       {
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addBinaryMath(EOpEqual, (yyvsp[-2].interm.intermTypedNode), (yyvsp[0].interm.intermTypedNode), (yyvsp[-1].lex).line);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[-1].lex).line, "==", (yyvsp[-2].interm.intermTypedNode)->getCompleteString(), (yyvsp[0].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            TIntermConstant* constant = parseContext.intermediate.addConstant(TType(EbtBool, EbpUndefined, EvqConst), (yyvsp[-1].lex).line);
			constant->setValue(false);
			(yyval.interm.intermTypedNode) = constant;
        } else if (((yyvsp[-2].interm.intermTypedNode)->isArray() || (yyvsp[0].interm.intermTypedNode)->isArray()))
            parseContext.recover();
    }
#line 3125 "hlslang_tab.cpp"
    break;

  case 55: /* equality_expression: equality_expression NE_OP relational_expression  */
#line 990 "hlslang.y"
                                                      { 
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addBinaryMath(EOpNotEqual, (yyvsp[-2].interm.intermTypedNode), (yyvsp[0].interm.intermTypedNode), (yyvsp[-1].lex).line);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[-1].lex).line, "!=", (yyvsp[-2].interm.intermTypedNode)->getCompleteString(), (yyvsp[0].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            TIntermConstant* constant = parseContext.intermediate.addConstant(TType(EbtBool, EbpUndefined, EvqConst), (yyvsp[-1].lex).line);
			constant->setValue(false);
			(yyval.interm.intermTypedNode) = constant;
        } else if (((yyvsp[-2].interm.intermTypedNode)->isArray() || (yyvsp[0].interm.intermTypedNode)->isArray()))
            parseContext.recover();
    }
#line 3141 "hlslang_tab.cpp"
    break;

  case 56: /* and_expression: equality_expression  */
#line 1004 "hlslang.y"
                          { (yyval.interm.intermTypedNode) = (yyvsp[0].interm.intermTypedNode); }
#line 3147 "hlslang_tab.cpp"
    break;

  case 57: /* and_expression: and_expression AMPERSAND equality_expression  */
#line 1005 "hlslang.y"
                                                   {
        UNSUPPORTED_FEATURE("&", (yyvsp[-1].lex).line);
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addBinaryMath(EOpAnd, (yyvsp[-2].interm.intermTypedNode), (yyvsp[0].interm.intermTypedNode), (yyvsp[-1].lex).line);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[-1].lex).line, "&", (yyvsp[-2].interm.intermTypedNode)->getCompleteString(), (yyvsp[0].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            (yyval.interm.intermTypedNode) = (yyvsp[-2].interm.intermTypedNode);
        }
    }
#line 3161 "hlslang_tab.cpp"
    break;

  case 58: /* exclusive_or_expression: and_expression  */
#line 1017 "hlslang.y"
                     { (yyval.interm.intermTypedNode) = (yyvsp[0].interm.intermTypedNode); }
#line 3167 "hlslang_tab.cpp"
    break;

  case 59: /* exclusive_or_expression: exclusive_or_expression CARET and_expression  */
#line 1018 "hlslang.y"
                                                   {
        UNSUPPORTED_FEATURE("^", (yyvsp[-1].lex).line);
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addBinaryMath(EOpExclusiveOr, (yyvsp[-2].interm.intermTypedNode), (yyvsp[0].interm.intermTypedNode), (yyvsp[-1].lex).line);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[-1].lex).line, "^", (yyvsp[-2].interm.intermTypedNode)->getCompleteString(), (yyvsp[0].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            (yyval.interm.intermTypedNode) = (yyvsp[-2].interm.intermTypedNode);
        }
    }
#line 3181 "hlslang_tab.cpp"
    break;

  case 60: /* inclusive_or_expression: exclusive_or_expression  */
#line 1030 "hlslang.y"
                              { (yyval.interm.intermTypedNode) = (yyvsp[0].interm.intermTypedNode); }
#line 3187 "hlslang_tab.cpp"
    break;

  case 61: /* inclusive_or_expression: inclusive_or_expression VERTICAL_BAR exclusive_or_expression  */
#line 1031 "hlslang.y"
                                                                   {
        UNSUPPORTED_FEATURE("|", (yyvsp[-1].lex).line);
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addBinaryMath(EOpInclusiveOr, (yyvsp[-2].interm.intermTypedNode), (yyvsp[0].interm.intermTypedNode), (yyvsp[-1].lex).line);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[-1].lex).line, "|", (yyvsp[-2].interm.intermTypedNode)->getCompleteString(), (yyvsp[0].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            (yyval.interm.intermTypedNode) = (yyvsp[-2].interm.intermTypedNode);
        }
    }
#line 3201 "hlslang_tab.cpp"
    break;

  case 62: /* logical_and_expression: inclusive_or_expression  */
#line 1043 "hlslang.y"
                              { (yyval.interm.intermTypedNode) = (yyvsp[0].interm.intermTypedNode); }
#line 3207 "hlslang_tab.cpp"
    break;

  case 63: /* logical_and_expression: logical_and_expression AND_OP inclusive_or_expression  */
#line 1044 "hlslang.y"
                                                            {
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addBinaryMath(EOpLogicalAnd, (yyvsp[-2].interm.intermTypedNode), (yyvsp[0].interm.intermTypedNode), (yyvsp[-1].lex).line);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[-1].lex).line, "&&", (yyvsp[-2].interm.intermTypedNode)->getCompleteString(), (yyvsp[0].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            TIntermConstant* constant = parseContext.intermediate.addConstant(TType(EbtBool, EbpUndefined, EvqConst), (yyvsp[-1].lex).line);
			constant->setValue(false);
			(yyval.interm.intermTypedNode) = constant;
        }
    }
#line 3222 "hlslang_tab.cpp"
    break;

  case 64: /* logical_xor_expression: logical_and_expression  */
#line 1057 "hlslang.y"
                             { (yyval.interm.intermTypedNode) = (yyvsp[0].interm.intermTypedNode); }
#line 3228 "hlslang_tab.cpp"
    break;

  case 65: /* logical_xor_expression: logical_xor_expression XOR_OP logical_and_expression  */
#line 1058 "hlslang.y"
                                                            { 
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addBinaryMath(EOpLogicalXor, (yyvsp[-2].interm.intermTypedNode), (yyvsp[0].interm.intermTypedNode), (yyvsp[-1].lex).line);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[-1].lex).line, "^^", (yyvsp[-2].interm.intermTypedNode)->getCompleteString(), (yyvsp[0].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            TIntermConstant* constant = parseContext.intermediate.addConstant(TType(EbtBool, EbpUndefined, EvqConst), (yyvsp[-1].lex).line);
			constant->setValue(false);
			(yyval.interm.intermTypedNode) = constant;
        }
    }
#line 3243 "hlslang_tab.cpp"
    break;

  case 66: /* logical_or_expression: logical_xor_expression  */
#line 1071 "hlslang.y"
                             { (yyval.interm.intermTypedNode) = (yyvsp[0].interm.intermTypedNode); }
#line 3249 "hlslang_tab.cpp"
    break;

  case 67: /* logical_or_expression: logical_or_expression OR_OP logical_xor_expression  */
#line 1072 "hlslang.y"
                                                          { 
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addBinaryMath(EOpLogicalOr, (yyvsp[-2].interm.intermTypedNode), (yyvsp[0].interm.intermTypedNode), (yyvsp[-1].lex).line);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[-1].lex).line, "||", (yyvsp[-2].interm.intermTypedNode)->getCompleteString(), (yyvsp[0].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            TIntermConstant* constant = parseContext.intermediate.addConstant(TType(EbtBool, EbpUndefined, EvqConst), (yyvsp[-1].lex).line);
			constant->setValue(false);
			(yyval.interm.intermTypedNode) = constant;
        }
    }
#line 3264 "hlslang_tab.cpp"
    break;

  case 68: /* conditional_expression: logical_or_expression  */
#line 1085 "hlslang.y"
                            { (yyval.interm.intermTypedNode) = (yyvsp[0].interm.intermTypedNode); }
#line 3270 "hlslang_tab.cpp"
    break;

  case 69: /* conditional_expression: logical_or_expression QUESTION expression COLON assignment_expression  */
#line 1086 "hlslang.y"
                                                                            {
       if (parseContext.boolOrVectorErrorCheck((yyvsp[-3].lex).line, (yyvsp[-4].interm.intermTypedNode)))
            parseContext.recover();
       
		(yyval.interm.intermTypedNode) = parseContext.intermediate.addSelection((yyvsp[-4].interm.intermTypedNode), (yyvsp[-2].interm.intermTypedNode), (yyvsp[0].interm.intermTypedNode), (yyvsp[-3].lex).line);
           
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[-3].lex).line, ":", (yyvsp[-2].interm.intermTypedNode)->getCompleteString(), (yyvsp[0].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            (yyval.interm.intermTypedNode) = (yyvsp[0].interm.intermTypedNode);
        }
    }
#line 3287 "hlslang_tab.cpp"
    break;

  case 70: /* assignment_expression: conditional_expression  */
#line 1101 "hlslang.y"
                             { (yyval.interm.intermTypedNode) = (yyvsp[0].interm.intermTypedNode); }
#line 3293 "hlslang_tab.cpp"
    break;

  case 71: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 1102 "hlslang.y"
                                                                 {        
        if (parseContext.lValueErrorCheck((yyvsp[-1].interm).line, "assign", (yyvsp[-2].interm.intermTypedNode)))
            parseContext.recover();
        (yyval.interm.intermTypedNode) = parseContext.addAssign((yyvsp[-1].interm).op, (yyvsp[-2].interm.intermTypedNode), (yyvsp[0].interm.intermTypedNode), (yyvsp[-1].interm).line);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.assignError((yyvsp[-1].interm).line, "assign", (yyvsp[-2].interm.intermTypedNode)->getCompleteString(), (yyvsp[0].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            (yyval.interm.intermTypedNode) = (yyvsp[-2].interm.intermTypedNode);
        } else if (((yyvsp[-2].interm.intermTypedNode)->isArray() || (yyvsp[0].interm.intermTypedNode)->isArray()))
            parseContext.recover();
    }
#line 3309 "hlslang_tab.cpp"
    break;

  case 72: /* assignment_operator: EQUAL  */
#line 1116 "hlslang.y"
                   {                                    (yyval.interm).line = (yyvsp[0].lex).line; (yyval.interm).op = EOpAssign; }
#line 3315 "hlslang_tab.cpp"
    break;

  case 73: /* assignment_operator: MUL_ASSIGN  */
#line 1117 "hlslang.y"
                   { FRAG_VERT_ONLY("*=", (yyvsp[0].lex).line);     (yyval.interm).line = (yyvsp[0].lex).line; (yyval.interm).op = EOpMulAssign; }
#line 3321 "hlslang_tab.cpp"
    break;

  case 74: /* assignment_operator: DIV_ASSIGN  */
#line 1118 "hlslang.y"
                   { FRAG_VERT_ONLY("/=", (yyvsp[0].lex).line);     (yyval.interm).line = (yyvsp[0].lex).line; (yyval.interm).op = EOpDivAssign; }
#line 3327 "hlslang_tab.cpp"
    break;

  case 75: /* assignment_operator: MOD_ASSIGN  */
#line 1119 "hlslang.y"
                   { UNSUPPORTED_FEATURE("%=", (yyvsp[0].lex).line);   (yyval.interm).line = (yyvsp[0].lex).line; (yyval.interm).op = EOpModAssign; }
#line 3333 "hlslang_tab.cpp"
    break;

  case 76: /* assignment_operator: ADD_ASSIGN  */
#line 1120 "hlslang.y"
                   {                                    (yyval.interm).line = (yyvsp[0].lex).line; (yyval.interm).op = EOpAddAssign; }
#line 3339 "hlslang_tab.cpp"
    break;

  case 77: /* assignment_operator: SUB_ASSIGN  */
#line 1121 "hlslang.y"
                   {                                    (yyval.interm).line = (yyvsp[0].lex).line; (yyval.interm).op = EOpSubAssign; }
#line 3345 "hlslang_tab.cpp"
    break;

  case 78: /* assignment_operator: LEFT_ASSIGN  */
#line 1122 "hlslang.y"
                   { UNSUPPORTED_FEATURE("<<=", (yyvsp[0].lex).line);  (yyval.interm).line = (yyvsp[0].lex).line; (yyval.interm).op = EOpLeftShiftAssign; }
#line 3351 "hlslang_tab.cpp"
    break;

  case 79: /* assignment_operator: RIGHT_ASSIGN  */
#line 1123 "hlslang.y"
                   { UNSUPPORTED_FEATURE("<<=", (yyvsp[0].lex).line);  (yyval.interm).line = (yyvsp[0].lex).line; (yyval.interm).op = EOpRightShiftAssign; }
#line 3357 "hlslang_tab.cpp"
    break;

  case 80: /* assignment_operator: AND_ASSIGN  */
#line 1124 "hlslang.y"
                   { UNSUPPORTED_FEATURE("&=",  (yyvsp[0].lex).line);  (yyval.interm).line = (yyvsp[0].lex).line; (yyval.interm).op = EOpAndAssign; }
#line 3363 "hlslang_tab.cpp"
    break;

  case 81: /* assignment_operator: XOR_ASSIGN  */
#line 1125 "hlslang.y"
                   { UNSUPPORTED_FEATURE("^=",  (yyvsp[0].lex).line);  (yyval.interm).line = (yyvsp[0].lex).line; (yyval.interm).op = EOpExclusiveOrAssign; }
#line 3369 "hlslang_tab.cpp"
    break;

  case 82: /* assignment_operator: OR_ASSIGN  */
#line 1126 "hlslang.y"
                   { UNSUPPORTED_FEATURE("|=",  (yyvsp[0].lex).line);  (yyval.interm).line = (yyvsp[0].lex).line; (yyval.interm).op = EOpInclusiveOrAssign; }
#line 3375 "hlslang_tab.cpp"
    break;

  case 83: /* expression: assignment_expression  */
#line 1130 "hlslang.y"
                            {
        (yyval.interm.intermTypedNode) = (yyvsp[0].interm.intermTypedNode);
    }
#line 3383 "hlslang_tab.cpp"
    break;

  case 84: /* expression: expression COMMA assignment_expression  */
#line 1133 "hlslang.y"
                                             {
        (yyval.interm.intermTypedNode) = parseContext.intermediate.addComma((yyvsp[-2].interm.intermTypedNode), (yyvsp[0].interm.intermTypedNode), (yyvsp[-1].lex).line);
        if ((yyval.interm.intermTypedNode) == 0) {
            parseContext.binaryOpError((yyvsp[-1].lex).line, ",", (yyvsp[-2].interm.intermTypedNode)->getCompleteString(), (yyvsp[0].interm.intermTypedNode)->getCompleteString());
            parseContext.recover();
            (yyval.interm.intermTypedNode) = (yyvsp[0].interm.intermTypedNode);
        }
    }
#line 3396 "hlslang_tab.cpp"
    break;

  case 85: /* constant_expression: conditional_expression  */
#line 1144 "hlslang.y"
                             {
        if (parseContext.constErrorCheck((yyvsp[0].interm.intermTypedNode)))
            parseContext.recover();
        (yyval.interm.intermTypedNode) = (yyvsp[0].interm.intermTypedNode);
    }
#line 3406 "hlslang_tab.cpp"
    break;

  case 86: /* declaration: function_prototype SEMICOLON  */
#line 1152 "hlslang.y"
                                     { (yyval.interm.intermDeclaration) = 0; }
#line 3412 "hlslang_tab.cpp"
    break;

  case 87: /* declaration: init_declarator_list SEMICOLON  */
#line 1153 "hlslang.y"
                                     { (yyval.interm.intermDeclaration) = (yyvsp[-1].interm.intermDeclaration); }
#line 3418 "hlslang_tab.cpp"
    break;

  case 88: /* function_prototype: function_declarator RIGHT_PAREN  */
#line 1157 "hlslang.y"
                                       {
        //
        // Multiple declarations of the same function are allowed.
        //
        // If this is a definition, the definition production code will check for redefinitions 
        // (we don't know at this point if it's a definition or not).
        //
        // Redeclarations are allowed.  But, return types and parameter qualifiers must match.
        //        
        TFunction* prevDec = static_cast<TFunction*>(parseContext.symbolTable.find((yyvsp[-1].interm.function)->getMangledName()));
        if (prevDec) {
            if (prevDec->getReturnType() != (yyvsp[-1].interm.function)->getReturnType()) {
                parseContext.error((yyvsp[0].lex).line, "overloaded functions must have the same return type", (yyvsp[-1].interm.function)->getReturnType().getBasicString(), "");
                parseContext.recover();
            }
            for (int i = 0; i < prevDec->getParamCount(); ++i) {
                if ((*prevDec)[i].type->getQualifier() != (*(yyvsp[-1].interm.function))[i].type->getQualifier()) {
                    parseContext.error((yyvsp[0].lex).line, "overloaded functions must have the same parameter qualifiers", (*(yyvsp[-1].interm.function))[i].type->getQualifierString(), "");
                    parseContext.recover();
                }
            }
        }
        
        //
        // If this is a redeclaration, it could also be a definition,
        // in which case, we want to use the variable names from this one, and not the one that's
        // being redeclared.  So, pass back up this declaration, not the one in the symbol table.
        //
        (yyval.interm).function = (yyvsp[-1].interm.function);
        (yyval.interm).line = (yyvsp[0].lex).line;

        parseContext.symbolTable.insert(*(yyval.interm).function);
    }
#line 3456 "hlslang_tab.cpp"
    break;

  case 89: /* function_prototype: function_declarator RIGHT_PAREN COLON IDENTIFIER  */
#line 1190 "hlslang.y"
                                                       {
        //
        // Multiple declarations of the same function are allowed.
        //
        // If this is a definition, the definition production code will check for redefinitions 
        // (we don't know at this point if it's a definition or not).
        //
        // Redeclarations are allowed.  But, return types and parameter qualifiers must match.
        //        
        TFunction* prevDec = static_cast<TFunction*>(parseContext.symbolTable.find((yyvsp[-3].interm.function)->getMangledName()));
        if (prevDec) {
            if (prevDec->getReturnType() != (yyvsp[-3].interm.function)->getReturnType()) {
                parseContext.error((yyvsp[-2].lex).line, "overloaded functions must have the same return type", (yyvsp[-3].interm.function)->getReturnType().getBasicString(), "");
                parseContext.recover();
            }
            for (int i = 0; i < prevDec->getParamCount(); ++i) {
                if ((*prevDec)[i].type->getQualifier() != (*(yyvsp[-3].interm.function))[i].type->getQualifier()) {
                    parseContext.error((yyvsp[-2].lex).line, "overloaded functions must have the same parameter qualifiers", (*(yyvsp[-3].interm.function))[i].type->getQualifierString(), "");
                    parseContext.recover();
                }
            }
        }
        
        //
        // If this is a redeclaration, it could also be a definition,
        // in which case, we want to use the variable names from this one, and not the one that's
        // being redeclared.  So, pass back up this declaration, not the one in the symbol table.
        //
        (yyval.interm).function = (yyvsp[-3].interm.function);
        (yyval.interm).line = (yyvsp[-2].lex).line;
        (yyval.interm).function->setInfo(new TTypeInfo(*(yyvsp[0].lex).string, 0));

        parseContext.symbolTable.insert(*(yyval.interm).function);
    }
#line 3495 "hlslang_tab.cpp"
    break;

  case 90: /* function_declarator: function_header  */
#line 1227 "hlslang.y"
                      {
        (yyval.interm.function) = (yyvsp[0].interm.function);
    }
#line 3503 "hlslang_tab.cpp"
    break;

  case 91: /* function_declarator: function_header_with_parameters  */
#line 1230 "hlslang.y"
                                      { 
        (yyval.interm.function) = (yyvsp[0].interm.function);  
    }
#line 3511 "hlslang_tab.cpp"
    break;

  case 92: /* function_header_with_parameters: function_header parameter_declaration  */
#line 1237 "hlslang.y"
                                            {
        // Add the parameter 
        (yyval.interm.function) = (yyvsp[-1].interm.function);
        if ((yyvsp[0].interm).param.type->getBasicType() != EbtVoid)
            (yyvsp[-1].interm.function)->addParameter((yyvsp[0].interm).param);
        else
            delete (yyvsp[0].interm).param.type;
    }
#line 3524 "hlslang_tab.cpp"
    break;

  case 93: /* function_header_with_parameters: function_header_with_parameters COMMA parameter_declaration  */
#line 1245 "hlslang.y"
                                                                  {   
        //
        // Only first parameter of one-parameter functions can be void
        // The check for named parameters not being void is done in parameter_declarator 
        //
        if ((yyvsp[0].interm).param.type->getBasicType() == EbtVoid) {
            //
            // This parameter > first is void
            //
            parseContext.error((yyvsp[-1].lex).line, "cannot be an argument type except for '(void)'", "void", "");
            parseContext.recover();
            delete (yyvsp[0].interm).param.type;
        } else {
            // Add the parameter 
            (yyval.interm.function) = (yyvsp[-2].interm.function); 
            (yyvsp[-2].interm.function)->addParameter((yyvsp[0].interm).param);
        }
    }
#line 3547 "hlslang_tab.cpp"
    break;

  case 94: /* function_header: fully_specified_type IDENTIFIER LEFT_PAREN  */
#line 1266 "hlslang.y"
                                                 {
        if ((yyvsp[-2].interm.type).qualifier != EvqGlobal && (yyvsp[-2].interm.type).qualifier != EvqTemporary) {
            parseContext.error((yyvsp[-1].lex).line, "no qualifiers allowed for function return", getQualifierString((yyvsp[-2].interm.type).qualifier), "");
            parseContext.recover();
        }
        // make sure a sampler is not involved as well...
        if (parseContext.structQualifierErrorCheck((yyvsp[-1].lex).line, (yyvsp[-2].interm.type)))
            parseContext.recover();
        
        // Add the function as a prototype after parsing it (we do not support recursion) 
        TFunction *function;
        TType type((yyvsp[-2].interm.type));
	const TString* mangled = 0;
	if ( *(yyvsp[-1].lex).string == "main")
	    mangled = NewPoolTString( "xlat_main");
	else
	    mangled = (yyvsp[-1].lex).string;

        function = new TFunction(mangled, type);
        (yyval.interm.function) = function;
    }
#line 3573 "hlslang_tab.cpp"
    break;

  case 95: /* function_header: profile_list fully_specified_type IDENTIFIER LEFT_PAREN  */
#line 1287 "hlslang.y"
                                                              {
        if ((yyvsp[-2].interm.type).qualifier != EvqGlobal && (yyvsp[-2].interm.type).qualifier != EvqTemporary) {
            parseContext.error((yyvsp[-1].lex).line, "no qualifiers allowed for function return", getQualifierString((yyvsp[-2].interm.type).qualifier), "");
            parseContext.recover();
        }
        // make sure a sampler is not involved as well...
        if (parseContext.structQualifierErrorCheck((yyvsp[-1].lex).line, (yyvsp[-2].interm.type)))
            parseContext.recover();
        
        // Add the function as a prototype after parsing it (we do not support recursion) 
        TFunction *function;
        TType type((yyvsp[-2].interm.type));
	const TString* mangled = 0;
	TString prefix = "xl";
	prefix += *(yyvsp[-3].lex).string;
	if ( *(yyvsp[-1].lex).string == "main")
	    mangled = NewPoolTString( (prefix + "@xlat_main").c_str() ) ;
	else
	    mangled = NewPoolTString( (prefix + "@" + *(yyvsp[-1].lex).string).c_str());

        function = new TFunction(mangled, type);
        (yyval.interm.function) = function;
    }
#line 3601 "hlslang_tab.cpp"
    break;

  case 96: /* parameter_declarator: type_specifier IDENTIFIER  */
#line 1314 "hlslang.y"
                                {
        if ((yyvsp[-1].interm.type).type == EbtVoid) {
            parseContext.error((yyvsp[0].lex).line, "illegal use of type 'void'", (yyvsp[0].lex).string->c_str(), "");
            parseContext.recover();
        }
        if (parseContext.reservedErrorCheck((yyvsp[0].lex).line, *(yyvsp[0].lex).string))
            parseContext.recover();
        TParameter param = {(yyvsp[0].lex).string, 0, new TType((yyvsp[-1].interm.type))};
        (yyval.interm).line = (yyvsp[0].lex).line;
        (yyval.interm).param = param; 
    }
#line 3617 "hlslang_tab.cpp"
    break;

  case 97: /* parameter_declarator: type_specifier IDENTIFIER EQUAL initializer  */
#line 1325 "hlslang.y"
                                                  {
        if ((yyvsp[-3].interm.type).type == EbtVoid) {
            parseContext.error((yyvsp[-2].lex).line, "illegal use of type 'void'", (yyvsp[-2].lex).string->c_str(), "");
            parseContext.recover();
        }
        if (parseContext.reservedErrorCheck((yyvsp[-2].lex).line, *(yyvsp[-2].lex).string))
            parseContext.recover();
        TParameter param = {(yyvsp[-2].lex).string, 0, new TType((yyvsp[-3].interm.type))};
        (yyval.interm).line = (yyvsp[-2].lex).line;
        (yyval.interm).param = param; 
        
        //TODO: add initializer support
    }
#line 3635 "hlslang_tab.cpp"
    break;

  case 98: /* parameter_declarator: type_specifier IDENTIFIER register_specifier  */
#line 1338 "hlslang.y"
                                                   {
        // register is being ignored
        if ((yyvsp[-2].interm.type).type == EbtVoid) {
            parseContext.error((yyvsp[-1].lex).line, "illegal use of type 'void'", (yyvsp[-1].lex).string->c_str(), "");
            parseContext.recover();
        }
        if (parseContext.reservedErrorCheck((yyvsp[-1].lex).line, *(yyvsp[-1].lex).string))
            parseContext.recover();
        TParameter param = {(yyvsp[-1].lex).string, 0, new TType((yyvsp[-2].interm.type))};
        (yyval.interm).line = (yyvsp[-1].lex).line;
        (yyval.interm).param = param; 
    }
#line 3652 "hlslang_tab.cpp"
    break;

  case 99: /* parameter_declarator: type_specifier IDENTIFIER COLON IDENTIFIER  */
#line 1350 "hlslang.y"
                                                 {
        //Parameter with semantic
        if ((yyvsp[-3].interm.type).type == EbtVoid) {
            parseContext.error((yyvsp[-2].lex).line, "illegal use of type 'void'", (yyvsp[-2].lex).string->c_str(), "");
            parseContext.recover();
        }
        if (parseContext.reservedErrorCheck((yyvsp[-2].lex).line, *(yyvsp[-2].lex).string))
            parseContext.recover();
        TParameter param = {(yyvsp[-2].lex).string, new TTypeInfo(*(yyvsp[0].lex).string, 0), new TType((yyvsp[-3].interm.type))};
        (yyval.interm).line = (yyvsp[-2].lex).line;
        (yyval.interm).param = param; 
    }
#line 3669 "hlslang_tab.cpp"
    break;

  case 100: /* parameter_declarator: type_specifier IDENTIFIER LEFT_BRACKET constant_expression RIGHT_BRACKET  */
#line 1362 "hlslang.y"
                                                                               {
        // Check that we can make an array out of this type
        if (parseContext.arrayTypeErrorCheck((yyvsp[-2].lex).line, (yyvsp[-4].interm.type)))
            parseContext.recover();
            
        if (parseContext.reservedErrorCheck((yyvsp[-3].lex).line, *(yyvsp[-3].lex).string))
            parseContext.recover();
            
        int size;
        if (parseContext.arraySizeErrorCheck((yyvsp[-2].lex).line, (yyvsp[-1].interm.intermTypedNode), size))
            parseContext.recover();
        (yyvsp[-4].interm.type).setArray(true, size);
             
        TType* type = new TType((yyvsp[-4].interm.type));
        TParameter param = { (yyvsp[-3].lex).string, 0, type };
        (yyval.interm).line = (yyvsp[-3].lex).line;
        (yyval.interm).param = param;
    }
#line 3692 "hlslang_tab.cpp"
    break;

  case 101: /* parameter_declarator: type_specifier IDENTIFIER LEFT_BRACKET constant_expression RIGHT_BRACKET COLON IDENTIFIER  */
#line 1380 "hlslang.y"
                                                                                                {
        // Check that we can make an array out of this type
        if (parseContext.arrayTypeErrorCheck((yyvsp[-4].lex).line, (yyvsp[-6].interm.type)))
            parseContext.recover();
            
        if (parseContext.reservedErrorCheck((yyvsp[-5].lex).line, *(yyvsp[-5].lex).string))
            parseContext.recover();
            
        int size;
        if (parseContext.arraySizeErrorCheck((yyvsp[-4].lex).line, (yyvsp[-3].interm.intermTypedNode), size))
            parseContext.recover();
        (yyvsp[-6].interm.type).setArray(true, size);
             
        TType* type = new TType((yyvsp[-6].interm.type));
        TParameter param = { (yyvsp[-5].lex).string, new TTypeInfo(*(yyvsp[0].lex).string, 0), type };
        (yyval.interm).line = (yyvsp[-5].lex).line;
        (yyval.interm).param = param;
    }
#line 3715 "hlslang_tab.cpp"
    break;

  case 102: /* parameter_declaration: type_qualifier parameter_qualifier parameter_declarator  */
#line 1409 "hlslang.y"
                                                              {
        (yyval.interm) = (yyvsp[0].interm);
        if (parseContext.paramErrorCheck((yyvsp[0].interm).line, (yyvsp[-2].interm.type).qualifier, (yyvsp[-1].interm.qualifier), (yyval.interm).param.type))
            parseContext.recover();
    }
#line 3725 "hlslang_tab.cpp"
    break;

  case 103: /* parameter_declaration: parameter_qualifier parameter_declarator  */
#line 1414 "hlslang.y"
                                               {
        (yyval.interm) = (yyvsp[0].interm);
        if (parseContext.parameterSamplerErrorCheck((yyvsp[0].interm).line, (yyvsp[-1].interm.qualifier), *(yyvsp[0].interm).param.type))
            parseContext.recover();
        if (parseContext.paramErrorCheck((yyvsp[0].interm).line, EvqTemporary, (yyvsp[-1].interm.qualifier), (yyval.interm).param.type))
            parseContext.recover();
    }
#line 3737 "hlslang_tab.cpp"
    break;

  case 104: /* parameter_declaration: type_qualifier parameter_qualifier parameter_type_specifier  */
#line 1424 "hlslang.y"
                                                                  {
        (yyval.interm) = (yyvsp[0].interm);
        if (parseContext.paramErrorCheck((yyvsp[0].interm).line, (yyvsp[-2].interm.type).qualifier, (yyvsp[-1].interm.qualifier), (yyval.interm).param.type))
            parseContext.recover();
    }
#line 3747 "hlslang_tab.cpp"
    break;

  case 105: /* parameter_declaration: parameter_qualifier parameter_type_specifier  */
#line 1429 "hlslang.y"
                                                   {
        (yyval.interm) = (yyvsp[0].interm);
        if (parseContext.parameterSamplerErrorCheck((yyvsp[0].interm).line, (yyvsp[-1].interm.qualifier), *(yyvsp[0].interm).param.type))
            parseContext.recover();
        if (parseContext.paramErrorCheck((yyvsp[0].interm).line, EvqTemporary, (yyvsp[-1].interm.qualifier), (yyval.interm).param.type))
            parseContext.recover();
    }
#line 3759 "hlslang_tab.cpp"
    break;

  case 106: /* parameter_qualifier: %empty  */
#line 1439 "hlslang.y"
                  {
        (yyval.interm.qualifier) = EvqIn;
    }
#line 3767 "hlslang_tab.cpp"
    break;

  case 107: /* parameter_qualifier: IN_QUAL  */
#line 1442 "hlslang.y"
              {
        (yyval.interm.qualifier) = EvqIn;
    }
#line 3775 "hlslang_tab.cpp"
    break;

  case 108: /* parameter_qualifier: OUT_QUAL  */
#line 1445 "hlslang.y"
               {
        (yyval.interm.qualifier) = EvqOut;
    }
#line 3783 "hlslang_tab.cpp"
    break;

  case 109: /* parameter_qualifier: INOUT_QUAL  */
#line 1448 "hlslang.y"
                 {
        (yyval.interm.qualifier) = EvqInOut;
    }
#line 3791 "hlslang_tab.cpp"
    break;

  case 110: /* parameter_type_specifier: type_specifier  */
#line 1454 "hlslang.y"
                     {
        TParameter param = { 0, 0, new TType((yyvsp[0].interm.type)) };
        (yyval.interm).param = param;
    }
#line 3800 "hlslang_tab.cpp"
    break;

  case 111: /* init_declarator_list: single_declaration  */
#line 1461 "hlslang.y"
                         {
        (yyval.interm.intermDeclaration) = (yyvsp[0].interm.intermDeclaration);
    }
#line 3808 "hlslang_tab.cpp"
    break;

  case 112: /* init_declarator_list: init_declarator_list COMMA IDENTIFIER type_info  */
#line 1464 "hlslang.y"
                                                      {
		TPublicType type = (yyvsp[-3].interm.intermDeclaration)->getPublicType();
		
        if (parseContext.structQualifierErrorCheck((yyvsp[-1].lex).line, type))
            parseContext.recover();
        
        if (parseContext.nonInitConstErrorCheck((yyvsp[-1].lex).line, *(yyvsp[-1].lex).string, type))
            parseContext.recover();

        if (parseContext.nonInitErrorCheck((yyvsp[-1].lex).line, *(yyvsp[-1].lex).string, (yyvsp[0].interm.typeInfo), type))
            parseContext.recover();
		
		TSymbol* sym = parseContext.symbolTable.find(*(yyvsp[-1].lex).string);
		if (!sym)
			(yyval.interm.intermDeclaration) = (yyvsp[-3].interm.intermDeclaration);
		else
			(yyval.interm.intermDeclaration) = parseContext.intermediate.growDeclaration((yyvsp[-3].interm.intermDeclaration), sym, NULL);
    }
#line 3831 "hlslang_tab.cpp"
    break;

  case 113: /* init_declarator_list: init_declarator_list COMMA IDENTIFIER LEFT_BRACKET RIGHT_BRACKET type_info  */
#line 1482 "hlslang.y"
                                                                                 {
		TPublicType type = (yyvsp[-5].interm.intermDeclaration)->getPublicType();
		
        if (parseContext.structQualifierErrorCheck((yyvsp[-3].lex).line, type))
            parseContext.recover();
            
        if (parseContext.nonInitConstErrorCheck((yyvsp[-3].lex).line, *(yyvsp[-3].lex).string, type))
            parseContext.recover();
        
        if (parseContext.arrayTypeErrorCheck((yyvsp[-2].lex).line, type) || parseContext.arrayQualifierErrorCheck((yyvsp[-2].lex).line, type))
            parseContext.recover();
        else {
            TVariable* variable;
            if (parseContext.arrayErrorCheck((yyvsp[-2].lex).line, *(yyvsp[-3].lex).string, (yyvsp[0].interm.typeInfo), type, variable))
                parseContext.recover();
		
			if (!variable)
				(yyval.interm.intermDeclaration) = (yyvsp[-5].interm.intermDeclaration);
			else {
				variable->getType().setArray(true);
				(yyval.interm.intermDeclaration) = parseContext.intermediate.growDeclaration((yyvsp[-5].interm.intermDeclaration), variable, NULL);
			}
        }
    }
#line 3860 "hlslang_tab.cpp"
    break;

  case 114: /* init_declarator_list: init_declarator_list COMMA IDENTIFIER LEFT_BRACKET constant_expression RIGHT_BRACKET type_info  */
#line 1506 "hlslang.y"
                                                                                                     {
		TPublicType type = (yyvsp[-6].interm.intermDeclaration)->getPublicType();
		
        if (parseContext.structQualifierErrorCheck((yyvsp[-4].lex).line, type))
            parseContext.recover();
            
        if (parseContext.nonInitConstErrorCheck((yyvsp[-4].lex).line, *(yyvsp[-4].lex).string, type))
            parseContext.recover();

        if (parseContext.arrayTypeErrorCheck((yyvsp[-3].lex).line, type) || parseContext.arrayQualifierErrorCheck((yyvsp[-3].lex).line, type))
            parseContext.recover();
        else {
            int size;
            if (parseContext.arraySizeErrorCheck((yyvsp[-3].lex).line, (yyvsp[-2].interm.intermTypedNode), size))
                parseContext.recover();
			
            TVariable* variable;
            if (parseContext.arrayErrorCheck((yyvsp[-3].lex).line, *(yyvsp[-4].lex).string, (yyvsp[0].interm.typeInfo), type, variable))
                parseContext.recover();
			
			if (!variable)
				(yyval.interm.intermDeclaration) = (yyvsp[-6].interm.intermDeclaration);
			else {
				variable->getType().setArray(true);
				variable->getType().setArraySize(size);
				(yyval.interm.intermDeclaration) = parseContext.intermediate.growDeclaration((yyvsp[-6].interm.intermDeclaration), variable, NULL);
			}
        }
    }
#line 3894 "hlslang_tab.cpp"
    break;

  case 115: /* init_declarator_list: init_declarator_list COMMA IDENTIFIER LEFT_BRACKET RIGHT_BRACKET type_info EQUAL initializer  */
#line 1535 "hlslang.y"
                                                                                                   {
		TPublicType type = (yyvsp[-7].interm.intermDeclaration)->getPublicType();
		
        if (parseContext.structQualifierErrorCheck((yyvsp[-5].lex).line, type))
            parseContext.recover();
            
        TVariable* variable = 0;
        if (parseContext.arrayTypeErrorCheck((yyvsp[-4].lex).line, type) || parseContext.arrayQualifierErrorCheck((yyvsp[-4].lex).line, type))
            parseContext.recover();
        else if (parseContext.arrayErrorCheck((yyvsp[-4].lex).line, *(yyvsp[-5].lex).string, type, variable))
			parseContext.recover();
		
        {
            TIntermSymbol* symbol;
            if (!parseContext.executeInitializer((yyvsp[-5].lex).line, *(yyvsp[-5].lex).string, (yyvsp[-2].interm.typeInfo), type, (yyvsp[0].interm.intermTypedNode), symbol, variable)) {
                if (!variable)
					(yyval.interm.intermDeclaration) = (yyvsp[-7].interm.intermDeclaration);
				else {
					variable->getType().setArray(true);
					variable->getType().setArraySize((yyvsp[0].interm.intermTypedNode)->getType().getArraySize());
					(yyval.interm.intermDeclaration) = parseContext.intermediate.growDeclaration((yyvsp[-7].interm.intermDeclaration), variable, (yyvsp[0].interm.intermTypedNode));
				}
            } else {
                parseContext.recover();
                (yyval.interm.intermDeclaration) = 0;
            }
        }
    }
#line 3927 "hlslang_tab.cpp"
    break;

  case 116: /* init_declarator_list: init_declarator_list COMMA IDENTIFIER LEFT_BRACKET constant_expression RIGHT_BRACKET type_info EQUAL initializer  */
#line 1563 "hlslang.y"
                                                                                                                       {
		TPublicType type = (yyvsp[-8].interm.intermDeclaration)->getPublicType();
		int array_size;
		
        if (parseContext.structQualifierErrorCheck((yyvsp[-6].lex).line, type))
            parseContext.recover();
            
        TVariable* variable = 0;
        if (parseContext.arrayTypeErrorCheck((yyvsp[-5].lex).line, type) || parseContext.arrayQualifierErrorCheck((yyvsp[-5].lex).line, type))
            parseContext.recover();
        else {
            if (parseContext.arraySizeErrorCheck((yyvsp[-5].lex).line, (yyvsp[-4].interm.intermTypedNode), array_size))
                parseContext.recover();
			
            if (parseContext.arrayErrorCheck((yyvsp[-5].lex).line, *(yyvsp[-6].lex).string, (yyvsp[-2].interm.typeInfo), type, variable))
                parseContext.recover();
        }

        {
            TIntermSymbol* symbol;
            if (!parseContext.executeInitializer((yyvsp[-6].lex).line, *(yyvsp[-6].lex).string, (yyvsp[-2].interm.typeInfo), type, (yyvsp[0].interm.intermTypedNode), symbol, variable)) {
				if (!variable)
					(yyval.interm.intermDeclaration) = (yyvsp[-8].interm.intermDeclaration);
				else {
					variable->getType().setArray(true);
					variable->getType().setArraySize(array_size);
					
					(yyval.interm.intermDeclaration) = parseContext.intermediate.growDeclaration((yyvsp[-8].interm.intermDeclaration), variable, (yyvsp[0].interm.intermTypedNode));
				}
            } else {
                parseContext.recover();
                (yyval.interm.intermDeclaration) = 0;
            }
        }
    }
#line 3967 "hlslang_tab.cpp"
    break;

  case 117: /* init_declarator_list: init_declarator_list COMMA IDENTIFIER type_info EQUAL initializer  */
#line 1598 "hlslang.y"
                                                                        {
		TPublicType type = (yyvsp[-5].interm.intermDeclaration)->getPublicType();
		
        if (parseContext.structQualifierErrorCheck((yyvsp[-3].lex).line, type))
            parseContext.recover();
			
        TIntermSymbol* symbol;
		if ( !IsSampler(type.type)) {
			if (!parseContext.executeInitializer((yyvsp[-3].lex).line, *(yyvsp[-3].lex).string, (yyvsp[-2].interm.typeInfo), type, (yyvsp[0].interm.intermTypedNode), symbol)) {
				TSymbol* variable = parseContext.symbolTable.find(*(yyvsp[-3].lex).string);
				if (!variable)
					(yyval.interm.intermDeclaration) = (yyvsp[-5].interm.intermDeclaration);
				else 				
					(yyval.interm.intermDeclaration) = parseContext.intermediate.growDeclaration((yyvsp[-5].interm.intermDeclaration), variable, (yyvsp[0].interm.intermTypedNode));
			} else {
				parseContext.recover();
				(yyval.interm.intermDeclaration) = 0;
			}
		} else {
			//Special code to skip initializers for samplers
			(yyval.interm.intermDeclaration) = (yyvsp[-5].interm.intermDeclaration);
			if (parseContext.structQualifierErrorCheck((yyvsp[-3].lex).line, type))
				parseContext.recover();
			
			if (parseContext.nonInitConstErrorCheck((yyvsp[-3].lex).line, *(yyvsp[-3].lex).string, type))
				parseContext.recover();
			
			if (parseContext.nonInitErrorCheck((yyvsp[-3].lex).line, *(yyvsp[-3].lex).string, (yyvsp[-2].interm.typeInfo), type))
				parseContext.recover();
		}
	}
#line 4003 "hlslang_tab.cpp"
    break;

  case 118: /* single_declaration: fully_specified_type  */
#line 1632 "hlslang.y"
                           {
		(yyval.interm.intermDeclaration) = 0;
    }
#line 4011 "hlslang_tab.cpp"
    break;

  case 119: /* single_declaration: fully_specified_type IDENTIFIER type_info  */
#line 1635 "hlslang.y"
                                                {				
		bool error = false;
        if (error &= parseContext.structQualifierErrorCheck((yyvsp[-1].lex).line, (yyvsp[-2].interm.type)))
            parseContext.recover();
        
        if (error &= parseContext.nonInitConstErrorCheck((yyvsp[-1].lex).line, *(yyvsp[-1].lex).string, (yyvsp[-2].interm.type)))
            parseContext.recover();

        if (error &= parseContext.nonInitErrorCheck((yyvsp[-1].lex).line, *(yyvsp[-1].lex).string, (yyvsp[0].interm.typeInfo), (yyvsp[-2].interm.type)))
            parseContext.recover();
		
		TSymbol* symbol = parseContext.symbolTable.find(*(yyvsp[-1].lex).string);
		if (!error && symbol) {
			(yyval.interm.intermDeclaration) = parseContext.intermediate.addDeclaration(symbol, NULL, (yyvsp[-1].lex).line);
		} else {
			(yyval.interm.intermDeclaration) = 0;
		}
    }
#line 4034 "hlslang_tab.cpp"
    break;

  case 120: /* single_declaration: fully_specified_type IDENTIFIER LEFT_BRACKET RIGHT_BRACKET type_info  */
#line 1653 "hlslang.y"
                                                                           {
        if (parseContext.structQualifierErrorCheck((yyvsp[-3].lex).line, (yyvsp[-4].interm.type)))
            parseContext.recover();

        if (parseContext.nonInitConstErrorCheck((yyvsp[-3].lex).line, *(yyvsp[-3].lex).string, (yyvsp[-4].interm.type)))
            parseContext.recover();

        if (parseContext.arrayTypeErrorCheck((yyvsp[-2].lex).line, (yyvsp[-4].interm.type)) || parseContext.arrayQualifierErrorCheck((yyvsp[-2].lex).line, (yyvsp[-4].interm.type)))
            parseContext.recover();
        else {
            (yyvsp[-4].interm.type).setArray(true);        
            TVariable* variable;
            if (parseContext.arrayErrorCheck((yyvsp[-2].lex).line, *(yyvsp[-3].lex).string, (yyvsp[0].interm.typeInfo), (yyvsp[-4].interm.type), variable))
                parseContext.recover();
        }
		
		TSymbol* symbol = parseContext.symbolTable.find(*(yyvsp[-3].lex).string);
		if (symbol) {
			(yyval.interm.intermDeclaration) = parseContext.intermediate.addDeclaration(symbol, NULL, (yyvsp[-3].lex).line);
		} else {
			(yyval.interm.intermDeclaration) = 0;
		}
    }
#line 4062 "hlslang_tab.cpp"
    break;

  case 121: /* single_declaration: fully_specified_type IDENTIFIER LEFT_BRACKET constant_expression RIGHT_BRACKET type_info  */
#line 1676 "hlslang.y"
                                                                                               {
        if (parseContext.structQualifierErrorCheck((yyvsp[-4].lex).line, (yyvsp[-5].interm.type)))
            parseContext.recover();

        if (parseContext.nonInitConstErrorCheck((yyvsp[-4].lex).line, *(yyvsp[-4].lex).string, (yyvsp[-5].interm.type)))
			parseContext.recover();
		
		TVariable* variable;
        if (parseContext.arrayTypeErrorCheck((yyvsp[-3].lex).line, (yyvsp[-5].interm.type)) || parseContext.arrayQualifierErrorCheck((yyvsp[-3].lex).line, (yyvsp[-5].interm.type)))
            parseContext.recover();
        else {
            int size;
            if (parseContext.arraySizeErrorCheck((yyvsp[-3].lex).line, (yyvsp[-2].interm.intermTypedNode), size))
                parseContext.recover();
            
            (yyvsp[-5].interm.type).setArray(true, size);
            if (parseContext.arrayErrorCheck((yyvsp[-3].lex).line, *(yyvsp[-4].lex).string, (yyvsp[0].interm.typeInfo), (yyvsp[-5].interm.type), variable))
                parseContext.recover();
			
			if (variable) {
				(yyval.interm.intermDeclaration) = parseContext.intermediate.addDeclaration(variable, NULL, (yyvsp[-4].lex).line);
			} else {
				(yyval.interm.intermDeclaration) = 0;
			}
        }
	}
#line 4093 "hlslang_tab.cpp"
    break;

  case 122: /* single_declaration: fully_specified_type IDENTIFIER LEFT_BRACKET RIGHT_BRACKET type_info EQUAL initializer  */
#line 1702 "hlslang.y"
                                                                                             {
		if (parseContext.structQualifierErrorCheck((yyvsp[-5].lex).line, (yyvsp[-6].interm.type)))
			parseContext.recover();

		TVariable* variable = 0;
		if (parseContext.arrayTypeErrorCheck((yyvsp[-4].lex).line, (yyvsp[-6].interm.type)) || parseContext.arrayQualifierErrorCheck((yyvsp[-4].lex).line, (yyvsp[-6].interm.type)))
			parseContext.recover();
		else {
			(yyvsp[-6].interm.type).setArray(true, (yyvsp[0].interm.intermTypedNode)->getType().getArraySize());
			if (parseContext.arrayErrorCheck((yyvsp[-4].lex).line, *(yyvsp[-5].lex).string, (yyvsp[-2].interm.typeInfo), (yyvsp[-6].interm.type), variable))
				parseContext.recover();
		}

		{        
			TIntermSymbol* symbol;
			if (!parseContext.executeInitializer((yyvsp[-5].lex).line, *(yyvsp[-5].lex).string, (yyvsp[-2].interm.typeInfo), (yyvsp[-6].interm.type), (yyvsp[0].interm.intermTypedNode), symbol, variable)) {
				if (variable)
					(yyval.interm.intermDeclaration) = parseContext.intermediate.addDeclaration(symbol, (yyvsp[0].interm.intermTypedNode), (yyvsp[-1].lex).line);
				else
					(yyval.interm.intermDeclaration) = 0;
			} else {
				parseContext.recover();
				(yyval.interm.intermDeclaration) = 0;
			}
		}
    }
#line 4124 "hlslang_tab.cpp"
    break;

  case 123: /* single_declaration: fully_specified_type IDENTIFIER LEFT_BRACKET constant_expression RIGHT_BRACKET type_info EQUAL initializer  */
#line 1728 "hlslang.y"
                                                                                                                 {
        if (parseContext.structQualifierErrorCheck((yyvsp[-6].lex).line, (yyvsp[-7].interm.type)))
            parseContext.recover();

        TVariable* variable = 0;
        if (parseContext.arrayTypeErrorCheck((yyvsp[-5].lex).line, (yyvsp[-7].interm.type)) || parseContext.arrayQualifierErrorCheck((yyvsp[-5].lex).line, (yyvsp[-7].interm.type)))
            parseContext.recover();
        else {
            int size;
            if (parseContext.arraySizeErrorCheck((yyvsp[-5].lex).line, (yyvsp[-4].interm.intermTypedNode), size))
                parseContext.recover();
            
            (yyvsp[-7].interm.type).setArray(true, size);
            if (parseContext.arrayErrorCheck((yyvsp[-5].lex).line, *(yyvsp[-6].lex).string, (yyvsp[-2].interm.typeInfo), (yyvsp[-7].interm.type), variable))
                parseContext.recover();
        }
        
		{        
			TIntermSymbol* symbol;
			if (!parseContext.executeInitializer((yyvsp[-6].lex).line, *(yyvsp[-6].lex).string, (yyvsp[-2].interm.typeInfo), (yyvsp[-7].interm.type), (yyvsp[0].interm.intermTypedNode), symbol, variable)) {
				if (variable)
					(yyval.interm.intermDeclaration) = parseContext.intermediate.addDeclaration(symbol, (yyvsp[0].interm.intermTypedNode), (yyvsp[-1].lex).line);
				else
					(yyval.interm.intermDeclaration) = 0;
			} else {
				parseContext.recover();
				(yyval.interm.intermDeclaration) = 0;
			}
		}       
    }
#line 4159 "hlslang_tab.cpp"
    break;

  case 124: /* single_declaration: fully_specified_type IDENTIFIER type_info EQUAL initializer  */
#line 1758 "hlslang.y"
                                                                  {
		if (parseContext.structQualifierErrorCheck((yyvsp[-3].lex).line, (yyvsp[-4].interm.type)))
			parseContext.recover();
		
		if (!IsSampler((yyvsp[-4].interm.type).type)) {
			TIntermSymbol* symbol;
			if (!parseContext.executeInitializer((yyvsp[-3].lex).line, *(yyvsp[-3].lex).string, (yyvsp[-2].interm.typeInfo), (yyvsp[-4].interm.type), (yyvsp[0].interm.intermTypedNode), symbol)) {
				if (symbol)
				{
					(yyval.interm.intermDeclaration) = parseContext.intermediate.addDeclaration(symbol, (yyvsp[0].interm.intermTypedNode), (yyvsp[-1].lex).line);
					if ((yyval.interm.intermDeclaration) == 0)//for some reasons, cannot use initializer on declaration
						parseContext.recover();
				}	
				else
					(yyval.interm.intermDeclaration) = 0;
			} else {
				parseContext.recover();
				(yyval.interm.intermDeclaration) = 0;
			}
		} else {
			//Skip sampler initializers for now
			(yyval.interm.intermDeclaration) = 0;

			if (parseContext.structQualifierErrorCheck((yyvsp[-3].lex).line, (yyvsp[-4].interm.type)))
				parseContext.recover();

			if (parseContext.nonInitConstErrorCheck((yyvsp[-3].lex).line, *(yyvsp[-3].lex).string, (yyvsp[-4].interm.type)))
				parseContext.recover();

			if (parseContext.nonInitErrorCheck((yyvsp[-3].lex).line, *(yyvsp[-3].lex).string, (yyvsp[-2].interm.typeInfo), (yyvsp[-4].interm.type)))
				parseContext.recover();
		}
    }
#line 4197 "hlslang_tab.cpp"
    break;

  case 125: /* fully_specified_type: type_specifier  */
#line 1806 "hlslang.y"
                     {
        (yyval.interm.type) = (yyvsp[0].interm.type);                       
    }
#line 4205 "hlslang_tab.cpp"
    break;

  case 126: /* fully_specified_type: type_qualifier type_specifier  */
#line 1809 "hlslang.y"
                                     {                
        if ((yyvsp[0].interm.type).array && parseContext.arrayQualifierErrorCheck((yyvsp[0].interm.type).line, (yyvsp[-1].interm.type))) {
            parseContext.recover();
            (yyvsp[0].interm.type).setArray(false);
        }
        
        if ((yyvsp[-1].interm.type).qualifier == EvqAttribute &&
            ((yyvsp[0].interm.type).type == EbtBool || (yyvsp[0].interm.type).type == EbtInt)) {
            parseContext.error((yyvsp[0].interm.type).line, "cannot be bool or int", getQualifierString((yyvsp[-1].interm.type).qualifier), "");
            parseContext.recover();
        }
        if (((yyvsp[-1].interm.type).qualifier == EvqVaryingIn || (yyvsp[-1].interm.type).qualifier == EvqVaryingOut) &&
            ((yyvsp[0].interm.type).type == EbtBool || (yyvsp[0].interm.type).type == EbtInt)) {
            parseContext.error((yyvsp[0].interm.type).line, "cannot be bool or int", getQualifierString((yyvsp[-1].interm.type).qualifier), "");
            parseContext.recover();
        }
        (yyval.interm.type) = (yyvsp[0].interm.type); 
        (yyval.interm.type).qualifier = (yyvsp[-1].interm.type).qualifier;
    }
#line 4229 "hlslang_tab.cpp"
    break;

  case 127: /* type_qualifier: CONST_QUAL  */
#line 1831 "hlslang.y"
                 {
        (yyval.interm.type).setBasic(EbtVoid, EvqConst, (yyvsp[0].lex).line);
    }
#line 4237 "hlslang_tab.cpp"
    break;

  case 128: /* type_qualifier: STATIC_QUAL  */
#line 1834 "hlslang.y"
                  {
        (yyval.interm.type).setBasic(EbtVoid, EvqStatic, (yyvsp[0].lex).line);
    }
#line 4245 "hlslang_tab.cpp"
    break;

  case 129: /* type_qualifier: STATIC_QUAL CONST_QUAL  */
#line 1837 "hlslang.y"
                             {
        (yyval.interm.type).setBasic(EbtVoid, EvqStaticConst, (yyvsp[-1].lex).line);
    }
#line 4253 "hlslang_tab.cpp"
    break;

  case 130: /* type_qualifier: ATTRIBUTE  */
#line 1840 "hlslang.y"
                { 
        VERTEX_ONLY("attribute", (yyvsp[0].lex).line);
        if (parseContext.globalErrorCheck((yyvsp[0].lex).line, parseContext.symbolTable.atGlobalLevel(), "attribute"))
            parseContext.recover();
        (yyval.interm.type).setBasic(EbtVoid, EvqAttribute, (yyvsp[0].lex).line);
    }
#line 4264 "hlslang_tab.cpp"
    break;

  case 131: /* type_qualifier: VARYING  */
#line 1846 "hlslang.y"
              {
        if (parseContext.globalErrorCheck((yyvsp[0].lex).line, parseContext.symbolTable.atGlobalLevel(), "varying"))
            parseContext.recover();
        if (parseContext.language == EShLangVertex)
            (yyval.interm.type).setBasic(EbtVoid, EvqVaryingOut, (yyvsp[0].lex).line);
        else
            (yyval.interm.type).setBasic(EbtVoid, EvqVaryingIn, (yyvsp[0].lex).line);
    }
#line 4277 "hlslang_tab.cpp"
    break;

  case 132: /* type_qualifier: UNIFORM  */
#line 1854 "hlslang.y"
              {
        if (parseContext.globalErrorCheck((yyvsp[0].lex).line, parseContext.symbolTable.atGlobalLevel(), "uniform"))
            parseContext.recover();
        (yyval.interm.type).setBasic(EbtVoid, EvqUniform, (yyvsp[0].lex).line);
    }
#line 4287 "hlslang_tab.cpp"
    break;

  case 133: /* type_specifier: type_specifier_nonarray  */
#line 1862 "hlslang.y"
                              {
        (yyval.interm.type) = (yyvsp[0].interm.type);
    }
#line 4295 "hlslang_tab.cpp"
    break;

  case 134: /* type_specifier: type_specifier_nonarray LEFT_BRACKET constant_expression RIGHT_BRACKET  */
#line 1865 "hlslang.y"
                                                                             {
        (yyval.interm.type) = (yyvsp[-3].interm.type);
        
        if (parseContext.arrayTypeErrorCheck((yyvsp[-2].lex).line, (yyvsp[-3].interm.type)))
            parseContext.recover();
        else {
            int size;
            if (parseContext.arraySizeErrorCheck((yyvsp[-2].lex).line, (yyvsp[-1].interm.intermTypedNode), size))
                parseContext.recover();
            (yyval.interm.type).setArray(true, size);
        }
    }
#line 4312 "hlslang_tab.cpp"
    break;

  case 135: /* type_specifier_nonarray: VOID_TYPE  */
#line 1880 "hlslang.y"
                {
        SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtVoid,EbpUndefined);
    }
#line 4320 "hlslang_tab.cpp"
    break;

  case 136: /* type_specifier_nonarray: FLOAT_TYPE  */
#line 1883 "hlslang.y"
                 {
        SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtFloat,EbpHigh);
    }
#line 4328 "hlslang_tab.cpp"
    break;

  case 137: /* type_specifier_nonarray: HALF_TYPE  */
#line 1886 "hlslang.y"
                {
        SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtFloat,EbpMedium);
    }
#line 4336 "hlslang_tab.cpp"
    break;

  case 138: /* type_specifier_nonarray: FIXED_TYPE  */
#line 1889 "hlslang.y"
                 {
        SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtFloat,EbpLow);
    }
#line 4344 "hlslang_tab.cpp"
    break;

  case 139: /* type_specifier_nonarray: INT_TYPE  */
#line 1892 "hlslang.y"
               {
        SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtInt,EbpHigh);
    }
#line 4352 "hlslang_tab.cpp"
    break;

  case 140: /* type_specifier_nonarray: BOOL_TYPE  */
#line 1895 "hlslang.y"
                {
        SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtBool,EbpHigh);
    }
#line 4360 "hlslang_tab.cpp"
    break;

  case 141: /* type_specifier_nonarray: VECTOR LEFT_ANGLE FLOAT_TYPE COMMA INTCONSTANT RIGHT_ANGLE  */
#line 1898 "hlslang.y"
                                                                 {
        TQualifier qual = parseContext.getDefaultQualifier();
        if ( (yyvsp[-1].lex).i > 4 || (yyvsp[-1].lex).i < 1 ) {
            parseContext.error((yyvsp[-4].lex).line, "vector dimension out of range", "", "");
            parseContext.recover();
            (yyval.interm.type).setBasic(EbtFloat, qual, (yyvsp[-5].lex).line);
        } else {
            (yyval.interm.type).setBasic(EbtFloat, qual, (yyvsp[-5].lex).line);
            (yyval.interm.type).setAggregate((yyvsp[-1].lex).i);
        }
    }
#line 4376 "hlslang_tab.cpp"
    break;

  case 142: /* type_specifier_nonarray: VECTOR LEFT_ANGLE INT_TYPE COMMA INTCONSTANT RIGHT_ANGLE  */
#line 1909 "hlslang.y"
                                                               {
        TQualifier qual = parseContext.getDefaultQualifier();
        if ( (yyvsp[-1].lex).i > 4 || (yyvsp[-1].lex).i < 1 ) {
            parseContext.error((yyvsp[-4].lex).line, "vector dimension out of range", "", "");
            parseContext.recover();
            (yyval.interm.type).setBasic(EbtInt, qual, (yyvsp[-5].lex).line);
        } else {
            (yyval.interm.type).setBasic(EbtInt, qual, (yyvsp[-5].lex).line);
            (yyval.interm.type).setAggregate((yyvsp[-1].lex).i);
        }
    }
#line 4392 "hlslang_tab.cpp"
    break;

  case 143: /* type_specifier_nonarray: VECTOR LEFT_ANGLE BOOL_TYPE COMMA INTCONSTANT RIGHT_ANGLE  */
#line 1920 "hlslang.y"
                                                                {
        TQualifier qual = parseContext.getDefaultQualifier();
        if ( (yyvsp[-1].lex).i > 4 || (yyvsp[-1].lex).i < 1 ) {
            parseContext.error((yyvsp[-4].lex).line, "vector dimension out of range", "", "");
            parseContext.recover();
            (yyval.interm.type).setBasic(EbtBool, qual, (yyvsp[-5].lex).line);
        } else {
            (yyval.interm.type).setBasic(EbtBool, qual, (yyvsp[-5].lex).line);
            (yyval.interm.type).setAggregate((yyvsp[-1].lex).i);
        }
    }
#line 4408 "hlslang_tab.cpp"
    break;

  case 144: /* type_specifier_nonarray: VEC2  */
#line 1931 "hlslang.y"
           {
        SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtFloat,EbpHigh);
        (yyval.interm.type).setAggregate(2);
    }
#line 4417 "hlslang_tab.cpp"
    break;

  case 145: /* type_specifier_nonarray: VEC3  */
#line 1935 "hlslang.y"
           {
        SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtFloat,EbpHigh);
        (yyval.interm.type).setAggregate(3);
    }
#line 4426 "hlslang_tab.cpp"
    break;

  case 146: /* type_specifier_nonarray: VEC4  */
#line 1939 "hlslang.y"
           {
        SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtFloat,EbpHigh);
        (yyval.interm.type).setAggregate(4);
    }
#line 4435 "hlslang_tab.cpp"
    break;

  case 147: /* type_specifier_nonarray: HVEC2  */
#line 1943 "hlslang.y"
            {
        SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtFloat,EbpMedium);
        (yyval.interm.type).setAggregate(2);
    }
#line 4444 "hlslang_tab.cpp"
    break;

  case 148: /* type_specifier_nonarray: HVEC3  */
#line 1947 "hlslang.y"
            {
        SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtFloat,EbpMedium);
        (yyval.interm.type).setAggregate(3);
    }
#line 4453 "hlslang_tab.cpp"
    break;

  case 149: /* type_specifier_nonarray: HVEC4  */
#line 1951 "hlslang.y"
            {
        SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtFloat,EbpMedium);
        (yyval.interm.type).setAggregate(4);
    }
#line 4462 "hlslang_tab.cpp"
    break;

  case 150: /* type_specifier_nonarray: FVEC2  */
#line 1955 "hlslang.y"
            {
        SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtFloat,EbpLow);
        (yyval.interm.type).setAggregate(2);
    }
#line 4471 "hlslang_tab.cpp"
    break;

  case 151: /* type_specifier_nonarray: FVEC3  */
#line 1959 "hlslang.y"
            {
        SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtFloat,EbpLow);
        (yyval.interm.type).setAggregate(3);
    }
#line 4480 "hlslang_tab.cpp"
    break;

  case 152: /* type_specifier_nonarray: FVEC4  */
#line 1963 "hlslang.y"
            {
        SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtFloat,EbpLow);
        (yyval.interm.type).setAggregate(4);
    }
#line 4489 "hlslang_tab.cpp"
    break;

  case 153: /* type_specifier_nonarray: BVEC2  */
#line 1967 "hlslang.y"
            {
        SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtBool,EbpHigh);
        (yyval.interm.type).setAggregate(2);
    }
#line 4498 "hlslang_tab.cpp"
    break;

  case 154: /* type_specifier_nonarray: BVEC3  */
#line 1971 "hlslang.y"
            {
        SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtBool,EbpHigh);
        (yyval.interm.type).setAggregate(3);
    }
#line 4507 "hlslang_tab.cpp"
    break;

  case 155: /* type_specifier_nonarray: BVEC4  */
#line 1975 "hlslang.y"
            {
        SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtBool,EbpHigh);
        (yyval.interm.type).setAggregate(4);
    }
#line 4516 "hlslang_tab.cpp"
    break;

  case 156: /* type_specifier_nonarray: IVEC2  */
#line 1979 "hlslang.y"
            {
        SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtInt,EbpHigh);
        (yyval.interm.type).setAggregate(2);
    }
#line 4525 "hlslang_tab.cpp"
    break;

  case 157: /* type_specifier_nonarray: IVEC3  */
#line 1983 "hlslang.y"
            {
        SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtInt,EbpHigh);
        (yyval.interm.type).setAggregate(3);
    }
#line 4534 "hlslang_tab.cpp"
    break;

  case 158: /* type_specifier_nonarray: IVEC4  */
#line 1987 "hlslang.y"
            {
        SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtInt,EbpHigh);
        (yyval.interm.type).setAggregate(4);
    }
#line 4543 "hlslang_tab.cpp"
    break;

  case 159: /* type_specifier_nonarray: MATRIX2  */
#line 1991 "hlslang.y"
              {
        FRAG_VERT_ONLY("mat2", (yyvsp[0].lex).line); 
        SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtFloat,EbpHigh);
        (yyval.interm.type).setAggregate(2, true);
    }
#line 4553 "hlslang_tab.cpp"
    break;

  case 160: /* type_specifier_nonarray: MATRIX3  */
#line 1996 "hlslang.y"
              { 
        FRAG_VERT_ONLY("mat3", (yyvsp[0].lex).line); 
        SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtFloat,EbpHigh);
        (yyval.interm.type).setAggregate(3, true);
    }
#line 4563 "hlslang_tab.cpp"
    break;

  case 161: /* type_specifier_nonarray: MATRIX4  */
#line 2001 "hlslang.y"
              { 
        FRAG_VERT_ONLY("mat4", (yyvsp[0].lex).line);
        SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtFloat,EbpHigh);
        (yyval.interm.type).setAggregate(4, true);
    }
#line 4573 "hlslang_tab.cpp"
    break;

  case 162: /* type_specifier_nonarray: HMATRIX2  */
#line 2006 "hlslang.y"
                   {
		FRAG_VERT_ONLY("mat2", (yyvsp[0].lex).line);
		SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtFloat,EbpMedium);
		(yyval.interm.type).setAggregate(2, true);
	}
#line 4583 "hlslang_tab.cpp"
    break;

  case 163: /* type_specifier_nonarray: HMATRIX3  */
#line 2011 "hlslang.y"
                   { 
		FRAG_VERT_ONLY("mat3", (yyvsp[0].lex).line);
		SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtFloat,EbpMedium);
		(yyval.interm.type).setAggregate(3, true);
	}
#line 4593 "hlslang_tab.cpp"
    break;

  case 164: /* type_specifier_nonarray: HMATRIX4  */
#line 2016 "hlslang.y"
                   { 
		FRAG_VERT_ONLY("mat4", (yyvsp[0].lex).line);
		SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtFloat,EbpMedium);
		(yyval.interm.type).setAggregate(4, true);
	}
#line 4603 "hlslang_tab.cpp"
    break;

  case 165: /* type_specifier_nonarray: FMATRIX2  */
#line 2021 "hlslang.y"
                   {
		FRAG_VERT_ONLY("mat2", (yyvsp[0].lex).line);
		SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtFloat,EbpLow);
		(yyval.interm.type).setAggregate(2, true);
	}
#line 4613 "hlslang_tab.cpp"
    break;

  case 166: /* type_specifier_nonarray: FMATRIX3  */
#line 2026 "hlslang.y"
                   { 
		FRAG_VERT_ONLY("mat3", (yyvsp[0].lex).line);
		SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtFloat,EbpLow);
		(yyval.interm.type).setAggregate(3, true);
	}
#line 4623 "hlslang_tab.cpp"
    break;

  case 167: /* type_specifier_nonarray: FMATRIX4  */
#line 2031 "hlslang.y"
                   { 
		FRAG_VERT_ONLY("mat4", (yyvsp[0].lex).line);
		SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtFloat,EbpLow);
		(yyval.interm.type).setAggregate(4, true);
	}
#line 4633 "hlslang_tab.cpp"
    break;

  case 168: /* type_specifier_nonarray: TEXTURE  */
#line 2036 "hlslang.y"
                  {
        FRAG_VERT_ONLY("texture", (yyvsp[0].lex).line);
        SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtTexture,EbpUndefined);
    }
#line 4642 "hlslang_tab.cpp"
    break;

  case 169: /* type_specifier_nonarray: SAMPLERGENERIC  */
#line 2040 "hlslang.y"
                     {
        FRAG_VERT_ONLY("sampler", (yyvsp[0].lex).line);
        SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtSamplerGeneric,EbpUndefined);
    }
#line 4651 "hlslang_tab.cpp"
    break;

  case 170: /* type_specifier_nonarray: SAMPLER1D  */
#line 2044 "hlslang.y"
                {
        FRAG_VERT_ONLY("sampler1D", (yyvsp[0].lex).line);
        SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtSampler1D,EbpUndefined);
    }
#line 4660 "hlslang_tab.cpp"
    break;

  case 171: /* type_specifier_nonarray: SAMPLER2D  */
#line 2048 "hlslang.y"
                {
        FRAG_VERT_ONLY("sampler2D", (yyvsp[0].lex).line);
        SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtSampler2D,EbpUndefined);
    }
#line 4669 "hlslang_tab.cpp"
    break;

  case 172: /* type_specifier_nonarray: SAMPLER3D  */
#line 2052 "hlslang.y"
                {
        FRAG_VERT_ONLY("sampler3D", (yyvsp[0].lex).line);
        SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtSampler3D,EbpUndefined);
    }
#line 4678 "hlslang_tab.cpp"
    break;

  case 173: /* type_specifier_nonarray: SAMPLERCUBE  */
#line 2056 "hlslang.y"
                  {
        FRAG_VERT_ONLY("samplerCube", (yyvsp[0].lex).line);
        SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtSamplerCube,EbpUndefined);
    }
#line 4687 "hlslang_tab.cpp"
    break;

  case 174: /* type_specifier_nonarray: SAMPLERRECT  */
#line 2060 "hlslang.y"
                  {
        FRAG_VERT_ONLY("samplerRECT", (yyvsp[0].lex).line);
        SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtSamplerRect,EbpUndefined);
    }
#line 4696 "hlslang_tab.cpp"
    break;

  case 175: /* type_specifier_nonarray: SAMPLERRECTSHADOW  */
#line 2064 "hlslang.y"
                        {
        FRAG_VERT_ONLY("samplerRECTShadow", (yyvsp[0].lex).line);
        SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtSamplerRectShadow,EbpUndefined);
    }
#line 4705 "hlslang_tab.cpp"
    break;

  case 176: /* type_specifier_nonarray: SAMPLER1DSHADOW  */
#line 2068 "hlslang.y"
                      {
        FRAG_VERT_ONLY("sampler1DShadow", (yyvsp[0].lex).line);
        SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtSampler1DShadow,EbpUndefined);
    }
#line 4714 "hlslang_tab.cpp"
    break;

  case 177: /* type_specifier_nonarray: SAMPLER2DSHADOW  */
#line 2072 "hlslang.y"
                      {
        FRAG_VERT_ONLY("sampler2DShadow", (yyvsp[0].lex).line);
        SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtSampler2DShadow,EbpUndefined);
    }
#line 4723 "hlslang_tab.cpp"
    break;

  case 178: /* type_specifier_nonarray: struct_specifier  */
#line 2076 "hlslang.y"
                       {
        FRAG_VERT_ONLY("struct", (yyvsp[0].interm.type).line);
        (yyval.interm.type) = (yyvsp[0].interm.type);
        (yyval.interm.type).qualifier = parseContext.getDefaultQualifier();
    }
#line 4733 "hlslang_tab.cpp"
    break;

  case 179: /* type_specifier_nonarray: TYPE_NAME  */
#line 2081 "hlslang.y"
                {     
        //
        // This is for user defined type names.  The lexical phase looked up the 
        // type.
        //
        TType& structure = static_cast<TVariable*>((yyvsp[0].lex).symbol)->getType();
        SET_BASIC_TYPE((yyval.interm.type),(yyvsp[0].lex),EbtStruct,EbpUndefined);
        (yyval.interm.type).userDef = &structure;
    }
#line 4747 "hlslang_tab.cpp"
    break;

  case 180: /* struct_specifier: STRUCT IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE  */
#line 2093 "hlslang.y"
                                                                       {
        TType* structure = new TType((yyvsp[-1].interm.typeList), *(yyvsp[-3].lex).string, EbpUndefined, (yyvsp[-3].lex).line);
        TVariable* userTypeDef = new TVariable((yyvsp[-3].lex).string, *structure, true);
        if (! parseContext.symbolTable.insert(*userTypeDef)) {
            parseContext.error((yyvsp[-3].lex).line, "redefinition", (yyvsp[-3].lex).string->c_str(), "struct");
            parseContext.recover();
        }
        (yyval.interm.type).setBasic(EbtStruct, EvqTemporary, (yyvsp[-4].lex).line);
        (yyval.interm.type).userDef = structure;
    }
#line 4762 "hlslang_tab.cpp"
    break;

  case 181: /* struct_specifier: STRUCT LEFT_BRACE struct_declaration_list RIGHT_BRACE  */
#line 2103 "hlslang.y"
                                                            {
        TType* structure = new TType((yyvsp[-1].interm.typeList), TString(""), EbpUndefined, (yyvsp[-3].lex).line);
        (yyval.interm.type).setBasic(EbtStruct, EvqTemporary, (yyvsp[-3].lex).line);
        (yyval.interm.type).userDef = structure;
    }
#line 4772 "hlslang_tab.cpp"
    break;

  case 182: /* struct_declaration_list: struct_declaration  */
#line 2111 "hlslang.y"
                         {
        (yyval.interm.typeList) = (yyvsp[0].interm.typeList);
    }
#line 4780 "hlslang_tab.cpp"
    break;

  case 183: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 2114 "hlslang.y"
                                                 {
        (yyval.interm.typeList) = (yyvsp[-1].interm.typeList);
        for (unsigned int i = 0; i < (yyvsp[0].interm.typeList)->size(); ++i) {
            for (unsigned int j = 0; j < (yyval.interm.typeList)->size(); ++j) {
                if ((*(yyval.interm.typeList))[j].type->getFieldName() == (*(yyvsp[0].interm.typeList))[i].type->getFieldName()) {
                    parseContext.error((*(yyvsp[0].interm.typeList))[i].line, "duplicate field name in structure:", "struct", (*(yyvsp[0].interm.typeList))[i].type->getFieldName().c_str());
                    parseContext.recover();
                }
            }
            (yyval.interm.typeList)->push_back((*(yyvsp[0].interm.typeList))[i]);
        }
    }
#line 4797 "hlslang_tab.cpp"
    break;

  case 184: /* struct_declaration: type_specifier struct_declarator_list SEMICOLON  */
#line 2129 "hlslang.y"
                                                      {
        (yyval.interm.typeList) = (yyvsp[-1].interm.typeList);
        
        if (parseContext.voidErrorCheck((yyvsp[-2].interm.type).line, (*(yyvsp[-1].interm.typeList))[0].type->getFieldName(), (yyvsp[-2].interm.type))) {
            parseContext.recover();
        }
        for (unsigned int i = 0; i < (yyval.interm.typeList)->size(); ++i) {
            //
            // Careful not to replace already know aspects of type, like array-ness
            //
            TType* type = (*(yyval.interm.typeList))[i].type;
            type->setBasicType((yyvsp[-2].interm.type).type);
            type->setPrecision((yyvsp[-2].interm.type).precision);
            type->setNominalSize((yyvsp[-2].interm.type).size);
            type->setMatrix((yyvsp[-2].interm.type).matrix);
            
            // don't allow arrays of arrays
            if (type->isArray()) {
                if (parseContext.arrayTypeErrorCheck((yyvsp[-2].interm.type).line, (yyvsp[-2].interm.type)))
                    parseContext.recover();
            }
            if ((yyvsp[-2].interm.type).array)
                type->setArraySize((yyvsp[-2].interm.type).arraySize);
            if ((yyvsp[-2].interm.type).userDef) {
                type->setStruct((yyvsp[-2].interm.type).userDef->getStruct());
                type->setTypeName((yyvsp[-2].interm.type).userDef->getTypeName());
            }
        }
    }
#line 4831 "hlslang_tab.cpp"
    break;

  case 185: /* struct_declarator_list: struct_declarator  */
#line 2161 "hlslang.y"
                        {
        (yyval.interm.typeList) = NewPoolTTypeList();
        (yyval.interm.typeList)->push_back((yyvsp[0].interm.typeLine));
    }
#line 4840 "hlslang_tab.cpp"
    break;

  case 186: /* struct_declarator_list: struct_declarator_list COMMA struct_declarator  */
#line 2165 "hlslang.y"
                                                     {
        (yyval.interm.typeList)->push_back((yyvsp[0].interm.typeLine));
    }
#line 4848 "hlslang_tab.cpp"
    break;

  case 187: /* struct_declarator: IDENTIFIER  */
#line 2171 "hlslang.y"
                 {
        (yyval.interm.typeLine).type = new TType(EbtVoid, EbpUndefined);
        (yyval.interm.typeLine).line = (yyvsp[0].lex).line;
        (yyval.interm.typeLine).type->setFieldName(*(yyvsp[0].lex).string);
    }
#line 4858 "hlslang_tab.cpp"
    break;

  case 188: /* struct_declarator: IDENTIFIER COLON IDENTIFIER  */
#line 2176 "hlslang.y"
                                  {
        (yyval.interm.typeLine).type = new TType(EbtVoid, EbpUndefined);
        (yyval.interm.typeLine).line = (yyvsp[-2].lex).line;
        (yyval.interm.typeLine).type->setFieldName(*(yyvsp[-2].lex).string);
        (yyval.interm.typeLine).type->setSemantic(*(yyvsp[0].lex).string);
    }
#line 4869 "hlslang_tab.cpp"
    break;

  case 189: /* struct_declarator: IDENTIFIER LEFT_BRACKET constant_expression RIGHT_BRACKET  */
#line 2182 "hlslang.y"
                                                                {
        (yyval.interm.typeLine).type = new TType(EbtVoid, EbpUndefined);
        (yyval.interm.typeLine).line = (yyvsp[-3].lex).line;
        (yyval.interm.typeLine).type->setFieldName(*(yyvsp[-3].lex).string);
        
        int size;
        if (parseContext.arraySizeErrorCheck((yyvsp[-2].lex).line, (yyvsp[-1].interm.intermTypedNode), size))
            parseContext.recover();
        (yyval.interm.typeLine).type->setArraySize(size);
    }
#line 4884 "hlslang_tab.cpp"
    break;

  case 190: /* struct_declarator: IDENTIFIER LEFT_BRACKET constant_expression RIGHT_BRACKET COLON IDENTIFIER  */
#line 2192 "hlslang.y"
                                                                                 {
        (yyval.interm.typeLine).type = new TType(EbtVoid, EbpUndefined);
        (yyval.interm.typeLine).line = (yyvsp[-5].lex).line;
        (yyval.interm.typeLine).type->setFieldName(*(yyvsp[-5].lex).string);
        
        int size;
        if (parseContext.arraySizeErrorCheck((yyvsp[-4].lex).line, (yyvsp[-3].interm.intermTypedNode), size))
            parseContext.recover();
        (yyval.interm.typeLine).type->setArraySize(size);
        (yyval.interm.typeLine).type->setSemantic(*(yyvsp[0].lex).string);
    }
#line 4900 "hlslang_tab.cpp"
    break;

  case 191: /* initializer: assignment_expression  */
#line 2208 "hlslang.y"
                            { (yyval.interm.intermTypedNode) = (yyvsp[0].interm.intermTypedNode); }
#line 4906 "hlslang_tab.cpp"
    break;

  case 192: /* initializer: initialization_list  */
#line 2209 "hlslang.y"
                          { (yyval.interm.intermTypedNode) = (yyvsp[0].interm.intermTypedNode); }
#line 4912 "hlslang_tab.cpp"
    break;

  case 193: /* initializer: sampler_initializer  */
#line 2210 "hlslang.y"
                          { (yyval.interm.intermTypedNode) = (yyvsp[0].interm.intermTypedNode); }
#line 4918 "hlslang_tab.cpp"
    break;

  case 194: /* declaration_statement: declaration  */
#line 2214 "hlslang.y"
                  { (yyval.interm.intermNode) = (yyvsp[0].interm.intermDeclaration); }
#line 4924 "hlslang_tab.cpp"
    break;

  case 195: /* statement: compound_statement  */
#line 2218 "hlslang.y"
                          { (yyval.interm.intermNode) = (yyvsp[0].interm.intermAggregate); }
#line 4930 "hlslang_tab.cpp"
    break;

  case 196: /* statement: simple_statement  */
#line 2219 "hlslang.y"
                          { (yyval.interm.intermNode) = (yyvsp[0].interm.intermNode); }
#line 4936 "hlslang_tab.cpp"
    break;

  case 197: /* simple_statement: declaration_statement  */
#line 2225 "hlslang.y"
                            { (yyval.interm.intermNode) = (yyvsp[0].interm.intermNode); }
#line 4942 "hlslang_tab.cpp"
    break;

  case 198: /* simple_statement: expression_statement  */
#line 2226 "hlslang.y"
                            { (yyval.interm.intermNode) = (yyvsp[0].interm.intermNode); }
#line 4948 "hlslang_tab.cpp"
    break;

  case 199: /* simple_statement: selection_statement  */
#line 2227 "hlslang.y"
                            { (yyval.interm.intermNode) = (yyvsp[0].interm.intermNode); }
#line 4954 "hlslang_tab.cpp"
    break;

  case 200: /* simple_statement: iteration_statement  */
#line 2228 "hlslang.y"
                            { (yyval.interm.intermNode) = (yyvsp[0].interm.intermNode); }
#line 4960 "hlslang_tab.cpp"
    break;

  case 201: /* simple_statement: jump_statement  */
#line 2229 "hlslang.y"
                            { (yyval.interm.intermNode) = (yyvsp[0].interm.intermNode); }
#line 4966 "hlslang_tab.cpp"
    break;

  case 202: /* compound_statement: LEFT_BRACE RIGHT_BRACE  */
#line 2233 "hlslang.y"
                             { (yyval.interm.intermAggregate) = 0; }
#line 4972 "hlslang_tab.cpp"
    break;

  case 203: /* $@1: %empty  */
#line 2234 "hlslang.y"
                 { parseContext.symbolTable.push(); }
#line 4978 "hlslang_tab.cpp"
    break;

  case 204: /* $@2: %empty  */
#line 2234 "hlslang.y"
                                                                     { parseContext.symbolTable.pop(); }
#line 4984 "hlslang_tab.cpp"
    break;

  case 205: /* compound_statement: LEFT_BRACE $@1 statement_list $@2 RIGHT_BRACE  */
#line 2234 "hlslang.y"
                                                                                                                     {
        if ((yyvsp[-2].interm.intermAggregate) != 0)            
            (yyvsp[-2].interm.intermAggregate)->setOperator(EOpSequence); 
        (yyval.interm.intermAggregate) = (yyvsp[-2].interm.intermAggregate);
    }
#line 4994 "hlslang_tab.cpp"
    break;

  case 206: /* statement_no_new_scope: compound_statement_no_new_scope  */
#line 2242 "hlslang.y"
                                      { (yyval.interm.intermNode) = (yyvsp[0].interm.intermNode); }
#line 5000 "hlslang_tab.cpp"
    break;

  case 207: /* statement_no_new_scope: simple_statement  */
#line 2243 "hlslang.y"
                                      { (yyval.interm.intermNode) = (yyvsp[0].interm.intermNode); }
#line 5006 "hlslang_tab.cpp"
    break;

  case 208: /* compound_statement_no_new_scope: LEFT_BRACE RIGHT_BRACE  */
#line 2248 "hlslang.y"
                             { 
        (yyval.interm.intermNode) = 0; 
    }
#line 5014 "hlslang_tab.cpp"
    break;

  case 209: /* compound_statement_no_new_scope: LEFT_BRACE statement_list RIGHT_BRACE  */
#line 2251 "hlslang.y"
                                            { 
        if ((yyvsp[-1].interm.intermAggregate))
            (yyvsp[-1].interm.intermAggregate)->setOperator(EOpSequence); 
        (yyval.interm.intermNode) = (yyvsp[-1].interm.intermAggregate); 
    }
#line 5024 "hlslang_tab.cpp"
    break;

  case 210: /* statement_list: statement  */
#line 2259 "hlslang.y"
                {
        (yyval.interm.intermAggregate) = parseContext.intermediate.makeAggregate((yyvsp[0].interm.intermNode), gNullSourceLoc); 
    }
#line 5032 "hlslang_tab.cpp"
    break;

  case 211: /* statement_list: statement_list statement  */
#line 2262 "hlslang.y"
                               { 
        (yyval.interm.intermAggregate) = parseContext.intermediate.growAggregate((yyvsp[-1].interm.intermAggregate), (yyvsp[0].interm.intermNode), gNullSourceLoc);
    }
#line 5040 "hlslang_tab.cpp"
    break;

  case 212: /* expression_statement: SEMICOLON  */
#line 2268 "hlslang.y"
                 { (yyval.interm.intermNode) = 0; }
#line 5046 "hlslang_tab.cpp"
    break;

  case 213: /* expression_statement: expression SEMICOLON  */
#line 2269 "hlslang.y"
                            { (yyval.interm.intermNode) = static_cast<TIntermNode*>((yyvsp[-1].interm.intermTypedNode)); }
#line 5052 "hlslang_tab.cpp"
    break;

  case 214: /* selection_statement: IF LEFT_PAREN expression RIGHT_PAREN selection_rest_statement  */
#line 2273 "hlslang.y"
                                                                    { 
        if (parseContext.boolErrorCheck((yyvsp[-4].lex).line, (yyvsp[-2].interm.intermTypedNode)))
            parseContext.recover();
        (yyval.interm.intermNode) = parseContext.intermediate.addSelection((yyvsp[-2].interm.intermTypedNode), (yyvsp[0].interm.nodePair), (yyvsp[-4].lex).line);
    }
#line 5062 "hlslang_tab.cpp"
    break;

  case 215: /* selection_rest_statement: statement ELSE statement  */
#line 2281 "hlslang.y"
                               {
        (yyval.interm.nodePair).node1 = (yyvsp[-2].interm.intermNode);
        (yyval.interm.nodePair).node2 = (yyvsp[0].interm.intermNode);
    }
#line 5071 "hlslang_tab.cpp"
    break;

  case 216: /* selection_rest_statement: statement  */
#line 2285 "hlslang.y"
                { 
        (yyval.interm.nodePair).node1 = (yyvsp[0].interm.intermNode);
        (yyval.interm.nodePair).node2 = 0;
    }
#line 5080 "hlslang_tab.cpp"
    break;

  case 217: /* condition: expression  */
#line 2295 "hlslang.y"
                 {
        (yyval.interm.intermTypedNode) = (yyvsp[0].interm.intermTypedNode);
        if (parseContext.boolErrorCheck((yyvsp[0].interm.intermTypedNode)->getLine(), (yyvsp[0].interm.intermTypedNode)))
            parseContext.recover();          
    }
#line 5090 "hlslang_tab.cpp"
    break;

  case 218: /* condition: fully_specified_type IDENTIFIER EQUAL initializer  */
#line 2300 "hlslang.y"
                                                        {
        TIntermSymbol* symbol;
        if (parseContext.structQualifierErrorCheck((yyvsp[-2].lex).line, (yyvsp[-3].interm.type)))
            parseContext.recover();
        if (parseContext.boolErrorCheck((yyvsp[-2].lex).line, (yyvsp[-3].interm.type)))
            parseContext.recover();
        
        if (!parseContext.executeInitializer((yyvsp[-2].lex).line, *(yyvsp[-2].lex).string, (yyvsp[-3].interm.type), (yyvsp[0].interm.intermTypedNode), symbol)) {
			(yyval.interm.intermTypedNode) = parseContext.intermediate.addDeclaration(symbol, (yyvsp[0].interm.intermTypedNode), (yyvsp[-2].lex).line);
        } else {
            parseContext.recover();
            (yyval.interm.intermTypedNode) = 0;
        }
    }
#line 5109 "hlslang_tab.cpp"
    break;

  case 219: /* $@3: %empty  */
#line 2317 "hlslang.y"
                       { parseContext.symbolTable.push(); ++parseContext.loopNestingLevel; }
#line 5115 "hlslang_tab.cpp"
    break;

  case 220: /* iteration_statement: WHILE LEFT_PAREN $@3 condition RIGHT_PAREN statement_no_new_scope  */
#line 2317 "hlslang.y"
                                                                                                                                          { 
        parseContext.symbolTable.pop();
        (yyval.interm.intermNode) = parseContext.intermediate.addLoop(ELoopWhile, (yyvsp[-2].interm.intermTypedNode), 0, (yyvsp[0].interm.intermNode), (yyvsp[-5].lex).line);
        --parseContext.loopNestingLevel;
    }
#line 5125 "hlslang_tab.cpp"
    break;

  case 221: /* $@4: %empty  */
#line 2322 "hlslang.y"
         { ++parseContext.loopNestingLevel; }
#line 5131 "hlslang_tab.cpp"
    break;

  case 222: /* iteration_statement: DO $@4 statement WHILE LEFT_PAREN expression RIGHT_PAREN SEMICOLON  */
#line 2322 "hlslang.y"
                                                                                                          {
        if (parseContext.boolErrorCheck((yyvsp[0].lex).line, (yyvsp[-2].interm.intermTypedNode)))
            parseContext.recover();
                    
        (yyval.interm.intermNode) = parseContext.intermediate.addLoop(ELoopDoWhile, (yyvsp[-2].interm.intermTypedNode), 0, (yyvsp[-5].interm.intermNode), (yyvsp[-4].lex).line);
        --parseContext.loopNestingLevel;
    }
#line 5143 "hlslang_tab.cpp"
    break;

  case 223: /* $@5: %empty  */
#line 2329 "hlslang.y"
                     { parseContext.symbolTable.push(); ++parseContext.loopNestingLevel; }
#line 5149 "hlslang_tab.cpp"
    break;

  case 224: /* iteration_statement: FOR LEFT_PAREN $@5 for_init_statement for_rest_statement RIGHT_PAREN statement_no_new_scope  */
#line 2329 "hlslang.y"
                                                                                                                                                                    {
        parseContext.symbolTable.pop();
        (yyval.interm.intermNode) = parseContext.intermediate.makeAggregate((yyvsp[-3].interm.intermNode), (yyvsp[-5].lex).line);
        (yyval.interm.intermNode) = parseContext.intermediate.growAggregate(
                (yyval.interm.intermNode),
                parseContext.intermediate.addLoop(ELoopFor, reinterpret_cast<TIntermTyped*>((yyvsp[-2].interm.nodePair).node1), reinterpret_cast<TIntermTyped*>((yyvsp[-2].interm.nodePair).node2), (yyvsp[0].interm.intermNode), (yyvsp[-6].lex).line),
                (yyvsp[-6].lex).line);
        (yyval.interm.intermNode)->getAsAggregate()->setOperator(EOpSequence);
        --parseContext.loopNestingLevel;
    }
#line 5164 "hlslang_tab.cpp"
    break;

  case 225: /* for_init_statement: expression_statement  */
#line 2342 "hlslang.y"
                           {
        (yyval.interm.intermNode) = (yyvsp[0].interm.intermNode); 
    }
#line 5172 "hlslang_tab.cpp"
    break;

  case 226: /* for_init_statement: declaration_statement  */
#line 2345 "hlslang.y"
                            {
        (yyval.interm.intermNode) = (yyvsp[0].interm.intermNode);
    }
#line 5180 "hlslang_tab.cpp"
    break;

  case 227: /* conditionopt: condition  */
#line 2351 "hlslang.y"
                { 
        (yyval.interm.intermTypedNode) = (yyvsp[0].interm.intermTypedNode); 
    }
#line 5188 "hlslang_tab.cpp"
    break;

  case 228: /* conditionopt: %empty  */
#line 2354 "hlslang.y"
                        { 
        (yyval.interm.intermTypedNode) = 0; 
    }
#line 5196 "hlslang_tab.cpp"
    break;

  case 229: /* for_rest_statement: conditionopt SEMICOLON  */
#line 2360 "hlslang.y"
                             { 
        (yyval.interm.nodePair).node1 = (yyvsp[-1].interm.intermTypedNode);
        (yyval.interm.nodePair).node2 = 0;
    }
#line 5205 "hlslang_tab.cpp"
    break;

  case 230: /* for_rest_statement: conditionopt SEMICOLON expression  */
#line 2364 "hlslang.y"
                                         {
        (yyval.interm.nodePair).node1 = (yyvsp[-2].interm.intermTypedNode);
        (yyval.interm.nodePair).node2 = (yyvsp[0].interm.intermTypedNode);
    }
#line 5214 "hlslang_tab.cpp"
    break;

  case 231: /* jump_statement: CONTINUE SEMICOLON  */
#line 2371 "hlslang.y"
                         {
        if (parseContext.loopNestingLevel <= 0) {
            parseContext.error((yyvsp[-1].lex).line, "continue statement only allowed in loops", "", "");
            parseContext.recover();
        }        
        (yyval.interm.intermNode) = parseContext.intermediate.addBranch(EOpContinue, (yyvsp[-1].lex).line);
    }
#line 5226 "hlslang_tab.cpp"
    break;

  case 232: /* jump_statement: BREAK SEMICOLON  */
#line 2378 "hlslang.y"
                      {
        if (parseContext.loopNestingLevel <= 0) {
            parseContext.error((yyvsp[-1].lex).line, "break statement only allowed in loops", "", "");
            parseContext.recover();
        }        
        (yyval.interm.intermNode) = parseContext.intermediate.addBranch(EOpBreak, (yyvsp[-1].lex).line);
    }
#line 5238 "hlslang_tab.cpp"
    break;

  case 233: /* jump_statement: RETURN SEMICOLON  */
#line 2385 "hlslang.y"
                       {
        (yyval.interm.intermNode) = parseContext.intermediate.addBranch(EOpReturn, (yyvsp[-1].lex).line);
        if (parseContext.currentFunctionType->getBasicType() != EbtVoid) {
            parseContext.error((yyvsp[-1].lex).line, "non-void function must return a value", "return", "");
            parseContext.recover();
        }
    }
#line 5250 "hlslang_tab.cpp"
    break;

  case 234: /* jump_statement: RETURN expression SEMICOLON  */
#line 2392 "hlslang.y"
                                  {        
        TIntermTyped *temp = (yyvsp[-1].interm.intermTypedNode);
        if (parseContext.currentFunctionType->getBasicType() == EbtVoid) {
            parseContext.error((yyvsp[-2].lex).line, "void function cannot return a value", "return", "");
            parseContext.recover();
        } else if (*(parseContext.currentFunctionType) != (yyvsp[-1].interm.intermTypedNode)->getType()) {
            TOperator op = parseContext.getConstructorOp(*(parseContext.currentFunctionType));
            if (op != EOpNull)
                temp = parseContext.constructBuiltIn((parseContext.currentFunctionType), op, (yyvsp[-1].interm.intermTypedNode), (yyvsp[-2].lex).line, false);
            else
                temp = 0;
            if (temp == 0) {
                parseContext.error((yyvsp[-2].lex).line, "function return is not matching type:", "return", "");
                parseContext.recover();
                temp = (yyvsp[-1].interm.intermTypedNode);
            }
        }
        (yyval.interm.intermNode) = parseContext.intermediate.addBranch(EOpReturn, temp, (yyvsp[-2].lex).line);
        parseContext.functionReturnsValue = true;
    }
#line 5275 "hlslang_tab.cpp"
    break;

  case 235: /* jump_statement: DISCARD SEMICOLON  */
#line 2412 "hlslang.y"
                        {
		// Jim: using discard when compiling vertex shaders should not be considered a syntactic error, instead,
		// we should issue a semantic error only if the code path is actually executed. (Not yet implemented)
        //FRAG_ONLY("discard", $1.line);
        (yyval.interm.intermNode) = parseContext.intermediate.addBranch(EOpKill, (yyvsp[-1].lex).line);
    }
#line 5286 "hlslang_tab.cpp"
    break;

  case 236: /* translation_unit: external_declaration  */
#line 2423 "hlslang.y"
                           { 
        (yyval.interm.intermNode) = (yyvsp[0].interm.intermNode); 
        parseContext.treeRoot = (yyval.interm.intermNode); 
    }
#line 5295 "hlslang_tab.cpp"
    break;

  case 237: /* translation_unit: translation_unit external_declaration  */
#line 2427 "hlslang.y"
                                            {
        (yyval.interm.intermNode) = parseContext.intermediate.growAggregate((yyvsp[-1].interm.intermNode), (yyvsp[0].interm.intermNode), gNullSourceLoc);
        parseContext.treeRoot = (yyval.interm.intermNode);
    }
#line 5304 "hlslang_tab.cpp"
    break;

  case 238: /* external_declaration: function_definition  */
#line 2434 "hlslang.y"
                          { 
        (yyval.interm.intermNode) = (yyvsp[0].interm.intermNode); 
    }
#line 5312 "hlslang_tab.cpp"
    break;

  case 239: /* external_declaration: declaration  */
#line 2437 "hlslang.y"
                  { 
        (yyval.interm.intermNode) = (yyvsp[0].interm.intermDeclaration); 
    }
#line 5320 "hlslang_tab.cpp"
    break;

  case 240: /* external_declaration: SEMICOLON  */
#line 2440 "hlslang.y"
                { (yyval.interm.intermNode) = 0; }
#line 5326 "hlslang_tab.cpp"
    break;

  case 241: /* $@6: %empty  */
#line 2444 "hlslang.y"
                         {
        TFunction& function = *((yyvsp[0].interm).function);
        TFunction* prevDec = static_cast<TFunction*>(parseContext.symbolTable.find(function.getMangledName()));
        //
        // Note:  'prevDec' could be 'function' if this is the first time we've seen function
        // as it would have just been put in the symbol table.  Otherwise, we're looking up
        // an earlier occurance.
        //
        if (prevDec->isDefined()) {
            //
            // Then this function already has a body.
            //
            parseContext.error((yyvsp[0].interm).line, "function already has a body", function.getName().c_str(), "");
            parseContext.recover();
        }
        prevDec->setDefined();
        
        //
        // New symbol table scope for body of function plus its arguments
        //
        parseContext.symbolTable.push();
        
        //
        // Remember the return type for later checking for RETURN statements.
        //
        parseContext.currentFunctionType = &(prevDec->getReturnType());
        parseContext.functionReturnsValue = false;
        
        // 
        // Insert parameters into the symbol table.
        // If the parameter has no name, it's not an error, just don't insert it 
        // (could be used for unused args).
        //
        // Also, accumulate the list of parameters into the HIL, so lower level code
        // knows where to find parameters.
        //
        TIntermAggregate* paramNodes = new TIntermAggregate;
        for (int i = 0; i < function.getParamCount(); i++) {
            TParameter& param = function[i];
            if (param.name != 0) {
                TVariable *variable = new TVariable(param.name, param.info, *param.type);
                // 
                // Insert the parameters with name in the symbol table.
                //
                if (! parseContext.symbolTable.insert(*variable)) {
                    parseContext.error((yyvsp[0].interm).line, "redefinition", variable->getName().c_str(), "");
                    parseContext.recover();
                    delete variable;
                }
                //
                // Transfer ownership of name pointer to symbol table.
                //
                param.name = 0;
                
                //
                // Add the parameter to the HIL
                //                
                paramNodes = parseContext.intermediate.growAggregate(
                                               paramNodes, 
                                               parseContext.intermediate.addSymbol(variable->getUniqueId(),
                                                                       variable->getName(),
                                                                       variable->getInfo(),
                                                                       variable->getType(), (yyvsp[0].interm).line), 
                                               (yyvsp[0].interm).line);
            } else {
                paramNodes = parseContext.intermediate.growAggregate(paramNodes, parseContext.intermediate.addSymbol(0, "", param.info, *param.type, (yyvsp[0].interm).line), (yyvsp[0].interm).line);
            }
        }
        parseContext.intermediate.setAggregateOperator(paramNodes, EOpParameters, (yyvsp[0].interm).line);
        (yyvsp[0].interm).intermAggregate = paramNodes;
        parseContext.loopNestingLevel = 0;
    }
#line 5403 "hlslang_tab.cpp"
    break;

  case 242: /* function_definition: function_prototype $@6 compound_statement_no_new_scope  */
#line 2516 "hlslang.y"
                                    {
        //?? Check that all paths return a value if return type != void ?
        //   May be best done as post process phase on intermediate code
        if (parseContext.currentFunctionType->getBasicType() != EbtVoid && ! parseContext.functionReturnsValue) {
            parseContext.error((yyvsp[-2].interm).line, "function does not return a value:", "", (yyvsp[-2].interm).function->getName().c_str());
            parseContext.recover();
        }
        parseContext.symbolTable.pop();
        TIntermAggregate *newNode = parseContext.intermediate.growAggregate((yyvsp[-2].interm).intermAggregate, (yyvsp[0].interm.intermNode), gNullSourceLoc);
        (yyval.interm.intermNode) = newNode;
        parseContext.intermediate.setAggregateOperator((yyval.interm.intermNode), EOpFunction, (yyvsp[-2].interm).line);
        (yyval.interm.intermNode)->getAsAggregate()->setName((yyvsp[-2].interm).function->getMangledName().c_str());
        (yyval.interm.intermNode)->getAsAggregate()->setPlainName((yyvsp[-2].interm).function->getName().c_str());
        (yyval.interm.intermNode)->getAsAggregate()->setType((yyvsp[-2].interm).function->getReturnType());
        
        //put it to inline function list if return type or one of parameters is non-square matrix
        if ((yyvsp[-2].interm).function->isInline())
			parseContext.inlineFuncList[(yyvsp[-2].interm).function->getMangledName()] = newNode;
        
	if ( (yyvsp[-2].interm).function->getInfo())
	    (yyval.interm.intermNode)->getAsAggregate()->setSemantic((yyvsp[-2].interm).function->getInfo()->getSemantic());
    }
#line 5430 "hlslang_tab.cpp"
    break;

  case 243: /* initialization_list: LEFT_BRACE initializer_list RIGHT_BRACE  */
#line 2541 "hlslang.y"
                                              {
		(yyval.interm.intermTypedNode) = (yyvsp[-1].interm.intermAggregate);
    }
#line 5438 "hlslang_tab.cpp"
    break;

  case 244: /* initialization_list: LEFT_BRACE initializer_list COMMA RIGHT_BRACE  */
#line 2544 "hlslang.y"
                                                    {
		(yyval.interm.intermTypedNode) = (yyvsp[-2].interm.intermAggregate);
    }
#line 5446 "hlslang_tab.cpp"
    break;

  case 245: /* initializer_list: assignment_expression  */
#line 2551 "hlslang.y"
                            {
        //create a new aggNode
       (yyval.interm.intermAggregate) = parseContext.intermediate.makeAggregate( (yyvsp[0].interm.intermTypedNode), (yyvsp[0].interm.intermTypedNode)->getLine());       
    }
#line 5455 "hlslang_tab.cpp"
    break;

  case 246: /* initializer_list: initialization_list  */
#line 2555 "hlslang.y"
                          {
       //take the inherited aggNode and return it
       (yyval.interm.intermAggregate) = (yyvsp[0].interm.intermTypedNode)->getAsAggregate();       
    }
#line 5464 "hlslang_tab.cpp"
    break;

  case 247: /* initializer_list: initializer_list COMMA assignment_expression  */
#line 2559 "hlslang.y"
                                                   {
        // append to the aggNode
       (yyval.interm.intermAggregate) = parseContext.intermediate.growAggregate( (yyvsp[-2].interm.intermAggregate), (yyvsp[0].interm.intermTypedNode), (yyvsp[0].interm.intermTypedNode)->getLine());       
    }
#line 5473 "hlslang_tab.cpp"
    break;

  case 248: /* initializer_list: initializer_list COMMA initialization_list  */
#line 2563 "hlslang.y"
                                                 {
       // append all children or $3 to $1 
       (yyval.interm.intermAggregate) = parseContext.mergeAggregates( (yyvsp[-2].interm.intermAggregate), (yyvsp[0].interm.intermTypedNode)->getAsAggregate());
    }
#line 5482 "hlslang_tab.cpp"
    break;

  case 249: /* annotation: LEFT_ANGLE RIGHT_ANGLE  */
#line 2570 "hlslang.y"
                             {
        //empty annotation
	  (yyval.interm.ann) = 0;
    }
#line 5491 "hlslang_tab.cpp"
    break;

  case 250: /* annotation: LEFT_ANGLE annotation_list RIGHT_ANGLE  */
#line 2574 "hlslang.y"
                                             {
      (yyval.interm.ann) = (yyvsp[-1].interm.ann);
    }
#line 5499 "hlslang_tab.cpp"
    break;

  case 251: /* annotation_list: annotation_item  */
#line 2580 "hlslang.y"
                      {
        (yyval.interm.ann) = new TAnnotation;
		(yyval.interm.ann)->addKey( *(yyvsp[0].lex).string);
    }
#line 5508 "hlslang_tab.cpp"
    break;

  case 252: /* annotation_list: annotation_list annotation_item  */
#line 2584 "hlslang.y"
                                      {
        (yyvsp[-1].interm.ann)->addKey( *(yyvsp[0].lex).string);
		(yyval.interm.ann) = (yyvsp[-1].interm.ann);
    }
#line 5517 "hlslang_tab.cpp"
    break;

  case 253: /* annotation_item: ann_type IDENTIFIER EQUAL ann_literal SEMICOLON  */
#line 2591 "hlslang.y"
                                                      {
        (yyval.lex).string = (yyvsp[-3].lex).string;
    }
#line 5525 "hlslang_tab.cpp"
    break;

  case 254: /* ann_type: FLOAT_TYPE  */
#line 2597 "hlslang.y"
                 {}
#line 5531 "hlslang_tab.cpp"
    break;

  case 255: /* ann_type: HALF_TYPE  */
#line 2598 "hlslang.y"
                {}
#line 5537 "hlslang_tab.cpp"
    break;

  case 256: /* ann_type: FIXED_TYPE  */
#line 2599 "hlslang.y"
                 {}
#line 5543 "hlslang_tab.cpp"
    break;

  case 257: /* ann_type: INT_TYPE  */
#line 2600 "hlslang.y"
               {}
#line 5549 "hlslang_tab.cpp"
    break;

  case 258: /* ann_type: BOOL_TYPE  */
#line 2601 "hlslang.y"
                {}
#line 5555 "hlslang_tab.cpp"
    break;

  case 259: /* ann_type: STRING_TYPE  */
#line 2602 "hlslang.y"
                  {}
#line 5561 "hlslang_tab.cpp"
    break;

  case 260: /* ann_type: BVEC2  */
#line 2603 "hlslang.y"
            {}
#line 5567 "hlslang_tab.cpp"
    break;

  case 261: /* ann_type: BVEC3  */
#line 2604 "hlslang.y"
            {}
#line 5573 "hlslang_tab.cpp"
    break;

  case 262: /* ann_type: BVEC4  */
#line 2605 "hlslang.y"
            {}
#line 5579 "hlslang_tab.cpp"
    break;

  case 263: /* ann_type: IVEC2  */
#line 2606 "hlslang.y"
            {}
#line 5585 "hlslang_tab.cpp"
    break;

  case 264: /* ann_type: IVEC3  */
#line 2607 "hlslang.y"
            {}
#line 5591 "hlslang_tab.cpp"
    break;

  case 265: /* ann_type: IVEC4  */
#line 2608 "hlslang.y"
            {}
#line 5597 "hlslang_tab.cpp"
    break;

  case 266: /* ann_type: VEC2  */
#line 2609 "hlslang.y"
           {}
#line 5603 "hlslang_tab.cpp"
    break;

  case 267: /* ann_type: VEC3  */
#line 2610 "hlslang.y"
           {}
#line 5609 "hlslang_tab.cpp"
    break;

  case 268: /* ann_type: VEC4  */
#line 2611 "hlslang.y"
           {}
#line 5615 "hlslang_tab.cpp"
    break;

  case 269: /* ann_type: HVEC2  */
#line 2612 "hlslang.y"
            {}
#line 5621 "hlslang_tab.cpp"
    break;

  case 270: /* ann_type: HVEC3  */
#line 2613 "hlslang.y"
            {}
#line 5627 "hlslang_tab.cpp"
    break;

  case 271: /* ann_type: HVEC4  */
#line 2614 "hlslang.y"
            {}
#line 5633 "hlslang_tab.cpp"
    break;

  case 272: /* ann_type: FVEC2  */
#line 2615 "hlslang.y"
            {}
#line 5639 "hlslang_tab.cpp"
    break;

  case 273: /* ann_type: FVEC3  */
#line 2616 "hlslang.y"
            {}
#line 5645 "hlslang_tab.cpp"
    break;

  case 274: /* ann_type: FVEC4  */
#line 2617 "hlslang.y"
            {}
#line 5651 "hlslang_tab.cpp"
    break;

  case 275: /* ann_literal: ann_numerical_constant  */
#line 2621 "hlslang.y"
                                 {}
#line 5657 "hlslang_tab.cpp"
    break;

  case 276: /* ann_literal: STRINGCONSTANT  */
#line 2622 "hlslang.y"
                         {}
#line 5663 "hlslang_tab.cpp"
    break;

  case 277: /* ann_literal: ann_literal_constructor  */
#line 2623 "hlslang.y"
                                  {}
#line 5669 "hlslang_tab.cpp"
    break;

  case 278: /* ann_literal: ann_literal_init_list  */
#line 2624 "hlslang.y"
                                {}
#line 5675 "hlslang_tab.cpp"
    break;

  case 279: /* ann_numerical_constant: INTCONSTANT  */
#line 2628 "hlslang.y"
                      {
		(yyval.lex).f = (float)(yyvsp[0].lex).i;
	}
#line 5683 "hlslang_tab.cpp"
    break;

  case 280: /* ann_numerical_constant: BOOLCONSTANT  */
#line 2631 "hlslang.y"
                       {
		(yyval.lex).f = ((yyvsp[0].lex).b) ? 1.0f : 0.0f;
	}
#line 5691 "hlslang_tab.cpp"
    break;

  case 281: /* ann_numerical_constant: FLOATCONSTANT  */
#line 2634 "hlslang.y"
                        {
		(yyval.lex).f = (yyvsp[0].lex).f;
	}
#line 5699 "hlslang_tab.cpp"
    break;

  case 282: /* ann_literal_constructor: ann_type LEFT_PAREN ann_value_list RIGHT_PAREN  */
#line 2640 "hlslang.y"
                                                         {}
#line 5705 "hlslang_tab.cpp"
    break;

  case 283: /* ann_value_list: ann_numerical_constant  */
#line 2644 "hlslang.y"
                                 {}
#line 5711 "hlslang_tab.cpp"
    break;

  case 284: /* ann_value_list: ann_value_list COMMA ann_numerical_constant  */
#line 2645 "hlslang.y"
                                                      {}
#line 5717 "hlslang_tab.cpp"
    break;

  case 285: /* ann_literal_init_list: LEFT_BRACE ann_value_list RIGHT_BRACE  */
#line 2649 "hlslang.y"
                                                {}
#line 5723 "hlslang_tab.cpp"
    break;

  case 286: /* register_specifier: COLON REGISTER LEFT_PAREN IDENTIFIER RIGHT_PAREN  */
#line 2653 "hlslang.y"
                                                       {
        // This is being thrown away
    }
#line 5731 "hlslang_tab.cpp"
    break;

  case 287: /* semantic: COLON IDENTIFIER  */
#line 2659 "hlslang.y"
                           { (yyval.lex).string = (yyvsp[0].lex).string;}
#line 5737 "hlslang_tab.cpp"
    break;

  case 288: /* type_info: %empty  */
#line 2663 "hlslang.y"
          { (yyval.interm.typeInfo) = 0;}
#line 5743 "hlslang_tab.cpp"
    break;

  case 289: /* type_info: semantic  */
#line 2664 "hlslang.y"
                   { (yyval.interm.typeInfo) = new TTypeInfo( *(yyvsp[0].lex).string, 0); }
#line 5749 "hlslang_tab.cpp"
    break;

  case 290: /* type_info: register_specifier  */
#line 2665 "hlslang.y"
                             { (yyval.interm.typeInfo) = 0; }
#line 5755 "hlslang_tab.cpp"
    break;

  case 291: /* type_info: annotation  */
#line 2666 "hlslang.y"
                     { (yyval.interm.typeInfo) = new TTypeInfo( "", (yyvsp[0].interm.ann)); }
#line 5761 "hlslang_tab.cpp"
    break;

  case 292: /* type_info: semantic annotation  */
#line 2667 "hlslang.y"
                              { (yyval.interm.typeInfo) = new TTypeInfo( *(yyvsp[-1].lex).string, (yyvsp[0].interm.ann)); }
#line 5767 "hlslang_tab.cpp"
    break;

  case 293: /* type_info: semantic register_specifier  */
#line 2668 "hlslang.y"
                                      { (yyval.interm.typeInfo) = new TTypeInfo( *(yyvsp[-1].lex).string, 0); }
#line 5773 "hlslang_tab.cpp"
    break;

  case 294: /* type_info: register_specifier annotation  */
#line 2669 "hlslang.y"
                                        { (yyval.interm.typeInfo) = new TTypeInfo( "", (yyvsp[0].interm.ann)); }
#line 5779 "hlslang_tab.cpp"
    break;

  case 295: /* type_info: semantic register_specifier annotation  */
#line 2670 "hlslang.y"
                                                 { (yyval.interm.typeInfo) = new TTypeInfo( *(yyvsp[-2].lex).string, (yyvsp[0].interm.ann)); }
#line 5785 "hlslang_tab.cpp"
    break;

  case 296: /* sampler_initializer: SAMPLERSTATE LEFT_BRACE sampler_init_list RIGHT_BRACE  */
#line 2674 "hlslang.y"
                                                                {
		TIntermConstant* constant = parseContext.intermediate.addConstant(TType(EbtFloat, EbpUndefined, EvqConst, 1), (yyvsp[-3].lex).line);
		constant->setValue(0.f);
		(yyval.interm.intermTypedNode) = constant;
	}
#line 5795 "hlslang_tab.cpp"
    break;

  case 297: /* sampler_initializer: SAMPLERSTATE LEFT_BRACE RIGHT_BRACE  */
#line 2679 "hlslang.y"
                                              {
	}
#line 5802 "hlslang_tab.cpp"
    break;

  case 298: /* sampler_init_list: sampler_init_item  */
#line 2684 "hlslang.y"
                            { }
#line 5808 "hlslang_tab.cpp"
    break;

  case 299: /* sampler_init_list: sampler_init_list sampler_init_item  */
#line 2685 "hlslang.y"
                                              { }
#line 5814 "hlslang_tab.cpp"
    break;

  case 300: /* sampler_init_item: IDENTIFIER EQUAL IDENTIFIER SEMICOLON  */
#line 2689 "hlslang.y"
                                                {}
#line 5820 "hlslang_tab.cpp"
    break;

  case 301: /* sampler_init_item: IDENTIFIER EQUAL LEFT_ANGLE IDENTIFIER RIGHT_ANGLE SEMICOLON  */
#line 2690 "hlslang.y"
                                                                       {}
#line 5826 "hlslang_tab.cpp"
    break;

  case 302: /* sampler_init_item: IDENTIFIER EQUAL LEFT_PAREN IDENTIFIER RIGHT_PAREN SEMICOLON  */
#line 2691 "hlslang.y"
                                                                       {}
#line 5832 "hlslang_tab.cpp"
    break;

  case 303: /* sampler_init_item: TEXTURE EQUAL IDENTIFIER SEMICOLON  */
#line 2692 "hlslang.y"
                                             {}
#line 5838 "hlslang_tab.cpp"
    break;

  case 304: /* sampler_init_item: TEXTURE EQUAL LEFT_ANGLE IDENTIFIER RIGHT_ANGLE SEMICOLON  */
#line 2693 "hlslang.y"
                                                                    {}
#line 5844 "hlslang_tab.cpp"
    break;

  case 305: /* sampler_init_item: TEXTURE EQUAL LEFT_PAREN IDENTIFIER RIGHT_PAREN SEMICOLON  */
#line 2694 "hlslang.y"
                                                                    {}
#line 5850 "hlslang_tab.cpp"
    break;


#line 5854 "hlslang_tab.cpp"

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
      yyerror (parseContextLocal, YY_("syntax error"));
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
                      yytoken, &yylval, parseContextLocal);
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, parseContextLocal);
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
  yyerror (parseContextLocal, YY_("memory exhausted"));
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
                  yytoken, &yylval, parseContextLocal);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, parseContextLocal);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 2697 "hlslang.y"

