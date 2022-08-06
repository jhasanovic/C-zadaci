/*kopirana verzija sa zamgera 14.1. u 20:16*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Planina {
	char naziv[50];
	int visina;
} niz[1000];

/*ucitaj podatke iz datoteke u niz tipa struct Planina*/
int ucitaj(struct Planina niz[],int n)
{
	int i=0,j=0;
	char znak,c;
	char prvi_dio[50];
	FILE* ulaz=fopen("planine.txt","r");
	if(ulaz==NULL) {
		printf("Pogreska pri otvaranju datoteke planine.txt");
		exit(0);
	}
	/*provjeriti je li prvo naziv ili visina*/
	znak=fgetc(ulaz);
	char drugi_dio[50];
	if(znak>='A' && znak<='z') {
		fseek(ulaz,0,SEEK_SET);/*vratiti kursor na pocetak*/
		j=0;
		c=getc(ulaz);
		ungetc(c,ulaz);
		while(j<1000 && fscanf(ulaz,"%s",prvi_dio)==1) {
			c=getc(ulaz);
			c=getc(ulaz);
			while(c>='A' && c<='z') {
				ungetc(c,ulaz);
				strcat(prvi_dio," ");
				fscanf(ulaz,"%s",drugi_dio);
				strcat(prvi_dio,drugi_dio);
				c=getc(ulaz);
				c=getc(ulaz);
			}
			ungetc(c,ulaz);
			fscanf(ulaz,"%d",&niz[j].visina);
			strcpy(niz[j].naziv,prvi_dio);
			j++;
		}
	}


	else if(znak>='0' && znak<='9') {
		fseek(ulaz,0,SEEK_SET);
		j=0;
		while(j<1000 && fscanf(ulaz,"%d",&niz[j].visina)==1) { /*ucitati visinu*/
			c=fgetc(ulaz);
			while(c==' ') { /*preskoci razmake poslije visine i prije naziva*/
				c=fgetc(ulaz);
			}
			ungetc(c,ulaz);/*vrati na prvo slovo naziva*/
			i=-1;
			do {
				if(i<50) i++;
				prvi_dio[i]=fgetc(ulaz);
			} while(prvi_dio[i]!=' ' && prvi_dio[i]!=EOF && prvi_dio[i]!='\n');/*doslo je do razmaka*/
			if(prvi_dio[i]!=' ') {
				prvi_dio[i]='\0';
			} else {
				while(prvi_dio[i]==' ') {
					prvi_dio[i]=' ';
					do {
						if(i<50) i++;
						prvi_dio[i]=fgetc(ulaz);
					} while(prvi_dio[i]!=' ' && prvi_dio[i]!=EOF && prvi_dio[i]!='\n');
				}
				prvi_dio[i]='\0';
			}
			strcpy(niz[j].naziv,prvi_dio);
			j++;
		}
	}
	fclose(ulaz);
	return j;
}
/*zapisi podatke iz strukture u binarnu datoteku*/
void zapisi(struct Planina niz[],int n)
{
	remove("planine.dat");
	FILE* izlaz=fopen("planine.dat","wb");
	if(izlaz==NULL) {
		printf("Pogreska pri otvaranju binarne datoteke planine.dat");
		exit(0);
	}
	fwrite(niz,sizeof(struct Planina),n,izlaz);
	if(ferror(izlaz))
		printf("Greska kod upisivanja u binarnu datoteku planine.dat");
	fclose(izlaz);
}

/*ispisati ime i visinu najvise planine do 2000 metara koja u imenu ima slovo a (veliko ili malo)*/
void ispis(struct Planina niz[],int n)
{
	/*naci najvisu planinu cija je visina<=2000, zatim pokazivacem prolaziti kroz ime i traziti slovo a/A,
	ako nije pronadjeno, staviti max prethodnu visinu planine*/
	int granica=2000,max=0,i,flag=0,maxi=-1;
	char* pok;
	do {
		for(i=0; i<n; i++) {
			if(niz[i].visina>max && niz[i].visina<granica) {
				max=niz[i].visina;
				maxi=i;
			}
		}
		/*nadjena najvisa planina, pretraziti string naziv*/
		pok=niz[maxi].naziv;
		while(*pok!='\0') {
			if(*pok!='A' && *pok!='a')
				flag=1;
			else if(*pok=='A' || *pok=='a') {
				flag=0;
				break;
			}
			pok++;
		}
		if(flag==1) {
			granica=max;
			max=0;
			maxi=0;
		}
	} while(flag!=0);
	if(maxi!=-1)/*ako je datoteka prazna ne ispisati nista*/
		printf("%s %d\n",niz[maxi].naziv,niz[maxi].visina);
}

int main()
{
	int i=0;
	struct Planina niz[1000];
	int ucitane=ucitaj(niz,8);

	for(i=0; i<ucitane; i++) {
		printf("%s - %d\n",niz[i].naziv,niz[i].visina);
	}
	ispis(niz,8);
	zapisi(niz,8);
	return 0;
}