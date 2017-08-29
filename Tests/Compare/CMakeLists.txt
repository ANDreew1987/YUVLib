project (Compare)

set(TEST_COMPARE_SOURCE_DIR ${CMAKE_SOURCE_DIR}/Tests/Compare)

set(TEST_COMPARE_SOURCES "${TEST_COMPARE_SOURCE_DIR}/Compare.cpp")

include_directories(
        "${CMAKE_SOURCE_DIR}/YUVLib/include"
)

add_executable(Compare ${TEST_COMPARE_SOURCES})
target_link_libraries(Compare YUVLib)

set(TEST_COMPARE_FORMAT
        yuv420
)

set(TEST_COMPARE_COLOR_SPACE
        bt601
        bt709
)

set(TEST_COMPARE_THREADING
        st
        mt
)

set(TEST_COMPARE_IMAGE_SIZE
        64
        128
        256
        512
)

foreach(FORMAT ${TEST_COMPARE_FORMAT})
    foreach(COLOR_SPACE ${TEST_COMPARE_COLOR_SPACE})
        foreach(THREADING ${TEST_COMPARE_THREADING})
            foreach(IMAGE_SIZE ${TEST_COMPARE_IMAGE_SIZE})
                add_test(NAME Compare_${FORMAT}_${COLOR_SPACE}_${THREADING}_${IMAGE_SIZE}_${IMAGE_SIZE}
                         COMMAND Compare ${FORMAT} ${COLOR_SPACE} ${THREADING} ${IMAGE_SIZE} ${IMAGE_SIZE}
                )
            endforeach()
        endforeach()
    endforeach()
endforeach()
