set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic")
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable(33.out main.c)
add_custom_target(run33
    COMMAND 33.out 
    DEPENDS 33.out
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
