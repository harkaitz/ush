cmake_minimum_required(VERSION 3.0)
project(uSh VERSION 0.2)

include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set (CPACK_PACKAGE_VERSION_MAJOR "${uSh_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${uSh_VERSION_MINOR}")
set (CPACK_GENERATOR             ZIP STGZ)
include (CPack)

# C/C++ flags.
if ( CMAKE_COMPILER_IS_GNUCC )
  set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -Wall -Werror -std=gnu99")
  if(${CMAKE_SYSTEM_NAME} STREQUAL Windows)
    set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -static")
  endif()
endif ( CMAKE_COMPILER_IS_GNUCC )
if ( MSVC )
  set(CMAKE_CXX_FLAGS  "${CMAKE_C_FLAGS} /W4")
endif ( MSVC )

# Library.
add_subdirectory(${CMAKE_SOURCE_DIR}/ush)

# Program.
add_executable(ushc ushc.c)
target_link_libraries(ushc ush)
target_compile_definitions(ushc PRIVATE -DDEBUG)
install(TARGETS ushc DESTINATION bin)

install(
  FILES ush_test.ush
  DESTINATION bin
  PERMISSIONS
  OWNER_READ    OWNER_WRITE OWNER_EXECUTE
  GROUP_READ    GROUP_WRITE GROUP_EXECUTE
  WORLD_EXECUTE             WORLD_READ)


