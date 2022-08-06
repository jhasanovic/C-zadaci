/*#1 Napisati funkciju const char* posljednja_rijec (const char *s)
koja vraća pokazivač na posljednju riječ u proslijeđenom stringu.*/

#include <stdio.h>
const char* posljednja_rijec (const char* s){
	const char* pok;
	const char* jedna=s;
	int flag=0;
	while(*s!='\0'){//prolazi kroz string do kraja
		if(*s==' ') flag=1;//ako je nadjen razmak(vise od jedne rijeci ili jedna s vise razmaka)
	if(*s==' ' && *(s+1)>32)//ako je trenutni razmak, a sljedeci slovo, uzmi taj pok
	pok=(s+1);
	s++;
	}
	if(flag==1)
	return pok;
	else return jedna;//ako nema nijednog razmaka, vrati na pocetak primljenog stringa(samo jedna rijec)
}

int main() {
	printf("'%s'", posljednja_rijec("    danas"));
	return 0;
}