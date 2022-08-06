/*#8 Napisati program koji računa koliko osoba ima godina, te klasificira osobu u neku od kategorija 
„prije skole“ (do 6 godina), „osnovna skola“ (od 6 do 14 godina), „srednja skola“ (od 14 do 18 godina), 
„fakultet“ (od 18 do 23 godine i „ostalo“ (stariji od 23 godine). Korisnik unosi godinu rođenja osobe i njen spol
(slovo „m“ ili „M“ ako je osoba muškog spola, slovo „z“ ili „Z“ ako je osoba ženskog spola; u slučaju da je uneseno
nešto osim ova 4 znaka, program treba ispisati „Pogresan unos spola osobe!“ i završiti sa radom.
Pomoć: potrebno je uvesti varijablu (ili simboličku konstantu pomoću #define) koja označava trenutnu godinu.
Ako je kao godina rođenja unesena godina veća od trenutne godine, treba ispisati „Neispravna godina rodjenja!“ i prekinuti izvršavanje.
Program treba da izračuna koliko osoba ima godina, da je razvrsta u neku od kategorija i dopiše „musko“ ili „zensko“ u zavisnosti od unesenog spola.*/

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
	if(godine<6 && (spol=='M' || spol=='m'))	
	printf("Osoba ima %d godina/e/u, klasificirana je u kategoriju: 'prije skole', musko je. ",godine); 
	else if(godine<6 && (spol=='Z' || spol=='z'))	
	printf("Osoba ima %d godina/e/u, klasificirana je u kategoriju: 'prije skole', zensko je. ",godine); 
	else if((godine>=6 && godine<14) && (spol=='M' || spol=='m'))	
	printf("Osoba ima %d godina/e/u, klasificirana je u kategoriju: 'osnovna skola', musko je. ",godine); 
	else if((godine>=6 && godine<14) && (spol=='Z' || spol=='z'))	
	printf("Osoba ima %d godina/e/u, klasificirana je u kategoriju: 'osnovna skola', zensko je. ",godine);
	else if((godine>=14 && godine<18) && (spol=='M' || spol=='m'))	
	printf("Osoba ima %d godina/e/u, klasificirana je u kategoriju: 'srednja skola', musko je. ",godine); 
	else if((godine>=14 && godine<18) && (spol=='Z' || spol=='z'))	
	printf("Osoba ima %d godina/e/u, klasificirana je u kategoriju: 'srednja skola', zensko je. ",godine); 
	else if((godine>=18 && godine<23) && (spol=='M' || spol=='m'))	
	printf("Osoba ima %d godina/e/u, klasificirana je u kategoriju: 'fakultet', musko je. ",godine); 
	else if((godine>=18 && godine<23) && (spol=='Z' || spol=='z'))	
	printf("Osoba ima %d godina/e/u, klasificirana je u kategoriju: 'fakultet', zensko je. ",godine); 
	else if((godine>=23) && (spol=='M' || spol=='m'))	
	printf("Osoba ima %d godina/e/u, klasificirana je u kategoriju: 'ostalo', musko je. ",godine); 
	else if((godine>=23) && (spol=='Z' || spol=='z'))	
	printf("Osoba ima %d godina/e/u, klasificirana je u kategoriju: 'ostalo', zensko je. ",godine); 
   }
   else
   printf("Pogresan unos spola osobe! ");
	}
	else
	printf("Neispravna godina rodjenja! ");
	return 0;
}
