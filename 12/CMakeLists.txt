set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic -lm")
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable(12.out main.c)
add_custom_target(run12
    COMMAND 12.out
    DEPENDS 12.out
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
