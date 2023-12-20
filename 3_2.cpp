#include <stdio.h>

struct student {
 char name[ 20 ] ;
 int age ;
 char sex ;
 float gpa ;
} ;

void upgrade( struct student *child ) ;

int main() {
	struct student aboy ;
	aboy.sex = 'M' ;
	aboy.gpa = 3.00 ;
	upgrade( &aboy ) ;
	printf( "%.2f", aboy.gpa ) ;
 
	struct student agirl ;
	agirl.sex = 'F' ;
	agirl.gpa = 2.00 ;
	upgrade( &agirl ) ;
	printf( "%.2f", agirl.gpa ) ;

	return 0 ;
}//end function

void upgrade( struct student *child ) {
	float plus, sum, num ;
	
	if( child->sex == 'M' ) {
		plus = ( child->gpa * 10 ) / 100 ; 
		sum = child->gpa + plus ;
		printf( "----|Show The Boys gpa increase by 10%\n" ) ;
		printf( "After gpa increase by 10% : %.2f\n", sum ) ;
		printf( "Before gpa increase by 10% : " ) ;
		
	} else if( child->sex == 'F' ) {
		
		plus = ( child->gpa * 20 ) / 100 ; 
		sum = child->gpa + plus ;
		printf( "\n----|Show Girls gpa increase by 20%\n" ) ;
		printf( "After gpa increase by 20% : %.2f\n", sum ) ;
		printf( "Before gpa increase by 20% : " ) ;
	}
	
}
