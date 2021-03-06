
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.11)
PROJECT (UnitTest)
ADD_DEFINITIONS(-std=c++14)
ADD_DEFINITIONS("-Wall")
#ADD_DEFINITIONS("-Wno-missing-braces")


find_package(PkgConfig)
pkg_check_modules(LOG4CXX REQUIRED liblog4cxx)
include_directories(${LOG4CXX_INCLUDE_DIRS})
link_directories(${LOG4CXX_LIBRARY_DIRS})
FIND_PACKAGE ( Threads REQUIRED )
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SEPARATE_BUILD OFF)
 
if (SEPARATE_BUILD STREQUAL "ON")
include_directories("${CMAKE_SOURCE_DIR}/../lckernel")
else()
include_directories("${CMAKE_SOURCE_DIR}/lckernel")
endif()

set(src
main.cpp
entitytest.cpp
code.cpp
)
set(hdrs
entitytest.h
code.h
testmath.h
)

add_executable(lcunittest ${src} ${hdrs} testintersect.h)
target_link_libraries(lcunittest lckernel gtest ${CMAKE_THREAD_LIBS_INIT} ${LOG4CXX_LIBRARIES})
