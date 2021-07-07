cmake_minimum_required(VERSION 3.14)
project(CUUC)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_COMPILER clang)

find_package(BISON)
find_package(FLEX)

BISON_TARGET(parser 
	     ${CMAKE_SOURCE_DIR}/src/parser/parser.y
	     ${CMAKE_CURRENT_BINARY_DIR}/parser.tab.c
	     VERBOSE
	     DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/parser.tab.h)
FLEX_TARGET(lex 
	    ${CMAKE_SOURCE_DIR}/src/lexer/lex.l 
	    ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.c
	    DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.h)

ADD_FLEX_BISON_DEPENDENCY(lex parser)

FILE(GLOB_RECURSE FILES ${CMAKE_SOURCE_DIR}/src/asm/*.c
			${CMAKE_SOURCE_DIR}/src/common/*.c
			${CMAKE_SOURCE_DIR}/src/lexer/*.c
			${CMAKE_SOURCE_DIR}/src/parser/*.c
			${CMAKE_SOURCE_DIR}/src/quads/*.c)

include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_CURRENT_BINARY_DIR})

add_executable(compiler 
	       ${CMAKE_SOURCE_DIR}/src/execs/compiler.c
	       ${BISON_parser_OUTPUTS} 
	       ${FLEX_lex_OUTPUTS} 
	       ${FILES})

# add_executable(lex_print
# 	       ${CMAKE_SOURCE_DIR}/src/execs/lex_print.c
# 	       ${BISON_parser_OUTPUTS}
# 	       ${FLEX_lex_OUTPUTS}
# 	       ${FILES})
