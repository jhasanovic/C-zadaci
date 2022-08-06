/*#6 Napišite program koji računa vrijednost korijena diskriminante K= sqrt(b*b-4ac). 
Unose se koeficijenti a, b i c. Također se pretpostavlja da su svi uneseni koeficijenti pozitivni 
(nije potrebno provjeravati) i da diskriminanta ima rješenje u skupu realnih brojeva 
(drugim riječima pod korijenom se neće naći negativan broj, tj.pretpostavimo da uvijek vrijedi b*b≥4ac).*/

#include <stdio.h>
#include <math.h>
int main()
{
    float a,b,c,K;
    printf("Unesite koeficijente a, b i c: ");
    scanf("%f %f %f",&a,&b,&c);
    K=sqrt(b*b-4*a*c);
    printf("Iznos za koeficijente %g, %g i %g je: %g",a,b,c,K);

return 0;
}

