set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic -lgmp")
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable(20.out main.c)
target_link_libraries(20.out gmp)
add_custom_target(run20
    COMMAND 20.out
    DEPENDS 20.out
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
