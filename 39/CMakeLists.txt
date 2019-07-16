set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic -lm")
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable(39.out main.c)
target_link_libraries(39.out m)
add_custom_target(run39
	COMMAND 39.out 
	DEPENDS 39.out
	WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
