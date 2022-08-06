#include <stdio.h>
#include <string.h>

/*funkcija za unos stringa*/
void unesi(char niz[],int velicina)
{
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	int i=0;
	while(i<velicina-1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

char* max_slog(char* stari, char* krajnji)
{
	char slogovi[100][100];
	char* pok=stari;
	char* poc=krajnji;
	int i=0,j=0,redovi=0,brojac=1,max=1,maxi=0,flag=0,duzina=0;
	/*upisivanje svakog sloga u jedan red matrice "slogovi"*/
	while(*pok!='\0') {
		if(*pok>='A' && *pok<='z') { /*ako je nadjeno slovo,ostale znakove ne upisujemo u matricu*/
			if(*pok=='A' || *pok=='E' || *pok=='I' || *pok=='O' || *pok=='U') { /*ako je samoglasnik(i veliko slovo)*/
				slogovi[i][j]=*pok+32;/*pretvori u malo slovo*/
				j++;
				slogovi[i][j]='\0';/*odmah zavrsi red*/
				i++;
				redovi++;
				j=0;
			} else if(*pok=='a' || *pok=='e' || *pok=='i' || *pok=='o' || *pok=='u') { /*samoglasnik(malo slovo)*/
				slogovi[i][j]=*pok;
				j++;
				slogovi[i][j]='\0';/*odmah zavrsi red*/
				i++;
				redovi++;
				j=0;
			}
			/*ako nije samoglasnik, ali iza njega je znak koji nije slovo*/
			else if(*(pok+1)<'a' || *(pok+1)>'z') {
				if(*pok>='A' && *pok<='Z')
					slogovi[i][j]=*pok+32;
				else
					slogovi[i][j]=*pok;
				j++;
				slogovi[i][j]='\0';
				i++;
				redovi++;
				j=0;
			}
			/*ako nije samoglasnik, ali nije kraj rijeci ili stringa*/
			else {
				if(*pok>='A' && *pok<='Z')
					slogovi[i][j]=*pok+32;
				else
					slogovi[i][j]=*pok;
				j++;
			}
		}
		pok++;
	}
	/*trazenje najduzeg sloga*/
	for(i=0; i<redovi; i++) {
		brojac=1;
		for(j=i+1; j<redovi; j++) {
			if(strcmp(slogovi[i],slogovi[j])==0) {/*strcmp ce vratiti 0 ako su jednaki*/
				flag++;
				brojac++;
				if(brojac>max || (brojac>=max && strlen(slogovi[i])>strlen(slogovi[maxi]))) {
					max=brojac;
					maxi=i;
				}
			}
		}
	}
	if(flag==0) { /*ako se ne nadje visestruko ponavljanje niti jednog sloga*/
		maxi=0;
		for(i=0; i<redovi; i++) {
			duzina=strlen(slogovi[i]);
			if(duzina>strlen(slogovi[maxi]))
				maxi=i;
		}
	}
	strcpy(krajnji,slogovi[maxi]);
	return poc;
}

int main()
{
	char stari[100];
	char krajnji[100];
	printf("Unesite string:");
	unesi(stari,100);
	printf("\nNajcesce se ponavlja slog: %s",max_slog(stari,krajnji));
	return 0;
}
