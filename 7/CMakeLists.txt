set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic")
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable(7.out main.c)
add_custom_target(run7
    COMMAND 7.out
    DEPENDS 7.out
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
