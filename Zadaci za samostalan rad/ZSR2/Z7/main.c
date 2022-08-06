/*#7 Prepraviti prethodni program tako da je ovaj put potrebno izvršiti provjeru vrijednosti diskriminante. 
Ako je vrijednost diskriminante nenegativna, program ima ispis identičan kao u prethodnom zadatku, 
u suprotnom (ako je vrijednost diskriminante negativna), potrebno je ispisati 
„Korijen negativnog broja nema realnih rjesenja!“.*/

#include <stdio.h>
#include <math.h>
int main()
{
    float a,b,c,K,D;
    printf("Unesite koeficijente a, b i c: ");
    scanf("%f %f %f",&a,&b,&c);
    K=sqrt(b*b-4*a*c);
    D=b*b-4*a*c;
    if(D<0)
    printf("Korijen negativnog broja nema realnih rjesenja!");
    else
    printf("Iznos za koeficijente %g, %g i %g je: %g",a,b,c,K);

return 0;
}