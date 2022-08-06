/*#6 Koristeći isključivo pokazivačku aritmetiku, napisati funkciju void nadovezi(int *p1, const int *q1, 
const int *q2) koja „nadovezuje“ drugi niz na kraj prvog niza. Pretpostaviti da prvi niz ima dovoljno mjesta da 
smjesti sve elemente drugog niza. Pokazivač p1 pokazuje tačno na lokaciju prvog niza gdje treba početi smiještati 
elemente, dok pokazivači q1 i q2 omeđuju drugi niz (q1 pokazuje na početak drugog niza a q2 tačno iza kraja drugog 
niza). Na primjer, neka prvi niz (imena niz1) sadrži 10 elemenata koji su sve nule, neka drugi niz (imena niz2) 
sadrži sljedeće elemente {1, 2, 3, 4, 5}. Sljedeći poziv nadovezi(niz1 + 2, niz2, niz2 + 5);
treba da modificira niz1 tako da on izgleda ovako: {0, 0, 1, 2, 3, 4, 5, 0, 0, 0}.*/

#include <stdio.h>

void nadovezi(int* p1, const int* q1, const int* q2){
while(q1!=q2){/*sve dok se pocetak i kraj ne poklope*/
*p1=*q1;
p1++;
q1++;
}
}

int main() {
int niz1[10]={0};
int niz2[4]={1,2,3,4};
nadovezi(niz1, niz2, niz2+4);
int i;
for(i=0; i<10; i++) 
printf("%d ",niz1[i]);
	return 0;
}