set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic")
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable(35.out main.c)
add_custom_target(run35
    COMMAND 35.out 
    DEPENDS 35.out
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
