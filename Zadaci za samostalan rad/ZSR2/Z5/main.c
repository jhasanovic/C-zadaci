/*#5 Prepraviti prethodni zadatak tako da korisnik može birati koji broj će biti ispisan u sredini,
ali isto tako da može birati znak kojim će taj broj biti okružen.*/

/*#4 Napisati program koji će pitati korisnika da unese neki broj u rasponu od 0 do 9. 
Od korisnika se očekuje da unese jednocifren prirodan broj, tako da vi ne trebate vršiti provjeru. 
Nakon toga program treba ispisati taj broj u sredini okružen zvjezdicama 
(5 zvjezdica u širini, 5 u visini osim u srednjem redu).*/
/*HINT: unosi se prvo znak, pa broj, jer bi u suprotnom program protumacio ENTER
koji pritisnemo nakon unosa kao znak*/
/*----------------RJESENJE: ostaviti razmak ispred %c-------------------------*/

#include <stdio.h>

int main() {
	int n,i,j;
	char znak;
	printf("Unesite znak kojim ce broj biti okruzen: ");
	scanf("%c",&znak);
	printf("Unesite prirodan broj u intervalu [0, 9]: ");
	scanf("%d",&n);
	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(i==2 && (j==0 || j==4))
			printf("%c",znak);
			else if(i==2 && (j==1 || j==3))
			printf(" ");
			else if(i==2 && j==2)
			printf("%d",n);
			else
			printf("%c",znak);
		}
		printf("\n");
	}
	return 0;
}
