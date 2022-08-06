/*#13 Napisati program koji „pametno“ ispisuje godine unesene kao cijeli broj iz intervala [0, 100]. 
Ukoliko broj nije iz intervala, program treba da ispiše (proizvoljnu) grešku i završi sa radom. 
Program treba, u zavisnosti od unesenog broja, da ispiše „godina“, „godinu“ ili „godine“.*/

#include <stdio.h>

int main() {
	int g;
	printf("Unesite godine: ");
	scanf("%d",&g);
	if(g<=100 && g>=0){
    if(g==1 || (g%10==1 && g!=11))
	printf("Imate %d godinu",g);
	else if((g%10==2 && g!=12) || (g%10==3 &&g!=13) || (g%10==4 &&g!=14))
	printf("Imate %d godine",g);
	else 
	printf("Imate %d godina",g);
	}
	else
	printf("Neispravan unos! ");
	return 0;
}
