#include <stdio.h>

char* izbaci_anagrame(char* string1, char* string2)
{
	char* provjera=string2;/*provjerava da li ima ijedno slovo u stringu2*/
	char* prvi=string1;
	char* pok1=string1;
	char* pok2=string2;
	char* pocetak=string1;/*pokazivac na prvo slovo rijeci koje treba izbaciti*/
	char* kraj=string1;/*pokazivac iza rijeci koju treba izbaciti*/
	int flag=0,i=0,slovo=0,izbaceno=0;
	int hist1[100]= {0};
	int hist2[100]= {0};

	while(*provjera!='\0') {
		if(*provjera>='A' && *provjera<='z'){
			slovo=1;
			break;
		}
		provjera++;
	}
	if(slovo==0) { /*znaci da nije nadjeno niti jedno slovo u stringu2*/
		return prvi;
	}
	while(*pok1!='\0') {
		while(*pok1<'A' || *pok1>'z')/*pomjeri pokazivac na prvo slovo rijeci*/
			pok1++;
		pocetak=pok1;
		kraj=pok1;
		while(*kraj>='A' && *kraj<='z')
			kraj++;
		pok2=string2;
		for(i='A'; i<='Z'; i++) {
			hist1[i]=0;
		}
		while(*pok1>='A' && *pok1<='z') {
			if(*pok1>='A' && *pok1<='Z')
				hist1[(int)*pok1]++;
			else
				hist1[*pok1-32]++;
			pok1++;
		}
		/*restartujemo pok2 na pocetak stringa 2 poslije svake unutrasnje petlje*/
		while(*pok2!='\0') {
			while(*pok2<'A' || *pok2>'z')/*pomjeri pokazivac na prvo slovo rijeci*/
				pok2++;
			for(i='A'; i<='Z'; i++) {
				hist2[i]=0;
			}
			while(*pok2>='A' && *pok2<='z') {
				if(*pok2>='A' && *pok2<='Z')
					hist2[(int)*pok2]++;
				else
					hist2[*pok2-32]++;
				pok2++;
			}

			for(i='A'; i<='Z'; i++) {
				if(hist1[i]!=hist2[i]) {
					flag=1;
					break;
				}
			}

			if(flag==0) { /*rijeci su anagrami, izbaci rijec iz stringa1*/
				while(pocetak<kraj) {
					*pocetak=' ';
					pocetak++;
					izbaceno=1;
				}
			}

			if(flag==1) { /*rijeci nisu anagrami, predji na sljedecu rijec*/
				flag=0;
			}
			
		}
	}
	if(*pok1=='\0' && slovo==1 && izbaceno==0) return prvi;
	return prvi;
}

int main()
{
	char string1[]= {"nema rijeci u stringu"};
	char string2[]= {"121291389"};
	printf("Nakon izbacivanja anagrama string glasi: %s",izbaci_anagrame(string1,string2));
	return 0;
}
