#include <stdio.h>

int main() {
	char x,y,znak;
	printf("Unesite znakove x i y: ");
	scanf("%c %c ",&x,&y);
	if((int)y<(int)x){
		printf("Pogresan unos");
		return 0;
	}
	FILE* ulaz=fopen("input.txt","r");
	FILE* izlaz=fopen("output.txt","w");
	if(ulaz==NULL){
		printf("Pogreska kod otvaranja datoteke input.txt!");
		return 1;
	}
	if(izlaz==NULL){
		printf("Pogreska kod otvaranja datoteke output.txt!");
		return 2;
	}
	while((znak=getc(ulaz))!=EOF){
		if((int)znak>=(int)x && (int)znak<=(int)y)
		fputc(znak,izlaz);
	}
	fclose(ulaz);
	fclose(izlaz);
	return 0;
}
