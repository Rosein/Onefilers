#include "grayscale.hpp"
#include "gtest/gtest.h"

TEST( FromCodersSchool, CompressCase )
{
    std::vector<std::pair<uint8_t, uint8_t>> expected { {0, 3}, {1, 2}, {2, 1}, {3, 1}, {0, 3}, 
                                                        {0, 2}, {4, 3}, {1, 5},
                                                        {2, 5}, {1, 1}, {2, 4}};
    std::array<std::array<uint8_t, WIDTH>, HEIGHT> input
    {
        std::array<uint8_t, WIDTH>{ 0, 0, 0, 1, 1, 2, 3, 0, 0, 0 },
        std::array<uint8_t, WIDTH>{ 0, 0, 4, 4, 4, 1, 1, 1, 1, 1 },
        std::array<uint8_t, WIDTH>{ 2, 2, 2, 2, 2, 1, 2, 2, 2, 2 }
    };
    EXPECT_EQ( expected, compressGrayscale( input ) );
}

TEST( FromCodersSchool_CompressCase_Test, DecompressCase )
{
    std::vector<std::pair<uint8_t, uint8_t>> expected { {0, 3}, {1, 2}, {2, 1}, {3, 1}, {0, 3}, 
                                                        {0, 2}, {4, 3}, {1, 5},
                                                        {2, 5}, {1, 1}, {2, 4}};
    std::array<std::array<uint8_t, WIDTH>, HEIGHT> input
    {
        std::array<uint8_t, WIDTH>{ 0, 0, 0, 1, 1, 2, 3, 0, 0, 0 },
        std::array<uint8_t, WIDTH>{ 0, 0, 4, 4, 4, 1, 1, 1, 1, 1 },
        std::array<uint8_t, WIDTH>{ 2, 2, 2, 2, 2, 1, 2, 2, 2, 2 }
    };
    EXPECT_EQ( input, decompressGrayscale( compressGrayscale( input ) ) );
}

int main( int argc, char ** argv )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}