cmake_minimum_required(VERSION 2.6)
#--------------------------------------------------------------------------
#path set

set(GTEST_PATH ${CMAKE_CURRENT_SOURCE_DIR}/gtest/include/)

#message(STATUS )
find_library(GTEST gtest ${CMAKE_CURRENT_SOURCE_DIR}/gtest/lib/)
if(GTEST)
    message(STATUS "found libgtest.a")
else()
	message(FATAL_ERROR "have not found libgtest.a")
endif()

set(LIBGTEST ${GTEST} CACHE INTERNAL " ")

set(3RDPARTY_SRC
	CACHE INTERNAL " ")
set(3RDPARTY_INC 
	${GTEST_PATH}
	CACHE INTERNAL " ")
