cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# Source Files
set(SOURCES
    # Debug
    src/debug/log.cpp

    # Math

    src/math/vector/vec1.cpp
    src/math/vector/vec2.cpp
    src/math/vector/vec3.cpp
    src/math/vector/vec4.cpp
    src/math/vector/vector.cpp

    # src/matrix/mat2.cpp
    src/math/matrix/mat3.cpp
    src/math/matrix/mat4.cpp
    src/math/matrix/matrix.cpp

    # Mesh
    # src/mesh/mesh.cpp

    # Media
    src/media/image.cpp
)

# Libraries
set(LIBRARIES
    m
    z
)

# Project (Library)
project(EngineToolkit VERSION 0.1.0 LANGUAGES C CXX)

add_library(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Examples
add_subdirectory(examples)
