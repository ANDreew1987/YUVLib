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

IF (MSVC)
	SET(FreeImage_INCLUDE_SEARCH_DIRS "$ENV{FREEIMAGE_DIR}/include")
	IF (CMAKE_CL_64)
		SET(FreeImage_LIBRARY_SEARCH_DIRS "$ENV{FREEIMAGE_DIR}/lib/x64")
	ELSE ()
		SET(FreeImage_LIBRARY_SEARCH_DIRS "$ENV{FREEIMAGE_DIR}/lib/x86")
	ENDIF ()
	FIND_LIBRARY(FreeImage_LIBRARY FreeImage.lib PATHS ${FreeImage_LIBRARY_SEARCH_DIRS})
ELSE ()
	FIND_LIBRARY(FreeImage_LIBRARY freeimage PATHS ${FreeImage_LIBRARY_SEARCH_DIRS})
ENDIF()

FIND_PATH(FreeImage_INCLUDE_DIR FreeImage.h ${FreeImage_INCLUDE_SEARCH_DIRS})

IF (FreeImage_INCLUDE_DIR AND FreeImage_LIBRARY)
    SET(FreeImage_FOUND TRUE)
ENDIF ()

IF (NOT FreeImage_FOUND)
    MESSAGE(FATAL_ERROR "Could not find FreeImage")
ENDIF ()