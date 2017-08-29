project (Convert)

set(TEST_CONVERT_SOURCE_DIR ${CMAKE_SOURCE_DIR}/Tests/Convert)

set(TEST_CONVERT_SOURCES "${TEST_CONVERT_SOURCE_DIR}/Convert.cpp")

include_directories(
        "${CMAKE_SOURCE_DIR}/YUVLib/include"
)

add_executable(Convert ${TEST_CONVERT_SOURCES})
target_link_libraries(Convert YUVLib)

#Performance tests

set(TEST_CONVERT_FORMAT
        yuv420
)

set(TEST_CONVERT_COLOR_SPACE
        bt601
        bt709
)

set(TEST_CONVERT_ALGORITHM
        std
        avx
)

set(TEST_CONVERT_THREADING
        st
        mt
)

set(TEST_CONVERT_COUNT
        10
)

set(TEST_CONVERT_IMAGE_SIZE
        64
        128
        256
        512
		1024
		2048
		4096
		8192
		16384
)

foreach(FORMAT ${TEST_CONVERT_FORMAT})
    foreach(COLOR_SPACE ${TEST_CONVERT_COLOR_SPACE})
		foreach(ALGORITHM ${TEST_CONVERT_ALGORITHM})
			foreach(THREADING ${TEST_CONVERT_THREADING})
				foreach(COUNT ${TEST_CONVERT_COUNT})
					foreach(IMAGE_SIZE ${TEST_CONVERT_IMAGE_SIZE})
						add_test(NAME Convert_${FORMAT}_${COLOR_SPACE}_${ALGORITHM}_${THREADING}_${COUNT}_${IMAGE_SIZE}_${IMAGE_SIZE}
								 COMMAND Convert ${FORMAT} ${COLOR_SPACE} ${ALGORITHM} ${THREADING} ${COUNT} ${IMAGE_SIZE} ${IMAGE_SIZE}
						)
					endforeach()
				endforeach()
            endforeach()
        endforeach()
    endforeach()
endforeach()

