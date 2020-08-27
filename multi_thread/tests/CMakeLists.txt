cmake_minimum_required(VERSION 2.6)
#--------------------------------------------------------------------------
#path set

set(SRC_PATH ${CMAKE_CURRENT_SOURCE_DIR})

aux_source_directory(${SRC_PATH} SRC_FILE)
aux_source_directory(${SRC_PATH}/ut UT_SRC)

set(TEST_SRC 
	${SRC_FILE}
	${UT_SRC}
	CACHE INTERNAL " ")
