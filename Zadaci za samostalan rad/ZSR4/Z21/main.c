/*#21 (Zadaća 1, 2015/2016) Program treba najprije omogućiti unos jednog cijelog broja n. Ako je broj paran, 
ako je manji od 3 ili veći od 100 treba ispisati poruku “Broj je van trazenog opsega” i prekinuti rad programa. 
U suprotnom na ekranu treba iscrtati oblik kao na primjeru ulaza i izlaza ispod, sastavljen od znakova plus (+).*/

#include <stdio.h>

int main() {
	int n,i,j;
	printf("Unesite broj n: ");
	scanf("%d",&n);
	if(n>=3 && n<=100 && n%2!=0){
	for(i=0;i<(3*n-1)/2;i++){
		for(j=0;j<n;j++){
		if(i==(n-1)/2 || i==n-1+((n-1)/2) || (j==0 && i>=(n-1)/2) || (j==n-1 && i>=((n-1)/2)) || (i+(n-1)/2==j) || (i-j==(n-1)/2) || (i+j==(n-1)/2) || (i+j==n-1+(n-1)/2))
		printf("+");
		else
		printf(" ");
		}
		printf("\n");
	}
	}
	else
	printf("\nBroj je van trazenog opsega");
	return 0;
}
