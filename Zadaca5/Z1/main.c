#include <stdio.h>

struct Tabela {
	char naziv[100];
	int pobjede;
	int nerijeseni;
	int porazi;
	int br_golova;
	int br_primljenih;
};

void unos_naziva(char niz[],int velicina)
{
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	int i=0;
	while(i<velicina-1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

int funkcija(struct Tabela Niz[],int n)
{
	int bodovi=0,i=0,j=0,izbaceni=0,razlika,max,maxi;
	/*sabrati bodove,odmah izbaciti ako ima manje od 20*/
	/*bodovi: pobjede*3+nerijeseni*/

	for(i=0; i<n; i++) {
		bodovi=0;
		bodovi=Niz[i].pobjede*3+Niz[i].nerijeseni;
		if(bodovi<20) {
			for(j=i; j<n-1; j++) {
				Niz[j]=Niz[j+1];
			}
			izbaceni++;
			n--;
			i--;
		}
	}
	max=Niz[0].br_golova-Niz[0].br_primljenih;/*pocetni max*/
	maxi=0;
	for(i=0; i<n; i++) {
		razlika=0;
		razlika=Niz[i].br_golova-Niz[i].br_primljenih;
		if(razlika>max) {
			max=razlika;
			maxi=i;/*maxi je indeks clana sa najvecom gol razlikom*/
		}
	}
		
	
	if(n>0)
		printf("Najvecu gol razliku ima:\n%s\n",Niz[maxi].naziv);
	else if(n==0)
	printf("Najvecu gol razliku ima: \n");
	return n;
}

int main()
{
	struct Tabela Niz[100];
	struct Tabela temp;
	int br_timova,i,j,n;
	printf("Unesite broj timova: ");
	scanf("%d",&br_timova);
	for(i=0; i<br_timova; i++) {
		printf("Unesite naziv %d. tima: ",i+1);
		unos_naziva(Niz[i].naziv,100);
		printf("Broj pobjeda: ");
		scanf("%d",&Niz[i].pobjede);
		printf("Broj nerijesenih: ");
		scanf("%d",&Niz[i].nerijeseni);
		printf("Broj poraza: ");
		scanf("%d",&Niz[i].porazi);
		printf("Broj datih golova: ");
		scanf("%d",&Niz[i].br_golova);
		printf("Broj primljenih golova: ");
		scanf("%d",&Niz[i].br_primljenih);
		printf("\n");
	}

	n=funkcija(Niz,br_timova);
	/*sortiranje po broju bodova*/
	for(i=0; i<n; i++) {
		for(j=0; j<n-1; j++) {
			if((Niz[j].pobjede*3+Niz[j].nerijeseni)<(Niz[j+1].pobjede*3+Niz[j+1].nerijeseni)) {
				temp=Niz[j];
				Niz[j]=Niz[j+1];
				Niz[j+1]=temp;
			}
		}
}
	
	printf("Tabela nakon izbacivanja:\n");
	for(i=0; i<n; i++) {
		printf("%d. %s\n",i+1,Niz[i].naziv);
	
	}
	return 0;
}