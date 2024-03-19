#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char region[ 50 ] ;
	char country[ 50 ] ;
	char item[ 30 ] ;
	char channel[ 10 ] ;
	char priority ;
	char Odate[ 20 ] ;
	char id[ 12 ] ;
	char Shdate[ 20 ] ;
	int sold ;
	float price ;
	float Ucost ;
	float revenue ;
	float Tcost ;
	float profit ;
}info ;

void read_file() ;
void mostSold ( char region[ 50 ], char online[ 10 ], char offline[ 10 ] ) ;
void leastSold ( char region[ 50 ], char offline[ 10 ] ) ;
void top10 ( char region[ 50 ], char online[ 10 ] ) ;
	
int main() {
	read_file() ;
	mostSold( "Europe", "Online", "Offline" ) ;
	leastSold( "Asia", "Offline" ) ;
	top10( "Central America and the Caribbean", "Online" ) ;
	return 0 ;
}//end main

void read_file() {
	FILE *f = fopen( "50 Sales Records.csv", "r" ) ;
	char str[ 1000 ] = "" ;
	info rec[ 5001 ] ;
	char *token ;
	char *delim = "," ;
	int i = 0 ;
	while ( fgets( str, sizeof( str ), f ) != NULL ) {
		//printf( "str = %s", str ) ;
		token = strtok( str, delim ) ;
		int col = 0 ;
		while ( token != NULL ) {
			switch ( col ) {
				case 0 :
					strcpy( rec[ i ].region, token ) ;
					break ;
				case 1 :
					strcpy( rec[ i ].country, token ) ;
					break ;
				case 2 :
					strcpy( rec[ i ].item, token ) ;
					break ;
				case 3 :
					strcpy( rec[ i ].channel, token ) ;
					break ;
				case 4 :
					rec[ i ].priority = token[ 0 ] ;
					break ;
				case 5 :
					strcpy( rec[ i ].Odate, token ) ;
					break ;
				case 6 :
					strcpy( rec[ i ].id, token ) ;
					break ;
				case 7 :
					strcpy( rec[ i ].Shdate, token ) ;
					break ;
				case 8 :
					rec[ i ].sold = atoi( token ) ;
					break ;
				case 9 :
					rec[ i ].price = atof( token ) ;
					break ;
				case 10 :
					rec[ i ].Ucost = atof( token ) ;
					break ;
				case 11 :
					rec[ i ].revenue = atof( token ) ;
					break ;
				case 12 :
					rec[ i ].Tcost = atof( token ) ;
					break ;
				case 13 :
					rec[ i ].profit = atof( token ) ;
					break ;
			}
			col++ ;
			token = strtok( NULL, delim ) ;
		} 
	}
	fclose( f ) ;
}

//find most unit sold in Europe channel type = online / offine
void mostSold ( char region[ 50 ], char online[ 10 ], char offline[ 10 ] ) {
	FILE *f = fopen( "50 Sales Records.csv", "r" ) ;
	char str[ 1000 ] = "" ;
	info rec[ 5001 ] ;
	char *token ;
	char *delim = "," ;
	int i = 0 ;
	while ( fgets( str, sizeof( str ), f ) != NULL ) {
		//printf( "str = %s", str ) ;
		token = strtok( str, delim ) ;
		int col = 0 ;
		while ( token != NULL ) {
			switch ( col ) {
				case 0 :
					strcpy( rec[ i ].region, token ) ;
					break ;
				case 1 :
					strcpy( rec[ i ].country, token ) ;
					break ;
				case 2 :
					strcpy( rec[ i ].item, token ) ;
					break ;
				case 3 :
					strcpy( rec[ i ].channel, token ) ;
					break ;
				case 4 :
					rec[ i ].priority = token[ 0 ] ;
					break ;
				case 5 :
					strcpy( rec[ i ].Odate, token ) ;
					break ;
				case 6 :
					strcpy( rec[ i ].id, token ) ;
					break ;
				case 7 :
					strcpy( rec[ i ].Shdate, token ) ;
					break ;
				case 8 :
					rec[ i ].sold = atoi( token ) ;
					break ;
				case 9 :
					rec[ i ].price = atof( token ) ;
					break ;
				case 10 :
					rec[ i ].Ucost = atof( token ) ;
					break ;
				case 11 :
					rec[ i ].revenue = atof( token ) ;
					break ;
				case 12 :
					rec[ i ].Tcost = atof( token ) ;
					break ;
				case 13 :
					rec[ i ].profit = atof( token ) ;
					break ;
			}
			col++ ;
			token = strtok( NULL, delim ) ;
		} 
		i++ ;
	}
	
	//check region, channel and find most sold 
	int mostOnline = 0, mostOffline = 0 ;
	char itemOn[ 30 ], itemOff[ 30 ], countryOn[ 30 ], countryOff[ 30 ] ;
	for( int j = 0 ; j < i ; j++ ) {
		if( strcmp( rec[ j ].region, "Europe" ) == 0 ) {
			if( strcmp( rec[ j ].channel, "Online" ) == 0 ) {
				if( rec[ j ].sold > mostOnline ) {
					mostOnline = rec[ j ].sold ; 
					strcpy( itemOn , rec[ j ].item ) ;
					strcpy( countryOn , rec[ j ].country ) ;
				}
			}else if( strcmp( rec[ j ].channel, "Offline" ) == 0 ) {
				if( rec[ j ].sold > mostOffline ) {
					mostOffline = rec[ j ].sold ; 
					strcpy( itemOff , rec[ j ].item ) ;
					strcpy( countryOff , rec[ j ].country ) ;
				}
			}
		}
	}	
	printf( "========= Most sold Online and Offline =========\n" ) ;
	printf( "Most sold Online [ Country ] : %s\n", countryOn ) ;
	printf( "Most sold Online [ Name ] : %s\n", itemOn ) ;
	printf( "Most sold Online [ Units ] : %d\n", mostOnline ) ;
	printf( "Most sold Offline [ Country ] : %s\n", countryOff ) ;
	printf( "Most sold Offline [ Name ] : %s\n", itemOff ) ;
	printf( "Most sold Offline [ Units ] : %d\n", mostOffline ) ;
	printf( "================================================\n" ) ;
	fclose( f ) ;
}

//find least unit sold in Asia  channel type = offline
void leastSold ( char region[ 50 ], char offline[ 10 ] ) {
	FILE *f = fopen( "50 Sales Records.csv", "r" ) ;
	char str[ 1000 ] = "" ;
	info rec[ 5001 ] ;
	char *token ;
	char *delim = "," ;
	int i = 0 ;
	while ( fgets( str, sizeof( str ), f ) != NULL ) {
		//printf( "str = %s", str ) ;
		token = strtok( str, delim ) ;
		int col = 0 ;
		while ( token != NULL ) {
			switch ( col ) {
				case 0 :
					strcpy( rec[ i ].region, token ) ;
					break ;
				case 1 :
					strcpy( rec[ i ].country, token ) ;
					break ;
				case 2 :
					strcpy( rec[ i ].item, token ) ;
					break ;
				case 3 :
					strcpy( rec[ i ].channel, token ) ;
					break ;
				case 4 :
					rec[ i ].priority = token[ 0 ] ;
					break ;
				case 5 :
					strcpy( rec[ i ].Odate, token ) ;
					break ;
				case 6 :
					strcpy( rec[ i ].id, token ) ;
					break ;
				case 7 :
					strcpy( rec[ i ].Shdate, token ) ;
					break ;
				case 8 :
					rec[ i ].sold = atoi( token ) ;
					break ;
				case 9 :
					rec[ i ].price = atof( token ) ;
					break ;
				case 10 :
					rec[ i ].Ucost = atof( token ) ;
					break ;
				case 11 :
					rec[ i ].revenue = atof( token ) ;
					break ;
				case 12 :
					rec[ i ].Tcost = atof( token ) ;
					break ;
				case 13 :
					rec[ i ].profit = atof( token ) ;
					break ;
			}
			col++ ;
			token = strtok( NULL, delim ) ;
		} 
		i++ ;
	}
	
	//check region, channel and find least sold
	int leastOffline ;
	char itemOff[ 30 ], countryOff[ 30 ] ;
	for( int j = 0 ; j < i ; j++ ) {
		if( strcmp( rec[ j ].region, "Asia" ) == 0 ) {
			if( strcmp( rec[ j ].channel, "Offline" ) == 0 ) {
				if( rec[ j ].sold < leastOffline ) {
					leastOffline = rec[ j ].sold ; 
					strcpy( itemOff , rec[ j ].item ) ;
					strcpy( countryOff , rec[ j ].country ) ;
				}
			}
		}
	}	
	printf( "\n======= Least sold in Asia Offline =======\n" ) ;
	printf( "Least sold Offline [ Country ] : %s\n", countryOff ) ;
	printf( "Least sold Offline [ Name ] : %s\n", itemOff ) ;
	printf( "Least sold Offline [ Units ] : %d\n", leastOffline ) ;
	printf( "==========================================\n" ) ;
	fclose( f ) ;
}

//find Top 10 Anime betrayal
void top10 ( char region[ 50 ], char online[ 10 ] ) {
		FILE *f = fopen( "50 Sales Records.csv", "r" ) ;
	char str[ 1000 ] = "" ;
	info rec[ 5001 ] ;
	char *token ;
	char *delim = "," ;
	int i = 0 ;
	int count = 0 ;
	while ( fgets( str, sizeof( str ), f ) != NULL ) {
		//printf( "str = %s", str ) ;
		token = strtok( str, delim ) ;
		int col = 0 ;
		while ( token != NULL ) {
			switch ( col ) {
				case 0 :
					strcpy( rec[ i ].region, token ) ;
					break ;
				case 1 :
					strcpy( rec[ i ].country, token ) ;
					break ;
				case 2 :
					strcpy( rec[ i ].item, token ) ;
					break ;
				case 3 :
					strcpy( rec[ i ].channel, token ) ;
					break ;
				case 4 :
					rec[ i ].priority = token[ 0 ] ;
					break ;
				case 5 :
					strcpy( rec[ i ].Odate, token ) ;
					break ;
				case 6 :
					strcpy( rec[ i ].id, token ) ;
					break ;
				case 7 :
					strcpy( rec[ i ].Shdate, token ) ;
					break ;
				case 8 :
					rec[ i ].sold = atoi( token ) ;
					break ;
				case 9 :
					rec[ i ].price = atof( token ) ;
					break ;
				case 10 :
					rec[ i ].Ucost = atof( token ) ;
					break ;
				case 11 :
					rec[ i ].revenue = atof( token ) ;
					break ;
				case 12 :
					rec[ i ].Tcost = atof( token ) ;
					break ;
				case 13 :
					rec[ i ].profit = atof( token ) ;
					break ;
			}
			col++ ;
			token = strtok( NULL, delim ) ;
		} 
		i++ ;
	}
	
	//swap Units to Most to Least
	for( int j = 1 ; j < i ; j++ ) {
		for( int k = j + 1 ; k < i ; k++ ) {
			if( rec[ j ].Ucost < rec[ k ].Ucost ) {
				info temp = rec[ j ] ;
				rec[ j ] = rec[ k ] ;
				rec[ k ] = temp ;
			}
		}
	}
	
	//check region, channel and find Top 10 Anime betrayal 
	printf( "\n===== Top 10 Unit cost in Central America and the Caribbean on Online =====\n" ) ;
	for( int l = 1 ; l < i ; l++ ) {
		if( strcmp( rec[ l ].region, "Central America and the Caribbean" ) == 0 ) {
			if( strcmp( rec[ l ].channel, "Online" ) == 0 ) {
				printf( "===========================================================================\n") ;
				printf( "[%d]\n", count + 1 ) ;
				printf( "Country [ Name ] : %s\n", rec[ l ].country ) ;
				printf( "Unit [ Name ] : %s\n", rec[ l ].item ) ;
				printf( "Unit [ Cost ] : %.2f\n", rec[ l ].Ucost ) ;
				count++ ;
			}
			if( count == 10 ) {
				printf( "===========================================================================\n" ) ;
				break ;
			}
		}
	}
	fclose( f ) ;
}
