#include <stdio.h>
#include <signal.h>
#include <unistd.h>		/* for convenience */
#include <setjmp.h>

sigjmp_buf env;
volatile int end = 2;

void bus_handler( int bus_sig_numb )
{
    ( void ) bus_sig_numb;
    end--;
    printf( "\nSent:%s\n", __func__ );
    siglongjmp( env, 0 );
}


int main()
{
    int ret;
    struct sigaction sa;
    sa.sa_handler = bus_handler;
    sigemptyset( &sa.sa_mask );
    if ( sigaction( SIGBUS , &sa, NULL ) == -1 )
    {
        printf( "Signal\n" );
        return -1;
    }
    ret = sigsetjmp( env,  1);
    printf( "PID:%ld\n", getpid() );
    printf( "Before while where end==%i.\n", end );
    while( end );
    
    printf( "Done.\n" );
    return 0;
}