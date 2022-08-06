/*#5 Napisati funkciju obrni_cifre koja prihvata pokazivač na početak niza i broj elemenata niza a koja svakom 
elementu niza obrće cifre. Koristiti isključivo pokazivačku aritmetiku. Npr. ako se niz sastoji od elemenata 
123, 101, 31, nakon poziva ove funkcije niz treba da sadrži elemente 321, 101, 13. Pomoć: napraviti pomoćnu funkciju
koja će obrnuti primljeni broj, te je iskoristiti u funkciji obrni_cifre.*/

#include <stdio.h>
#include <math.h>

int pomocna(int broj){
int obrnuti=0,cifra,i=0,flag=0;
if(broj<0){
broj=-broj;
flag=1;
}
while(broj>0){
cifra=broj%10;
broj/=10;
obrnuti=obrnuti*10+cifra;
i++;
}
if(flag==1) return -obrnuti;
return obrnuti;
}

void obrni_cifre(int niz[],int vel){
	int* p;
	for(p=niz;p<niz+vel;p++){
	*p=pomocna(*p);	
	}
}

int main() {
int niz1 [5] = {-11,23,321,918,33};
obrni_cifre(niz1, 5);
int i;
for(i=0; i<5; i++) printf("%d ", niz1[i]);
	return 0;
}
