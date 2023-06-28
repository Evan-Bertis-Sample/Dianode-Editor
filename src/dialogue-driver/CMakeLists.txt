cmake_minimum_required(VERSION 3.15)

project(Dialogue-Driver)

set(NAME "dialogue-driver")
set(DRIVER_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Dialogue-Driver/src)
set(DRIVER_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Dialogue-Driver/include)

file(GLOB DRIVER_SRC ${DRIVER_SRC_DIR}/*.cpp)
file(GLOB DRIVER_INCLUDE ${DRIVER_INCLUDE_DIR})

add_library(${NAME} STATIC)
target_sources(${NAME} PRIVATE ${DRIVER_SRC})
target_include_directories(${NAME} PUBLIC ${DRIVER_INCLUDE})