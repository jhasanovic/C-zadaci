/*#10 (II parcijalni ispit 2014/15; Završni ispit 2015/16; Završni ispit 2016/17)
Napisati funkciju sa prototipom: char* prebroji (char* tekst, char* slova) Funkcija prima dva stringa pri čemu tekst
sadrži neki tekst a slova je prazan (i dovoljno velik). Funkcija treba u string slova zapisati sva slova koja se
javljaju u prvom stringu i to poredane po broju ponavljanja od onih koja se javljaju najviše puta do onih koja se
javljaju najmanje puta. Pri tome treba zanemariti razliku između velikih i malih slova a drugi string treba
sadržavati isključivo VELIKA slova. Ako se više slova javljaju podjednak broj puta, treba najprije upisati u string
ono slovo koje se nalazi ranije u ASCII tabeli. Radi lakšeg lančanog pozivanja, funkcija vraća pokazivač na prvo
slovo stringa slova.*/
#include <stdio.h>

char* prebroji(char* tekst, char* slova)
{
	char* pok=slova;
	int slovo=0,j=0;
	int brojaci[100]= {0},i;
	char pomocni[30];
	if(*tekst=='\0')
		return pok;
	while(*tekst!='\0') {
		if(*tekst>='A' && *tekst<='Z')
			brojaci[(int)*tekst]++;
		else if(*tekst>='a' && *tekst<='z')
			brojaci[*tekst-32]++;
		tekst++;
	}
	for(i='A'; i<'Z'; i++) {
		if(brojaci[i]!=0) {
			slovo=1;
			break;
		}
	}
	slova=pok;
	int flag=0;
	if(slovo==0) return pok;
	int max=-1,maxi=-1;
	do {
		max=0;
		for(i='A'; i<'Z'; i++) {
			if(brojaci[i]>max) {
				max=brojaci[i];
				maxi=i;
			}
		}
		*slova=maxi;
		pomocni[j]=maxi;
		if(j!=0 && maxi==pomocni[j-1]) {
		flag=1;
		continue;
		}
		slova++;
		brojaci[maxi]=0;
		j++;
	} while(flag!=1);
	*slova='\0';
	return pok;
}

int main()
{
	char tekst[] = "Ovo je neki primjer.";
	char slova[100];
	prebroji(tekst,slova);
	printf("'%s'", slova);
	return 0;
}
/*

#include <stdio.h>
char* prebroji (char* tekst, char* slova){
 
int niz[26]={0};
 
char *pocetak=tekst;
 
while(*tekst!='\0'){
 
    if(*tekst<='Z' && *tekst>='A')niz[*tekst-'A']++;
    if(*tekst<='z' && *tekst>='a')niz[*tekst-'a']++;
 
    tekst++;
}
 
int i=0,j=0,maxi=0,brojac=0;//max_indeks==maxi
 
for(i=0;i<26;i++){
    maxi=0;//kazem da je A slovo najvise puta upisano
 
    for(j=0;j<26;j++)
       if(niz[j]>niz[maxi]) maxi=j;//trazim koj se slovo najvise naslo
       //posto ovdje pise >, uzet se kao max prvo slovo koje ima max vrijednost
       //ako A i C su se javili 19 puta, maxi ce ostat 0 jer 19>19 je false
 
    if(niz[maxi]==0) break;//ako se max slovo javilo 0 puta znaci ispisalo ih je sve
    *slova='A'+maxi;
    slova++;
    niz[maxi]=0;
 
}
*slova='\0';
 
return pocetak;
}

int main()
{
	char tekst[] = "Ovo je neki primjer.";
	char slova[100];
	prebroji(tekst,slova);
	printf("'%s'", slova);
	return 0;
}
*/