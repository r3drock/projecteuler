set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic")
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable(22.out main.c)
add_custom_target(run22
    COMMAND 22.out
    DEPENDS 22.out
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
