/*#7 Napisati funkciju armstrong koja za primljeni cjelobrojni parametar n ispituje da li je n Armstrongov broj, 
koji se definiše kao broj od k cifara koji je jednak sumi svih cifara stepenovanih sa k. Npr. za broj 371 treba da 
vrati 1, jer 371 jeste Armstrongov broj (3^3 + 7^3 + 1^3 = 371), korišten je stepen k = 3 jer broj 371 ima 3 cifre. 
Još jedan primjer Armstrongovog broja je 1634 (1^4 + 6^4 + 3^4 + 4^4 = 1634), k = 4.*/
#include <stdio.h>
#include <math.h>

int armstrong(int n){
	int broj=0,temp=n,cifra,suma=0,temp2=n;
	/*nalazi broj cifara*/
	while(temp>0){
		broj++;
		temp/=10;
	}
	while(n>0){
		cifra=n%10;
		suma+=pow(cifra,broj);
		n/=10;
	}
	if(suma==temp)return 1;
	else return 0;

}
int main() {
	int y,n;
	printf("Unesite broj n: ");
	scanf("%d",&n);
	y=armstrong(n);
	printf("%d",y);
	return 0;
}
