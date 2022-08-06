/*#9 Napisati funkciju int dec2bin(short dec) koja pretvara decimalni broj u njegovu binarnu reprezentaciju. 
Treba obratiti pažnju da se u tip int može smjestiti samo 10 binarnih cifara pa ne treba funkciji prosljeđivati 
brojeve veće od 210 – 1. Primjer, dec2bin (777) treba da vrati 1100001001, dok dec2bin (1023) treba da vrati 
1111111111. (1023 je najveći broj koji se smije prosljeđivati funkciji.)*/
#include <stdio.h>
#include <math.h>

int dec2bin(short dec){
    int	i=1,binarni=0,cifra;
	while(dec>0){
		cifra=dec%2;
		binarni+=cifra*i;
		dec/=2;
		i*=10;
	}
	return binarni;
}
int main() {
	int n,y;
	printf("Unesite broj: ");
	scanf("%d",&n);
	y=dec2bin(n);
	printf("Broj %d u binarnom zapisu je %d",n,y);
	return 0;
}
