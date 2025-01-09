// Copyright 2024 Harishwar Reddy

#include <iostream>
#include <sstream>
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE
#include <boost/test/unit_test.hpp>
#include "FibLFSR.hpp"
using PhotoMagic::FibLFSR;

// Test for step function
BOOST_AUTO_TEST_CASE(test_step) {
    FibLFSR lfsr("1011011000110110");
    BOOST_CHECK_EQUAL(lfsr.step(), 0);
    BOOST_CHECK_EQUAL(lfsr.step(), 0);
    BOOST_CHECK_EQUAL(lfsr.step(), 0);
    BOOST_CHECK_EQUAL(lfsr.step(), 1);
    BOOST_CHECK_EQUAL(lfsr.step(), 1);
}

// Test for the << operator output
BOOST_AUTO_TEST_CASE(test_operator_output) {
    FibLFSR lfsr("1011011000110110");
    std::ostringstream oss;
    oss << lfsr;
    BOOST_CHECK_EQUAL(oss.str(), "1011011000110110");
}

// Test for all-zeros seed
BOOST_AUTO_TEST_CASE(test_all_zeros_seed) {
    FibLFSR lfsr("0000000000000000");
    BOOST_CHECK_EQUAL(lfsr.step(), 0);  // All bits are 0, expect 0
    BOOST_CHECK_EQUAL(lfsr.generate(8), 0);  // Generate 8 bits, all 0
}

// Test for generating bits
BOOST_AUTO_TEST_CASE(test_generate) {
    FibLFSR lfsr("1011011000110110");
    BOOST_CHECK_EQUAL(lfsr.generate(5), 3);  // Adjusted due to new tap configuration
    BOOST_CHECK_EQUAL(lfsr.generate(5), 6);  // Adjusted due to new tap configuration
}

// Test for multiple steps
BOOST_AUTO_TEST_CASE(test_multiple_steps) {
    FibLFSR lfsr("0110100001100110");
    BOOST_CHECK_EQUAL(lfsr.generate(7), 67);  // Adjusted to reflect new tap bits
    BOOST_CHECK_EQUAL(lfsr.generate(9), 24);  // Adjusted to reflect new tap bits
}

// Test for generating 0 bits
BOOST_AUTO_TEST_CASE(test_generate_zero) {
    FibLFSR lfsr("1111000011110000");
    BOOST_CHECK_EQUAL(lfsr.generate(0), 0);  // Generating 0 bits should still return 0
}
