#include "hello2.hpp"

#include <gtest/gtest.h>

TEST(Hello2Test, case1) {
    auto a = std::make_shared<Hello2>();
    EXPECT_EQ(a->h2(), "hello");
}

TEST(Hello2Test, case2) {
    auto a = std::make_shared<Hello2>();
    EXPECT_EQ(a->h2(), "world");
}

TEST(Hello2Test, case3) {
    auto a = std::make_shared<Hello2>();
    EXPECT_EQ(a->h2(), "world");
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}