set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic -lgmp")
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable(21.out main.c)
add_custom_target(run21
    COMMAND 21.out
    DEPENDS 21.out
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
