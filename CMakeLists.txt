cmake_minimum_required(VERSION 3.27)
project(Switcheroo)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES "")

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

#add_executable(${PROJECT_NAME} test.cpp)

#target_link_libraries( hello_binary
#    PRIVATE 
#        hello_library
#)