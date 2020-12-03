//
//  pa14-test.cpp
//  2020-summer-cs202-pa14-array_class
//
//  Created by Kevin on 6/28/20.
//  Copyright © 2020 Kevin. All rights reserved.
//
// Note: These are the unit tests for the template Array class.

#include "Array.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEMPLATE_TEST_CASE("Default Constructor", "[Array][Template]", char, short, int, float, double)
{
    Array<TestType> ary1;

    REQUIRE(ary1.size() == 0);
    REQUIRE(ary1.begin() != nullptr);
    REQUIRE(ary1.begin() == ary1.end());

    Array<TestType> ary2(5);

    REQUIRE(ary2.size() == 5);
    REQUIRE(ary2.begin() != nullptr);
    REQUIRE(ary2.begin() != ary2.end());

    for (auto item : ary2) {
        REQUIRE(item == TestType {});
    }
}

TEMPLATE_TEST_CASE("Copy Constructor", "[Array][Template]", char, short, int, float, double)
{
    // reference Arrays used in testing
    const TestType REF[] { 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80 };
    constexpr size_t REFLEN {sizeof REF / sizeof *REF};

    Array<TestType> ary1(REFLEN);

    std::copy(REF, REF + REFLEN, ary1.begin());
    Array<TestType> ary2(ary1);

    REQUIRE(ary1.begin() != ary2.begin());
    REQUIRE(ary1.size() == ary2.size());
    REQUIRE(std::equal(ary1.begin(), ary1.end(), ary2.begin(), ary2.end()));
}

TEMPLATE_TEST_CASE("Simple Array Constructor", "[Array][Template]", char, short, int, float, double)
{
    // reference Arrays used in testing
    const TestType REF[] { 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80 };
    constexpr size_t REFLEN {sizeof REF / sizeof *REF};

    Array<TestType> ary1(REF, REFLEN);

    REQUIRE(ary1.begin() != REF);
    REQUIRE(ary1.size() == REFLEN);
    REQUIRE(std::equal(ary1.begin(), ary1.end(), REF, REF + REFLEN));
}

TEMPLATE_TEST_CASE("Array::at", "[Array][Template]", char, short, int, float, double)
{
    // reference Arrays used in testing
    const TestType REF[] { 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80 };
    constexpr size_t REFLEN {sizeof REF / sizeof *REF};

    Array<TestType> ary1(REF, REFLEN);
    Array<TestType> ary2(REFLEN);

    REQUIRE(ary1.size() == REFLEN);
    REQUIRE(ary2.size() == REFLEN);

    for (size_t i = 0; i < ary1.size(); ++i) {
        REQUIRE_NOTHROW(ary2.at(i) = ary1.at(i));
    }

    for (size_t i = 0; i < ary2.size(); ++i) {
        REQUIRE_NOTHROW(ary1.at(i) == ary2.at(i));
    }

    REQUIRE_THROWS(ary1.at(ary1.size()) = TestType {});
    REQUIRE_THROWS(ary1.at(ary1.size()) == TestType {});

    REQUIRE(std::equal(ary1.begin(), ary1.end(), ary2.begin(), ary2.end()));
}

TEMPLATE_TEST_CASE("Array::operator[]", "[Array][Template]", char, short, int, float, double)
{
    // reference Arrays used in testing
    const TestType REF[] { 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80 };
    constexpr size_t REFLEN {sizeof REF / sizeof *REF};

    Array<TestType> ary1(REF, REFLEN);
    Array<TestType> ary2(REFLEN);

    REQUIRE(ary1.size() == REFLEN);
    REQUIRE(ary2.size() == REFLEN);

    for (size_t i = 0; i < ary1.size(); ++i) {
        REQUIRE_NOTHROW(ary2[i] = ary1[i]);
    }

    for (size_t i = 0; i < ary2.size(); ++i) {
        REQUIRE_NOTHROW(ary1[i] == ary2[i]);
    }

    //~ REQUIRE_NOTHROW(ary1[ary1.size()] =  TestType {});
    //~ REQUIRE_NOTHROW(ary1[ary1.size()] == TestType {});
}

TEMPLATE_TEST_CASE("Array::front", "[Array][Template]", char, short, int, float, double)
{
    // reference Arrays used in testing
    const TestType REF[] { 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80 };
    constexpr size_t REFLEN {sizeof REF / sizeof *REF};

    Array<TestType> ary1(REF, REFLEN);

    REQUIRE(ary1.front() == *REF);
}

TEMPLATE_TEST_CASE("Array::back", "[Array][Template]", char, short, int, float, double)
{
    // reference Arrays used in testing
    const TestType REF[] { 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80 };
    constexpr size_t REFLEN {sizeof REF / sizeof *REF};

    Array<TestType> ary1(REF, REFLEN);

    REQUIRE(ary1.back() == *(REF + REFLEN - 1));
}

TEMPLATE_TEST_CASE("Array::begin", "[Array][Template]", char, short, int, float, double)
{
    // reference Arrays used in testing
    const TestType REF[] { 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80 };
    constexpr size_t REFLEN {sizeof REF / sizeof *REF};

    Array<TestType> ary1;
    Array<TestType> ary2(REF, REFLEN);

    REQUIRE(ary1.begin() != nullptr);
    REQUIRE(ary2.begin() != nullptr);
}

TEMPLATE_TEST_CASE("Array::end", "[Array][Template]", char, short, int, float, double)
{
    // reference Arrays used in testing
    const TestType REF[] { 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80 };
    constexpr size_t REFLEN {sizeof REF / sizeof *REF};

    Array<TestType> ary1;
    Array<TestType> ary2(REF, REFLEN);

    REQUIRE(ary1.end() == ary1.begin() + ary1.size());
    REQUIRE(ary2.end() == ary2.begin() + ary2.size());
}

TEMPLATE_TEST_CASE("Array::size", "[Array][Template]", char, short, int, float, double)
{
    // reference Arrays used in testing
    const TestType REF[] { 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80 };
    constexpr size_t REFLEN {sizeof REF / sizeof *REF};

    Array<TestType> ary1;
    Array<TestType> ary2(REF, REFLEN);

    REQUIRE(ary1.size() == 0);
    REQUIRE(ary2.size() == REFLEN);
}

TEMPLATE_TEST_CASE("Array::swap", "[Array][Template]", char, short, int, float, double)
{
    // reference Arrays used in testing
    const TestType REF[] { 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80 };
    constexpr size_t REFLEN {sizeof REF / sizeof *REF};

    Array<TestType> ary1;
    Array<TestType> ary2(REF, REFLEN);

    const auto ary1_begin = ary1.begin();
    const auto ary2_begin = ary2.begin();

    ary1.swap(ary2);

    REQUIRE(ary1.begin() == ary2_begin);
    REQUIRE(ary2.begin() == ary1_begin);
    REQUIRE(ary1.size()  == REFLEN);
    REQUIRE(ary2.size()  == 0);
}

TEMPLATE_TEST_CASE("Array::operator=", "[Array][Template]", char, short, int, float, double)
{
    // reference Arrays used in testing
    const TestType REF[] { 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80 };
    constexpr size_t REFLEN {sizeof REF / sizeof *REF};

    Array<TestType> ary1(REFLEN);
    std::copy(REF, REF + REFLEN, ary1.begin());

    Array<TestType> ary2;

    ary2 = ary1;

    REQUIRE(ary2.begin() != ary1.begin());
    REQUIRE(ary2.size() == ary1.size());
    REQUIRE(std::equal(ary2.begin(), ary2.end(), ary1.begin(), ary1.end()));
}

TEMPLATE_TEST_CASE("Array::operator+=", "[Array][Template]", char, short, int, float, double)
{
    // reference Arrays used in testing
    const TestType FIRSTHALF[] { 65, 66, 67, 68, 69, 70, 71, 72 };
    const TestType SECONDHALF[] { 73, 74, 75, 76, 77, 78, 79, 80 };
    const TestType REF[] { 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80 };
    constexpr size_t REFLEN {sizeof REF / sizeof *REF};

    Array<TestType> ary1(FIRSTHALF, REFLEN / 2);
    ary1 += Array<TestType>(SECONDHALF, REFLEN / 2);

    REQUIRE(ary1.size() == REFLEN);
    REQUIRE(std::equal(ary1.begin(), ary1.end(), REF, REF + REFLEN));

    ary1 += TestType {};

    REQUIRE(ary1.size() == REFLEN + 1);
    REQUIRE(std::equal(ary1.begin(), ary1.end() - 1, REF, REF + REFLEN));
    REQUIRE(ary1.back() == TestType {});
}

TEMPLATE_TEST_CASE("operator+", "[Array][Template]", char, short, int, float, double)
{
    // reference Arrays used in testing
    const TestType FIRSTHALF[] { 65, 66, 67, 68, 69, 70, 71, 72 };
    const TestType SECONDHALF[] { 73, 74, 75, 76, 77, 78, 79, 80 };
    const TestType REF[] { 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80 };
    constexpr size_t REFLEN {sizeof REF / sizeof *REF};

    auto ary1 = Array<TestType>(FIRSTHALF, REFLEN / 2) + Array<TestType>(SECONDHALF, REFLEN / 2);
    REQUIRE(std::equal(ary1.begin(), ary1.end(), REF, REF + REFLEN));

    ary1 = Array<TestType>(REF, REFLEN) + TestType {};

    REQUIRE(std::equal(ary1.begin(), ary1.end() - 1, REF, REF + REFLEN));
    REQUIRE(ary1.back() == TestType {});
}

TEMPLATE_TEST_CASE("operator==", "[Array][Template]", char, short, int, float, double)
{
    // reference Arrays used in testing
    const TestType REF[] { 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80 };
    constexpr size_t REFLEN {sizeof REF / sizeof *REF};

    REQUIRE(Array<TestType>() == Array<TestType>());

    Array<TestType> ary1(REF, REFLEN);
    Array<TestType> ary2(REF, REFLEN);

    REQUIRE(ary1.begin() != ary2.begin());
    REQUIRE(ary1 == ary2);
    REQUIRE(std::equal(ary1.begin(), ary1.end(), REF, REF + REFLEN));
    REQUIRE(std::equal(ary2.begin(), ary2.end(), REF, REF + REFLEN));
    REQUIRE(std::equal(ary1.begin(), ary1.end(), ary2.begin(), ary2.end()));

    ary2[ary2.size() - 1] = TestType {};

    REQUIRE(ary1 != ary2);
    REQUIRE(!std::equal(ary1.begin(), ary1.end(), ary2.begin(), ary2.end()));
}

/* EOF */

