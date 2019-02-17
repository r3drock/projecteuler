cmake_minimum_required (VERSION 2.6)
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )
project (main)
add_executable(main.out main.c)
add_custom_target(run
    COMMAND main.out
    DEPENDS main.out
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)

