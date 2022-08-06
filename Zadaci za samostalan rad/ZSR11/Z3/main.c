/*Data je struktura koja opisuje trenutni kurs neke valute u kursnoj listi (koliko KM ćete dobiti za jednu 
jedinicu te valute).
struct Kurs {
char valuta[5];
float vrijednost;
};
Npr. trenutni kurs za valutu EUR je 1.955830 KM, pa struktura za tu valutu sadrži vrijednosti "EUR" i 1.95583.
Napisati funkciju razmjena koja prima kursnu listu (niz proizvoljne dužine čiji su članovi tipa struct Kurs), 
jedan string koji označava valutu (npr. "EUR") i iznos u KM (realan broj), a vraća iznos u primljenoj valuti. 
Ako se valuta ne nalazi u nizu treba vratiti 0.*/
#include <stdio.h>

struct Kurs{
char valuta [5];
float vrijednost;
};

float razmjena(struct Kurs KursnaLista[],int n,char* string,double km){
	char* pok1;
	char* pok2=string;
	int flag=0,i=0;
	for(i=0;i<n;i++){
		pok1=KursnaLista[i].valuta;
		pok2=string;
		while(*pok1==*pok2){
			pok1++;
			pok2++;
			if (*pok1=='\0' || *pok2=='\0') break;
		}
		if(*pok1=='\0' && *pok2=='\0'){
			flag=1;
			break;
		}
	}
	if(flag==0)
	return 0;
else{
 return KursnaLista[i].vrijednost*km;
}
}

int main() {
struct Kurs niz[4] = {{"ABBB", 1.8}, {"USD", 1.2}, {"AABC", 1.5}, {"USDD",1.28}};
  printf("%g ", razmjena(niz, 3, "AB", 1.4));
  printf("%g ", razmjena(niz, 3, "ABC", 1.22));
  printf("%g ", razmjena(niz, 5, "USD", 1.955830));
  printf("%g ", razmjena(niz, 4, "USDD", 1.955830));
	return 0;
}
