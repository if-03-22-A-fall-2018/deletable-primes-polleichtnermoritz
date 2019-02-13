#include "deletable_primes.h"
#include <math.h>
/*----------------------------------------------------------
 *				HTBLA-Leonding / Class
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			deletable_primes.c
 * Author:			P. Bauer
 * Due Date:		October 16, 2012
 * ----------------------------------------------------------
 * Description:
 * Implementation of deletable_primes.h.
 * ----------------------------------------------------------
 */

 unsigned long remove_digit(int index, unsigned long n)
 {
   long numPow=pow(10,index);
   return (n/(numPow*10))*numPow+(n%numPow);
 }

 int get_ways(unsigned long p)
 {
   int way=0;

  if(p<10 && is_prime(p))
  {
    return 1;
  }
  else if(p<10 && !is_prime(p))
  {
    return 0;
  }

  for (int i = 0; i < get_lenght(p); i++)
  {
    if(is_prime(remove_digit(i,p)))
    {
      way+=get_ways(remove_digit(i,p));
    }
  }
  return way;
 }

 bool is_prime(unsigned long p)
 {
   if (p <= 1 || (p % 2 == 0 && p > 2))
   {
     return false;
   }

   for(int i = 3; i <= sqrt(p); i+= 2)
   {
     if (p % i == 0)
        return false;
   }

   return true;
 }

 int get_lenght(unsigned long n)
 {
  int lenght=0;

  while (n>1) {
    n/=10;
    lenght++;
  }
  return lenght;
}
