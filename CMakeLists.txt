cmake_minimum_required(VERSION 3.0)

project(traj_gen)

set(HEAD_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(EXEC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(SRC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src)

find_package(PythonLibs 3 REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})


# 使用通配符匹配源文件
file(GLOB SOURCES "${SRC_PATH}/*.cc")



set(EXECUTABLE_OUTPUT_PATH ${EXEC_PATH})

include_directories(${HEAD_PATH})
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${PYTHON_LIBRARIES})