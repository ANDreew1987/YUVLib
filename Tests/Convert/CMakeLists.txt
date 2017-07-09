project (Convert)

set(TEST_CONVERT_SOURCE_DIR ${CMAKE_SOURCE_DIR}/Tests/Convert)

set(TEST_CONVERT_SOURCES "${TEST_CONVERT_SOURCE_DIR}/Convert.cpp")

include_directories(
        "${CMAKE_SOURCE_DIR}/YUVLib/include"
)

add_executable(Convert ${TEST_CONVERT_SOURCES})
target_link_libraries(Convert YUVLib)