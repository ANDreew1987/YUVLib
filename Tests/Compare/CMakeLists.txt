project (Compare)

set(TEST_COMPARE_SOURCE_DIR ${CMAKE_SOURCE_DIR}/Tests/Compare)

set(TEST_COMPARE_SOURCES "${TEST_COMPARE_SOURCE_DIR}/Compare.cpp")

include_directories(
        "${CMAKE_SOURCE_DIR}/YUVLib/include"
)

add_executable(Compare ${TEST_COMPARE_SOURCES})
target_link_libraries(Compare YUVLib)