// Copyright 2024 Harishwar Reddy

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE FibLFSR_Tests
#include <boost/test/unit_test.hpp>
#include "FibLFSR.hpp"

BOOST_AUTO_TEST_CASE(test_constructor) {
    PhotoMagic::FibLFSR flfsr("1011011000110110");
    BOOST_CHECK_EQUAL(flfsr.generate(5), 3);
}

BOOST_AUTO_TEST_CASE(test_step) {
    PhotoMagic::FibLFSR flfsr("1011011000110110");
    BOOST_CHECK_EQUAL(flfsr.step(), 0);
    BOOST_CHECK_EQUAL(flfsr.step(), 0);
    BOOST_CHECK_EQUAL(flfsr.step(), 0);
    BOOST_CHECK_EQUAL(flfsr.step(), 1);
}

BOOST_AUTO_TEST_CASE(test_generate) {
    PhotoMagic::FibLFSR flfsr("1011011000110110");
    BOOST_CHECK_EQUAL(flfsr.generate(5), 3);
    BOOST_CHECK_EQUAL(flfsr.generate(5), 6);
    BOOST_CHECK_EQUAL(flfsr.generate(5), 14);
}

BOOST_AUTO_TEST_CASE(test_stream_operator) {
    PhotoMagic::FibLFSR flfsr("1011011000110110");
    std::ostringstream oss;
    oss << flfsr;
    BOOST_CHECK_EQUAL(oss.str(), "1011011000110110");
}
