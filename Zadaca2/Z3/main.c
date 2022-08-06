#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001

int main() {
	
	int i,j,t,n,cifra,brojaci[10]={0};
	double niz[1000],novi,ostatak;
	do{
	printf("Unesite broj clanova niza: ");
	scanf("%d",&n);
	}while(n<=0 || n>100);
	printf("Unesite niz: ");

	for(i=0;i<n;i++){
		scanf("%lf",&niz[i]);
	}
	
	for(i=n-1;i>=0;i--){
		for(j=i-1;j>=0;j--){
			if(fabs(niz[i]-(2*niz[j]))<EPSILON){
				n++;
				novi=(niz[i]+niz[j])/2;
				/*Pomjeranje clanova za jedan clan unaprijed*/
				for(t=n;t>=i;t--){
					if(t!=i)
					niz[t-1]=niz[t-2];
					else
					niz[i]=novi;				
					
				}
			}
			j=0;//j se postavi na 0 da bi se prekinula unutrasnja petlja*/
		}
	}
	
	printf("Nakon ubacivanja niz glasi: \n");
	for(i=0;i<n;i++){
		if(i!=n-1)
		printf("%g ",niz[i]);
		else
		printf("%g",niz[i]);
	}
	
	for(i=0;i<n;i++){
		ostatak=niz[i]-(int)niz[i];
		ostatak*=10;
		cifra=(int)ostatak;
	    brojaci[cifra]++;
	}
	
	for(i=0;i<10;i++){
	if(brojaci[i]!=0)
	printf("\nCifra %d se ponavlja %d puta.",i,brojaci[i]);
	}
	return 0;
}