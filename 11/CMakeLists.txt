set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic")
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable(11.out main.c)
add_custom_target(run11
    COMMAND 11.out
    DEPENDS 11.out
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
