#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int fill_packet( char * packet, char * src, int * len_pack )
{
    int byte = 0;
    int len_src = strlen( src );
    len_src /= 3;
    *len_pack = len_src - 1;
    for( int i = 0; i < len_src - 1; i++)
    {   
        sscanf( src + 3*i, "%x", &byte );   //odczyt kolejnych bajtow
        packet[ i ] = byte;
    }  
    sscanf( src + 3 * ( len_src - 1 ), "%x", &byte ); // odczyt channel id
    packet[  len_src - 1  ] = 0;
    return byte;
}

int main( int argc, char ** argv )
{
    char output [200];
    int byte = 0;
    memset( output, 0, 200 );
    char input [200] = "00 00 00 00 00 00 01 01 01 01 01 01 ae fe 10 02 00 14 00 00 00 80 90 00 00 00 01 01 e1 00 00 00 00 00 ff f1 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 01 104";
    int len_input = strlen( input );
    len_input /= 3;
    for( int i = 0; i < len_input - 1; i++)
    {   
        sscanf( input + 3*i, "%x", &byte );
        output[ i ] = byte;
        printf( "%d ", byte );
    }
    printf( "\n" );
    sscanf( input + 3 * ( len_input - 1 ), "%x", &byte );
    output[ len_input - 1 ] = 0;
    printf( "%d ", byte );
    printf( "\n" );
}