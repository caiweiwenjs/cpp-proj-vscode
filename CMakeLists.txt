cmake_minimum_required(VERSION 3.17.2)
project(cpp_demo)

# cmake examples: https://github.com/ttroy50/cmake-examples

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "src/*.c??")

add_library(hello_library STATIC
    ${SOURCES}
)
target_include_directories(hello_library
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

add_executable(main main.cpp)
target_link_libraries(main 
    PRIVATE
        hello_library
)

if (test)
    enable_testing()

    set(GTEST_ROOT "third-party/gtest")
    find_package(GTest REQUIRED)
    
    add_executable(hello_test test/hello_test.cpp)
    target_link_libraries(hello_test 
        PRIVATE
            hello_library
            GTest::GTest 
            GTest::Main
    )
    add_test(all_tests hello_test)

    add_executable(hello2_test test/hello2_test.cpp)
    target_link_libraries(hello2_test 
        PRIVATE
            hello_library
            GTest::GTest 
            GTest::Main
    )
    add_test(all_tests hello2_test)

endif()