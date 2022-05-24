cmake_minimum_required (VERSION 3.8)

add_subdirectory (SysY_Lex)
add_subdirectory (SysY_Yacc)

aux_source_directory(. DIR_SRCS)
# aux_source_directory(SysY_Lex DIR_SRCS)

add_executable(Test ${DIR_SRCS})

target_link_libraries(Test SysY_Lex)
target_link_libraries(Test SysY_Yacc)

include_directories(${PROJECT_SOURCE_DIR}/include)
