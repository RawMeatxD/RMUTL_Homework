#include <stdio.h>

int* GetMatrix( int *row, int *col ) ;

int main() {
 	int *data, m, n ;
 	data = GetMatrix( &m, &n ) ;
 	delete[] data ;
	return 0 ;
}//end function

int* GetMatrix( int *row, int *col ) {
	
	int *data ; 
	printf( "----|Input Row and Column.\n" ) ;
	printf( "Enter row : " ) ;
	scanf( "%d", row ) ;
	printf( "Enter col : " ) ;
	scanf( "%d", col ) ;

	data = new int[ *row * *col ] ;
	
	printf( "----|Input Data in Array.\n" ) ;
	for( int i = 0 ; i < *row ; i++ ) {
		for( int j = 0 ; j < *col ; j++ ){
			printf( "Data[ %d ][ %d ] = ", i, j ) ;
			scanf( "%d", &data[ i * *col + j ] ) ;
		}//end for j
	}//end for i
	
	printf( "----|Show Data.\n" ) ;
	for( int i = 0 ; i < *row ; i++ ) {
		for( int j = 0 ; j < *col ; j++ ){
			printf( "Data[ %d ][ %d ] = %d\n", i, j, data[i * *col + j] ) ;
		}//end for j
	}//end for i
	
	return data ;
	
}//end function GetMatrix


