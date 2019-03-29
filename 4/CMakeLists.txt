cmake_minimum_required (VERSION 2.6)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic")
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable(4.out main.c)
add_custom_target(run4
    COMMAND 4.out
    DEPENDS 4.out
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
