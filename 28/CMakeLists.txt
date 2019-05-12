set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic")
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable(28.out main.c)
add_custom_target(run28
    COMMAND 28.out
    DEPENDS 28.out
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
