set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic -lgmp")
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable(16.out main.c)
add_custom_target(run16
    COMMAND 16.out
    DEPENDS 16.out
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
