/*#20 (I parcijalni ispit, 2016/2017) Potrebno je unijeti cijeli broj N, pomoću do-while petlje osigurati da je 
N neparan broj veći od 1. Nakon toga na ekranu nacrtati znak + sastavljen od ASCII karaktera, širine i visine N 
znakova, pri čemu su gornji i donji krak sastavljeni od znaka vertikalna linija – pipe (|), lijevi i desni krak od
znaka minus (-) pri čemu se na rubu lijevog kraka nalazi znak manje-od (<) a na rubu desnog kraka znak veće-od (>),
a u sredini se nalazi znak plus (+).*/

#include <stdio.h>

int main() {
	int n,i,j;
	do{
	printf("\nUnesite N: ");
	scanf("%d",&n);
	if(n<1)
	printf("N je manje od 1!");
	else if(n%2==0)
	printf("N je parno!");
	}while(n%2==0 || n<1);
	
	printf("\n");
	for(i=-n/2;i<=n/2;i++){
		for(j=-n/2;j<=n/2;j++){
			if(i==0 && j==0)
			printf("+");
			else
			if(i==0 && j!=-n/2 && j!=n/2)
			printf("-");
			else if(i==0 &&j==-n/2)
			printf("<");
			else if(i==0 &&j==n/2)
			printf(">");
			else if(j==0)
			printf("|");
			else
			printf(" ");
		}
		printf("\n");
	}
	return 0;
}
