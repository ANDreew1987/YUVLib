SET(FreeImage_FOUND FALSE)

SET(FreeImage_INCLUDE_SEARCH_DIRS
        ${FreeImage_LIBRARY_SEARCH_DIRS}
        ${CMAKE_LIBRARY_PATH}
        /usr/include
        )

SET(FreeImage_LIBRARY_SEARCH_DIRS
        ${FreeImage_LIBRARY_SEARCH_DIRS}
        ${CMAKE_LIBRARY_PATH}
        /usr/lib
        /usr/local/lib
        )

FIND_PATH(FreeImage_INCLUDE_DIR FreeImage.h ${FreeImage_INCLUDE_SEARCH_DIRS})
FIND_LIBRARY(FreeImage_LIBRARY freeimage PATHS ${FreeImage_LIBRARY_SEARCH_DIRS})

IF (FreeImage_INCLUDE_DIR AND FreeImage_LIBRARY)
    SET(FreeImage_FOUND TRUE)
ENDIF ()

IF (NOT FreeImage_FOUND)
    MESSAGE(FATAL_ERROR "Could not find FreeImage")
ENDIF ()