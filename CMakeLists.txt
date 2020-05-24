cmake_minimum_required(VERSION 3.17.2)
project(cpp_demo)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.c??")

add_executable(main ${SOURCES} main.cpp)


if (test)

    enable_testing()

    set(GTEST_ROOT "third-party/gtest")
    find_package(GTest REQUIRED)
    
    add_executable(hello_test ${SOURCES} test/hello_test.cpp)
    target_link_libraries(hello_test GTest::GTest GTest::Main)
    add_test(AllTests hello_test)

    add_executable(hello2_test ${SOURCES} test/hello2_test.cpp)
    target_link_libraries(hello2_test GTest::GTest GTest::Main)
    add_test(AllTests hello2_test)

endif()