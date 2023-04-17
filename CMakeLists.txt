cmake_minimum_required(VERSION 2.8)

project(liusong_pro)
include_directories("/usr/include/eigen3")
# include_directories("/usr/include/boost")
set(CMAKE_BUILD_TYPE "Debug")

# ADD_PROJECT_DEPENDENCY(Eigen3 REQUIRED PKG_CONFIG_REQUIRES "eigen3 >= 3.0.5")

#aux_source_directory（目录  存放文件列表的变量） 搜索./ls_pro1目录下的所有.cpp文件
# aux_source_directory(./ls_pro1 CPP_LIST1)
# add_executable(
#     out_file1 
#     ${CPP_LIST1}
# )
add_definitions( -std=c++14)

INCLUDE_DIRECTORIES("/usr/local/include")
# LINK_LIBRARIES("/usr/local/lib/libqpOASES.a")
# add_executable(test_ik test_ik.cpp)
add_executable(text1 text1.cpp)
# add_executable(text2 text2.cpp)
# add_executable(text3 text3.cpp)
#add_executable(this_test this_test.cpp)
#add_executable(friend_function friend_function.cpp)
#add_executable(friend_function2 friend_function2.cpp)
#add_executable(inherit1 inherit1.cpp)
#add_executable(inherit2 inherit2.cpp)
#add_executable(inherit3 inherit3.cpp)
#add_executable(inherit4 inherit4.cpp)
#add_executable(inherit5 inherit5.cpp)
# add_executable(inherit6 inherit6.cpp)
add_executable(Class_Object_as_func_para Class_Object_as_func_para.cpp)
#add_executable(inherit_test inherit_test.cpp)
#add_executable(duotai1 duotai1.cpp)
#add_executable(pointer1 pointer1.cpp)
#add_executable(pointer2 pointer2.cpp)
#add_executable(pointer3 pointer3.cpp)
# add_executable(pointer4 pointer4.cpp)
#add_executable(Vector1 Vector1.cpp)
#add_executable(Vector2 Vector2.cpp)
# add_executable(priority_queue priority_queue.cpp)

#---------------------------------------------------------------------
# SET(PINOCCHIO_MODEL_DIR "${PROJECT_SOURCE_DIR}/models")
# ADD_DEFINITIONS(-DPINOCCHIO_MODEL_DIR="${PINOCCHIO_MODEL_DIR}")
# SET(PINOCCHIO_MODEL_DIR "~/home/lius/Example/models")

# INCLUDE_DIRECTORIES("/opt/openrobots/include")
# LINK_LIBRARIES("/opt/openrobots/lib/libpinocchio.so")

# add_executable(pino1 pino1.cpp)
# add_executable(pino_IK pino_IK.cpp)
# add_executable(test_boost test_boost.cpp)
#-------------------------------------------------------------------

# INCLUDE_DIRECTORIES: 添加头文件(.h)路径;
# LINK_DIRECTORIES: 添加需要链接的库文件目录;
# LINK_LIBRARIES: 添加需要链接的库文件路径;
# link_libraries用在add_executable之前，target_link_libraries用在add_executable之后
# link_libraries用来链接静态库，target_link_libraries用来链接导入库，即按照header file + .lib + .dll方式隐式调用动态库的.lib库
# set(PINO_LIB "${/opt/openrobots/lib}" )




