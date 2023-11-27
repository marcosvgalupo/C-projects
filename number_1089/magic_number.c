#include <stdio.h>

int main(void) {
  int n, y, cases = 0, greater, smaller, c2, d2, u2, z;
  
  for (n = 123; n <=987; n++) {

    int c1 = n/100, d1 = (n % 100)/10, u1 = n%100%10;

    if (c1!=d1 && c1!=u1 && u1!=d1 && c1!=0 && u1 != 0 && d1 != 0){
      
      int ninv = c1 + (10 * d1) + (100 * u1);
      
      if (n > ninv) greater = n, smaller = ninv;
      else greater = ninv, smaller = n;
  
      int x = greater - smaller;
      int c2 = x/100, d2 = (x%100)/10, u2 = (x%100)%10;
      int xinv = ( c2 + 10 * d2 + 100 * u2);
      
      z = x + xinv;
      cases++;
      
     printf("case %3i: %i-%i=%3i, %3i+%i=%i\n", cases, greater, smaller, x, x, xinv, z);
    } 
  }
  return 0;
}
