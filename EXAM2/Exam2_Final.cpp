#include <stdio.h>

struct node {
	
	int data ;
	struct node *next ;
	struct node *back ;
	
};

struct node *AddNode( struct node **walk, int data ) ;
void ShowAll( struct node *walk ) ;
void SwapNode( struct node **walk, int x, int y ) ;

int main() {
	struct node *start, *now ;
	
	printf( "Before Swap : \n" ) ;
	
	now = AddNode( &start, 1 ) ;	
	now = AddNode( &start, 2 ) ;	
	now = AddNode( &start, 3 ) ;	
	now = AddNode( &start, 4 ) ;	
	now = AddNode( &start, 5 ) ;
	ShowAll( start ) ;
	
	printf( "After Swap : \n" ) ;
	
	SwapNode( &start, 1, 4 ) ; 
	ShowAll( start ) ;
	SwapNode( &start, 2, 3 ) ;
	ShowAll( start ) ;
	SwapNode( &start, 5, 2 ) ;
	ShowAll( start ) ;
	SwapNode( &start, 4, 1 ) ;
	ShowAll( start ) ;
		
	
}

struct node *AddNode( struct node **walk, int data ) {
	
	struct node *temp = NULL ; 
	
	while( *walk != NULL ) {
		temp = *walk ;
		walk = &( *walk )->next ;
	}//end while
	
	*walk = new struct node ;
	( *walk )->data = data ;
	( *walk )->next = NULL ;
	( *walk )->back = temp ;
	return *walk ;
	
}//end fuction Addnode

void SwapNode( struct node **walk, int A, int B ) {
	//if A and B is the same end program
	if( A == B ) {
		return ;
	}//end if
	
	//find first position you want to swap
	struct node *nextA = *walk ;
	struct node *backA = NULL ;
	while( nextA && nextA->data != A ) {
		backA = nextA ;
		nextA = nextA->next ;
	}//end while
	
	//find second position you want to swap
	struct node *nextB = *walk ;
	struct node *backB = NULL ;
	while( nextB && nextB->data != B ) {
		backB = nextB ;
		nextB = nextB->next ;
	}//end while
	
	//if A or B is NULL end program
	if( nextA == NULL || nextB == NULL ) {
		return ;
	}//end if
	
	//if A is not head
	if( backA != NULL ) {
		backA->next = nextB ;
	} else { //else make B as new head
		*walk = nextB ;
	}//end if
	
	//if B is not head
	if( backB != NULL ) {
		backB->next = nextA ;
	} else { //else make A as new head
		*walk = nextA ;
	}//end if
	
	//swap next pointers
	struct node *temp = nextB->next ;
	nextB->next = nextA->next ;
	nextA->next = temp ;
	
}

void ShowAll( struct node *walk ) {
	while( walk != NULL ) {
		printf( "%d ",walk->data ) ;
		walk = walk->next ;
	}//end while
	printf( "\n" ) ;
}//end fuction ShowAll
//66543206061-4 Kittisak Poodtrong
