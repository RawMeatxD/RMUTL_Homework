#include <stdio.h>

char* reverse( char str1[]) ;

int main() {
 char text[ 50 ] = "I Love You" ;
 char *out ;
 out = reverse( text ) ;
}//end function

char* reverse( char str1[] ) {
	int i = 0, j = 0 ;
	int length = 0 ;
	char hold, str2[ 50 ] ;
	
    while (str1[length] != '\0') {
        length++;
    }//end while count str1[]'s length.
	
	for( i = length ; i >= 0 ; i-- ) {			
		hold = str1[ i ] ;
		str2[ j ] = hold ;	
		j++ ;
	}//end for reverse & collect loop
	
	printf( "----|Show str1 :\n" ) ;		
	for( i = 0 ; i < 20 ; i++ ) {	
		printf( "%c", str1[ i ] ) ;		
	}//end for show str1
	
	printf( "\n----|Show str2 :\n" ) ;
	for( j = 0 ; j < length + 1 ; j++ ) {
		printf( "%c", str2[ j ] ) ;
	}//end for show str2
}
