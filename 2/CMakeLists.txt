set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic")
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable(2.out main.c)
add_custom_target(run2
    COMMAND 2.out
    DEPENDS 2.out
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
