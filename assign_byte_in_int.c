#include "stdint.h"
#include "assert.h"
#include "stdio.h"


void incr_byte( uint64_t * dest, uint8_t index )
{
    uint8_t * temp = dest;
    *( temp + index ) = *( temp + index ) + 1;
}

uint64_t incr_byte( uint64_t * dest, uint8_t index )
{
    uint8_t * temp = dest;
    *( temp + index ) = *( temp + index ) + 1;
    return *dest;
}
void test()
{
    uint64_t dest = 0;
    assert( incr_byte( &dest, 0 ) == 1 );
    printf("[ %i ]{ %d }\n", __LINE__, dest );

    dest = 0;
    assert( incr_byte( &dest, 1 ) == 256 );
    printf("[ %i ]{ %d }\n", __LINE__, dest );
    assert( incr_byte( &dest, 1 ) == 512 );

    printf("[ %i ]{ %d }\n", __LINE__, dest );
}

int main()
{
    test();
    return 0;
}