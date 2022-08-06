/*#11 (Zadaća 2 2013/2014) Napisati program koji omogućuje unos proizvoljnog broja pozitivnih
cijelih brojeva (maksimalno 100, a minimalno 3 elementa) u niz A. Unos se prekida unosom 
broja -1. Program treba provjeriti da li je uneseni niz v-niz. V-niz je niz kod kojeg su svi 
elementi najprije strogo opadajući do nekog elementa koji je minimum niza, a nakon njega su 
svi elementi strogo rastući. Ako je minimum prvi ili posljednji član niza, taj niz se ne 
smatra v-nizom.*/

#include <stdio.h>
int main() {
	int niz[100],i,j,vel,br=0;
	
	do{
	for(i=0;i<100;i++){
		scanf("%d",&niz[i]);
		if(niz[i]==-1){
			vel=i;
			br++;
			break;
		
		}
		
	}
	if(br!=0 && vel>=3)break;
	if(vel<3){printf("Nedovoljno elemenata\n");
		return 0;
	}
	
	}while(1);
	
	br=0;
	int min;
	int tacno=1;
	for(i=0;i<vel;i++){
		
		if(niz[i]>niz[i+1]){
			min=0;
		}
		else min = 1;
		
		//nasao minimum
		if(min==1){
			for(j=i;j<vel-1;j++){
				//rastuci mora biti od j
				if(niz[j]>niz[j+1]) {tacno=0;
				break;}
			}
		}
		
		if(tacno==0) break;
		if(min==1) break;
	} 
	
	if(min==0) tacno = 0 ;
	
	if(tacno) printf("Niz je v-niz");
	else printf("Niz nije v-niz");
	
	return 0;
}