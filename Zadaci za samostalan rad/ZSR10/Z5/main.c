/*#5 Napisati funkciju void nta_rijec( const char * str, char * rijec, int n)
koja pronalazi n-tu riječ u rečenici str i smješta je u niz na koji pokazuje parametar rijec . Ukoliko je n veći od
broja riječi u rečenici, funkcija treba da stavi „prazan“ string u parametar rijec (nul znak tj. '\0' na početak
stringa). Pod pojmom "riječ" podrazumijevamo neprekinuti niz velikih ili malih slova.*/
#include <stdio.h>
#include <string.h>

void nta_rijec(const char* str,char* rijec,int n)
{
 int br=0;
    int razmak=1;
    while (*str!='\0') {
        if (!( (*str>='A' && *str<='Z') || (*str>='a' && *str<='z') ) ) razmak=1;
        else if (razmak) {
            razmak=0;
            br++;
            if (br==n) {
                while((*str>='A' && *str<='Z') || (*str>='a' && *str<='z')) {
                    *rijec++=*str++;
                }
                *rijec='\0';
            }
        }
        str++;
    }
    if (n>br) *rijec='\0';
		
}

int main()
{
	const char *tekst = "   Zeko     pije     mlijeko!          ";
	char rijec[101]; //pretpostavimo da nije duza od 100 znakova
	nta_rijec(tekst, rijec, 2); // 2. rijec po redu ("pije")
	printf ("2. rijec: '%s'", rijec);
	return 0;
}