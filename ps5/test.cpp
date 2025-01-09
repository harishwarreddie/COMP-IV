//  CopyRight 2024 Harishwar Reddy Erri
#define BOOST_TEST_MODULE MyTest
#include <boost/test/included/unit_test.hpp>
#include "EDistance.hpp"

BOOST_AUTO_TEST_CASE(FIRST_TESTCASE) {
    std::string a = "a";
    std::string b = "a";
    EDistance ed(a, b);

    int result = ed.computePenalty('a', 'a');

    BOOST_REQUIRE_EQUAL(result, 0);
}

BOOST_AUTO_TEST_CASE(SECOND_TESTCASE) {
    BOOST_REQUIRE_THROW(EDistance("hello", ""), std::exception);
    BOOST_REQUIRE_THROW(EDistance("", ""), std::exception);
}

BOOST_AUTO_TEST_CASE(THIRD_TESTCASE) {
    int result1 = EDistance::findMin(4, 3, 2);
    BOOST_REQUIRE_EQUAL(result1, 2);

    int result2 = EDistance::findMin(5, 3, 5);
    BOOST_REQUIRE_EQUAL(result2, 3);

    int result3 = EDistance::findMin(7, 7, 7);
    BOOST_REQUIRE_EQUAL(result3, 7);
}

BOOST_AUTO_TEST_CASE(FOURTH_TESTCASE) {
    EDistance ed1("hello", "hello");
    BOOST_REQUIRE_EQUAL(ed1.calculateDistance(), 0);

    EDistance ed2("eatting", "setting");
    BOOST_REQUIRE_EQUAL(ed2.calculateDistance(), 2);
}
