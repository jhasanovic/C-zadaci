/*#11 Diskretizacija predstavlja pridruživanje prebrojivog skupa vrijednosti funkciji, 
na način da se određenom broju vrijednosti x koordinate pridružuje vrijednost funkcije 
u toj tački. Vrijednosti xi se biraju na osnovu određenog koraka diskretizacije, koji 
određuje razmak između susjednih x vrijednosti. Napišite program koji ispisuje skup od n 
elemenata koji se dobiju diskretizacijom funkcije y=x3+5x2-7x+14, sa korakom k. Vrijednosti 
n i k se unose sa tastature. Sa tastature se također unosi i početna vrijednost x. */

#include <stdio.h>

int main() {
	int i;
	float n,k,x,rez;
	printf("Unesite n: ");
	scanf("%f",&n);
	printf("Unesite korak diskretizacije: ");
	scanf("%f",&k);
	printf("Unesite pocetnu vrijednost x: ");
	scanf("%f",&x);
	
	printf("x     y=f(x)\n");
	printf("------------\n");
	for(i=0;i<n;i++){
		rez=x*x*x+5*x*x-7*x+14;
		printf("%.1f %8.2f\n",x,rez);
		x+=k;
	}
	return 0;
}
