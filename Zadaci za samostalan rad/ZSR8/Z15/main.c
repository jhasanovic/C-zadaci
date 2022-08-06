/*#15 (Zadaća 3, 2012/13) Napisati funkciju sa prototipom:void crtanje(int niz[], int vel)
Funkcija prima niz sa parnim brojem elemenata koji su pozitivni cijeli brojevi. Svaki par elemenata u nizu
predstavlja: ASCII vrijednost znaka koji treba ispisati na ekranu i broj puta koliko se taj znak treba ponoviti.
Npr. niz 65,2,98,3,33,1 treba dati rezultat: "AAbbb!" (bez navodnika). Za prelazak u novi red možete koristiti ASCII
kod 13. Ako niz ne zadovoljava uslove zadatka, funkcija se treba samo prekinuti bez ispisivanja ičega, a nipošto ne
prekoračiti dimenzije niza.
Zatim ovu funkciju iskoristite u funkciji: void pravougaonik(int a, int b, int znak)
Koja na ekranu iscrtava šuplji pravougaonik širine a i visine b znakova, iscrtan pomoću znaka čija je ASCII vrijednost
znak. Postavite razumno ograničenje na veličinu a i b. U funkciji pravougaonik se funkcija crtanje smije pozvati tačno
jednom, a zabranjeno je pozivati funkciju printf! Konačno, napravite i main koji omogućava unos vrijednosti a i b i
zatim iscrtava odgovarajući pravougaonik koristeći znak zvjezdica (*).*/
#include <stdio.h>

void crtanje(int niz[],int vel)
{
	//velicina niza treba biti parna i svi brojevi trebaju biti pozitivni cijeli brojevi
	int* i;
	int temp,broj,brojac=0,flag=0;
	for(i=niz; i<niz+vel; i++) {
		if(*i<0) {
			flag=1;
			break;
		}
		brojac++;
	}
	if(flag==0 && brojac%2==0) {
		for(i=niz; i<niz+vel;) { //na prvom je clanu
			temp=*i;
			i++;//sad je na drugom
			broj=*i;
			while(broj>0) {
				printf("%c",temp);
				broj--;
			}
			i++;
		}
	}
}

void pravougaonik(int a,int b,int znak)
{
	int niz[100];
	int velicina=4,i=0,sirina=a,visina=b,razmak;
	razmak=sirina-2;
	for(i=0; i<20;) {
		if(i==0) {
			niz[i]=znak;
			niz[i+1]=a;
			niz[i+2]=13;
			niz[i+3]=1;
			i+=4;
		} 
		else{
			niz[i]=znak;
			i++;
			niz[i]=1;
			i++;
			while(razmak>0){
			niz[i]=32;//razmak ispisati (a-2) puta
			i++;
			razmak--;
			}
			niz[i]=znak;
			i++;
			niz[i]=1;
			i++;
			niz[i]=13;
			i++;
			niz[i]=1;
			i++;
		}
	}
	crtanje(niz,4);
	//a je broj znakova po x-sirina
	//b je broj znakova po y-visina
	//void crtanje se poziva samo jednom, u niz se ubacuje znak,a,novi red,(visina-2)*(znak,(sirina-2)razmaka,znak),
	//znak,a,novi,red
	//popunjavanje niza
}
int main()
{
	int niz[]= {65,2,98,3,33,1};
	crtanje(niz,6);
	printf("\n");
	pravougaonik(5,3,63);
	return 0;
}
