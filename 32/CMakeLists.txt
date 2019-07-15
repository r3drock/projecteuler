set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic")
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable(32.out main.c)
add_custom_target(run32
    COMMAND ./32.sh 
    DEPENDS 32.out
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
