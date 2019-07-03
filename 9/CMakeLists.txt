set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic -lm")
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable(9.out main.c)
target_link_libraries(9.out m)
add_custom_target(run9
    COMMAND 9.out
    DEPENDS 9.out
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
