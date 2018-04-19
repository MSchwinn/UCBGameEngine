cmake_minimum_required(VERSION 3.10)
project(UCBGameEngine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")
set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_PREFIX_PATH Z:/LkbA/2018-SS/Spieleprogrammierung/Game Programming Env/ExternalLibs/SFML-2.4.2/lib)

set(SFML_ROOT "../../ExternalLibs/SFML-2.4.2/")

add_executable(UCBGameEngine main.cpp)

set(SFML_STATIC_LIBRARIES TRUE)

# Detect and add SFML
# set(SFML_DIR "Z:/LkbA/2018-SS/Spieleprogrammierung/Game Programming Env/ExternalLibs/SFML-2.4.2/cmake/Modules")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 COMPONENTS audio graphics window system REQUIRED)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(UCBGameEngine ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()