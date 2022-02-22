cmake_minimum_required(VERSION 3.10)
project(DxfRW) 

#需要根据自己路径决定的模块
#occ
#osg
#xlsx
#opencv

# cmake模块的目录
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/;${CMAKE_MODULE_PATH}") 

# C++14
set(CMAKE_CXX_STANDARD 14)
# 禁止MSVC的wd4996警告
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4996")  

option (WNT "Use WNT" ON)
add_definitions("-DWNT")

# QT
# Find includes in corresponding build directories
#打开全局moc
set(CMAKE_AUTOMOC ON)
#打开全局uic
set(CMAKE_AUTOUIC ON)
#打开全局rcc，本示例中没有使用qrc，此句可以去掉
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Gui Widgets Sql Multimedia MultimediaWidgets UiTools Designer OpenGL CONFIG  REQUIRED)


file(GLOB HEADERS *.h *.hpp *.cpp *.ui)
add_executable(${PROJECT_NAME}  ${HEADERS})

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Sql Qt5::Multimedia Qt5::MultimediaWidgets Qt5::UiTools Qt5::Designer Qt5::OpenGL)


