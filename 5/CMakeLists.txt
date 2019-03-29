set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic")
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable(5.out main.c)
add_custom_target(run5
    COMMAND 5.out
    DEPENDS 5.out
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
