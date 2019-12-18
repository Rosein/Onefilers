#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

uint32_t get_rest_of_file_size( FILE * f_in )
{
    uint32_t current_pos = ftell( f_in );
    fseek( f_in, 0, SEEK_END );
    uint32_t size_of_file = ftell( f_in );
    fseek( f_in, current_pos, SEEK_SET );
    return size_of_file - current_pos;
}

size_t strlength( char * src, uint32_t * current_pos, bool * is_eof_file, uint32_t file_size )
{
    uint32_t size_till_lf = 0;
    uint32_t i = *current_pos;
    // printf( "current pos : %i \n", i );
    // printf("========== BEGIN ITER ===========\n");
    while( i < file_size && src[ i ] != '\n' && src[ i ] != EOF )
    {
        // printf( "%c ", src[ i ] );
        i++;
    }
    // printf("\n========== END ITER ===========\n");
    *is_eof_file = !( i < file_size );
    size_till_lf = i - *current_pos + 1;
    // printf( "diff : %i \n", size_till_lf );
    *current_pos = i + 1;
    return size_till_lf - 1;
}

int main( int argc, char * argv [] )
{
    FILE * f_in = fopen("sample.txt", "r+");
    if ( f_in == NULL)
        return 1;

    uint32_t rest_size = get_rest_of_file_size( f_in );
    char * buff = malloc( rest_size + 1 );
    if( buff == NULL )
    {
        exit( 1 );
    }
    fread( buff, 1, rest_size, f_in );
    bool is_eof_file = false;
    uint32_t current_pos = 0;
    uint32_t size_of_line = 0;
    while( !is_eof_file )
    {
        printf( "[ full_file ][ cur_line : %s ]\n", buff + current_pos );
        // size_of_line = strlen( buff );
        size_of_line = strlength( buff, &current_pos, &is_eof_file, rest_size );
        printf( "[ len_line : %4u ]\n\n\n", size_of_line );
    }
    fclose( f_in );
    return 0;
}