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
target_link_libraries(MyUtil )


add_executable(TestTimer ../test/testTimer.cpp ${base_src})
target_link_libraries(TestTimer )


add_executable(TestUniquePtr ../test/testUniquePtr.cpp ${base_src})
target_link_libraries(TestUniquePtr )


add_executable(TestSharedPtr ../test/testSharedPtr.cpp ${base_src})
target_link_libraries(TestSharedPtr )


add_executable(TestWeakPtr ../test/testWeakPtr.cpp ${base_src})
target_link_libraries(TestWeakPtr )
