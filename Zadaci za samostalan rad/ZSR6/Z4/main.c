/*#4 Modificirati prethodni program tako da korisnik pored unosa elemenata niza unosi i 
broj decimala na koje želi zaokružiti elemente niza kao i broj decimala za ispis.*/
#include <stdio.h>
#include <math.h>
int main() {
	int greska,n,i,zaokruzivanje,ispis;
	double niz[100];
	do{
		greska=0;
printf("Unesite broj elemenata niza: ");
scanf("%d",&n);
if(n<1 || n>20){
printf("Unos neispravan!\n");
greska=1;
}
}while(greska==1);

printf("Unesite %d brojeva: \n",n);
for(i=0;i<n;i++){
scanf("%lf",&niz[i]);
}
printf("Unesite broj decimala za zaokruzivanje: ");
scanf("%d",&zaokruzivanje);
printf("Unesite broj decimala za ispis: ");
scanf("%d",&ispis);

for(i=0;i<n;i++){
	niz[i]*=pow(10,zaokruzivanje);
	niz[i]=round(niz[i]);
	niz[i]/=pow(10,zaokruzivanje);
	if(niz[i]==-0)
	niz[i]=0;
}


for(i=0;i<n;i++){
	if(i==0 && n==1)
	printf("{%.*f}",ispis,niz[i]);
	else if(i==0)
	printf("{%.*f,",ispis,niz[i]);
	else if(i==n-1)
	printf(" %.*f}",ispis,niz[i]);
	else
	printf(" %.*f,",ispis,niz[i]);
}
return 0;
}