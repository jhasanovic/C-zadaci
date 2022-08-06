#include <stdio.h>
#include <stdlib.h>

struct Prodavnica {
	char naziv[100];
	int ID;
};

struct Artikal {
	char naziv[100];
	double cijena;
	int prodavnica;//ovo je ID prodavnice
};

int ucitaj_artikle(struct Artikal *niz,int kap)
{
	FILE* ulaz = fopen("artikli.bin", "rb");
	if (ulaz == NULL) {
		printf("Greska pri otvaranju datoteke.");
		return 1;
	}
	int ucitani=fread(niz,sizeof(struct Artikal),kap,ulaz);
	fclose(ulaz);
	return ucitani;
}
int ucitaj_prodavnice(struct Prodavnica *niz,int kap)
{
	int ucitani;
	FILE* ulaz = fopen("prodavnice.txt", "r");
	if (ulaz == NULL) {
		printf("Greska pri otvaranju datoteke.");
		return 1;
	}
	int i=0;
	while(i<kap && fscanf(ulaz,"%100s %d\n",niz[i].naziv,&niz[i].ID)==2);
	i++;
	ucitani=i;
	fclose(ulaz);
	return ucitani;
}
int main()
{
	struct Artikal niz[100];
	struct Prodavnica prodavnice[100];
	int ucitani=ucitaj_artikle(niz,100);
	printf("%d\n",ucitani);
	int prodavnice_ucitane=ucitaj_prodavnice(prodavnice,100);
	printf("%d\n",prodavnice_ucitane);
	return 0;
}
