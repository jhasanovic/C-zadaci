#include <stdio.h>
#include <stdlib.h>

struct Datum {
	int datum,mjesec,godina;
};

struct Student {
	char ime [20],prezime[20];
	struct Datum datum_rodjenja;
};

/*funkcija koja vraca broj dana koje treba dodati ako je godina prestupna*/
int broj_prestupnih(int g,int m)
{
	int broj_dana;
	if(m>2)
		broj_dana=g/4-g/100+g/400;
	else
		broj_dana=(g-1)/4-(g-1)/100+(g-1)/400;
	return broj_dana;
}
/*naci broj dana od 0. do prve godine - broj dana od 0. do druge godine, abs uporediti sa d*/
int dodatni(int m)
{
	int broj_dana_prije_m=0;
	/*januar ne uzimamo u obzir, za njega samo dodajemo dan na sumu u funkciji period*/
	switch(m) {
	case 12:
		broj_dana_prije_m=30;
	case 11:
		broj_dana_prije_m+=31;
	case 10:
		broj_dana_prije_m+=30;
	case 9:
		broj_dana_prije_m+=31;
	case 8:
		broj_dana_prije_m+=31;
	case 7:
		broj_dana_prije_m+=30;
	case 6:
		broj_dana_prije_m+=31;
	case 5:
		broj_dana_prije_m+=30;
	case 4:
		broj_dana_prije_m+=31;
	case 3:
		broj_dana_prije_m+=28;
	case 2:
		broj_dana_prije_m+=31;
	case 1:
		broj_dana_prije_m+=0;
		break;
	}
	return broj_dana_prije_m;
}
void period(struct Student Niz[],int n,int d)
{
	int i=0,j=0,prije_prve=0,prije_druge=0,broj_dana_prije1=0,broj_dana_prije2=0,prestupne=0;
	for(i=0; i<n; i++) {
		prestupne=broj_prestupnih(Niz[i].datum_rodjenja.godina,Niz[i].datum_rodjenja.mjesec);
		broj_dana_prije1=dodatni(Niz[i].datum_rodjenja.mjesec);
		prije_prve=Niz[i].datum_rodjenja.godina*365+prestupne+broj_dana_prije1+Niz[i].datum_rodjenja.datum;

		for(j=i+1; j<n; j++) {
			prestupne=broj_prestupnih(Niz[j].datum_rodjenja.godina,Niz[j].datum_rodjenja.mjesec);
			broj_dana_prije2=dodatni(Niz[j].datum_rodjenja.mjesec);
			prije_druge=Niz[j].datum_rodjenja.godina*365+prestupne+broj_dana_prije2+Niz[j].datum_rodjenja.datum;

			if(abs(prije_prve-prije_druge)==d)/*razlika je d, ispisati par*/
				printf("%s %s - %s %s\n",Niz[i].ime,Niz[i].prezime,Niz[j].ime,Niz[j].prezime);
		}

	}
}
/*funkcija koja zapisuje u binarnu datoteku studenti.dat, dan i mjesec 1 bajt, godina 2 bajta*/
void zapisi(struct Student Niz[],int n)
{
	int i=0;
	unsigned char dat,mj;
	unsigned short god;
	remove("studenti.dat");/*brisanje prethodnog sadrzaja, posto je mod ab*/
	FILE* izlaz=fopen("studenti.dat","ab");
	if(izlaz==NULL) {
		printf("Greska pri otvaranju datoteke studenti.dat");
		exit(0);
	}
	while(i<n) {
		fwrite(Niz[i].ime,sizeof(Niz[i].ime),1,izlaz);
		fwrite(Niz[i].prezime,sizeof(Niz[i].prezime),1,izlaz);
		dat=(unsigned char)Niz[i].datum_rodjenja.datum;
		fwrite(&dat,sizeof(unsigned char),1,izlaz);
		mj=(unsigned char)Niz[i].datum_rodjenja.mjesec;
		fwrite(&mj,sizeof(unsigned char),1,izlaz);
		god=(unsigned short)Niz[i].datum_rodjenja.godina;
		fwrite(&god,sizeof(unsigned short),1,izlaz);
		i++;

		if(ferror(izlaz)) {
			printf("Greska pri pisanju u datoteku studenti.dat");
			fclose(izlaz);
			exit(0);
		}
	}
	fclose(izlaz);
}

/*funkcija promijeni prima jednog studenta i redni broj, te u datoteci studenti.dat mijenja zapis tog studenta,
tako da umjesto njega zapise studenta koji je prvi parametar funkcije promijeni*/
void promijeni(struct Student izmjena, int redni)
{
	unsigned char dat,mj;
	unsigned short god;
	FILE* izlaz=fopen("studenti.dat","r+b");
	if(izlaz==NULL) {
		printf("Greska pri otvaranju datoteke studenti.dat");
		exit(0);
	}
	/*44=ime(20)+prezime(20)+datum(1)+mjesec(1)+godina(2)*/
	fseek(izlaz,redni*44,SEEK_SET);/*kursor je na pocetku imena studenta koji treba promijeniti*/
	fwrite(&izmjena.ime,sizeof(izmjena.ime),1,izlaz);
	fwrite(&izmjena.prezime,sizeof(izmjena.prezime),1,izlaz);
	dat=(unsigned char)izmjena.datum_rodjenja.datum;
	fwrite(&dat,sizeof(unsigned char),1,izlaz);
	mj=(unsigned char)izmjena.datum_rodjenja.mjesec;
	fwrite(&mj,sizeof(unsigned char),1,izlaz);
	god=(unsigned short)izmjena.datum_rodjenja.godina;
	fwrite(&god,sizeof(unsigned short),1,izlaz);

	if(ferror(izlaz)) {
		printf("Greska pri izmjeni datoteke studenti.dat");
		fclose(izlaz);
		exit(0);
	}
	fclose(izlaz);
}

int main()
{
	struct Student niz[] = {
		{ "Sara", "Sarac", { 18, 2, 1998} },
		{ "Pero", "Peric", { 31, 11, 1999} },
		{ "Aleksandar", "Sasic", { 31, 12, 1997} },
		{ "Ana-Marija", "Anic-Marijic", { 1, 1, 1999} }
	};
	struct Student izmjena = { "Meho", "Mehic", { 1, 1, 1998} };
	period(niz,4,49);
	zapisi(niz,4);
	promijeni(izmjena,2);
	return 0;
}
