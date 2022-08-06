/*#15 Napisati program koji ispisuje tablicu kvadrâta brojeva iz intervala [a b] sa korakom k. Korisnik unosi 
granice intervala a i b, korak k, te širinu ispisa i broj decimala koje će program ispisivati.*/
#include <stdio.h>
#include <math.h>
#define EPSILON 0.00001

int main() {
	int sirina,dec,i;
	double a,b,k,x,kvadrat;
	
printf("Unesite interval [a b]: "); 
scanf("%lf %lf",&a,&b);
printf("Unesite korak: ");
scanf("%lf",&k);
printf("Unesite sirinu ispisa: ");
scanf("%d",&sirina);
printf("Unesite broj decimala: ");
scanf("%d",&dec);

printf("X");
for(i=1;i<=2*sirina-3;i++){
	printf(" ");
}
printf("X^2\n");
for(i=1;i<=2*sirina+1;i++){
printf("-");
}
printf("\n");
x=a;
while(x < b || fabs(x-b) < EPSILON){
	kvadrat=x*x;
	printf("%-*.*f|%*.*f\n",sirina,dec,x,sirina,dec,kvadrat);
	x+=k;
}
	return 0;
}
