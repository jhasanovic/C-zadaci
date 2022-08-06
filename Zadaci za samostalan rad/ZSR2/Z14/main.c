/*#14 Prepraviti zadatak #8 kombinirajući ga sa prethodnim zadatkom (#13) tako da sada ne ispisuje „godina/e/u“
nego da odluči šta da upotrijebi prilikom ispisa. Ako ste zadatak pametno uradili, onda ćete izmjenu raditi 
samo na jednom mjestu. Cilj ovoga zadatka je da vas pokuša usmjeriti da zadatke pišete što modularnije i 
skalabilnije, pa kada je potrebno nešto mijenjati ili dodavati, to uradite na što manje mjesta jer time 
smanjujete mogućnost grešaka. Što manje pišete kôda koji se ponavlja, to je bolje!*/


#include <stdio.h>
#define trenutna 2015
int main() {
	int godina_rodjenja,godine;
	char spol;
	printf("Unesite godinu rodjenja osobe: ");
	scanf("%d",&godina_rodjenja);
	if(godina_rodjenja<=trenutna){
	printf("Unesite spol osobe (m/M ili z/Z): ");
	scanf(" %c",&spol);
	godine=trenutna-godina_rodjenja;
	if(spol=='M' || spol=='m' || spol=='Z' || spol=='z'){
		
	if(godine<6 && godine==1 && (spol=='M' || spol=='m'))	
	printf("Osoba ima %d godinu, klasificirana je u kategoriju: 'prije skole', musko je. ",godine); 
	else if(godine<6 && godine==1 && (spol=='Z' || spol=='z'))	
	printf("Osoba ima %d godinu, klasificirana je u kategoriju: 'prije skole', zensko je. ",godine);
	else if(godine<6 && godine!=5 && (spol=='M' || spol=='m'))	
	printf("Osoba ima %d godine, klasificirana je u kategoriju: 'prije skole', musko je. ",godine); 
	else if(godine<6 && godine!=5 && (spol=='Z' || spol=='z'))	
	printf("Osoba ima %d godine, klasificirana je u kategoriju: 'prije skole', zensko je. ",godine);
	else if(godine<6 && godine==5 && (spol=='M' || spol=='m'))	
	printf("Osoba ima %d godina, klasificirana je u kategoriju: 'prije skole', musko je. ",godine); 
	else if(godine<6 &&godine==5 && (spol=='Z' || spol=='z'))	
	printf("Osoba ima %d godina, klasificirana je u kategoriju: 'prije skole', zensko je. ",godine);
	else if((godine>=6 && godine<14) && (spol=='M' || spol=='m'))	
	printf("Osoba ima %d godina, klasificirana je u kategoriju: 'osnovna skola', musko je. ",godine); 
	else if((godine>=6 && godine<14) && (spol=='Z' || spol=='z'))	
	printf("Osoba ima %d godina, klasificirana je u kategoriju: 'osnovna skola', zensko je. ",godine);
	else if((godine>=14 && godine<18) && (spol=='M' || spol=='m'))	
	printf("Osoba ima %d godina, klasificirana je u kategoriju: 'srednja skola', musko je. ",godine); 
	else if((godine>=14 && godine<18) && (spol=='Z' || spol=='z'))	
	printf("Osoba ima %d godina, klasificirana je u kategoriju: 'srednja skola', zensko je. ",godine); 
	else if((godine>=18 && godine<23 && godine==21) && (spol=='M' || spol=='m'))	
	printf("Osoba ima %d godinu, klasificirana je u kategoriju: 'fakultet', musko je. ",godine); 
	else if((godine>=18 && godine<23 && godine==21) && (spol=='Z' || spol=='z'))	
	printf("Osoba ima %d godinu, klasificirana je u kategoriju: 'fakultet', zensko je. ",godine);
	else if(godine==22 && (spol=='M' || spol=='m'))	
	printf("Osoba ima %d godine, klasificirana je u kategoriju: 'fakultet', musko je. ",godine); 
	else if(godine==22 && (spol=='Z' || spol=='z'))	
	printf("Osoba ima %d godine, klasificirana je u kategoriju: 'fakultet', zensko je. ",godine);
	else if((godine>=18 && godine<23) && (spol=='M' || spol=='m'))	
	printf("Osoba ima %d godina, klasificirana je u kategoriju: 'fakultet', musko je. ",godine); 
	else if((godine>=18 && godine<23) && (spol=='Z' || spol=='z'))	
	printf("Osoba ima %d godina, klasificirana je u kategoriju: 'fakultet', zensko je. ",godine); 
	else if(godine>=23 && (godine%10==3 || godine%10==4) && (spol=='M' || spol=='m'))	
	printf("Osoba ima %d godine, klasificirana je u kategoriju: 'ostalo', musko je. ",godine); 
	else if(godine>=23 && (godine%10==3 || godine%10==4) && (spol=='Z' || spol=='z'))	
	printf("Osoba ima %d godine, klasificirana je u kategoriju: 'ostalo', zensko je. ",godine);
	else if(godine>=23 && (godine%10==1 ) && (spol=='M' || spol=='m'))	
	printf("Osoba ima %d godinu, klasificirana je u kategoriju: 'ostalo', musko je. ",godine); 
	else if(godine>=23 && (godine%10==1) && (spol=='Z' || spol=='z'))	
	printf("Osoba ima %d godinu, klasificirana je u kategoriju: 'ostalo', zensko je. ",godine);
	else if(godine>=23  && (spol=='M' || spol=='m'))	
	printf("Osoba ima %d godina, klasificirana je u kategoriju: 'ostalo', musko je. ",godine); 
	else if(godine>=23 && (spol=='Z' || spol=='z'))	
	printf("Osoba ima %d godina, klasificirana je u kategoriju: 'ostalo', zensko je. ",godine);
   }
   else
   printf("Pogresan unos spola osobe! ");
	}
	else
	printf("Neispravna godina rodjenja! ");
	return 0;
}