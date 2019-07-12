set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic")
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable(34.out main.c)
add_custom_target(run34
    COMMAND 34.out
    DEPENDS 34.out
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
