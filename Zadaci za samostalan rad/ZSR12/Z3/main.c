#include <stdio.h>

int main() {
	signed int niz[100];
	int i,upisani=0;
	for(i=0;i<100;i++){
	scanf("%d",&niz[i]);
	if(niz[i]==-1)
	break;
	upisani++;
	}
	
	FILE* ulaz=fopen("brojevi.bin","wb");
	if(ulaz==NULL){
		printf("Pogreska kod otvaranja datoteke brojevi.bin!");
		return 0;
	}
	
	int uspjesni= fwrite(niz,sizeof(niz[0]), upisani, ulaz);
	if(ferror(ulaz))
	printf("Greska kod upisivanja u datoteku");
	fread(niz,sizeof(niz),upisani,ulaz);
	/*ispisati niz ucitan u binarnu datoteku*/
	for(i=0;i<uspjesni;i++){
		printf("%d ",niz[i]);
	}
	
	fclose(ulaz);
	return 0;
}
