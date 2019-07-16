set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic -g -O -D FORTIFY_SOURCE=2")
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable(67.out main.c)
add_custom_target(run67
    COMMAND cat pyramid.txt | ./67.out
    DEPENDS 67.out
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
