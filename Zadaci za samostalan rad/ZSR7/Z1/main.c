/*#1 Napisati funkciju ocisti bez parametara koja čisti ulazni tok nakon pogrešnog unosa. Pored toga, napisati 
funkciju unesi koja unosi cijeli broj sa tastature. Ako unos nije ispravan (unesu se slova, realan broj), funkcija
treba očistiti ulazni tok (pozivom funkcije ocisti) te zatražiti ponovni unos. Konačno, napisati funkciju prosjek 
koja prima cijeli broj, a vraća prosjek cifara proslijeđenog broja. Npr. sljedeći poziv
double d = prosjek(324); u varijablu d treba staviti vrijednost 3 jer je to prosjek cifara.*/
#include <stdio.h>
#include <math.h>

void ocisti()
{
	while(getchar()!='\n') {}
}
double prosjek(long long n)
{
	int cifra,suma=0,broj=0;
	double p;
	if(n==0) return 0;
	while(n>0) {
		cifra=n%10;
		n/=10;
		suma+=cifra;
		broj++;
	}
	p=suma/broj;
	return p;
}
int main()
{
	double n,a;
	int greska;
	long long poziv;
	do {
		greska=0;
		printf("Unesite cijeli broj: ");
		a=scanf("%lf",&n);
		if(a!=1 || (n-(long long int)n)!=0 ) {
			greska=1;
			printf("Unos pogresan!\n");
			ocisti();
		}
	} while(greska==1);
poziv=(long long)n;
	printf("Prosjek je: %g",prosjek(poziv));

	return 0;
}
