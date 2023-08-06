cmake_minimum_required(VERSION 3.0)

# 指定lib库输出路径
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)


# PROJECT_SOURCE_DIR: 当前项目的根目录
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/src/MMBase)
include_directories(${PROJECT_SOURCE_DIR}/../MMCommon/include)

set(SRC_LIST MMLoginHandler.cpp)

# 创建库文件
add_library(MMHandler SHARED ${SRC_LIST})