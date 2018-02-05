cmake_minimum_required(VERSION 3.8)
project(readParamProj C CXX)

set(CMAKE_CXX_STANDARD 11)

file(GLOB headers src/*.h)
file(GLOB sources src/*.cpp)


set(main_SRCS ${sources} ${headers})
add_executable(readParamProj ${main_SRCS})
 
find_package( Boost COMPONENTS serialization system REQUIRED )
target_include_directories(readParamProj PUBLIC ${Boost_INCLUDE_DIRS})
target_link_libraries(readParamProj ${Boost_LIBRARIES})