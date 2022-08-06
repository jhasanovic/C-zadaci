/*#2 Napisati program koji od korisnika traži unos ocjena iz 5 predmeta te računa prosjek tih ocjena.
Ocjene su u intervalu [6, 10] i to nije potrebno provjeravati.
Potrebno je ispisati zbir unesenih ocjena i prosjek zaokružen na 2 decimalna mjesta.*/

#include <stdio.h>

int main()
{
	int a,b,c,d,e,zbir;
	float prosjek;
	printf("Unesite 5 ocjena: ");
	scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
	zbir=a+b+c+d+e;
	prosjek=(float)zbir/5;
	printf("Zbir unesenih ocjena je %d, a prosjek je: %.2f",zbir,prosjek);
	return 0;
}
