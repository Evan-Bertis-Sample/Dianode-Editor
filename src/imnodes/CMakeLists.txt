cmake_minimum_required(VERSION 3.15)

project(imnodes)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(IMNODES_IMGUI_TARGET_NAME imgui)

if(MSVC)
    add_compile_definitions(SDL_MAIN_HANDLED)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

# Imnodes

add_library(imnodes)
target_sources(imnodes PRIVATE
    Imnodes/imnodes.h
    Imnodes/imnodes_internal.h
    Imnodes/imnodes.cpp)
target_include_directories(imnodes PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(imnodes PUBLIC ${IMNODES_IMGUI_TARGET_NAME})