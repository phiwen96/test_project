

file (GLOB HEADER_LIST ../include/*.hpp)
file (GLOB SOURCE_LIST *.cpp)


add_executable (login_system ${SOURCE_LIST} ${HEADER_LIST})



target_include_directories (login_system PRIVATE ../include)


