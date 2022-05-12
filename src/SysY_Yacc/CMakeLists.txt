cmake_minimum_required (VERSION 3.8)

aux_source_directory(. DIR_LIB_SRCS)

add_library(SysY_Yacc ${DIR_LIB_SRCS})

target_include_directories(SysY_Yacc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})