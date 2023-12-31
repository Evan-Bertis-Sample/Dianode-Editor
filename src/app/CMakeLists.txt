set(NAME "App")

include(${PROJECT_SOURCE_DIR}/cmake/StaticAnalyzers.cmake)

file(COPY App/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(${NAME} App/Main.cpp)

if (WIN32)
  # Copy DLL files on Windows to the target App build folder.
  add_custom_command(TARGET ${NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:SDL2::SDL2>
    $<TARGET_FILE_DIR:${NAME}>)
endif ()

target_include_directories(${NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(${NAME} PRIVATE cxx_std_20)
target_link_libraries(${NAME} PRIVATE project_warnings Core imnodes dialogue-driver)
