#include <stdio.h>

int main() {
	int n,brojac=1,i;
	char znak,c;
	printf("Unesite broj: ");
	scanf("%d",&n);
	if(n<1){
		printf("Pogresan unos");
		return 0;
	}
	FILE* ulaz=fopen("input.txt","r");
	if(ulaz==NULL){
		printf("Pogreska kod otvaranja datoteke input.txt!");
		return 1;
	}
	FILE* izlaz=fopen("output.txt","w");
	if(izlaz==NULL){
		printf("Pogreska kod otvaranja datoteke output.txt!");
		return 2;
	}
	c=getc(ulaz);
	while((znak=fgetc(ulaz))!=EOF){
		while(c==znak){
			brojac++;
			znak=fgetc(ulaz);
		}
		if(brojac>=n){
			for(i=0;i<brojac;i++){
				fputc(c,izlaz);
			}
		}
		c=znak;
		brojac=1;
	}
	
	fclose(ulaz);
	fclose(izlaz);
	return 0;
}
