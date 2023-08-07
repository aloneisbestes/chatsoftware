cmake_minimum_required(VERSION 3.0)

# 指定lib库输出路径
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

SET(MMFACTORY_PATH ${PROJECT_SOURCE_DIR}/src/MMFactory)
SET(MMHANDLER_PATH ${PROJECT_SOURCE_DIR}/src/MMHandler)
SET(MMBASE_PATH ${PROJECT_SOURCE_DIR}/src/MMBase)

# PROJECT_SOURCE_DIR: 当前项目的根目录
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/src/MMBase)
include_directories(${PROJECT_SOURCE_DIR}/src/MMNetwork)
include_directories(${PROJECT_SOURCE_DIR}/src/MMFactory)
include_directories(${PROJECT_SOURCE_DIR}/src/MMHandler)
include_directories(${PROJECT_SOURCE_DIR}/src/MMBase)
set(SRC_LIST ${MMFACTORY_PATH}/MMHandlerFactory.cpp ${MMHANDLER_PATH}/MMLoginHandler.cpp ${MMBASE_PATH}/MMBaseHandler.cpp)

# 创建库文件
add_library(MMFactory SHARED ${SRC_LIST})