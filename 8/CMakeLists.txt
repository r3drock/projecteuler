set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic")
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable(8.out main.c)
add_custom_target(run8
    COMMAND 8.out
    DEPENDS 8.out
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
