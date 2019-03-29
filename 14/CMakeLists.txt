set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic")
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable(14.out main.c)
add_custom_target(run14
    COMMAND 14.out
    DEPENDS 14.out
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
