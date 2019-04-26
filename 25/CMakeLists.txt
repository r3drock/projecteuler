set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic -lgmp")
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable(25.out main.c)
add_custom_target(run25
    COMMAND 25.out
    DEPENDS 25.out
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
