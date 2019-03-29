set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic")
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable(6.out main.c)
add_custom_target(run6
    COMMAND 6.out
    DEPENDS 6.out
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
