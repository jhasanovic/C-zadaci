#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define delta 0.01

/*probne funkcije*/
double f1 (double x)
{
	return 2*x+2;
}
double g1 (double x)
{
	return 4*x-2;
}
double h1 (double x){ 

	return (f1(x)-g1(x));
}

double presjek (double A, double B, int* status){

double H,n;
	/*sve dok je interval veci od 0.01*/
	
		H=(A+B)/2; /*polovimo interval*/
		if(fabs(h1(H))<=EPSILON && fabs(h1(A))<=EPSILON && fabs(h1(B))<=EPSILON) { /*funkcije identicne*/
			*status=2;
			return 0;
		} else if(fabs(h1(A))<=EPSILON) {
			*status=0;
			return A;
		} else if(fabs(h1(B))<=EPSILON) {
			*status=0;
			return B;
		} else if(fabs(h1(H))<=EPSILON) {
			*status=0;
			return H;
		}
		/*trazimo novi podinterval tamo gdje funkcija mijenja znak*/
		else {

		if(h1(A)*h1(H)<0) {
			n=A; 
			while(n<H){
			if(fabs(h1(n))<=EPSILON){
			*status=0;
			return n; 
			}
			n+=delta;
			}
		} else if(h1(B)*h1(H)<0) {
			n=H;
			while(n<B) {
				if(fabs(h1(n))<=EPSILON){
					*status=0;
					return n; 
				}
				n+=delta; 
		} 
			
		} else {
			 n=A;
			 while(n<B) {
			 	if(fabs(h1(n))<=EPSILON){
			 		*status=0;
			 		return n; 
			 	}
			 	n+=delta; 
			 	
			 	}
			*status=1;
			return 0;
		}
		}
}

int main()
{
	double A,B,rez;
	int adresa=-1;
	printf("Unesite tacke intervala A i B: ");
	scanf("%lf %lf",&A,&B);
	rez=presjek(A,B,&adresa);
	printf("%g %d",rez,adresa);
	return 0;
}