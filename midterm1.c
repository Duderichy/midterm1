/*
This program contains two important functions which are recursive and calculate
the value of pi to a certain accuracy depending on the number of terms used
*/

#include <stdio.h>
#include <math.h>

double pi_leibniz (int);

double pi_leibniz (int n)  {
  // The parameter of the function is the number of the terms in the series to keep.
  double j = n;

  if (n >= 0)  {

    return 4*pow(-1,j)/(2*j+1) + pi_leibniz (n - 1);

  }
  else  {

    return 0;

  }
}

double pi_bbp (int);

double pi_bbp (int n)  {

  double j = n;

  if ( n >= 0 ) {

  return (1 / pow ( 16 , j ) ) * ( 4 / ( 8 * j + 1) - 2 / ( 8 * j + 4) - 1 / ( 8 * j + 5) - 1 / ( 8 * j + 6)) + pi_bbp (n - 1);

  }
  else {

    return 0;

  }
}

int main(void)  { // j and n are just used as iteration variables n

  int n = 100;

  printf("%10.20f\n", pi_leibniz (n) );

  printf("%10.20f\n", pi_bbp (n) );

}
