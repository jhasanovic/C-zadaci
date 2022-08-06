/*#14 (Završni ispit 2016/2017, Zadaća 2 2015/2016) Napisati program koji omogućuje unos kvadratne matrice cijelih
brojeva dimenzija NxN (N nije veće od 100). Korisnik najprije unosi broj N (do-while petljom osigurati da je u
traženom opsegu), zatim unosi elemente matrice. Zatim se ispisuje vrsta matrice, tj. jedan od sljedećih tekstova:
Nul-matrica (čiji su svi elementi 0)
Jedinicna matrica (dijagonalna matrica na čijoj dijagonali su svi elementi jedinice),
Dijagonalna matrica (kod koje su svi elementi van glavne dijagonale 0)
Gornja trougaona matrica (kod koje su svi elementi ispod glavne dijagonale 0)
Donja trougaona matrica (kod koje su svi elementi iznad glavne dijagonale 0)
Sporedna dijagonalna matrica (matrica kod koje su svi elementi van sporedne dijagonale 0)
Nista od navedenog*/

#include <stdio.h>

int main()
{
	int mat[100][100],i=0,j=0,nula=1,jedinica=1,dijagonalna=1,gornja=1,donja=1,sporedna=1,n=0;
	printf("Unesite broj N: ");
	scanf("%d",&n);
	printf("Unesite elemente matrice: \n");
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			scanf("%d",&mat[i][j]);
		}
	}
	/*provjera da li je nula matrica*/
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			if(mat[i][j]!=0) {
				nula=0;
				break;
			}
		}
		if(nula==0)
			break;
	}
	if(nula==1) {
		printf("Nul-matrica");
		return 0;
	}
	/*provjera da li je jedinicna matrica*/
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			if(i==j && mat[i][j]!=1) {
				jedinica=0;
				break;
			}
		}
		if(jedinica==0)
			break;
	}
	if(jedinica==1) {
		printf("Jedinicna matrica");
		return 0;
	}
	/*provjera da li je dijagonalna*/
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			if(i!=j && mat[i][j]!=0) {
				dijagonalna=0;
				break;
			}
		}
		if(dijagonalna==0)
			break;
	}
	if(dijagonalna==1) {
		printf("Dijagonalna matrica");
		return 0;
	}
	/*provjera da li je gornja trougaona*/
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			if(j<i && mat[i][j]!=0) {
				gornja=0;
				break;
			}
		}
		if(gornja==0)
			break;
	}
	if(gornja==1) {
		printf("Gornja trougaona matrica");
		return 0;
	}
	/*provjera da li je donja trougaona*/
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			if(i<j && mat[i][j]!=0) {
				donja=0;
				break;
			}
		}
		if(donja==0)
			break;
	}
	if(donja==1) {
		printf("Donja trougaona matrica");
		return 0;
	}
	/*provjera da li je sporedna dijagonalna*/
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			if((i+j)!=(n-1) && mat[i][j]!=0) {
				sporedna=0;
				break;
			}
		}
		if(sporedna==0)
			break;
	}
	if(sporedna==1) {
		printf("Sporedna dijagonalna matrica");
		return 0;
	}
	printf("Nista od navedenog");
	return 0;
}
