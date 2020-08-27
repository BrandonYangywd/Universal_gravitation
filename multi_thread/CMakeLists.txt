cmake_minimum_required(VERSION 2.6)

project(MULTI_THREAD C CXX)

#enable_testing()

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE "Debug")
endif()

set(CXX_FLAGS
 -g
 # -DVALGRIND
 -DCHECK_PTHREAD_RETURN_VALUE
 -D_FILE_OFFSET_BITS=64
 -Wall
 -Wextra
 -Werror
 -Wconversion
 -Wno-unused-parameter
 -Wold-style-cast
 -Woverloaded-virtual
 -Wpointer-arith
 -Wshadow
 -Wwrite-strings
 -march=native
 # -MMD
 -std=c++11
 -pthread
 -rdynamic
 )
string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

add_subdirectory(${PROJECT_SOURCE_DIR}/3rdparty/)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/)
add_subdirectory(${PROJECT_SOURCE_DIR}/tests/)

include_directories(${3RDPARTY_INC}
	${SRC_INC}
	)

string(TOUPPER ${CMAKE_BUILD_TYPE} BUILD_TYPE)
message(STATUS "CXX_FLAGS = " ${CMAKE_CXX_FLAGS} " " ${CMAKE_CXX_FLAGS_${BUILD_TYPE}})

message(STATUS "SRC FILE: " 
	${SRC}
	${TEST_SRC}
	${3RDPARTY_SRC}
	)

add_executable(multi_exe 
	${SRC}
	${TEST_SRC}
	${3RDPARTY_SRC}
	)

target_link_libraries(multi_exe ${LIBGTEST})
