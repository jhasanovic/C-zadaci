/*#14 (Zadaća 3, 2014/15; Završni ispit 2016/17) Napišite funkciju sa prototipom:
int broj_sadrzan(unsigned int a, unsigned int b)
koja prima dva pozitivna cijela broja a i b čije su vrijednosti u opsegu dozvoljenih vrijednosti tipa unsigned int,
a vraća logičku istinu (cijeli broj 1) ako je broj b sadržan u broju a, a logičku neistinu (cijeli broj 0) ako nije.
Npr. u broju 2358 sadržan je broj 35.
Napravite i main funkciju koja omogućuje da se unesu dva cijela broja, poziva funkciju broj_sadrzan, te ispisuje
tekst ISTINA ili NEISTINA ovisno od toga šta je funkcija vratila.*/

#include <stdio.h>
#include <math.h>
int broj_sadrzan(unsigned int a, unsigned int b)
{
	/*broj b treba biti sadrzan u broju a*/
	int zadnja_cifra=b%10;
	int pomb,poma;
	int cifra1,cifra2;
	if(a==b) return 1;
	while(a!=0){
		pomb=b;
		poma=a;
		cifra2=poma%10;
		cifra1=pomb%10;
		if (cifra2==zadnja_cifra) {
			while (cifra1==cifra2 && pomb!=0 && poma!=0) {
				pomb=pomb/10;
				poma=poma/10;
				cifra1=pomb%10;
				cifra2=poma%10;
			}
			if (pomb==0) return 1;
		}
		a=a/10;
	}
	return 0;
}
int main()
{
	int a,b,rezultat=-1;
	printf("Unesite broj a: ");
	scanf("%d",&a);
	printf("Unesite broj b: ");
	scanf("%d",&b);
	rezultat=broj_sadrzan(a,b);
	if(rezultat==0)
		printf("NEISTINA");
	else if(rezultat==1)
		printf("ISTINA");
	return 0;
}
