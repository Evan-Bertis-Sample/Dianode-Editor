cmake_minimum_required(VERSION 3.22)

include(cmake/AppleBuild.cmake)

project(
  Dianode-Editor
  DESCRIPTION "A node based GUI for creating branching dialogue, powered by Dialogue-Driver."
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(cmake/StandardProjectSettings.cmake)

# Link this "library" to use the warnings specified in CompilerWarnings.cmake
add_library(project_warnings INTERFACE)
include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

add_subdirectory(vendor)
add_subdirectory(src)
