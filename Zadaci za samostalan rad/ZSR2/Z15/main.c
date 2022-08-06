/*#15 Napisati program koji od korisnika traži unos cijelog broja te ispituje da li se taj broj nalazi u nekom 
od ispod navedenih intervala. Ako se uneseni broj ne nalazi u nekom od intervala, potrebno je ispisati 
„Ne nalazi“, u suprotnom treba ispisati „Nalazi“. Ispitati pripadnost broja sljedećim intervalima: 
A: [-3, 11), (5, 15), (17, 31], (19, 33)
B: (-1, 1], [2, 12], [5, 56], [9, 10)
C: (-11, -6), (15, 16], [6, 9]
Broj pripada intervalu ako pripada nekom od intervala iz skupine A i ako pripada nekom od intervala iz skupine B,
te ako ne pripada nekom od intervala iz C skupine.*/
#include <stdio.h>

int main() {
	int n;
	printf("Unesite cijeli broj: ");
	scanf("%d",&n);
	if(((n>=-3 && n<=11) || (n>5 && n<15) || (n>17 && n<=31) || (n>19 && n<33))&&((n>-1 && n<=1) || (n>=2 && n<=12)
	|| (n>=5 && n<=56) || (n>=9 && n<10)) && ((n<=-11 || n>=-6) && (n<=15 || n>16 ) &&(n<6 || n>9)))
	printf("Nalazi");
	else
	printf("Ne nalazi");
	return 0;
}
