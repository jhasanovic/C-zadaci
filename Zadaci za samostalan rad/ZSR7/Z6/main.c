/*#6 Napisati funkciju int stepen_broja_dva(int n) koja vraća logičku istinu (1) ako je broj n stepen broja 2 te 
logičku neistinu u suprotnom. Npr. za n = 32 treba vratiti 1, a za n = 15 treba vratiti 0. Ni ovdje nemojte 
koristiti funkciju pow.*/
#include <stdio.h>

int stepen_broja_dva(int n){
	if(n==0) return 0;
	while(n>1){
		if(n%2==1){
			return 0;
		}
		n/=2;
	}
	return 1;
}
int main() {
	int n,y;
	printf("Unesite broj: ");
	scanf("%d",&n);
	y=stepen_broja_dva(n);
	printf("%d",y);
	return 0;
}
