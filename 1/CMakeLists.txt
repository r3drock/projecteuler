set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic")
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable(1.out main.c)
add_custom_target(run1
    COMMAND 1.out
    DEPENDS 1.out
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
