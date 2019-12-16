#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


#define CHECK_ALLOC( x )    if( NULL == ( x ) )                                                                                                                        \
                            {                                                                                                                                          \
                                fprintf( stderr, "ERROR_ALLOC             : ( %i )[ %s ]{ %s } < %s > " #x " \n", __LINE__, __FILE__, __FUNCTION__, strerror(errno) ); \
                                exit( 1 );                                                                                                                             \
                            }


#define END_IF( x )    if( x )                                                                                                                 \
                            {                                                                                                                  \
                                fprintf( stdout, "EXIT_CONDITION_SATISFIED: ( %i )[ %s ]{ %s } " #x " \n", __LINE__, __FILE__, __FUNCTION__ ); \
                                exit( 1 );                                                                                                     \
                            }


#define PRINT_IF( x )    if( x )                                                                                                           \
                            {                                                                                                              \
                                fprintf( stdout, "CONDITION_SATISFIED     : ( %i )[ %s ]{ %s } " #x " \n", __LINE__, __FILE__, __FUNCTION__ ); \
                            }

#define PRINT_MSG( x )          fprintf( stdout, "MSG                     : ( %i )[ %s ]{ %s } " #x " \n", __LINE__, __FILE__, __FUNCTION__ );

int main()
{
    PRINT_IF( 25 == 5 * 5 );
    PRINT_MSG( Dobrze Ci życie idzie );
    int * i = NULL;
    CHECK_ALLOC(i);

    return 0;
}