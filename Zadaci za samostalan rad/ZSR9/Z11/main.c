#include <stdio.h>
#include <string.h>

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

//rastavljanje primljenog stringa na slogove
char* na_razmake (char* stari){

char novi[100];
char* pok=stari;
char* pocetak=stari;
int j=0;

//unesi(stari,100);

while(*pok!='\0')

{
while(*pok==' ' && *(pok+1)==' ')
pok++;
int flag=0;
if(*pok=='A' || *pok=='a' || *pok=='E' || *pok=='e' || *pok=='I' || *pok=='i' || *pok=='O' || *pok=='o' || *pok=='U' || *pok=='u' )
flag=1;//kraj sloga
if((*pok<'A' || *pok>'z') && *pok!=' '){//ignorisi znakove koji nisu slova
    pok++;
    continue;
}
//if(*pok>='A' && *pok<='z' && (*(pok+1)<'A' || *(pok+1)>'z') && *(pok+1)!=' '){
//novi[j]=' ';
//j++;
//}
//if(*pok<'A' || *pok>'z')//kopiraj samo slova
    novi[j] = *pok;

j++;


if(flag==1 && *(pok+1)!=' '){//ispusti nepotrebne razmake
novi[j] = ' ';
j++;
}
pok++;
}

novi[j] = '\0';
strcpy(stari,novi);

return pocetak;
}

int main(){
char stari[100];
unesi(stari,100);
printf("%s",na_razmake(stari));
return 0;
}
