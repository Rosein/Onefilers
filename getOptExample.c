#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int memo, opt;
    int nsecs, tfnd;

    char * parse_buffer;
    parse_buffer = ( char * ) malloc( sizeof( char ) * 32 );
    memset( parse_buffer, 0, sizeof parse_buffer );
    tfnd = 0;
    flags = 0;
    for( int i = 0; i < argc; i++ )
        printf( "%s\t", argv [ i ] );
    printf( "\n" );
    
    for( int i = 0; i < argc; i++ )
        printf( "%s\t", argv [ i ] );
    printf( "\n" );
    printf("flags=%d; tfnd=%d; buffer=%s; optind=%d\n", flags, tfnd, parse_buffer, optind);

    if (optind >= argc) {
        fprintf(stderr, "Expected argument after options\n");
        exit(EXIT_FAILURE);
    }

    printf("name argument = %s\n", argv[optind]);

    /* Other code omitted */

    exit(EXIT_SUCCESS);
}