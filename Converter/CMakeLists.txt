project(Converter)

set(CONVERTER_SOURCE_DIR ${CMAKE_SOURCE_DIR}/Converter)
set(CONVERTER_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/Converter)

file(GLOB CONVERTER_SOURCES
        "${CONVERTER_SOURCE_DIR}/*.cpp"
)

file(GLOB CONVERTER_INCLUDES
        "${CONVERTER_INCLUDE_DIR}/*.hpp"
        "${CMAKE_SOURCE_DIR}/YUVLib/include/*.hpp"
)

include_directories(
        "${CONVERTER_INCLUDE_DIR}"
        "${CMAKE_SOURCE_DIR}/YUVLib/include"
)

add_executable(Converter ${CONVERTER_SOURCES} ${CONVERTER_INCLUDES})

target_link_libraries(Converter YUVLib)
