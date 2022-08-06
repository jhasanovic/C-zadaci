#include <stdio.h>

int main() {
	int d,m,g;
	printf("Unesite dan, mjesec i godinu (razdvojite razmakom): ");
	scanf("%d %d %d",&d,&m,&g);
	if(d>=1 && d<=31 && m>=1 && m<=12 && g>=1 && g<=4000){
		switch (m){
			case 1:
			printf("Uneseni datum je %d. januar %d. godine",d,g);
			break;
			case 2:
			printf("Uneseni datum je %d. februar %d. godine",d,g);
			break;
			case 3:
			printf("Uneseni datum je %d. mart %d. godine",d,g);
			break;
			case 4:
			printf("Uneseni datum je %d. april %d. godine",d,g);
			break;
			case 5:
			printf("Uneseni datum je %d. maj %d. godine",d,g);
			break;
			case 6:
			printf("Uneseni datum je %d. juni %d. godine",d,g);
			break;
			case 7:
			printf("Uneseni datum je %d. juli %d. godine",d,g);
			break;
			case 8:
			printf("Uneseni datum je %d. august %d. godine",d,g);
			break;
			case 9:
			printf("Uneseni datum je %d. septembar %d. godine",d,g);
			break;
			case 10:
			printf("Uneseni datum je %d. oktobar %d. godine",d,g);
			break;
			case 11:
			printf("Uneseni datum je %d. novembar %d. godine",d,g);
			break;
			case 12:
			printf("Uneseni datum je %d. decembar %d. godine",d,g);
			break;
			
		}
	}
	else
	printf("Pogresni ulazni podaci!");
	return 0;
}