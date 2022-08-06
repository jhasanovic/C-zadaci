/*#13 Napisati program koji od korisnika zahtijeva unos dimenzije kvadratne matrice cijelih brojeva (dimenzija 
ne veće od 50), i elemente matrice. Pri tome osigurati da se matrica unese korektno. Program treba iz matrice 
izbaciti elemente na glavnoj dijagonali ako je n neparno, a ako je parno i sa glavne i sa sporedne dijagonale. 
Matricu treba modifikovati, a ne samo pri ispisu zanemariti elemente na dijagonali. Elemente matrice poravnati 
sa lijevom stranom i ostaviti 5 mjesta za ispis svakog broja.*/

#include <stdio.h>

int main() {
	int n,mat[50][50],i,j;
	printf("Unesite dimenziju matrice:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Unesite elemente %d. reda:\n",i+1);
		j=0;
		while(j<n){
			scanf("%d",&mat[i][j]);
			j++;
		}
	}
int m=n;
int k;
/*izbacivanje sa glavne*/
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(i==j){
				for(k=j;k<m-1;k++){
					mat[i][k]=mat[i][k+1];
				}
				}
			
			}
		}
		m--;
/*izbacivanje i sa sporedne ako je n parno*/

if(n%2==0){
for(i=0; i<n; i++) {
            for(j=0; j<m; j++) {
                if(i<n/2 && i+j==m-1) {
                    for(k=j; k<m-1; k++)
                        mat[i][k]=mat[i][k+1];
                }
               
                if(i>=n/2 && i+j==m) {
                    for(k=j; k<m-1; k++)
                        mat[i][k]=mat[i][k+1];
                }
            }
        }
        m--;
 
}

printf("Matrica nakon izbacivanja dijagonale: \n");
for(i=0;i<n;i++){
	for(j=0;j<m;j++){
	printf("%-5d",mat[i][j]);	
	}
	printf("\n");
}

	return 0;
}
