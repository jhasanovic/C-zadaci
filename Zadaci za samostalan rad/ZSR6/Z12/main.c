/*#12 Napisati program koji od korisnika traži unos broja n (ne veći od 50) koji predstavlja 
dimenziju matrice formata n × n. Program treba popuniti matricu tako da na glavnoj dijagonali 
budu nule, ispod dijagonale (paralelno sa glavnom dijagonalom) su elementi popunjeni sa -1, 
-2, ..., -n, dok su elementi iznad glavne dijagonale (paralelno sa njom) popunjeni sa 1, 2, 
..., n. */
#include <stdio.h>

int main() {
	int n,i,j;
	printf("Unesite n: \n");
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j) printf("%4d",0);
			if(j>i) printf("%4d",j-i);
			if(j<i) printf("%4d",j-i);
		}
		printf("\n");
	}

	return 0;
}
