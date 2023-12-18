#include <stdio.h>

int showAnswer( int i, int A[], int B[], int Answer[], char op ) ;

int main() {
	int A[ 6 ], B[ 6 ], Answer[ 7 ]   ;	//declare array variable A[], B[], Answer[].
	int num ; 							//declare integer variable num to recive input number.
	int i = 0, j = 6 ;					//declare integer variable i, j to be counter.	
	int hold, hold_else ;				//declare integer variable hold, hold_else to store sum and minus
	int length = -1 ;					//declare integer variable to count array's length.
	int decimal = 0 ;					//declare integer variable *decimal to roll up the numbers. *Translation problems (;w;)*
	char op ;							//declare character variable to store operator - and +.
	char EndProgram ;					//declare character variable to store char y and n.
	
	do {
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
		
		do {
			length++ ;
		} while ( A[ length ] != '\0' ) ;//end while count *A[]'s length. *A[] and B[] both have the same length.
		
		i = 0 ;
		length-- ;
		
		//choose operator - or + 
		printf( "Operator : \n" ) ;
		do {
			scanf( " %c", &op ) ;
			
			if( op == '+' ) {//if choose +
			
				do {
					hold = A[ length - 1 ] + B[ length - 1 ] ;		
					if( hold >= 10 ) {
						hold = hold - 10 ;
						
						if( decimal == 1 ) {
							hold = hold + decimal ;
							Answer[ j ] = hold ;
						} else {
							Answer[ j ] = hold ;
						}//end if decimal
						
						decimal++ ;	
						
					} else if( hold < 10 ) {
						hold_else = hold ;
						
						if( decimal == 1 ) {
							hold_else = hold_else + decimal ;
							decimal-- ;
							
							if( hold_else >= 10 ) {
								hold_else = hold_else - 10 ;
								Answer[ j ] = hold_else ;
								decimal++ ;		
							} else {
								Answer[ j ] = hold_else ;
							}//end if hold_else >= 10
							
						} else {
							Answer[ j ] = hold_else ;
						}//end if decimal	
					}//end if hold
					length-- ;
					j-- ;
					
					if( decimal > 1 ) {
						decimal-- ;
					}//end if control decimal
					
					if( length < 0 ) {
						break ;
					}//end if break loop
				} while ( true ) ;//end calculation loop ( + )
				
				showAnswer( i, A, B, Answer, op ) ;//function show answer
				break ;
				
			} else if ( op == '-' ) {//if choose - 
				do {
					hold = A[ length - 1 ] - B[ length - 1 ] ;
					if( hold < 0 ) {
						hold = hold + 10 ;
						
						if( decimal == 1 ) {
							hold = hold - decimal ;
							Answer[ j ] = hold ;
						} else {
							Answer[ j ] = hold ;
						}//end if decimal
						decimal++ ;	
					} else if( hold >= 0 ) {
						hold_else = hold ;
						if( decimal == 1 ) {
							hold_else = hold_else - decimal ;
							decimal-- ;
							if( hold_else < 0 ) {
								hold_else = hold_else + 10 ;
								Answer[ j ] = hold_else ;
								decimal++ ;		
							} else {
								Answer[ j ] = hold_else ;
							}//end if hold_else < 0
						} else {
							Answer[ j ] = hold_else ;
						}//end if decimal	
					}//end if hold
					length-- ;
					j-- ;
					
					if( decimal > 1 ) {
						decimal-- ;
					}//end if control decimal
					
					if( length < 0 ) {
						break ;
					}//end if break loop
				} while ( true ) ;//end calculation loop ( - )
				showAnswer( i, A, B, Answer, op ) ;//function show answer
				break ;
			}//end if choose - or + 
		} while ( true ) ;//end choose operator loop
		
		//choose y to run again, n to stop program.
		printf( "\nWanna run again?? [y/n] : " ) ;
		scanf( " %c", &EndProgram ) ;
		
		if( EndProgram == 'n' ) {
			break ;
		} else if( EndProgram == 'y' ) {	
			num = 0 ; 
			i = 0 ;
			j = 6 ;							
			hold ;
			hold_else ;
			length = -1 ;
			decimal = 0 ;
		} else {
			printf( "Please enter ( y and n ) only!!.\n" ) ;
		}//end if choose y or n
		
	} while ( true ) ;//end program loop
}//end function main

//show Answer[]
int showAnswer( int i, int A[], int B[], int Answer[], char op ) {
	int index = 0 ;
	int length = -1 ;
	
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
	do {
		if( op == '+' ) {
			printf( "\t%d", Answer[ i ] ) ;
			i++ ;
		} else if( op == '-' ) {
			printf( "\t%d", Answer[ i ] ) ;
			i++ ;
		}//end if
				
		if( i > 6 ) {
			break ;
		}//end if break loop
	} while ( true ) ;//end do-while show array Answer[]	
	printf( "\n\t\t==========================================================" ) ;
}//end function Answer[]

//66543206061-4 Kittisak Poodtrong Sec 3
