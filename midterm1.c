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

    return 4*pow(-1,j)/(2*j+1) + pi_leibniz (n - 1); //remember to watch types of variables

  }
  else  {

    return 0;

  }
}

void pi_bbp (int);

void pi_bbp (int n)  {

  double i = n;

  // return (/* fill in series shit here as function of i*/) + pi_bbp (n - 1); //remember to watch types of variables
}

int main(void)  {

  int n = 100000;

  printf("%10.10f\n", pi_leibniz (n));

  // pi_bbp (n);


}
