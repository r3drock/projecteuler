set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic")
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable(41.out main.c)
add_custom_target(run41
	COMMAND 41.out 
	DEPENDS 41.out
	WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
