/*#12 Dopuniti prethodni zadatak tako da pored vrijednosti funkcije u tački x, računa i vrijednost izvoda. 
Vrijednost izvoda izračunajte Eulerovim metodom konačnih razlika, po formuli: y'=y'(xi)= yi+1-yi∆x , gdje yi 
predstavlja vrijednost funkcije y u tački i, a ∆x predstavlja razliku vrijednosti x u kojima računamo yi+1 i yi.*/

#include <stdio.h>

int main() {
	int i;
	float n,k,x,rez,izvod;
	printf("Unesite n: ");
	scanf("%f",&n);
	printf("Unesite korak diskretizacije: ");
	scanf("%f",&k);
	printf("Unesite pocetnu vrijednost x: ");
	scanf("%f",&x);
	
	printf("x     y=f(x)   y'\n");
	printf("-------------------\n");
	for(i=0;i<n;i++){
		rez=x*x*x+5*x*x-7*x+14;
		izvod=2*x*x+10*x-7;
		printf("%-6.1f%-7.2f %.2f\n",x,rez,izvod);
		x+=k;
	}
	return 0;
}
