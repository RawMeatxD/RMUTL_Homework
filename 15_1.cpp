#include <stdio.h>

double f( double x ) ;
double RootOfFunction( double xl, double xr, double epsilon ) ;

int main() {
 double root ;
 root = RootOfFunction( -1, 10, 0.1 ) ;
 printf( "Root = %.1f", root ) ;
 return 0 ;
}//end function

double f( double x ) {
 return 2 * x - 5 ;
}//end function

double RootOfFunction( double xl, double xr, double epsilon ) {
	double x_mid;
    double f_xl = f(xl); 
    double f_xr = f(xr); 

    while (f(xr - xl) >= epsilon) { 
        x_mid = (xl + xr) / 2.0; 
        double f_xmid = f(x_mid); 

        if (f_xmid == 0.0) { 
            return x_mid; 
        } else if (f_xmid * f_xl < 0) { 
            xr = x_mid; 
            f_xr = f_xmid; 
        } else { 
            xl = x_mid; 
            f_xl = f_xmid; 
        }
    }
    return (xl + xr) / 2.0;
}
