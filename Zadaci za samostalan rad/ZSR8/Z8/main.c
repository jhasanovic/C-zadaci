/*#8 Koristeći isključivo pokazivačku aritmetiku, napisati funkciju int izbaci_podniz(int *p1, int *p2,
const int *q1, const int *q2)koja iz niza omeđenog sa p1 i p2 izbacuje svako ponavljanje drugog niza omeđenog sa q1 i
q2 (za omeđavanje vrijedi ista stvar kao i u prethodnom zadatku). Funkcija treba da modificira prvi niz tako da 
elementi koji nisu izbačeni ostanu u istom redoslijedu. Također, funkcija treba da vrati broj izbačenih elemenata 
(odnosno 0 ako izbacivanja nije bilo tj. ako prvi niz nije sadržavao drugi niz).*/
#include <stdio.h>
 
int izbaci_podniz (int* p1, int* p2, const int* q1, const int*q2)
{
 
    int* pocetak=p1;
    int sadrzan=0;
    int* poc=p1;
    int* pom1=p1;
    const int* pom2=q1;
    while (p1<p2) {
        pom1=p1;
        pom2=q1;
        pocetak=p1;
        while (*pom1==*pom2) {
            pom1++;
            pom2++;
            if (pom2==q2 && pom1<p2) {
                sadrzan++;
                while (pom1<p2) {
                    *pocetak=*pom1;
                    pom1++;
                    pocetak++;
                }
                pom1=p1;
                break;
            }
            if (pom2==q2 && pom1==p2) {
                sadrzan++;
                return (q2-q1)*sadrzan;
            }
        }
 
        p1++;
    }
    return (q2-q1)*sadrzan;
}
 
int main()
{
    int niz1[12]= {1,1,2,3,2,1,2,3,3,1,2,3};
    int niz2[1]= {3};
    int k = izbaci_podniz(niz1, niz1+12, niz2, niz2+1);
    int i;
    for(i=0; i<12-k; i++) printf("%d ",niz1[i]);
    return 0;
}