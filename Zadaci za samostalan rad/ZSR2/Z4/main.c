/*#4 Napisati program koji će pitati korisnika da unese neki broj u rasponu od 0 do 9. 
Od korisnika se očekuje da unese jednocifren prirodan broj, tako da vi ne trebate vršiti provjeru. 
Nakon toga program treba ispisati taj broj u sredini okružen zvjezdicama 
(5 zvjezdica u širini, 5 u visini osim u srednjem redu).*/

#include <stdio.h>

int main() {
	int n,i,j;
	printf("Unesite prirodan broj u intervalu [0, 9]: ");
	scanf("%d",&n);
	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(i==2 && (j==0 || j==4))
			printf("*");
			else if(i==2 && (j==1 || j==3))
			printf(" ");
			else if(i==2 && j==2)
			printf("%d",n);
			else
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
