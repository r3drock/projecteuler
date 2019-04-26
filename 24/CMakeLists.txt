set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic")
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable(24.out main.c)
add_custom_target(run24
    COMMAND 24.out
    DEPENDS 24.out
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
