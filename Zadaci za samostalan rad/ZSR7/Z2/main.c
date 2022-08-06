/*#2 Napisati funkciju vrati_najveci_stepen koja prihvata cijeli broj n, a vraća najveći stepen broja 2 koji je 
manji ili jednak broju n. Primjer, za n = 35 funkcija treba vratiti 5 jer je broj 32 najveći broj koji je stepen 
broja 2 (25 = 32) a koji je manji ili jednak n tj. od 35.*/
#include <stdio.h>

int vrati_najveci_stepen(int n){
	int stepen=0;
	while(n>1){
		n/=2;
		stepen++;
	}
	return stepen;
}
int main() {
	int n,y;
	printf("Unesi n: ");
	scanf("%d",&n);
	y=vrati_najveci_stepen(n);
	printf("Najveci stepen broja %d je %d",n,y);
	return 0;
}
