#include<stdio.h>
#include<stdlib.h>
int main( int argc, char ** argv )
{
    if( argc != 2 )
    {   
        printf("Error: missing input char.\n");
        exit( 1 );
    }
    printf( "Int: %i\nChar: %c\n", argv[ 1 ][ 0 ], argv[ 1 ][ 0 ]);
    return 0;
}