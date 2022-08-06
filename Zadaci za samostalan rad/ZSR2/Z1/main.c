/*#1 Napisati program koji „precizno“ računa 4. korijen unesenog broja. 
Potrebno je osigurati preciznost na preko 12 decimalnih mjesta. 
Korisnik unosi broj, program računa 4. korijen i ispisuje ga na 10 decimalnih mjesta.*/

#include <stdio.h>
#include <math.h>

int main() {
	double broj,korijen;
	printf("Unesi broj: ");
	scanf("%lf",&broj);
	korijen=sqrt(sqrt(broj));
	printf("4. korijen iz broja %g je %.10f",broj,korijen);
	return 0;
}
