/*#4 Napisati funkciju fibonacci koja prihvata broj n i vraća n-ti Fibonaccijev broj. Npr. za n = 15 funkcija 
treba vratiti broj 610.*/
#include <stdio.h>

int fibonacci(int n){
	if(n==0)return 0;
	else if(n==1)return 1;
	else return (fibonacci(n-1)+fibonacci(n-2));
}
int main() {
	int n,y;
	printf("Unesite broj: ");
	scanf("%d",&n);
	y=fibonacci(n);
	printf("%d-ti Fibonaccijev broj je %d",n,y);
	return 0;
}
