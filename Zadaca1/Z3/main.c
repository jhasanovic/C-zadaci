#include <stdio.h>

int main() {
	char slovo1,slovo2;
	int broj1,broj2,sabit,fadila,preostalo_sabit,preostalo_fadila,pogresan_unos1,pogresan_unos2,brojac1,brojac2;
	
	/*Vanjska do-while u slucaju greske, unutrasnja ucitava jedan po jedan unos i sabira.
	U slucaju greske, ispisuje se poruka tek nakon unesene tacke*/
	do{
		sabit=0;
		pogresan_unos1=0;
		brojac1=0;
	printf("Unesite pogotke za Sabita: ");
	do{
	scanf(" %c",&slovo1);
	brojac1++;
	if(slovo1=='.') break;
	else if((slovo1!='X' && slovo1!='O' && slovo1!='I' && slovo1!='S' && slovo1!='D' && slovo1!='T') || brojac1>9){
	pogresan_unos1=1;
	printf("Neispravni ulazni podaci.\n");
	while(getchar()!='\n'){}
	break;
	}
	else{
	if(slovo1=='X' || slovo1=='O' || slovo1=='I'){
		if(slovo1=='X')
		sabit=sabit;
		else if(slovo1=='O')
		sabit=sabit+25;
		else if(slovo1=='I')
		sabit=sabit+50;
		continue;
	}
	
	scanf("%d",&broj1);
	if(slovo1=='S')
	sabit=sabit+broj1;
	else if(slovo1=='D')
	sabit=sabit+2*broj1;
	else if(slovo1=='T')
	sabit=sabit+3*broj1;
	}
	
}while(slovo1!='.');
}while(pogresan_unos1!=0);

do{
	fadila=0;
	pogresan_unos2=0;
	brojac2=0;
	printf("Unesite pogotke za Fadilu: ");
	do{
	scanf(" %c",&slovo2);
	brojac2++;
	if(slovo2=='.') break;
	else if((slovo2!='X' && slovo2!='O' && slovo2!='I' && slovo2!='S' && slovo2!='D' && slovo2!='T') || brojac2>9){
		pogresan_unos2=1;
		printf("Neispravni ulazni podaci.\n");
	    while(getchar()!='\n'){}
		break;
	}
	else{
    if(slovo2=='X' || slovo2=='O' || slovo2=='I'){
		if(slovo2=='X')
		fadila=fadila;
		else if(slovo2=='O')
		fadila=fadila+25;
		else if(slovo2=='I')
		fadila=fadila+50;
		continue;
	}
	
	scanf("%d",&broj2);
		if(slovo2=='S')
		fadila=fadila+broj2;
		else if(slovo2=='D')
		fadila=fadila+2*broj2;
		else if(slovo2=='T')
		fadila=fadila+3*broj2;
	
}
}while(slovo2!='.');
}while(pogresan_unos2!=0);
	
	if(sabit>301 && fadila>301)
	printf("Oba igraca su premasila potrebni broj poena, rezultat je nerijesen.");
	
	else if(sabit<=301 && fadila<=301){
	printf("Sabit je ostvario %d poena, Fadila je ostvarila %d poena. ",sabit,fadila);
	preostalo_sabit=301-sabit;
	preostalo_fadila=301-fadila;
	if(preostalo_fadila<preostalo_sabit)
	printf("Pobjednik je Fadila, kojoj je ostalo jos %d poena do pobjede.",preostalo_fadila);
	else if(preostalo_sabit<preostalo_fadila)
	printf("Pobjednik je Sabit, kojem je ostalo jos %d poena do pobjede.",preostalo_sabit);
	else if(preostalo_fadila==preostalo_sabit)
	printf("Rezultat je nerijesen.");
	}
	
	else if(sabit>301 && fadila<=301){
	printf("Sabit je premasio potrebni broj poena, Fadila je ostvarila %d poena. ",fadila);
	preostalo_fadila=301-fadila;
	printf("Pobjednik je Fadila, kojoj je ostalo jos %d poena do pobjede.",preostalo_fadila);
	}
	
	else if(fadila>301 && sabit<=301){
		printf("Fadila je premasila potrebni broj poena, Sabit je ostvario %d poena. ",sabit);
		preostalo_sabit=301-sabit;
		printf("Pobjednik je Sabit, kojem je preostalo %d poena do pobjede.",preostalo_sabit);
	}
	return 0;
}
