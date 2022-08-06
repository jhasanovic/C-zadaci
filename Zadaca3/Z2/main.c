#include <stdio.h>
#include <math.h>

double stepen(double x)
{
	static int brojac=1;
	static double zapamti=0;
	double rez=1;
	int temp;
	if(fabs(zapamti-x)>=0.0001) /*ako argument kojim se funkcija poziva nije isti kao prethodni, kreni od pocetka*/
		brojac=1;
	temp=brojac;
	while(temp>0) {
		rez=rez*x;
		temp--;
	}
	brojac++;/*spremljen broj poziva istim argumentom*/
	zapamti=x;/*spremljen posljednji argument kojim je funkcija pozvana*/

	return rez;
}

void stepenuj_niz(double A[], int s[], int duzina)
{
	int i,brojac;
	double temp;
	//double* p=A;
	//double* q=p+1;
	/*stepenovanje niza A*/
	for(i=0; i<duzina; i++) {
		brojac=0;
		/*if(fabs(*p-*q)<0.001) {ako je prethodni clan niza A isti kao trenutni
		   brojac++;
		   p++;
		   q++;
			}*/
		temp=A[i];
		while(s[i]>0) {
			A[i]=stepen(temp);
			s[i]--;
		}
		/*if(brojac!=0)
		A[i]/=*p;*/
	}
}


int main()
{
	double A[1000];
	int s[1000],duzina,i;

	printf("Unesite duzinu nizova: ");
	scanf("%d",&duzina);

	printf("Unesite niz A: ");
	for(i=0; i<duzina; i++) {
		scanf("%lf",&A[i]);
	}

	printf("Unesite niz s: ");
	for(i=0; i<duzina; i++) {
		scanf("%d",&s[i]);
	}

	stepenuj_niz(A,s,duzina);
	for(i=0; i<duzina; i++) {
		printf("%g ",A[i]);
	}
	return 0;
}
