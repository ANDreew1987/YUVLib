project (Compare)

set(TEST_COMPARE_SOURCE_DIR ${CMAKE_SOURCE_DIR}/Tests/Compare)

set(TEST_COMPARE_SOURCES "${TEST_COMPARE_SOURCE_DIR}/Compare.cpp")

include_directories(
        "${CMAKE_SOURCE_DIR}/YUVLib/include"
)

add_executable(Compare ${TEST_COMPARE_SOURCES})
target_link_libraries(Compare YUVLib)

enable_testing()

add_test(NAME Compare_yuv420_bt601_st_size_64_64   COMMAND Compare "yuv420" "bt601" "st"  "64"  "64")
add_test(NAME Compare_yuv420_bt601_mt_size_64_64   COMMAND Compare "yuv420" "bt601" "mt"  "64"  "64")

add_test(NAME Compare_yuv420_bt601_st_size_128_128 COMMAND Compare "yuv420" "bt601" "st" "128" "128")
add_test(NAME Compare_yuv420_bt601_mt_size_128_128 COMMAND Compare "yuv420" "bt601" "mt" "128" "128")

add_test(NAME Compare_yuv420_bt601_st_size_256_256 COMMAND Compare "yuv420" "bt601" "st" "256" "256")
add_test(NAME Compare_yuv420_bt601_mt_size_256_256 COMMAND Compare "yuv420" "bt601" "mt" "256" "256")

add_test(NAME Compare_yuv420_bt709_st_size_64_64   COMMAND Compare "yuv420" "bt709" "st"  "64"  "64")
add_test(NAME Compare_yuv420_bt709_mt_size_64_64   COMMAND Compare "yuv420" "bt709" "mt"  "64"  "64")

add_test(NAME Compare_yuv420_bt709_st_size_128_128 COMMAND Compare "yuv420" "bt709" "st" "128" "128")
add_test(NAME Compare_yuv420_bt709_mt_size_128_128 COMMAND Compare "yuv420" "bt709" "mt" "128" "128")

add_test(NAME Compare_yuv420_bt709_st_size_256_256 COMMAND Compare "yuv420" "bt709" "st" "256" "256")
add_test(NAME Compare_yuv420_bt709_mt_size_256_256 COMMAND Compare "yuv420" "bt709" "mt" "256" "256")

