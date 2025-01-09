// CopyRight 2024 Harishwar Reddy Erri

#define BOOST_TEST_MODULE RandWriterTest
#include <boost/test/included/unit_test.hpp>
#include "RandWriter.hpp"

BOOST_AUTO_TEST_SUITE(RandWriterTests)

BOOST_AUTO_TEST_CASE(TestInvalidKGram) {
    RandWriter rw("sample text", 3);
    BOOST_REQUIRE_THROW(rw.freq("in"), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(TestValidKGram) {
    RandWriter rw("sample text", 3);
    BOOST_REQUIRE_NO_THROW(rw.freq("sam"));
}

BOOST_AUTO_TEST_CASE(TestFrequencyOfKGram) {
    RandWriter rw("sample text", 3);
    int frequency = rw.freq("sam");
    BOOST_REQUIRE_EQUAL(frequency, 1);
}

BOOST_AUTO_TEST_CASE(TestGenerateText) {
    RandWriter rw("sample text", 3);
    std::string generatedText = rw.generate("sam", 10);
    BOOST_REQUIRE(!generatedText.empty());
}

BOOST_AUTO_TEST_CASE(TestGenerateTextLength) {
    RandWriter rw("THE ADVENTURES OF TOM SAWYER", 5);
    std::string generatedText = rw.generate("THE A", 100);
    BOOST_REQUIRE_EQUAL(generatedText.length(), 100);
}

BOOST_AUTO_TEST_CASE(TestGenerateIncorrectLength) {
    RandWriter rw("THE ADVENTURES OF TOM SAWYER", 5);
    std::string generatedText = rw.generate("THE A", 300);
    BOOST_REQUIRE_EQUAL(generatedText.length(), 300);
}

BOOST_AUTO_TEST_CASE(TestGenerateStartsWithCorrectKGram) {
    RandWriter rw("THE ADVENTURES OF TOM SAWYER", 5);
    std::string startingKGram = "THE A";
    std::string generatedText = rw.generate(startingKGram, 100);
    BOOST_REQUIRE_EQUAL(generatedText.substr(0, startingKGram.length()), startingKGram);
}

BOOST_AUTO_TEST_SUITE_END()
