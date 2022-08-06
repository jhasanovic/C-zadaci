/*#7 Napisati funkciju int je_li_palindrom(const char* str) koja ispituje da li je proslijeđeni string palindrom te
vraća 1 ako jeste, odnosno 0 ako nije. U funkciji je zabranjeno korištenje indekisranja stringa (p[i]) kao i 
trivijalne simulacije indeksiranja pomoću *(p + i). Pri tome ignorirati sve znakove koji nisu slova i brojevi. 
Također, ignorirati velika i mala slova.*/
#include <stdio.h>
 
int je_li_palindrom(const char* Str)
{
    char pom[200];//niz u koji prepisujemo string Str
    char* p=pom;
    char temp;//temp zbog konverzije const pok u obicni pok
    int flag=0;//za razmake
    const char* pocetak=Str;
    //provjeravamo ako su svi razmaci
    while(*Str!='\0'){
    	if(*Str==' ')
    	flag=1;
    	else{
    		flag=0;
    		break;
    	}
    	Str++;
    }
    if(flag==1)
    return 0;
    
    Str=pocetak;
    while (*Str!='\0') {
        if ((*Str>='A' && *Str<='Z') || (*Str>='a' && *Str<='z') || (*Str<='9' && *Str>='0')) {
            if (*Str>='A' && *Str<='Z') temp=*Str+32;//upisujemo string u pomocni niz
            else temp=*Str;
            *p=temp;
            p++;
        }
        Str++;
    }
    *p='\0';//terminiramo niz
    p--;//vratimo na zadnji clan pomocnog niza
    Str=pocetak;//vratimo pokazivac na pocetak
    while (*Str!='\0') {
        if ((*Str>='A' && *Str<='Z') || (*Str>='a' && *Str<='z')|| (*Str<='9' && *Str>='0')) {
            if (*Str>='A' && *Str<='Z') temp=*Str+32;
            else temp=*Str;
            if(temp!=*p) return 0;//sad poredimo trenutni temp sa vrijednoscu p koji ide prema naprijed
            p--;
        }
        Str++;
    }
    return 1;
}
 
int main()
{
    printf("%d",je_li_palindrom("  "));
    return 0;
}