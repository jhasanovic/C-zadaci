/*#3 Napisati program koji će od korisnika tražiti unos n realnih elemenata niza 
(ne više od 20) i koji će svaki elemenat niza zaokužiti na 2 decimale. Pri tome se misli 
na pravo zaokruživanje, a ne samo zaokruživanje prilikom ispisa. Tako modificiran niz 
ispisati sa preciznošću na 4 decimalna mjesta, unutar vitičastih zagrada.*/
#include <stdio.h>
#include <math.h>
int main() {
	int greska,n,i;
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

printf("Unesite %d brojeva: ",n);
for(i=0;i<n;i++){
scanf("%lf",&niz[i]);
}

for(i=0;i<n;i++){
	niz[i]*=100;
	niz[i]=round(niz[i]);
	niz[i]/=100;
}

printf("\n");
for(i=0;i<n;i++){
	if(i==0 && n==1)
	printf("{%.4f}",niz[i]);
	else if(i==0)
	printf("{%.4f,",niz[i]);
	else if(i==n-1)
	printf(" %.4f}",niz[i]);
	else
	printf(" %.4f,",niz[i]);
}
return 0;
}