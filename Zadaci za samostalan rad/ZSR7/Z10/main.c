/*#10 Napisati funkciju short bin2dec(int bin) koja pretvara binarni broj u njegovu decimalnu reprezentaciju. 
Iskoristiti iste primjere kao u prethodnom zadatku.*/
#include <stdio.h>
#include <math.h>

short bin2dec(int bin){
	int i=0,suma=0,cifra,temp=bin;
	if(bin<0)bin=-bin;
	while(bin!=0){
		cifra=bin%10;
		bin/=10;
		if(cifra==1)
		suma+=pow(2,i);
		i++;
	}
	if(temp<0)
	suma=-suma;

	return suma;
}
int main() {
	int n,y;
	printf("Unesite broj: ");
	scanf("%d",&n);
	y=bin2dec(n);
	printf("Broj %d u decimalnom zapisu je %d",n,y);
	return 0;
}
