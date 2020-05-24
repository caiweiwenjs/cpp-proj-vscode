#include "hello2.hpp"
#include "hello.hpp"

#include <iostream>
#include <memory>


int main() {
    auto a = std::make_shared<Hello>();
    std::cout << a->h1(1) << std::endl;
    auto b = std::make_shared<Hello2>();
    std::cout << b->h2() << std::endl;
    return 0;
}