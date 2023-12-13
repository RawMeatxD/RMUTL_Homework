#include <stdio.h>

int GetSet( int ** ) ;

int main() {
 int *data, num ;
 num = GetSet( &data ) ;
 return 0 ;
}//end function

int GetSet( int **data ) {
	int *num ;
	//printf( "----| Input Array's Size." ) ;
	printf( "Enter Number : " ) ;
	scanf( "%d", num ) ;
	
	*data = new int[ *num ] ;
	
	//printf( "----| Input Data in Array.\n" ) ;
	for( int i = 0 ; i < *num ; i++ ) {
		printf( "Enter Data %d : ", i + 1 ) ;
		scanf( "%d", &data[ i ] ) ;
	}//end for input data
	
	//printf( "----| Show Data." ) ;
	for( int j = 0 ; j < *num ; j++ ) {
		printf( "Data %d : %d", j + 1, data[ j ] ) ;
	}//end for show data
}


