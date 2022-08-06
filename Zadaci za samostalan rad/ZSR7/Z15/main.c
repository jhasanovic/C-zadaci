/*#15 (Zadaća 3, 2016/17) Napišite funkciju pod imenom daj_prost koja nema parametara, a svaki put kada se pozove
vraća sljedeći prost broj. Kada prvi put pozovete funkciju, ona treba vratiti broj 2, drugi put treba vratiti broj
3, zatim broj 5, 7, 11 itd.
Ovu funkciju iskoristite u programu koji omogućuje korisniku da unese prirodne brojeve A i B takve da je A<B,
a zatim ispisuje sumu svih prostih brojeva strogo većih od A a strogo manjih od B. U ovom programu se obavezno mora
iskoristiti napravljena funkcija daj_prost, ne smiju se računati prosti brojevi na neki drugi način.*/

#include <stdio.h>

int daj_prost()
{
	long long i,j;
	int flag=0;
	static long long sljedeci;
	static int poziv=0;
	if (poziv==0)
		sljedeci=2;
	for (i = sljedeci; i <= 1000000; i++) {
		flag = 1;
		for (j = 2; j <= i / 2; j++) {
			if (i % j == 0) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			sljedeci=i;
			break;
		}
	}
	sljedeci++;
	poziv++;
	return i;
}
int main()
{
	long long a,b,suma=0,broj=0;
	do{
	printf("Unesite brojeve A i B: ");
	scanf("%lld %lld",&a,&b);
	if(!(a<b))
	printf("A nije manje od B.\n");
	else if(a<=0)
	printf("A nije prirodan broj.\n");
	}while(!(a<b) || a<=0);
	do{
		broj=daj_prost();
		if(broj>a && broj<b){
		suma+=broj;
		}
	}while(broj<b);
	printf("Suma prostih brojeva izmedju %lld i %lld je %lld.",a,b,suma);
	return 0;
}
