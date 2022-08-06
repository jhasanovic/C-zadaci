/*#5 Napisati program koji od korisnika traži unos n, broj elemenata niza (najviše 100). 
Nakon toga korisnik unosi elemente u niz, a program treba da iz niza izbaci sve parne 
elemente. Elemente izbacivati uz očuvanje redoslijeda (tako da se na njihovo mjesto 
pomjere ostali elementi). Program treba da ispiše novonastali niz kao i sumu njegovih 
elemenata.*/
#include <stdio.h>
#include <math.h>
int main() {
	int greska,n,i,j;
	int niz[100],suma=0;
	do{
		greska=0;
printf("Unesite broj elemenata niza: ");
scanf("%d",&n);
if(n<0 || n>100){
printf("Unos neispravan!\n");
greska=1;
}
}while(greska==1);

printf("Unesite %d brojeva: ",n);
for(i=0;i<n;i++){
scanf("%d",&niz[i]);
}

/*izbacivanje parnih clanova iz niza*/

for(i=0;i<n;i++){
	if(niz[i]%2==0){
	for(j=i;j<n-1;j++){
		niz[j]=niz[j+1];
	}
		n--;
		i--;
	}
	
	else
	suma+=niz[i];
	}

printf("Niz je: ");
for(i=0;i<n;i++){
	printf(" %d,",niz[i]);
}
printf("\nSuma je: %d",suma);
return 0;
}