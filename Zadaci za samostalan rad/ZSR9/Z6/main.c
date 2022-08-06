/*#6 Napisati funkciju char* popuni_lijevo (char* str, int n) koja popunjava razmacima proslijeđeni string sa lijeve
strane. Ukoliko je dužina stringa veća ili jednaka od n, funkcija ne treba ništa da radi. Primjer korištenja:
char n1[100] = "Bosna", n2[100] = "Hercegovina";
char *p1 = popuni_lijevo(n1, 15);
char *p2 = popuni_lijevo(n2, 15);
printf ("\n'%s'\n'%s'", p1, p2);
Kôd iznad bi trebao ispisati sljedeće:
'          Bosna'
'    Hercegovina'
Funkcija ne smije koristiti pomoćne funkcije. Napisati i funkciju popuni_desno koja s desne strane popunjava string 
razmacima.*/
#include <stdio.h>
 
char* popuni_desno (char* Str, int n) {
    char* kr=Str;
    char* poc=Str;
    while (*kr!='\0') kr++;
    int vel=kr-Str;
    if (vel>=n) return poc;
    while (kr<Str+n) {
        *kr=' ';
        kr++;
    }
    return poc;
}
 
char* popuni_lijevo (char* Str, int n)
{
    char* pocetak=Str;
    char* kraj=Str;
    char* izakraja=Str+n;
    while (*kraj!='\0') kraj++;
    int vel=kraj-Str;
    if (vel>=n) return Str;
    //moze vece ili jednako
    while (kraj>=pocetak) {
        *(izakraja)=*kraj;
        kraj--;
        izakraja--;
    }
    while (izakraja>=pocetak) {
        *izakraja=' ';
        izakraja--;
    }
   
    return Str;
}
int main()
{
    char n1[100] = "Bosna", n2[100] = "Hercegovina";
    char *p1 = popuni_lijevo(n1, 15);
    char *p2 = popuni_desno(n2, 15);
    printf ("'%s'\n'%s'", p1, p2);
    return 0;
}