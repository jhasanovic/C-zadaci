/*#11 (II parcijalni ispit 2013/14, 2016/17; Završni ispit 2016/17) Napisati funkciju sa prototipom
char* izbaci_maxbroj(char* s) koja iz primljenog stringa izbacuje najveći broj. Ako se isti broj pojavljuje više puta 
u stringu, treba izbaciti SVA njegova pojavljivanja. U stringu se mogu nalaziti isključivo cijeli brojevi, pa tako 
"123.456" treba posmatrati kao dva broja. Mogu se nalaziti i negativni brojevi (koji su manji od pozitivnih itd.) 
Funkcija treba vratiti pokazivač na početak primljenog stringa.*/
//IDEJA: sve brojeve iz stringa upisati u niz, naci najveci, naci taj broj u stringu, vratiti pok na njega, izbaciti,
//pozivati funkciju sve dok se ne dodje do kraja stringa
#include <stdio.h>

char* izbaci_maxbroj(char* s){
    int max, predznak=1, broj=0, brojac=0;
    char *pok_na_broj;
    char *pocetak=s;
   
    while (*s!='\0'){
        while (!(*s>='0' && *s<='9') && *s!='\0') s++;
        if (*s=='\0') ;
        else {
            pok_na_broj=s;
            if (pok_na_broj!=pocetak){
                if (*(pok_na_broj-1)=='-') predznak=-1;
                else predznak=1;
            }
            else predznak=1;
            broj=0;
            do{
                broj=broj*10+*pok_na_broj-'0';
                pok_na_broj++;
            }while (*pok_na_broj>='0' && *pok_na_broj<='9') ;
            broj*=predznak;
            if (brojac==0) {
                max=broj;
                brojac++;
            }
            else {
                if (broj>max) max=broj;
            }
            s=pok_na_broj;
        }
    }
    if (brojac==0) return pocetak;
    int broj_cifara=0;
    broj=max;
    do{
        broj/=10;
        broj_cifara++;
    } while (broj!=0) ;
    char maxbroj[100];
    s=maxbroj;
    if (max<0) {
        *s++='-';
        max*=-1;
    }
    s+=broj_cifara;
    *s='\0';
    s--;
    do{
    *s=max%10+'0';
    s--;
    max/=10;
    }while (max!=0);
    s=pocetak;
    char *temp=maxbroj;
    char *adresa=maxbroj;
    char *pocetakbroja;
    while (*s!='\0'){
        temp=adresa;
        while (*s!='\0' && *s!=*temp) s++;
        if (*s=='\0') return pocetak;
        pocetakbroja=s;
        while (1){
            if (*temp=='\0') break;
            if (*temp!=*s) break;
            temp++;
            s++;
        }
        if (*temp=='\0'){
            while (*s!='\0'){
                *pocetakbroja=*s;
                pocetakbroja++;
                s++;
            }
            *pocetakbroja=*s;
            s=pocetak;
        }
        s++;
    }
    return pocetak;
}
 
 
int main() {
    printf("ZSR 10, Zadatak 11");
    return 0;
}
