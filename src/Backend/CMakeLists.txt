cmake_minimum_required (VERSION 3.8)

aux_source_directory(. DIR_LIB_SRCS)

add_library(IR2ASM ${DIR_LIB_SRCS})

target_include_directories(IR2ASM PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
