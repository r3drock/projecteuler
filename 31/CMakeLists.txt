set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic")
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable(31.out main.c)
add_custom_target(run31
    COMMAND 31.out
    DEPENDS 31.out
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
