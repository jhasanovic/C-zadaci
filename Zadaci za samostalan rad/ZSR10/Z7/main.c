/*#7 Napisati funkciju zamijeni_rijec istih parametara i povratnog tipa kao i funkcija zamijeni_tekst iz prethodnog 
zadatka, ali ovaj put funkcija treba da mijenja tekst jedino ako taj tekst predstavlja riječ (omeđena sa obje strane
razmacima osim eventualno prve i posljednje riječi). Npr. da je tekst u prethodnom zadatku glasio „Zeko pije caja. 
Caj pije zeko.“, ukoliko bismo zamijenili „caj“ sa „mlijeko“ funkcija bi zamijenila rijec „caja“ sa „mlijekoa“, što 
možda nije ono što smo željeli. Upravo taj nedostatak uklanja funkcija zamijeni_rijec koja će mijenjati
tekst jedino ako je riječ; u primjeru iznad bi samo riječ „Caj“ bila zamijenjena, ali ne i riječ „caja“.*/
#include <stdio.h>
char* zamijeni_rijec (char* Str, const char* sta, const char* sa_cim, int cs)
{
    //deklaracija
    char* pocetak=Str;
    char* poc=Str;
    char* poc1=Str;
    const char* pom1=sta;
    const char* pom2=sa_cim;
    char* kraj=Str;
    int pomak=0,br1=0,br2=0;
    char temp1,temp2;
    //trazenje kraja
    while (*kraj!='\0') kraj++;
    while (*sta!='\0') {
        br1++;
        sta++;
    }
    sta=pom1;
    while (*sa_cim!='\0') {
        br2++;
        sa_cim++;
    }
    sa_cim=pom2;
    pomak=br2-br1;
    if (cs) {
        while (*Str!='\0') {
            pom2=sa_cim;
            pom1=sta;
            poc=Str;
            poc1=Str;
            while (*poc==*pom1) {
                poc++;
                pom1++;
                if (*pom1=='\0' || *poc=='\0') break;
            }
            if (*pom1=='\0' && (*poc==' ' || *poc=='\0') && (poc1==pocetak || (*(poc1-1)==' ' ) ) ) {
                if (pomak==0) {
                    while (*pom2!='\0') {
                        *poc1=*pom2;
                        poc1++;
                        pom2++;
                    }
                }
                if (pomak<0) {
                    while (*pom2!='\0') {
                        *poc1=*pom2;
                        poc1++;
                        pom2++;
                    }
                    while (*poc++==*poc1++);
                }
                if (pomak>0) {
                    while (kraj>=poc) {
                        *(kraj+pomak)=*kraj;
                        kraj--;
                    }
                    while (*kraj!='\0') kraj++;
                    while (*pom2!='\0') {
                        *poc1=*pom2;
                        poc1++;
                        pom2++;
                    }
                }
            }
            Str++;
        }
    } else {
        while (*Str!='\0') {
            poc1=Str;
            poc=Str;
            pom1=sta;
            pom2=sa_cim;
            if (*poc>='A' && *poc<='Z') temp1=*poc+32;
            else temp1=*poc;
            if (*pom1>='A' && *pom1<='Z') temp2=*pom1+32;
            else temp2=*pom1;
            while (temp1==temp2) {
                poc++;
                pom1++;
                if (*poc=='\0' || *pom1=='\0') break;
                if (*poc>='A' && *poc<='Z') temp1=*poc+32;
                else temp1=*poc;
                if (*pom1>='A' && *pom1<='Z') temp2=*pom1+32;
                else temp2=*pom1;
               
            }
            if (*pom1=='\0' &&  ( !( (*poc>='A' && *poc<='Z') || (*poc>='a' && *poc<='z') ) )  && (poc1==pocetak || (*(poc1-1)==' ') ) ) {
                if (pomak==0) {
                    while (*pom2!='\0') {
                        *poc1=*pom2;
                        poc1++;
                        pom2++;
                    }
                }
                if (pomak>0) {
                    while (kraj>=poc) {
                        *(kraj+pomak)=*kraj;
                        kraj--;
                    }
                    while (*kraj!='\0') kraj++;
                    while (*pom2!='\0') {
                        *poc1=*pom2;
                        poc1++;
                        pom2++;
                    }
                }
                if (pomak<0) {
                    while (*pom2!='\0') {
                        *poc1=*pom2;
                        poc1++;
                        pom2++;
                    }
                    while (*poc1++=*poc++);
                }
            }
            Str++;
        }
 
    }
    return pocetak;
}
 
 
int main()
{
    char tekst[100] = "   CAJ.  Pije caj iz ocaja mali zeko!";
zamijeni_rijec (tekst, "caj", "mlijeko", 0); //cs = 1
printf ("'%s'", tekst);
    return 0;
}
