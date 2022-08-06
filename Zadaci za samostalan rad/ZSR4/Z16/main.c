/*#16 Napisati program koji za uneseno n ispisuje dvije simetrične strelice (u ogledalu) dimenzija 2n × n. 
Ukoliko je n manje od 2, program treba ispisati grešku i završiti s radom.*/
#include <stdio.h>

int main() {
	int i,j,n;
	printf("Unesite n: ");
	scanf("%d",&n);
	if(n<2){
	printf("Neispravan unos");
	return 0;
	}
	
	for(i=1;i<=2*n-1;i++){
		for(j=1;j<=2*n+1;j++){
		if(i<=n){
		if(j<=n && j>i)
		printf(" ");
		else if(j>n && i+j<=2*n+1)
		printf(" ");
		else if(i==n && j==n+1)
		printf(" ");
		else
		printf("*");
		}
		else{
			if(i+j<=2*n)
			printf("*");
			else if(j-i>1)
			printf("*");
			else
			printf(" ");
		}
		}
		printf("\n");
	}
	return 0;
}
