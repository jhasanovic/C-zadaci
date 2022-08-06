/*#5 Napisati funkciju double stepen (double b, int e) koja vraća potenciju broja be bez korištenja funkcije pow. 
Funkcija treba da radi i sa negativnim eksponentom.*/

#include <stdio.h>
#include <math.h>
double stepen(double b,int e){
	double suma=1;
	if(fabs(e)<0.0001)return 1;
	else{
		if(e<0) {
			b=1/b;
			e=-e;
		}
	while(e>0){
		suma=suma*b;
		e--;
	}
	return suma;
	}
}
int main() {
	int e;
	double b,y;
	printf("Unesite broj: ");
	scanf("%lf",&b);
	printf("Unesite stepen broja: ");
	scanf("%d",&e);
	y=stepen(b,e);
	printf("%g",y);
	return 0;
}
