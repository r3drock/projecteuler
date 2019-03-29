set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic")
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable(15.out main.c)
add_custom_target(run15
    COMMAND 15.out
    DEPENDS 15.out
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
