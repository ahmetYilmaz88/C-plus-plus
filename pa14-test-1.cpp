//
//  pa14-test.cpp
//  2020-summer-cs202-pa14-array_class
//
//  Created by Kevin on 6/25/20.
//  Copyright © 2020 Kevin. All rights reserved.
//
// Note: These are the unit tests for the Array class. 

#include "Array.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// reference Arrays used in testing
static const int FIRSTHALF[] = {
    65, 66, 67, 68, 69, 70, 71, 72
};
static const int SECONDHALF[] = {
    73, 74, 75, 76, 77, 78, 79, 80
};
static const int REF[] = {
    65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80
};
static const size_t REFLEN = sizeof REF / sizeof *REF;

TEST_CASE("Default Constructor")
{
    Array ary1;

    REQUIRE(ary1.size() == 0);
    REQUIRE(ary1.begin() != nullptr);
    REQUIRE(ary1.begin() == ary1.end());

    Array ary2(5);

    REQUIRE(ary2.size() == 5);
    REQUIRE(ary2.begin() != nullptr);
    REQUIRE(ary2.begin() != ary2.end());

    for (auto item : ary2) {
        REQUIRE(item == int {});
    }
}

TEST_CASE("Copy Constructor")
{
    Array ary1(REFLEN);
    std::copy(REF, REF + REFLEN, ary1.begin());
    Array ary2(ary1);

    REQUIRE(ary1.begin() != ary2.begin());
    REQUIRE(ary1.size() == ary2.size());
    REQUIRE(std::equal(ary1.begin(), ary1.end(), ary2.begin(), ary2.end()));
}

TEST_CASE("Simple Array Constructor")
{
    Array ary1(REF, REFLEN);

    REQUIRE(ary1.begin() != REF);
    REQUIRE(ary1.size() == REFLEN);
    REQUIRE(std::equal(ary1.begin(), ary1.end(), REF, REF + REFLEN));
}

TEST_CASE("Array::at")
{
    Array ary1(REF, REFLEN);
    Array ary2(REFLEN);

    REQUIRE(ary1.size() == REFLEN);
    REQUIRE(ary2.size() == REFLEN);

    for (size_t i = 0; i < ary1.size(); ++i) {
        REQUIRE_NOTHROW(ary2.at(i) = ary1.at(i));
    }

    for (size_t i = 0; i < ary2.size(); ++i) {
        REQUIRE_NOTHROW(ary1.at(i) == ary2.at(i));
    }

    REQUIRE_THROWS(ary1.at(ary1.size()) = int {});
    REQUIRE_THROWS(ary1.at(ary1.size()) == int {});

    REQUIRE(std::equal(ary1.begin(), ary1.end(), ary2.begin(), ary2.end()));
}

TEST_CASE("Array::operator[]")
{
    Array ary1(REF, REFLEN);
    Array ary2(REFLEN);

    REQUIRE(ary1.size() == REFLEN);
    REQUIRE(ary2.size() == REFLEN);

    for (size_t i = 0; i < ary1.size(); ++i) {
        REQUIRE_NOTHROW(ary2[i] = ary1[i]);
    }

    for (size_t i = 0; i < ary2.size(); ++i) {
        REQUIRE_NOTHROW(ary1[i] == ary2[i]);
    }

    //~ REQUIRE_NOTHROW(ary1[ary1.size()] =  int {});
    //~ REQUIRE_NOTHROW(ary1[ary1.size()] == int {});
}

TEST_CASE("Array::front")
{
    Array ary1(REF, REFLEN);

    REQUIRE(ary1.front() == *REF);
}

TEST_CASE("Array::back")
{
    Array ary1(REF, REFLEN);

    REQUIRE(ary1.back() == *(REF + REFLEN - 1));
}

TEST_CASE("Array::begin")
{
    Array ary1;
    Array ary2(REF, REFLEN);

    REQUIRE(ary1.begin() != nullptr);
    REQUIRE(ary2.begin() != nullptr);
}

TEST_CASE("Array::end")
{
    Array ary1;
    Array ary2(REF, REFLEN);

    REQUIRE(ary1.end() == ary1.begin() + ary1.size());
    REQUIRE(ary2.end() == ary2.begin() + ary2.size());
}

TEST_CASE("Array::size")
{
    Array ary1;
    Array ary2(REF, REFLEN);

    REQUIRE(ary1.size() == 0);
    REQUIRE(ary2.size() == REFLEN);
}

TEST_CASE("Array::swap")
{
    Array ary1;
    Array ary2(REF, REFLEN);

    const auto ary1_begin = ary1.begin();
    const auto ary2_begin = ary2.begin();

    ary1.swap(ary2);

    REQUIRE(ary1.begin() == ary2_begin);
    REQUIRE(ary2.begin() == ary1_begin);
    REQUIRE(ary1.size()  == REFLEN);
    REQUIRE(ary2.size()  == 0);
}

TEST_CASE("Array::operator=")
{
    Array ary1(REFLEN);
    std::copy(REF, REF + REFLEN, ary1.begin());

    Array ary2;

    ary2 = ary1;

    REQUIRE(ary2.begin() != ary1.begin());
    REQUIRE(ary2.size() == ary1.size());
    REQUIRE(std::equal(ary2.begin(), ary2.end(), ary1.begin(), ary1.end()));
}

TEST_CASE("Array::operator+=")
{
    Array ary1(FIRSTHALF, REFLEN / 2);
    ary1 += Array(SECONDHALF, REFLEN / 2);

    REQUIRE(ary1.size() == REFLEN);
    REQUIRE(std::equal(ary1.begin(), ary1.end(), REF, REF + REFLEN));

    ary1 += int {};

    REQUIRE(ary1.size() == REFLEN + 1);
    REQUIRE(std::equal(ary1.begin(), ary1.end() - 1, REF, REF + REFLEN));
    REQUIRE(ary1.back() == int {});
}

TEST_CASE("operator+")
{
    auto ary1 = Array(FIRSTHALF, REFLEN / 2) + Array(SECONDHALF, REFLEN / 2);
    REQUIRE(std::equal(ary1.begin(), ary1.end(), REF, REF + REFLEN));

    ary1 = Array(REF, REFLEN) + int {};

    REQUIRE(std::equal(ary1.begin(), ary1.end() - 1, REF, REF + REFLEN));
    REQUIRE(ary1.back() == int {});
}

TEST_CASE("operator==")
{
    REQUIRE(Array() == Array());

    Array ary1(REF, REFLEN);
    Array ary2(REF, REFLEN);

    REQUIRE(ary1.begin() != ary2.begin());
    REQUIRE(ary1 == ary2);
    REQUIRE(std::equal(ary1.begin(), ary1.end(), REF, REF + REFLEN));
    REQUIRE(std::equal(ary2.begin(), ary2.end(), REF, REF + REFLEN));
    REQUIRE(std::equal(ary1.begin(), ary1.end(), ary2.begin(), ary2.end()));

    ary2[ary2.size() - 1] = int {};

    REQUIRE(ary1 != ary2);
    REQUIRE(!std::equal(ary1.begin(), ary1.end(), ary2.begin(), ary2.end()));
}

/* EOF */

