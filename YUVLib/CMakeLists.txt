project(YUVLib)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mavx2")
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

find_package(FreeImage REQUIRED)

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
        "${YUV_LIB_INCLUDE_DIR}/Converters"
        "${YUV_LIB_INCLUDE_DIR}/Frames"
        "${FreeImage_INCLUDE_DIR}"
)

add_library(YUVLib STATIC ${YUV_LIB_SOURCES} ${YUV_LIB_INCLUDES})

target_link_libraries(YUVLib ${FreeImage_LIBRARY})
