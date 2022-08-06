/*#7 Koristeći isključivo pokazivačku aritmetiku, napisati funkciju int podniz (const int *p1, const int *p2,
const int *q1, const int *q2) koja provjerava da li se niz omeđen sa pokazivačima q1 i q2 (q1 pokazuje na prvi 
element, a q2 tačno iza zadnjeg) nalazi unutar niza omeđenog pokazivačima p1 i p2 (p1 pokazuje na početak, a p2 
tačno iza kraja niza). Funkcija treba da vrati indeks prvog elementa prvog niza na kojem počinje drugi podniz 
odnosno -1 ukoliko prvi niz ne sadrži drugi niz unutar sebe. Ukoliko ima više podnizova, treba vratiti indeks prvog.
*/
#include <stdio.h>

int podniz (const int* p1, const int* p2, const int* q1, const int* q2)
{
    const int* pom2=p1;
    const int* pom1=q1;
    while (p1<p2) {
        pom2=p1;
        pom1=q1;
        while (*pom1==*pom2) {
            pom2++;
            pom1++;
            if (pom1==q2) return br-(p2-p1);
        }
        p1++;
    }
    return -1;
       
}
int main()
{
 int niz1[10]={1,2,3,4,5,6,7,8,9,10};
    int niz2[10]={1,2,3,4,5,6,7,8,9,10};
    int k = podniz(niz1, niz1+10, niz2, niz2+10);
    printf("%d", k);

    return 0;
}