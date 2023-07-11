//
// Created by skye on 2023/7/11.
//

#ifndef GTEST_GMOCK_MOCKUSER_H
#define GTEST_GMOCK_MOCKUSER_H
#include "User.h"
#include <gmock/gmock.h>

class MockUser: public User {
public:
    MOCK_METHOD(int, getAge, (), (override));
};

#endif //GTEST_GMOCK_MOCKUSER_H
