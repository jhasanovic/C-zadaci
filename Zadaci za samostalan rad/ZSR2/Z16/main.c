/*#16 Napisati program koji od korisnika traži da unese 3 cijela broja, te provjerava da li su ti brojevi u
nekom od sljedećih intervala: [-20, -8], [-1, 1], [40, 50], [77, 101]. Program za svaki broj treba da ispiše
kojem intervalu pripada odnosno da ne pripada niti jednom intervalu. Na kraju, program treba da ispiše da li 
svi uneseni brojevi pripadaju jednom te istom intervalu.*/
//greska u autotestu 2
#include <stdio.h>

int main() {
	int a,b,c,flaga=5,flagb=6,flagc=7;
	printf("Unesite tri cijela broja: ");
	scanf("%d %d %d",&a,&b,&c);
	if(a>=-20 && a<=-8){
	printf("Broj %d pripada intervalu [-20, -8]",a);
	flaga=1;
	}
	else if(a>=-1 && a<=1){
	printf("Broj %d pripada intervalu [-1, 1]",a);
	flaga=2;
	}
	else if(a>=40 && a<=50){
	printf("Broj %d pripada intervalu [40, 50]",a);
	flaga=3;
	}
	else if(a>=77 && a<=101){
	printf("Broj %d pripada intervalu [77, 101]",a);
	flaga=4;
	}
	else 
	printf("Broj %d ne pripada niti jednom intervalu",a);
	
	if(b>=-20 && b<=-8){
	printf("\nBroj %d pripada intervalu [-20, -8]",b);
	flagb=1;
	}
	else if(b>=-1 && b<=1){
	printf("\nBroj %d pripada intervalu [-1, 1]",b);
	flagb=2;
	}
	else if(b>=40 && b<=50){
	printf("\nBroj %d pripada intervalu [40, 50]",b);
	flagb=3;
	}
	else if(b>=77 && b<=101){
	printf("\nBroj %d pripada intervalu [77, 101]",b);
	flagb=4;
	}
	else
	printf("\nBroj %d ne pripada niti jednom intervalu",b);
	
	if(c>=-20 && c<=-8){
	printf("\nBroj %d pripada intervalu [-20, -8]",c);
	flagc=1;
	}
	else if(c>=-1 && c<=1){
	printf("\nBroj %d pripada intervalu [-1, 1]",c);
	flagc=2;
	}
	else if(c>=40 && c<=50){
	printf("\nBroj %d pripada intervalu [40, 50]",c);
	flagc=3;
	}
	else if(c>=77 && c<=101){
	printf("\nBroj %d pripada intervalu [77, 101]",c);
	flagc=4;
	}
	else
	printf("\nBroj %d ne pripada niti jednom intervalu",c);
	
	if(flaga==flagb && flaga==flagc)
	printf("\nSvi brojevi pripadaju jednom intervalu.");
	else
	printf("\nSvi brojevi ne pripadaju jednom te istom intervalu.");
	return 0;
}
