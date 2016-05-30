/*
This program contains two important functions which are recursive and calculate
the value of pi to a certain accuracy depending on the number of terms used
*/

// Started out using recusive algorihims, it was a bad idea, switched to for loops

#include <stdio.h>
#include <math.h>

double pi_leibniz (int);

double pi_leibniz (int n)  {
  // The parameter of the function is the number of the terms in the series to keep.
  double j;
  double pi = 0;

  for (j = 0; j <= n; j++)  {

    pi = 4*pow(-1,j)/(2*j+1) + pi;

  }

  return pi;

}

double pi_bbp (int);

double pi_bbp (int n)  {

  double j;
  double pi = 0;

  for (j = 0; j <= n; j++)  {

    pi = (1 / pow ( 16 , j ) ) * ( 4 / ( 8 * j + 1) - 2 / ( 8 * j + 4) - 1 / ( 8 * j + 5) - 1 / ( 8 * j + 6)) + pi;

  }

  return pi;
}

int main(void)  { // j and n are just used as iteration variables n

  int i = 1;

  double pi;

  double abserr;

  double tol = pow ( 10 , -6 );

  do {

    pi = pi_leibniz (i);

    abserr = fabs (pi - M_PI);

    printf ("%8d   %20.15f   %20.15f\n", i, pi, abserr);

    i *= 2;

  } while ( abserr > tol );

  i = 1;

  do {

    pi = pi_bbp (i);

    abserr = fabs (pi - M_PI);

    printf ("%8d   %20.15f   %20.15f\n", i, pi, abserr);

    i *= 2;

  } while ( abserr > tol );

  //printf("%10.20f\n", pi_leibniz (n) );

  //printf("%10.20f\n", pi_bbp (n) );

}
