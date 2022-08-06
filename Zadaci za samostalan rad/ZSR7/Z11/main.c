/*#11 Napisati funckiju int random(int a, int b) koja vraća neki nasumični broj u intervalu [a, b). Za generisanje 
slučajnih brojeva koristiti rand funkciju iz stdlib.h biblioteke.
Napomena: „pripremanje“ rand funkcije tj. pisanje
srand((unsigned int) time (NULL));
uraditi u main funkciji ili nekoj funkciji koja koristi Random funkciju, prije njenog poziva.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Random(int a,int b){
	return a+rand()%(b-a-1);
}
int main() {
	int a=6,b=15,nasumicni;
	srand((unsigned int)time(NULL));
	nasumicni=Random(a,b);
	printf("%d",nasumicni);
	return 0;
}
