/*#3 Napisati funkciju prva_cifra koja za proslijeđeni parametar n vraća prvu cifru toga broja. Npr. prva_cifra(7392)
; treba da vrati broj 7. Predznak broja zanemariti.*/
#include <stdio.h>

int prva_cifra(int n){
	int prva;
	if(n<0)
	n=-n;
	if(n==0)
	return 0;
	else{
	while(n>0){
		prva=n%10;
		n/=10;
	}
	}
	return prva;
}
int main() {
	int y,n;
	printf("Unesite broj n: ");
	scanf("%d",&n);
	y=prva_cifra(n);
	printf("Prva cifra broja %d je %d",n,y);
	return 0;
}
