/*

*/

#include <stdio.h>
#include <math.h>

double pi_leibniz (int);

double pi_leibniz (int n)  {
  // The parameter of the function is the number of the terms in the series to keep.
  double i = n;

  return (-1)^i/(2i+1) + double pi_leibniz (int n - 1); //remember to watch types of variables

}

double pi_bbp (int);

double pi_bbp (int n)  {

  double i = n;

  return (/* fill in series shit here*/) + double pi_bbp (int n - 1); //remember to watch types of variables
}

int main(void)  {

  int n;

  double pi_leibniz (int n);

  double pi_bbp (int);


}
