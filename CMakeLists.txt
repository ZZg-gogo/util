cmake_minimum_required(VERSION 2.6)

project (ZZG_UTIL)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -ggdb -Wall -O0 -Wno-unused-variable -pthread")

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

##选择性编译测试程序
if(FALSE)
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


add_executable(TestEnableSharedFromThis ../test/testEnableSharedFromThis.cpp ${base_src})
target_link_libraries(TestEnableSharedFromThis )


add_executable(TestOptianal ../test/testOptianal.cpp ${base_src})
target_link_libraries(TestOptianal )

add_executable(TestAssign ../test/testAssign.cpp ${base_src})
target_link_libraries(TestAssign )

add_executable(TestLexicalCast ../test/testLexicalCast.cpp ${base_src})
target_link_libraries(TestLexicalCast )

add_executable(TestFormat ../test/testFormat.cpp ${base_src})
target_link_libraries(TestFormat )

endif()






######模板的
if(FALSE)
    add_executable(testCommonType ../testTemplate/testCommonType.cpp ${base_src})
    target_link_libraries(testCommonType )

    add_executable(testUsingTypename ../testTemplate/testUsingTypename.cpp ${base_src})
    target_link_libraries(testUsingTypename )

    add_executable(testVarTemplate ../testTemplate/testVarTemplate.cpp ${base_src})
    target_link_libraries(testVarTemplate )

    add_executable(testRawArray ../testTemplate/testRawArray.cpp ${base_src})
    target_link_libraries(testRawArray )

    add_executable(testMoveEnableIf ../testTemplate/testMoveEnableIf.cpp ${base_src})
    target_link_libraries(testMoveEnableIf )

    add_executable(testCompileTime ../testTemplate/testCompileTime.cpp ${base_src})
    target_link_libraries(testCompileTime )


    add_executable(testTemplateLib ../testTemplate/testTemplateLib.cpp ${base_src})
    target_link_libraries(testTemplateLib )
endif()

add_executable(testTraits ../testTemplate/testTraits.cpp ${base_src})
target_link_libraries(testTraits )





