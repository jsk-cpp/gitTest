#include <iostream>
#include <gtest/gtest.h>

int add(int a, int b) {
    return a + b;
}

TEST(testCase1, add) {
    EXPECT_EQ(add(3,4), 7);
    EXPECT_EQ(add(2,3), 5);
//    EXPECT_EQ(add(1,2), 4); //错误
}

#include "MockUser.h"
#include <gmock/gmock.h>
TEST(testCase2, test) {
    MockUser user;
    EXPECT_CALL(user, getAge).
    WillOnce(::testing::Return(200)). //调用一次返回200
    WillOnce(::testing::Return(300)). //再调用一次返回300
    WillRepeatedly(::testing::Return(500)). //重复调用返回500
    Times(::testing::AtLeast(3)); //最少调用次数3次

    //getAge是纯虚函数，但也可以通过MockUser实例化的对象进行调用
    std::cout << user.getAge() << std::endl;
    std::cout << user.getAge() << std::endl;
    std::cout << user.getAge() << std::endl;
    std::cout << user.getAge() << std::endl;
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}