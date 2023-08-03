# 导入头文件目录
# include_directories(${PROJECT_SOURCE_DIR}/include)

# 设置可执行文件输出路径
# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
 
# 指定头文件路径，PROJECT_SOURCE_DIR: 当前项目的根目录
include_directories(
    ${PROJECT_SOURCE_DIR}/../MMCommon/include
    ${PROJECT_SOURCE_DIR}/../MMCommon/src
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src/MMNetwork
    ${PROJECT_SOURCE_DIR}/src/MMBase
    )

# 调用子目录下的CMakeLists.txt
add_subdirectory(MMNetwork)
add_subdirectory(MMFactory)

# 生成可执行文件
# add_executable(mgraccount ${ALL_SRC} test.cpp)
# add_executable(httpserver ${ALL_SRC} main.cpp)
add_executable(MMChat main.cpp MMCommon.cpp MMError.cpp)

# 添加外部链接库
link_directories(${PROJECT_SOURCE_DIR}/lib)
target_link_libraries(MMChat MMNetwork MMFactory)