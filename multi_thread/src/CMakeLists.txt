cmake_minimum_required(VERSION 2.6)
#--------------------------------------------------------------------------
#path set

set(SRC_PATH ${CMAKE_CURRENT_SOURCE_DIR})

aux_source_directory( ${SRC_PATH} SRC_FILE)

set(SRC 
	${SRC_FILE}
	CACHE INTERNAL " ")

set(SRC_INC 
	${SRC_PATH}
	CACHE INTERNAL " ")
