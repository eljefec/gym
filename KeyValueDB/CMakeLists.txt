project(KeyValueDB)

cmake_minimum_required (VERSION 3.5)

add_definitions(-std=c++11)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

set(sources RunDB/RunDB.cpp StaticLib/DB.cpp StaticLib/DBRunner.cpp)

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

endif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

add_executable(KeyValueDB ${sources})

target_link_libraries(KeyValueDB z)
