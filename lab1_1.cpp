#include <stdio.h>

int main() {
	int num = 0 ;
	do {
		printf( "Enter Number : " ) ;
		scanf( "%d", &num ) ;
		
		for( int i = 1 ; i <= num ; i++ ) {
			printf( "[%d] Hello world\n", i ) ;
		}	
	} while( true ) ;
}
