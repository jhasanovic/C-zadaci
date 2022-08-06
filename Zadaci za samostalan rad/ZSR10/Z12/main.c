/*#12 (Završni ispit 2015/16; Zadaća 4, 2016/17) Napišite funkciju sa sljedećim prototipom:
char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci)
Prvi parametar funkcije je string koji sadrži neki tekst, a drugi i treći parametar su nizovi pokazivača tipa char 
(nizovi riječi) čija je veličina broj_rijeci. Funkcija treba pronaći u stringu sve riječi iz niza rijeci (sva njihova
pojavljivanja u stringu) i zamijeniti ih odgovarajućim riječima iz niza zamjene. Pri tome trebate paziti da se 
zamijene samo kompletne riječi, a ne njihovi dijelovi. Riječ je omeđena znakovima razmaka ili početkom ili krajem 
stringa. Ako je string prazan ili ako su nizovi prazni, ne treba raditi ništa. Pretpostavite da je string tekst 
dovoljno velik da primi sve eventualne dodatne karaktere. Funkcija treba biti case-sensitive (razlikovati velika i 
mala slova).Radi lakšeg lančanog pozivanja, funkcija treba vratiti pokazivač na početak primljenog stringa.*/
#include <stdio.h>

int podstring (const char *str, const char *trazi){
    char *pocetak=str;
    char *s2=trazi;
    char *s1=str;
    while(*s1!='\0'){
       
        char *pok=s1;
        s2=trazi;
        while(*s1==*s2){
            s1++;
            s2++;
            if(*s2=='\0' && (pok==pocetak || *(pok-1)==' ') && (*s1==' ' || *s1=='\0' ))return pok-pocetak;//samo *s2=='\0' za bilo koji podniz ne puna rijec
        }
       
        s1++;
    }
    return -1;
   
}
 
void Izbaci(char *s,int vel){
   
    while(*(s+vel-1)!='\0'){
        *s=*(s+vel);
        s++;
    }
   
}
 
void UbaciTekst(char *ind,const char *tekst){
   
   
   
    char *kraj=tekst;
    while(*kraj!='\0')kraj++;
    int vel=kraj-tekst;
   
    kraj=ind;
    while(*kraj!='\0')kraj++;
   
    while(kraj>=ind){
       
        *(kraj+vel)=*kraj;
        kraj--;
    }
   
    char *s2=tekst;
   
    while(*s2!='\0'){
       
        *ind=*s2;
        ind++;
        s2++;
    }
   
   
}
 
 
char *ZamijeniTekst (char *Str, const char *sta, const char *sa_cim){
   
   
    int v1;
    char*kraj=sta;
    while(*kraj!='\0')kraj++;
    v1=kraj-sta;
   
    char *poc=Str;
    while(1){
       
        int indeks=podstring(Str,sta);
        if(indeks==-1 )break;
       
        Izbaci(Str+indeks,v1);//str nek bude pocetak brojeva, a v1 razlika kraja brojeva ipocetka
        UbaciTekst(Str+indeks,sa_cim);
       
    }
   
    return poc;
}
 
/*--->>>> Zamjena niza rijeci <<<---- */
char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci){
   
    char *poc=tekst;
    int i=0,j=0;
   
    for(i=0;i<broj_rijeci;i++){
       
        while(1){
           
            int indeks=podstring(tekst,rijeci[i]);//i prestavlja n-tu rijec u matrici rijeci
            if(indeks==-1)break;
            ZamijeniTekst(tekst,rijeci[i],zamjene[i]);
        }
       
    }
   
   
   
    return poc;
}
int main() {
    printf("ZSR 10, Zadatak 12");
    return 0;
}
