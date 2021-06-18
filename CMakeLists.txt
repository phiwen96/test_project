cmake_minimum_required (VERSION 3.19.4)

project (
	test_project
	VERSION 1.0
	DESCRIPTION "create a login system"
	LANGUAGES CXX
)	
set (CMAKE_CXX_STANDARD 20)

add_subdirectory (src)