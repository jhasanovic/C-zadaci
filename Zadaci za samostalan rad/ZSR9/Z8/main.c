/*#8 Napisati funkciju int prebroji(const char* str, const char* slova)
koja u proslijeđenom string str broji pojavljivanje znakova iz stringa slova (svaki znak posebno). Potrebno je 
ignorirati velika i mala slova.*/
#include <stdio.h>
 
int prebroji (const char* Str, const char* slova)
{
    char brojaci[26]= {0}; //histogram za 26 slova
    int br=0;
    char temp;
    while (*Str!='\0') {//do kraja stringa
        if ((*Str>='A' && *Str<='Z') || (*Str>='a' && *Str<='z') ) {//ne pravi razliku izmedju velikog i malog slova
           if (*Str>='A' && *Str<='Z') 
            temp=*Str+32;//sve pretvoriti u mala
            else 
            temp=*Str;
            brojaci[temp-'a']++;
        }
        Str++;
    }
 
    while (*slova!='\0') {//prolazimo kroz manji string 
        if (*slova>='A' && *slova<='Z') temp=*slova+32;
        else temp=*slova;//pretvaramo sva slova u mala
        br+=brojaci[temp-'a'];//br je ukupan broj pojavljivanja slova
        slova++;
    }
    return br;
}

int main() {
printf ("%d ", prebroji("Otorinolaringologija", "oag"));
printf ("%d", prebroji("Danas", "ad"));
return 0;
}