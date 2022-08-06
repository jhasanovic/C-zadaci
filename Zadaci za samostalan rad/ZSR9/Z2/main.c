/*#2 U prethodnom zadatku, ukoliko bi proslijeđeni string bio „danas je divan   dan   “, isječak iznad bi ispisao 
ljednja rijec: 'dan    '“. Prepravite prethodni program tako da modificira izvorni string na način da ignoriše 
sve razmake nakon posljednje riječi.*/

#include <stdio.h>

char* posljednja_rijec (char* s){
	char* pok;
	char* jedna=s;
	char* novi;
	int flag=0;
	while(*s!='\0'){//prolazi kroz string do kraja
	if(*s==' '){
	flag=1;
	}//ako je nadjen razmak(vise od jedne rijeci ili jedna s vise razmaka)
	if(*s==' ' && *(s+1)>32)//ako je trenutni razmak, a sljedeci slovo, uzmi taj pok
	pok=(s+1);
	s++;
	}
	if(flag==1){
		novi=pok;
		while(*novi!=' ')
		novi++;
		*novi='\0';
	return pok;
	}
	else return jedna;//ako nema nijednog razmaka, vrati na pocetak primljenog stringa(samo jedna rijec)
}

int main() {
	printf("'%s'", posljednja_rijec("danas     "));
	return 0;
}
