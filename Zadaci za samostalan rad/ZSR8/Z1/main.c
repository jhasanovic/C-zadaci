/*#1 Napisati funkciju ispisi koja će ispisivati niz unutar vitičastih zagrada pri čemu su elementi razdvojeni 
znakom zarez. Funkcija prihvata dva parametra, niz (tačnije, pokazivač na prvi elemenat niza) i cijeli broj n koji 
predstavlja broj elemenata niza. */

#include <stdio.h>

void ispisi(int niz[],int n){
	int* p;
	if(n==0){
		printf("{}");
	}
	else{
	for(p=niz;p<niz+n;p++){
	    if(p==niz)
		printf("{%d, ",*p);
		else if(p==niz+n-1)
		printf("%d}",*p);
		else
		printf("%d, ",*p);
	}
	}
}
int main() {
	int niz1[] = {1,2,3};
	ispisi(niz1, 3);
	return 0;
}
