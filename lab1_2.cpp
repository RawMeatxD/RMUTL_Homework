#include <stdio.h>
#include <string.h>

void GetSet( int [], int * ) ;

int main() {
 int *data, num ;
 GetSet( data, &num ) ;
 return 0 ;
}//end function

void GetSet( int [] , int * ) {
	int *data, num ;
	printf( "Enter Number : " ) ;
	scanf( "%d", &num ) ;
	
	for( int i = 0 ; i < num ; i++ ) {
		printf( "Enter Data %d : ", i + 1 ) ;
		scanf( "%d", &data[ i ] ) ;
	}
	
	for( int j = 0 ; j < num ; j++ ) {
		printf( "Data %d : %d\n", j + 1, data[ j ] ) ;
	}
}
