set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic -lm")
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable(3.out main.c)
add_custom_target(run3
    COMMAND 3.out
    DEPENDS 3.out
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
