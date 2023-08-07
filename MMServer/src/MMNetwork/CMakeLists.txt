cmake_minimum_required(VERSION 3.0)

# 指定lib库输出路径
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

SET(MMNETWORK_PATH ${PROJECT_SOURCE_DIR}/src/MMNetwork)
SET(MMBASE_PATH ${PROJECT_SOURCE_DIR}/src/MMBase)
SET(MMDATAFACTORY_PATH ${PROJECT_SOURCE_DIR}/../MMCommon/src)

# PROJECT_SOURCE_DIR: 当前项目的根目录
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/src/MMBase)
include_directories(${PROJECT_SOURCE_DIR}/src/MMNetwork)
include_directories(${PROJECT_SOURCE_DIR}/src/MMFactory)
set(SRC_LIST ${MMNETWORK_PATH}/MMNetworkServer.cpp ${MMBASE_PATH}/MMBaseNetwork.cpp ${MMNETWORK_PATH}/MMNetworkClient.cpp
    ${MMDATAFACTORY_PATH}/mmdatafacotry.cpp ${MMDATAFACTORY_PATH}/MMOtherData.cpp ${MMDATAFACTORY_PATH}/mmlogindata.cpp
    ${MMDATAFACTORY_PATH}/MMBaseDataJson.cpp)

# 创建库文件
add_library(MMNetwork SHARED ${SRC_LIST})