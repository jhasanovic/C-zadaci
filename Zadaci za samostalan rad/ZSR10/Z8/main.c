/*#8 Napisati funkciju int periodican( const char *string) koja vraća vrijednost 0 ukoliko string nije periodičan,
a ukoliko jeste, funkcija treba da vrati dužinu perioda, tj. broj znakova u jednom periodu. Pod periodičnim stringom
podrazumijevamo string koji se sastoji isključivo od periodičnog ponavljanja istog podstringa (s tim da zadnji
podstring ne mora da bude kompletan). Primjeri periodičnih stringova (periodi su 2, 3 i 5, respektivno):
ababab
abcabca
DanasDanasDa
dok sljedeći stringovi nisu periodični (period im je 0):
ababac
DanasDanasS*/
#include <stdio.h>
int periodican(const char *string){
   
    int i;
    char *kraj=string;
    while(*kraj!='\0')kraj++;
   
    int vel=kraj-string;
   
    for(i=1;i<vel;i++){
       
        char *pok=string;
       
        while(*(pok+i)!='\0'){
           
        if(*pok!=*(pok+i))break;
       
        pok++;
        }
       
            if(*(pok+i)=='\0')return i;
       
    }
   
    return 0;
   
}

int main()
{
    char a[] = "ababab", b[] = "abcabca", c[]="DanasDanasDa";
    printf("%d %d %d", periodican(a), periodican(b), periodican(c));
    return 0;
}
