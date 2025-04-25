cmake_minimum_required(VERSION 3.16)

project(Switcheroo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(switcheroo STATIC)

target_include_directories(switcheroo
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_sources(switcheroo
    PRIVATE
        src/aarch64/decoder.cpp
        src/aarch64/recompiler.cpp
)

set_target_properties(switcheroo PROPERTIES POSITION_INDEPENDENT_CODE ON)

include(GNUInstallDirs)
install(TARGETS switcheroo
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})