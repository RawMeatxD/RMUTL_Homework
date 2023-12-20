#include <stdio.h>

void reverse( char str1[], char str2[] ) ;

int main() {
 	//char text[ 50 ] = "I Love You" ;
 	char text[ 50 ] = "Hello World" ;
 	char out[ 50 ] ;
 	reverse( text, out ) ;
}//end function

void reverse( char str1[], char str2[] ) {
	int i = 0, j = 0 ;
	int length = 0;
	char hold ;
	
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
	for( j = 0 ; j < 20 ; j++ ) {
		printf( "%c", str2[ j ] ) ;
	}//end for show str2
	
}//end function reverse
