#include <array>
#include <utility>
#include <vector>

// constexpr size_t HEIGHT = 3;
constexpr size_t HEIGHT = 32;
// constexpr size_t WIDTH = 10;
constexpr size_t WIDTH = 32;

using Compr = std::vector<std::pair<uint8_t, uint8_t>>;
using Decompr = std::array<std::array<uint8_t, WIDTH>, HEIGHT>;

Compr compressGrayscale( Decompr bitmap )
{
    Compr compressed;
    for( int i = 0; i < HEIGHT; ++i )
    {
        compressed.push_back( { bitmap[ i ][ 0 ], 1 } );
        for( int j = 1; j < WIDTH; ++j )
        {
            if( compressed.back().first == bitmap[ i ][ j ] )
            {
                ( compressed.back().second )++;
            }
            else
            {
                compressed.push_back( { bitmap[ i ][ j ], 1 } );
            }
        }
    }
    return compressed;
}

Decompr decompressGrayscale( Compr compressed_bitmap )
{
    Decompr bitmap;
    auto cur_pair = std::begin( compressed_bitmap );
    for( auto & row : bitmap )
    {
        for( auto & el : row )
        {
            if( ( *cur_pair ).second )
            {
                el = ( *cur_pair ).first;
            }
            else
            {
                el = ( *( ++cur_pair ) ).first;
            }
            ( *cur_pair ).second--;
        }
    }
    return bitmap;
}