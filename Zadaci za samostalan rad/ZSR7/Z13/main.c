/*#13 Napisati funkciju int korijen (int a) koja radi slično kao i funkcija potpun_kvadrat iz prethodnog zadatka, 
s tim da funkcija korijen treba da vrati vrijednost korijena broja koji joj se šalje. Pri tome analizirati samo 
brojeve koji su potpuni kvadrati, a za ostale brojeve vratiti vrijednost -1.*/
#include <stdio.h>
#include <math.h>

int korijen(int a){
	int jeste=-1;
	/*provjera da li je potpun kvadrat*/
	int n=sqrt(a);
	if(n*n==a)
	jeste=1;
	else jeste=0;
	if(jeste==1) return sqrt(a);
	else return -1;
}

int main() {
printf("%d", korijen(25));
	return 0;
}
