set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic")
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable(38.out main.c)
add_custom_target(run38
	COMMAND 38.out 
	DEPENDS 38.out
	WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
