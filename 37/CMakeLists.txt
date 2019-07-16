set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic")
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable(37.out main.c)
add_custom_target(run37
	COMMAND 37.out 
	DEPENDS 37.out
	WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
