/*#13 (Zadaća 3, 2012/13; Završni ispit 2015/16) Napisati funkciju sa sljedećim prototipom:
int* istecifre(int* niz, int vel, int* p)
Prva dva parametra funkcije opisuju niz cijelih brojeva (pokazivač na prvi element i veličina niza), dok je treći
parametar p pokazivač na neki element tog niza. Funkcija treba vratiti pokazivač na onaj član niza koji ima iste
cifre u istom broju kao element na koji pokazuje pokazivač p. Tako npr. ako p pokazuje na broj 411, funkcija može
vratiti pokazivač na neki drugi član niza čija je vrijednost također 411, a može vratiti i pokazivače na 141 ili
114, ali ne treba vratiti pokazivač na 14, 441, 4141 (iste cifre, ali ne isti broj tih cifara), 321 (ista suma
cifara ali nisu iste cifre) itd..
Ako se u nizu nalazi više elemenata koji zadovoljavaju uslov zadatka, funkcija treba vratiti pokazivač na prvi
takav element koji se nalazi nakon elementa na koji pokazuje p. Ako do kraja niza nema odgovarajućih elemenata,
ali ih ima prije pokazivača p, onda funkcija treba vratiti pokazivač na prvi odgovarajući element od početka niza.
Konačno, ako se u nizu ne nalazi niti jedan element koji zadovoljava uslove zadatka, funkcija treba vratiti
primljeni pokazivač p.*/

#include <stdio.h>

int* istecifre(int* niz, int vel, int* p)
{
	if(vel==1) return p;//ako je u nizu samo jedan clan, ne treba ni traziti
	int hist1[10]= {0},hist2[10]= {0}; //histogram za clan niza na koji pokazuje p
	int temp,temp2,cifra,flag=0,j;
	int* i;
	temp=*p;
	temp2=*niz;
	while(temp>0) {
		cifra=temp%10;
		hist1[cifra]++;
		temp/=10;
	}
	/*popuniti histogram za svaki sljedeci, provjeriti odmah je li isti*/
	for(i=niz; i<niz+vel; i++) {
		flag=0;
		if(i!=p) { //preskociti zadati
			temp2=*i;
			while(temp2>0) { //popuniti histogram trenutnog
				cifra=temp2%10;
				hist2[cifra]++;
				temp2/=10;
			}
			for(j=0; j<10; j++) { //poredjenje histograma
				if(hist1[j]!=hist2[j]) {
					flag=-1;//nije isti, predji na sljedeci
					for(j=0; j<10; j++) {
						hist2[j]=0;
					}
					break;
				}
			}
			if(flag==0) {
			break;
		}
		}
		
	}
	if(flag==-1) return p;
return i;
}

int main()
{
	int niz[] = {1, 2, 3, 411, 4, 321, 144, 4141, 141, 6};
	int*p = istecifre(niz, 10, niz+3);
	printf("Broj %d pozicija %d", *p, (int)(p-niz));
	return 0;
}
