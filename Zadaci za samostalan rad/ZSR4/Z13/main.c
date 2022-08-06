/*#13 Napisati program koji ispisuje na ekranu jediničnu matricu dimenzije n, pri čemu se broj n unosi sa tastature. 
Pri tome je od korisnika potrebno tražiti da unese dodatni parametar r, koji će definisati format ispisa matrice, 
tako da između svake susjedne kolone bude r praznih mjesta. (Pri rješavanju zadatka nemojte koristiti nizove ni 
matrice!)*/

#include <stdio.h>

int main() {
	int n,r,i,j;
	printf("Unesite n: ");
	scanf("%d",&n);
    printf("Unesite sirinu ispisa: ");
	scanf("%d",&r);
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
		if(i==j)
		printf("%*d",r,1);
		else
		printf("%*d",r,0);
		}
		printf("\n");
	}
	return 0;
}
