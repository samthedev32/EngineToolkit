cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# Source Files
set(SOURCES
    # Debug
    src/debug/log.cpp

    # Math
    src/math/quat.cpp

    # Mesh
    # src/mesh/mesh.cpp

    # Media

    ## Image
    src/media/image/common.cpp
    src/media/image/transform.cpp
    
    src/media/image/load_bmp.cpp
    src/media/image/load_png.cpp

    # UI
    src/UI/Layout.cpp
    src/UI/Element.cpp
    src/UI/LayoutPrototype.cpp

    # ECS
    src/ecs/ecs.cpp

    # Window
    src/window/x11.cpp
)

# Libraries
set(LIBRARIES m z X11)

# Project (Library)
project(EngineToolkit VERSION 0.1.0 LANGUAGES C CXX)

add_library(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Examples
add_subdirectory(examples)
