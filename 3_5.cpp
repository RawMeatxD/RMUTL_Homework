#include <stdio.h>

struct student {
	char name[ 20 ] ;
};

struct student (*GetStudent( int *room ) )[ 10 ] ;

int main() {
	struct student ( *children )[ 10 ] ;
	int group ;
	children = GetStudent( &group ) ;
	return 0 ;
}//end function

struct student (*GetStudent( int *room ) )[ 10 ] {
	
	struct student child[ 20 ][ 10 ] ;
	
	printf( "Enter amount of Room : " ) ;
	scanf( "%d", &(*room) ) ;
	
	for( int i = 0 ; i < *room ; i++ ) {
		printf( "----| Room[ %d ] |----\n", i + 1 ) ;
		for( int j = 0 ; j < 10 ; j++ ) {
			printf( "Enter student name[ %d ] : ", j + 1 ) ;
			scanf( "%s", child[ i ][ j ].name ) ;
		}
	}
	printf( "\n" ) ;
	for( int i = 0 ; i < *room ; i++ ) {
		printf( "----| Show student data Room[ %d ] |----\n", i + 1 ) ;
		for( int j = 0 ; j < 10 ; j++ ) {
			printf( "Show student name[ %d ] = %s\n", j + 1, child[ i ][ j ].name ) ;
		}
	}
	
};
