#include <stdio.h>
#include <string.h>

struct studentNode {
	char name[20] ;
	int age ;
	char sex ;
	float gpa ;
	struct studentNode *next ;
} ;

void ShowAll( struct studentNode *walk ) ;
struct studentNode *AddNode( struct studentNode **start, char *name, int age, char sex, float gpa ) ;
void InsNode( struct studentNode *now, char *name, int age, char sex, float gpa ) ;
void DelNode(struct studentNode *now) ;

int main() {
	struct studentNode *start, *now ;
	start = NULL ;
	now = AddNode( &start, "one", 6, 'M', 3.11 ) ; ShowAll( start ) ;
	now = AddNode( &start, "two", 8, 'F', 3.22 ) ; ShowAll( start ) ;
	InsNode( now, "three", 10, 'M', 3.33 ) ; ShowAll( start ) ;
	InsNode( now, "four", 12, 'F', 3.44 ) ; ShowAll( start ) ;
	DelNode( now ) ; ShowAll( start ) ;  
	return 0 ;
}//end function

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
}

void InsNode( struct studentNode *now, char *name, int age, char sex, float gpa ){
	
	struct studentNode *Node = new struct studentNode;
    strcpy( Node->name, name ) ;
    Node->age = age ;
    Node->sex = sex ;
    Node->gpa = gpa ;
    Node->next = now->next ;  
    now->next = Node ;  
	
}

void DelNode(struct studentNode *now) {

    struct studentNode *temp = now->next;
    now->next = temp->next;
    delete temp ;
    
}

void ShowAll( struct studentNode *walk ) {
	while( walk != NULL ) {
		printf( "%s ", walk->name ) ;
		walk = walk->next ;
	}//end while
	printf( "\n" ) ;
}//end function
//66543206061-4 Kittisak Poodtrong
