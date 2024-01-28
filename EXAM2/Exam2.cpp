#include <stdio.h>
#include <string.h>

struct studentNode{
	char name[ 20 ] ;
	int age ;
	char sex ;
	float gpa ;
	struct studentNode *next ;
	struct studentNode *back ;
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
	
	swap( &start, 3, 2 ) ;
	
	printf( "After swap : \n" ) ;
	ShowAll( start ) ;
	
	return 0 ;
}

struct studentNode *AddNode( struct studentNode **start, char *name, int age, char sex, float gpa ) {
	struct studentNode *node = new struct studentNode ;
	
	node->next = NULL ;
	node->back = NULL ;
	
	strcpy( node->name, name ) ;
	node->age = age ;
	node->sex = sex ;
	node->gpa = gpa ;
	
	if( *start == NULL ) {
		*start = node ;
	} else {
		struct studentNode *temp = *start ;
		while( temp->next != NULL ) {
			temp = temp->next ;
		}
		temp->next = node ;
		node->back = temp ;
	}
	
	return node ;
}//end function

void swap( struct studentNode **start, int A, int B ) {
	if( *start == NULL || ( *start )->next == NULL ) {
		printf( "Empty node or less then one node.\n" ) ;
		return ;
	} else if( A == B ) {
		printf( "Can't swap same position.\n" ) ;
		return ;
	} 
	
	struct studentNode *previousA = NULL, *currentA = *start ;
	for( int i = 1 ; currentA != NULL && i < A ; ++i ) {
		previousA = currentA ;
		currentA = currentA->next ;
	}//end for
	
	struct studentNode *previousB = NULL, *currentB = *start ;
	for( int i = 1 ; currentB != NULL && i < B ; ++i ) {
		previousB = currentB ;
		currentB = currentB->next ;
	}//end for
	
	if( currentA == NULL || currentB == NULL ) {
		printf( "Error.\n" ) ;
		return ;
	} else {
		
		if( previousA != NULL ) {
			previousA->next = currentB ;
		} else {
			*start = currentB ;
		}//end if
		
		if( previousB != NULL ) {
			previousB->next = currentA ;
		} else {
			*start = currentA ;
		}//end if
	
	struct studentNode *temp = currentA->next ;
	currentA->next = currentB->next ;
	currentB->next = temp ;
	
	if( currentA->next != NULL ) {
		currentA->next->back = currentA ;
	}
	if( currentB->next != NULL ) {
		currentB->next->back = currentB ;
	}
		
	}//end if
	
}//end function

void ShowAll( struct studentNode *walk ) {
	while( walk != NULL ) {
		printf( "%s ", walk->name ) ;
		walk = walk->next ;
	}//end while
	printf( "\n" ) ;
}//end function
