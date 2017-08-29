cmake_minimum_required(VERSION 3.6)

project(YUVLibrary)

set(CMAKE_CXX_STANDARD 11)

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	set(FLAGS_AVX2 "/arch:AVX2")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	set(FLAGS_AVX2 "-mavx2")
	set(MT_LIB "pthread")
endif()

add_subdirectory(YUVLib)
add_subdirectory(Converter)
add_subdirectory(Player)

enable_testing()

add_subdirectory(Tests)
