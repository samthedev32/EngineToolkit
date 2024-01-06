configure_file(config.h.in config.h)
include_directories(${CMAKE_BINARY_DIR}/examples)

add_subdirectory(debug)
add_subdirectory(math)
add_subdirectory(media)
add_subdirectory(ui)
add_subdirectory(window)