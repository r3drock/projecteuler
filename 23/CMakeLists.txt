set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic")
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable(23.out main.c)
add_custom_target(run23
    COMMAND 23.out
    DEPENDS 23.out
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
