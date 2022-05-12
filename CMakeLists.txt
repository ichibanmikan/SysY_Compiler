cmake_minimum_required (VERSION 3.8)

project ("Test")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/out)
#设置库文件的输出目录
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/out/lib)
#增加当前文件夹下的src文件夹为子文件夹，进入该文件夹执行其目录下CMakeLists.txt文件
add_subdirectory(${PROJECT_SOURCE_DIR}/src)
