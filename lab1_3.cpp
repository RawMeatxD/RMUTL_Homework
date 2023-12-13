#include <stdio.h>
int *GetSet( int * ) ;

int main() {
	int *data, num ;
	data = GetSet( &num ) ;
	return 0 ;
}//end function

int *GetSet( int *num ) {
	int *data ;
	printf( "----| Set Array Size.\n" ) ;
	printf( "Enter Number : " ) ;
	scanf( "%d", num ) ;
	
	data = new int[ *num ] ;
	
	printf( "----| Input Data in Array.\n" ) ;
	for( int i = 0 ; i < *num ; i++ ) {
		printf( "Enter Data %d : ", i + 1 ) ;
		scanf( "%d", &(data)[ i ] ) ;
	}//end for input data
	
	printf( "----| Show Data.\n" ) ;
	for( int i = 0 ; i < *num ; i++ ) {
		printf( "Data %d = %d\n", i + 1, data[ i ] ) ;
	}//end for show data
}//end function GetSet
