set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic")
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable(10.out main.c)
add_custom_target(run10
    COMMAND 10.out
    DEPENDS 10.out
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
