project (Convert)

set(TEST_CONVERT_SOURCE_DIR ${CMAKE_SOURCE_DIR}/Tests/Convert)

set(TEST_CONVERT_SOURCES "${TEST_CONVERT_SOURCE_DIR}/Convert.cpp")

include_directories(
        "${CMAKE_SOURCE_DIR}/YUVLib/include"
)

add_executable(Convert ${TEST_CONVERT_SOURCES})
target_link_libraries(Convert YUVLib)

enable_testing()

add_test(NAME Convert_yuv420_bt601_std_st_count_10_size_64_64       COMMAND Convert "yuv420" "bt601" "std" "st" "10"    "64"    "64")
add_test(NAME Convert_yuv420_bt601_std_mt_count_10_size_64_64       COMMAND Convert "yuv420" "bt601" "std" "mt" "10"    "64"    "64")
add_test(NAME Convert_yuv420_bt601_avx_st_count_10_size_64_64       COMMAND Convert "yuv420" "bt601" "avx" "st" "10"    "64"    "64")
add_test(NAME Convert_yuv420_bt601_avx_mt_count_10_size_64_64       COMMAND Convert "yuv420" "bt601" "avx" "mt" "10"    "64"    "64")

add_test(NAME Convert_yuv420_bt601_std_st_count_10_size_128_128     COMMAND Convert "yuv420" "bt601" "std" "st" "10"   "128"   "128")
add_test(NAME Convert_yuv420_bt601_std_mt_count_10_size_128_128     COMMAND Convert "yuv420" "bt601" "std" "mt" "10"   "128"   "128")
add_test(NAME Convert_yuv420_bt601_avx_st_count_10_size_128_128     COMMAND Convert "yuv420" "bt601" "avx" "st" "10"   "128"   "128")
add_test(NAME Convert_yuv420_bt601_avx_mt_count_10_size_128_128     COMMAND Convert "yuv420" "bt601" "avx" "mt" "10"   "128"   "128")

add_test(NAME Convert_yuv420_bt601_std_st_count_10_size_256_256     COMMAND Convert "yuv420" "bt601" "std" "st" "10"   "256"   "256")
add_test(NAME Convert_yuv420_bt601_std_mt_count_10_size_256_256     COMMAND Convert "yuv420" "bt601" "std" "mt" "10"   "256"   "256")
add_test(NAME Convert_yuv420_bt601_avx_st_count_10_size_256_256     COMMAND Convert "yuv420" "bt601" "avx" "st" "10"   "256"   "256")
add_test(NAME Convert_yuv420_bt601_avx_mt_count_10_size_256_256     COMMAND Convert "yuv420" "bt601" "avx" "mt" "10"   "256"   "256")

add_test(NAME Convert_yuv420_bt601_std_st_count_10_size_512_512     COMMAND Convert "yuv420" "bt601" "std" "st" "10"   "512"   "512")
add_test(NAME Convert_yuv420_bt601_std_mt_count_10_size_512_512     COMMAND Convert "yuv420" "bt601" "std" "mt" "10"   "512"   "512")
add_test(NAME Convert_yuv420_bt601_avx_st_count_10_size_512_512     COMMAND Convert "yuv420" "bt601" "avx" "st" "10"   "512"   "512")
add_test(NAME Convert_yuv420_bt601_avx_mt_count_10_size_512_512     COMMAND Convert "yuv420" "bt601" "avx" "mt" "10"   "512"   "512")

add_test(NAME Convert_yuv420_bt601_std_st_count_10_size_1024_1024   COMMAND Convert "yuv420" "bt601" "std" "st" "10"  "1024"  "1024")
add_test(NAME Convert_yuv420_bt601_std_mt_count_10_size_1024_1024   COMMAND Convert "yuv420" "bt601" "std" "mt" "10"  "1024"  "1024")
add_test(NAME Convert_yuv420_bt601_avx_st_count_10_size_1024_1024   COMMAND Convert "yuv420" "bt601" "avx" "st" "10"  "1024"  "1024")
add_test(NAME Convert_yuv420_bt601_avx_mt_count_10_size_1024_1024   COMMAND Convert "yuv420" "bt601" "avx" "mt" "10"  "1024"  "1024")

add_test(NAME Convert_yuv420_bt601_std_st_count_10_size_2048_2048   COMMAND Convert "yuv420" "bt601" "std" "st" "10"  "2048"  "2048")
add_test(NAME Convert_yuv420_bt601_std_mt_count_10_size_2048_2048   COMMAND Convert "yuv420" "bt601" "std" "mt" "10"  "2048"  "2048")
add_test(NAME Convert_yuv420_bt601_avx_st_count_10_size_2048_2048   COMMAND Convert "yuv420" "bt601" "avx" "st" "10"  "2048"  "2048")
add_test(NAME Convert_yuv420_bt601_avx_mt_count_10_size_2048_2048   COMMAND Convert "yuv420" "bt601" "avx" "mt" "10"  "2048"  "2048")

add_test(NAME Convert_yuv420_bt601_std_st_count_10_size_4096_4096   COMMAND Convert "yuv420" "bt601" "std" "st" "10"  "4096"  "4096")
add_test(NAME Convert_yuv420_bt601_std_mt_count_10_size_4096_4096   COMMAND Convert "yuv420" "bt601" "std" "mt" "10"  "4096"  "4096")
add_test(NAME Convert_yuv420_bt601_avx_st_count_10_size_4096_4096   COMMAND Convert "yuv420" "bt601" "avx" "st" "10"  "4096"  "4096")
add_test(NAME Convert_yuv420_bt601_avx_mt_count_10_size_4096_4096   COMMAND Convert "yuv420" "bt601" "avx" "mt" "10"  "4096"  "4096")

add_test(NAME Convert_yuv420_bt601_std_st_count_10_size_8192_8192   COMMAND Convert "yuv420" "bt601" "std" "st" "10"  "8192"  "8192")
add_test(NAME Convert_yuv420_bt601_std_mt_count_10_size_8192_8192   COMMAND Convert "yuv420" "bt601" "std" "mt" "10"  "8192"  "8192")
add_test(NAME Convert_yuv420_bt601_avx_st_count_10_size_8192_8192   COMMAND Convert "yuv420" "bt601" "avx" "st" "10"  "8192"  "8192")
add_test(NAME Convert_yuv420_bt601_avx_mt_count_10_size_8192_8192   COMMAND Convert "yuv420" "bt601" "avx" "mt" "10"  "8192"  "8192")

