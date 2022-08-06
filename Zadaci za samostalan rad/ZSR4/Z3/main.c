/*#3 Napisati program koji od korisnika traži da unese broj n i koji će ispisati tablicu 
množenja za uneseni broj n. Broj n mora biti u intervalu [2, 10], što program mora 
provjeriti i završiti sa radom ukoliko uneseni broj to ne zadovoljava. Tablicu ispisivati
lijevo poravnatu, na 4 mjesta širine.*/

#include <stdio.h>

int main(){
int n,i,j;
printf("Unesite n: ");
scanf("%d",&n);

if(n>=4 && n<=10){
for(i=1;i<=n;i++){
for(j=1;j<=n;j++){
printf("%-4d",i*j);
}
printf("\n");
}
}

else 
printf("Uneseni broj nije u intervalu!");
return 0;
}