cmake_minimum_required(VERSION 2.6)

project (ZZG_UTIL)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -ggdb -Wall -O0 -Wno-unused-variable -pthread")

link_directories(
    ${PROJECT_SOURCE_DIR}/lib
	/usr/lib64/mysql/
    /usr/local/lib/
)



set(base_src
)

set(src
../main.cpp
)


add_executable(MyUtil ${src} ${base_src})
target_link_libraries(MyUtil ${Boost_LIBRARIES})

