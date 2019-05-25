set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic")
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable(27.out main.c)
add_custom_target(run27
    COMMAND 27.out
    DEPENDS 27.out
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
