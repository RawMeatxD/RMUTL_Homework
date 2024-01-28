#include <stdio.h>
#include <string.h>

struct studentNode{
	char name[ 20 ] ;
	int age ;
	char sex ;
	float gpa ;
	struct studentNode *next ;
};

struct studentNode *AddNode( struct studentNode **start, char *name, int age, char sex, float gpa ) ;
void ShowAll( struct studentNode *walk ) ;
void swap( struct studentNode **start, int A, int B ) ;
	
int main() {
	struct studentNode *start, *now, **walk ;
	start = NULL ;
	AddNode( &start, "one", 6, 'M', 3.11 ) ;
	AddNode( &start, "two", 8, 'F', 3.22 ) ;
	AddNode( &start, "three", 10, 'M', 3.33 ) ;
	AddNode( &start, "four", 12, 'F', 3.44 ) ;
	AddNode( &start, "five", 20, 'F', 3.69 ) ;
	
	printf( "Before swap : \n" ) ;
	ShowAll( start ) ;
	
	swap( &start, 1, 4 ) ;
	
	printf( "After swap : \n" ) ;
	ShowAll( start ) ;
	
	return 0 ;
}

struct studentNode *AddNode( struct studentNode **start, char *name, int age, char sex, float gpa ) {
	
	while( ( *start ) != NULL ){
		start = &(( *start )->next) ;
	}
	
	*start = new struct studentNode ;
	strcpy( ( *start )->name, name ) ;
	( *start )->age = age ;
	( *start )->sex = sex ;
	( *start )->gpa = gpa ;
	( *start )->next = NULL ;
	
	return *start ;
}//end function

void swap( struct studentNode **start, int A, int B ) {
	if( *start == NULL || ( *start )->next == NULL ) {
		printf( "Empty node or less then one node.\n" ) ;
		return ;
	} else if( A == B ) {
		printf( "Can't swap same position.\n" ) ;
		return ;
	} 
	
	struct studentNode *prevA = NULL, *currA = *start ;
	for( int i = 1 ; currA != NULL && i < A ; ++i ) {
		prevA = currA ;
		currA = currA->next ;
	}//end for
	
	struct studentNode *prevB = NULL, *currB = *start ;
	for( int i = 1 ; currB != NULL && i < B ; ++i ) {
		prevB = currB ;
		currB = currB->next ;
	}//end for
	
	if( currA == NULL || currB == NULL ) {
		printf( "Error.\n" ) ;
		return ;
	} else {
		
		if( prevA != NULL ) {
			prevA->next = currB ;
		} else {
			*start = currB ;
		}//end if
		
		if( prevB != NULL ) {
			prevB->next = currA ;
		} else {
			*start = currA ;
		}//end if
	
	struct studentNode *temp = currA->next ;
	currA->next = currB->next ;
	currB->next = temp ;
		
	}//end if
	
}//end function

void ShowAll( struct studentNode *walk ) {
	while( walk != NULL ) {
		printf( "%s ", walk->name ) ;
		walk = walk->next ;
	}//end while
	printf( "\n" ) ;
}//end function
