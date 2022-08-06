/*#3 Napisati funkciju void sortiraj(double niz[], int n) koja sortira elemente niza u opadajućem poretku koristeći 
Selection sort algoritam sa predavanja.*/
#include <stdio.h>

void sortiraj(double niz[],int n){
	double* p;
	double* q;
	double* max;
	double temp;
	for(p=niz;p<niz+n;p++){
	max=p;
	for(q=p+1;q<niz+n;q++){
		if(*max<*q)
		max=q;
	}
	temp=*p;
	*p=*max;
	*max=temp;
	}
}
int main() {
	int n=3,i;
	double niz[3]={1,0,-2};
    sortiraj(niz,3);
    for(i=0;i<n;i++){
    printf("%g ",niz[i]);	
    }
	return 0;
}
