/*#18 Napisati program koji će koristiti kao jednoupotrebni jednostavni kalkulator. 
Program najprije izlistava operacije koje korisnik može koristiti, a zatim, nakon što je korisnik 
odabrao operaciju, unosi jedan ili dva broja/operanda (u zavisnosti od operacije) i vrši tu operaciju nad njima.*/

#include <stdio.h>
#include <math.h>
int main() {
	float n1,n2,zbir,razlika,proizvod,kolicnik,stepen,korijen;
	char op;
	printf("--- Moj mini kalkulator ---\n");
	printf("Sabiranje: +\n");
	printf("Oduzimanje: -\n");
	printf("Mnozenje: *\n");
	printf("Dijeljenje: /\n");
	printf("Kvadriranje: #\n");
	printf("Korjenovanje: &\n");
	
	printf("Odaberite operaciju: ");
    scanf("%c",&op);
    if(op=='+' || op=='-' || op=='*' || op=='/'){
    printf("Unesite prvi broj: ");
    scanf("%f",&n1);
    printf("Unesite drugi broj: ");
    scanf("%f",&n2);
    
    zbir=n1+n2;
    razlika=n1-n2;
    proizvod=n1*n2;
    kolicnik=n1/n2;
    
    if(op=='+')
    printf("Rezultat: %g + %g = %.2f",n1,n2,zbir);
    else if(op=='-')
    printf("Rezultat: %g - %g = %g",n1,n2,razlika);
    else if(op=='*')
    printf("Rezultat: %g * %g = %g",n1,n2,proizvod);
    else if(op=='/'){
    	if(n2!=0)
        printf("Rezultat: %g / %g = %g",n1,n2,kolicnik);
        else
        printf("GRESKA: Dijeljenje sa nulom!");
    }
    }
    
    else if(op=='#' || op=='&') {
    printf("Unesite broj: ");
    scanf("%f",&n1);
    stepen=pow(n1,2);
    korijen=sqrt(n1);
    if(op=='#')
    printf("Rezultat: %g^2 = %g",n1,stepen);
    else if(op=='&')
    printf("Rezultat: %g^(1/2) = %g",n1,korijen);
    }
    
    else
    printf("GRESKA: Nepostojeca operacija!");
   
	return 0;
}
