set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic")
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable(13.out main.c)
add_custom_target(run13
    COMMAND cat numbers | ./13.out
    DEPENDS 13.out
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
