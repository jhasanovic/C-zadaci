/*#4 Prepravite funkciju iz prethodnog zadatka tako da prihvata dodatni parametar cs
(skraćeno od case sensitive ) koji može imati vrijednost 1 (poređenje treba uzeti u
obzir velika i mala slova, funkcionalnost je ista kao u prethodnom zadatku) i 0 (treba
ignorirati razliku između velikih i malih slova). Prototip funkcije sada izgleda ovako:
char * izbaci_tekst( char * str, const char * tekst, int cs)*/

#include <stdio.h>

char* izbaci_tekst (char* str,const char* tekst,int cs)
{
    char* pom1=str;
    const char* pom2=tekst;
    char* pok=str;
    char temp1,temp2;
    char* pocetak;
    if (*pom2=='\0') return pok;
    if(cs==1) {
        while (*str!='\0') {
            pom1=str;
            pocetak=str;
            pom2=tekst;
            while (*pom1==*pom2) {
                pom1++;
                pom2++;
                if (*pom1=='\0' || *pom2=='\0') break;
            }
            if (*pom2=='\0') {
                while(*pocetak++=*pom1++);
                str=pok;
                //bitno da se ne krahira
                continue;
            }
            str++;
        }
    } else if(cs==0) {
        while (*str!='\0') {
            pom1=str;
            pom2=tekst;
            pocetak=str;
            if(*pom1>='A' && *pom1<='Z') temp1=*pom1+32;
            else temp1=*pom1;
            if (*pom2>='A' && *pom2<='Z') temp2=*pom2+32;
            else temp2=*pom2;
            while (temp1==temp2) {
                pom1++;
                pom2++;
                if(*pom1>='A' && *pom1<='Z') temp1=*pom1+32;
                else temp1=*pom1;
                if (*pom2>='A' && *pom2<='Z') temp2=*pom2+32;
                else temp2=*pom2;
                if (*pom1=='\0' || *pom2=='\0') break;
            }
            if (*pom2=='\0') {
                while (*pocetak++=*pom1++);
                str=pok;
                continue;
            }
            str++;
 
        }
    }
    return pok;
}
int main()
{
    char niz[] = "danas je divan dan!";
    printf("'%s'", izbaci_tekst(niz, "Dan",0));

    return 0;
}
