cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# Source Files
set(SOURCES
    src/Library.cpp
)

# Libraries
set(LIBRARIES
)

# Project (Library)
project(Library VERSION 0.1.0 LANGUAGES C CXX)

add_library(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Examples
add_subdirectory(hello_library)