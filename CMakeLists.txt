cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

#! Указать свою папку qt_dir, где расположены bin, include, lib, plagins ...
set(qt_dir D:/Libs/Qt/5.15.2/mingw81_64)
set(Qt5_DIR ${qt_dir}/lib/cmake/Qt5/)

set(proj_version 1.0.0.0)
project(CopyApp VERSION ${proj_version} LANGUAGES CXX)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(${PROJECT_NAME} WIN32
        src/main.cpp
)
target_link_libraries(${PROJECT_NAME} PUBLIC 
            Qt5::Widgets  
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON
    CACHE INTERNAL
    "Export compile commands" FORCE
)

set(platform_dir platforms)
file(MAKE_DIRECTORY ${platform_dir})
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${qt_dir}/plugins/platforms/qwindows.dll
                ${platform_dir}/qwindows.dll)
