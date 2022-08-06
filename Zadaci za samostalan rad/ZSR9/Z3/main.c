/*#3 Napišite funkciju sa prototipom: char* velika(char *s); koja u primljenom stringu sva mala slova pretvara u 
velika. Funkcija treba da vraća pokazivač na početak istog stringa koji je proslijeđen funkciji kao parametar.*/

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

char* velika(char* s){
	char* pok=s;
	while(*s!='\0'){
		if(*s>='a' && *s<='z')
		*s-=32;
		s++;
	}
	return pok;
}
int main() {
	printf("Unesite neki tekst: ");
	char s[100];
	unesi(s,100);
	printf("%s", velika(s));
	return 0;
}
