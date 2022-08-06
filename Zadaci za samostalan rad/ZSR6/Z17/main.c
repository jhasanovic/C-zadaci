/*#17 (Zadaća 2, 2016/2017) Zamislimo da na ekranu imamo koordinatni sistem sastavljen od 20x20 mjesta. Ishodište
koordinatnog sistema je u gornjem lijevom uglu i ono odgovara koordinatama (0,0).
Omogućite korisniku da unese najviše 10 tačaka koristeći koordinate [0,19]. Zatim iscrtajte oblik sastavljen od
znakova zvjezdica (asterisk) na onim koordinatama koje je korisnik unio, a na ostalim lokacijama prazno mjesto. U
slučaju da je unesen neispravan broj tačaka ili koordinate izvan dozvoljenog opsega treba ispisati poruku "Pogresan
unos" i zatražiti da se ponovo unese broj tačaka odnosno koordinate te tačke.*/

#include <stdio.h>

int main()
{
	int n,i=0,j,t,tacke[10][2]={0};
	char mat[20][20]={0};
	do {
		printf("Unesite broj tacaka: ");
		scanf("%d",&n);
	} while(n>10 || n<0);
	for(i=0; i<n; i++) {
		for(j=0; j<1; j++) {
			printf("Unesite %d. tacku: ",i+1);
			scanf("%d %d",&tacke[i][j],&tacke[i][j+1]);
		}
	}
	for(i=0; i<20; i++) {
		for(j=0; j<20; j++) {
			for(t=0; t<n; t++) { //(n,2)
				if(tacke[t][0]==j && tacke[t][1]==i)
				    mat[i][j]='*';	
			}
		}
	}
	for (i=0; i<20; i++) {
        for (j=0; j<20; j++) {
            if (mat[i][j]==0) printf(" ");
            else printf("%c",mat[i][j]);
        }
        printf ("\n");
    }
	return 0;
}
