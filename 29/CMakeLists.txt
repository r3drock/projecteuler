set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic")
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable(29.out main.c)
add_custom_target(run29
    COMMAND 29.out
    DEPENDS 29.out
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
