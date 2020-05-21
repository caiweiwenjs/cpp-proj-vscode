#include "hello.hpp"

#include <gtest/gtest.h>

TEST(HelloTest, case1) {
    auto a = std::make_shared<Hello>();
    EXPECT_EQ(a->h1(1), 2);
}

TEST(HelloTest, case2) {
    auto a = std::make_shared<Hello>();
    EXPECT_EQ(a->h1(2), 3);
}

TEST(HelloTest, case3) {
    auto a = std::make_shared<Hello>();
    EXPECT_EQ(a->h1(2), 2);
}

TEST(HelloTest, case4) {
    auto a = std::make_shared<Hello>();
    EXPECT_EQ(a->h1(4), 5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}