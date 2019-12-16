#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main( int argc, char ** argv )
{
	if( argc > 0 )
	for( unsigned int i = 0; i < atoi( argv[ 1 ] ); i++ )
		printf( "%s %i\n", strerror( i ), i );
	return 0; 
}
