/*#2 Prepraviti funkciju iz prethodnog zadatka tako da ignoriše razliku između velikih i
malih slova. Npr. za drugi primjer gdje se traži tekst „Divan“ funkcija bi trebala da vrati
broj 9 jer se u stringu nalazi tekst „divan“.*/
#include <stdio.h>

int pronadji_posljednji(const char *str, const char *trazi){
   
    const char *pocetak=str;
    const char *s2=trazi;
    const char *s1=str;
    char c1,c2;
    const char* vraceno;
    int br=0;
    while(*s1!='\0'){
       
        const char *pok=s1;
        s2=trazi;
        c1=*s1;
        c2=*s2;
       
        if(c1<='Z' && c1>='A')c1+=32;
            if(c2<='Z' && c2>='A')c2+=32;
           
        while(c1==c2){
            s1++;
            s2++;
           
        c1=*s1;
        c2=*s2;
       
        if(c1<='Z' && c1>='A')c1+=32;
            if(c2<='Z' && c2>='A')c2+=32;
            if(*s2=='\0'){vraceno= pok-pocetak;
            br++;}
        }
       
        s1++;
    }
   
   
        if(br!=0) return vraceno;
    return -1;
}
 
int main() {
    const char *n = "danas je divan dan!";
    printf ("%d", pronadji_posljednji(n, "Dan"));
    return 0;
}