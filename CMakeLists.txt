cmake_minimum_required (VERSION 3.8)

set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS_RELEASE "-O2")

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

project ("compiler")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/out)
#设置库文件的输出目录
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/out/lib)
#增加当前文件夹下的src文件夹为子文件夹，进入该文件夹执行其目录下CMakeLists.txt文件
add_subdirectory(${PROJECT_SOURCE_DIR}/src)
