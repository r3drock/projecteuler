set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic")
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable(36.out main.c)
add_custom_target(run36
	COMMAND 36.out 
	DEPENDS 36.out
	WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
