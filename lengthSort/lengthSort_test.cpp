#include "lengthSort.hpp"
#include "gtest/gtest.h"

TEST( FromCourse, RandomlyChosenSequence )
{
    EXPECT_EQ( std::deque<std::string>( { "One", "Two", "Four", "Three" } ), lengthSort( { "Three", "One", "Four", "Two" } ) );
}

int main( int argc, char ** argv )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}