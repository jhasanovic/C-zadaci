#include <stdio.h>
#include <stdlib.h>

struct Broj {
	char ime[20];
	char prezime[20];
	char broj[20];
} Niz[1000];

/*ucitati podatke iz datoteke u ovaj niz i vratiti broj ucitanih zapisa*/
int ucitaj_pascal(struct Broj Niz[])
{
	char c;
	int duzina=0;
	int i=0,j=0;
	FILE* ulaz=fopen("imenik.dat","rb");
	if(ulaz==NULL) {
		printf("Pogreska pri otvaranju datoteke imenik.dat");
		return 0;
	}
	c=fgetc(ulaz);/*prvi ucitani znak je duzina stringa*/
	while(c!=EOF) {
		duzina=c;
		/*ucitavanje imena*/
		for(i=0; i<duzina; i++) {
			c=fgetc(ulaz);
			Niz[j].ime[i]=c;
		}
		Niz[j].ime[i]='\0';
		c=getc(ulaz);/*sljedeci bajt koji oznacava duzinu*/
		duzina=c;
		/*ucitavanje prezimena*/
		for(i=0; i<duzina; i++) {
			c=fgetc(ulaz);
			Niz[j].prezime[i]=c;
		}
		Niz[j].prezime[i]='\0';
		c=fgetc(ulaz);
		duzina=c;
		/*ucitavanje broja*/
		for(i=0; i<duzina; i++) {
			c=fgetc(ulaz);
			Niz[j].broj[i]=c;
		}
		Niz[j].broj[i]='\0';
		c=fgetc(ulaz);
		j++;
		if(ferror(ulaz)) {
			printf("Pogreska pri citanju datoteke imenik.dat");
			fclose(ulaz);
			return 0;
		}
	}

	fclose(ulaz);
	return j;/*broj ucitanih*/
}
/*zapisati podatke iz niza u tekstualnu datoteku, svaki u novom redu, odvojeni razmacima*/
void zapisi_txt(struct Broj Niz[],int n)
{
	int i=0;
	FILE* izlaz=fopen("imenik.txt","w");
	if(izlaz==NULL) {
		printf("Pogreska pri otvaranju datoteke imenik.txt");
		exit(0);
	}
	/*pisanje u tekstualnu datoteku*/
	while(i<n) {
		fprintf(izlaz,"%s %s %s\n",Niz[i].ime,Niz[i].prezime,Niz[i].broj);
		i++;
	}
	fclose(izlaz);
}

/*funkcija main samo uzastopno poziva gornje dvije funkcije*/
int main()
{
	int ucitani=ucitaj_pascal(Niz);
	zapisi_txt(Niz,ucitani);
	return 0;
}