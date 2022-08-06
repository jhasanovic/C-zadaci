/*#6 Napisati funkciju char * zamijeni_tekst( char * str,const char *sta, const char *sa_cim, int cs)
Koja u proslijeđenom stringu str mijenja sva pojavljivanja teksta sta sa tekstom sa_cim . Voditi računa da je moguće
da se izvorni string proširi (pogledati primjer), ali pretpostaviti da ima dovoljno mjesta za proširivanje.
Parametar cs označava da li će biti ignorirana razlika između velikih i malih slova (cs = 1 znači da nema 
ignoriranja,dok cs = 0 znači da treba ignorirati). Primjer (riječ „caj“ se ponavlja dva puta i oba puta ju je 
potrebno zamijeniti sa dužom riječi „mlijeko“):
char tekst[100] = " Zeko pije CAJ. Pije caj mali zeko!";
zamijeni_tekst(tekst, "caj", "mlijeko", 0); //cs = 0
printf ("'%s'", tekst);
Primjer iznad treba da ispiše:
' Zeko pije mlijeko. Pije mlijeko mali zeko!'*/
#include <stdio.h>
char* zamijeni_tekst (char* Str, const char* sta, const char* sa_cim, int cs)
{
    //deklaracija varijabli
    int br1=0,br2=0;
    const char* pom1=sta;
    char* pom=Str;
    char* pocetak=Str;
    const char* pom2=sa_cim;
    char* kraj=Str;
    char* poc=Str;
    int pomak=0;
    char temp1,temp2;
    //racunanje pomaka
    while (*kraj!='\0') kraj++;
    while (*pom1!='\0') {
        br1++;
        pom1++;
    }
    while (*pom2!='\0') {
        br2++;
        pom2++;
    }
    pomak=br2-br1;
    //ako je cs
    if (cs) {
        while (*Str!='\0') {
            pom1=sta;
            pom=Str;
            pom2=sa_cim;
            poc=Str;
            while(*pom1==*pom) {
                pom1++;
                pom++;
                if (*pom1=='\0' || *pom=='\0') break;
            }
            if (*pom1=='\0') {
                //ako je rijec koja mijenja veca od rijeci koju mijenjamo
                if (pomak>0) {
                    while (kraj>=pom) {
                        *(kraj+pomak)=*kraj;
                        kraj--;
                    }
                    while (*kraj!='\0') kraj++;
                    while (*pom2!='\0') {
                        *poc=*pom2;
                        poc++;
                        pom2++;
                    }
                    if(poc==kraj) *poc='\0';
                } else if (pomak==0) { //ako su rijeci iste duzine
                    while (*pom2!='\0') {
                        *poc=*pom2;
                        poc++;
                        pom2++;
                    }
                    if (poc==kraj) *poc='\0';
 
                } else if (pomak<0) { //ako je rijec koji mijenjamo duza od one koja se mijenja
                    while (*pom2!='\0') {
                        *poc=*pom2;
                        poc++;
                        pom2++;
                    }
                    if (poc==kraj) *poc='\0';
                    while (*poc++=*pom++);
                }
            }
            Str++;
        }
    } else {
        while (*Str!='\0') {
            pom1=sta;
            pom=Str;
            pom2=sa_cim;
            poc=Str;
           
            if(*pom1>='A' && *pom1<='Z') temp1=*pom1+32;
            else temp1=*pom1;
            if (*pom>='A' && *pom<='Z') temp2=*pom+32;
            else temp2=*pom;
           
            while(temp1==temp2) {
                pom1++;
                pom++;
                if(*pom1>='A' && *pom1<='Z') temp1=*pom1+32;
                else temp1=*pom1;
                if (*pom>='A' && *pom<='Z') temp2=*pom+32;
                else temp2=*pom;
                if (*pom1=='\0' || *pom=='\0') break;
            }
           
            if (*pom1=='\0') {
                if (pomak>0) {
                    while (kraj>=pom) {
                        *(kraj+pomak)=*kraj;
                        kraj--;
                    }
                    while (*kraj!='\0') kraj++;
                    while (*pom2!='\0') {
                        *poc=*pom2;
                        poc++;
                        pom2++;
                    }
                    if(poc==kraj) *poc='\0';
                } else if (pomak==0) {
                    while (*pom2!='\0') {
                        *poc=*pom2;
                        poc++;
                        pom2++;
                    }
                    if (poc==kraj) *poc='\0';
 
                } else if (pomak<0) {
                    while (*pom2!='\0') {
                        *poc=*pom2;
                        poc++;
                        pom2++;
                    }
                    if (poc==kraj) *poc='\0';
                    while (*poc++=*pom++);
                }
            }
            Str++;
        }
    }
    return pocetak;
}
 
int main()
{
    printf("ZSR 10, Zadatak 6");
    return 0;
}