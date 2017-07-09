project(YUVLib)

set(CMAKE_CXX_STANDARD 11)

set(YUV_LIB_SOURCE_DIR ${CMAKE_SOURCE_DIR}/YUVLib/source)
set(YUV_LIB_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/YUVLib/include)

file(GLOB YUV_LIB_SOURCES
        "${YUV_LIB_SOURCE_DIR}/*.cpp"
        "${YUV_LIB_SOURCE_DIR}/Converters/*.cpp"
        "${YUV_LIB_SOURCE_DIR}/Frames/*.cpp"
)

file(GLOB YUV_LIB_INCLUDES
        "${YUV_LIB_INCLUDE_DIR}/*.hpp"
        "${YUV_LIB_INCLUDE_DIR}/Converters/*.hpp"
        "${YUV_LIB_INCLUDE_DIR}/Frames/*.hpp"
)

include_directories(
        "${YUV_LIB_INCLUDE_DIR}"
)

set_source_files_properties(
		"${YUV_LIB_SOURCE_DIR}/Converters/YUVAVXConverter.cpp"
		PROPERTIES
		COMPILE_FLAGS ${FLAGS_AVX2}
)

add_library(YUVLib STATIC ${YUV_LIB_SOURCES} ${YUV_LIB_INCLUDES})

target_link_libraries(YUVLib ${MT_LIB})
