/*#4 Napisati funkciju char *izbaci_viska_razmake (char *str) koja izbacuje sve višestruke razmake iz proslijeđenog
stringa. Dodatno, funkcija treba da ukloni sve eventualne razmake prije prve riječi i nakon posljednje riječi. 
Funkcija treba vratiti pokazivač na početak stringa.*/

#include <stdio.h>

void unesi(char niz[], int velicina){
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	int i=0;
	while(i<velicina-1 && znak!='\n'){
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

char je_li_razmak(char s){
	if(s==' ' || s=='\n' || s=='\t')
	return 0;
	else return 1;
}

char *izbaci_viska_razmake (char *str){
char* pocetak=str;
char* p1;
char* p2;
int razmak=1;
while(*str!='\0'){
	if(je_li_razmak(*str))
	razmak=1;
	else if(razmak==1){
		razmak=0;
		p1=str;
		p2=str;
		while(*p2!='\0' && !(je_li_razmak(*p2)))
		p2++;
		if(str!=pocetak && *p2!='\0')
		*p1++=' ';
		while(*p1++=*p2++);
	}
	str++;
}
return pocetak;
}

int main() {
	char str[100];
	unesi(str,100);
	printf("%s",izbaci_viska_razmake(str));
	return 0;
}