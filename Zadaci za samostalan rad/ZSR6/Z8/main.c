/*#8 Prepraviti prethodni zadatak tako da ispisuje poziciju posljednjeg unesenog broja 
kojeg pretražuje. U primjeru 1 iz prethodnog zadaka za broj 7 bi trebalo ispisati da je 
unesen kao 6. broj po redu.*/
#include <stdio.h>

int main() {
int i,nadjen=0,indeks,n=0;
double niz[100]={0},trazeni=0;
for(i=0;i<100;i++){
printf("Unesite %d. element (-1 za kraj unosa): \n",i+1);
scanf("%lf",&niz[i]);
if(niz[i]==-1)
break;
n++;
}

printf("Unesite broj za pretragu: ");
scanf("%lf",&trazeni);
for(i=0;i<n;i++){
	if(trazeni==niz[i]){
	nadjen=1;
	indeks=i+1;
	}
}
if(nadjen==1)
printf("\nBroj %g je unesen kao %d. broj po redu.",trazeni,indeks);
else
printf("\nBroj %g se ne nalazi medju unesenim brojevima!",trazeni);

	return 0;
}

