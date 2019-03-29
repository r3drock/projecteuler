set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic -g -O -D FORTIFY_SOURCE=2")
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable(18.out main.c)
add_custom_target(run18
    COMMAND cat pyramid.txt | ./18.out
    DEPENDS 18.out
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
