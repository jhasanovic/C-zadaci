/*#6 Napisati program koji od korisnika traži unos n elemenata niza (ne više od 200),
unos se prekida brojem -1 (koji se ne unosi u niz). Program nakon toga treba pronaći i
ispisati najmanji i drugi najmanji broj u unesenom nizu. */
#include <stdio.h>
#include <math.h>
int main()
{
	int n=0,i;
	double niz[100],min,min2;

	for(i=0; i<100; i++) {
		printf("Unesite %d. element (-1 za kraj unosa): \n",i+1);
		scanf("%lf",&niz[i]);
		if(fabs(niz[i]+1)<0.0001)
			break;
		n++;
	}
	if(n==0) {
		min=0;
		min2=0;
		printf("Najmanji broj je: %g\n",min);
		printf("Drugi najmanji broj je: %g\n",min2);
		return 0;
	}
	min=niz[0];
	for(i=0; i<n; i++) {
		if(niz[i]<min) {
			min=niz[i];
		}
	}
	min2=niz[0];
	for(i=0; i<n; i++) {
		if(niz[i]>min && niz[i]<min2) {
			min2=niz[i];
		}
	}

	printf("Najmanji broj je: %g\n",min);
	printf("Drugi najmanji broj je: %g\n",min2);

	return 0;
}
