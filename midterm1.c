/*
This program contains two important functions which are recursive and calculate
the value of pi to a certain accuracy depending on the number of terms used
*/

// Started out using recusive algorihims, it was a bad idea, switched to for loops

#include <stdio.h>
#include <math.h>
#include "timer.h"
#include "adjust.h"

double pi_leibniz (int);

double pi_leibniz (int n)  {

  // The parameter of the function is the number of the terms in the series to keep.
  // This function uses Leibniz's series for estimating pi using n terms

  double j;
  double pi = 0;

  for (j = 0; j <= n; j++)  {

    pi = 4 * pow ( -1 ,j ) / ( 2 * j + 1 ) + pi;

  }

  return pi;

}

double pi_bbp (int);

double pi_bbp (int n)  {

  // The parameter of the function is the number of the terms in the series to keep.
  // This function uses the Bailey-Borwein-Plouffe series to estimate pi using n terms

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

  do { //doubles the amount of terms in the pi_leibniz series until error is less than 10^-6

    pi = pi_leibniz (i);

    abserr = fabs (pi - M_PI);

    printf ("%8d   %20.15f   %20.15f\n", i, pi, abserr);

    i *= 2;

  } while ( abserr > tol );

  i = 1;

  do { //doubles the amount of terms in the pi_bbp series until error is less than 10^-6

    pi = pi_bbp (i);

    abserr = fabs (pi - M_PI);

    printf ("%8d   %20.15f   %20.15f\n", i, pi, abserr);

    i *= 2;

  } while ( abserr > tol );

  // end of code figuring out number of terms needed for 10^-6 accuracy

  int count = 10;
  double time;
  double time1;
  double tmin = 1;
  double tmax = 2;

  printf("pi_leibniz\n");

  do {
      timer_start ();

      for (int k = 0; k <= count; k++) {

        pi_leibniz (1048576);

      }

      time = timer_stop ();

      time1 = time / count;

      printf (" %10.2f usec     %10.6f sec    %10d\n",
          time1 * 1.e6, time, count);

      /*
       * adjust count such that cpu time is between
       * tmin and tmax
       */

      count = adjust_rep_count (count, time, tmin, tmax);


  } while ((time > tmax) || (time < tmin));

  printf("pi_pbb\n");

  do {

      timer_start ();

      for (int k = 0; k < count; k++) {

        pi_bbp (4);

      }

      time = timer_stop ();

      time1 = time / count;

      printf (" %10.2f usec     %10.6f sec    %10d\n", time1 * 1.e6, time, count);

      /*
       * adjust count such that cpu time is between
       * tmin and tmax
       */

      count = adjust_rep_count (count, time, tmin, tmax);

  } while ((time > tmax) || (time < tmin));

  return 0;

}
