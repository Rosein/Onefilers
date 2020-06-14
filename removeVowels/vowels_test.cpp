#include "vowels.hpp"
#include "gtest/gtest.h"

TEST( SingleWords, StayOnlyBs )
{
    EXPECT_EQ( std::vector<std::string>( { {"bcd"}, {"bbbccbc"}, {"qwrt"} } ), removeVowels( { {"abcde"}, {"aabbbccabc"}, {"qwerty"} } ) );
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
