/*#9 Napisati program koji od korisnika traži unos dva niza (sa najviše od 50 elemenata), 
unos se prekida sa -1. Program u treći niz treba da smjesti elemente koji se javljaju i u 
prvom i u drugom nizu, bez ponavljanja. Konkretnije, ako nizove smatramo skupovima, 
program treba da nađe presjek dva skupa. Paziti da presjek može biti prazan skup, tj. da 
treći niz može imati nula elemenata. Također, iza posljednjeg elementa niza prilikom ispisa 
nema znaka zarez. */

#include <stdio.h>
#include <math.h>

int main() {
	double niz1[100],niz2[100],niz[100];
	int i,j,k=0,br1=0,br2=0,m;
	printf("Unesite elemente 1.niza (-1 kraj): \n");
	for(i=0;i<100;i++){
		scanf("%lf",&niz1[i]);
		if(fabs(niz1[i]+1)<0.0001)
		break;
		br1++;
	}
    printf("Unesite elemente 2.niza (-1 kraj): \n"); 
    for(i=0;i<100;i++){
		scanf("%lf",&niz2[i]);
		if(fabs(niz2[i]+1)<0.0001)
		break;
		br2++;
	}
	
	for(i=0;i<br1;i++){
		for(j=0;j<br2;j++){
		if(fabs(niz1[i]-niz2[j])<0.000001){
		niz[k]=niz1[i];
		k++;
		}
		}
	}
	
	if(k==0){
	printf("Presjek unesenih nizova je prazan skup!");
	return 0;
	}
	else{
		/*iz krajnjeg niza izbacimo sve iste*/
 for(i = 0; i < k; i++)
    {
        for(j = i+1; j < k; )
        {
            if(fabs(niz[j]-niz[i])<0.00001)
            {
                for(m = j; m < k; m++)
                {
                    niz[m] = niz[m+1];
                }
                k--;
            }
            else
            {
                j++;
            }
        }
    }

 
}
printf("Presjek unesenih nizova je: ");

for(i=0;i<k;i++){
	if(i==k-1)
	printf("%g",niz[i]);
	else
	printf("%g, ",niz[i]);
}

	return 0;
}
