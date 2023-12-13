#include <stdio.h>

void GetMatrix( int **value, int *row, int *col ) ;

int main() {
	int *data, m, n ;
	GetMatrix( &data, &m, &n ) ;
	
	delete []data;
	return 0 ;
}//end function

void GetMatrix( int **value, int *row, int *col ) {
	
	printf( "----|Input Row and Column.\n" ) ;
	printf( "Enter row : " ) ;
	scanf( "%d", row ) ;
	printf( "Enter col : " ) ;
	scanf( "%d", col ) ;

	*value = new int[ *row * *col ] ;
	
	printf( "----|Input Data in Array.\n" ) ;
	for( int i = 0 ; i < *row ; i++ ) {
		for( int j = 0 ; j < *col ; j++ ){
			printf( "Data[ %d ][ %d ] = ", i, j ) ;
			scanf( "%d", &( *value )[ i * *col + j ] ) ;
		}//end for j
	}//end for i
	
	printf( "----|Show Data.\n" ) ;
	for( int i = 0 ; i < *row ; i++ ) {
		for( int j = 0 ; j < *col ; j++ ){
			printf( "Data[ %d ][ %d ] = %d\n", i, j, (*value)[i * *col + j] ) ;
		}//end for j
	}//end for i
}//end function GetMatrix

