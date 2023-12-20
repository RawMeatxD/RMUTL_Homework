#include <stdio.h>

void explode( char str1[], char splitter, char str2[][10], int *count ) ;

int main() {
	char out[ 20 ][ 10 ] ;
	int num ;
	explode( "I/Love/You", '/', out, &num ) ;
	return 0 ;
}//end function

void explode( char str1[], char splitter, char str2[][10], int *count ) {	
	int i = 0, j = 0 ;
	int len = 0 ;
	
	while( str1[ len ] != '\0' ) {
		len++ ;
	}//end while count str1 length 
	//printf( "[ %d ]\n", len ) ;
	
	for( i = 0, j = 0 ; i < len ; i++ ) {
		
		if( str1[ i ] == splitter ) {	
			( *count )++ ;
			j = 0 ;
		} else {
			str2[ *count ][ j ] = str1[ i ] ;
			j++ ;
		}//end if
			
	}//end for
	( *count )++ ;
	
	for( i = 0 ; i < len ; i++ ) {
		printf( "str2[ %d ] = \" %s \"\n", i, str2[ i ] ) ;
		
		if( i >= *count - 1 ) {
			break ;	
		}//end if
		
	}//end for
 	printf( "\ncount = %d", *count ) ;
	
	//printf( "[ %c ]", splitter ) ;
}
