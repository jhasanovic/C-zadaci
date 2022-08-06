/*#10 (Zadaća 2 2013/2014) Napisati program koji omogućuje da se izračuna medijan rezultata
studenata na nekom ispitu. Najprije je potrebno unijeti broj studenata koji su pristupili
ispitu (maksimalno 500). Nakon toga se unose bodovi ostvareni na ispitu koji predstavljaju
realni broj u opsegu [0,20]. Ukoliko se unese broj van ovog intervala, potrebno je ispisati
poruku "Rezultat ispita nije u trazenom intervalu" i prekinuti rad programa. Nakon završenog
unosa potrebno je ispisati medijan. Medijan nekog niza brojeva dužine n je takva vrijednost
za koju je barem n/2-1 članova niza manje ili jednako tom medijanu, a barem n/2-1 ih je
veće ili jednako. Ukoliko je broj članova niza neparan, medijan je onaj član niza koji
zadovoljava uslov zadatka, a ukoliko je paran za medijan se uzima aritmetička sredina dva
člana niza koja su najbliža medijanu.*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int br_studenata, i, j;
	float rez[500], medijan, temp;
	printf("Unesite broj studenata: ");
	scanf("%d", &br_studenata);
	if(br_studenata<=500) {
		printf("Unesite bodove na ispitu: ");
		for(i=0; i<br_studenata; i++) {
			scanf("%f", &rez[i]);
			if(rez[i]<0 || rez[i]>20)
				break;
		}
//U slucaju da nema greske pri unosu:
		if(br_studenata==i) {
//sortiramo niz "rez"
			for(i=0; i<br_studenata; i++)
				for(j=i; j<br_studenata; j++) {
					if(rez[i]>rez[j]) {
						temp=rez[i];
						rez[i]=rez[j];
						rez[j]=temp;
					}
				}
//Ako je neparan broj:
			if(br_studenata%2!=0) {
				medijan=rez[(br_studenata-1)/2];
			}
//Ako je paran broj:
			else {
				medijan=(rez[br_studenata/2]+rez[(br_studenata-1)/2])/2;
			}
			printf("Medijan je: %.1f", medijan);
		} else printf("Rezultat ispita nije u trazenom intervalu");
	} else printf("Broj studenata je veci od granica niza");
	return 0;
}
