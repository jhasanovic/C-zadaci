/*#10 Napisati program koji računa zbir, razliku, proizvod i količnik posljednje dvije cifre unesesnog cijelog broja.
Ukoliko broj ima manje od dvije cifre, cifru koja nedostaje (tj. prvu cifru) zamijeniti nulom. 
U slučaju dijeljenja s nulom, ispisati „Nemoguce!“.*/

#include <stdio.h>
#include <stdlib.h>
int main() {
	int broj,n,zbir,razlika,proizvod,zadnja,predzadnja;
	float kolicnik;
	printf("Unesite cijeli broj: ");
	scanf("%d",&broj);
	n=broj;
	if(broj>=10 || broj<=-10){
    zadnja=abs(broj)%10;
	broj=broj/10;
	predzadnja=abs(broj)%10;
	}
    else{
    zadnja=abs(n)%10;
	n=n/10;
	predzadnja=0;	
    }
   
    
	zbir=predzadnja+zadnja;
	razlika=predzadnja-zadnja;
	proizvod=predzadnja*zadnja;
	kolicnik=(float)predzadnja/zadnja;
	
printf("Zbir zadnje dvije cifre (%d i %d) je: %d\n",predzadnja,zadnja,zbir);
printf("Razlika zadnje dvije cifre (%d i %d) je: %d\n",predzadnja,zadnja,razlika);
printf("Proizvod zadnje dvije cifre (%d i %d) je: %d\n",predzadnja,zadnja,proizvod);
if(zadnja!=0)
printf("Kolicnik zadnje dvije cifre (%d i %d) je: %.6f\n",predzadnja,zadnja,kolicnik);
else
printf("Kolicnik zadnje dvije cifre (%d i %d) je: Nemoguce! ",predzadnja,zadnja);

	return 0;
}
