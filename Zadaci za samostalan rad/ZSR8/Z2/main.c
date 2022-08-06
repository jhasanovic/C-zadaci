/*#2 Napisati funkciju udvostruci koja će udvostručiti sve elemente niza proslijeđenog kao parametar. Funkcija ne 
vraća ništa, a modificira proslijeđeni joj niz. Parametri funkcije su identični kao i u prethodnom zadatku. Npr. 
za proslijeđeni niz {1, 0, -2} funkcija ga treba modificirati tako da on izgleda {2, 0, -4}.*/
#include <stdio.h>

void udvostruci(int niz[],int n){
	int* p;
	for(p=niz;p<niz+n;p++){
		(*p)*=2;
	}
}

int main() {
	int niz[3]={1,0,-2};
    udvostruci(niz,3);
	return 0;
}
