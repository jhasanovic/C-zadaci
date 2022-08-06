/*#7 Napisati program koji od korisnika traži unos najviše 100 elemenata (sa -1 se unos 
prekida). Program zatim od korisnika traži da unese neki broj n i ispituje da li je broj n 
među unesenim brojevima. Ako nije, treba ispisati odgovarajuću poruku, a ukoliko jeste, 
treba reći koji je po redu broj n unesen (gleda se samo prvi unos n broja). */
#include <stdio.h>

int main() {
int i,nadjen=0,indeks;
double niz[100]={0},trazeni=0;
for(i=0;i<100;i++){
printf("Unesite %d. element (-1 za kraj unosa): \n",i+1);
scanf("%lf",&niz[i]);
if(niz[i]==-1)
break;
}

printf("Unesite broj za pretragu: ");
scanf("%lf",&trazeni);
for(i=0;i<100;i++){
	if(niz[i]==trazeni){
	nadjen=1;
	indeks=i+1;
	break;
	}
}
if(nadjen==1)
printf("\nBroj %g je unesen kao %d. broj po redu.",trazeni,indeks);
else
printf("\nBroj %g se ne nalazi medju unesenim brojevima!",trazeni);

	return 0;
}
