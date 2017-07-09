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
add_subdirectory(Tests)
add_subdirectory(Player)

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
															 
