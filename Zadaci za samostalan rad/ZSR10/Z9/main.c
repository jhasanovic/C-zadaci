/*#9 (Zadaća 4, 2012/13; Završni ispit 2016/17) Napišite funkcije sa prototipovima:
char* kompresuj(char* s), char* dekompresuj (char* s)
Funkcija kompresuj prima string a zatim vrši RLE kompresiju stringa po sljedećem principu: ukoliko se naiđe na neki 
znak (char) koji se ponavlja više od tri puta, potrebno ga je zamijeniti sljedećim nizom znakova: uzvičnik (!) koji 
označava da slijedi ponavljanje, zatim znak koji se ponavlja i na kraju broj puta koliko se znak ponavlja. Ovaj broj
treba biti predstavljan znakovima koji odgovaraju ciframa. Ukoliko se u primljenom stringu naiđe na znak uzvičnik, 
potrebno ga je zamijeniti sa dva uzvičnika kako ne bi bio pogrešno protumačen kao znak kompresije. Radi lakšeg
lančanog pozivanja funkcija vraća pokazivač na prvo slovo primljenog stringa.
Primjer: Ako je dat string
aaaaabbb!cccccccccccc
potrebno ga je zamijeniti sa
!a5bbb!!!c12 Objašnjenje: !a5 - znak a se ponavlja pet puta
bbb - pošto se znak b ponavlja samo tri puta, nećemo ga kompresovati jer se time ništa ne dobija
!! - znak uzvičnik je ponovljen (escapovan) da ne bi bio pogrešno protumačen kao znak kompresije
!c12 - znak c se ponavlja 12 puta. Cifre se uvijek kompresuju, čak i ako se pojavljuju samo jednom, da bi se 
izbjegla zabuna sa brojem ponavljanja. Npr. ako string glasi
aaaaa4 bez ovog pravila kompresovani string bi glasio !a54 a to bi značilo da se slovo a ponavlja 54 puta, pa zato 
kompresujemo i cifru 4 tako da dobijamo: ! a5!41 Funkcija dekompresuj treba raditi inverznu operaciju, odnosno svaki
string kompresovan funkcijom kompresuj treba uspješno vratiti u izvorni oblik. Pretpostavite da se nakon svakog 
znaka uzvičnika nalazi još jedan uzvičnik (koji izbacujemo) ili da se nalazi neki znak nakon kojeg slijedi jedna ili
više cifara koje predstavljaju broj ponavljanja znaka. Neće biti testirane situacije gdje to nije slučaj.*/
#include <stdio.h>
 
char* kompresuj(char* s)
{
    int bru,i,br,pomi,br_cif;
    char znak;
    char string[12];
    char* pocetak=s;
    char* sb=string;
    char* kraj=s;
    char* pom=s;
    char* poc=s;
    //duplanje uzvicnika
    while (*s!='\0') {
        if (*s=='!') {
            bru=0;
            while (*s=='!') {
                s++;
                bru++;
            }
            kraj=s;
            pom=s;
            while (*kraj!='\0') kraj++;
            while (kraj>=s) {
                *(kraj+bru)=*kraj;
                kraj--;
            }
            for (i=0; i<bru; i++) *pom++='!';
            s=s+bru-1;
        }
        s++;
    }
    //kompresovanje cifara
    s=pocetak;
    char cifra;
    while (*s!='\0') {
        if (*s>='0' && *s<='9') {
            cifra=*s;
            while(*kraj!='\0') kraj++;
            while (kraj>=s) {
                *(kraj+2)=*kraj;
                kraj--;
            }
            *s++='!';
            *s++=cifra;
            *s='1';
        }
        s++;
    }
    s=pocetak;
    while (*s!='\0') {
        br=0;
        znak=*s;
        pom=s;
        poc=s;
        while (*pom==znak && znak!='!') {
            pom++;
            br++;
        }
        if (br>3 && br<10) {
            *poc++='!';
            *poc++=znak;
            *poc++=br+'0';
            while (*poc++=*pom++);
        }
        if (br>=10) {
            pomi=br;
            //prebrojavanje cifara
            do {
                pomi/=10;
                sb++;
            } while (pomi!=0);
            *sb--='\0';
            //stavljanje cifara u pomocni string
            do {
                *sb=br%10+'0';
                sb--;
                br=br/10;
            } while (br!=0);
            sb++;
            //kopiranje pomocnog stringa
            *poc++='!';
            *poc++=znak;
            while(*sb!='\0') {
                *poc=*sb;
                poc++;
                sb++;
            }
            while (*poc++=*pom++);
        }
        s++;
    }
    return pocetak;
}
 
char* dekompresuj (char* s)
{
    char* pocetak=s;
    char* pom;
    char* poc=s;
    char* kraj=s;
    char znak;
    int br,br_cif;
    int i;
    //izbavicanje duplih uzvicnika
    while (*s!='\0') {
        br=0;
        br_cif=0;
        if (*s=='!' && *(s+1)=='!') {
            poc=s+1;
            pom=s+2;
            while(*poc++=*pom++);
        }
        if (*s=='!' && *(s+2)>='0' && *(s+2)<='9') {
            znak=*(s+1);
            pom=s+2;
            kraj=s;
            while(*pom>='0' && *pom<='9') {
                br=br*10+*pom-'0';
                pom++;
                br_cif++;
            }
            while (*kraj!='\0') kraj++;
            while (kraj>s) {
                *(kraj+br-br_cif-2)=*kraj;
                kraj--;
            }
            poc=s;
            for(i=0; i<br; i++) *poc++=znak;
        }
        s++;
    }
    return pocetak;
}
 
int main()
{
    /* Razmaci */
    char tekst[100] = "! 10Tekst!a6! 16";
    printf("'%s'", dekompresuj(tekst));
    return 0;
}
