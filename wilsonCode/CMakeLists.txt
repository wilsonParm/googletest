#cmake最低版本需求，不加入此行会受到警告信息
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

PROJECT(main) #项目名称

#把当前目录(.)下所有源代码文件和头文件加入变量SRC_LIST
AUX_SOURCE_DIRECTORY(. SRC_LIST)

INCLUDE_DIRECTORIES(include )

#gtest.a库路径加入
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib)

AUX_SOURCE_DIRECTORY(. DIR_SRCS)

#生成应用程序 main
ADD_EXECUTABLE(main ${SRC_LIST})

