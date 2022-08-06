/*#3 Napisati funkciju char * izbaci_tekst( char * str, const char * tekst) koja iz izvornog stringa str izbaciju
svako pojavljivanje teksta tekst . Funkcija vraća pokazivač na početak proslijeđenog stringa. Primjer korištenja:
char niz[] = "danas je divan dan!";
//ispisuje: 'as je divan !'
printf("'%s'", izbaci_tekst(niz, "dan"));
Prilikom svakog izbacivanja treba krenuti ispočetka, tako npr. ako string glasi
"aabcbc" nakon izbacivanja "abc" treba dobiti prazan string.*/

#include <stdio.h>
 
char* izbaci_tekst (char* str,const char* tekst)
{
    char* pom1;
    const char* pom2=tekst;
    char* pocetak;
    char* pok=str;
    if (*pom2=='\0') return pok;
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
    return pok;
}
int main()
{
	char niz[] = "danas je divan dan!";
	printf("'%s'", izbaci_tekst(niz, "dan"));

	return 0;
}