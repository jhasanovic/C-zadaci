/*Copy pasteana prethodna verzija zadatka sa zamgera u 20:07*/
#include <stdio.h>
#define seg 4

int main() {
	/*varijable postavljene na nulu samo zbog upozorenja na zamgeru*/
	int izbor,zbir=0,razlika=0,proizvod=0,kolicnik=0,prvi=0,drugi=0,greska=0,i,j,cifra1=0,cifra2=0,rez=0,preskoci=0;
	char mat[5][114];
	
	/*Ispunjavanje matrice koja sluzi kao sablon sa svim ciframa*/
	for(i=0;i<=4;i++){
		for(j=0;j<=113;j++){
			if(i==0 && ((j>=0 && j<=4) || j==16 ||(j>=24 && j<=28) || (j>=36 && j<=40) || j==48 || j==52 || 
			(j>=60 && j<=64) || (j>=72 && j<=76) || (j>=84 && j<=88) || (j>=96 && j<=100) || (j>=108 && j<=112))) 
			mat[i][j]='*';
			
			else if(i==1 && (j==0 || j==4 || j==16 || j==28 || j==40 || j==48 || j==52 || j==60 || j==72 || j==88 || 
			j==96 || j==100 || j==108 || j==112))
			mat[i][j]='*'; 
			
			else if(i==2 && ((j==0 || j==4) || j==16 || (j>=24 && j<=28) || (j>=36 && j<=40) || (j>=48 && j<=52) || 
			(j>=60 && j<=64) ||	(j>=72 && j<=76) || (j>=24 && j<=28) || j==88 || (j>=96 && j<=100) || (j>=108 && j<=112))) 
			mat[i][j]='*';
			
			else if(i==3 && ((j==0 || j==4) || j==16 || j==24 || j==40 || j==52 || j==64 || j==72 || j==76 || j==88 
			|| j==96 || j==100 || j==112))
			mat[i][j]='*'; 
			
			else if(i==4 && ((j>=0 && j<=4)|| j==16 || (j>=24 && j<=28) || (j>=36 && j<=40) || j==52 || (j>=60 && j<=64)
			|| (j>=72 && j<=76) || j==88 || (j>=96 && j<=100) || (j>=108 && j<=112))) 
			mat[i][j]='*';
			else mat[i][j]=' ';
			
		}
	}

	do{
		preskoci=0;
		greska=0;
	printf("Odaberite cjelobrojnu operaciju:\n");
	printf("[1] Sabiranje\n");
	printf("[2] Oduzimanje\n");
	printf("[3] Mnozenje\n");
	printf("[4] Dijeljenje\n");
	printf("[5] Izlaz iz programa\n");
	printf(">>\n");
	scanf("%d",&izbor);
	if(izbor<1 || izbor>5){
	preskoci=1;
	if(preskoci==1)
	continue;
	}
	else if(izbor==1){
		printf("[1] Sabiranje\n");
		printf("Unesite operande: ");
		scanf("%d %d",&prvi,&drugi);
		zbir=prvi+drugi;
		rez=zbir;
		if(zbir>=100 || zbir<0)
		greska=1;
	}
	else if(izbor==2){
		printf("[2] Oduzimanje\n");
		printf("Unesite operande: ");
		scanf("%d %d",&prvi,&drugi);
		razlika=prvi-drugi;
		rez=razlika;
		if(razlika>=100 || razlika<0)
		greska=1;
	}
	else if(izbor==3){
		printf("[3] Mnozenje\n");
		printf("Unesite operande: ");
		scanf("%d %d",&prvi,&drugi);
		proizvod=prvi*drugi;
		rez=proizvod;
		if(proizvod>=100 || proizvod<0)
		greska=1;
	}
	else if(izbor==4){
		printf("[4] Dijeljenje\n");
		printf("Unesite operande: ");
		scanf("%d %d",&prvi,&drugi);
		if(drugi==0 || kolicnik<0 || kolicnik>=100)
		greska=1;
		else{
		kolicnik=prvi/drugi;
		rez=kolicnik;
		}
	}
	else if(izbor==5){
	return 0;
	}
	
	if(greska==1){
		for(i=0;i<=seg;i++){
			for(j=0;j<=4*seg;j++){
			if(j==0)
			printf("*");
			else if(i%2==0 && j<=seg)
			printf("*");
			else if(i==seg/2 && j>=3*seg)
			printf("*");
			else if(j==3*seg && i>=seg/2)
		    printf("*");
			else 
			printf(" ");
			}
			printf("\n");
		}

	}
	
	else{
		if(rez>=10){
		cifra2=rez%10;
		rez/=10;
		cifra1=rez%10;
		
		}
		else{
			cifra1=0;
			cifra2=rez%10;
		}
		
		for(i=0;i<=seg;i++){
			for(j=0;j<3*seg;j++){
			printf("%c",mat[i][cifra1*12+j]);
			}
			for(j=0;j<=seg;j++){
			printf("%c",mat[i][cifra2*12+j]);
			}
			printf("\n");
		}
		
		}
	printf("\n");
	}while(greska==1 || izbor!=5);
	return 0;
}