/*#12 Napisati funkciju int potpun_kvadrat(int a) koja vraća vrijednost 1 ako je broj a potpun kvadrat (a je kvadrat
nekog broja), a vraća vrijednost 0 u suprotnom. Na primjer, za broj 64 će biti vraćena vrijednost 1, jer je 64 = 82.
U slučaju da se funkciji proslijedi negativan broj, zanemariti predznak te nastaviti rad kao da je proslijeđen
pozitivan broj.*/
#include <stdio.h>
#include <math.h>

int potpun_kvadrat(int a)
{
	if(a<0) a=-a;
	int n=sqrt(a);
	if(n*n==a)return 1;
	return 0;
}
int main()
{
	int a;
	printf("Unesite broj: ");
	scanf("%d",&a);
	printf("%d",potpun_kvadrat(a));
	return 0;
}
