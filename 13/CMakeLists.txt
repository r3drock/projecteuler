cmake_minimum_required (VERSION 2.6)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic")
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

project (main)
add_executable(main.out main.c)
add_custom_target(run
    COMMAND cat numbers | ./main.out
    DEPENDS main.out
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
