/*#2 Napisati program koji od korisnika traži unos n realnih elemenata niza 
(ne više od 100) koji će te elemente ispisati sortirane od manjeg ka većem unutar 
vitičastih zagrada, razdvojene znakom zarez (iza posljednjeg elementa nema znaka zarez). 
Ukoliko je broj n van opsega, ponovo tražiti unos. */
#include <stdio.h>

int main() {
	int greska,n,i,j,min;
	double niz[100],temp;
	do{
		greska=0;
printf("Unesite broj elemenata niza: ");
scanf("%d",&n);
if(n<1 || n>50){
printf("Unos neispravan!\n");
greska=1;
}
}while(greska==1);

printf("Unesite %d brojeva: ",n);
for(i=0;i<n;i++){
scanf("%lf",&niz[i]);
}

for(i=0;i<n;i++){
	min=i;
	for(j=i+1;j<n;j++){
	if(niz[j]<niz[min])	
	min=j;
	}
	temp=niz[i];
	niz[i]=niz[min];
	niz[min]=temp;
}
printf("\n");
for(i=0;i<n;i++){
	if(i==0 && n==1)
	printf("{%g}",niz[i]);
	else if(i==0)
	printf("{%g,",niz[i]);
	else if(i==n-1)
	printf(" %g}",niz[i]);
	else
	printf(" %g,",niz[i]);
}
return 0;
}