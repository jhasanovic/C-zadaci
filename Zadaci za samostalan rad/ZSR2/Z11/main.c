/*#11 Napisati program koji sekunde (koje se unose kao cijeli broj), pretvara u dane, sate, minute i sekunde. 
Zanemariti predznak unesenog broja. */
#include <stdio.h>

int main() {
	int dani,sati,minute,sekunde;
	printf("Unesite broj sekundi: ");
	scanf("%d",&sekunde);
	if(sekunde<0)
	sekunde=-sekunde;
	dani=sekunde/86400;
	sati=(sekunde%86400)/3600;
	minute=((sekunde%86400)%3600)/60;
	sekunde=sekunde-(dani*86400)-(sati*3600)-(minute*60);
	
	printf("Pretvoreno: %dd %dh %dm %ds",dani,sati,minute,sekunde);
	return 0;
}
