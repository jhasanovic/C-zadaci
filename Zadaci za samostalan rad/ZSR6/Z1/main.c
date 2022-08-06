/*#1 Napisati program koji od korisnika traži da unese n, broj elemenata niza 
(ne više od 50). Ukoliko je n izvan opsega ispisati poruku i zatražiti ponovni unos. 
Zatim se unosi n brojeva koje će ispisati u obrnutom redoslijedu od redoslijeda unosa. 
Elemente ispisivati razdvojene znakom zarez. */
#include <stdio.h>

int main() {
	int greska,n,i;
	double niz[100];
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

printf("\n");
for(i=n-1;i>=0;i--){
	printf(" %g,",niz[i]);
}
return 0;
}