#include<stdio.h>
#include<strings.h>

int main( int argc, char ** argv )
{
    if ( argc > 1 )
        for( int i = 1; i <= atoi( argv [ 1 ] ); ++i )
            printf("%i ", i );
    else
    {
        printf("Usage: %s len_seq\n", argv [ 0 ] );
    }
    return 0;
}