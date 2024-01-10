#include <stdio.h>

int showAnswer( int i, int A[], int B[], int Answer[], char op ) ;

int main() {
	int A[ 6 ], B[ 6 ], Answer[ 7 ] ;	//declare array variable A[], B[], Answer[].
	int num ; 							//declare integer variable num to recive input number.
	int i = 0, j = 6 ;					//declare integer variable i, j to be counter.	
	int hold ;							//declare integer variable hold to store sum and minus
	int length = 5 ;					//declare integer variable to be counter array's length.
	int decimal = 0 ;					//declare integer variable *decimal to roll up the numbers. *Translation problems (;w;)*
	char op ;							//declare character variable to store operator - and +.
	
	//input A[]
	printf( "Enter Number A : \n" ) ;
	do {
		do {
			printf( "A[%d] : ", i ) ;
			scanf( "%d", &num ) ;
				
			if( num <= 9 && num >= 0 ) {
				A[ i ] = num ;
				i++ ;
				break ;	
			} else {
				printf( "Please enter ( 0 - 9 ) only!!.\n" ) ;
			}//end if check input 0 - 9 and store
				
		} while ( true ) ;//end do-while check recived number 0 - 9
	
		if( i > 5 ) {
			break ;
		}//end if break loop
	} while ( true ) ;//end do-while input A[]
		
	//input B[]
	i = 0 ;
	printf( "Enter Number B : \n" ) ;
	do {
		do {
			printf( "B[%d] : ", i ) ;
			scanf( "%d", &num ) ;
				
			if( num <= 9 && num >= 0 ) {
				B[ i ] = num ;
				i++ ;
				break ;
			} else {
				printf( "Please enter ( 0 - 9 ) only!!.\n" ) ;
			}//end if check input 0 - 9 and store
				
		} while ( true ) ;//end do-while check recived number 0 - 9
			
		if( i > 5 ) {
			break ;
		}//end if break loop
	} while ( true ) ;//end do-while input B[]
			
	i = 0 ;
		
	//choose operator - or + 
	printf( "Operator : \n" ) ;
	do {
		scanf( " %c", &op ) ;
			
		if( op == '+' ) {//if choose +
			//calculation loop ( + )
			do {
				hold = A[ length ] + B[ length ] + decimal  ;	
				Answer[ j ] = hold % 10 ;
				decimal	= hold / 10 ;
				Answer[ 0 ] = decimal ;
				j-- ;
				length-- ;
				
				if( length < 0 ) {
					break ;
				}//end if break loop
			} while ( true ) ;//end calculation loop ( + )
				
			showAnswer( i, A, B, Answer, op ) ;//function show answer
			break ;
				
		} else if ( op == '-' ) {//if choose - 
			hold = 0 ;
			
			if ( A[ 0 ] >= B[ 0 ] ) {
				
				//calculation loop ( - )
				do {
					hold = ( A[ length ] - B[ length ] ) - decimal ;
					
					if( hold < 0 ) {
						Answer[ j ] = hold + 10 ;
						decimal = 1 ;
						Answer[ 0 ] = decimal ;
					} else {
						Answer[ j ] = hold ;
						decimal = 0 ;
						Answer[ 0 ] = decimal ;
					}//end if 
					
					j-- ;
					length-- ;
					
					if( length < 0 ) {
						break ;
					}//end if break loop
				} while ( true ) ;//end calculation loop ( - )
				
			} else if( A[ 0 ] < B[ 0 ] ) {
			 
			 	//calculation loop ( - )
				do {
					hold = ( B[ length ] - A[ length ] ) - decimal ;
					
					if( hold < 0 ) {
						Answer[ j ] = hold + 10 ;
						decimal = 1 ;
						Answer[ 0 ] = decimal ;
					} else {
						Answer[ j ] = hold ;
						decimal = 0 ;
						Answer[ 0 ] = decimal ;
					}//end if 
					
					j-- ;
					length-- ;
					
					if( length < 0 ) {
						break ;
					}//end if break loop
				} while ( true ) ;//end calculation loop ( - )
			 
			}
			
			showAnswer( i, A, B, Answer, op ) ;//function show answer
			break ;
		}//end if choose - or + 
	} while ( true ) ;//end choose operator loop
	
}//end function main

//show Answer[]
int showAnswer( int i, int A[], int B[], int Answer[], char op ) {
	int index = 0 ;
	
	//show index
	printf( "\nIndex : \t\tx" ) ;
	i = 0 ;
	do {
		printf( "\t%d", i ) ;
		i++ ;
				
		if( i > 5 ) {
			break ;
		}//end if break loop
	} while ( true ) ;//end do-while show index
	
	//show array A[]
	printf( "\n" ) ;
	printf( "\nNumber A : \t\t" ) ;
	i = 0 ;
	do {
		printf( "\t%d", A[ i ] ) ;
		i++ ;
				
		if( i > 5 ) {
			break ;
		}//end if break loop
	} while ( true ) ;//end do-while show array A[]
	
	//show operator
	printf( "\nOperator : \t\t\t\t\t\t\t\t %c", op ) ;
	
	//show array B[]
	printf( "\nNumber B : \t\t" ) ;
	i = 0 ;
	do {
		printf( "\t%d", B[ i ] ) ;
		i++ ;
					
		if( i > 5 ) {
			break ;
		}//end if break loop
	} while ( true ) ;//end do-while show array B[]
	
	printf( "\n\t\t----------------------------------------------------------" ) ;
	
	//show array Answer[]
	printf( "\nAnswer : \t" ) ;
	i = 0 ;
		if( op == '+' ) {
			do {
				printf( "\t%d", Answer[ i ] ) ;
				i++ ;
			
				if( i > 6 ) {
				break ;
					}//end if break loop
			} while ( true ) ;//end do-while show array Answer[]
		} else if( op == '-' ) {
			
			if ( A[ 0 ] >= B[ 0 ] ) {
				do {
					printf( "\t%d", Answer[ i ] ) ;
					i++ ;
				
					if( i > 6 ) {
					break ;
					}//end if break loop
				} while ( true ) ;//end do-while show array Answer[]
				
			} else if ( A[ 0 ] < B[ 0 ] ) {
				printf( "\t%c", op ) ;
				do {
					printf( "\t%d", Answer[ i + 1 ] ) ;
					i++ ;
				
					if( i > 5 ) {
					break ;
					}//end if break loop
				} while ( true ) ;//end do-while show array Answer[]
			}
				
		}//end if
				
	printf( "\n\t\t==========================================================" ) ;
}//end function Answer[]

//66543206061-4 Kittisak Poodtrong Sec 3
