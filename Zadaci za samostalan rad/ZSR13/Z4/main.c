#include <stdio.h>
#include <string.h>

struct Grad {
	char naziv[20];
	int br_stanovnika;
};

struct Drzava {
	char naziv[50];
	struct Grad glavni;
};

struct Regija {
	char naziv[50];
	struct Grad glavni;
};

int filtriraj(struct Drzava drzave[],int br_drzava,struct Regija regije[],int br_regija)
{
	int i=0,j=0,t=0,flag=0;
	char slovo;
	for(i=0; i<br_drzava; i++) {
		for(j=0; j<br_regija; j++) {
			slovo=drzave[i].naziv[0];
			if((strcmp(drzave[i].glavni.naziv,regije[j].glavni.naziv)==0 || slovo=='Z' ||
			        drzave[i].glavni.br_stanovnika<10000) ) {
				for(t=i; t<br_drzava-1; t++) {
					drzave[t]=drzave[t+1];
				}

				j=0;
				i--;
				br_drzava--;
				flag=1;
			}
			if(flag==1) {
				flag=0;
				break;
			}
		}
	}
	return br_drzava;
}

int main()
{
	struct Drzava drzave[] = {
		{"Mozambik", { "Maputo", 123456}},
		{"Zimbabve", { "Harare", 345126}},
		{"zambija", { "Lusaka", 521423}}, /* Malo Z ! */
		{"Bosna i Hercegovina", { "Sarajevo", 123456}},
		{"Zelenortska republika", { "Praia", 123456}}
	};
	struct Regija regije[] = {
		{"Regija1", { "Grad21", 345126}},
		{"Regija2", { "Grad2", 123123}},
		{"Regija3", { "Grad18", 123456}}
	};
	printf("%d",filtriraj(drzave,100,regije,100));
	return 0;
}
