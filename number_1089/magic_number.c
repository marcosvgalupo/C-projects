#include <stdio.h>

int main(void) {
  int n, ninv, x, xinv, y, caso = 0, c1, u1, d1, maior, menor, c2, d2, u2,
      z;
  for (n = 123; n <=987; n++) {

    c1= n/100, d1=(n % 100)/10, u1=(n % 100)%10;
    if ((c1!=d1)&&(c1!=u1)&&(u1!=d1)&&(c1!=0)&&(u1 != 0) &&(d1 != 0)){
      ninv = c1 + (10 * d1) + (100 * u1);
      if (n>ninv) {
        maior = n, menor = ninv;
      } else {
        maior = ninv, menor = n;
      }
      x=maior-menor;
      c2=x/100, d2=(x%100)/10, u2=(x%100)%10;
      xinv=((c2)+(10*d2)+(100*u2));
      z = x+xinv;
      caso++;
     printf("caso %3i: %i-%i=%3i, %3i+%i=%i\n", caso, maior, menor, x, x, xinv, z);
    } else {
    }
  }
}
