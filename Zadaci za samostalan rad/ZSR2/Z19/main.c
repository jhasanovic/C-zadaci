#include <stdio.h>

int main() {
	int h,m;
	double cijena,nova;
	printf("Unesite trenutno vrijeme (hh:mm): ");
	scanf("%d:%d",&h,&m);
	printf("Unesite cijenu robe (KM): ");
	scanf("%lf",&cijena);
	if(h>=8 && (h<17 || (h==17 && m==0))){
		if(cijena<15){
		nova=cijena+cijena*0.15;
		printf("Cijena je uvecana za 15%% i iznosi %gKM.",nova);
		}
		else if(cijena>=15 && cijena<=45){
			nova=cijena-4;
			printf("Cijena je smanjena za 4KM i iznosi %gKM.",nova);
		}
		else if(cijena>45){
		nova=cijena-cijena*0.12;
		printf("Cijena je smanjena za 12%% i iznosi %gKM.",nova);
		}
		
	}
	else
	printf("Uneseno vrijeme je van radnog vremena prodavnice. ");
	return 0;
}
